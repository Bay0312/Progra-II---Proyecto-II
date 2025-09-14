# 🎵 Audio Store Management System

> **Proyecto II - Programación II**: Sistema completo de gestión para tienda de equipos de audio desarrollado en **C++** con **patrones de diseño clásicos** y arquitectura **orientada a objetos**.

[![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91?style=flat&logo=visual-studio&logoColor=white)](https://visualstudio.microsoft.com/)
[![Windows](https://img.shields.io/badge/Windows-0078D6?style=flat&logo=windows&logoColor=white)](https://microsoft.com/windows)
[![Academic](https://img.shields.io/badge/Proyecto-Académico-green?style=flat)](https://github.com)

---

## 👥 Equipo de Desarrollo

<div align="center">
<table>
<tr>
<th>🧑‍💻 Desarrollador</th>
</tr>
<tr>
<td><b>David Calvo H.</b></td>
</tr>
<tr>
<td><b>Bayron Vega A.</b></td>
</tr>
</table>
</div>

---

## 📌 Descripción del Sistema

Sistema integral de **gestión comercial** para tienda de equipos de audio que implementa un **ecosistema completo** de venta, desde la catalogación de productos hasta la facturación final, utilizando principios sólidos de **ingeniería de software**.

### 🎯 **Objetivo Académico**
Demostrar competencias en **programación orientada a objetos**, **patrones de diseño** y **arquitectura de software** mediante un caso de uso real y complejo.

---

## ⚡ Funcionalidades del Sistema

<div align="center">
<table>
<tr>
<td align="center">🎛️<br><b>Catálogo Digital</b><br>Gestión completa de<br>componentes de audio</td>
<td align="center">🏬<br><b>Multi-Tienda</b><br>Control de inventarios<br>y sucursales</td>
<td align="center">👥<br><b>CRM Integrado</b><br>Clientes personas<br>y empresariales</td>
<td align="center">💰<br><b>Sistema de Ventas</b><br>Directas y en línea<br>con envíos</td>
</tr>
</table>
</div>

### 🛠️ **Características Técnicas**

#### 📦 **Gestión de Productos**
- **Componentes individuales:** Fuentes, procesadores, parlantes
- **Sistemas completos:** Configuraciones pre-armadas de audio
- **Inventario dinámico** con control de stock en tiempo real

#### 👤 **Administración de Clientes**
- **Personas naturales** con datos personales
- **Empresas** con información comercial
- **Sistema de notificaciones** automáticas de nuevos productos

#### 💳 **Módulo de Ventas**
- **Ventas directas:** Facturación inmediata en tienda
- **Ventas en línea:** Con cálculo automático de costos de envío
- **Registro temporal:** Trazabilidad completa de transacciones

#### 🔒 **Gestión de Errores**
- **Excepciones personalizadas** para casos específicos del dominio
- **Validación robusta** de datos de entrada
- **Prevención de duplicados** en el sistema

---

## 🏗️ Arquitectura y Patrones de Diseño

### 🎨 **Patrones Implementados**

<div align="center">
<table>
<tr>
<th>🔧 Patrón</th>
<th>📝 Implementación</th>
<th>🎯 Propósito</th>
</tr>
<tr>
<td><b>🌳 Composite</b></td>
<td><code>Sistema</code> + <code>Componente</code></td>
<td>Tratamiento uniforme de productos individuales y sistemas</td>
</tr>
<tr>
<td><b>🔄 Iterator</b></td>
<td><code>Iterador</code> + <code>IteradorLista</code></td>
<td>Recorrido consistente de colecciones personalizadas</td>
</tr>
<tr>
<td><b>👁️ Observer</b></td>
<td><code>Catalogo</code> → <code>Cliente</code></td>
<td>Notificación automática de nuevos productos</td>
</tr>
<tr>
<td><b>🎯 Strategy</b></td>
<td><code>VentaDirecta</code> / <code>VentaEnLinea</code></td>
<td>Algoritmos intercambiables de facturación</td>
</tr>
</table>
</div>

### 📂 **Estructura del Proyecto**

<details>
<summary><b>🗂️ Ver arquitectura completa</b></summary>

```
Proyecto II - Progra II/
├── 📄 Visual Studio Solution
│   ├── Proyecto II _ Progra II.sln
│   ├── .gitattributes
│   └── .gitignore
│
├── 🏗️ Arquitectura Core
│   ├── Componente.h/.cpp          # 🧩 Clase abstracta base
│   ├── Sistema.h/.cpp             # 🌳 Composite pattern
│   └── Excepciones.h/.cpp         # ⚠️ Manejo de errores
│
├── 📦 Componentes de Audio
│   ├── Fuente.h/.cpp              # 🔌 Fuentes de alimentación
│   ├── Procesador.h/.cpp          # 🖥️ Procesadores de audio
│   └── Parlante.h/.cpp            # 🔊 Sistemas de altavoces
│
├── 👥 Gestión de Clientes (Observer)
│   ├── Cliente.h/.cpp             # 👤 Interfaz cliente
│   ├── Persona.h/.cpp             # 🧑 Clientes individuales
│   └── Empresa.h/.cpp             # 🏢 Clientes corporativos
│
├── 🛒 Sistema Comercial
│   ├── Catalogo.h/.cpp            # 📋 Gestión de productos
│   ├── Tienda.h/.cpp              # 🏪 Orquestador principal
│   ├── Venta.h/.cpp               # 💰 Clase base ventas
│   ├── VentaDirecta.h/.cpp        # 🏬 Ventas en tienda
│   └── VentaEnLinea.h/.cpp        # 🌐 Ventas con envío
│
├── 🔧 Utilidades y Estructuras
│   ├── PlantillaLista.h           # 📝 Lista ligada custom
│   ├── Nodo.h                     # 🔗 Nodo de lista
│   ├── Iterador.h/.cpp            # 🔄 Iterator pattern
│   └── Fecha.h/.cpp               # 📅 Manejo temporal
│
├── 🖥️ Interfaz de Usuario
│   ├── Menu.h/.cpp                # 🎛️ Sistema de menús
│   └── Source.cpp                 # 🚀 Punto de entrada
│
└── 💾 Persistencia
    └── Datos guardados (texto plano)
```

</details>

---

## 🚀 Instalación y Ejecución

### 📋 **Requisitos del Sistema**

| Componente | Versión | Descripción |
|------------|---------|-------------|
| **Visual Studio** | 2019/2022+ | IDE principal con soporte C++ |
| **Windows SDK** | 10.0+ | APIs del sistema operativo |
| **C++ Standard** | C++14+ | Estándar del lenguaje |
| **Sistema Operativo** | Windows 10+ | Requerido para funciones específicas |

### 🛠️ **Pasos de Instalación**

#### 1️⃣ **Obtener el Código**
```bash
# Clonar repositorio
git clone [URL_DEL_REPOSITORIO]
cd "Proyecto II - Progra II"

# O descargar ZIP y extraer
```

#### 2️⃣ **Abrir en Visual Studio**
```
1. Abrir Visual Studio 2019/2022
2. File → Open → Project/Solution
3. Seleccionar: "Proyecto II _ Progra II.sln"
4. Esperar la carga completa del proyecto
```

#### 3️⃣ **Compilar y Ejecutar**
```
🔨 Compilar:  Ctrl + Shift + B  (Build Solution)
🚀 Ejecutar:  Ctrl + F5        (Start Without Debugging)
🐛 Debug:     F5               (Start Debugging)
```

### 🎮 **Navegación del Sistema**
Una vez ejecutado, el sistema presenta un **menú interactivo** que permite:
- Gestionar catálogo de productos
- Administrar clientes y notificaciones
- Procesar ventas directas y en línea
- Consultar historial de transacciones

---

## 📊 **Casos de Uso del Sistema**

<details>
<summary><b>🎯 Ver ejemplos de uso</b></summary>

### 🏪 **Gestión de Tienda**
```cpp
// Crear y configurar tienda
Tienda audioStore("TechSound Pro");
audioStore.agregarProducto(new Fuente("PSU-500W", 150.00));
audioStore.agregarProducto(new Parlante("Bookshelf-Deluxe", 300.00));
```

### 👥 **Registro de Clientes**
```cpp
// Cliente individual
Persona clientePersona("Juan Pérez", "12345678", "juan@email.com");

// Cliente empresarial  
Empresa clienteEmpresa("Studio Records", "987654321", "contacto@studio.com");

// Suscripción a notificaciones
catalogo.suscribirCliente(&clientePersona);
```

### 💰 **Procesamiento de Ventas**
```cpp
// Venta directa en tienda
VentaDirecta ventaTienda(cliente, productos, fecha, "Factura-001");

// Venta en línea con envío
VentaEnLinea ventaWeb(cliente, productos, fecha, "Dirección entrega", 25.00);
```

</details>

---

## 🧪 **Testing y Validación**

### 🔬 **Casos de Prueba**
- **Gestión de productos:** Agregar, modificar, eliminar componentes
- **Sistema Observer:** Verificar notificaciones automáticas
- **Cálculo de ventas:** Validar precios, descuentos, envíos
- **Excepciones:** Manejo de errores y casos límite

### 📊 **Métricas de Calidad**
- **Cobertura de código:** ~85% (estimado)
- **Patrones implementados:** 4 patrones GoF
- **Principios SOLID:** Aplicación parcial con mejoras identificadas

---

## 🎓 **Contexto Académico**

### 📚 **Curso:** Programación II
### 🏫 **Institución:** UNA
### 📅 **Período:** Semestre I / 2023

### 🎯 **Objetivos Pedagógicos Alcanzados**
- ✅ **OOP Avanzado:** Herencia, polimorfismo, abstracción
- ✅ **Design Patterns:** Implementación práctica de patrones GoF
- ✅ **Memory Management:** Gestión manual de memoria en C++
- ✅ **Software Architecture:** Separación de responsabilidades
- ✅ **Error Handling:** Excepciones personalizadas y robustez
---
