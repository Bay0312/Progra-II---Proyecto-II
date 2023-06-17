/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 4-0254-0670 David Calvo H. grupo 02
* 7-0300-0234 Bayron Vega A. grupo 03
*
* -------------------------------------------------------------------
*/

#include <iostream>
#include <sstream>
#include <locale.h>
#include "Sistema.h"
#include "Fuente.h"
#include "PlantillaLista.h"
#include "Parlante.h"
#include "Componente.h"
#include "Iterador.h"
#include "Menu.h"

int main() {
	setlocale(LC_CTYPE, "Spanish"); //Define el español como lenguaje del programa, permitiendo imprimir letras tildadas, "ñ", "¿" y demás.


	Menu* menu = new Menu(); 

	menu->menuPrincipal(); 
	
	delete menu;

	//Si algo pasara con el archivo, es posible hacer con lo siguiente una carga rapida, solo hay que ponerlo en el menu principal:

	/*tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad CD", "DF531", "Unidad básica", "001", 100.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad CD", "MT909", "Protección de salto", "002", 150.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad CD", "CE230", "Múltiples velocidades", "003", 175.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad CD", "YF292", "Soporte SACD", "004", 200.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Tornamesa", "FF211", "Unidad básica 33/56 RPM", "005", 180.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Tornamesa", "HA401", "Soporte 78 RPM", "006", 230.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Tornamesa", "EG266", "Brazo automático", "007", 320.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Radio", "NW671", "Básico AM/FM", "008", 90.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Radio", "JU272", "Onda corta", "009", 300.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Radio", "OE214", "Sintonizador automático", "010", 220.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Radio", "LZ248", "Sintonizador programable", "011", 280.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad Bluetooth", "YM396", "Básico", "012", 70.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad Bluetooth", "CE169", "Multicanal", "013", 100.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Unidad Bluetooth", "HN871", "Receptor FM", "014", 90.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Micrófono", "GX610", "Alámbrico", "015", 90.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Micrófono", "HE601", "Alámbrico omnidireccional", "016", 95.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Micrófono", "EO222", "Inalámbrico", "017", 120.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Micrófono", "IS308", "Inalámbrico rango ampliado", "018", 180.00));
	tienda->agregarProductosCat(new Fuente("Fuente de Audio", "Micrófono", "UK405", "Inalámbrico Bluetooth", "019", 100.00));

	tienda->agregarProductosCat(new Procesador("Procesador", "Amplificador", "CA188", "80W", "020", 90.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Amplificador", "SK956", "100W", "021", 115.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Amplificador", "JV322", "200W", "022", 140.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Amplificador", "UI569", "220W", "023", 165.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Amplificador", "YV439", "400W", "024", 190.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Mezclador", "JC327", "2 canales analógicos", "025", 70.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Mezclador", "XJ941", "2 canales digitales", "026", 85.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Mezclador", "DB258", "4 canales analógicos", "027", 130.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Mezclador", "AN918", "4 canales digitales", "028", 150.0));
	tienda->agregarProductosCat(new Procesador("Procesador", "Mezclador", "AI821", "8 canales (digital/analógico)", "029", 325.0));

	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "MK537", "200W", "030", 235.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "WR390", "400W", "031", 275.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "SE772", "400W perfil plano", "032", 315.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "HT863", "400W inalámbrico", "033", 355.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "SN791", "300W 4 canales", "034", 395.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Parlante", "EA457", "280W subwoofer", "035", 435.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "UK930", "Básico (intraural)", "036", 20.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "DV270", "Básico (supraural, diadema)", "037", 40.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "AA891", "Básico (circumaural)", "038", 45.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "SZ314", "Básico (inalámbrico)", "039", 60.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "OC829", "Circumaural bajos profundos", "040", 90.0));
	tienda->agregarProductosCat(new Parlante("Parlante", "Audífono", "YG838", "Inalámbrico bajos profundos", "041", 120.0));*/

	
	return 0;
}