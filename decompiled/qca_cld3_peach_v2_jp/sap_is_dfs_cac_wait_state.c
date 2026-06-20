_QWORD *__fastcall sap_is_dfs_cac_wait_state(
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
  _QWORD *result; // x0
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  int is_dfs_cac_wait; // w20
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  if ( a1 )
  {
    result = _cds_get_context(52, (__int64)"sap_is_dfs_cac_wait_state", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( !result )
      return result;
    v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            result[2694],
            *(unsigned __int8 *)(a1 + 12),
            14);
    if ( v11 )
    {
      v20 = v11;
      is_dfs_cac_wait = wlan_vdev_is_dfs_cac_wait(v11);
      wlan_objmgr_vdev_release_ref(v20, 0xEu, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      return (_QWORD *)(is_dfs_cac_wait == 0);
    }
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: vdev is NULL for vdev_id: %u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sap_is_dfs_cac_wait_state",
      *(unsigned __int8 *)(a1 + 12));
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid sap context", a2, a3, a4, a5, a6, a7, a8, a9, "sap_is_dfs_cac_wait_state");
  }
  return nullptr;
}
