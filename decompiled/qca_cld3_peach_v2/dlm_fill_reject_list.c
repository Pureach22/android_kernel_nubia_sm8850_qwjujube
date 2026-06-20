__int64 __fastcall dlm_fill_reject_list(_QWORD *a1, __int64 a2, _BYTE *a3, int a4, unsigned __int8 a5, __int64 *a6)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x1
  int v21; // w24
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  __int64 v26; // x27
  __int64 v27; // x25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  int v37; // w9
  __int64 v38; // x10
  int v39; // w11
  int v40; // w11
  int v41; // w8
  int v42; // w8
  int v43; // w8
  __int16 v44; // w9
  int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  int v66; // w9
  int v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // [xsp+0h] [xbp-60h]
  __int64 v77; // [xsp+0h] [xbp-60h]
  __int64 v78; // [xsp+0h] [xbp-60h]
  __int64 v79; // [xsp+8h] [xbp-58h]
  __int64 v80; // [xsp+10h] [xbp-50h]
  __int64 v81; // [xsp+18h] [xbp-48h]
  __int64 v82; // [xsp+20h] [xbp-40h]
  int v83; // [xsp+3Ch] [xbp-24h]
  _QWORD *v85; // [xsp+48h] [xbp-18h] BYREF
  __int64 v86[2]; // [xsp+50h] [xbp-10h] BYREF

  v86[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v85 = nullptr;
  v86[0] = 0;
  result = qdf_list_peek_front(a1, v86);
  v20 = (_QWORD *)v86[0];
  if ( v86[0] )
  {
    v21 = a5;
    v83 = a5;
    do
    {
      if ( (unsigned __int8)*a3 == v21 )
      {
        result = qdf_trace_msg(
                   0x6Du,
                   8u,
                   "%s: Max size reached in list, reject_ap_type %d",
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   "dlm_fill_reject_list",
                   (unsigned int)a4);
        break;
      }
      qdf_list_peek_next(a1, v20, &v85);
      v26 = v86[0];
      result = dlm_update_ap_info(v86[0], a6, 0);
      if ( !*(_BYTE *)(v26 + 136) )
      {
        if ( v26 == -16 )
        {
          v24 = 0;
          v22 = 0;
          v23 = 0;
          v25 = 0;
        }
        else
        {
          v22 = *(unsigned __int8 *)(v26 + 16);
          v23 = *(unsigned __int8 *)(v26 + 17);
          v24 = *(unsigned __int8 *)(v26 + 18);
          v25 = *(unsigned __int8 *)(v26 + 21);
        }
        qdf_trace_msg(
          0x6Du,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "dlm_fill_reject_list",
          v22,
          v23,
          v24,
          v25);
        qdf_list_remove_node((__int64)a1, (_QWORD *)v26);
        result = _qdf_mem_free(v26);
        goto LABEL_6;
      }
      if ( a4 > 2 )
      {
        switch ( a4 )
        {
          case 3:
            if ( (*(_BYTE *)(v26 + 136) & 2) != 0 )
              goto LABEL_29;
            break;
          case 4:
            if ( (*(_BYTE *)(v26 + 136) & 0x10) != 0 )
            {
LABEL_29:
              v27 = a2 + 96LL * (unsigned __int8)*a3;
              *(_DWORD *)(v27 + 68) = *(char *)(v26 + 60);
              *(_DWORD *)(v27 + 64) = dlm_get_delta_of_bssid(a4, v26, a6);
              if ( a4 == 4 )
              {
                v36 = *(_DWORD *)(v26 + 76);
                *(_DWORD *)(v27 + 76) = v36;
                v37 = *(_DWORD *)(v26 + 72);
                *(_DWORD *)(v27 + 88) = v37;
                v38 = *(_QWORD *)(v26 + 64);
                *(_QWORD *)(v27 + 80) = v38;
                v39 = *(_DWORD *)(v26 + 140);
                if ( (v39 & 8) != 0 )
                {
                  v40 = 4;
                }
                else if ( (v39 & 0x10) != 0 )
                {
                  v40 = 5;
                }
                else if ( (v39 & 0x100) != 0 )
                {
                  v40 = 9;
                }
                else if ( (v39 & 0x80) != 0 )
                {
                  v40 = 8;
                }
                else if ( (v39 & 0x200) != 0 )
                {
                  v40 = 10;
                }
                else if ( (v39 & 0x800) != 0 )
                {
                  v40 = 12;
                }
                else if ( (v39 & 0x400) != 0 )
                {
                  v40 = 11;
                }
                else if ( (v39 & 0x1000) != 0 )
                {
                  v40 = 13;
                }
                else if ( (v39 & 0x2000) != 0 )
                {
                  v40 = 16;
                }
                else if ( (v39 & 0x4000) != 0 )
                {
                  v40 = 17;
                }
                else if ( (v39 & 0x8000) != 0 )
                {
                  v40 = 15;
                }
                else
                {
                  v40 = (v39 << 14 >> 31) & 0xE;
                }
                *(_DWORD *)(v27 + 72) = v40;
                LODWORD(v81) = v40;
                LODWORD(v79) = v37;
                LODWORD(v76) = v36;
                qdf_trace_msg(
                  0x6Du,
                  8u,
                  "%s: %02x:%02x:%02x:**:**:%02x source %d original timeout %u received time %lu reject reason %d",
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  "dlm_fill_rssi_reject_params",
                  *(unsigned __int8 *)(v26 + 16),
                  *(unsigned __int8 *)(v26 + 17),
                  *(unsigned __int8 *)(v26 + 18),
                  *(unsigned __int8 *)(v26 + 21),
                  v76,
                  v79,
                  v38,
                  v81);
              }
              *(_DWORD *)(v27 + 60) = a4;
              v41 = *(_DWORD *)(v26 + 16);
              *(_WORD *)(v27 + 4) = *(_WORD *)(v26 + 20);
              *(_DWORD *)v27 = v41;
              v42 = *(_DWORD *)(v26 + 140);
              if ( (v42 & 0x800) != 0 )
              {
                v43 = 12;
              }
              else if ( (v42 & 0x1000) != 0 )
              {
                v43 = 13;
              }
              else if ( (v42 & 0x2000) != 0 )
              {
                v43 = 16;
              }
              else if ( (v42 & 0x4000) != 0 )
              {
                v43 = 17;
              }
              else if ( (v42 & 0x8000) != 0 )
              {
                v43 = 15;
              }
              else if ( (v42 & 0x10000) != 0 )
              {
                v43 = 19;
              }
              else
              {
                v43 = (v42 << 14 >> 31) & 0xE;
              }
              *(_DWORD *)(v27 + 72) = v43;
              ++*a3;
              v44 = *(_WORD *)(v26 + 26);
              *(_DWORD *)(v27 + 8) = *(_DWORD *)(v26 + 22);
              *(_WORD *)(v27 + 12) = v44;
              v45 = *(unsigned __int8 *)(v26 + 48);
              *(_BYTE *)(v27 + 56) = v45;
              qdf_mem_copy((void *)(v27 + 16), (const void *)(v26 + 28), (unsigned int)(2 * v45));
              LODWORD(v76) = *(unsigned __int8 *)(v27 + 56);
              qdf_trace_msg(
                0x6Du,
                8u,
                "%s: Added MLO AP%02x:%02x:%02x:**:**:%02x to avoid list with tried link count %d",
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                "dlm_update_reject_mlo_config",
                *(unsigned __int8 *)(v27 + 8),
                *(unsigned __int8 *)(v27 + 9),
                *(unsigned __int8 *)(v27 + 10),
                *(unsigned __int8 *)(v27 + 13),
                v76);
              if ( v26 == -16 )
              {
                v64 = 0;
                v62 = 0;
                v63 = 0;
                v65 = 0;
              }
              else
              {
                v62 = *(unsigned __int8 *)(v26 + 16);
                v63 = *(unsigned __int8 *)(v26 + 17);
                v64 = *(unsigned __int8 *)(v26 + 18);
                v65 = *(unsigned __int8 *)(v26 + 21);
              }
              LODWORD(v82) = *(_DWORD *)(v26 + 140);
              LODWORD(v81) = (unsigned __int8)*a3;
              LODWORD(v80) = *(char *)(v26 + 60);
              LODWORD(v79) = *(_DWORD *)(a2 - 32 + 96LL * (unsigned __int8)*a3);
              LODWORD(v77) = a4;
              qdf_trace_msg(
                0x6Du,
                8u,
                "%s: Adding BSSID %02x:%02x:%02x:**:**:%02x of type %d retry delay %d expected RSSI %d, entries added = %"
                "d reject reason %d",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "dlm_fill_reject_list",
                v62,
                v63,
                v64,
                v65,
                v77,
                v79,
                v80,
                v81,
                v82);
              v66 = *(_DWORD *)(v26 + 22);
              *(_WORD *)(v27 + 12) = *(_WORD *)(v26 + 26);
              *(_DWORD *)(v27 + 8) = v66;
              v67 = *(unsigned __int8 *)(v26 + 48);
              *(_BYTE *)(v27 + 56) = v67;
              qdf_mem_copy((void *)(v27 + 16), (const void *)(v26 + 28), (unsigned int)(2 * v67));
              LODWORD(v78) = *(unsigned __int8 *)(v27 + 56);
              result = qdf_trace_msg(
                         0x6Du,
                         8u,
                         "%s: Added MLO AP%02x:%02x:%02x:**:**:%02x to avoid list with tried link count %d",
                         v68,
                         v69,
                         v70,
                         v71,
                         v72,
                         v73,
                         v74,
                         v75,
                         "dlm_update_reject_mlo_config",
                         *(unsigned __int8 *)(v27 + 8),
                         *(unsigned __int8 *)(v27 + 9),
                         *(unsigned __int8 *)(v27 + 10),
                         *(unsigned __int8 *)(v27 + 13),
                         v78);
              v21 = v83;
            }
            break;
          case 5:
            if ( (*(_BYTE *)(v26 + 136) & 0x20) != 0 )
              goto LABEL_29;
            break;
          default:
LABEL_25:
            result = qdf_trace_msg(
                       0x6Du,
                       2u,
                       "%s: Wrong list type %d passed",
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       "dlm_is_bssid_of_type",
                       (unsigned int)a4);
            break;
        }
      }
      else if ( a4 )
      {
        if ( a4 == 1 )
        {
          if ( (*(_BYTE *)(v26 + 136) & 1) != 0 )
            goto LABEL_29;
        }
        else
        {
          if ( a4 != 2 )
            goto LABEL_25;
          if ( (*(_BYTE *)(v26 + 136) & 8) != 0 )
            goto LABEL_29;
        }
      }
      else if ( (*(_BYTE *)(v26 + 136) & 4) != 0 )
      {
        goto LABEL_29;
      }
LABEL_6:
      v20 = v85;
      v85 = nullptr;
      v86[0] = (__int64)v20;
    }
    while ( v20 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
