__int64 __fastcall show_sta_info(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w0
  unsigned __int64 StatusReg; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _QWORD *v40; // x1
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  unsigned __int8 *v50; // x8
  unsigned __int64 v51; // x26
  unsigned int v52; // w3
  int v53; // w4
  int v54; // w5
  int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  __int64 *v66; // [xsp+0h] [xbp-20h] BYREF
  _QWORD *v67; // [xsp+8h] [xbp-18h] BYREF
  __int64 v68[2]; // [xsp+10h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = nullptr;
  v5 = _osif_vdev_sync_op_start(a1 - 1376, &v66, (__int64)"show_sta_info");
  if ( !v5 )
  {
    v67 = nullptr;
    v68[0] = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v6, v7, v8, v9, v10, v11, v12, v13, "__show_sta_info", a1 - 1080);
    v5 = _hdd_validate_adapter(a1 + 1312, (__int64)"__show_sta_info", v14, v15, v16, v17, v18, v19, v20, v21);
    if ( !v5 )
    {
      if ( *(_DWORD *)(a1 + 1352) == 1 )
      {
        v5 = _wlan_hdd_validate_context(
               *(_QWORD *)(a1 + 1336),
               (__int64)"__show_sta_info",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29);
        if ( !v5 )
        {
          scnprintf(a3, 4096, "%s    get_sta_info:\nstaAddress\n", (const char *)(a1 - 1080));
          v5 = v30;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 40184);
          }
          else
          {
            raw_spin_lock_bh(a1 + 40184);
            *(_QWORD *)(a1 + 40192) |= 1uLL;
          }
          hdd_get_front_sta_info_no_lock((_QWORD *)(a1 + 40160), v68);
          v40 = (_QWORD *)v68[0];
          if ( v68[0] )
          {
            hdd_take_sta_info_ref(a1 + 40160, v68[0], 0, 0x1Du, v32, v33, v34, v35, v36, v37, v38, v39);
            v40 = (_QWORD *)v68[0];
          }
          hdd_get_next_sta_info_no_lock((_QWORD *)(a1 + 40160), v40, &v67);
          if ( v67 )
            hdd_take_sta_info_ref(a1 + 40160, (__int64)v67, 0, 0x1Du, v41, v42, v43, v44, v45, v46, v47, v48);
          v49 = *(_QWORD *)(a1 + 40192);
          if ( (v49 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 40192) = v49 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 40184);
            v50 = (unsigned __int8 *)v68[0];
            if ( v68[0] )
              goto LABEL_15;
          }
          else
          {
            raw_spin_unlock(a1 + 40184);
            v50 = (unsigned __int8 *)v68[0];
            if ( v68[0] )
            {
LABEL_15:
              v51 = _ReadStatusReg(SP_EL0);
              while ( 1 )
              {
                v52 = v50[32];
                v53 = v50[33];
                v54 = v50[34];
                if ( __PAIR64__(v53, v52) == 0xFF000000FFLL )
                {
                  if ( v54 == 255 )
                  {
                    if ( v50[35] == 255 && v50[36] == 255 && v50[37] == 255 )
                      goto LABEL_24;
                    v54 = 255;
                  }
                  v53 = 255;
                }
                v22 = scnprintf(
                        a3 + v5,
                        4096LL - v5,
                        "%02x:%02x:%02x:**:**:%02x ecsa=%d\n",
                        v52,
                        v53,
                        v54,
                        v50[37],
                        v50[56]);
                v5 += v55;
LABEL_24:
                hdd_put_sta_info_ref(a1 + 40160, v68, 1, 0x1Du, v22, v23, v24, v25, v26, v27, v28, v29);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v51 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v51 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(a1 + 40184);
                }
                else
                {
                  raw_spin_lock_bh(a1 + 40184);
                  *(_QWORD *)(a1 + 40192) |= 1uLL;
                }
                v68[0] = (__int64)v67;
                hdd_get_next_sta_info_no_lock((_QWORD *)(a1 + 40160), v67, &v67);
                if ( v67 )
                  hdd_take_sta_info_ref(a1 + 40160, (__int64)v67, 0, 0x1Du, v56, v57, v58, v59, v60, v61, v62, v63);
                v64 = *(_QWORD *)(a1 + 40192);
                if ( (v64 & 1) != 0 )
                {
                  *(_QWORD *)(a1 + 40192) = v64 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(a1 + 40184);
                  v50 = (unsigned __int8 *)v68[0];
                  if ( !v68[0] )
                    break;
                }
                else
                {
                  raw_spin_unlock(a1 + 40184);
                  v50 = (unsigned __int8 *)v68[0];
                  if ( !v68[0] )
                    break;
                }
              }
            }
          }
        }
      }
      else
      {
        v5 = 0;
      }
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", v22, v23, v24, v25, v26, v27, v28, v29, "__show_sta_info");
    _osif_vdev_sync_op_stop((__int64)v66, (__int64)"show_sta_info");
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
