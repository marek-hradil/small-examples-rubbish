composee :: [a -> a] -> a -> a
composee [] = id
composee (x: xs) = x . composee xs