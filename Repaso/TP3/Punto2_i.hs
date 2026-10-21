contarDigitos :: Int -> Int
contarDigitos n
 | n == 0 = 0
 | otherwise = 1 + contarDigitos (div n 10)

productoDeDigitos :: Int -> Int
productoDeDigitos 0 = 0
productoDeDigitos n = productoDeDigitos' n
 where
  productoDeDigitos' 0 = 1
  productoDeDigitos' n = (mod n 10) * productoDeDigitos' (div n 10)
  
tieneCeros :: Int -> Bool
tieneCeros 0 = True
tieneCeros n
 | n < 10 = False
 | otherwise = (mod n 10) == 0 || tieneCeros (div n 10)
 
encontrarMenor :: Int -> Int
encontrarMenor n
 | n < 10 = n
 | otherwise = (if (mod n 10) < encontrarMenor (div n 10) then mod n 10 else encontrarMenor (div n 10))
 
crearLista :: Int -> [Int]
crearLista 0 = []
crearLista n = [1..n]

divisionEntera :: Int -> Int -> Int
divisionEntera n 0 = 0
divisionEntera n x =  (if n-x < 0 then 0 else 1 + divisionEntera (n-x) x)