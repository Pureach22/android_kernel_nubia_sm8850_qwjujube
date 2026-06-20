__int64 __fastcall extract_big_data_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10,
        _DWORD *a11)
{
  _DWORD *v11; // x9
  _DWORD *v12; // x8
  const char *v14; // x2

  if ( a10 )
  {
    v11 = (_DWORD *)*a10;
    if ( *a10 )
    {
      v12 = (_DWORD *)a10[4];
      if ( v12 )
      {
        *a11 = v11[1];
        a11[2] = v11[3];
        a11[1] = v11[2];
        a11[3] = v12[1];
        a11[4] = v12[2];
        a11[5] = v12[3];
        a11[6] = v12[4];
        a11[7] = v12[5];
        return 0;
      }
      v14 = "%s: invalid dp stats param";
    }
    else
    {
      v14 = "%s: invalid fixed param";
    }
  }
  else
  {
    v14 = "%s: invalid buffer";
  }
  qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_big_data_stats_tlv");
  return 16;
}
