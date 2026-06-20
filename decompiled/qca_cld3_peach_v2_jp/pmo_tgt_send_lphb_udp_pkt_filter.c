__int64 __fastcall pmo_tgt_send_lphb_udp_pkt_filter(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  const char *v22; // x2

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_send_lphb_udp_pkt_filter");
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 312);
  if ( !v12 )
  {
    v21 = 29;
    v22 = "%s: send_lphb_udp_filter_req is null";
    goto LABEL_7;
  }
  if ( *((_DWORD *)v12 - 1) != -2027754356 )
    __break(0x8228u);
  v21 = v12(a1, a2);
  if ( v21 )
  {
    v22 = "%s: Failed to send lphb udp filter req";
LABEL_7:
    qdf_trace_msg(0x4Du, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "pmo_tgt_send_lphb_udp_pkt_filter");
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v13, v14, v15, v16, v17, v18, v19, v20, "pmo_tgt_send_lphb_udp_pkt_filter");
  return v21;
}
