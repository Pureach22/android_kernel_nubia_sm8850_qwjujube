__int64 __fastcall hdd_extract_sar_nested_attrs(
        _QWORD *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w8
  __int64 v13; // x9
  unsigned int v14; // w9
  __int64 v15; // x9
  unsigned int v16; // w9
  const char *v18; // x2

  a2[4] = 0;
  v10 = a1[7];
  if ( v10 || (v10 = a1[8]) != 0 )
  {
    a2[3] = *(_DWORD *)(v10 + 4);
    v11 = a1[4];
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 4);
      if ( v12 >= 2 )
      {
        v18 = "%s: Invalid SAR Band attr";
LABEL_14:
        qdf_trace_msg(0x33u, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_extract_sar_nested_attrs");
        return 0xFFFFFFFFLL;
      }
      *a2 = v12;
      LODWORD(v11) = 1;
      a2[4] = 1;
    }
    v13 = a1[5];
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 4);
      LODWORD(v11) = v11 | 2;
      a2[4] = v11;
      a2[1] = v14;
    }
    v15 = a1[6];
    if ( !v15 )
      return 0;
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 < 2 )
    {
      a2[2] = v16;
      a2[4] = v11 | 4;
      return 0;
    }
    v18 = "%s: Invalid SAR Modulation attr";
    goto LABEL_14;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: SAR Spec does not have power limit or index value",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_extract_sar_nested_attrs");
  return 4294967274LL;
}
