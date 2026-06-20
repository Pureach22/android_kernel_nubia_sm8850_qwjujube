__int64 __fastcall pmo_tgt_config_icmp_offload_req(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v12)(__int64, unsigned __int8 *); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: vdev_id: %d: ICMP offload %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "pmo_tgt_config_icmp_offload_req",
    *a2,
    a2[1]);
  v12 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *))(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 464);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != 123897044 )
      __break(0x8228u);
    return v12(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_icmp_offload_req is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pmo_tgt_config_icmp_offload_req");
    return 29;
  }
}
