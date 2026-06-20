unsigned __int64 __fastcall scmi_clk_round_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x8

  v2 = *(_QWORD *)(a1 + 24);
  if ( (*(_BYTE *)(v2 + 68) & 1) != 0 )
    return a2;
  v4 = *(_QWORD *)(v2 + 80);
  result = v4;
  if ( v4 < a2 )
  {
    result = *(_QWORD *)(v2 + 88);
    if ( result > a2 )
      return v4 + (~v4 + a2 + *(_QWORD *)(v2 + 96)) / (unsigned int)*(_QWORD *)(v2 + 96) * *(_QWORD *)(v2 + 96);
  }
  return result;
}
