__int64 __fastcall lim_ndi_del_bss_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 session_by_vdev_id; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  unsigned int v34; // w2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD v43[7]; // [xsp+8h] [xbp-38h] BYREF

  v14 = a1 + 0x2000;
  v43[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_ndi_del_bss_rsp";
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a4, a5, a6, a7, a8, a9, a10, a11);
  v23 = *(unsigned __int8 *)(v14 + 693);
  memset(v43, 0, 48);
  if ( v23 )
  {
    if ( *(_WORD *)(v14 + 496) )
    {
      LOWORD(v43[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v43) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v43[0]));
    }
  }
  if ( a2 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(_BYTE *)(a2 + 4), v15, v16, v17, v18, v19, v20, v21, v22);
    if ( session_by_vdev_id )
    {
      a3 = session_by_vdev_id;
      if ( !*(_DWORD *)a2 )
      {
        v34 = 0;
        *(_DWORD *)(session_by_vdev_id + 72) = 1;
        goto LABEL_13;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: NDI: DEL_BSS_RSP error (%x)",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "lim_ndi_del_bss_rsp");
LABEL_10:
      v34 = 533;
LABEL_13:
      lim_send_stop_bss_response(a1, *(unsigned __int8 *)(a3 + 10), v34);
      result = pe_delete_session(a1, a3, v35, v36, v37, v38, v39, v40, v41, v42);
      goto LABEL_14;
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session Does not exist for given sessionID",
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "lim_ndi_del_bss_rsp");
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: NDI: DEL_BSS_RSP with no body!",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "lim_ndi_del_bss_rsp");
    if ( a3 )
      goto LABEL_10;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
