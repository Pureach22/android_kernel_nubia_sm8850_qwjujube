__int64 __fastcall _lim_process_sme_set_ht2040_mode(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 session_by_bssid; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  int v30; // w8
  const char *v31; // x2
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int16 i; // w21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x27
  unsigned int *v51; // x25
  __int16 v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _QWORD v61[2]; // [xsp+0h] [xbp-40h] BYREF
  _BYTE v62[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: received Set HT 20/40 mode message",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "__lim_process_sme_set_ht2040_mode",
    0,
    0,
    0,
    0,
    0,
    0);
  if ( !a2 )
  {
    v31 = "%s: Buffer is Pointing to NULL";
LABEL_13:
    result = qdf_trace_msg(0x35u, 2u, v31, v12, v13, v14, v15, v16, v17, v18, v19, "__lim_process_sme_set_ht2040_mode");
    goto LABEL_14;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, a2 + 6, v62);
  if ( !session_by_bssid )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Session does not exist for given BSSID: %02x:%02x:%02x:**:**:%02x",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "__lim_process_sme_set_ht2040_mode",
               a2[6],
               a2[7],
               a2[8],
               a2[11]);
    goto LABEL_14;
  }
  v29 = session_by_bssid;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Update session entry for cbMod=%d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "__lim_process_sme_set_ht2040_mode",
    a2[4]);
  v30 = a2[4];
  if ( v30 == 3 )
  {
    *(_DWORD *)(v29 + 164) = 3;
    *(_BYTE *)(v29 + 161) = 1;
    goto LABEL_16;
  }
  if ( v30 == 1 )
  {
    *(_DWORD *)(v29 + 164) = 1;
    *(_BYTE *)(v29 + 161) = 1;
    goto LABEL_16;
  }
  if ( a2[4] )
  {
    v31 = "%s: Invalid cbMode";
    goto LABEL_13;
  }
  *(_DWORD *)(v29 + 164) = 0;
  *(_BYTE *)(v29 + 161) = 0;
  *(_BYTE *)(v29 + 160) = a2[5] == 1;
LABEL_16:
  sch_set_fixed_beacon_fields(a1, v29);
  result = lim_send_beacon_ind(a1, v29, 3u, v33, v34, v35, v36, v37, v38, v39, v40);
  if ( *(_WORD *)(v29 + 376) )
  {
    for ( i = 0; *(unsigned __int16 *)(v29 + 376) > (unsigned int)i; ++i )
    {
      result = dph_get_hash_entry(a1, i, v29 + 360);
      if ( result )
      {
        if ( (*(_WORD *)result & 1) != 0 && (*(_BYTE *)(result + 346) & 8) != 0 )
        {
          v50 = result;
          result = _qdf_mem_malloc(0xCu, "__lim_process_sme_set_ht2040_mode", 9089);
          if ( !result )
            break;
          v51 = (unsigned int *)result;
          *(_DWORD *)result = *(_DWORD *)(v29 + 164) != 0;
          qdf_mem_copy((void *)(result + 6), (const void *)(v50 + 350), 6u);
          v52 = *(unsigned __int8 *)(v29 + 10);
          LODWORD(v61[0]) = 4263;
          *((_WORD *)v51 + 2) = v52;
          v61[1] = v51;
          if ( (unsigned int)scheduler_post_message_debug(
                               0x35u,
                               0x36u,
                               54,
                               (unsigned __int16 *)v61,
                               0x2397u,
                               (__int64)"__lim_process_sme_set_ht2040_mode") )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Not able to post WMA_UPDATE_OP_MODE message to WMA",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "__lim_process_sme_set_ht2040_mode");
            result = _qdf_mem_free((__int64)v51);
            break;
          }
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: Notified FW about OP mode chwidth: %d",
                     v53,
                     v54,
                     v55,
                     v56,
                     v57,
                     v58,
                     v59,
                     v60,
                     "__lim_process_sme_set_ht2040_mode",
                     *v51);
        }
        else
        {
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: station does not support HT40",
                     v42,
                     v43,
                     v44,
                     v45,
                     v46,
                     v47,
                     v48,
                     v49,
                     "__lim_process_sme_set_ht2040_mode");
        }
      }
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
