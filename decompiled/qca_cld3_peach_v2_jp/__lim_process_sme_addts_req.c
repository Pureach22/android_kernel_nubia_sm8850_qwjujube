__int64 __fastcall _lim_process_sme_addts_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w20
  __int64 session_by_bssid; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 hash_entry; // x0
  char v40; // w8
  __int16 v41; // w9
  const char *v42; // x2
  unsigned int v43; // w1
  __int64 result; // x0
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x1
  __int64 v48; // x0
  __int16 v49; // w8
  __int64 v50; // x9
  __int64 v51; // x3
  __int64 v52; // x9
  __int64 v53; // x10
  __int64 v54; // x8
  __int64 v55; // x10
  __int64 v56; // x8
  char v57; // w9
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w8
  __int64 v67; // x1
  _QWORD v68[4]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v69; // [xsp+20h] [xbp-30h]
  __int64 v70; // [xsp+28h] [xbp-28h]
  __int64 v71; // [xsp+30h] [xbp-20h]
  __int16 v72; // [xsp+38h] [xbp-18h]
  char v73[4]; // [xsp+3Ch] [xbp-14h] BYREF
  int v74; // [xsp+40h] [xbp-10h] BYREF
  __int16 v75; // [xsp+44h] [xbp-Ch]
  __int64 v76; // [xsp+48h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v74 = 0;
  v73[0] = 0;
  if ( a2 )
  {
    v11 = *(unsigned __int8 *)(a2 + 4);
    session_by_bssid = pe_find_session_by_bssid(a1, a2 + 5, v73);
    if ( !session_by_bssid )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session Does not exist for given bssId",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "__lim_process_sme_addts_req");
      v45 = *(_QWORD *)(a2 + 58);
      v46 = *(_QWORD *)(a2 + 66);
      v47 = *(unsigned __int8 *)(a2 + 16);
      v48 = a1;
      v69 = *(_QWORD *)(a2 + 50);
      v70 = v45;
      v49 = *(_WORD *)(a2 + 74);
      v50 = *(_QWORD *)(a2 + 18);
      v71 = v46;
      v51 = 0;
LABEL_20:
      v72 = v49;
      v54 = *(_QWORD *)(a2 + 26);
      v55 = *(_QWORD *)(a2 + 34);
      v68[0] = v50;
      v68[1] = v54;
      v56 = *(_QWORD *)(a2 + 42);
      v68[2] = v55;
      v68[3] = v56;
      result = lim_send_sme_addts_rsp(v48, v47, 16, v51, v68, v11);
      goto LABEL_21;
    }
    v22 = session_by_bssid;
    lim_diag_event_report(a1, 29, session_by_bssid, 0);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received SME_ADDTS_REQ (TSid %d, UP %d)",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "__lim_process_sme_addts_req",
      (*(unsigned __int16 *)(a2 + 21) >> 1) & 0xF,
      (*(unsigned __int16 *)(a2 + 21) >> 11) & 7);
    if ( *(_DWORD *)(v22 + 88) == 2 )
    {
      hash_entry = dph_get_hash_entry(a1, 1u, v22 + 360);
      if ( hash_entry )
      {
        if ( (*(_WORD *)hash_entry & 1) != 0 && *(_DWORD *)(hash_entry + 8) == 14 )
        {
          v40 = *(_BYTE *)(a2 + 179) & 0xF1;
          *(_BYTE *)(a2 + 179) = v40;
          v41 = *(_WORD *)hash_entry;
          if ( (*(_WORD *)hash_entry & 0x100) != 0 && (*(_WORD *)(a2 + 21) & 0x180) != 0x80 )
          {
            v57 = 4;
          }
          else if ( (v41 & 0x40) != 0 )
          {
            v57 = 2;
          }
          else
          {
            if ( (v41 & 0x80) == 0 )
            {
              v42 = "%s: ADDTS_REQ ignore - qos is disabled";
              v43 = 3;
LABEL_18:
              qdf_trace_msg(0x35u, v43, v42, v31, v32, v33, v34, v35, v36, v37, v38, "__lim_process_sme_addts_req");
LABEL_19:
              v52 = *(_QWORD *)(a2 + 58);
              v53 = *(_QWORD *)(a2 + 66);
              v47 = *(unsigned __int8 *)(a2 + 16);
              v48 = a1;
              v69 = *(_QWORD *)(a2 + 50);
              v70 = v52;
              v49 = *(_WORD *)(a2 + 74);
              v50 = *(_QWORD *)(a2 + 18);
              v71 = v53;
              v51 = v22;
              goto LABEL_20;
            }
            v57 = 8;
          }
          *(_BYTE *)(a2 + 179) = v40 | v57;
          if ( (*(_DWORD *)(v22 + 80) | 2) != 0xA )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: AddTs received in invalid LIMsme state (%d)",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "__lim_process_sme_addts_req");
            goto LABEL_19;
          }
          if ( *(_BYTE *)(a1 + 8876) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Addts (token %d, tsid %d, up %d) is still pending",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "__lim_process_sme_addts_req",
              *(unsigned __int8 *)(a1 + 8713),
              (*(unsigned __int16 *)(a1 + 8717) >> 1) & 0xF,
              (*(unsigned __int16 *)(a1 + 8717) >> 11) & 7);
            goto LABEL_19;
          }
          v74 = *(_DWORD *)(v22 + 24);
          v75 = *(_WORD *)(v22 + 28);
          *(_BYTE *)(a1 + 8876) = 1;
          qdf_mem_copy((void *)(a1 + 8696), (const void *)a2, 0xB4u);
          ((void (__fastcall *)(__int64, int *, __int64, __int64))lim_send_addts_req_action_frame)(
            a1,
            &v74,
            a2 + 17,
            v22);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Sent ADDTS request",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "__lim_process_sme_addts_req");
          v66 = *(_DWORD *)(a2 + 12);
          if ( !v66 )
            v66 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3504LL);
          if ( (unsigned int)tx_timer_change(a1 + 1344, v66 / 0xAuLL, 0)
            || (v67 = (unsigned __int8)(*(_BYTE *)(a1 + 8877) + 1),
                ++*(_BYTE *)(a1 + 8877),
                (unsigned int)tx_timer_change_context(a1 + 1344, v67)) )
          {
            v42 = "%s: AddtsRsp timer change failed!";
          }
          else
          {
            qdf_trace(53, 0xDu, *(_WORD *)(v22 + 8), 11);
            *(_BYTE *)(a1 + 1394) = v73[0];
            result = tx_timer_activate((char *)(a1 + 1344));
            if ( !(_DWORD)result )
              goto LABEL_21;
            v42 = "%s: AddtsRsp timer activation failed!";
          }
        }
        else
        {
          v42 = "%s: AddTs received in invalid MLM state";
        }
      }
      else
      {
        v42 = "%s: Cannot find AP context for addts req";
      }
    }
    else
    {
      v42 = "%s: AddTs received on AP - ignoring";
    }
    v43 = 2;
    goto LABEL_18;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: Buffer is Pointing to NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__lim_process_sme_addts_req");
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
