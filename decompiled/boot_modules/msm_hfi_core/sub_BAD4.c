__int64 __usercall sub_BAD4@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X3>, int a5@<W8>)
{
  unsigned int v5; // w17
  unsigned int *v6; // x19

  atomic_load(v6);
  return set_tx_buffer(a1, a2, a3, a4, v5 ^ __ROR4__(a5, 28));
}
