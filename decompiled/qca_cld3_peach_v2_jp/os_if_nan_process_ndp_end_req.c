__int64 __fastcall os_if_nan_process_ndp_end_req(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  __int64 v14; // x21
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  int v25; // w9
  _WORD *v26; // x8
  unsigned int v27; // w10
  int v28; // w9
  const char *v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  int v39; // w9
  char v40; // w10
  __int64 v41; // x19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  unsigned int v59; // w0
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w20
  __int64 *v70; // [xsp+0h] [xbp-440h] BYREF
  int v71; // [xsp+Ch] [xbp-434h] BYREF
  char v72; // [xsp+10h] [xbp-430h]
  char v73; // [xsp+11h] [xbp-42Fh]
  unsigned __int64 time_of_the_day_us; // [xsp+12h] [xbp-42Eh]
  unsigned __int64 StatusReg; // [xsp+1Ah] [xbp-426h]
  __int16 v76; // [xsp+22h] [xbp-41Eh]
  char v77; // [xsp+24h] [xbp-41Ch]
  _QWORD s[131]; // [xsp+28h] [xbp-418h] BYREF

  s[130] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = nullptr;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 11, 20);
  if ( !v4 )
    goto LABEL_11;
  v13 = *(unsigned int **)(v4 + 608);
  if ( !v13 || (v13 = *(unsigned int **)v13) == nullptr || (v14 = *((_QWORD *)v13 + 4)) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v4, 0x14u, v13, v5, v6, v7, v8, v9, v10, v11, v12);
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  wlan_objmgr_vdev_release_ref(v4, 0x14u, v13, v5, v6, v7, v8, v9, v10, v11, v12);
  result = _osif_vdev_sync_op_start(v14, &v70, (__int64)"os_if_nan_process_ndp_end_req");
  if ( !(_DWORD)result )
  {
    memset(s, 0, 0x410u);
    v24 = *(_QWORD *)(a2 + 16);
    if ( v24 )
    {
      v25 = *(unsigned __int16 *)(v24 + 4);
      v26 = *(_WORD **)(a2 + 88);
      LODWORD(s[1]) = v25;
      if ( v26 )
      {
        v27 = (unsigned __int16)(*v26 - 4);
        v28 = (unsigned __int16)(*v26 - 4) >> 2;
        HIDWORD(s[1]) = v28;
        if ( v27 > 3 )
        {
          qdf_mem_copy(&s[2], v26 + 2, (unsigned int)(4 * v28));
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: sending ndp_end_req to SME, transaction_id: %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "__os_if_nan_process_ndp_end_req",
            LODWORD(s[1]));
          v38 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(
                  a1,
                  11,
                  20);
          if ( v38 )
          {
            v39 = *(_DWORD *)(v38 + 16);
            v40 = *(_BYTE *)(v38 + 104);
            v41 = v38;
            s[0] = v38;
            v71 = 1376297;
            v72 = v39;
            v73 = v40;
            time_of_the_day_us = qdf_get_time_of_the_day_us();
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
            v76 = s[1];
            v77 = BYTE4(s[1]);
            wlan_cp_stats_cstats_write_to_buff(0, (__int64)&v71, 0x19u, v42, v43, v44, v45, v46, v47, v48, v49);
            v58 = ucfg_nan_req_processor(v41, s, 8u, v50, v51, v52, v53, v54, v55, v56, v57);
            v59 = qdf_status_to_os_return(v58);
            if ( v59 )
            {
              v69 = v59;
              wlan_objmgr_vdev_release_ref(v41, 0x14u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
            }
            else
            {
              v69 = 0;
            }
            goto LABEL_20;
          }
          v29 = "%s: NAN data interface is not available";
        }
        else
        {
          v29 = "%s: Num NDP instances is 0";
        }
      }
      else
      {
        v29 = "%s: NDP instance ID array is unavailable";
      }
    }
    else
    {
      v29 = "%s: Transaction ID is unavailable";
    }
    qdf_trace_msg(0x48u, 2u, v29, v16, v17, v18, v19, v20, v21, v22, v23, "__os_if_nan_process_ndp_end_req");
    v69 = -22;
LABEL_20:
    _osif_vdev_sync_op_stop((__int64)v70, (__int64)"os_if_nan_process_ndp_end_req");
    result = v69;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
