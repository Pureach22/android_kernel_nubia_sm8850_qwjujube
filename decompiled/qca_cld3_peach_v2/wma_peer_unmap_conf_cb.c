__int64 __fastcall wma_peer_unmap_conf_cb(
        unsigned int a1,
        unsigned int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x22
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *v33; // x23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  __int64 v43; // x22
  void *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w19
  _QWORD v54[7]; // [xsp+8h] [xbp-38h] BYREF

  v54[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_peer_unmap_conf_cb", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v23 = context;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: peer_id_cnt: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_peer_unmap_conf_cb",
      a2);
    result = wmi_unified_peer_unmap_conf_send(*v23, a1, a2, a3);
    if ( (_DWORD)result == 8 )
    {
      memset(&v54[2], 0, 32);
      v33 = _cds_get_context(53, (__int64)"wma_peer_unmap_conf_cb", v25, v26, v27, v28, v29, v30, v31, v32);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: post unmap_conf cmd to MC thread",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "wma_peer_unmap_conf_cb");
      if ( v33 )
      {
        v42 = _qdf_mem_malloc(0x10u, "wma_peer_unmap_conf_cb", 1678);
        if ( v42 )
        {
          *(_BYTE *)v42 = a1;
          v43 = v42;
          *(_DWORD *)(v42 + 4) = a2;
          v44 = (void *)_qdf_mem_malloc(2LL * a2, "wma_peer_unmap_conf_cb", 1686);
          *(_QWORD *)(v43 + 8) = v44;
          if ( v44 )
          {
            qdf_mem_copy(v44, a3, 2 * a2);
            v54[0] = 4539;
            v54[1] = v43;
            if ( !(unsigned int)wma_post_ctrl_msg((__int64)v33, (unsigned __int16 *)v54) )
            {
              result = 8;
              goto LABEL_14;
            }
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: wma_post_ctrl_msg failed",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "wma_peer_unmap_conf_cb");
            _qdf_mem_free(*(_QWORD *)(v43 + 8));
            v53 = 16;
          }
          else
          {
            v53 = 2;
          }
          _qdf_mem_free(v43);
          result = v53;
        }
        else
        {
          result = 2;
        }
      }
      else
      {
        result = 16;
      }
    }
  }
  else
  {
    result = 4;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
