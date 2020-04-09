// UVM Plantel....: Hispano
// Carrera........: Ingeniería en Sistemas Computacionales
// Materia........: Programación Orientada a Objetos
// Profesor.......: Jorge Alberto Flores Quintana
// Fecha..........: 2020/04/08
// Programador(es): Jorge Alberto Flores Quintana 66384419 jorge_floresq@my.uvm.edu.mx
// Programa.......: charES_MX.cpp
// Propósito......: Programa que muestra el uso de las librerías local para mostrar cadenas de caracteres 
//                  en español (Versión C++/C)
//                  Basado en https://stackoverflow.com/questions/2492077/output-unicode-strings-in-windows-console-app
//                            http://www.angelikalanger.com/Articles/Cuj/Internationalization/I18N.html
// Versión........: 1.0     Version inicial
//                  

#include <iostream>
#include <string>
#include <locale>
#include <locale.h>

constexpr auto STR_LOCALE_MX = "es_MX.utf8";		// código de caracteres UNICODE para consola

int main(void)
{
	// Se reemplaza el locale global de C++ para mostrar caracteres español (tiene que ser "es_MX.utf8)
	std::locale::global(std::locale(STR_LOCALE_MX));		// para C++
	setlocale(LC_ALL, STR_LOCALE_MX);						// para C y C++ que se sincronicen con stdio

	// Opcional: Se activa el locale para la saluda con cout (Si se quita no tiene efecto sobre los números)
	std::cout.imbue(std::locale());

	// ejemplo de uso para mostrar el locale configurado
	std::cout << "El parámetro de locale actual es " << std::locale().name().c_str() << std::endl;

	// se muestra información que puede ser afectada por el locale
	const char car = (char)64;				// caracter @
	const int entero = 1234;				// numero entero cualquiera
	const float flotante = 3.1515926f;		// pi
	const double doble = 3e9;				// velocidad de la luz
	const std::string cad1 = "México";
	const std::string cad2 = "aeiouun - áéíóúüñ - ÁÉÍÓÚÜÑ";

	std::cout << car << std::endl;
	std::cout << entero << std::endl;
	std::cout << flotante << std::endl;
	std::cout << doble << std::endl;
	std::cout << cad1 << std::endl;
	std::cout << cad2 << std::endl;

	return EXIT_SUCCESS;
}
