__int64 __fastcall extract_roam_ml_info_tlv(
        int a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        char a13)
{
  __int64 v14; // x4
  char v17; // w20
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x9
  unsigned __int8 i; // w10
  __int64 v25; // x0
  unsigned __int8 v26; // w0
  unsigned int v27; // w1
  unsigned int v28; // w1

  if ( !a2 )
    return 4;
  v14 = *(unsigned int *)(a2 + 408);
  if ( !*(_QWORD *)(a2 + 400) || !(_DWORD)v14 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Empty roam ml info param buf :%d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_roam_ml_info_tlv",
      v14);
    return 4;
  }
  v17 = a13;
  qdf_mem_set(a3, 0x50u, 0);
  v23 = *(_QWORD *)(a2 + 400);
  if ( v23 )
  {
    for ( i = 0; *(_DWORD *)(a2 + 408) > (unsigned int)i; ++i )
    {
      if ( (*(_DWORD *)(v23 + 12) & 0x3F) == v17 )
      {
        v25 = a3[1];
        *a3 = 1;
        if ( (unsigned int)v25 >= 3 )
        {
          __break(0x5512u);
          return wmi_fill_keys_from_tlv(v25, v19, v20, v21, v22);
        }
        v20 = (__int64)&a3[24 * (unsigned int)v25 + 8];
        v26 = v25 + 1;
        *(_BYTE *)(v20 + 6) = (*(_DWORD *)(v23 + 12) >> 10) & 0xF;
        v27 = ((*(_DWORD *)(v23 + 12) >> 7) & 7) - 1;
        if ( v27 >= 3 )
          v27 = 3;
        *(_DWORD *)(v20 + 8) = v27;
        *(_BYTE *)(v20 + 7) = (*(_DWORD *)(v23 + 12) & 0x40) == 0;
        *(_WORD *)v20 = *(_DWORD *)(v23 + 4);
        *(_BYTE *)(v20 + 2) = *(_WORD *)(v23 + 6);
        *(_BYTE *)(v20 + 3) = *(_BYTE *)(v23 + 7);
        *(_WORD *)(v20 + 4) = *(_DWORD *)(v23 + 8);
        v28 = *(_DWORD *)(v23 + 12);
        *(_QWORD *)(v20 + 16) = a12;
        a3[1] = v26;
        v19 = (unsigned __int16)(v28 >> 14);
        *(_DWORD *)(v20 + 12) = v19;
      }
      v23 += 16;
      if ( !v23 )
        return 0;
    }
  }
  return 0;
}
