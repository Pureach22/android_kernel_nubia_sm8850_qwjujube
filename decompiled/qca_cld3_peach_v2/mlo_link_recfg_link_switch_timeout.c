__int64 __fastcall mlo_link_recfg_link_switch_timeout(
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
  __int64 v10; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v10 = *(_QWORD *)(a2 + 3880);
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Link switch active cmd timeout",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_link_recfg_link_switch_timeout");
  v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          *(unsigned __int8 *)(v10 + 144),
          90);
  if ( !v12 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: Invalid link switch VDEV %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "mlo_link_recfg_link_switch_timeout",
             *(unsigned __int8 *)(v10 + 144));
  v21 = v12;
  wlan_cm_trigger_panic_on_cmd_timeout(v12);
  return wlan_objmgr_vdev_release_ref(v21, 0x5Au, v22, v23, v24, v25, v26, v27, v28, v29, v30);
}
