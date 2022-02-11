/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artblin <artblin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 01:45:55 by artblin           #+#    #+#             */
/*   Updated: 2022/02/07 06:51:49 by artblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define G(a)goto a
#define E(a)return(a)
#define S(a)sizeof(a)
#define T(a)int a
#define x main
#define m malloc
#define sr srand
#define p printf
#define f free
#define t time
#define r rand
#define N 0
#define R 1
#define X 0
#define Z 1
#define M 3
#define W " "
#define Vo void
#define In int
#define Ch char

In main(int ac,char **av){
	if(ac^3)E(1);
	T(a[2])={0,0};
	T(i[2])={1,0};
	c:if(*(av[i[X]])){
		if((*(av[i[X]])^'0')<10){
			a[i[Z]]*=10;a[i[Z]]+=(*(av[i[X]])-'0');
		}++(av[i[X]]);G(c);
	}if(i[X]++==1&&!i[Z]++)G(c);
	T(*s)=m(S(In)*a[N]);
	sr(t((Vo*)0));
	if(a[N]>((a[R]<<1)+1))E(1);
	i[X]=0;
	g:if(i[X]<a[N]){
		i[Z]=0;
		s[i[X]]=(r()%(a[R]+1));
		if(!(r()%(M)))s[i[X]]*=(-1);
		t:if(i[Z]<i[X]){
			if(s[i[X]]==s[i[Z]])G(g);
			i[Z]++;G(t);
		}i[X]++;G(g);
	}i[X]=0;
	p:if(i[X]<a[N]){
		p("%d",s[i[X]]);
		if(i[X]^a[N]-1)p(W);
		i[X]++;G(p);
	}if(s)f(s);
	E(0);}
