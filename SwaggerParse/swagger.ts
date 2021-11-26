export default {
  openapi: "3.0.1",
  info: {
    title: "ExtraBen.Api",
    version: "v1",
  },
  paths: {
    "/Account/Login": {
      post: {
        tags: ["Account"],
        requestBody: {
          content: {
            "application/json": {
              schema: {
                $ref: "#/components/schemas/Login",
              },
            },
            "text/json": {
              schema: {
                $ref: "#/components/schemas/Login",
              },
            },
            "application/*+json": {
              schema: {
                $ref: "#/components/schemas/Login",
              },
            },
          },
        },
        responses: {
          "200": {
            description: "Success",
          },
        },
      },
    },
    "/Partner": {
      get: {
        tags: ["Partner"],
        responses: {
          "200": {
            description: "Success",
            content: {
              "text/plain": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/PartnerListItem",
                  },
                },
              },
              "application/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/PartnerListItem",
                  },
                },
              },
              "text/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/PartnerListItem",
                  },
                },
              },
            },
          },
        },
      },
    },
    "/Project/{partner}": {
      get: {
        tags: ["Project"],
        parameters: [
          {
            name: "partner",
            in: "path",
            required: true,
            schema: {
              type: "string",
            },
          },
          {
            name: "isFinal",
            in: "query",
            schema: {
              type: "boolean",
              default: false,
            },
          },
        ],
        responses: {
          "200": {
            description: "Success",
            content: {
              "text/plain": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/ProjectListItem",
                  },
                },
              },
              "application/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/ProjectListItem",
                  },
                },
              },
              "text/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/ProjectListItem",
                  },
                },
              },
            },
          },
        },
      },
    },
    "/Ticket/{partner}": {
      get: {
        tags: ["Ticket"],
        parameters: [
          {
            name: "partner",
            in: "path",
            required: true,
            schema: {
              type: "string",
            },
          },
          {
            name: "projectIds",
            in: "query",
            schema: {
              type: "string",
            },
          },
          {
            name: "pattern",
            in: "query",
            schema: {
              type: "string",
            },
          },
          {
            name: "archive",
            in: "query",
            schema: {
              type: "boolean",
              default: false,
            },
          },
          {
            name: "days",
            in: "query",
            schema: {
              type: "integer",
              format: "int32",
              default: 0,
            },
          },
          {
            name: "top",
            in: "query",
            schema: {
              type: "integer",
              format: "int32",
              default: 0,
            },
          },
        ],
        responses: {
          "200": {
            description: "Success",
            content: {
              "text/plain": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/TicketListItem",
                  },
                },
              },
              "application/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/TicketListItem",
                  },
                },
              },
              "text/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/TicketListItem",
                  },
                },
              },
            },
          },
        },
      },
    },
    "/Ticket/detail/{id}": {
      get: {
        tags: ["Ticket"],
        parameters: [
          {
            name: "id",
            in: "path",
            required: true,
            schema: {
              type: "integer",
              format: "int32",
            },
          },
        ],
        responses: {
          "200": {
            description: "Success",
            content: {
              "text/plain": {
                schema: {
                  $ref: "#/components/schemas/Ticket",
                },
              },
              "application/json": {
                schema: {
                  $ref: "#/components/schemas/Ticket",
                },
              },
              "text/json": {
                schema: {
                  $ref: "#/components/schemas/Ticket",
                },
              },
            },
          },
          "404": {
            description: "Not Found",
            content: {
              "text/plain": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
              "application/json": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
              "text/json": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
            },
          },
          "403": {
            description: "Forbidden",
            content: {
              "text/plain": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
              "application/json": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
              "text/json": {
                schema: {
                  $ref: "#/components/schemas/ErrorResult",
                },
              },
            },
          },
        },
      },
    },
    "/User/{partner}": {
      get: {
        tags: ["User"],
        parameters: [
          {
            name: "partner",
            in: "path",
            required: true,
            schema: {
              type: "string",
            },
          },
        ],
        responses: {
          "200": {
            description: "Success",
            content: {
              "text/plain": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/User",
                  },
                },
              },
              "application/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/User",
                  },
                },
              },
              "text/json": {
                schema: {
                  type: "array",
                  items: {
                    $ref: "#/components/schemas/User",
                  },
                },
              },
            },
          },
        },
      },
    },
  },
  components: {
    schemas: {
      ErrorResult: {
        type: "object",
        properties: {
          message: {
            type: "string",
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      Login: {
        type: "object",
        properties: {
          email: {
            type: "string",
            nullable: true,
          },
          password: {
            type: "string",
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      PartnerListItem: {
        type: "object",
        properties: {
          id: {
            type: "string",
            nullable: true,
          },
          name: {
            type: "string",
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      ProjectListItem: {
        type: "object",
        properties: {
          id: {
            type: "string",
            nullable: true,
          },
          name: {
            type: "string",
            nullable: true,
          },
          nameExternal: {
            type: "string",
            nullable: true,
          },
          type: {
            type: "string",
            nullable: true,
          },
          status: {
            type: "integer",
            format: "int32",
          },
          partnerId: {
            type: "string",
            nullable: true,
          },
          partnerName: {
            type: "string",
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      Ticket: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          subject: {
            type: "string",
            nullable: true,
          },
          isClosed: {
            type: "boolean",
            readOnly: true,
          },
          projectId: {
            type: "string",
            nullable: true,
          },
          projectName: {
            type: "string",
            nullable: true,
          },
          projectNameExternal: {
            type: "string",
            nullable: true,
          },
          projectType: {
            type: "string",
            nullable: true,
          },
          partnerId: {
            type: "string",
            nullable: true,
          },
          isForOffer: {
            type: "boolean",
            readOnly: true,
          },
          offerId: {
            type: "integer",
            format: "int32",
            nullable: true,
            readOnly: true,
          },
          offerNumber: {
            type: "integer",
            format: "int32",
            nullable: true,
            readOnly: true,
          },
          items: {
            type: "array",
            items: {
              $ref: "#/components/schemas/TicketItem",
            },
            nullable: true,
          },
          users: {
            type: "array",
            items: {
              $ref: "#/components/schemas/TicketUser",
            },
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      TicketItem: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          text: {
            type: "string",
            nullable: true,
          },
          creator: {
            type: "string",
            nullable: true,
            readOnly: true,
          },
          creatorIni: {
            type: "string",
            nullable: true,
            readOnly: true,
          },
          creatorIsInternal: {
            type: "boolean",
            readOnly: true,
          },
          createdDate: {
            type: "string",
            format: "date-time",
            readOnly: true,
          },
          isInternal: {
            type: "boolean",
            readOnly: true,
          },
          files: {
            type: "array",
            items: {
              $ref: "#/components/schemas/TicketItemFile",
            },
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      TicketItemFile: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          name: {
            type: "string",
            nullable: true,
          },
          url: {
            type: "string",
            nullable: true,
          },
          fileType: {
            type: "string",
            nullable: true,
          },
          isImage: {
            type: "boolean",
          },
        },
        additionalProperties: false,
      },
      TicketListItem: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          subject: {
            type: "string",
            nullable: true,
          },
          projectId: {
            type: "string",
            nullable: true,
          },
          projectName: {
            type: "string",
            nullable: true,
          },
          projectNameExternal: {
            type: "string",
            nullable: true,
          },
          projectType: {
            type: "string",
            nullable: true,
          },
          creatorFirstName: {
            type: "string",
            nullable: true,
          },
          creatorLastName: {
            type: "string",
            nullable: true,
          },
          createdDate: {
            type: "string",
            format: "date-time",
          },
          creatorIsInternal: {
            type: "boolean",
          },
          lastActivityDate: {
            type: "string",
            format: "date-time",
            nullable: true,
          },
          lastUserFirstName: {
            type: "string",
            nullable: true,
          },
          lastUserLastName: {
            type: "string",
            nullable: true,
          },
          lastUserIsInternal: {
            type: "boolean",
          },
          lastItemId: {
            type: "integer",
            format: "int32",
          },
          lastItemText: {
            type: "string",
            nullable: true,
          },
          partnerId: {
            type: "string",
            nullable: true,
          },
          partnerName: {
            type: "string",
            nullable: true,
          },
          isClosed: {
            type: "boolean",
          },
          closedDate: {
            type: "string",
            format: "date-time",
            nullable: true,
          },
          offerRequestId: {
            type: "integer",
            format: "int32",
            nullable: true,
          },
          offerRequestDate: {
            type: "string",
            format: "date-time",
            nullable: true,
          },
          itemsCount: {
            type: "integer",
            format: "int32",
          },
        },
        additionalProperties: false,
      },
      TicketUser: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          firstName: {
            type: "string",
            nullable: true,
          },
          lastName: {
            type: "string",
            nullable: true,
          },
        },
        additionalProperties: false,
      },
      User: {
        type: "object",
        properties: {
          id: {
            type: "integer",
            format: "int32",
          },
          firstName: {
            type: "string",
            nullable: true,
          },
          lastName: {
            type: "string",
            nullable: true,
          },
          isInternal: {
            type: "boolean",
          },
          isArchived: {
            type: "boolean",
          },
        },
        additionalProperties: false,
      },
    },
    securitySchemes: {
      Bearer: {
        type: "apiKey",
        description: "Please insert JWT with Bearer into field",
        name: "Authorization",
        in: "header",
      },
    },
  },
  security: [
    {
      Bearer: [],
    },
  ],
} as const;
