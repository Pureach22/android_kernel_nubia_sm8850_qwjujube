__int64 __usercall sub_1C4558@<X0>(int a1@<W8>)
{
  __int64 v1; // x16

  *(_DWORD *)(v1 + 124) = a1;
  *(_DWORD *)(v1 + 128) = v1;
  return dsi_pll_program_slave();
}
