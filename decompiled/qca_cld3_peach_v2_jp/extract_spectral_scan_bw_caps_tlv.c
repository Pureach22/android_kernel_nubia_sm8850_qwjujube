__int64 __fastcall extract_spectral_scan_bw_caps_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w26
  unsigned int v15; // w9
  unsigned int *v16; // x8
  unsigned int v17; // w24
  __int64 v18; // x27
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x1
  char v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x9
  const char *v33; // x2
  __int64 v34; // [xsp+0h] [xbp-10h]

  if ( !a2 )
  {
    v33 = "%s: param_buf is NULL";
LABEL_14:
    qdf_trace_msg(0x31u, 2u, v33, a4, a5, a6, a7, a8, a9, a10, a11, "extract_spectral_scan_bw_caps_tlv");
    return 29;
  }
  if ( !a3 )
  {
    v33 = "%s: bw_caps is null";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a2 + 8) )
  {
    v14 = 0;
    do
    {
      v17 = v14;
      v18 = 20LL * (int)v14;
      v19 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3672LL);
      v20 = *(unsigned int *)(*(_QWORD *)a2 + v18 + 4);
      if ( *((_DWORD *)v19 - 1) != -2112860426 )
        __break(0x8228u);
      v21 = v19(a1, v20);
      v30 = a3 + 16LL * (int)v14;
      *(_BYTE *)v30 = v21;
      *(_DWORD *)(v30 + 4) = *(_DWORD *)(*(_QWORD *)a2 + v18 + 8);
      v31 = *(unsigned int *)(*(_QWORD *)a2 + v18 + 12);
      if ( (unsigned int)v31 <= 9 )
        v15 = dword_9E7138[v31];
      else
        v15 = 8;
      *(_DWORD *)(v30 + 8) = v15;
      *(_DWORD *)(v30 + 12) = *(_DWORD *)(*(_QWORD *)a2 + 20LL * (int)v14 + 16);
      v16 = (unsigned int *)(*(_QWORD *)a2 + 20LL * (int)v14);
      LODWORD(v34) = v16[4];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: bw_caps[%u]:: pdev_id:%u smode:%uoperating_bw:%u supported_flags:0x%x",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "extract_spectral_scan_bw_caps_tlv",
        v14++,
        v16[1],
        v16[2],
        v16[3],
        v34);
    }
    while ( v17 + 1 < *(_DWORD *)(a2 + 8) );
  }
  return 0;
}
