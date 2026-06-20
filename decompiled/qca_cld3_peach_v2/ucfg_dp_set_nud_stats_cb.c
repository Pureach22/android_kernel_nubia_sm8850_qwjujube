__int64 __fastcall ucfg_dp_set_nud_stats_cb(
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
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x21
  __int64 result; // x0
  const char *v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( !a1 )
  {
    v16 = "%s: psoc is null";
LABEL_8:
    qdf_trace_msg(0x45u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "dp_intf_get_tx_ops");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get ops",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "ucfg_dp_set_nud_stats_cb");
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    v16 = "%s: psoc private object is null";
    goto LABEL_8;
  }
  v13 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 768);
  v14 = comp_private_obj;
  if ( *((_DWORD *)v13 - 1) != -770124015 )
    __break(0x8228u);
  result = v13(a1);
  *(_QWORD *)(v14 + 800) = a2;
  return result;
}
