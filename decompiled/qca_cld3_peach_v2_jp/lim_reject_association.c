__int64 __fastcall lim_reject_association(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4,
        unsigned int a5,
        unsigned __int16 a6,
        unsigned __int8 a7,
        unsigned int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int64 a17)
{
  __int64 v25; // x4
  int v26; // w10
  int v27; // w11
  int v28; // w12
  int v29; // w13
  __int64 v30; // x8
  __int64 *v31; // x9
  __int64 v32; // x27
  char v33; // w8
  __int16 *hash_entry; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  bool v43; // zf
  __int16 *v44; // x24
  __int64 result; // x0
  __int64 v46; // x20
  __int64 v47; // x0
  __int64 *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  __int64 v61; // [xsp+38h] [xbp-18h]
  __int64 v62; // [xsp+40h] [xbp-10h] BYREF
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = *(unsigned __int16 *)(a17 + 8);
  WORD2(v62) = 0;
  LODWORD(v62) = 0;
  if ( a2 )
  {
    v26 = *a2;
    v27 = a2[1];
    v28 = a2[2];
    v29 = a2[5];
  }
  else
  {
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v29 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sessionid: %d auth_type: %d sub_type: %d add_pre_auth_context: %d sta_id: %d delete_sta: %d result_code : %d pee"
    "r_addr: %02x:%02x:%02x:**:**:%02x",
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    "lim_reject_association",
    v25,
    a5,
    (unsigned __int8)a3,
    a4,
    a6,
    a7,
    a8,
    v26,
    v27,
    v28,
    v29,
    v61,
    v62,
    v63);
  if ( a4 )
  {
    v30 = *(unsigned int *)(a1 + 11408);
    if ( (_DWORD)v30 )
    {
      v31 = *(__int64 **)(a1 + 11416);
      while ( (*(_BYTE *)(*v31 + 278) & 4) == 0 )
      {
        --v30;
        ++v31;
        if ( !v30 )
          goto LABEL_12;
      }
      *(_BYTE *)(*v31 + 278) &= ~4u;
      v32 = *v31;
      if ( *v31 )
      {
        qdf_mem_copy((void *)(v32 + 8), a2, 6u);
        v33 = *(_BYTE *)(v32 + 278);
        *(_DWORD *)(v32 + 16) = a5;
        *(_DWORD *)(v32 + 20) = 9;
        *(_BYTE *)(v32 + 278) = v33 & 0xFE;
        *(_QWORD *)(v32 + 552) = qdf_mc_timer_get_system_ticks();
        lim_add_pre_auth_node(a1, v32);
      }
    }
  }
LABEL_12:
  hash_entry = (__int16 *)dph_get_hash_entry(a1, a6, a17 + 360);
  v43 = a7 == 0;
  v44 = hash_entry;
  if ( v43 )
  {
    v48 = (__int64 *)(hash_entry + 472);
    if ( !hash_entry )
      v48 = &v62;
    lim_send_assoc_rsp_mgmt_frame(a1, 17, 1, a2, a3, hash_entry, a17, 0, v48);
    if ( a2 )
    {
      v57 = *a2;
      v58 = a2[1];
      v59 = a2[2];
      v60 = a2[5];
    }
    else
    {
      v59 = 0;
      v57 = 0;
      v58 = 0;
      v60 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received Re/Assoc req when max associated STAs reached from %02x:%02x:%02x:**:**:%02x",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "lim_reject_association",
      v57,
      v58,
      v59,
      v60);
    result = lim_send_sme_max_assoc_exceeded_ntf(a1, a2, *(unsigned __int8 *)(a17 + 10));
  }
  else if ( hash_entry )
  {
    hash_entry[17] = 8;
    lim_cleanup_rx_path(a1, hash_entry, a17, 1, v35, v36, v37, v38, v39, v40, v41, v42);
    result = lim_send_assoc_rsp_mgmt_frame(a1, a8, 0, a2, a3, v44, a17, 0, v44 + 472);
    v46 = *(_QWORD *)(*(_QWORD *)(a17 + 384) + 8LL * (unsigned __int16)v44[168]);
    if ( v46 )
    {
      v47 = *(_QWORD *)(v46 + 3272);
      if ( v47 )
      {
        _qdf_nbuf_free(v47);
        *(_QWORD *)(v46 + 3272) = 0;
        *(_QWORD *)(v46 + 3288) = 0;
        *(_DWORD *)(v46 + 3280) = 0;
        v46 = *(_QWORD *)(*(_QWORD *)(a17 + 384) + 8LL * (unsigned __int16)v44[168]);
      }
      result = _qdf_mem_free(v46);
      *(_QWORD *)(*(_QWORD *)(a17 + 384) + 8LL * (unsigned __int16)v44[168]) = 0;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: No STA context, yet rejecting Association",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "lim_reject_association");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
