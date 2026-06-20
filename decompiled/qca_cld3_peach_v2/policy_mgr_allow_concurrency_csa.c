__int64 __fastcall policy_mgr_allow_concurrency_csa(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        int a7)
{
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x25
  __int64 assoc_link_vdev; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x4
  double v61; // d0
  char v62; // w0
  char v63; // w20
  unsigned int *v64; // x8
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int8 v80; // w2
  __int64 result; // x0
  int v82; // [xsp+8h] [xbp-C8h] BYREF
  unsigned __int8 v83[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v84[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v85; // [xsp+C0h] [xbp-10h]
  __int64 v86; // [xsp+C8h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v85 = 0;
  memset(v84, 0, sizeof(v84));
  v83[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v32 = "%s: Invalid Context";
LABEL_24:
    qdf_trace_msg(0x4Fu, 2u, v32, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_allow_concurrency_csa");
    goto LABEL_25;
  }
  v23 = context;
  v82 = 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: check concurrency_csa vdev:%d ch %d bw %d, forced %d, reason %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_allow_concurrency_csa",
    a5,
    a3,
    a4,
    a6 & 1,
    a7);
  if ( (unsigned int)policy_mgr_get_chan_by_session_id(a1, a5, &v82) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to get channel for vdev:%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_allow_concurrency_csa",
      a5);
LABEL_25:
    result = 0;
    goto LABEL_26;
  }
  qdf_mem_set(v84, 0xB4u, 0);
  qdf_mutex_acquire(v23 + 56);
  if ( (a6 & 1) != 0 && (a7 == 10 || a7 == 6) )
    policy_mgr_store_and_del_conn_info_by_chan_and_mode(
      a1,
      v82,
      a2,
      (unsigned int *)v84,
      v83,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40);
  else
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
      a1,
      a5,
      v84,
      v83);
  v41 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a5, 24);
  if ( v41 )
  {
    v50 = v41;
    if ( *(_DWORD *)(v41 + 16) || (wlan_vdev_mlme_is_mlo_vdev(v41, v42, v43, v44, v45, v46, v47, v48, v49) & 1) == 0 )
    {
      v60 = 0;
    }
    else if ( (*(_BYTE *)(v50 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v50)) != 0 )
    {
      if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v52, v53, v54, v55, v56, v57, v58, v59) )
        v60 = 3;
      else
        v60 = 1;
    }
    else
    {
      v60 = 1;
    }
    v61 = ((double (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))policy_mgr_allow_concurrency)(
            a1,
            a2,
            a3,
            a4,
            v60,
            a5);
    v63 = v62;
    wlan_objmgr_vdev_release_ref(v50, 0x18u, v64, v61, v65, v66, v67, v68, v69, v70, v71);
    v80 = v83[0];
    if ( v83[0] )
      goto LABEL_20;
  }
  else
  {
    v63 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
            a1,
            a2,
            a3,
            a4,
            0,
            a5);
    v80 = v83[0];
    if ( v83[0] )
LABEL_20:
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v84, v80, v72, v73, v74, v75, v76, v77, v78, v79);
  }
  qdf_mutex_release(v23 + 56);
  if ( (v63 & 1) == 0 )
  {
    v32 = "%s: CSA concurrency check failed";
    goto LABEL_24;
  }
  result = 1;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
