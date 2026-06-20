void __fastcall _lim_process_add_ts_rsp(
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
  __int64 v13; // x21
  __int64 v14; // x23
  unsigned int v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  unsigned int v25; // w1
  __int64 v26; // x0
  __int64 v27; // x23
  unsigned int v28; // w0
  unsigned int v29; // w8
  int v30; // w9
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x2
  __int64 v40; // x0
  __int64 v41; // x9
  __int64 v42; // x5
  __int128 v43; // kr00_16
  int v44; // w9
  unsigned int v45; // w8
  int v46; // w8
  char v47; // w10
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w9
  __int64 v65; // x4
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int8 v74; // w1
  unsigned int v75; // w3
  unsigned int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w21
  __int64 v86; // [xsp+0h] [xbp-1A0h] BYREF
  unsigned __int16 v87; // [xsp+Ch] [xbp-194h] BYREF
  _DWORD v88[2]; // [xsp+10h] [xbp-190h] BYREF
  _QWORD dest[24]; // [xsp+18h] [xbp-188h] BYREF
  __int64 src[25]; // [xsp+D8h] [xbp-C8h] BYREF

  src[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 16);
  v13 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 40);
  memset(src, 0, 188);
  v87 = 0;
  v86 = 0;
  memset(v88, 0, 6);
  qdf_trace_msg(0x35u, 3u, "%s: Recv AddTs Response", a4, a5, a6, a7, a8, a9, a10, a11, "__lim_process_add_ts_rsp");
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    v24 = "%s: AddTsRsp recvd at AP: ignoring";
LABEL_3:
    v25 = 3;
LABEL_8:
    qdf_trace_msg(0x35u, v25, v24, v16, v17, v18, v19, v20, v21, v22, v23, "__lim_process_add_ts_rsp");
    goto LABEL_9;
  }
  v26 = dph_lookup_hash_entry(v16, v17, v18, v19, v20, v21, v22, v23, a1, (unsigned __int8 *)(v14 + 10), &v87, a3 + 360);
  if ( !v26 )
  {
    v24 = "%s: Station context not found - ignoring AddTsRsp";
    v25 = 2;
    goto LABEL_8;
  }
  v27 = v26;
  v28 = sir_convert_addts_rsp2_struct(a1, v13, v15, src);
  if ( !v28 )
  {
    if ( !*(_BYTE *)(a1 + 8876) )
    {
      v24 = "%s: rx AddTsRsp but no req was ever sent-ignoring";
      goto LABEL_3;
    }
    if ( *(unsigned __int8 *)(a1 + 8713) != LOBYTE(src[0]) )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: token mismatch got: %d exp: %d - ignoring",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__lim_process_add_ts_rsp");
      goto LABEL_9;
    }
    v29 = *(unsigned __int16 *)((char *)&src[2] + 1);
    v30 = (*(unsigned __int16 *)((char *)&src[2] + 1) >> 7) & 3;
    if ( v30 == 2 )
    {
      if ( HIDWORD(src[0]) )
        goto LABEL_23;
    }
    else if ( v30 != 3 || HIDWORD(src[0]) )
    {
      goto LABEL_23;
    }
    if ( LOBYTE(src[9]) >= 2u )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Sta: %d Too many Tclas: %d 1 supported",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__lim_process_add_ts_rsp",
        v87);
      goto LABEL_9;
    }
    if ( LOBYTE(src[9]) == 1 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Response from STA: %d tsid: %d UP: %d OK!",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__lim_process_add_ts_rsp",
        v87,
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 1) & 0xF,
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 11) & 7);
      v29 = *(unsigned __int16 *)((char *)&src[2] + 1);
    }
LABEL_23:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Recv AddTsRsp: tsid: %d UP: %d status: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "__lim_process_add_ts_rsp",
      (v29 >> 1) & 0xF,
      (v29 >> 11) & 7);
    if ( (BYTE1(src[2]) & 0x60) != 0x20 )
    {
      memcpy(dest, src, 0xBCu);
      if ( (lim_is_medium_time_valid(a3, dest) & 1) == 0 )
        HIDWORD(src[0]) = 1;
    }
    lim_deactivate_and_change_timer(a1, 11);
    if ( HIDWORD(src[0]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Recv AddTsRsp: tsid: %d UP: %d status: %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__lim_process_add_ts_rsp",
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 1) & 0xF,
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 11) & 7);
      v39 = HIDWORD(src[0]);
      v40 = a1;
      dest[4] = *(__int64 *)((char *)&src[5] + 6);
      *(_OWORD *)&dest[5] = *(_OWORD *)((char *)&src[6] + 6);
      v41 = *(__int64 *)((char *)&src[1] + 6);
      LOWORD(dest[7]) = HIWORD(src[8]);
      v42 = *(unsigned __int8 *)(a3 + 10);
      v43 = *(_OWORD *)((char *)&src[2] + 6);
      goto LABEL_28;
    }
    if ( (src[23] & 0x10000) != 0 )
    {
      qdf_trace_msg(0x35u, 8u, "%s: TSM IE Present", v31, v32, v33, v34, v35, v36, v37, v38, "__lim_process_add_ts_rsp");
      *(_BYTE *)(a3 + 7044) = (*(unsigned __int16 *)((char *)&src[2] + 1) >> 11) & 7;
      qdf_mem_copy((void *)(a3 + 7046), (char *)&src[22] + 6, 4u);
      lim_send_sme_tsm_ie_ind(a1, a3, SBYTE6(src[22]), SHIBYTE(src[22]), src[23]);
    }
    lim_set_tspec_uapsd_mask_per_session(a1, a3, &src[2], (*(unsigned __int16 *)((char *)&src[2] + 1) >> 10) & 1);
    v44 = (*(unsigned __int16 *)((char *)&src[2] + 1) >> 5) & 3;
    v45 = 0x33220110u >> ((*(unsigned __int16 *)((char *)&src[2] + 1) >> 9) & 0x1C);
    if ( v44 == 3 )
    {
      v46 = 1 << (v45 & 3);
      v47 = *(_BYTE *)(a3 + 7277) | v46;
      LOBYTE(v46) = *(_BYTE *)(a3 + 7278) | v46;
      *(_BYTE *)(a3 + 7277) = v47;
    }
    else
    {
      if ( v44 != 1 )
      {
        if ( !v44 )
          *(_BYTE *)(a3 + 7277) |= 1 << (v45 & 3);
        goto LABEL_38;
      }
      v46 = *(unsigned __int8 *)(a3 + 7278) | (1 << (v45 & 3));
    }
    *(_BYTE *)(a3 + 7278) = v46;
LABEL_38:
    lim_set_active_edca_params(a1, a3 + 7096, a3);
    if ( dph_get_hash_entry(a1, 1u, a3 + 360) )
      v56 = lim_send_edca_params(a1, a3 + 7136, *(unsigned __int8 *)(a3 + 10), 0);
    else
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Self entry missing in Hash Table",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "__lim_process_add_ts_rsp");
    v64 = *(_DWORD *)(a3 + 26);
    LOWORD(v88[0]) = *(_WORD *)(a3 + 24);
    *(_DWORD *)((char *)v88 + 2) = v64;
    if ( (src[23] & 0x200000) != 0 )
    {
      v65 = *(unsigned int *)((char *)&src[21] + 6);
    }
    else
    {
      v65 = 0;
      *(_DWORD *)((char *)&src[21] + 6) = 0;
    }
    if ( (unsigned int)lim_tspec_add(
                         a1,
                         (const void *)(v27 + 338),
                         *(_WORD *)(v27 + 336),
                         (__int64 *)((char *)&src[1] + 6),
                         v56,
                         v57,
                         v58,
                         v59,
                         v60,
                         v61,
                         v62,
                         v63,
                         v65,
                         &v86) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Adding entry in lim Tspec Table failed",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "__lim_process_add_ts_rsp");
      lim_send_delts_req_action_frame(a1, v88, 1, &src[2], (char *)&src[1] + 6, a3);
      goto LABEL_46;
    }
    v74 = *(_BYTE *)(v86 + 1);
    v75 = *(unsigned __int8 *)(a3 + 8);
    *(_OWORD *)&dest[5] = *(_OWORD *)((char *)&src[6] + 6);
    LOWORD(dest[7]) = HIWORD(src[8]);
    dest[0] = *(__int64 *)((char *)&src[1] + 6);
    *(_OWORD *)&dest[1] = *(_OWORD *)((char *)&src[2] + 6);
    *(_OWORD *)&dest[3] = *(_OWORD *)((char *)&src[4] + 6);
    v76 = lim_send_hal_msg_add_ts(a1, v74, dest, v75, src[23]);
    if ( !v76 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: AddTsRsp received successfully UP: %d TSID: %d",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "__lim_process_add_ts_rsp",
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 11) & 7,
        (*(unsigned __int16 *)((char *)&src[2] + 1) >> 1) & 0xF);
      goto LABEL_46;
    }
    v85 = v76;
    lim_admit_control_delete_ts(
      a1,
      *(_WORD *)(v27 + 336),
      (__int64)&src[2],
      nullptr,
      (_BYTE *)(v86 + 1),
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84);
    lim_send_delts_req_action_frame(a1, v88, 1, &src[2], (char *)&src[1] + 6, a3);
    v42 = *(unsigned __int8 *)(a3 + 10);
    v40 = a1;
    dest[4] = *(__int64 *)((char *)&src[5] + 6);
    *(_OWORD *)&dest[5] = *(_OWORD *)((char *)&src[6] + 6);
    v41 = *(__int64 *)((char *)&src[1] + 6);
    v39 = v85;
    LOWORD(dest[7]) = HIWORD(src[8]);
    v43 = *(_OWORD *)((char *)&src[2] + 6);
LABEL_28:
    dest[0] = v41;
    *(_OWORD *)&dest[1] = v43;
    dest[3] = *(__int64 *)((char *)&src[4] + 6);
    lim_send_sme_addts_rsp(v40, 1, v39, a3, dest, v42);
LABEL_46:
    *(_BYTE *)(a1 + 8876) = 0;
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: AddTsRsp parsing failed %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "__lim_process_add_ts_rsp",
    v28);
LABEL_9:
  _ReadStatusReg(SP_EL0);
}
