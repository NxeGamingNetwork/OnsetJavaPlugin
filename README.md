# OnsetJavaPlugin
Authors: JanHolger, Digital

### Features
* Create JVMs.
* Communicate from Lua <-> Java.

### Data Types we support
#### Method Parameters
* String (java.lang.String)
* Integer (java.lang.Integer)

#### Return Values
* String (java.lang.String)
* Integer (java.lang.Integer)

We will be adding more data types later on.

### Lua Functions
#### CreateJava
Create a new JVM with a jar. Returns JVM ID.
```lua
CreateJava(path)
```
* **path** Relative path to the jar file, relative from the root server directory. Example: path/to/file.jar

#### DestroyJava
Destroy a JVM.
```lua
DestroyJava(jvmID)
```
* **jvmID** ID to the JVM you have created using CreateJava.

#### CallJavaStaticMethod
Destroy a JVM.
```lua
CallJavaStaticMethod(jvmID, className, methodName, methodSignature, args...)
```
* **jvmID** ID to the JVM you have created using CreateJava. Example: 1
* **className** Class name of the class you want to call a method in, must include package path as well. Example: dev/joseph/Test (dev.joseph.Test).
* **methodName** Static method name you want to call. Example: returnTestInt
* **methodSignature** Signature of the method you want to call. Example: (Ljava/lang/Integer;)I
* **args (Optional)** Pass arguments into the method.


