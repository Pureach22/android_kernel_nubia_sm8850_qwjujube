__int64 __fastcall lim_deauth_tx_complete_cnf_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x24
  const char *v17; // x4
  int v18; // w8
  __int64 session_by_session_id; // x23
  char v20; // w25
  bool v21; // w26
  __int64 v22; // x27
  __int64 v23; // x1
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  void *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  unsigned int v43; // w19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 session_by_vdev_id; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // [xsp+0h] [xbp-40h] BYREF
  __int64 v71; // [xsp+8h] [xbp-38h]
  __int64 v72; // [xsp+10h] [xbp-30h]
  __int64 v73; // [xsp+18h] [xbp-28h]
  __int64 v74; // [xsp+20h] [xbp-20h]
  __int64 v75; // [xsp+28h] [xbp-18h]
  __int16 v76; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+38h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  if ( a4 )
    wlan_send_tx_complete_event(a1, a2, a4, a3, 9);
  v16 = *(_QWORD *)(a1 + 12400);
  if ( a3 )
    v17 = "fail";
  else
    v17 = "success";
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tx_complete = %s tx_success = %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_deauth_tx_complete_cnf_handler",
    v17,
    a3,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75);
  if ( !a2
    || ((*(_BYTE *)(a2 + 68) & 4) != 0 ? (v18 = *(unsigned __int16 *)(a2 + 66)) : (v18 = 0),
        (unsigned int)(*(_DWORD *)(a2 + 112) + v18) <= 0x1A) )
  {
    v20 = 0;
    session_by_session_id = 0;
    v21 = v16 == 0;
    goto LABEL_16;
  }
  session_by_session_id = 0;
  v20 = 0;
  v21 = v16 == 0;
  if ( v16 || (v22 = *(_QWORD *)(a2 + 224)) == 0 )
  {
LABEL_16:
    if ( !a4 )
      goto LABEL_18;
    goto LABEL_17;
  }
  if ( a4 )
    v23 = a4[10];
  else
    v23 = 255;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, v23);
  session_by_session_id = session_by_vdev_id;
  if ( session_by_vdev_id
    && (*(_DWORD *)(session_by_vdev_id + 7036) | 2) == 3
    && (v76 = 0,
        (v61 = dph_lookup_hash_entry(
                 v53,
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 a1,
                 (unsigned __int8 *)(v22 + 4),
                 &v76,
                 session_by_vdev_id + 360)) != 0)
    && (*(_WORD *)v61 & 0x800) != 0
    && *(_DWORD *)(v61 + 832) != *(_DWORD *)(session_by_session_id + 284) )
  {
    if ( *(_BYTE *)(v61 + 642) && (*(_BYTE *)(v61 + 645) & 1) == 0 )
      lim_trigger_sta_deletion(a1, v61, session_by_session_id, v62, v63, v64, v65, v66, v67, v68, v69);
    v20 = 1;
  }
  else
  {
    v20 = 0;
  }
  v21 = 1;
  if ( a4 )
LABEL_17:
    lim_update_disconnect_vdev_id(a1, a4[10]);
LABEL_18:
  if ( a2 )
    _qdf_nbuf_free(a2);
  if ( (v20 & 1) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v21 )
      session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v16 + 12));
    if ( a3 && session_by_session_id && *(_BYTE *)(session_by_session_id + 9790) )
    {
      if ( (tx_timer_running(a1 + 2664) & 1) != 0 )
        lim_deactivate_and_change_timer(a1, 17);
      lim_send_deauth_mgmt_frame(
        a1,
        *(unsigned __int16 *)(session_by_session_id + 9788),
        (void *)(session_by_session_id + 9782),
        session_by_session_id,
        1,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32);
      result = 0;
      --*(_BYTE *)(session_by_session_id + 9790);
    }
    else
    {
      v33 = (void *)_qdf_mem_malloc(0x40u, "lim_deauth_tx_complete_cnf_handler", 5080);
      if ( v33 )
      {
        v42 = (__int64)v33;
        qdf_mem_copy(v33, a4, 0x40u);
        v71 = v42;
        LOWORD(v70) = 4320;
        HIDWORD(v70) = a3;
        result = lim_post_msg_high_priority(a1, (unsigned __int16 *)&v70);
        if ( (_DWORD)result )
        {
          v43 = result;
          _qdf_mem_free(v42);
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: posting message: %X to LIM failed, reason: %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "lim_deauth_tx_complete_cnf_handler",
            (unsigned __int16)v70,
            v43);
          result = v43;
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: malloc failed",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "lim_deauth_tx_complete_cnf_handler");
        result = 2;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
