__int64 __fastcall lim_send_epcs_action_req_frame(
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
  unsigned int v15; // w20
  _QWORD *v16; // x22
  unsigned __int8 *session_by_vdev_id; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  unsigned __int8 *v27; // x19
  __int64 v28; // x5
  int v29; // w10
  int v30; // w11
  int v31; // w12
  int v32; // w13
  __int64 result; // x0
  unsigned int packed_epcs_neg_reqSize; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w24
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  char *v52; // x23
  char *v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w9
  __int16 v63; // w9
  __int64 v64; // x5
  char *v65; // x23
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w21
  const char *v76; // x2
  __int64 v77; // x4
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _QWORD *v86; // x0
  int v87; // w0
  __int16 v88; // w2
  unsigned int v89; // w19
  int v90; // [xsp+8h] [xbp-68h]
  int v91; // [xsp+10h] [xbp-60h]
  int v92; // [xsp+18h] [xbp-58h]
  int v93; // [xsp+20h] [xbp-50h]
  __int64 v94; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v95; // [xsp+54h] [xbp-1Ch] BYREF
  char *v96; // [xsp+58h] [xbp-18h] BYREF
  __int16 v97; // [xsp+64h] [xbp-Ch] BYREF
  char v98; // [xsp+66h] [xbp-Ah]
  __int64 v99; // [xsp+68h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = nullptr;
  v95 = 0;
  v94 = 0;
  context = _cds_get_context(53, (__int64)"lim_send_epcs_action_req_frame", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    if ( a1 )
    {
      v15 = *(unsigned __int8 *)(a1 + 168);
      v16 = context;
      session_by_vdev_id = (unsigned __int8 *)pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
      if ( session_by_vdev_id )
      {
        v26 = *((_DWORD *)a3 + 1);
        v27 = session_by_vdev_id;
        v28 = session_by_vdev_id[30];
        v97 = *a3;
        v98 = v26;
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
          "%s: Sending a EPCS negotiation Request token %d from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "lim_send_epcs_action_req_frame",
          (unsigned __int8)v26,
          v28,
          session_by_vdev_id[31],
          session_by_vdev_id[32],
          session_by_vdev_id[35],
          v29,
          v30,
          v31,
          v32);
        packed_epcs_neg_reqSize = dot11f_get_packed_epcs_neg_reqSize(v16, &v97, &v95);
        if ( (packed_epcs_neg_reqSize & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to calculate packed size for a EPCS negotiation Request (0x%08x).",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "lim_send_epcs_action_req_frame",
            packed_epcs_neg_reqSize);
          v95 = 3;
        }
        else if ( packed_epcs_neg_reqSize )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: There were warnings while calculating packed size for a EPCS negotiation Request (0x%08x).",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "lim_send_epcs_action_req_frame");
        }
        v43 = v95;
        if ( (unsigned int)cds_packet_alloc((unsigned __int16)v95 + 24, &v96, &v94) || !v94 )
        {
          v76 = "%s: Failed to allocate %d bytes for a EPCS req action frm";
          v77 = v43 + 24;
        }
        else
        {
          qdf_mem_set(v96, v43 + 24, 0);
          v52 = v96;
          v53 = v96 + 4;
          *v96 = -48;
          qdf_mem_copy(v53, a2, 6u);
          v52[10] = v27[30];
          v52[11] = v27[31];
          v52[12] = v27[32];
          v52[13] = v27[33];
          v52[14] = v27[34];
          v52[15] = v27[35];
          qdf_mem_copy(v52 + 16, a2, 6u);
          v62 = *((unsigned __int16 *)v16 + 10802);
          if ( v62 <= 0xFFE )
            v63 = v62 + 1;
          else
            v63 = 2048;
          *((_WORD *)v16 + 10802) = v63;
          *((_WORD *)v52 + 11) = (16 * (v63 & 0xF)) | *((_WORD *)v52 + 11) & 0xFF0F;
          v64 = (unsigned __int8)(*((_WORD *)v16 + 10802) >> 4);
          *((_WORD *)v52 + 11) = (16 * *((_WORD *)v16 + 10802)) & 0xFF00 | (16 * (v63 & 0xF));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "lim_populate_mac_header",
            v63 & 0xF,
            v64,
            *((unsigned __int16 *)v16 + 10802),
            0);
          v65 = v96;
          v96[16] = v27[24];
          v65[17] = v27[25];
          v65[18] = v27[26];
          v65[19] = v27[27];
          v65[20] = v27[28];
          v65[21] = v27[29];
          lim_set_protected_bit(v16, v27, a2, v65);
          v66 = dot11f_pack_epcs_neg_req(v16, &v97, v96 + 24, v95, &v95);
          if ( (v66 & 0x10000000) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to pack a EPCS negotiation request (0x%08x)",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "lim_send_epcs_action_req_frame",
              v66);
            cds_packet_free(v94);
LABEL_31:
            result = 16;
            goto LABEL_32;
          }
          if ( v66 )
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: There were warnings while packing EPCS req (0x%08x)",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "lim_send_epcs_action_req_frame");
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v27 + 71)) && (*((_DWORD *)v27 + 1759) & 0xFFFFFFFE) != 2 )
            v75 = 0;
          else
            v75 = 64;
          qdf_trace(53, 2u, *((_WORD *)v27 + 4), (unsigned __int8)*(_WORD *)v65 >> 4);
          v86 = _cds_get_context(54, (__int64)"lim_send_epcs_action_req_frame", v78, v79, v80, v81, v82, v83, v84, v85);
          LOWORD(v93) = 0;
          LOBYTE(v92) = 0;
          LOBYTE(v91) = v15;
          LOBYTE(v90) = v75;
          v87 = wma_tx_packet(v86, v94, v43 + 24, 3, 1, 7, lim_tx_complete, v96, 0, v90, v91, v92, v93, 12, 0, 0);
          v88 = *((_WORD *)v27 + 4);
          v89 = v87;
          qdf_trace(53, 5u, v88, v87);
          if ( !v89 )
          {
            result = 0;
            goto LABEL_32;
          }
          v76 = "%s: wma_tx_frame FAILED! Status [%d]";
          v77 = v89;
        }
        qdf_trace_msg(0x35u, 2u, v76, v44, v45, v46, v47, v48, v49, v50, v51, "lim_send_epcs_action_req_frame", v77);
        goto LABEL_31;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: session not found for given vdev_id %d ",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_send_epcs_action_req_frame",
        v15);
      result = 4;
    }
    else
    {
      result = 29;
    }
  }
  else
  {
    result = 4;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
