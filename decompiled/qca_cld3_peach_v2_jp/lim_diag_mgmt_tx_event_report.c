__int64 __fastcall lim_diag_mgmt_tx_event_report(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int16 a4,
        __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v18; // w8
  unsigned int v19; // w26
  __int64 v20; // x0
  unsigned int v21; // w1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int8 v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w9
  int v40; // w10
  int v41; // w11
  __int64 v42; // x6
  int v43; // w8
  __int64 result; // x0
  _QWORD v45[4]; // [xsp+50h] [xbp-40h] BYREF
  __int64 v46; // [xsp+70h] [xbp-20h] BYREF
  __int64 v47; // [xsp+78h] [xbp-18h] BYREF
  int v48; // [xsp+80h] [xbp-10h]
  __int64 v49; // [xsp+88h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v46 = 0;
  v47 = 0;
  memset(v45, 0, sizeof(v45));
  if ( a2 && a3 )
  {
    qdf_mem_set(v45, 0x34u, 0);
    v18 = *a2;
    LOBYTE(v45[0]) = (*a2 >> 2) & 3;
    BYTE1(v45[0]) = v18 >> 4;
    qdf_mem_copy((char *)&v46 + 4, (const void *)(a3 + 30), 6u);
    qdf_mem_copy((char *)&v47 + 2, a2 + 16, 6u);
    if ( *(unsigned __int8 *)(a3 + 36) >= 0x20u )
      v19 = 32;
    else
      v19 = *(unsigned __int8 *)(a3 + 36);
    qdf_mem_copy((char *)v45 + 4, (const void *)(a3 + 37), v19);
    v20 = *(_QWORD *)(a1 + 21560);
    v21 = *(_DWORD *)(a3 + 284);
    BYTE3(v45[0]) = v19;
    v30 = wlan_reg_freq_to_chan(v20, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    v39 = BYTE4(v46);
    v40 = BYTE5(v46);
    v41 = BYTE1(v47);
    v42 = *((unsigned __int16 *)a2 + 11) >> 4;
    if ( &v46 == (__int64 *)-4LL )
    {
      v39 = 0;
      v40 = 0;
      v43 = 0;
    }
    else
    {
      v43 = BYTE6(v46);
    }
    if ( &v46 == (__int64 *)-4LL )
      v41 = 0;
    BYTE2(v45[0]) = v30;
    LOWORD(v48) = a4;
    HIWORD(v48) = a5;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TX frame: type:%d sub_type:%d seq_num:%d ssid:%.*s selfmacaddr:%02x:%02x:%02x:**:**:%02x bssid:%02x:%02x:%02x:"
      "**:**:%02x channel:%d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_diag_mgmt_tx_event_report",
      LOBYTE(v45[0]),
      BYTE1(v45[0]),
      v42,
      BYTE3(v45[0]),
      (char *)v45 + 4,
      v39,
      v40,
      v43,
      v41,
      BYTE2(v47),
      BYTE3(v47),
      BYTE4(v47),
      HIBYTE(v47),
      v30);
    result = host_diag_event_report_payload(3154, 52, v45);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: not valid input",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "lim_diag_mgmt_tx_event_report");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
