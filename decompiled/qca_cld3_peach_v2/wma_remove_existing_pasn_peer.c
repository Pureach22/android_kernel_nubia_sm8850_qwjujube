__int64 __fastcall wma_remove_existing_pasn_peer(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10)
{
  __int64 *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x19
  unsigned int v21; // w21
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  const char *v32; // x2
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_remove_existing_pasn_peer", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma_handle is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_remove_existing_pasn_peer");
    result = 4;
    goto LABEL_11;
  }
  v20 = context;
  v21 = *a10;
  wma_acquire_wakelock(context + 391, 8000);
  v22 = wmi_unified_peer_delete_send(*v20);
  if ( !v22 )
  {
    wma_remove_objmgr_peer(
      (__int64)v20,
      *(_QWORD *)(v20[65] + 488LL * v21),
      a10 + 1,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30);
    if ( (wmi_service_enabled(*v20, 0x6Eu, v34, v35, v36, v37, v38, v39, v40, v41) & 1) != 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev:%d Wait for the peer delete response",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "wma_remove_existing_pasn_peer",
        v21);
      if ( !wma_fill_hold_req(v20, v21, 4131, 17, a10 + 1, a10, 8000) )
      {
        v32 = "%s: vdev:%d Failed to allocate request";
        v31 = v21;
        goto LABEL_4;
      }
    }
    else
    {
      wma_release_wakelock(v20 + 391);
      lim_continue_bss_peer_create(a10);
    }
    result = 0;
    goto LABEL_11;
  }
  v31 = v22;
  v32 = "%s: Peer delete could not be sent to firmware %d";
LABEL_4:
  qdf_trace_msg(0x36u, 2u, v32, v23, v24, v25, v26, v27, v28, v29, v30, "wma_remove_existing_pasn_peer", v31);
  wma_release_wakelock(v20 + 391);
  result = 16;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
