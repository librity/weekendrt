/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 03:07:18 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 03:17:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef int (*Operation)(int a, int b);

typedef struct _str
{
	int result;	   // to sotre the resut
	Operation opt; // funtion pointer

} STR;

int Add(int a, int b)
{
	return a + b;
}

int Multi(int a, int b)
{
	return a * b;
}

int main(int argc, char **argv)
{
	STR str_obj;
	str_obj.opt = Add; //the function pointer variable point to Add function
	str_obj.result = str_obj.opt(5, 3);
	printf(" the result is %d\n", str_obj.result);
	str_obj.opt = Multi; //the function pointer variable point to Multi function
	str_obj.result = str_obj.opt(5, 3);
	printf(" the result is %d\n", str_obj.result);
	return 0;
}
