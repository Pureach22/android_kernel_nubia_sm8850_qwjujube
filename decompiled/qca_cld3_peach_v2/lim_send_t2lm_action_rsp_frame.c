__int64 __fastcall lim_send_t2lm_action_rsp_frame(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        char a4,
        unsigned __int16 a5)
{
  char v10; // w24
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w8
  int v24; // w9
  int v25; // w10
  int v26; // w11
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int packed_t2lm_neg_rspSize; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w23
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char *v53; // x22
  char *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w9
  __int16 v64; // w9
  __int64 v65; // x5
  char *v66; // x22
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  char v76; // w20
  __int64 result; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _QWORD *context; // x0
  int v87; // w0
  __int16 v88; // w2
  unsigned int v89; // w19
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  int v98; // [xsp+8h] [xbp-68h]
  int v99; // [xsp+10h] [xbp-60h]
  int v100; // [xsp+18h] [xbp-58h]
  __int64 v101; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v102; // [xsp+54h] [xbp-1Ch] BYREF
  char *v103; // [xsp+58h] [xbp-18h] BYREF
  int v104; // [xsp+60h] [xbp-10h] BYREF
  unsigned __int16 v105; // [xsp+64h] [xbp-Ch]
  __int64 v106; // [xsp+68h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_BYTE *)(a3 + 10);
  v105 = 0;
  v104 = 0;
  v103 = nullptr;
  v102 = 0;
  v101 = 0;
  qdf_mem_set(&v104, 6u, 0);
  v19 = *(unsigned __int8 *)(a3 + 30);
  v20 = *(unsigned __int8 *)(a3 + 31);
  v21 = *(unsigned __int8 *)(a3 + 32);
  v22 = *(unsigned __int8 *)(a3 + 35);
  BYTE2(v104) = a4;
  LOWORD(v104) = 293;
  v105 = a5;
  if ( a2 )
  {
    v23 = *a2;
    v24 = a2[1];
    v25 = a2[2];
    v26 = a2[5];
  }
  else
  {
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending a T2LM negotiation Response from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "lim_send_t2lm_action_rsp_frame",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Dialog token %d status %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "lim_send_t2lm_action_rsp_frame",
    BYTE2(v104),
    v105);
  packed_t2lm_neg_rspSize = dot11f_get_packed_t2lm_neg_rspSize(a1, &v104, &v102);
  if ( (packed_t2lm_neg_rspSize & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate packed size for a T2LM negotiation Response (0x%08x).",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_send_t2lm_action_rsp_frame",
      packed_t2lm_neg_rspSize);
    v102 = 6;
  }
  else if ( packed_t2lm_neg_rspSize )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating packed size for a T2LM negotiation Response (0x%08x).",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_send_t2lm_action_rsp_frame");
  }
  v44 = v102;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v102 + 24, &v103, &v101) || !v101 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a T2LM rsp action frm",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_send_t2lm_action_rsp_frame",
      v44 + 24);
    result = 16;
  }
  else
  {
    qdf_mem_set(v103, v44 + 24, 0);
    v53 = v103;
    v54 = v103 + 4;
    *v103 = -48;
    qdf_mem_copy(v54, a2, 6u);
    v53[10] = *(_BYTE *)(a3 + 30);
    v53[11] = *(_BYTE *)(a3 + 31);
    v53[12] = *(_BYTE *)(a3 + 32);
    v53[13] = *(_BYTE *)(a3 + 33);
    v53[14] = *(_BYTE *)(a3 + 34);
    v53[15] = *(_BYTE *)(a3 + 35);
    qdf_mem_copy(v53 + 16, a2, 6u);
    v63 = *(unsigned __int16 *)(a1 + 21604);
    if ( v63 <= 0xFFE )
      v64 = v63 + 1;
    else
      v64 = 2048;
    *(_WORD *)(a1 + 21604) = v64;
    *((_WORD *)v53 + 11) = (16 * (v64 & 0xF)) | *((_WORD *)v53 + 11) & 0xFF0F;
    v65 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v53 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v64 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "lim_populate_mac_header",
      v64 & 0xF,
      v65,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v66 = v103;
    v103[16] = *(_BYTE *)(a3 + 24);
    v66[17] = *(_BYTE *)(a3 + 25);
    v66[18] = *(_BYTE *)(a3 + 26);
    v66[19] = *(_BYTE *)(a3 + 27);
    v66[20] = *(_BYTE *)(a3 + 28);
    v66[21] = *(_BYTE *)(a3 + 29);
    lim_set_protected_bit(a1, a3, a2, v66);
    v67 = dot11f_pack_t2lm_neg_rsp(a1, &v104, v103 + 24, v102, &v102);
    if ( (v67 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a T2LM negotiation response (0x%08x)",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "lim_send_t2lm_action_rsp_frame",
        v67);
      cds_packet_free(v101);
      result = 16;
    }
    else
    {
      if ( v67 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: There were warnings while packing T2LM rsp (0x%08x)",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "lim_send_t2lm_action_rsp_frame");
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284)) && (*(_DWORD *)(a3 + 7036) & 0xFFFFFFFE) != 2 )
        v76 = 0;
      else
        v76 = 64;
      qdf_trace(53, 2u, *(_WORD *)(a3 + 8), (unsigned __int8)*(_WORD *)v66 >> 4);
      context = _cds_get_context(54, (__int64)"lim_send_t2lm_action_rsp_frame", v78, v79, v80, v81, v82, v83, v84, v85);
      LOBYTE(v99) = v10;
      LOBYTE(v98) = v76;
      LOBYTE(v100) = 0;
      v87 = wma_tx_packet(
              context,
              v101,
              v44 + 24,
              3,
              1,
              7,
              lim_tx_complete,
              v103,
              lim_mgmt_t2lm_rsp_tx_complete,
              v98,
              v99,
              v100,
              (unsigned __int16)*(_DWORD *)(a3 + 284),
              12,
              0,
              0);
      v88 = *(_WORD *)(a3 + 8);
      v89 = v87;
      qdf_trace(53, 5u, v88, v87);
      if ( v89 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: wma_tx_frame FAILED! Status [%d]",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "lim_send_t2lm_action_rsp_frame",
          v89);
        result = v89;
      }
      else
      {
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
