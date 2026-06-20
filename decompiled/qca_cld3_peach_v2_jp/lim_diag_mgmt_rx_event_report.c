__int64 __fastcall lim_diag_mgmt_rx_event_report(
        __int64 result,
        unsigned __int8 *a2,
        __int64 a3,
        __int16 a4,
        __int16 a5)
{
  __int64 v7; // x24
  unsigned int v10; // w8
  unsigned int v11; // w26
  __int64 v12; // x0
  unsigned int v13; // w1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w9
  int v32; // w10
  int v33; // w11
  __int64 v34; // x6
  int v35; // w8
  _QWORD v36[4]; // [xsp+50h] [xbp-40h] BYREF
  __int64 v37; // [xsp+70h] [xbp-20h] BYREF
  __int64 v38; // [xsp+78h] [xbp-18h] BYREF
  int v39; // [xsp+80h] [xbp-10h]
  __int64 v40; // [xsp+88h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a3 )
  {
    v7 = result;
    v39 = 0;
    v37 = 0;
    v38 = 0;
    memset(v36, 0, sizeof(v36));
    qdf_mem_set(v36, 0x34u, 0);
    v10 = *a2;
    LOBYTE(v36[0]) = (*a2 >> 2) & 3;
    BYTE1(v36[0]) = v10 >> 4;
    qdf_mem_copy((char *)&v37 + 4, (const void *)(a3 + 30), 6u);
    qdf_mem_copy((char *)&v38 + 2, a2 + 16, 6u);
    if ( *(unsigned __int8 *)(a3 + 36) >= 0x20u )
      v11 = 32;
    else
      v11 = *(unsigned __int8 *)(a3 + 36);
    qdf_mem_copy((char *)v36 + 4, (const void *)(a3 + 37), v11);
    v12 = *(_QWORD *)(v7 + 21560);
    v13 = *(_DWORD *)(a3 + 284);
    BYTE3(v36[0]) = v11;
    v22 = wlan_reg_freq_to_chan(v12, v13, v14, v15, v16, v17, v18, v19, v20, v21);
    v31 = BYTE4(v37);
    v32 = BYTE5(v37);
    v33 = BYTE1(v38);
    v34 = *((unsigned __int16 *)a2 + 11) >> 4;
    if ( &v37 == (__int64 *)-4LL )
    {
      v31 = 0;
      v32 = 0;
      v35 = 0;
    }
    else
    {
      v35 = BYTE6(v37);
    }
    if ( &v37 == (__int64 *)-4LL )
      v33 = 0;
    BYTE2(v36[0]) = v22;
    LOWORD(v39) = a4;
    HIWORD(v39) = a5;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RX frame: type:%d sub_type:%d seq_num:%d ssid:%.*s selfmacaddr:%02x:%02x:%02x:**:**:%02x bssid:%02x:%02x:%02x:"
      "**:**:%02x channel:%d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_diag_mgmt_rx_event_report",
      LOBYTE(v36[0]),
      BYTE1(v36[0]),
      v34,
      BYTE3(v36[0]),
      (char *)v36 + 4,
      v31,
      v32,
      v35,
      v33,
      BYTE2(v38),
      BYTE3(v38),
      BYTE4(v38),
      HIBYTE(v38),
      v22);
    result = host_diag_event_report_payload(3155, 52, v36);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
