__int64 __fastcall lim_process_mlm_set_bss_key_rsp(
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
  __int64 v12; // x21
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int8 *v30; // x23
  unsigned int v31; // w21
  __int64 session_by_vdev_id; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // w24
  int v42; // w22
  int v43; // w25
  __int64 v44; // x26
  int v45; // w3
  bool v46; // zf
  char v47; // w8
  void *v48; // x0
  __int16 v49; // w9
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  unsigned __int64 v59; // x1
  _QWORD v60[6]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v61; // [xsp+38h] [xbp-18h] BYREF
  int v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v12 = a1 + 0x2000;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_mlm_set_bss_key_rsp";
  v62 = 0;
  v61 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *(unsigned __int8 *)(v12 + 693);
  memset(v60, 0, sizeof(v60));
  if ( v13 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v60[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v60) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v60[0]));
    }
  }
  qdf_mem_set(&v61, 0xCu, 0);
  v30 = *(unsigned __int8 **)(a2 + 8);
  if ( v30 )
  {
    v31 = *v30;
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *v30);
    if ( session_by_vdev_id )
    {
      v41 = *(_WORD *)(session_by_vdev_id + 8);
      v42 = *((unsigned __int16 *)v30 + 2);
      v43 = *((unsigned __int16 *)v30 + 7);
      v44 = session_by_vdev_id;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev %d (pe %d) limMlmState %d status %d key_len %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_process_mlm_set_bss_key_rsp",
        v31,
        (unsigned __int8)v41,
        *(unsigned int *)(session_by_vdev_id + 72),
        *((unsigned __int16 *)v30 + 2),
        v43);
      v45 = *(_DWORD *)(v44 + 72);
      if ( v42 )
        v46 = 1;
      else
        v46 = v43 == 0;
      v47 = !v46;
      HIBYTE(v62) = v47;
      qdf_trace(53, 0, *(_WORD *)(v44 + 8), v45);
      BYTE2(v62) = v41;
      v48 = *(void **)(a2 + 8);
      v49 = *((_WORD *)v30 + 6);
      LODWORD(v61) = *((_DWORD *)v30 + 2);
      WORD2(v61) = v49;
      qdf_mem_set(v48, 0x10u, 0);
      _qdf_mem_free(*(_QWORD *)(a2 + 8));
      *(_QWORD *)(a2 + 8) = 0;
      qdf_trace(53, 0xAu, 0, 1024);
      result = lim_process_mlm_set_keys_cnf(a1, (unsigned __int8 *)&v61, v50, v51, v52, v53, v54, v55, v56, v57);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session does not exist for vdev_id %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_process_mlm_set_bss_key_rsp",
        v31);
      qdf_mem_set(*(void **)(a2 + 8), 0x10u, 0);
      _qdf_mem_free(*(_QWORD *)(a2 + 8));
      v59 = (unsigned int)v61 | ((unsigned __int64)WORD2(v61) << 32);
      *(_QWORD *)(a2 + 8) = 0;
      result = lim_send_sme_set_context_rsp(a1, v59, 0, 541, 0, v31);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg bodyptr is null",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "lim_process_mlm_set_bss_key_rsp");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
