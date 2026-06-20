__int64 __fastcall hdd_handle_beacon_reporting_start_op(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v15; // x21
  char v16; // w22
  unsigned int v17; // w0
  unsigned int v18; // w19
  const char *v19; // x2
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  if ( (a3 & 1) != 0 )
  {
    v15 = a2;
    v16 = a5;
    v17 = sme_register_bcn_report_pe_cb(
            *(_QWORD *)(a1 + 16),
            (__int64)hdd_send_bcn_recv_info,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13);
    if ( v17 )
    {
      v18 = v17;
      v19 = "%s: bcn recv info cb reg failed = %d";
LABEL_6:
      qdf_trace_msg(0x33u, 2u, v19, a6, a7, a8, a9, a10, a11, a12, a13, "hdd_handle_beacon_reporting_start_op", v18);
      return qdf_status_to_os_return(v18);
    }
    v20 = sme_register_bcn_recv_pause_ind_cb(
            *(_QWORD *)(a1 + 16),
            (__int64)hdd_beacon_recv_pause_indication,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13);
    if ( v20 )
    {
      v18 = v20;
      v19 = "%s: pause_ind_cb reg failed = %d";
      goto LABEL_6;
    }
    a4 = -2147483647;
    a5 = v16;
    a2 = v15;
  }
  v18 = sme_handle_bcn_recv_start(
          *(_QWORD *)(a1 + 16),
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL),
          a4,
          a5 & 1,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13);
  if ( v18 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: bcn rcv start failed with status=%d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_handle_beacon_reporting_start_op",
      v18);
    if ( (unsigned int)sme_register_bcn_report_pe_cb(*(_QWORD *)(a1 + 16), 0, v29, v30, v31, v32, v33, v34, v35, v36) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: bcn report cb deregistration failed",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "hdd_handle_beacon_reporting_start_op");
    if ( (unsigned int)sme_register_bcn_recv_pause_ind_cb(
                         *(_QWORD *)(a1 + 16),
                         0,
                         v37,
                         v38,
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: bcn pause ind cb deregistration failed",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "hdd_handle_beacon_reporting_start_op");
  }
  return qdf_status_to_os_return(v18);
}
