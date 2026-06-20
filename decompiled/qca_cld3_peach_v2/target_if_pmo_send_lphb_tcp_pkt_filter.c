__int64 __fastcall target_if_pmo_send_lphb_tcp_pkt_filter(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  int v22; // [xsp+0h] [xbp-70h]
  int v23; // [xsp+8h] [xbp-68h]
  int v24; // [xsp+10h] [xbp-60h]
  int v25; // [xsp+18h] [xbp-58h]
  int v26; // [xsp+20h] [xbp-50h]

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    v25 = *((unsigned __int8 *)a2 + 8);
    v26 = *((unsigned __int8 *)a2 + 9);
    v24 = *((unsigned __int8 *)a2 + 7);
    v23 = *((unsigned __int8 *)a2 + 6);
    v22 = *((unsigned __int8 *)a2 + 5);
    qdf_trace_msg(
      0x49u,
      4u,
      "%s: SET_TCP_PKT_FILTER length=%d, offset=%d, session=%d, filter=%2x:%2x:%2x:%2x:%2x:%2x ...",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_tcp_pkt_filter",
      *a2,
      *((unsigned __int8 *)a2 + 2),
      *((unsigned __int8 *)a2 + 3),
      *((unsigned __int8 *)a2 + 4),
      v22,
      v23,
      v24,
      v25,
      v26);
    if ( a1 && (v19 = *(_QWORD *)(a1 + 2800)) != 0 && (v20 = *(_QWORD *)(v19 + 16)) != 0 )
    {
      result = wmi_unified_lphb_config_tcp_pkt_filter_cmd(v20);
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Invalid wmi handle",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "target_if_pmo_send_lphb_tcp_pkt_filter");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: TCP PKT FILTER LPHB configuration is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_tcp_pkt_filter");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
