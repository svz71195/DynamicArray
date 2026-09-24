# Dynamic Arrays in C
Small header only implementation for Dynamic Arrays using some C23 features. Heavily inspired by tsoding's implementation in nob and stb_bs. See tests on how to use.

## Implementation
* "DynamicArra.def": Contains a standardized struct needing a #define of data TYPE and NAME (see DynamicArray.h for example)
* "DynamicArray.h": Contains typeagnostic macro implementation of common Array operations

## Usage
Copy DynamicArray.def and DynamicArray.h into your project and customize to your needs. Since some C23 features are present, compiler needs to support it.
