__int64 __fastcall lim_perform_deauth(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  __int64 v28; // x4
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8
  int v32; // w9
  __int64 v33; // x6
  __int64 v34; // x7
  int v35; // w8
  int v36; // w9
  __int64 v37; // x6
  __int64 v38; // x7
  int v39; // w8
  int v40; // w9
  __int64 v41; // x23
  int v42; // w8
  int v43; // w9
  __int64 v44; // x24
  __int64 v45; // x8
  __int64 v46; // x6
  __int64 v47; // x7
  int v48; // w8
  int v49; // w9
  __int64 v50; // x6
  __int64 v51; // x7
  int v52; // w8
  int v53; // w9
  __int64 v54; // x6
  __int64 v55; // x7
  int v56; // w8
  int v57; // w9
  __int64 v58; // x6
  __int64 v59; // x7
  int v60; // w8
  int v61; // w9
  int v62; // w9
  __int64 v63; // x0
  __int16 v64; // w2
  int v65; // w3
  __int16 v66; // w2
  const char *v67; // x2
  __int64 v68; // x5
  unsigned int v69; // w1
  __int16 v70; // w8
  __int64 v71; // x20
  int v72; // w8
  int v73; // w9
  __int64 v74; // x24
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int16 v83; // w9
  int v84; // w10
  __int64 v85; // [xsp+0h] [xbp-40h]
  __int64 v86; // [xsp+8h] [xbp-38h]
  __int16 v87; // [xsp+1Ch] [xbp-24h] BYREF
  __int64 v88; // [xsp+20h] [xbp-20h] BYREF
  __int64 v89; // [xsp+28h] [xbp-18h] BYREF
  int v90; // [xsp+30h] [xbp-10h]
  __int64 v91; // [xsp+38h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  v89 = 0;
  v88 = 518;
  v87 = 0;
  result = dph_lookup_hash_entry(a6, a7, a8, a9, a10, a11, a12, a13, a1, a4, &v87, a2 + 360);
  if ( !result )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Hash entry not found",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "lim_perform_deauth");
    goto LABEL_69;
  }
  v27 = *(_DWORD *)(a2 + 88);
  if ( v27 == 1 )
    goto LABEL_61;
  if ( v27 != 2 )
    goto LABEL_69;
  v28 = *(unsigned int *)(a2 + 72);
  if ( (int)v28 <= 10 )
  {
    if ( (int)v28 > 8 )
    {
      if ( (_DWORD)v28 == 9 )
      {
        if ( a4 )
        {
          v46 = *a4;
          v47 = a4[1];
          v48 = a4[2];
          v49 = a4[5];
        }
        else
        {
          v48 = 0;
          v46 = 0;
          v47 = 0;
          v49 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: received Deauth frame state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_perform_deauth",
          9,
          (unsigned __int16)a3,
          v46,
          v47,
          v48,
          v49);
        qdf_mem_copy(&v89, a4, 6u);
        v66 = *(_WORD *)(a2 + 8);
        HIWORD(v89) = a3;
        *(_DWORD *)(a2 + 72) = 1;
        qdf_trace(53, 0, v66, 1);
        result = lim_process_mlm_rsp_messages(a1, 1019, &v89);
      }
      else
      {
        if ( a4 )
        {
          v37 = *a4;
          v38 = a4[1];
          v39 = a4[2];
          v40 = a4[5];
        }
        else
        {
          v39 = 0;
          v37 = 0;
          v38 = 0;
          v40 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: received Deauth frame state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_perform_deauth",
          10,
          (unsigned __int16)a3,
          v37,
          v38,
          v39,
          v40);
        if ( lim_search_pre_auth_list(a1, a4) )
          lim_delete_pre_auth_node(a1, a4);
        lim_stop_pmfcomeback_timer(a2);
        v63 = *(_QWORD *)(a2 + 128);
        if ( v63 )
        {
          _qdf_mem_free(v63);
          *(_QWORD *)(a2 + 128) = 0;
        }
        v64 = *(_WORD *)(a2 + 8);
        v65 = *(_DWORD *)(a2 + 76);
        WORD2(v88) = a3;
        BYTE6(v88) = v64;
        *(_DWORD *)(a2 + 72) = v65;
        qdf_trace(53, 0, v64, v65);
        lim_deactivate_and_change_timer(a1, 5);
        result = lim_process_mlm_rsp_messages(a1, 1010, &v88);
      }
      goto LABEL_69;
    }
    if ( (_DWORD)v28 == 1 )
      goto LABEL_22;
    if ( (_DWORD)v28 == 5 )
    {
      if ( a4 )
      {
        v33 = *a4;
        v34 = a4[1];
        v35 = a4[2];
        v36 = a4[5];
      }
      else
      {
        v35 = 0;
        v33 = 0;
        v34 = 0;
        v36 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: received Deauth frame state %X with failure code %d from %02x:%02x:%02x:**:**:%02x",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_perform_deauth",
        5,
        (unsigned __int16)a3,
        v33,
        v34,
        v35,
        v36);
      result = lim_restore_from_auth_state(a1, 518, a3, a2);
      goto LABEL_69;
    }
    goto LABEL_37;
  }
  if ( (int)v28 > 20 )
  {
    if ( (_DWORD)v28 == 21 )
    {
      *(_BYTE *)(a2 + 7263) = 1;
      if ( a4 )
      {
        v50 = *a4;
        v51 = a4[1];
        v52 = a4[2];
        v53 = a4[5];
      }
      else
      {
        v52 = 0;
        v50 = 0;
        v51 = 0;
        v53 = 0;
      }
      v67 = "%s: Received Deauth frame in state %X with Reason Code %d from Peer%02x:%02x:%02x:**:**:%02x";
      LODWORD(v86) = v53;
      v68 = (unsigned __int16)a3;
      v69 = 8;
      v28 = 21;
      goto LABEL_79;
    }
    if ( (_DWORD)v28 != 28 )
    {
      if ( (_DWORD)v28 == 29 )
      {
        if ( a4 )
        {
          v29 = *a4;
          v30 = a4[1];
          v31 = a4[2];
          v32 = a4[5];
        }
        else
        {
          v31 = 0;
          v29 = 0;
          v30 = 0;
          v32 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: received Deauth frame state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_perform_deauth",
          29,
          (unsigned __int16)a3,
          v29,
          v30,
          v31,
          v32);
        result = _qdf_mem_malloc(0x24u, "lim_process_sae_auth_msg", 374);
        if ( result )
        {
          v70 = *(unsigned __int8 *)(a2 + 10);
          v71 = result;
          *(_BYTE *)(result + 22) = 1;
          *(_WORD *)(result + 4) = v70;
          *(_DWORD *)(result + 32) = 513;
          qdf_mem_copy((void *)(result + 23), a4, 6u);
          lim_process_sae_msg(a1, v71);
          result = _qdf_mem_free(v71);
        }
        goto LABEL_69;
      }
      goto LABEL_37;
    }
    v44 = result;
    if ( a4 )
    {
      v58 = *a4;
      v59 = a4[1];
      v60 = a4[2];
      v61 = a4[5];
    }
    else
    {
      v60 = 0;
      v58 = 0;
      v59 = 0;
      v61 = 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received Deauth frame in FT state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "lim_perform_deauth",
      28,
      (unsigned __int16)a3,
      v58,
      v59,
      v60,
      v61);
    goto LABEL_60;
  }
  if ( (_DWORD)v28 != 11 )
  {
    if ( (_DWORD)v28 == 14 )
    {
LABEL_22:
      if ( *(_BYTE *)(result + 344) == 4 )
      {
        v41 = result;
        if ( a4 )
        {
          v42 = a4[2];
          v43 = a4[5];
        }
        else
        {
          v42 = 0;
          v43 = 0;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: received Deauth frame in state %X with reason code %d from Tdls peer%02x:%02x:%02x:**:**:%02x",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_perform_deauth",
          v42,
          v43);
        result = lim_send_sme_tdls_del_sta_ind(a1, v41, a2, a3);
        goto LABEL_69;
      }
      v44 = result;
      if ( !(unsigned int)qdf_mem_cmp(a4, (const void *)(a2 + 24), 6u) )
        lim_delete_tdls_peers(a1, a2, 0);
      v45 = lim_search_pre_auth_list(a1, a4);
      result = v44;
      if ( !v45 )
        goto LABEL_61;
      lim_delete_pre_auth_node(a1, a4);
      goto LABEL_60;
    }
LABEL_37:
    if ( a4 )
    {
      v50 = *a4;
      v51 = a4[1];
      v52 = a4[2];
      v62 = a4[5];
    }
    else
    {
      v52 = 0;
      v50 = 0;
      v51 = 0;
      v62 = 0;
    }
    v67 = "%s: received Deauth frame in state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x";
    v68 = (unsigned __int16)a3;
    v69 = 2;
    LODWORD(v86) = v62;
LABEL_79:
    LODWORD(v85) = v52;
LABEL_68:
    result = qdf_trace_msg(
               0x35u,
               v69,
               v67,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "lim_perform_deauth",
               v28,
               v68,
               v50,
               v51,
               v85,
               v86);
    goto LABEL_69;
  }
  v44 = result;
  if ( a4 )
  {
    v54 = *a4;
    v55 = a4[1];
    v56 = a4[2];
    v57 = a4[5];
  }
  else
  {
    v56 = 0;
    v54 = 0;
    v55 = 0;
    v57 = 0;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: received Deauth frame state %X with reasonCode=%d from %02x:%02x:%02x:**:**:%02x",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "lim_perform_deauth",
    11,
    (unsigned __int16)a3,
    v54,
    v55,
    v56,
    v57);
LABEL_60:
  result = v44;
LABEL_61:
  v72 = *(_DWORD *)(result + 8);
  if ( v72 == 17 || v72 == 22 || *(_BYTE *)(result + 645) == 1 )
  {
    v28 = *(unsigned __int8 *)(result + 645);
    if ( a4 )
    {
      v68 = *a4;
      v50 = a4[1];
      v51 = a4[2];
      v73 = a4[5];
    }
    else
    {
      v51 = 0;
      v68 = 0;
      v50 = 0;
      v73 = 0;
    }
    v67 = "%s: Deletion is in progress (%d) for peer:%02x:%02x:%02x:**:**:%02x in mlmState %d";
    v69 = 8;
    LODWORD(v86) = *(_DWORD *)(result + 8);
    LODWORD(v85) = v73;
    goto LABEL_68;
  }
  v74 = result;
  *(_DWORD *)(result + 24) = (unsigned __int16)a3;
  *(_WORD *)(result + 34) = 5;
  *(_BYTE *)(result + 645) = 1;
  qdf_mem_copy(&v89, (const void *)(result + 338), 6u);
  v83 = *(unsigned __int8 *)(v74 + 24);
  v84 = *(unsigned __int8 *)(a1 + 12409);
  LOWORD(v90) = 5;
  HIWORD(v89) = v83;
  if ( v84 )
    *(_BYTE *)(a1 + 12409) = 0;
  if ( *(_DWORD *)(a2 + 88) == 2 )
    v75 = wma_tx_abort(*(unsigned __int8 *)(a2 + 10));
  lim_update_lost_link_info((_DWORD *)a1, a2, a5, v75, v76, v77, v78, v79, v80, v81, v82);
  if ( *(_DWORD *)(a2 + 88) == 2 )
    lim_process_mlm_rsp_messages(a1, 1019, &v89);
  result = lim_send_sme_deauth_ind(a1, v74, a2);
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
