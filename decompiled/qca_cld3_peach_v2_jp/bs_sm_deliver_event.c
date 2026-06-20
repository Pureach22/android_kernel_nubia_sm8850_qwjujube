__int64 __fastcall bs_sm_deliver_event(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  unsigned int ll_lt_sap_vdev_id; // w0
  __int64 v9; // x0
  __int64 v10; // x19
  __int64 *comp_private_obj; // x0
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w20

  ll_lt_sap_vdev_id = wlan_policy_mgr_get_ll_lt_sap_vdev_id(a1);
  if ( (unsigned __int8)ll_lt_sap_vdev_id > 5u )
    return 4;
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         a1,
         ll_lt_sap_vdev_id,
         105);
  if ( !v9 )
    return 4;
  v10 = v9;
  comp_private_obj = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(v9, 0x34u);
  if ( comp_private_obj )
  {
    v21 = *comp_private_obj;
    if ( *comp_private_obj )
    {
      qdf_mutex_acquire(v21 + 16);
      v30 = wlan_sm_dispatch(*(_QWORD *)(v21 + 80), a2, a3, a4, v22, v23, v24, v25, v26, v27, v28, v29);
      qdf_mutex_release(v21 + 16);
    }
    else
    {
      v30 = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM vdev %d ll_sap obj null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "bs_sm_deliver_event",
      *(unsigned __int8 *)(v10 + 104));
    v30 = 4;
  }
  wlan_objmgr_vdev_release_ref(v10, 0x69u, v12, v13, v14, v15, v16, v17, v18, v19, v20);
  return v30;
}
