## DragonLang

The Dragon Language idea is to have all benofits of dynamic and static languages with low-level capabilities.

The possible syntax for this language should look like something like this:
```
#[feature:static] Staticly Typed feature of language
#[feature:dynamic] Dynamicly Typed feature of language
#[feature:unsafe] Unsafe feature of language
#[feature:library:no-std] For Micro Controllers, only libcore is supported
#[feature:memory:no-gc] No Garbage Collector
#[feature:language:python]
#[feature:language:javascript]
#[feature:language:typescript]
#[feature:language:cpp]

fun some_function()

empty_var? = None

fun some_function2()

type Integer:
    fun __add__(self)
    
    fun __sub__(self)


open class Object:
	  from "python@os" import read
	  fun __init__(self)

	  fun __init__(self)


extend Object:
	  from "javascript@./cool-library" import cool
	  from "typescript@https://deno.ts" import deno
	  fun new_method(self)

	  fun two(self)


let x = 8
Object.new_func = fun (): # Lambda function
	  return x


Object() # Value based object creation

unsafe stack 2424 # Allocate Stack Buffer

unsafe alloc 2424 # Heap buffer allocation with raw memory
unsafe alloc[global] 2424 # Heap buffer available cross Multi-Thread-s raw memory

alloc Object() # Reference counting
alloc[global] Object() # Multi-Thread Reference counting

new Object() # new Object(), Garbage Collector
new[global] Object() # Multi-Thread Garbage Collector

obj = new Object() # new Object(), Garbage Collector
new[global] Object() # Multi-Thread Garbage Collector

from "cpp@math.h" import cos
from "cpp@mod:std" import thread
from "cpp@thread" import thread

pub enum Token:
	  Keyword: str,


pub fun postive():
	  return n >= 0


pub fun postive(n):
	  return n >= 0


pub fun postive(ref n, t):
    return *n >= 0


pub coro fun fib(n: int) -> value0:Iterator[int], value1:int ~ CustomError:
    check positive: postive(n)

    raise CustomError()
    let name = 4
    name = 5 # Error, name is immutable
    let mut name2 = 4
    name2 = 8 # It is okay
    a, b = 0, 1
    while a < n:
    	await sfsas
      	yield a
      	a, b = b, a + b


fun __main__():
	return 8

a, b = 0, 1
```
Also you can find the syntax in Github Gists https://gist.github.com/redradist/e33c82ccd1d3348a15648f29d7445398
