#include "../include/int_ranges.h"

namespace ir {
	/// A funcao nega o sinal de todos os elementos do intervalo [first, last)
	void negate( value_type * first, value_type * last )
	{
		while(first != last)
			*first++ *= -1;
	}

	/// A funcao retorna um ponteiro para o menor valor do intervalo [first, last)
	const value_type * min( const value_type* first, const value_type* last )
	{
		const value_type *menor = first;

		while(first != last)
		{
			if(*first < *menor)
				menor = first;

			first++;
		}

		return menor;
	}

	/// A funcao inverte a ordem dos elementos do intervalo [first, last)
	void reverse( value_type *first, value_type*last )
	{
		value_type dis = std::distance(first, last)/2;

		for(value_type i=0; i<dis; i++)
			std::swap(*(first+i), *(last-i-1));
	}

	/// A funcao multiplica cada elemento do intervalo [first, last) por uma constante
	void scalar_multiplication( value_type * first, value_type * last, value_type scalar )
	{
		while(first != last)
			*first++ *= scalar; 
	}

	/// A funcao calcula e retorna o produto escalar entre os dois vetores
	value_type dot_product( const value_type *a_first, const value_type *a_last, const value_type *b_first )
	{
		value_type dis = std::distance(a_first, a_last);
		value_type prod{0};

		if(value_type i=0; i<dis; i++)
			prod += (*a_first+i)*(*b_first+i);

		return prod;
	}

	/// A funcao 'compacta' os elementos do intervalo [first, last) e retorna um ponteiro para o elemento imediatamente posterior ao ultimo elemento compactado  
	void compact( value_type *first, value_type *last )
	{
		value_type *aux = first;

		while(first != last)
		{
			if(*first > 0)
			{
				*aux = *first;
				aux++;
			}

			first++;
		}

		return aux;
	}

	/// A funcao copia os elementos do intervalo [first, last) para outro intervalo começando em 'd_first'
	value_type * copy( const value_type * first, const value_type *last, value_type *d_first )
	{
		value_type dis = std::distance(first, last);
		
		for(value_type i=0; i<dis; i++)
			d_first[i] = *(first+i);
				
		value_type *d_last = &d_first[dis];
		
		return d_last;
	}

	/// A funcao elimina repitiçoes de elementos no intervalo [first, last) 
	value_type * unique( value_type * first, value_type * last )
	{	
		value_type *cp = first; 
		value_type *aux = first; 
		value_type cont = 0; 
		
		while(first != last)
		{
			if(cont == 0)
				aux++;
			else {
				for(value_type i=0; i<cont; i++)
				{
					if(*first == *(cp+i))
						break;
					else if(*first != *(cp+i) && i == cont-1)
					{
						*aux = *first;
						aux++;
					}
				}
			}

			first++;
			cont++;
		}

		return aux;
	}

	/// A funcao reordena os elementos do intervalo [first, last) pela cor, pretos e brancos, respectivamente 
	value_type * sort_marbles( value_type * first, value_type * last )
	{
		value_type *aux = first;
		value_type *cp = first;
		value_type cont = 0;

		while(aux != last)
		{
			if(*first == 1 && *aux == 0){
				std::swap(*first, *aux);
				first++;
			}
		
			aux++;
		
			if(*first == *(first+1)){
				cont++;
			}
		}
		
		if(cont == std::distance(first, last) && *(last-1)==1)
			return last;		
		else if(cont == std::distance(first, last) && *(last-1)==0)	
			return cp;
		
		return first;
	}

	/// A funcao reordena os elementos do intervalo [first, last) com base em um valor 'pivot' passado
	void partition( value_type * first, value_type * last, value_type * pivot )
	{
		value_type aux;
		value_type i, j;

		for (i=1; i<std::distance(first, last); i++)
		{
			j = i;
			while(j>0 && first[j-1] > first[j])
			{
				aux = first[j];
				first[j] = first[j-1];
				first[j 1] = aux;
				j--;
			}
		}
	}

	/// A funcao realiza uma rotacao à esquerda dos elementos do intervalo [first, last)
	value_type * rotate( value_type *first, value_type *n_first, value_type *last )
	{
		int *aux = new int[(n_first-first)];
		copy(first, first + (n_first-first), aux);

		while(n_first<last)
		{
			*first = *(first+(n_first - first));
			first++;
			n_first++;
		}
		
		while(first<last)
		{
			*first = *aux;
			aux++;
			first++;
		}
	}

}
