__int64 __fastcall lim_process_auth_frame_type2(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int16 *a3,
        _WORD *a4,
        __int64 a5,
        const void *a6,
        unsigned __int16 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v20; // x4
  __int64 v22; // x24
  __int64 v24; // x5
  const char *v25; // x2
  __int64 v26; // x6
  __int64 v27; // x7
  unsigned int v28; // w1
  __int64 result; // x0
  int v30; // w4
  int v31; // w9
  __int64 v32; // x8
  int v33; // w10
  int v34; // w10
  __int64 v35; // x2
  __int64 v36; // x0
  __int64 v37; // x1
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  int v49; // w26
  __int64 v50; // x1
  _BYTE *v51; // x8
  __int64 v52; // x0
  unsigned int v53; // w24
  int wep_key; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned __int16 v63; // w8
  __int64 v64; // x0
  __int64 v65; // x23
  unsigned __int16 v66; // w8
  unsigned int v67; // w26
  unsigned __int16 v68; // w8
  size_t v69; // x2
  __int64 v70; // x25
  __int16 v71; // w2
  int v72; // [xsp+0h] [xbp-30h]
  unsigned __int64 v73; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v74[3]; // [xsp+18h] [xbp-18h] BYREF

  v74[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(unsigned int *)(a8 + 72);
  memset(v74, 0, 13);
  if ( (_DWORD)v20 != 5 )
  {
    if ( *(_DWORD *)(a8 + 88) == 2 && *(_DWORD *)(a8 + 80) == 6 && !a3[2] )
    {
      v46 = *(_QWORD *)(a8 + 7432);
      if ( v46 )
      {
        if ( !(unsigned int)qdf_mem_cmp((const void *)(v46 + 18), a2 + 10, 6u) )
        {
          result = qdf_trace_msg(
                     0x35u,
                     3u,
                     "%s: rx PreAuth frm2 in smestate: %d from: %02x:%02x:%02x:**:**:%02x",
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     a14,
                     a15,
                     a16,
                     "lim_process_auth_frame_type2",
                     *(unsigned int *)(a8 + 80),
                     a2[10],
                     a2[11],
                     a2[12],
                     a2[15]);
          *(_WORD *)(a8 + 7444) = 0;
          if ( a6 && a7 <= 0x17Fu )
          {
            result = (__int64)qdf_mem_copy((void *)(a8 + 7446), a6, a7);
            *(_WORD *)(a8 + 7444) = a7;
          }
          goto LABEL_10;
        }
        v20 = *(unsigned int *)(a8 + 72);
      }
    }
    v24 = a2[10];
    v26 = a2[11];
    v25 = "%s: rx Auth frm2 from peer in state: %d addr %02x:%02x:%02x:**:**:%02x";
    v27 = a2[12];
    v28 = 8;
    v72 = a2[15];
    goto LABEL_9;
  }
  v22 = *(_QWORD *)(a1 + 8);
  if ( (unsigned int)qdf_mem_cmp(a2 + 10, *(const void **)(a1 + 11376), 6u) )
  {
    v20 = a2[10];
    v24 = a2[11];
    v25 = "%s: received Auth frame2 from unexpected peer%02x:%02x:%02x:**:**:%02x";
    v26 = a2[12];
    v27 = a2[15];
LABEL_4:
    v28 = 3;
LABEL_9:
    result = qdf_trace_msg(
               0x35u,
               v28,
               v25,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               "lim_process_auth_frame_type2",
               v20,
               v24,
               v26,
               v27,
               v72);
    goto LABEL_10;
  }
  if ( *(_DWORD *)(a8 + 88) == 2
    && (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a8 + 16), a9, a10, a11, a12, a13, a14, a15, a16) & 1) != 0
    && (a3[508] & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: MLO IE not present in auth frame from peer, abort connection",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "lim_process_auth_frame_type2");
    lim_send_deauth_mgmt_frame(a1, 1, a8 + 24, a8, 0);
    v36 = a1;
    v37 = 500;
LABEL_30:
    v35 = 1;
    goto LABEL_31;
  }
  v30 = a3[2];
  v31 = *a3;
  v32 = *(_QWORD *)(a1 + 11376);
  if ( v30 == 13 )
  {
    v33 = *(_DWORD *)(v32 + 8);
    if ( v33 != v31 )
    {
      *a3 = v33;
      LOWORD(v31) = v33;
      v32 = *(_QWORD *)(a1 + 11376);
    }
  }
  v34 = *(_DWORD *)(v32 + 8);
  if ( v34 == (unsigned __int16)v31 )
  {
    if ( v30 )
    {
LABEL_19:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: rx Auth frame from peer with failure code %d %02x:%02x:%02x:**:**:%02x",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "lim_process_auth_frame_type2",
        a2[15]);
      v35 = a3[2];
      v36 = a1;
      v37 = 513;
LABEL_31:
      result = lim_restore_from_auth_state(v36, v37, v35, a8);
      goto LABEL_10;
    }
  }
  else
  {
    if ( v34 != 3 || *(_BYTE *)(a8 + 10008) != 1 )
    {
      v24 = a2[10];
      v26 = a2[11];
      v25 = "%s: rx Auth frame2 for unexpected auth algo %d%02x:%02x:%02x:**:**:%02x";
      v27 = a2[12];
      v28 = 3;
      v20 = (unsigned __int16)v31;
      v72 = a2[15];
      goto LABEL_9;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: rx Auth frame2 auth algo %d in SAE PMK case",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "lim_process_auth_frame_type2",
      (unsigned __int16)v31);
    if ( a3[2] )
      goto LABEL_19;
  }
  if ( (lim_process_fils_auth_frame2(a1, a8, a3) & 1) != 0 )
  {
LABEL_24:
    v35 = a3[2];
    v36 = a1;
    v37 = 0;
    goto LABEL_31;
  }
  if ( !*a3 )
  {
    *(_DWORD *)(a8 + 172) = 0;
    v64 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
    v20 = a2[10];
    v24 = a2[11];
    v26 = a2[12];
    v27 = a2[15];
    if ( !v64 )
    {
      v25 = "%s: Max pre-auth nodes reached SA: %02x:%02x:%02x:**:**:%02x";
      goto LABEL_4;
    }
    v65 = v64;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: add new auth node: for %02x:%02x:%02x:**:**:%02x",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "lim_process_auth_frame_type2",
      v20,
      v24,
      v26,
      v27);
    qdf_mem_copy((void *)(v65 + 8), *(const void **)(a1 + 11376), 6u);
    *(_BYTE *)(v65 + 278) &= ~1u;
    *(_DWORD *)(v65 + 16) = *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL);
    *(_WORD *)(v65 + 544) = *((_WORD *)a2 + 11) >> 4;
    *(_QWORD *)(v65 + 552) = qdf_mc_timer_get_system_ticks();
    lim_add_pre_auth_node(a1, v65);
    goto LABEL_24;
  }
  v49 = *(_DWORD *)(a8 + 88);
  v50 = v22 + 5652;
  v51 = (_BYTE *)(a8 + 1620);
  if ( v49 != 1 )
    v51 = (_BYTE *)(v22 + 5652);
  if ( !*v51 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: rx Auth frm from peer for unsupported auth algo %d %02x:%02x:%02x:**:**:%02x",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "lim_process_auth_frame_type2",
      a2[15]);
    *a4 = *a3;
    v66 = a3[1];
    a4[2] = 13;
    a4[1] = v66 + 1;
    result = lim_send_auth_mgmt_frame(a1, a4, a2 + 10, 0, a8);
    goto LABEL_10;
  }
  if ( *((_BYTE *)a3 + 6) != 16 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: rx auth frm with invalid challenge txtie",
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               "lim_process_auth_frame_type2");
    goto LABEL_10;
  }
  v52 = *(_QWORD *)(a8 + 16);
  v53 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5656LL);
  v73 = 13;
  wep_key = mlme_get_wep_key(v52, v38, v39, v40, v41, v42, v43, v44, v45, v50, v53, v74, &v73);
  if ( v49 != 1 && wep_key )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: cant retrieve Defaultkey",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "lim_process_auth_frame_type2");
    *a4 = *a3;
    v63 = a3[1];
    a4[2] = 15;
    a4[1] = v63 + 1;
    lim_send_auth_mgmt_frame(a1, a4, a2 + 10, 0, a8);
    v36 = a1;
    v37 = 514;
    goto LABEL_30;
  }
  v67 = v73;
  *(_WORD *)a5 = *a3;
  v68 = a3[1];
  *(_WORD *)(a5 + 4) = 0;
  *(_BYTE *)(a5 + 6) = 16;
  *(_WORD *)(a5 + 2) = v68 + 1;
  v69 = *((unsigned __int8 *)a3 + 7);
  *(_BYTE *)(a5 + 7) = v69;
  qdf_mem_copy((void *)(a5 + 8), a3 + 4, v69);
  result = _qdf_mem_malloc(*((unsigned __int8 *)a3 + 7) + 16LL, "lim_process_auth_frame_type2", 1464);
  if ( result )
  {
    v70 = result;
    lim_encrypt_auth_frame(a1, v53, v74, a5, result, v67);
    v71 = *(_WORD *)(a8 + 8);
    *(_DWORD *)(a8 + 72) = 7;
    qdf_trace(53, 0, v71, 7);
    lim_send_auth_mgmt_frame(a1, v70, a2 + 10, *((unsigned __int8 *)a3 + 7), a8);
    result = _qdf_mem_free(v70);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
