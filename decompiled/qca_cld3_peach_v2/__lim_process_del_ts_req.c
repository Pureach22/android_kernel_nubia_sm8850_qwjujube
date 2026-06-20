__int64 __fastcall _lim_process_del_ts_req(
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
  __int64 v13; // x8
  __int64 v14; // x22
  int v15; // w23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _WORD *v25; // x21
  unsigned int v26; // w0
  __int64 result; // x0
  const char *v28; // x2
  unsigned int v29; // w1
  const char *v30; // x2
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x23
  __int64 v40; // x26
  unsigned int v41; // w3
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w8
  int v51; // w9
  unsigned int v52; // w8
  int v53; // w8
  char v54; // w10
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  _QWORD v71[6]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v72[2]; // [xsp+38h] [xbp-68h]
  unsigned __int8 v73[4]; // [xsp+4Ch] [xbp-54h] BYREF
  _BYTE v74[4]; // [xsp+50h] [xbp-50h] BYREF
  unsigned __int16 v75; // [xsp+54h] [xbp-4Ch] BYREF
  __int64 v76; // [xsp+58h] [xbp-48h] BYREF
  __int64 v77; // [xsp+60h] [xbp-40h]
  __int64 v78; // [xsp+68h] [xbp-38h]
  __int64 v79; // [xsp+70h] [xbp-30h]
  __int64 v80; // [xsp+78h] [xbp-28h]
  __int64 v81; // [xsp+80h] [xbp-20h]
  _QWORD v82[3]; // [xsp+88h] [xbp-18h] BYREF

  v82[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 16);
  v14 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 40);
  v81 = 0;
  memset(v82, 0, 15);
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v76 = 0;
  v75 = 0;
  v74[0] = 0;
  v73[0] = 0;
  v16 = dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, a1, (unsigned __int8 *)(v13 + 10), &v75, a3 + 360);
  if ( !v16 )
  {
    v28 = "%s: Station context not found - ignoring DelTs";
    v29 = 2;
LABEL_28:
    result = qdf_trace_msg(0x35u, v29, v28, v17, v18, v19, v20, v21, v22, v23, v24, "__lim_process_del_ts_req");
    goto LABEL_29;
  }
  v25 = (_WORD *)v16;
  v26 = sir_convert_delts_req2_struct(a1, v14, v15, (int)&v76);
  if ( v26 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: DelTs parsing failed %d",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "__lim_process_del_ts_req",
               v26);
    goto LABEL_29;
  }
  if ( (v82[1] & 0x1000000000000LL) != 0 )
  {
    if ( (*(_BYTE *)(a3 + 7024) & 2) == 0 || (*v25 & 0x40) == 0 )
    {
      v28 = "%s: Ignore delts req: wme not enabled";
      goto LABEL_27;
    }
    v30 = "%s: WME Delts received";
  }
  else if ( (*(_BYTE *)(a3 + 7024) & 1) != 0 && (*v25 & 0x80) != 0 )
  {
    v30 = "%s: 11e QoS Delts received";
  }
  else
  {
    if ( (*(_BYTE *)(a3 + 7024) & 4) == 0 || (*v25 & 0x100) == 0 )
    {
      v28 = "%s: Ignoring delts request: qos not enabled/capable";
LABEL_27:
      v29 = 3;
      goto LABEL_28;
    }
    v30 = "%s: WSM Delts received";
  }
  qdf_trace_msg(0x35u, 8u, v30, v17, v18, v19, v20, v21, v22, v23, v24, "__lim_process_del_ts_req");
  if ( (v82[1] & 0x1000000000000LL) != 0 )
    v39 = 6;
  else
    v39 = 0;
  if ( (v82[1] & 0x1000000000000LL) != 0 )
    v40 = 7;
  else
    v40 = 1;
  if ( *(_DWORD *)(a3 + 88) != 1 )
    v31 = lim_send_sme_delts_ind(a1, &v76, v75, a3);
  if ( (unsigned int)lim_admit_control_delete_ts(
                       a1,
                       v25[174],
                       (unsigned __int64)&v76 | v39,
                       v74,
                       v73,
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38) )
  {
    v28 = "%s: Unable to Delete TS";
    goto LABEL_27;
  }
  if ( (*(_WORD *)((unsigned __int64)&v76 | v40) & 0x100) == 0 )
  {
    v41 = *(unsigned __int8 *)(a3 + 8);
    v71[4] = v80;
    v71[5] = v81;
    v72[0] = v82[0];
    *(_QWORD *)((char *)v72 + 7) = *(_QWORD *)((char *)v82 + 7);
    v71[0] = v76;
    v71[1] = v77;
    v71[2] = v78;
    v71[3] = v79;
    if ( (unsigned int)lim_send_hal_msg_del_ts(a1, v73[0], v71, v41, (const void *)(a3 + 24)) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 3u,
                 "%s: DelTs with UP: %d failed ignoring request",
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 "__lim_process_del_ts_req",
                 (*(unsigned __int16 *)((unsigned __int64)&v76 | v40) >> 11) & 7);
      goto LABEL_29;
    }
  }
  lim_set_tspec_uapsd_mask_per_session(a1, a3, (unsigned __int64)&v76 | v39, 0);
  v50 = *(unsigned __int16 *)((unsigned __int64)&v76 | v40);
  v51 = (v50 >> 5) & 3;
  v52 = 0x33220110u >> ((v50 >> 9) & 0x1C);
  if ( v51 == 3 )
  {
    v53 = 1 << (v52 & 3);
    v54 = *(_BYTE *)(a3 + 7277) & ~(_BYTE)v53;
    LOBYTE(v53) = *(_BYTE *)(a3 + 7278) & ~(_BYTE)v53;
    *(_BYTE *)(a3 + 7277) = v54;
  }
  else
  {
    if ( v51 != 1 )
    {
      if ( !v51 )
        *(_BYTE *)(a3 + 7277) &= ~(1 << (v52 & 3));
      goto LABEL_40;
    }
    v53 = *(unsigned __int8 *)(a3 + 7278) & ~(1 << (v52 & 3));
  }
  *(_BYTE *)(a3 + 7278) = v53;
LABEL_40:
  lim_set_active_edca_params(a1, a3 + 7096, a3);
  if ( dph_get_hash_entry(a1, 1u, a3 + 360) )
    v63 = lim_send_edca_params(a1, a3 + 7136, *(unsigned __int8 *)(a3 + 10), 0);
  else
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Self entry missing in Hash Table",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "__lim_process_del_ts_req");
  qdf_trace_msg(0x35u, 8u, "%s: DeleteTS succeeded", v63, v64, v65, v66, v67, v68, v69, v70, "__lim_process_del_ts_req");
  result = lim_send_sme_tsm_ie_ind(a1, a3, 0, 0, 0);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
