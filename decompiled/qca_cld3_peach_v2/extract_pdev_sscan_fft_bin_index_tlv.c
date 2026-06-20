__int64 __fastcall extract_pdev_sscan_fft_bin_index_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x8
  int v12; // w9
  unsigned __int16 v13; // w10
  int v14; // w11
  unsigned __int16 v15; // w12
  unsigned __int16 v16; // w13
  __int16 v17; // w8
  unsigned __int16 v18; // w8

  if ( !a10 )
    return 4;
  v11 = *(_QWORD *)(a10 + 16);
  if ( !v11 )
    return 4;
  v12 = *(_DWORD *)(v11 + 4);
  *(_WORD *)(a11 + 2) = v12;
  v13 = *(_WORD *)(v11 + 6) - v12 + 1;
  *(_WORD *)(a11 + 4) = v13;
  v14 = *(_DWORD *)(v11 + 8);
  *(_WORD *)(a11 + 10) = v14;
  v15 = *(_WORD *)(v11 + 10) - v14 + 1;
  *(_WORD *)(a11 + 12) = v15;
  v16 = *(_DWORD *)(v11 + 12);
  *(_WORD *)(a11 + 6) = v16;
  v17 = *(_WORD *)(v11 + 14);
  *(_BYTE *)a11 = 1;
  v18 = v17 - v16 + 1;
  *(_WORD *)(a11 + 8) = v18;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: start_pri80: %u num_pri80: %u start_sec80: %u num_sec80: %u start_5mhz: %u, num_5mhz: %u",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_pdev_sscan_fft_bin_index_tlv",
    (unsigned __int16)v12,
    v13,
    (unsigned __int16)v14,
    v15,
    v16,
    v18);
  return 0;
}
