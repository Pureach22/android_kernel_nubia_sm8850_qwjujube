__int64 __fastcall extract_pdev_spectral_session_chan_info_tlv(
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
  unsigned int *v11; // x19
  unsigned int v13; // w20
  __int64 v14; // x10
  __int64 v15; // x10
  unsigned int v16; // w9
  const char *v17; // x2

  if ( !a10 )
  {
    v17 = "%s: param_buf is NULL";
LABEL_11:
    qdf_trace_msg(0x31u, 2u, v17, a1, a2, a3, a4, a5, a6, a7, a8, "extract_pdev_spectral_session_chan_info_tlv");
    return 29;
  }
  if ( !a11 )
  {
    v17 = "%s: chan_info is NULL";
    goto LABEL_11;
  }
  v11 = *(unsigned int **)(a10 + 32);
  if ( !v11 )
  {
    v17 = "%s: chan_info tlv is not present in the event";
    goto LABEL_11;
  }
  v13 = 8;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: operating_pri20_freq:%u operating_cfreq1:%uoperating_cfreq2:%u operating_bw:%uoperating_puncture_20mhz_bitmap:%u"
    "sscan_cfreq1:%u sscan_cfreq2:%usscan_bw:%u sscan_puncture_20mhz_bitmap:%u",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_pdev_spectral_session_chan_info_tlv",
    v11[1],
    v11[2],
    v11[3],
    v11[4],
    v11[5],
    v11[6],
    v11[7],
    v11[8],
    v11[9]);
  *(_DWORD *)a11 = v11[1];
  *(_DWORD *)(a11 + 4) = v11[2];
  *(_DWORD *)(a11 + 8) = v11[3];
  v14 = v11[4];
  if ( (unsigned int)v14 <= 9 )
    v13 = dword_AD8FB0[v14];
  *(_DWORD *)(a11 + 12) = v13;
  *(_WORD *)(a11 + 16) = v11[5];
  *(_DWORD *)(a11 + 20) = v11[6];
  *(_DWORD *)(a11 + 24) = v11[7];
  v15 = v11[8];
  if ( (unsigned int)v15 > 9 )
    v16 = 8;
  else
    v16 = dword_AD8FB0[v15];
  *(_DWORD *)(a11 + 28) = v16;
  *(_WORD *)(a11 + 32) = v11[9];
  return 0;
}
