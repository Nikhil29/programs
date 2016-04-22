#!/usr/bin/env python

def insertsym(symTab, label, value, location, length):
	sym = [value, location, length]
	symTab[label] = sym

def deletesym(symTab, label):
	if symTab.__contains__(label):
		symTab.__delitem__(label)

def updateValueInsymTab(symTab, label, newValue):
	if symTab.__contains__(label):
		symTab[label][0] = newValue

def updateLocationInsymTab(symTab, label, newLocation):
	if symTab.__contains__(label):
		symTab[label][1] = newLocation

def printsymTab(symTab):
	for sym in symTab:
		print sym,symTab[sym]

# Machine Operation Tab Initialisation
def initialiseMacOpTab(macOpTab):
	macOpTab['mov'] = 00
	macOpTab['load'] = 01
	macOpTab['store'] = 02
	macOpTab['add'] = 03
	macOpTab['sub'] = 04
	macOpTab['mul'] = 05
	macOpTab['xor'] = 06

if __name__=="__main__":
	symTab = {}
	insertsym(symTab, 'a', 34, 2345, 2)
	printsymTab(symTab)
	deletesym(symTab, 'b')
	printsymTab(symTab)
	updateValueInsymTab(symTab, 'a', 33)
	updateLocationInsymTab(symTab, 'a', 56)
	printsymTab(symTab)