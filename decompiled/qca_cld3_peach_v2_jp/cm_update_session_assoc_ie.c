__int64 __fastcall cm_update_session_assoc_ie(__int64 a1, __int64 a2, const void **a3)
{
  unsigned __int8 v4; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 v27; // x0
  size_t v28; // x0
  __int64 v29; // x0
  size_t v30; // x2
  void *v31; // x0

  v4 = a2;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v6 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL for vdev %d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "cm_update_session_assoc_ie",
             v4);
  v15 = v6;
  rso_config_fl = wlan_cm_get_rso_config_fl(v6, "cm_update_session_assoc_ie", 6470);
  if ( rso_config_fl )
  {
    v26 = rso_config_fl;
    v27 = *(_QWORD *)(rso_config_fl + 248);
    if ( v27 )
    {
      _qdf_mem_free(v27);
      *(_QWORD *)(v26 + 248) = 0;
      *(_DWORD *)(v26 + 240) = 0;
    }
    v28 = *(unsigned int *)a3;
    if ( (_DWORD)v28 )
    {
      v29 = _qdf_mem_malloc(v28, "cm_update_session_assoc_ie", 6483);
      *(_QWORD *)(v26 + 248) = v29;
      if ( v29 )
      {
        cm_update_ext_cap_ie_at_source(a1, a3);
        v30 = *(unsigned int *)a3;
        v31 = *(void **)(v26 + 248);
        *(_DWORD *)(v26 + 240) = v30;
        qdf_mem_copy(v31, a3[1], v30);
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Assoc IE len 0",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "cm_update_session_assoc_ie");
    }
  }
  return wlan_objmgr_vdev_release_ref(v15, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24, v25);
}
