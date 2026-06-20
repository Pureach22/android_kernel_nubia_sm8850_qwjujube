__int64 __usercall sub_1C9BC0@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, int a3@<W8>)
{
  __int64 v3; // x16

  *(_DWORD *)(v3 + 124) = a3;
  *(_DWORD *)(v3 + 128) = v3;
  return dsi_pll_4nm_program_slave(a1, a2);
}
