__int64 __fastcall _lim_process_sme_assoc_cnf_new(
        __int64 a1,
        unsigned int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 session_by_bssid; // x0
  __int64 v22; // x5
  __int64 v23; // x19
  __int64 hash_entry; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x4
  __int64 v43; // x5
  const char *v44; // x2
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 result; // x0
  const char *v48; // x2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w7
  unsigned __int8 v67; // w3
  __int64 v68; // x0
  __int64 v69; // x4
  __int64 v70; // x5
  int v71; // [xsp+0h] [xbp-70h]
  int v72; // [xsp+8h] [xbp-68h]
  _BYTE v73[4]; // [xsp+1Ch] [xbp-54h] BYREF
  int v74; // [xsp+20h] [xbp-50h] BYREF
  __int16 v75; // [xsp+24h] [xbp-4Ch]
  __int64 v76; // [xsp+28h] [xbp-48h] BYREF
  __int64 v77; // [xsp+30h] [xbp-40h] BYREF
  __int64 v78; // [xsp+38h] [xbp-38h]
  __int64 v79; // [xsp+40h] [xbp-30h]
  __int64 v80; // [xsp+48h] [xbp-28h]
  __int64 v81; // [xsp+50h] [xbp-20h]
  __int64 v82; // [xsp+58h] [xbp-18h]
  __int64 v83; // [xsp+60h] [xbp-10h]
  __int64 v84; // [xsp+68h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v73[0] = 0;
  v75 = 0;
  v74 = 0;
  if ( a3 )
  {
    qdf_mem_copy(&v76, a3, 0x40u);
    if ( (v77 & 0x1000000000000LL) != 0 )
    {
      v48 = "%s: Received invalid SME_RE(ASSOC)_CNF message";
    }
    else
    {
      session_by_bssid = pe_find_session_by_bssid(a1, &v77, v73);
      if ( session_by_bssid )
      {
        v22 = *(unsigned int *)(session_by_bssid + 80);
        v23 = session_by_bssid;
        if ( *(_DWORD *)(session_by_bssid + 88) == 1 && (_DWORD)v22 == 16 )
        {
          hash_entry = dph_get_hash_entry(a1, WORD2(v78), session_by_bssid + 360);
          if ( hash_entry )
          {
            v33 = hash_entry;
            if ( (unsigned int)qdf_mem_cmp((const void *)(hash_entry + 350), (char *)&v77 + 6, 6u) )
            {
              v42 = WORD2(v78);
              v43 = BYTE6(v77);
              v44 = "%s: peerMacAddr mismatched for aid %d, peer %02x:%02x:%02x:**:**:%02x";
              v45 = HIBYTE(v77);
              v46 = (unsigned __int8)v78;
              v71 = BYTE3(v78);
            }
            else
            {
              if ( *(_DWORD *)(v33 + 8) == 15 && a2 == 5142 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Received SME_ASSOC_CNF. Delete Timer",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  "__lim_process_sme_assoc_cnf_new");
                lim_deactivate_and_change_per_sta_id_timer(a1, 8, *(unsigned __int16 *)(v33 + 348));
                if ( HIDWORD(v76) )
                {
                  if ( (*(_BYTE *)(v33 + 32) & 2) == 0 )
                    *(_BYTE *)(v33 + 32) |= 2u;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Recv Assoc Cnf, status Code : %d(assoc id=%d) Reason code: %d",
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    "__lim_process_sme_assoc_cnf_new");
                  if ( (unsigned int)v79 <= 1 )
                    v65 = 1;
                  else
                    v65 = v79;
                  v67 = (_DWORD)v79 != 53 && (_DWORD)v79 != 13;
                  lim_reject_association(
                    a1,
                    (unsigned __int8 *)(v33 + 350),
                    *(_BYTE *)(v33 + 32) & 1,
                    v67,
                    *(_DWORD *)(v33 + 12),
                    *(_WORD *)(v33 + 348),
                    1u,
                    v65,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v23);
                }
                else
                {
                  v69 = *(unsigned __int16 *)(v33 + 348);
                  *(_DWORD *)(v33 + 8) = 14;
                  *(_QWORD *)(v33 + 40) = v80;
                  *(_DWORD *)(v33 + 48) = v81;
                  *(_QWORD *)(v33 + 56) = v82;
                  v70 = BYTE4(v83);
                  *(_DWORD *)(v33 + 64) = v83;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: sending Assoc Rsp frame to STA assoc id=%d, tx cb %d",
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    "__lim_process_sme_assoc_cnf_new",
                    v69,
                    v70);
                  lim_send_assoc_rsp_mgmt_frame(
                    a1,
                    0,
                    *(unsigned __int16 *)(v33 + 348),
                    v33 + 350,
                    *(_BYTE *)(v33 + 32) & 1,
                    v33,
                    v23,
                    BYTE4(v83),
                    v33 + 1080);
                  *(_QWORD *)(v33 + 40) = 0;
                  *(_DWORD *)(v33 + 48) = 0;
                  *(_QWORD *)(v33 + 56) = 0;
                  *(_DWORD *)(v33 + 64) = 0;
                }
                goto LABEL_34;
              }
              v42 = BYTE6(v77);
              v43 = HIBYTE(v77);
              v44 = "%s: peer %02x:%02x:%02x:**:**:%02x not in WT_ASSOC_CNF_STATE, for aid %d, sta mlmstate %d";
              v45 = (unsigned __int8)v78;
              v46 = BYTE3(v78);
              v72 = *(_DWORD *)(v33 + 8);
              v71 = WORD2(v78);
            }
            qdf_trace_msg(
              0x35u,
              8u,
              v44,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "__lim_process_sme_assoc_cnf_new",
              v42,
              v43,
              v45,
              v46,
              v71,
              v72);
LABEL_34:
            v68 = *(_QWORD *)(*(_QWORD *)(v23 + 384) + 8LL * *(unsigned __int16 *)(v33 + 348));
            if ( v68 && (v83 & 0x100000000LL) == 0 )
            {
              lim_free_assoc_req_frm_buf(v68);
              _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v23 + 384) + 8LL * *(unsigned __int16 *)(v33 + 348)));
              *(_QWORD *)(*(_QWORD *)(v23 + 384) + 8LL * *(unsigned __int16 *)(v33 + 348)) = 0;
            }
            goto LABEL_13;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Rcvd invalid msg %X due to no STA ctx, aid %d, peer %02x:%02x:%02x:**:**:%02x",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "__lim_process_sme_assoc_cnf_new",
            a2,
            WORD2(v78),
            BYTE6(v77),
            HIBYTE(v77),
            (unsigned __int8)v78,
            BYTE3(v78));
          lim_send_sme_disassoc_ntf(a1, (char *)&v77 + 6, &v74, 520);
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Rcvd unexpected msg %X in state %X, in role %X",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "__lim_process_sme_assoc_cnf_new",
            a2,
            v22);
        }
LABEL_13:
        _qdf_mem_free(v80);
        result = _qdf_mem_free(v82);
        goto LABEL_14;
      }
      v48 = "%s: session does not exist for given bssId";
    }
    qdf_trace_msg(0x35u, 2u, v48, v13, v14, v15, v16, v17, v18, v19, v20, "__lim_process_sme_assoc_cnf_new");
    goto LABEL_13;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: msg_buf is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "__lim_process_sme_assoc_cnf_new");
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
