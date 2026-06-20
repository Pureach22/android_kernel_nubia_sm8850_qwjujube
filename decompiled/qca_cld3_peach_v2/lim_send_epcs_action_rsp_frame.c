__int64 __fastcall lim_send_epcs_action_rsp_frame(
        __int64 a1,
        unsigned __int8 *a2,
        __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  _QWORD *v15; // x21
  unsigned __int8 *session_by_vdev_id; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w23
  int v26; // w24
  __int64 v27; // x4
  unsigned __int8 *v28; // x19
  int v29; // w8
  int v30; // w9
  int v31; // w10
  int v32; // w11
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int packed_epcs_neg_rspSize; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w23
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char *v60; // x22
  char *v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w9
  __int16 v71; // w9
  __int64 v72; // x5
  char *v73; // x22
  char *v74; // x3
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  char v84; // w20
  const char *v85; // x2
  __int64 v86; // x4
  unsigned __int8 v87; // w21
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  _QWORD *v96; // x0
  int v97; // w0
  __int16 v98; // w2
  unsigned int v99; // w19
  int v100; // [xsp+8h] [xbp-68h]
  int v101; // [xsp+10h] [xbp-60h]
  int v102; // [xsp+18h] [xbp-58h]
  __int64 v103; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v104; // [xsp+54h] [xbp-1Ch] BYREF
  char *v105; // [xsp+58h] [xbp-18h] BYREF
  __int16 v106; // [xsp+60h] [xbp-10h] BYREF
  __int16 v107; // [xsp+62h] [xbp-Eh]
  __int16 v108; // [xsp+64h] [xbp-Ch]
  __int64 v109; // [xsp+68h] [xbp-8h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v107 = 0;
  v105 = nullptr;
  v104 = 0;
  v103 = 0;
  context = _cds_get_context(53, (__int64)"lim_send_epcs_action_rsp_frame", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v15 = context;
    session_by_vdev_id = (unsigned __int8 *)pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
    if ( session_by_vdev_id )
    {
      v25 = *((_DWORD *)a3 + 1);
      v26 = *((_DWORD *)a3 + 2);
      v27 = session_by_vdev_id[30];
      v28 = session_by_vdev_id;
      v106 = *a3;
      LOBYTE(v107) = v25;
      v108 = v26;
      if ( a2 )
      {
        v29 = *a2;
        v30 = a2[1];
        v31 = a2[2];
        v32 = a2[5];
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
        "%s: Sending a EPCS negotiation Response from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_send_epcs_action_rsp_frame",
        v27,
        session_by_vdev_id[31],
        session_by_vdev_id[32],
        session_by_vdev_id[35],
        v29,
        v30,
        v31,
        v32);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Dialog token %d status %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_send_epcs_action_rsp_frame",
        (unsigned __int8)v25,
        (unsigned __int16)v26);
      packed_epcs_neg_rspSize = dot11f_get_packed_epcs_neg_rspSize(v15, &v106, &v104);
      if ( (packed_epcs_neg_rspSize & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to calculate packed size for a EPCS negotiation Response (0x%08x).",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "lim_send_epcs_action_rsp_frame",
          packed_epcs_neg_rspSize);
        v104 = 6;
      }
      else if ( packed_epcs_neg_rspSize )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: There were warnings while calculating packed size for a EPCS negotiation Response (0x%08x).",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "lim_send_epcs_action_rsp_frame");
      }
      v51 = v104;
      if ( (unsigned int)cds_packet_alloc((unsigned __int16)v104 + 24, &v105, &v103) || !v103 )
      {
        v85 = "%s: Failed to allocate %d bytes for a EPCS rsp action frm";
        v86 = v51 + 24;
      }
      else
      {
        qdf_mem_set(v105, v51 + 24, 0);
        v60 = v105;
        v61 = v105 + 4;
        *v105 = -48;
        qdf_mem_copy(v61, a2, 6u);
        v60[10] = v28[30];
        v60[11] = v28[31];
        v60[12] = v28[32];
        v60[13] = v28[33];
        v60[14] = v28[34];
        v60[15] = v28[35];
        qdf_mem_copy(v60 + 16, a2, 6u);
        v70 = *((unsigned __int16 *)v15 + 10802);
        if ( v70 <= 0xFFE )
          v71 = v70 + 1;
        else
          v71 = 2048;
        *((_WORD *)v15 + 10802) = v71;
        *((_WORD *)v60 + 11) = (16 * (v71 & 0xF)) | *((_WORD *)v60 + 11) & 0xFF0F;
        v72 = (unsigned __int8)(*((_WORD *)v15 + 10802) >> 4);
        *((_WORD *)v60 + 11) = (16 * *((_WORD *)v15 + 10802)) & 0xFF00 | (16 * (v71 & 0xF));
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "lim_populate_mac_header",
          v71 & 0xF,
          v72,
          *((unsigned __int16 *)v15 + 10802),
          0);
        v73 = v105;
        v74 = v105;
        *(_WORD *)v105 &= ~0x400u;
        v73[16] = v28[24];
        v73[17] = v28[25];
        v73[18] = v28[26];
        v73[19] = v28[27];
        v73[20] = v28[28];
        v73[21] = v28[29];
        lim_set_protected_bit(v15, v28, a2, v74);
        v75 = dot11f_pack_epcs_neg_rsp(v15, &v106, v105 + 24, v104, &v104);
        if ( (v75 & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to pack a EPCS negotiation response (0x%08x)",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "lim_send_epcs_action_rsp_frame",
            v75);
          cds_packet_free(v103);
LABEL_28:
          result = 16;
          goto LABEL_29;
        }
        if ( v75 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: There were warnings while packing EPCS rsp (0x%08x)",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "lim_send_epcs_action_rsp_frame");
        if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v28 + 71)) && (*((_DWORD *)v28 + 1759) & 0xFFFFFFFE) != 2 )
          v84 = 0;
        else
          v84 = 64;
        qdf_trace(53, 2u, *((_WORD *)v28 + 4), (unsigned __int8)*(_WORD *)v73 >> 4);
        v87 = v28[10];
        v96 = _cds_get_context(54, (__int64)"lim_send_epcs_action_rsp_frame", v88, v89, v90, v91, v92, v93, v94, v95);
        LOBYTE(v102) = 0;
        LOBYTE(v101) = v87;
        LOBYTE(v100) = v84;
        v97 = wma_tx_packet(v96, v103, v51 + 24, 3, 1, 7, lim_tx_complete, v105, 0, v100, v101, v102, 0, 12, 0, 0);
        v98 = *((_WORD *)v28 + 4);
        v99 = v97;
        qdf_trace(53, 5u, v98, v97);
        if ( !v99 )
        {
          result = 0;
          goto LABEL_29;
        }
        v85 = "%s: wma_tx_frame FAILED! Status [%d]";
        v86 = v99;
      }
      qdf_trace_msg(0x35u, 2u, v85, v52, v53, v54, v55, v56, v57, v58, v59, "lim_send_epcs_action_rsp_frame", v86);
      goto LABEL_28;
    }
  }
  result = 4;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
