__int64 __usercall sub_168AA4@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X3>, int a5@<W8>)
{
  int v5; // w11

  return hif_disable_interrupt(a1, a2, a3, a4, a5 ^ (unsigned int)~__ROR4__(v5, 23));
}
