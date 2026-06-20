__int64 __fastcall lim_process_mlm_set_sta_key_rsp(
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
  __int64 v30; // x24
  unsigned int v31; // w21
  int v32; // w3
  unsigned __int8 v33; // w25
  __int64 result; // x0
  __int64 session_by_vdev_id; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w22
  int v45; // w23
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int16 v54; // w9
  bool v55; // zf
  char v56; // w8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 v65; // x1
  _QWORD v66[6]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v67; // [xsp+38h] [xbp-18h] BYREF
  int v68; // [xsp+40h] [xbp-10h]
  __int64 v69; // [xsp+48h] [xbp-8h]

  v12 = a1 + 0x2000;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_mlm_set_sta_key_rsp";
  v68 = 0;
  v67 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = *(unsigned __int8 *)(v12 + 693);
  memset(v66, 0, sizeof(v66));
  if ( v13 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v66[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v66) )
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
          LOWORD(v66[0]));
    }
  }
  qdf_mem_set(&v67, 0xCu, 0);
  v30 = *(_QWORD *)(a2 + 8);
  if ( v30 )
  {
    v31 = *(unsigned __int8 *)(v30 + 6);
    if ( (unsigned int)wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), *(_BYTE *)(v30 + 6)) == 16 )
    {
      v32 = 0;
      v33 = v31;
    }
    else
    {
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, v31);
      if ( !session_by_vdev_id )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session does not exist for given vdev_id %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "lim_process_mlm_set_sta_key_rsp",
          v31);
        qdf_mem_set(*(void **)(a2 + 8), 0x20u, 0);
        _qdf_mem_free(*(_QWORD *)(a2 + 8));
        v65 = (unsigned int)v67 | ((unsigned __int64)WORD2(v67) << 32);
        *(_QWORD *)(a2 + 8) = 0;
        result = lim_send_sme_set_context_rsp(a1, v65, 0, 541, 0, v31);
        goto LABEL_18;
      }
      v33 = *(_BYTE *)(session_by_vdev_id + 8);
      v32 = *(_DWORD *)(session_by_vdev_id + 72);
    }
    qdf_trace(53, 0, v33, v32);
    v44 = *(unsigned __int16 *)(v30 + 16);
    v45 = *(unsigned __int16 *)(v30 + 28);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: PE session ID %d, vdev_id %d key_len %d status %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_process_mlm_set_sta_key_rsp",
      v33,
      v31,
      *(unsigned __int16 *)(v30 + 28),
      *(unsigned __int16 *)(v30 + 16));
    v54 = *(_WORD *)(v30 + 25);
    if ( v44 )
      v55 = 1;
    else
      v55 = v45 == 0;
    LODWORD(v67) = *(_DWORD *)(v30 + 21);
    v56 = !v55;
    WORD2(v67) = v54;
    HIBYTE(v68) = v56;
    BYTE2(v68) = v33;
    qdf_trace(53, 0xAu, 0, 1024);
    lim_process_mlm_set_keys_cnf(a1, (unsigned __int8 *)&v67, v57, v58, v59, v60, v61, v62, v63, v64);
    qdf_mem_set(*(void **)(a2 + 8), 0x20u, 0);
    result = _qdf_mem_free(*(_QWORD *)(a2 + 8));
    *(_QWORD *)(a2 + 8) = 0;
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg bodyptr is NULL",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "lim_process_mlm_set_sta_key_rsp");
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
