#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
	using value_type = int;
	
	/// A funcao nega o sinal de todos os elementos do intervalo [first, last)
	void negate( value_type * first, value_type * last );

	/// A funcao retorna um ponteiro para o menor valor do intervalo [first, last)
	const value_type * min( const value_type * first, const value_type * last);

	/// A funcao inverte a ordem dos elementos do intervalo [first, last)
	void reverse( value_type *first, value_type*last );

	/// A funcao multiplica cada elemento do intervalo [first, last) por uma constante
	void scalar_multiplication( value_type * first, value_type * last, value_type scalar );

	/// A funcao calcula e retorna o produto escalar entre dois vetores
	value_type dot_product( const value_type *a_first, const value_type *a_last, const value_type *b_first );

	/// A funcao copia os elementos do intervalo [first, last) para outro intervalo começando em 'd_first'
	value_type * copy( const value_type * first, const value_type * last, value_type *d_first );

	/// A funcao elimina repitiçoes de elementos no intervalo [first, last)
	value_type * unique( value_type * first, value_type * last );

	/// A funcao reordena os elementos do intervalo [first, last) pela cor, pretos e brancos, respectivamente
	value_type * sort_marbles( value_type * first, value_type * last );

	/// A funcao reordena os elementos do intervalo [first, last) com base em um valor 'pivot' passado
	void partition( value_type * first, value_type * last, value_type * pivot );

	/// A funcao realiza uma rotacao à esquerda dos elementos do intervalo [first, last)
	value_type * rotate( value_type *first, value_type *n_first, value_type *last );

}
#endif
