import schema from "./swagger";

type Schema = typeof schema;

type ExtractGet<T> = T extends { get: infer R } ? R : never;
type ExtractPost<T> = T extends { post: infer R } ? R : never;
type ExtractGetOrPost<T> = ExtractGet<T> | ExtractPost<T>;

type ExtractParameters<T> = T extends { parameters: infer R } ? R : [];

type GetPathParameters<PathName extends keyof Schema["paths"]> =
  ExtractParameters<ExtractGetOrPost<Schema["paths"][PathName]>>;

type ConvertParamSchemaToType<T> = T extends { type: "string" }
  ? string
  : T extends { type: "boolean" }
  ? boolean
  : T extends { type: "integer" }
  ? number
  : never;

type ApplyRequired<Req, T> = Req extends true ? T : T | null | undefined;

type ConvertParamToType<T> = T extends {
  name: infer Name;
  required: infer Required;
  schema: infer Schema;
}
  ? [Name, ApplyRequired<Required, ConvertParamSchemaToType<Schema>>]
  : T extends { name: infer Name; schema: infer Schema }
  ? [Name, ApplyRequired<false, ConvertParamSchemaToType<Schema>>]
  : never;

type ConvertAllParamsToTypes<
  T extends readonly unknown[],
  Out extends unknown[] = []
> = T extends readonly [infer H, ...infer R]
  ? ConvertAllParamsToTypes<R, [...Out, ConvertParamToType<H>]>
  : Out;

type ConvertParamArrayToObject<
  T extends [key: string, value: unknown][],
  Acc extends Record<string, unknown> = {}
> = T extends [infer H, ...infer R]
  ? ConvertParamArrayToObject<R, Acc & Record<H[0], H[1]>>
  : Acc;

const get = <PathName extends keyof Schema["paths"]>(
  endpoint: PathName,
  params: ConvertAllParamsToTypes<GetPathParameters<PathName>>
) => {};

get("/Project/{partner}", [
  ["partner", "abc"],
  ["isFinal", undefined],
]);
