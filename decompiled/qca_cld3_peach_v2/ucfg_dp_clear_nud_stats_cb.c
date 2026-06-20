__int64 __fastcall ucfg_dp_clear_nud_stats_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v11)(_QWORD); // x8
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !a1 )
  {
    v13 = "%s: psoc is null";
LABEL_8:
    qdf_trace_msg(0x45u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "dp_intf_get_tx_ops");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get ops",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "ucfg_dp_clear_nud_stats_cb");
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    v13 = "%s: psoc private object is null";
    goto LABEL_8;
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 776);
  if ( *((_DWORD *)v11 - 1) != -770124015 )
    __break(0x8228u);
  return v11(a1);
}
