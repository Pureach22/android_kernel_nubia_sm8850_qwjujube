__int64 __fastcall ucfg_p2p_mgmt_tx(
        __int64 a1,
        const void **a2,
        _QWORD *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x19
  __int64 v28; // x8
  size_t v29; // x0
  void *v30; // x0
  int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  unsigned int v41; // w21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  unsigned int v51; // w20
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // [xsp+34h] [xbp-3Ch] BYREF
  __int64 v61; // [xsp+38h] [xbp-38h] BYREF
  __int64 v62; // [xsp+40h] [xbp-30h]
  __int64 (__fastcall *v63)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+48h] [xbp-28h]
  __int64 (__fastcall *v64)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+50h] [xbp-20h]
  __int64 v65; // [xsp+58h] [xbp-18h]
  __int64 v66; // [xsp+60h] [xbp-10h]
  __int64 v67; // [xsp+68h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v66 = 0;
  v63 = nullptr;
  v64 = nullptr;
  v61 = 0;
  v62 = 0;
  v60 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: psoc context passed is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "ucfg_p2p_mgmt_tx");
    result = 4;
    goto LABEL_17;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: P2P soc context is NULL", v17, v18, v19, v20, v21, v22, v23, v24, "ucfg_p2p_mgmt_tx");
    result = 16;
    goto LABEL_17;
  }
  v25 = comp_private_obj;
  v26 = _qdf_mem_malloc(0x110u, "ucfg_p2p_mgmt_tx", 344);
  if ( !v26 )
  {
LABEL_16:
    result = 2;
    goto LABEL_17;
  }
  v27 = v26;
  if ( *((_DWORD *)a2 + 5) )
  {
    v28 = 0;
    v60 = 0;
  }
  else
  {
    v50 = qdf_idr_alloc(v25 + 224, v26, &v60);
    if ( v50 )
    {
      v51 = v50;
      _qdf_mem_free(v27);
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: failed to alloc idr, status :%d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "ucfg_p2p_mgmt_tx",
        v51);
      result = v51;
      goto LABEL_17;
    }
    v28 = v60;
  }
  *a3 = v28;
  *(_QWORD *)(v27 + 16) = v25;
  *(_DWORD *)(v27 + 24) = *(_DWORD *)a2;
  *(_DWORD *)(v27 + 44) = *((_DWORD *)a2 + 1);
  *(_DWORD *)(v27 + 64) = *((_DWORD *)a2 + 2);
  v29 = *((int *)a2 + 3);
  *(_DWORD *)(v27 + 56) = v29;
  *(_BYTE *)(v27 + 61) = *((_DWORD *)a2 + 4) != 0;
  *(_BYTE *)(v27 + 62) = *((_DWORD *)a2 + 5) != 0;
  *(_BYTE *)(v27 + 60) = *((_DWORD *)a2 + 6) != 0;
  *(_DWORD *)(v27 + 264) = *((_DWORD *)a2 + 10);
  v30 = (void *)_qdf_mem_malloc(v29, "ucfg_p2p_mgmt_tx", 371);
  *(_QWORD *)(v27 + 48) = v30;
  if ( !v30 )
  {
    _qdf_mem_free(v27);
    goto LABEL_16;
  }
  qdf_mem_copy(v30, a2[4], *(unsigned int *)(v27 + 56));
  v31 = v60;
  *(_QWORD *)(v27 + 256) = 0;
  *(_DWORD *)(v27 + 40) = v31;
  p2p_rand_mac_tx(a4, v27);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, vdev_id:%d, freq:%d, wait:%d, buf_len:%d, cck:%d, no ack:%d, off chan:%d cookie = 0x%llx opmode:%d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "ucfg_p2p_mgmt_tx",
    a1,
    *(unsigned int *)a2,
    *((unsigned int *)a2 + 1),
    *((unsigned int *)a2 + 2),
    *((_DWORD *)a2 + 3),
    *((_DWORD *)a2 + 4),
    *((_DWORD *)a2 + 5),
    *((_DWORD *)a2 + 6),
    *a3,
    *(_DWORD *)(v27 + 264));
  LOWORD(v61) = 2;
  v62 = v27;
  v63 = p2p_process_cmd;
  v64 = p2p_msg_flush_callback;
  result = scheduler_post_message_debug(0x33u, 0x4Eu, 72, (unsigned __int16 *)&v61, 0x18Bu, (__int64)"ucfg_p2p_mgmt_tx");
  if ( (_DWORD)result )
  {
    v41 = result;
    if ( v60 )
      qdf_idr_remove(v25 + 224, v60);
    _qdf_mem_free(*(_QWORD *)(v27 + 48));
    _qdf_mem_free(v27);
    qdf_trace_msg(0x4Eu, 2u, "%s: post msg fail:%d", v42, v43, v44, v45, v46, v47, v48, v49, "ucfg_p2p_mgmt_tx", v41);
    result = v41;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
