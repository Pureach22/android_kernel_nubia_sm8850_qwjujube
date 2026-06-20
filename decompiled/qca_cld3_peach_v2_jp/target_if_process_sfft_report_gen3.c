__int64 __fastcall target_if_process_sfft_report_gen3(
        __int64 result,
        _DWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w9
  int v12; // w10
  unsigned int v13; // w9
  char v14; // w10
  int v15; // w11
  unsigned int v16; // w10
  int v17; // w10
  int v18; // w11
  unsigned int v19; // w9
  int v20; // w10
  __int64 v21; // x20

  if ( !result || !a2 || !a3 )
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: null params: p_fft_report %pK p_sfft %pK rparams %pK",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "target_if_process_sfft_report_gen3",
             result,
             a2,
             a3);
  *a2 = *(_DWORD *)result;
  a2[3] = *(_DWORD *)(result + 8) & 3;
  a2[4] = (*(_DWORD *)(result + 8) >> 2) & 7;
  if ( *a3 == 1 )
  {
    a2[5] = (*(_DWORD *)(result + 8) >> 5) & 0x3FFF;
    v16 = *(_DWORD *)(result + 8);
    a2[7] = *(_DWORD *)(result + 12) & 7;
    v13 = v16 >> 19;
    v14 = 12;
    v15 = *(_DWORD *)(result + 12) >> 3;
    goto LABEL_9;
  }
  if ( !*a3 )
  {
    a2[5] = (*(_DWORD *)(result + 8) >> 5) & 0xFFF;
    v11 = *(_DWORD *)(result + 8);
    v12 = (v11 >> 28) & 7;
    v13 = v11 >> 17;
    a2[7] = v12;
    v14 = 9;
    v15 = *(_DWORD *)(result + 12);
LABEL_9:
    a2[8] = v15 & 0x1FF;
    v17 = *(_DWORD *)(result + 12) >> v14;
    if ( (v13 & 0x400) != 0 )
      v18 = -2048;
    else
      v18 = 0;
    a2[9] = (unsigned __int8)v17;
    a2[6] = v18 & 0xFFFFF800 | v13 & 0x7FF;
    a2[10] = *(unsigned __int8 *)(result + 16);
    v19 = *(_DWORD *)(result + 16);
    if ( ((v19 >> 8) & 0x200) != 0 )
      v20 = -1024;
    else
      v20 = 0;
    a2[11] = v20 & 0xFFFFFC00 | (v19 >> 8) & 0x3FF;
    a2[12] = (*(_DWORD *)(result + 16) >> 18) & 0x7F;
    a2[13] = *(_DWORD *)(result + 16) >> 25;
    return result;
  }
  v21 = jiffies;
  if ( target_if_process_sfft_report_gen3___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x56u,
               2u,
               "%s: Invalid spectral report format: %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "target_if_process_sfft_report_gen3");
    target_if_process_sfft_report_gen3___last_ticks = v21;
  }
  return result;
}
