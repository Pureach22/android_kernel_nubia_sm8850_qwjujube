__int64 __fastcall ucfg_nan_datapath_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a5, a6, a7, a8, a9, a10, a11, a12, "nan_get_psoc_priv_obj");
    return qdf_trace_msg(
             0x53u,
             2u,
             "%s: nan psoc priv object is NULL",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "ucfg_nan_datapath_event_handler");
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x53u,
             2u,
             "%s: nan psoc priv object is NULL",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "ucfg_nan_datapath_event_handler");
  v25 = *(_DWORD **)(comp_private_obj + 24);
  if ( *(v25 - 1) != 497807660 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v25)(a1, a2, a3, a4);
}
