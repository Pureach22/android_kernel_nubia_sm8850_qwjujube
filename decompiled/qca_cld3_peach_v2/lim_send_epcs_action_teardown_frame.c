__int64 __fastcall lim_send_epcs_action_teardown_frame(
        __int64 a1,
        unsigned __int8 *a2,
        _WORD *a3,
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
  __int64 v26; // x4
  unsigned __int8 *v27; // x19
  int v28; // w8
  int v29; // w9
  int v30; // w10
  int v31; // w11
  __int64 result; // x0
  unsigned int packed_epcs_teardownSize; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w24
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  char *v51; // x23
  char *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w9
  __int16 v62; // w9
  __int64 v63; // x5
  char *v64; // x23
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  char v74; // w21
  const char *v75; // x2
  __int64 v76; // x4
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  _QWORD *v85; // x0
  int v86; // w0
  __int16 v87; // w2
  unsigned int v88; // w19
  int v89; // [xsp+8h] [xbp-68h]
  int v90; // [xsp+10h] [xbp-60h]
  int v91; // [xsp+18h] [xbp-58h]
  __int64 v92; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v93; // [xsp+54h] [xbp-1Ch] BYREF
  char *v94; // [xsp+58h] [xbp-18h] BYREF
  _WORD v95[2]; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v96; // [xsp+68h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v94 = nullptr;
  v93 = 0;
  v92 = 0;
  context = _cds_get_context(53, (__int64)"lim_send_epcs_action_teardown_frame", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    if ( a1 )
    {
      v15 = *(unsigned __int8 *)(a1 + 168);
      v16 = context;
      session_by_vdev_id = (unsigned __int8 *)pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
      if ( session_by_vdev_id )
      {
        v26 = session_by_vdev_id[30];
        v27 = session_by_vdev_id;
        v95[0] = *a3;
        if ( a2 )
        {
          v28 = *a2;
          v29 = a2[1];
          v30 = a2[2];
          v31 = a2[5];
        }
        else
        {
          v30 = 0;
          v28 = 0;
          v29 = 0;
          v31 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Sending a EPCS tear down from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "lim_send_epcs_action_teardown_frame",
          v26,
          session_by_vdev_id[31],
          session_by_vdev_id[32],
          session_by_vdev_id[35],
          v28,
          v29,
          v30,
          v31);
        packed_epcs_teardownSize = dot11f_get_packed_epcs_teardownSize(v16, v95, &v93);
        if ( (packed_epcs_teardownSize & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to calculate packed size for a EPCS tear down (0x%08x).",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "lim_send_epcs_action_teardown_frame",
            packed_epcs_teardownSize);
          v93 = 2;
        }
        else if ( packed_epcs_teardownSize )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: There were warnings while calculating packed size for a EPCS tear down (0x%08x).",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "lim_send_epcs_action_teardown_frame");
        }
        v42 = v93;
        if ( (unsigned int)cds_packet_alloc((unsigned __int16)v93 + 24, &v94, &v92) || !v92 )
        {
          v75 = "%s: Failed to allocate %d bytes for a EPCS req action frm";
          v76 = v42 + 24;
        }
        else
        {
          qdf_mem_set(v94, v42 + 24, 0);
          v51 = v94;
          v52 = v94 + 4;
          *v94 = -48;
          qdf_mem_copy(v52, a2, 6u);
          v51[10] = v27[30];
          v51[11] = v27[31];
          v51[12] = v27[32];
          v51[13] = v27[33];
          v51[14] = v27[34];
          v51[15] = v27[35];
          qdf_mem_copy(v51 + 16, a2, 6u);
          v61 = *((unsigned __int16 *)v16 + 10802);
          if ( v61 <= 0xFFE )
            v62 = v61 + 1;
          else
            v62 = 2048;
          *((_WORD *)v16 + 10802) = v62;
          *((_WORD *)v51 + 11) = (16 * (v62 & 0xF)) | *((_WORD *)v51 + 11) & 0xFF0F;
          v63 = (unsigned __int8)(*((_WORD *)v16 + 10802) >> 4);
          *((_WORD *)v51 + 11) = (16 * *((_WORD *)v16 + 10802)) & 0xFF00 | (16 * (v62 & 0xF));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_populate_mac_header",
            v62 & 0xF,
            v63,
            *((unsigned __int16 *)v16 + 10802),
            0);
          v64 = v94;
          v94[16] = v27[24];
          v64[17] = v27[25];
          v64[18] = v27[26];
          v64[19] = v27[27];
          v64[20] = v27[28];
          v64[21] = v27[29];
          lim_set_protected_bit(v16, v27, a2, v64);
          v65 = dot11f_pack_epcs_teardown(v16, v95, v94 + 24, v93, &v93);
          if ( (v65 & 0x10000000) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to pack a EPCS tear down (0x%08x)",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "lim_send_epcs_action_teardown_frame",
              v65);
            cds_packet_free(v92);
LABEL_31:
            result = 16;
            goto LABEL_32;
          }
          if ( v65 )
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: There were warnings while packing EPCS tear down(0x%08x)",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "lim_send_epcs_action_teardown_frame");
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v27 + 71)) && (*((_DWORD *)v27 + 1759) & 0xFFFFFFFE) != 2 )
            v74 = 0;
          else
            v74 = 64;
          qdf_trace(53, 2u, *((_WORD *)v27 + 4), (unsigned __int8)*(_WORD *)v64 >> 4);
          v85 = _cds_get_context(
                  54,
                  (__int64)"lim_send_epcs_action_teardown_frame",
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84);
          LOBYTE(v91) = 0;
          LOBYTE(v90) = v15;
          LOBYTE(v89) = v74;
          v86 = wma_tx_packet(v85, v92, v42 + 24, 3, 1, 7, lim_tx_complete, v94, 0, v89, v90, v91, 0, 12, 0, 0);
          v87 = *((_WORD *)v27 + 4);
          v88 = v86;
          qdf_trace(53, 5u, v87, v86);
          if ( !v88 )
          {
            result = 0;
            goto LABEL_32;
          }
          v75 = "%s: wma_tx_frame FAILED! Status [%d]";
          v76 = v88;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          v75,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "lim_send_epcs_action_teardown_frame",
          v76);
        goto LABEL_31;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session not found for given vdev_id %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_send_epcs_action_teardown_frame",
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
