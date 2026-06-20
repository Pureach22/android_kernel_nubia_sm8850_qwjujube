bool __fastcall hdd_sap_is_acs_in_progress(
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
  _QWORD *link_info_from_objmgr; // x0
  _QWORD *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v20; // x2

  if ( !a1 )
  {
    v20 = "%s: vdev is NULL";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sap_is_acs_in_progress");
    return 0;
  }
  link_info_from_objmgr = (_QWORD *)wlan_hdd_get_link_info_from_objmgr();
  if ( !link_info_from_objmgr )
  {
    v20 = "%s: null adapter";
    goto LABEL_7;
  }
  v10 = link_info_from_objmgr;
  if ( (hdd_adapter_is_ap(*link_info_from_objmgr) & 1) != 0 )
    return *((_DWORD *)v10 + 654) != 0;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: vdev id %d is not AP",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "hdd_sap_is_acs_in_progress",
    *((unsigned __int8 *)v10 + 8));
  return 0;
}
