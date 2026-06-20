__int64 __fastcall icc_clk_get_bw(__int64 a1, __int64 a2, _DWORD *a3)
{
  _QWORD *v3; // x8
  unsigned __int64 v5; // x8

  v3 = *(_QWORD **)(a1 + 112);
  if ( v3 && *v3 )
    v5 = clk_get_rate() / 0x3E8uLL;
  else
    LODWORD(v5) = 0x7FFFFFFF;
  *a3 = v5;
  return 0;
}
