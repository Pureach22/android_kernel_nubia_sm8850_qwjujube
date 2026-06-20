__int64 __fastcall target_if_pmo_send_lphb_tcp_params(
        __int64 a1,
        unsigned int *a2,
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
  int v22; // [xsp+0h] [xbp-80h]
  int v23; // [xsp+8h] [xbp-78h]
  int v24; // [xsp+10h] [xbp-70h]
  int v25; // [xsp+18h] [xbp-68h]
  int v26; // [xsp+20h] [xbp-60h]
  int v27; // [xsp+28h] [xbp-58h]
  int v28; // [xsp+30h] [xbp-50h]
  unsigned int v29; // [xsp+38h] [xbp-48h]

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    v29 = a2[6];
    v28 = *((unsigned __int16 *)a2 + 11);
    v27 = *((unsigned __int8 *)a2 + 20);
    v26 = *((unsigned __int8 *)a2 + 17);
    v25 = *((unsigned __int8 *)a2 + 16);
    v24 = *((unsigned __int8 *)a2 + 15);
    v23 = *((unsigned __int8 *)a2 + 14);
    v22 = *((unsigned __int16 *)a2 + 6);
    qdf_trace_msg(
      0x49u,
      4u,
      "%s: PMO --> WMI_HB_SET_TCP_PARAMS srv_ip=%08x, dev_ip=%08x, src_port=%d, dst_port=%d, timeout=%d, session=%d, gate"
      "way_mac= %02x:%02x:%02x:**:**:%02x, time_period_sec=%d,tcp_sn=%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_tcp_params",
      *a2,
      a2[1],
      *((unsigned __int16 *)a2 + 4),
      *((unsigned __int16 *)a2 + 5),
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29);
    if ( a1 && (v19 = *(_QWORD *)(a1 + 2800)) != 0 && (v20 = *(_QWORD *)(v19 + 16)) != 0 )
    {
      result = wmi_unified_lphb_config_tcp_params_cmd(v20);
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
        "target_if_pmo_send_lphb_tcp_params");
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: TCP params LPHB configuration is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_pmo_send_lphb_tcp_params");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
