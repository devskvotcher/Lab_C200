#pragma once
class Bochka
{	
	float concentration;				
	unsigned int kruzhka;
	unsigned int ob_em;	
public:
	
	Bochka(float, unsigned int , unsigned int);

	void Pereliv(Bochka&);
	float GetConcentration() const;
};