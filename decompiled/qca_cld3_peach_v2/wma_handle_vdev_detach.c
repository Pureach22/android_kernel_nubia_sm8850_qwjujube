__int64 __fastcall wma_handle_vdev_detach(
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
  unsigned int v11; // w20
  __int64 v12; // x21
  __int64 **context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 **v23; // x19
  __int64 v24; // x8
  __int64 v25; // x8
  void (*v26)(void); // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x20
  unsigned int *v44; // x8
  const char *v45; // x2
  _QWORD v47[9]; // [xsp+8h] [xbp-48h] BYREF

  v47[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a2 + 6);
  v12 = *(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)(a2 + 6);
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_handle_vdev_detach", a3, a4, a5, a6, a7, a8, a9, a10);
  v22 = *(_QWORD *)(a1 + 520);
  v23 = context;
  memset(v47, 0, 64);
  v24 = *(_QWORD *)(v22 + 488LL * v11);
  if ( !v24 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: vdev is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "wma_cdp_vdev_detach");
    goto LABEL_12;
  }
  if ( !context || *(unsigned __int8 *)(v24 + 168) == 255 )
    goto LABEL_12;
  if ( !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_vdev_detach");
    if ( (qdf_is_recovering() & 1) == 0 )
      goto LABEL_14;
LABEL_13:
    wlan_mgmt_txrx_vdev_drain(
      *(_QWORD *)v12,
      (void (*)(void))wma_mgmt_frame_fill_peer_cb,
      (__int64)v47,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
    goto LABEL_14;
  }
  v25 = **context;
  if ( !v25 || (v26 = *(void (**)(void))(v25 + 24)) == nullptr )
  {
LABEL_12:
    if ( (qdf_is_recovering() & 1) == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( *((_DWORD *)v26 - 1) != -1818723745 )
    __break(0x8228u);
  v26();
  if ( (qdf_is_recovering() & 1) != 0 )
    goto LABEL_13;
LABEL_14:
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Releasing wma reference for vdev:%d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wma_handle_vdev_detach",
    v11);
  v43 = *(_QWORD *)v12;
  if ( !*(_QWORD *)v12 )
  {
    v45 = "%s: vdev context is NULL";
LABEL_19:
    qdf_trace_msg(0x36u, 8u, v45, v35, v36, v37, v38, v39, v40, v41, v42, "wma_release_vdev_ref");
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev state: %d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wma_release_vdev_ref",
    *(unsigned int *)(v43 + 1336));
  v44 = (unsigned int *)*(unsigned int *)(v43 + 1336);
  if ( (_DWORD)v44 != 6 )
  {
    v45 = "%s: no vdev delete";
    goto LABEL_19;
  }
  *(_BYTE *)(v12 + 184) = 0;
  *(_QWORD *)v12 = 0;
  wlan_objmgr_vdev_release_ref(v43, 8u, v44, v35, v36, v37, v38, v39, v40, v41, v42);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return 16 * (unsigned int)(v23 == nullptr);
}
