size_t __fastcall wcnss_wowpattern_write(__int64 a1, int a2, size_t a3)
{
  __int64 v5; // x8
  __int64 v6; // x20
  int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  char *v36; // x0
  char *v37; // x0
  char *v38; // x0
  char *v39; // x21
  char *v40; // x0
  char *v41; // x22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 *v50; // [xsp+8h] [xbp-228h] BYREF
  _BYTE v51[4]; // [xsp+10h] [xbp-220h] BYREF
  _BYTE v52[4]; // [xsp+14h] [xbp-21Ch] BYREF
  char *stringp; // [xsp+18h] [xbp-218h] BYREF
  _BYTE s[513]; // [xsp+27h] [xbp-209h] BYREF
  __int64 v55; // [xsp+228h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v50 = nullptr;
  v6 = *(_QWORD *)(v5 + 696);
  v7 = _osif_vdev_sync_op_start(v6, &v50, (__int64)"wcnss_wowpattern_write");
  if ( !v7 )
  {
    memset(s, 0, sizeof(s));
    v52[0] = 0;
    v51[0] = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__wcnss_wowpattern_write");
    if ( *(_DWORD *)(v6 + 2688) == 1885692259 )
    {
      v24 = *(_QWORD *)(v6 + 2712);
      v25 = _wlan_hdd_validate_context(v24, (__int64)"__wcnss_wowpattern_write", v16, v17, v18, v19, v20, v21, v22, v23);
      if ( v25 )
      {
        a3 = v25;
LABEL_9:
        _osif_vdev_sync_op_stop((__int64)v50, (__int64)"wcnss_wowpattern_write");
        goto LABEL_10;
      }
      if ( !wlan_hdd_validate_modules_state(v24, v26, v27, v28, v29, v30, v31, v32, v33) )
      {
LABEL_8:
        a3 = -22;
        goto LABEL_9;
      }
      if ( (sme_is_feature_supported_by_fw(22) & 1) != 0 )
      {
        if ( a3 < 0x201 )
        {
          _check_object_size(s, a3, 0);
          if ( inline_copy_from_user_2((int)s, a2, a3) )
          {
            a3 = -14;
            goto LABEL_9;
          }
          s[a3] = 0;
          stringp = s;
          v36 = strsep(&stringp, " ");
          if ( v36 && !(unsigned int)kstrtou8(v36, 0, v52) )
          {
            v37 = strsep(&stringp, " ");
            if ( !v37 )
            {
              ((void (__fastcall *)(__int64, _QWORD))hdd_del_wowl_ptrn_debugfs)(v6 + 2688, v52[0]);
              goto LABEL_9;
            }
            if ( !(unsigned int)kstrtou8(v37, 0, v51) )
            {
              v38 = strsep(&stringp, " ");
              if ( v38 )
              {
                v39 = v38;
                v40 = strsep(&stringp, " ");
                if ( v40 )
                {
                  v41 = v40;
                  v40[strlen(v40) - 1] = 0;
                  ((void (__fastcall *)(__int64, _QWORD, _QWORD, char *, char *))hdd_add_wowl_ptrn_debugfs)(
                    v6 + 2688,
                    v52[0],
                    v51[0],
                    v39,
                    v41);
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: exit",
                    v42,
                    v43,
                    v44,
                    v45,
                    v46,
                    v47,
                    v48,
                    v49,
                    "__wcnss_wowpattern_write");
                  goto LABEL_9;
                }
              }
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Command length is larger than %d bytes",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__wcnss_wowpattern_write",
            512);
        }
        goto LABEL_8;
      }
      v34 = "%s: Wake-on-Wireless feature is not supported in firmware!";
    }
    else
    {
      v34 = "%s: Invalid adapter or adapter has invalid magic";
    }
    qdf_trace_msg(0x33u, 2u, v34, v16, v17, v18, v19, v20, v21, v22, v23, "__wcnss_wowpattern_write");
    goto LABEL_8;
  }
  a3 = v7;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return a3;
}
