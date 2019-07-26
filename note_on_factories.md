07/24/2019

Review of Krishna's Factory_Method Course

From what I understand so far, using a factory is useful because it makes the "main" (client side implementation) simpler and cleaner. If a factory is not used, there will be lots of if statements in the main, and if a new class is added, the client has to update the main and add more if statements. So basically the idea is to take all the if statements out of the main and place them in a separate function or class. In that case, the client does not have to change anything if a new class is added.

Krishna's Factories:

1. Simple: In this code, first you need to make a pointer (e.g. newcourse) to the base factory (e.g. CourseFactory) by calling a static function of that class (e.g. create_course) and pass it the class name you want (e.g. C++ or Java). This will direct you to the appropriate derived factory (e.g. either CppFactory or JavaFactory) based on the class name you passed. Then you need to make another pointer (e.g. course) to the actual base class (e.g. Course) by calling a function in the derived factory (e.g. generatecourse). This will direct you to the actual class you are looking for (e.g. either Cpp or Java).

* This doesn't actually look that simple, and it seems like it has redundant steps. I am not sure why Krishna thought this was simple. I think when I asked him he said something like "constructors are the reason", but I'm not sure what that means.

2. Intermediate: This is actually a simplified version of the last code. In this code the derived factories have been eliminated, so you don't need to first point to the derived factories and then point to the derived classes from there. You just call a static function inside the factory (e.g. MyCourseFactory::generatecourse or if we want to use similar names as before CourseFactory::create_course), pass it the name of the class you want, and it will return a pointer to the appropriate derived class.

* The reason why we need to use a static member function in this factory is that we want to use the function without instantiating the factory class itself. The alternative would be to not have it static, but instantiate the class first and then use the dot operator. Something like below:

```cpp
MyCourseFactory factory();
auto mycourse = factory.generatecourse(coursename);
```

* Also I have tried removing the factory class and just having a stand-alone function and it works. I am not sure why we need to have this function inside a class instead of just having it on its own.

3. Advanced (**Using Map**): In this code you just need to pass the class name to a member function (e.g. Create) of the factory class and it will return a pointer to the class you want. In this code, the  client implementation has become very simple, but there is a lot going on in the background. Initially, before the code is executed, all classes need to be registered. This is done using a preprocessor called REGISTER_CLASS which takes the name and the type of the class as input and passes those to the constructor of a class called Registrar. The constructor of Registrar creates an instance of the factory class and calls the member function RegisterFactoryFunction which actually performs the registration. The RegisterFactoryFunction creates a map of the name of the class and a pointer to it, and stores it in factoryFunctionRegistry (in case it's not clear, factoryFunctionRegistry is a private member of the factory class which maps the name of each derived class to a pointer to it.). For all classes to be registered the preprocessor REGISTER_CLASS should be added to their implementation (e.g. REGISTER_CLASS("C++", Cpp)). This registration will take place in the compilation step, and when the code is executed, the Create function of the factory uses the existing factoryFunctionRegistry to find the appropriate pointer to the given class name.

* I am not sure why we can't call the RegisterFactoryFunction directly from the preprocessor and instead we have to instantiate the Registrar class first and then have the constructor of that class call RegisterFactoryFunction. But I guess that's the good way to do it beasue Krishna holds on to it in the more advanced codes coming up.

4. Advanced_Template: Very similar to the last code, the only difference is that the Registrar class has been templatized (the template is for the type of the derived class). Also, the register class is statically instantiated in the derived classes' implementations, which allows removing the REGISTER_CLASS preprocessor, because static instantiation of a class happens in compile time.

5. Generic_Method: In this code the factory has been templatized to accept any type of base class. Therefore this factory can be used to instantiate any derived classes from any base class just by using the key (e.g. name of the class).

6. Generic_Method_Constructor: Similar to the last code, but, in addition to the type of the base class, the factory can handle any type and number of arguments that the base class has. So this factory can be used for ANY code. You just need to make sure the classes are registered properly in their implementation files.
