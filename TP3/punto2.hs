contarDigitos :: Int -> Int
contarDigitos 0 = 0
contarDigitos n = 1 + contarDigitos(div n 10)

productoDeDigitos :: Int -> Int
productoDeDigitos 0 = 1
productoDeDigitos n = (mod n 10) * productoDeDigitos (div n 10)

tieneCeros :: Int -> Bool
tieneCeros n
	| n == 0 = True
	| n < 10 = False
	| (mod n 10) == 0 = True
	| otherwise = tieneCeros (div n 10)
	
encontrarMenor :: Int -> Int
encontrarMenor n
	| n < 10 = n
	| otherwise = min (mod n 10) (encontrarMenor(div n 10))
	
crearLista :: Int -> [Int]
crearLista n = [1..n]

divisionEntera :: Int -> Int -> Int
divisionEntera x y
	| x < y = x
	| otherwise = 1 + divisionEntera (x-y) y

-- Listas

contar :: [Int] -> Int
contar [] = 0
contar (_:xs) = 1 + contar xs


sumaDeElementosGuards :: [Int] -> Int
sumaDeElementosGuards xs
 | null xs  = 0
 | otherwise = sum xs

sumaDeElementosPattern :: [Int] -> Int
sumaDeElementosPattern [] = 0
sumaDeElementosPattern xs = sum xs

filtrarLista1Guards :: [Int] -> Int -> [Int]
filtrarLista1Guards xs n
 | null xs = []
 | head xs == n = filtrarLista1Guards (tail xs) n
 | otherwise = (take 1 xs) ++ filtrarLista1Guards (tail xs) n
 
filtrarLista1Pattern :: [Int] -> Int -> [Int]
filtrarLista1Pattern [] n = []
filtrarLista1Pattern (x:xs) n = if x == n then filtrarLista1Pattern xs n else [x] ++ filtrarLista1Pattern xs n

filtrarLista1List :: [Int] -> Int -> [Int]
filtrarLista1List xs n = [ i | i <- xs, i /= n]

invertirLista :: [Int] -> [Int]
invertirLista xs
 | null xs = []
 | otherwise = ([last xs]) ++ invertirLista(init xs)
 
subLista1 :: [Int] -> Int -> [Int]
subLista1 xs n
 | null xs = []
 | n == 0 = []
 | otherwise = [head xs] ++ subLista1(tail xs) (n-1)
 
subLista2 :: [Int] -> Int -> [Int]
subLista2 xs n
 | null xs = []
 | n == 0 = xs
 | otherwise = subLista2(tail xs) (n-1)
 
interseccion :: [Int] -> [Int] -> [Int]
interseccion xs1 xs2
 | null xs1 || null xs2 = []
 | otherwise = if elem (head xs1) xs2 then [head xs1] ++ interseccion (tail xs1) xs2 else interseccion (tail xs1) xs2
 
subLista3 :: [Int] -> Int -> Int -> [Int]
subLista3 [] x n = []
subLista3 (h:xs) x n = if n == 0 then [] else if h > x then [h] ++ subLista3 xs x (n-1) else subLista3 xs x (n-1)

