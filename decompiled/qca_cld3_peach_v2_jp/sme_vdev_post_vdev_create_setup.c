__int64 __fastcall sme_vdev_post_vdev_create_setup(
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
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  unsigned int v22; // w20
  unsigned int setup; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  __int64 result; // x0
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w22
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to get vdev mlme obj!",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sme_vdev_post_vdev_create_setup");
    return 4;
  }
  v21 = cmpt_obj;
  v22 = *(unsigned __int8 *)(a2 + 104);
  setup = wma_post_vdev_create_setup(a2);
  if ( setup )
  {
    v32 = setup;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to setup wma for vdev: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "sme_vdev_post_vdev_create_setup",
      v22);
    return v32;
  }
  v34 = csr_setup_vdev_session(v21);
  if ( v34 )
  {
    v43 = v34;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to setup CSR layer for vdev: %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "sme_vdev_post_vdev_create_setup",
      v22);
  }
  else
  {
    wlan_vdev_set_dot11mode(*(_QWORD *)(a1 + 8), *(_DWORD *)(a2 + 16), v21, v35, v36, v37, v38, v39, v40, v41, v42);
    result = mlme_vdev_self_peer_create(a2, v44, v45, v46, v47, v48, v49, v50, v51);
    if ( !(_DWORD)result )
      return result;
    v43 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to create vdev selfpeer for vdev:%d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "sme_vdev_post_vdev_create_setup",
      v22);
    csr_cleanup_vdev_session(a1, v22);
  }
  wma_cleanup_vdev(a2);
  return v43;
}
