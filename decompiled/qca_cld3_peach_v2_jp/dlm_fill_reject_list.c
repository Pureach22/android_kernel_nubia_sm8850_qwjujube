__int64 __fastcall dlm_fill_reject_list(
        _QWORD *a1,
        __int64 a2,
        unsigned __int8 *a3,
        int a4,
        unsigned __int8 a5,
        __int64 *a6)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x1
  int v22; // w27
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x26
  __int64 v28; // x24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  int v38; // w9
  __int64 v39; // x10
  int v40; // w11
  int v41; // w11
  int v42; // w9
  int v43; // w9
  int v44; // w9
  unsigned __int8 v45; // w9
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  __int64 v50; // [xsp+0h] [xbp-40h]
  __int64 v51; // [xsp+8h] [xbp-38h]
  __int64 v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+18h] [xbp-28h]
  __int64 v54; // [xsp+20h] [xbp-20h]
  _QWORD *v55; // [xsp+28h] [xbp-18h] BYREF
  __int64 v56[2]; // [xsp+30h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = nullptr;
  v56[0] = 0;
  result = qdf_list_peek_front(a1, v56);
  v21 = (_QWORD *)v56[0];
  if ( v56[0] )
  {
    v22 = a5;
    do
    {
      if ( *a3 == v22 )
      {
        result = qdf_trace_msg(
                   0x6Du,
                   8u,
                   "%s: Max size reached in list, reject_ap_type %d",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "dlm_fill_reject_list",
                   (unsigned int)a4);
        break;
      }
      qdf_list_peek_next(a1, v21, &v55);
      v27 = v56[0];
      result = dlm_update_ap_info(v56[0], a6, 0);
      if ( !*(_BYTE *)(v27 + 104) )
      {
        if ( v27 == -16 )
        {
          v25 = 0;
          v23 = 0;
          v24 = 0;
          v26 = 0;
        }
        else
        {
          v23 = *(unsigned __int8 *)(v27 + 16);
          v24 = *(unsigned __int8 *)(v27 + 17);
          v25 = *(unsigned __int8 *)(v27 + 18);
          v26 = *(unsigned __int8 *)(v27 + 21);
        }
        qdf_trace_msg(
          0x6Du,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x cleared from list",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "dlm_fill_reject_list",
          v23,
          v24,
          v25,
          v26);
        qdf_list_remove_node((__int64)a1, (_QWORD *)v27);
        result = _qdf_mem_free(v27);
        goto LABEL_6;
      }
      if ( a4 > 2 )
      {
        switch ( a4 )
        {
          case 3:
            if ( (*(_BYTE *)(v27 + 104) & 2) != 0 )
              goto LABEL_29;
            break;
          case 4:
            if ( (*(_BYTE *)(v27 + 104) & 0x10) != 0 )
            {
LABEL_29:
              v28 = a2 + 48LL * *a3;
              *(_DWORD *)(v28 + 16) = *(char *)(v27 + 28);
              *(_DWORD *)(v28 + 12) = dlm_get_delta_of_bssid(a4, v27, a6);
              if ( a4 == 4 )
              {
                v37 = *(_DWORD *)(v27 + 44);
                *(_DWORD *)(v28 + 24) = v37;
                v38 = *(_DWORD *)(v27 + 40);
                *(_DWORD *)(v28 + 40) = v38;
                v39 = *(_QWORD *)(v27 + 32);
                *(_QWORD *)(v28 + 32) = v39;
                v40 = *(_DWORD *)(v27 + 108);
                if ( (v40 & 8) != 0 )
                {
                  v41 = 4;
                }
                else if ( (v40 & 0x10) != 0 )
                {
                  v41 = 5;
                }
                else if ( (v40 & 0x100) != 0 )
                {
                  v41 = 9;
                }
                else if ( (v40 & 0x80) != 0 )
                {
                  v41 = 8;
                }
                else if ( (v40 & 0x200) != 0 )
                {
                  v41 = 10;
                }
                else if ( (v40 & 0x800) != 0 )
                {
                  v41 = 12;
                }
                else if ( (v40 & 0x400) != 0 )
                {
                  v41 = 11;
                }
                else if ( (v40 & 0x1000) != 0 )
                {
                  v41 = 13;
                }
                else if ( (v40 & 0x2000) != 0 )
                {
                  v41 = 16;
                }
                else if ( (v40 & 0x4000) != 0 )
                {
                  v41 = 17;
                }
                else if ( (v40 & 0x8000) != 0 )
                {
                  v41 = 15;
                }
                else
                {
                  v41 = (v40 << 14 >> 31) & 0xE;
                }
                *(_DWORD *)(v28 + 20) = v41;
                LODWORD(v53) = v41;
                LODWORD(v51) = v38;
                LODWORD(v50) = v37;
                qdf_trace_msg(
                  0x6Du,
                  8u,
                  "%s: %02x:%02x:%02x:**:**:%02x source %d original timeout %u received time %lu reject reason %d",
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  "dlm_fill_rssi_reject_params",
                  *(unsigned __int8 *)(v27 + 16),
                  *(unsigned __int8 *)(v27 + 17),
                  *(unsigned __int8 *)(v27 + 18),
                  *(unsigned __int8 *)(v27 + 21),
                  v50,
                  v51,
                  v39,
                  v53);
              }
              *(_DWORD *)(v28 + 8) = a4;
              v42 = *(_DWORD *)(v27 + 16);
              *(_WORD *)(v28 + 4) = *(_WORD *)(v27 + 20);
              *(_DWORD *)v28 = v42;
              v43 = *(_DWORD *)(v27 + 108);
              if ( (v43 & 0x800) != 0 )
              {
                v44 = 12;
              }
              else if ( (v43 & 0x1000) != 0 )
              {
                v44 = 13;
              }
              else if ( (v43 & 0x2000) != 0 )
              {
                v44 = 16;
              }
              else if ( (v43 & 0x4000) != 0 )
              {
                v44 = 17;
              }
              else if ( (v43 & 0x8000) != 0 )
              {
                v44 = 15;
              }
              else if ( (v43 & 0x10000) != 0 )
              {
                v44 = 19;
              }
              else
              {
                v44 = (v43 << 14 >> 31) & 0xE;
              }
              *(_DWORD *)(v28 + 20) = v44;
              v45 = *a3 + 1;
              *a3 = v45;
              if ( v27 == -16 )
              {
                v48 = 0;
                v46 = 0;
                v47 = 0;
                v49 = 0;
              }
              else
              {
                v46 = *(unsigned __int8 *)(v27 + 16);
                v47 = *(unsigned __int8 *)(v27 + 17);
                v48 = *(unsigned __int8 *)(v27 + 18);
                v49 = *(unsigned __int8 *)(v27 + 21);
              }
              LODWORD(v54) = *(_DWORD *)(v27 + 108);
              LODWORD(v53) = v45;
              LODWORD(v52) = *(char *)(v27 + 28);
              LODWORD(v51) = *(_DWORD *)(a2 - 36 + 48LL * v45);
              LODWORD(v50) = a4;
              result = qdf_trace_msg(
                         0x6Du,
                         8u,
                         "%s: Adding BSSID %02x:%02x:%02x:**:**:%02x of type %d retry delay %d expected RSSI %d, entries "
                         "added = %d reject reason %d",
                         v29,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         "dlm_fill_reject_list",
                         v46,
                         v47,
                         v48,
                         v49,
                         v50,
                         v51,
                         v52,
                         v53,
                         v54);
            }
            break;
          case 5:
            if ( (*(_BYTE *)(v27 + 104) & 0x20) != 0 )
              goto LABEL_29;
            break;
          default:
LABEL_25:
            result = qdf_trace_msg(
                       0x6Du,
                       2u,
                       "%s: Wrong list type %d passed",
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       "dlm_is_bssid_of_type",
                       (unsigned int)a4);
            break;
        }
      }
      else if ( a4 )
      {
        if ( a4 == 1 )
        {
          if ( (*(_BYTE *)(v27 + 104) & 1) != 0 )
            goto LABEL_29;
        }
        else
        {
          if ( a4 != 2 )
            goto LABEL_25;
          if ( (*(_BYTE *)(v27 + 104) & 8) != 0 )
            goto LABEL_29;
        }
      }
      else if ( (*(_BYTE *)(v27 + 104) & 4) != 0 )
      {
        goto LABEL_29;
      }
LABEL_6:
      v21 = v55;
      v55 = nullptr;
      v56[0] = (__int64)v21;
    }
    while ( v21 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
