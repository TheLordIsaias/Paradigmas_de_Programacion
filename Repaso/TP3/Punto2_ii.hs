contar [] = 0
contar (x:xs) = 1 + contar xs

sumaDeElementosG :: [Int] -> Int
sumaDeElementosG xs
 | null xs = 0
 | length xs == 1 = (head xs)
 | otherwise = (head xs) + sumaDeElementosG (tail xs)

sumaDeElementosPM :: [Int] -> Int
sumaDeElementosPM [] = 0
sumaDeElementosPM (x:xs) = x + sumaDeElementosPM xs

filtrarLista1G xs i
 | null xs = []
 | length xs == 1 = (if head xs /= i then xs else [])
 | otherwise = (if head xs == i then filtrarLista1G (tail xs) i else (take 1 xs) ++ filtrarLista1G (tail xs) i)

filtrarLista1PM [] i = []
filtrarLista1PM (x:xs) i = (if x /= i then [x] else []) ++ filtrarLista1PM xs i

filtrarLista1LC xs i = [x | x <- xs , x /= i]

invertirLista xs
 | null xs = []
 | length xs == 1 = xs
 | otherwise = invertirLista (tail xs) ++ [head xs]


subLista1 xs n
 | null xs = []
 | n == 1 = [head xs]
 | n > 0 = [head xs] ++ subLista1 (tail xs) (n-1)
 
subLista2 xs n
 | null xs = []
 | n == 1 = [tail xs]
 | n > 0 = subLista2 (tail xs) (n-1)
 
interseccion xs1 xs2
 | null xs2 = []
 | null xs1 = []
 | length xs1 == 1 = (if elem (head xs1) xs2 then [head xs1] else [])
 | otherwise = (if elem (head xs1) xs2 then [head xs1] else []) ++ interseccion (tail xs1) xs2
 
subLista3 [] x n = []
subLista3 xs x 1 = (if (head xs) > x then [head xs] else [])
subLista3 xs x n = (if (head xs) > x then [head xs] ++ subLista3 (tail xs) x (n-1) else [] ++ subLista3 (tail xs) x (n-1))

verificar :: (a -> Bool) -> [a] -> Bool
verificar _ [] = True
verificar p (x:xs) = p x && verificar p xs

filtrarLista2G :: (a -> Bool) -> [a] -> [a]
filtrarLista2G _ [] = []
filtrarLista2G p (x:xs)
 | null xs = (if p x then [x] else [])
 | otherwise = (if p x then [x] else []) ++ filtrarLista2G p xs
 
filtrarLista2PM :: (a -> Bool) -> [a] -> [a]
filtrarLista2PM _ [] = []
filtrarLista2PM p (x:xs) = (if p x then [x] else []) ++ filtrarLista2PM p xs

filtrarLista2LC :: (a -> Bool) -> [a] -> [a]
filtrarLista2LC p xs = [x  | x <- xs, p x]

transformarG :: (a -> b) -> [a] -> [b]
transformarG f xs
 | null xs = []
 | null (tail xs) = [f (head xs)]
 | otherwise = [f (head xs)] ++ transformarG f (tail xs)
 
transformarPM :: (a -> b) -> [a] -> [b]
transformarPM _ [] = []
transformarPM f (x:xs) = [f x] ++ transformarPM f xs

transformarLC :: (a -> b) -> [a] -> [b]
transformarLC f xs = [f x | x <- xs]

tablaDeImpares :: Int -> [Int]
tablaDeImpares n = [x | x <- [0..n], mod x 2 /= 0]

paresOrdenados :: Int -> [(Int, Int)]
paresOrdenados z = [(x, y) | x <- [0..5], y <- [0..5], even x ,odd y ,x*y > z]

combinarG :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarG f xs1 xs2
 | null xs1 = []
 | null xs2 = []
 | otherwise = [f (head xs1) (head xs2)] ++ combinarG f (tail xs1) (tail xs2)

combinarPM :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarPM f [] xs2 = []
combinarPM f xs1 [] = []
combinarPM f xs1 xs2 = [f (head xs1) (head xs2)] ++ combinarG f (tail xs1) (tail xs2)

combinarLC :: (a -> b -> c) -> [a] -> [b] -> [c]
combinarLC f xs1 xs2 = [f (xs1 !! i) (xs2 !! i) | i <- [0.. min (length xs1) (length xs2) - 1]]

insertarLista xs1 xs2 n
 | n < 0 = []
 | null xs2 = []
 | otherwise = xs1 ++ drop n xs2
