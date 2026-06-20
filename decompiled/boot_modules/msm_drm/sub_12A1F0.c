__int64 __usercall sub_12A1F0@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, _DWORD *a4@<X3>, int a5@<W8>)
{
  int v5; // w11

  *a4 = v5;
  a4[1] = a5;
  return sde_connector_complete_commit(a1, a2, a3, a4 + 47);
}
