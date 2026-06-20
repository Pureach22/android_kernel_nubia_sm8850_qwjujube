__int64 __fastcall dlm_update_reject_ap_list_to_fw(__int64 a1)
{
  char *psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char *v11; // x21
  __int64 pdev_by_id; // x0
  __int64 v13; // x19
  __int64 pdev_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  const char *v24; // x2
  const char *v25; // x2
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  psoc_obj = (char *)dlm_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v25 = "%s: DLM psoc obj NULL";
    return qdf_trace_msg(0x6Du, 2u, v25, v3, v4, v5, v6, v7, v8, v9, v10, "dlm_update_reject_ap_list_to_fw");
  }
  v11 = psoc_obj;
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, *psoc_obj, 0x4Du);
  if ( !pdev_by_id )
  {
    v25 = "%s: pdev obj NULL";
    return qdf_trace_msg(0x6Du, 2u, v25, v3, v4, v5, v6, v7, v8, v9, v10, "dlm_update_reject_ap_list_to_fw");
  }
  v13 = pdev_by_id;
  pdev_obj = dlm_get_pdev_obj();
  if ( pdev_obj )
  {
    v23 = pdev_obj;
    if ( !(unsigned int)qdf_mutex_acquire(pdev_obj) )
    {
      dlm_send_reject_ap_list_to_fw(v13, v23 + 64, v11 + 8);
      qdf_mutex_release(v23);
      return wlan_objmgr_pdev_release_ref(v13, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    }
    v24 = "%s: failed to acquire reject_ap_list_lock";
  }
  else
  {
    v24 = "%s: DLM pdev obj NULL";
  }
  qdf_trace_msg(0x6Du, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "dlm_update_reject_ap_list_to_fw");
  return wlan_objmgr_pdev_release_ref(v13, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
}
