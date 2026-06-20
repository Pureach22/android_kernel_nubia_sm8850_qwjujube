__int64 __fastcall clk_rcg2_enable(__int64 a1)
{
  __int64 v2; // x20
  __int64 freq; // x0
  __int64 *v4; // x21
  __int64 result; // x0
  unsigned int v6; // w20

  if ( (*(_BYTE *)(a1 + 152) & 1) != 0 )
    clk_rcg2_set_force_enable(a1);
  if ( *(_BYTE *)(a1 - 16) != 1 )
    goto LABEL_13;
  v2 = *(_QWORD *)(a1 - 24);
  freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
  if ( !freq )
    return 4294967274LL;
  if ( v2 == cxo_f )
    v4 = &cxo_f;
  else
    v4 = (__int64 *)freq;
  if ( (*(_BYTE *)(a1 + 152) & 1) == 0 )
    clk_rcg2_set_force_enable(a1);
  result = clk_rcg2_configure(a1 - 48, v4);
  if ( (*(_BYTE *)(a1 + 152) & 1) == 0 )
  {
    v6 = result;
    regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 0, 0, 0, 0);
    result = v6;
  }
  if ( !(_DWORD)result )
  {
LABEL_13:
    *(_BYTE *)(a1 + 155) = 1;
    return 0;
  }
  return result;
}
