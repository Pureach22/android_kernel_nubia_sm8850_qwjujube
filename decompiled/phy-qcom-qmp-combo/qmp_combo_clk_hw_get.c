__int64 __fastcall qmp_combo_clk_hw_get(__int64 a1, __int64 a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a1 + 12);
  if ( v2 == 2 )
    return a2 + 424;
  if ( v2 == 1 )
    return a2 + 400;
  if ( v2 )
    return -22;
  return a2 + 352;
}
