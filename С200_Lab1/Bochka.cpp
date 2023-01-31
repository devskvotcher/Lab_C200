#include "Bochka.h"
#include <iostream>

Bochka::Bochka(float concentration, unsigned int kruzhka, unsigned int ob_em)
{
	Bochka::concentration = concentration;
	Bochka::kruzhka = kruzhka;
	Bochka::ob_em = ob_em;
	
}

void Bochka::Pereliv(Bochka& other)
{
	
	Bochka::concentration = (other.concentration + Bochka::ob_em * Bochka::concentration) / (Bochka::ob_em + Bochka::kruzhka);

	Bochka::ob_em += Bochka::kruzhka;											// ��������� ������ � ������
	other.ob_em -= Bochka::kruzhka;										 	// ������� ������ �� ������	
		
}

float Bochka::GetConcentration() const
{
	return Bochka::concentration;
}



