__int64 __fastcall extract_dbr_buf_release_fixed_tlv(__int64 a1, __int64 a2, unsigned int *a3)
{
  _DWORD *v3; // x21
  __int64 (*v6)(void); // x8
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w8
  unsigned int v17; // w6
  const char *v18; // x2
  unsigned int v20; // w8
  unsigned int v21; // w9
  unsigned int v22; // w9
  unsigned int v23; // w9

  if ( !a2 )
    return 4;
  v3 = *(_DWORD **)a2;
  if ( !*(_QWORD *)a2 )
    return 4;
  v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3728LL);
  if ( *((_DWORD *)v6 - 1) != -2112860426 )
    __break(0x8228u);
  v7 = v6();
  *a3 = v7;
  a3[1] = v3[2];
  v16 = *(_DWORD *)(a2 + 24);
  if ( !v16 || (v17 = v3[3], v16 < v17) )
  {
    v18 = "%s: actual num of buf release entries less than provided entries";
LABEL_8:
    qdf_trace_msg(0x31u, 2u, v18, v8, v9, v10, v11, v12, v13, v14, v15, "extract_dbr_buf_release_fixed_tlv");
    return 4;
  }
  a3[2] = v17;
  v20 = *(_DWORD *)(a2 + 40);
  if ( !v20 || v20 < v3[4] )
  {
    v21 = *(_DWORD *)(a2 + 56);
    if ( !v21 || v21 < v3[4] )
    {
      v22 = *(_DWORD *)(a2 + 72);
      if ( !v22 || v22 < v3[4] )
      {
        v23 = *(_DWORD *)(a2 + 88);
        if ( !v23 || v23 < v3[4] )
        {
          v18 = "%s:  actual num of meta data entries less than provided entries";
          goto LABEL_8;
        }
      }
    }
  }
  a3[3] = v20;
  a3[4] = *(_DWORD *)(a2 + 56);
  a3[5] = *(_DWORD *)(a2 + 72);
  a3[6] = *(_DWORD *)(a2 + 88);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: pdev id %d mod id %d num buf release entry %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "extract_dbr_buf_release_fixed_tlv",
    v7);
  return 0;
}
