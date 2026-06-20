__int64 __fastcall lim_process_tdls_del_sta_rsp(
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
  __int64 v11; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w23
  __int64 v33; // x24
  __int64 v34; // x25
  __int64 v35; // x0
  __int64 v36; // x22
  __int64 result; // x0
  char v38; // w23
  __int64 v39; // x24
  __int64 v40; // x25
  __int64 v41; // x0
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x23
  char v52; // w25
  __int64 v53; // x26
  __int64 v54; // x27
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x24
  unsigned int v65; // w0
  unsigned int v66; // w8
  __int64 v67; // x9
  __int16 v68; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v69; // [xsp+10h] [xbp-40h] BYREF
  __int64 v70; // [xsp+18h] [xbp-38h]
  __int64 (__fastcall *v71)(__int64, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-30h]
  __int64 v72; // [xsp+28h] [xbp-28h]
  __int64 v73; // [xsp+30h] [xbp-20h]
  __int64 v74; // [xsp+38h] [xbp-18h]
  unsigned int v75; // [xsp+40h] [xbp-10h] BYREF
  unsigned __int16 v76; // [xsp+44h] [xbp-Ch]
  __int64 v77; // [xsp+48h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  v68 = 0;
  v76 = 0;
  v75 = 0;
  if ( v11 )
  {
    qdf_mem_copy(&v75, (const void *)(v11 + 12), 6u);
    v23 = dph_lookup_hash_entry(
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            a1,
            (unsigned __int8 *)(v11 + 12),
            &v68,
            a3 + 360);
    if ( !v23 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: DPH Entry for STA: %X is missing release the serialization command",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_tdls_del_sta_rsp",
        1);
      v38 = *(_BYTE *)(a3 + 10);
      v39 = v76;
      v40 = v75;
      v73 = 0;
      v74 = 0;
      v71 = nullptr;
      v72 = 0;
      v69 = 0;
      v70 = 0;
      v41 = _qdf_mem_malloc(0x18u, "lim_send_sme_tdls_del_sta_rsp", 4121);
      if ( v41 )
      {
        v36 = v41;
        *(_BYTE *)v41 = v38;
        *(_DWORD *)(v41 + 4) = 0;
        *(_DWORD *)(v41 + 8) = v40;
        *(_WORD *)(v41 + 12) = (v40 | (unsigned __int64)(v39 << 32)) >> 32;
LABEL_9:
        *(_QWORD *)(v36 + 16) = *(_QWORD *)(a1 + 21624);
        v70 = v36;
        v71 = tgt_tdls_del_peer_rsp;
        v42 = scheduler_post_message_debug(
                0x35u,
                0,
                73,
                (unsigned __int16 *)&v69,
                0x1027u,
                (__int64)"lim_send_sme_tdls_del_sta_rsp");
        if ( v42 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: post msg fail, %d",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "lim_send_sme_tdls_del_sta_rsp",
            v42);
          _qdf_mem_free(v36);
        }
      }
LABEL_20:
      result = _qdf_mem_free(v11);
      *(_QWORD *)(a2 + 8) = 0;
      goto LABEL_21;
    }
    if ( *(_DWORD *)(v11 + 4) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: DEL STA failed!",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_tdls_del_sta_rsp");
      v32 = *(_BYTE *)(a3 + 10);
      v33 = v76;
      v34 = v75;
      v73 = 0;
      v74 = 0;
      v71 = nullptr;
      v72 = 0;
      v69 = 0;
      v70 = 0;
      v35 = _qdf_mem_malloc(0x18u, "lim_send_sme_tdls_del_sta_rsp", 4121);
      if ( v35 )
      {
        v36 = v35;
        *(_BYTE *)v35 = v32;
        *(_DWORD *)(v35 + 4) = 16;
        *(_DWORD *)(v35 + 8) = v34;
        *(_WORD *)(v35 + 12) = (v34 | (unsigned __int64)(v33 << 32)) >> 32;
        goto LABEL_9;
      }
      goto LABEL_20;
    }
    v51 = v23;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: DEL STA success",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_process_tdls_del_sta_rsp");
    v52 = *(_BYTE *)(a3 + 10);
    v53 = v76;
    v54 = v75;
    v73 = 0;
    v74 = 0;
    v71 = nullptr;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v55 = _qdf_mem_malloc(0x18u, "lim_send_sme_tdls_del_sta_rsp", 4121);
    if ( v55 )
    {
      *(_BYTE *)v55 = v52;
      v64 = v55;
      *(_DWORD *)(v55 + 4) = 0;
      *(_DWORD *)(v55 + 8) = v54;
      *(_WORD *)(v55 + 12) = (v54 | (unsigned __int64)(v53 << 32)) >> 32;
      *(_QWORD *)(v55 + 16) = *(_QWORD *)(a1 + 21624);
      v70 = v55;
      v71 = tgt_tdls_del_peer_rsp;
      v65 = scheduler_post_message_debug(
              0x35u,
              0,
              73,
              (unsigned __int16 *)&v69,
              0x1027u,
              (__int64)"lim_send_sme_tdls_del_sta_rsp");
      if ( v65 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: post msg fail, %d",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "lim_send_sme_tdls_del_sta_rsp",
          v65);
        _qdf_mem_free(v64);
      }
    }
    lim_release_peer_idx(v56, v57, v58, v59, v60, v61, v62, v63, a1, *(unsigned __int16 *)(v51 + 348), a3);
    v66 = *(unsigned __int16 *)(v51 + 348);
    if ( v66 >= 0x20 )
    {
      if ( v66 > 0x3F )
      {
LABEL_19:
        lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(v51 + 350), *(unsigned __int16 *)(v51 + 348), a3);
        goto LABEL_20;
      }
      v67 = 7256;
      LOBYTE(v66) = v66 - 32;
    }
    else
    {
      v67 = 7252;
    }
    *(_DWORD *)(a3 + v67) &= ~(1 << v66);
    goto LABEL_19;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: del_sta_params is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_process_tdls_del_sta_rsp");
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
