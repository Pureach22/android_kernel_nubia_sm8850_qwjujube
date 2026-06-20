__int64 __fastcall wma_get_ll_stats_ext_buf(
        unsigned int *a1,
        unsigned int a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x5
  __int64 v12; // x6
  unsigned int v13; // w9
  int v14; // w9
  unsigned int v15; // w10
  int v16; // w8
  unsigned int v17; // w10
  int v18; // w8
  unsigned int v19; // w10
  int v20; // w8
  unsigned int v21; // w9
  unsigned int v22; // w8
  __int64 result; // x0
  int v24; // w9
  unsigned int v25; // w8
  int v26; // w9
  bool v27; // cf
  int v28; // w8
  unsigned int v29; // w19
  unsigned int v31; // w8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid input parameters",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_get_ll_stats_ext_buf");
    return 0;
  }
  v11 = a3[6];
  if ( (unsigned int)v11 >= 0x2B )
  {
    v12 = a3[9];
LABEL_12:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: excess wmi buffer: peer %d cca %d tx_mpdu %d tx_succ%d tx_fail %d tx_ppdu %d rx_mpdu %d rx_mcs %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_get_ll_stats_ext_buf",
      a2,
      v11,
      v12,
      a3[10],
      a3[11],
      a3[13],
      a3[15],
      a3[16]);
    return 0;
  }
  v12 = a3[9];
  if ( (unsigned int)v12 > 0x600 )
    goto LABEL_12;
  v13 = a3[10];
  if ( v13 > 1536 - (int)v12 )
    goto LABEL_12;
  v14 = v13 + v12;
  v15 = a3[11];
  if ( v15 > 1536 - v14 )
    goto LABEL_12;
  v16 = v15 + v14;
  v17 = a3[13];
  if ( v17 > 1536 - v16 )
    goto LABEL_12;
  v18 = v17 + v16;
  v19 = a3[15];
  if ( v19 > 1536 - v18 )
    goto LABEL_12;
  v20 = v19 + v18;
  v21 = a3[16];
  if ( v21 > 1536 - v20 )
    goto LABEL_12;
  v22 = v21 + v20;
  if ( v22 > 0x38 )
    goto LABEL_12;
  v24 = 16 * v22;
  v25 = v22 < 0x28;
  v26 = v24 + 912;
  v27 = v25 >= a2;
  v28 = v25 >= a2 ? v26 : 0;
  if ( !v27 )
    goto LABEL_12;
  v29 = 36 * v11 + 92 + v28;
  if ( v29 >= 0x601 )
    goto LABEL_12;
  result = _qdf_mem_malloc((unsigned int)(36 * v11 + 92 + v28), "wma_get_ll_stats_ext_buf", 1332);
  if ( result )
    v31 = v29;
  else
    v31 = 0;
  *a1 = v31;
  return result;
}
