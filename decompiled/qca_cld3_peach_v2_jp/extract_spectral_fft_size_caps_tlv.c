__int64 __fastcall extract_spectral_fft_size_caps_tlv(
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
  unsigned int v14; // w24
  unsigned int v15; // w9
  __int64 v16; // x10
  __int64 v17; // x27
  __int64 (__fastcall *v18)(__int64, __int64); // x9
  __int64 v19; // x1
  char v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x9
  const char *v32; // x2

  if ( !a2 )
  {
    v32 = "%s: param_buf is NULL";
LABEL_14:
    qdf_trace_msg(0x31u, 2u, v32, a4, a5, a6, a7, a8, a9, a10, a11, "extract_spectral_fft_size_caps_tlv");
    return 29;
  }
  if ( !a3 )
  {
    v32 = "%s: fft size caps is NULL";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a2 + 24) )
  {
    v14 = 0;
    do
    {
      v17 = 16LL * (int)v14;
      v18 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3672LL);
      v19 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + v17 + 4);
      if ( *((_DWORD *)v18 - 1) != -2112860426 )
        __break(0x8229u);
      v20 = v18(a1, v19);
      v29 = a3 + 12LL * (int)v14;
      *(_BYTE *)v29 = v20;
      v30 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + v17 + 8);
      if ( (unsigned int)v30 <= 9 )
        v15 = dword_9E7138[v30];
      else
        v15 = 8;
      *(_DWORD *)(v29 + 4) = v15;
      v16 = 16LL * (int)v14;
      *(_DWORD *)(v29 + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 16) + v16 + 12);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: fft_size_caps[%u]:: pdev_id:%u sscan_bw:%usupported_flags:0x%x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "extract_spectral_fft_size_caps_tlv",
        v14++,
        *(unsigned int *)(*(_QWORD *)(a2 + 16) + v16 + 4),
        *(unsigned int *)(*(_QWORD *)(a2 + 16) + v16 + 8),
        *(unsigned int *)(*(_QWORD *)(a2 + 16) + v16 + 12));
    }
    while ( v14 < *(_DWORD *)(a2 + 24) );
  }
  return 0;
}
