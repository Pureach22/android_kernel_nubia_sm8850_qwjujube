__int64 __fastcall ucfg_dp_req_get_arp_stats(
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
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  const char *v15; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !a1 )
  {
    v15 = "%s: psoc is null";
LABEL_8:
    qdf_trace_msg(0x45u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "dp_intf_get_tx_ops");
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get ops",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_dp_req_get_arp_stats");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    v15 = "%s: psoc private object is null";
    goto LABEL_8;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 784);
  if ( *((_DWORD *)v13 - 1) != 281511136 )
    __break(0x8228u);
  return v13(a1, a2);
}
