__int64 __fastcall lim_process_sae_msg(
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
  __int64 session_by_vdev_id; // x0
  unsigned int v13; // w6
  __int64 v14; // x20
  int v15; // w8
  __int64 v16; // x2
  __int64 v17; // x1
  __int64 v18; // x0
  const char *v19; // x2
  unsigned int v20; // w1
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  __int64 v58; // x23
  __int64 v59; // x0
  __int64 v60; // x24
  __int64 v61; // x0
  __int64 v62; // [xsp+0h] [xbp-30h]
  _QWORD v63[3]; // [xsp+18h] [xbp-18h] BYREF

  v63[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v19 = "%s: SAE msg is NULL";
LABEL_13:
    v20 = 2;
    goto LABEL_14;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
  if ( !session_by_vdev_id )
  {
    v19 = "%s: SAE:Unable to find session";
    goto LABEL_13;
  }
  v13 = *(_DWORD *)(session_by_vdev_id + 7036);
  v14 = session_by_vdev_id;
  if ( v13 >= 4 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: SAE:Not supported in this mode %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_sae_msg",
               v13);
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SAE:status %d limMlmState %d opmode %d peer: %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_sae_msg",
    *(unsigned __int8 *)(a2 + 22),
    *(unsigned int *)(session_by_vdev_id + 72),
    *(unsigned __int8 *)(a2 + 24),
    *(unsigned __int8 *)(a2 + 25),
    *(unsigned __int8 *)(a2 + 28));
  v15 = *(_DWORD *)(v14 + 88);
  if ( v15 != 1 )
  {
    if ( v15 == 2 )
    {
      if ( *(_DWORD *)(v14 + 72) == 29 )
      {
        if ( (tx_timer_running(a1 + 3192) & 1) != 0 )
          lim_deactivate_and_change_timer(a1, 21);
        lim_sae_auth_cleanup_retry(a1, *(unsigned __int8 *)(v14 + 10));
        v16 = *(unsigned __int8 *)(a2 + 22);
        if ( *(_BYTE *)(a2 + 22) )
        {
          v17 = *(unsigned int *)(a2 + 32);
          v18 = a1;
        }
        else
        {
          v63[0] = 0;
          v63[1] = 0;
          if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 6), v63, 0x10u) )
          {
            v57 = _qdf_mem_malloc(0x98u, "lim_process_sae_msg_sta", 107);
            if ( v57 )
            {
              v58 = v57;
              v59 = _qdf_mem_malloc(0x101u, "lim_process_sae_msg_sta", 111);
              if ( v59 )
              {
                v60 = v59;
                qdf_mem_copy((void *)(v58 + 6), (const void *)(a2 + 6), 0x10u);
                qdf_mem_copy((void *)v58, (const void *)(a2 + 23), 6u);
                qdf_mem_set((void *)(*(_QWORD *)(v14 + 112) + 2LL), 0x101u, 0);
                lim_update_connect_rsn_ie(v14, v60, v58);
                _qdf_mem_free(v58);
                v61 = v60;
              }
              else
              {
                v61 = v58;
              }
              _qdf_mem_free(v61);
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: pmkid not received in ext auth",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "lim_process_sae_msg_sta");
          }
          v18 = a1;
          v17 = 0;
          v16 = 0;
        }
        result = lim_restore_from_auth_state(v18, v17, v16, v14);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: received SAE msg in state %X",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "lim_process_sae_msg_sta");
        result = lim_print_mlm_state(a1, 2, *(unsigned int *)(v14 + 72));
      }
      goto LABEL_16;
    }
    v19 = "%s: SAE message on unsupported interface";
    v20 = 8;
LABEL_14:
    result = qdf_trace_msg(0x35u, v20, v19, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_sae_msg");
    goto LABEL_16;
  }
  result = lim_search_pre_auth_list(a1, a2 + 23);
  if ( result )
  {
    v30 = result;
    if ( *(_BYTE *)(a2 + 22) )
    {
      LODWORD(v62) = *(unsigned __int8 *)(a2 + 22);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: SAE authentication failed for %02x:%02x:%02x:**:**:%02x status: %u",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_process_sae_msg_ap",
        *(unsigned __int8 *)(a2 + 23),
        *(unsigned __int8 *)(a2 + 24),
        *(unsigned __int8 *)(a2 + 25),
        *(unsigned __int8 *)(a2 + 28),
        v62);
      if ( *(_BYTE *)(v30 + 560) == 1 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Assoc req cached; clean it up",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "lim_process_sae_msg_ap");
        lim_process_assoc_cleanup(a1, v14, *(_QWORD *)(v30 + 584), *(_BYTE *)(v30 + 577));
        v39 = *(_QWORD *)(v30 + 568);
        *(_BYTE *)(v30 + 560) = 0;
        lim_free_assoc_req_frm_buf(v39);
        _qdf_mem_free(*(_QWORD *)(v30 + 568));
      }
      result = lim_delete_pre_auth_node(a1, a2 + 23);
    }
    else
    {
      v40 = *(unsigned __int8 *)(result + 560);
      *(_DWORD *)(result + 20) = 9;
      if ( v40 == 1 )
      {
        LOBYTE(v63[0]) = 0;
        *(_BYTE *)(result + 560) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Assoc req cached; handle it",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "lim_process_sae_msg_ap");
        result = lim_send_assoc_ind_to_sme(
                   a1,
                   v14,
                   *(unsigned __int8 *)(v30 + 561),
                   (unsigned __int8 *)(v30 + 562),
                   *(_WORD **)(v30 + 568),
                   7,
                   *(_BYTE *)(v30 + 576),
                   v63,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   *(_BYTE *)(v30 + 578),
                   0,
                   *(_WORD *)(v30 + 592));
        if ( (result & 1) == 0 )
        {
          lim_process_assoc_cleanup(a1, v14, *(_QWORD *)(v30 + 584), v63[0]);
          lim_free_assoc_req_frm_buf(*(_QWORD *)(v30 + 568));
          result = _qdf_mem_free(*(_QWORD *)(v30 + 568));
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "lim_process_sae_msg_ap",
               *(unsigned __int8 *)(a2 + 23),
               *(unsigned __int8 *)(a2 + 24),
               *(unsigned __int8 *)(a2 + 25),
               *(unsigned __int8 *)(a2 + 28));
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
