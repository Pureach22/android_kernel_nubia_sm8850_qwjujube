__int64 __fastcall lim_process_ap_mlm_del_sta_rsp(
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
  unsigned __int16 *v11; // x23
  __int64 hash_entry; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int16 v59; // w1
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w24
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // [xsp+0h] [xbp-20h]
  _QWORD v79[2]; // [xsp+10h] [xbp-10h] BYREF

  v79[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 **)(a2 + 8);
  if ( !v11 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg->bodyptr NULL",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_ap_mlm_del_sta_rsp");
    goto LABEL_18;
  }
  hash_entry = dph_get_hash_entry(a1, *v11, a3 + 360);
  if ( !hash_entry )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: DPH Entry for STA %X missing",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_process_ap_mlm_del_sta_rsp",
      *v11);
    result = _qdf_mem_free((__int64)v11);
    *(_QWORD *)(a2 + 8) = 0;
    goto LABEL_18;
  }
  v24 = hash_entry;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received del Sta Rsp in StaD MlmState: %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_process_ap_mlm_del_sta_rsp",
    *(unsigned int *)(hash_entry + 8));
  if ( *((_DWORD *)v11 + 1) )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: DEL STA failed!",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_process_ap_mlm_del_sta_rsp");
LABEL_15:
    v69 = 506;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: AP received the DEL_STA_RSP for assocID: %X sta mac %02x:%02x:%02x:**:**:%02x",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "lim_process_ap_mlm_del_sta_rsp",
    *v11,
    *(unsigned __int8 *)(v24 + 350),
    *(unsigned __int8 *)(v24 + 351),
    *(unsigned __int8 *)(v24 + 352),
    *(unsigned __int8 *)(v24 + 355));
  v42 = *(unsigned int *)(v24 + 8);
  if ( (v42 & 0xFFFFFFFE) != 0x16 )
  {
    v60 = lim_mlm_state_str(v42);
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received unexpected WMA_DEL_STA_RSP in state %s for assocId %d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "lim_process_ap_mlm_del_sta_rsp",
      v60,
      *(unsigned __int16 *)(v24 + 348));
    goto LABEL_15;
  }
  LODWORD(v78) = *(unsigned __int8 *)(v24 + 355);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Deleted STA AssocID %d Addr %02x:%02x:%02x:**:**:%02x",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "lim_process_ap_mlm_del_sta_rsp",
    *(unsigned __int16 *)(v24 + 348),
    *(unsigned __int8 *)(v24 + 350),
    *(unsigned __int8 *)(v24 + 351),
    *(unsigned __int8 *)(v24 + 352),
    v78);
  if ( *(_DWORD *)(v24 + 8) != 23 )
  {
    v69 = 0;
LABEL_16:
    result = _qdf_mem_free((__int64)v11);
    *(_QWORD *)(a2 + 8) = 0;
    if ( *(_DWORD *)(v24 + 8) != 23 )
      result = lim_prepare_and_send_del_sta_cnf(a1, v24, v69, a3, v70, v71, v72, v73, v74, v75, v76, v77);
    goto LABEL_18;
  }
  _qdf_mem_free((__int64)v11);
  *(_QWORD *)(a2 + 8) = 0;
  result = lim_add_sta(a1, (unsigned __int16 *)v24, 0, a3);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not Add STA with assocId: %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "lim_process_ap_mlm_del_sta_rsp",
      *(unsigned __int16 *)(v24 + 348));
    if ( *(_BYTE *)(v24 + 72) )
    {
      v59 = *(_WORD *)(v24 + 348);
      v79[0] = 0;
      if ( !(unsigned int)lim_tspec_find_by_assoc_id(
                            v51,
                            v52,
                            v53,
                            v54,
                            v55,
                            v56,
                            v57,
                            v58,
                            a1,
                            v59,
                            v24 + 74,
                            a1 + 8920,
                            v79) )
        lim_admit_control_delete_ts(
          a1,
          *(_WORD *)(v24 + 348),
          v24 + 76,
          nullptr,
          (_BYTE *)(v79[0] + 1LL),
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58);
    }
    result = lim_reject_association(
               a1,
               (unsigned __int8 *)(v24 + 350),
               *(_BYTE *)(v24 + 32) & 1,
               1u,
               *(_DWORD *)(v24 + 12),
               *(_WORD *)(v24 + 348),
               1u,
               1u,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               a3);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
