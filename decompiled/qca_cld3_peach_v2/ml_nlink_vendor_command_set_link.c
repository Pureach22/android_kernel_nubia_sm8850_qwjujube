__int64 __fastcall ml_nlink_vendor_command_set_link(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        unsigned __int16 a7,
        unsigned __int16 a8)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 pdev_by_id; // x0
  __int64 v25; // x27
  char is_vdev_in_cac_wait; // w28
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  const char *v45; // x2
  __int64 result; // x0
  __int64 v47; // [xsp+0h] [xbp-20h] BYREF
  __int64 v48; // [xsp+8h] [xbp-18h]
  unsigned __int64 v49; // [xsp+10h] [xbp-10h]
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v49 = 0;
  v47 = 0;
  if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) != 0 && (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
  {
    v45 = "%s: eMLSR concurrency not allow to set link";
    goto LABEL_8;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0x18u);
  if ( !pdev_by_id )
  {
    v45 = "%s: null pdev";
LABEL_8:
    qdf_trace_msg(
      0x8Fu,
      8u,
      v45,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ml_nlink_vendor_command_set_link",
      v47,
      v48,
      v49,
      v50);
    result = 4;
    goto LABEL_13;
  }
  v25 = pdev_by_id;
  is_vdev_in_cac_wait = wlan_util_is_vdev_in_cac_wait(pdev_by_id, 0x18u);
  wlan_objmgr_pdev_release_ref(v25, 0x18u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( (is_vdev_in_cac_wait & 1) != 0 )
  {
    v44 = "%s: reject due to cac in progress";
  }
  else
  {
    if ( (policy_mgr_is_chan_switch_in_progress(a1) & 1) == 0 )
    {
      qdf_mem_set(&v47, 0x18u, 0);
      LODWORD(v47) = a3;
      v49 = __PAIR64__(a4, a5);
      BYTE4(v47) = a6;
      LODWORD(v48) = a7;
      HIDWORD(v48) = a8;
      result = ml_nlink_conn_change_notify(a1, a2, 0x12u, (__int64)&v47);
      goto LABEL_13;
    }
    v44 = "%s: reject due to ch switch in progress";
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    v44,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "ml_nlink_vendor_command_set_link",
    v47,
    v48,
    v49,
    v50);
  result = 8;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
