from distutils.core import setup, Extension

module1 = Extension(
	'pokoev', 
	 sources = ['multy.c'] 
)

setup(
	name = 'pokoev',              
	version = '1.2.1',               
	description = 'Simple module', 
	ext_modules= [module1]         
)