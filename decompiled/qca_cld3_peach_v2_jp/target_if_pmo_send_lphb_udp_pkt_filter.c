__int64 __fastcall target_if_pmo_send_lphb_udp_pkt_filter(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const void *v10; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 result; // x0
  int v23; // [xsp+0h] [xbp-70h]
  int v24; // [xsp+8h] [xbp-68h]
  int v25; // [xsp+10h] [xbp-60h]
  int v26; // [xsp+18h] [xbp-58h]
  int v27; // [xsp+20h] [xbp-50h]
  __int64 v28; // [xsp+28h] [xbp-48h]
  __int64 v29; // [xsp+40h] [xbp-30h] BYREF
  __int64 v30; // [xsp+48h] [xbp-28h]
  __int64 v31; // [xsp+50h] [xbp-20h]
  __int64 v32; // [xsp+58h] [xbp-18h]
  __int64 v33; // [xsp+60h] [xbp-10h]
  __int64 v34; // [xsp+68h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v33) = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( a2 )
  {
    v10 = a2 + 2;
    v27 = *((unsigned __int8 *)a2 + 9);
    v26 = *((unsigned __int8 *)a2 + 8);
    v25 = *((unsigned __int8 *)a2 + 7);
    v24 = *((unsigned __int8 *)a2 + 6);
    v23 = *((unsigned __int8 *)a2 + 5);
    qdf_trace_msg(
      0x49u,
      4u,
      "%s: SET_UDP_PKT_FILTER length=%d, offset=%d, session=%d, filter=%2x:%2x:%2x:%2x:%2x:%2x ...",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_udp_pkt_filter",
      *a2,
      *((unsigned __int8 *)a2 + 2),
      *((unsigned __int8 *)a2 + 3),
      *((unsigned __int8 *)a2 + 4),
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      0,
      0,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
    qdf_mem_copy((char *)&v29 + 4, v10, 0x20u);
    if ( a1 && (v20 = *(_QWORD *)(a1 + 2800)) != 0 && (v21 = *(_QWORD *)(v20 + 16)) != 0 )
    {
      result = wmi_unified_lphb_config_udp_pkt_filter_cmd(v21);
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Invalid wmi handle",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pmo_send_lphb_udp_pkt_filter");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: LPHB UDP packet filter configuration is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_udp_pkt_filter");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
