## Adapter Pattern
**Prototype** is a structural desing pattern that allows object with imcompatible interfaces to collaborate.

Problems:
 * Imagine you want to integrate a 3rd-party library to your app. But the library works with different format. You need to add an adapter for compatible with your app.
 
 
 #### Identification
 Adapter is recognizable by a constructor which takes an instance of different abstract/interface type. When adapter receives a call to any of its methods, it translates parameters to the appropriate format and then directs the call to one or several methods of wrapped object.