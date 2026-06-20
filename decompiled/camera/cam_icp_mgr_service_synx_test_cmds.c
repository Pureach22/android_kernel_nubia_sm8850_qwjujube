__int64 __fastcall cam_icp_mgr_service_synx_test_cmds(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x22
  int v5; // w8
  int v6; // w8
  unsigned int v7; // w21
  __int64 v8; // x1
  char v9; // w8
  __int64 v10; // x0
  __int64 v11; // x1
  unsigned int v12; // w0
  __int64 v13; // x6
  __int64 v14; // x4
  unsigned int v15; // w0
  const char *v16; // x7
  const char *v17; // x6
  __int64 v18; // x0
  __int64 v19; // x1
  unsigned int v20; // w0
  __int64 v22; // x1
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x20
  __int64 v26; // x1
  __int64 v27; // x21
  __int64 v28; // x0
  __int64 v29; // x22
  __int64 v30; // x1
  __int64 v31; // x23
  int v32; // w0
  int v33; // [xsp+2Ch] [xbp-34h] BYREF
  __int64 v34; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int64 v35; // [xsp+38h] [xbp-28h]
  unsigned __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v38[2]; // [xsp+50h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = a1 + 40960;
    mutex_lock(a1);
    v5 = a2[1];
    if ( v5 == 2 )
    {
      v9 = *(_BYTE *)(v4 + 3269);
      v37 = 0;
      v38[0] = 0;
      v35 = 0;
      v36 = 0;
      v33 = 256;
      if ( (v9 & 1) == 0 )
      {
        v15 = cam_icp_mgr_icp_resume(a1, &v33);
        if ( v15 )
        {
          v7 = v15;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_synx_send_test_cmd",
            7973,
            "Failed to resume ICP rc: %d",
            v15);
          goto LABEL_29;
        }
        v22 = *(_QWORD *)(v4 + 3160);
        if ( v22 )
          hfi_set_debug_level(*(unsigned int *)(a1 + 156), v22, *(unsigned int *)(v4 + 3168));
      }
      v10 = (unsigned int)a2[9];
      v11 = *(unsigned int *)(a1 + 148);
      v34 = 0x301080100000018LL;
      v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64 *, _QWORD *, _QWORD, _QWORD))cam_mem_get_io_buf)(
              v10,
              v11,
              &v37,
              v38,
              0,
              0);
      if ( v12 )
      {
        v13 = (unsigned int)a2[9];
        v7 = v12;
        v14 = 7990;
      }
      else
      {
        v18 = (unsigned int)a2[10];
        v19 = *(unsigned int *)(a1 + 148);
        v35 = __PAIR64__(v37, v38[0]);
        v20 = ((__int64 (__fastcall *)(__int64, __int64, __int64 *, _QWORD *, _QWORD, _QWORD))cam_mem_get_io_buf)(
                v18,
                v19,
                &v37,
                v38,
                0,
                0);
        if ( !v20 )
        {
          v36 = __PAIR64__(v37, v38[0]);
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_mgr_synx_send_test_cmd",
              8011,
              "Input (hdl: 0x%x iova: 0x%x size: 0x%x) output (hdl: 0x%x iova: 0x%x size: 0x%x)",
              a2[9],
              HIDWORD(v35),
              v35,
              a2[10],
              v37,
              LODWORD(v38[0]));
          v23 = *(unsigned int *)(a1 + 156);
          *(_DWORD *)(v4 + 3064) = 0;
          v7 = hfi_write_cmd(v23, &v34);
          if ( !v7 )
          {
            v24 = ktime_get_with_offset(1);
            v25 = ns_to_timespec64(v24);
            v27 = v26;
            if ( cam_common_wait_for_completion_timeout(v4 + 3064) )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                3,
                "cam_icp_mgr_synx_send_test_cmd",
                8026,
                "Synx test cmd done rc: %d",
                0);
              v7 = 0;
            }
            else
            {
              v28 = ktime_get_with_offset(1);
              v29 = ns_to_timespec64(v28);
              v31 = v30;
              v32 = jiffies_to_msecs(1250, v30);
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                256,
                1,
                "cam_icp_mgr_synx_send_test_cmd",
                8020,
                "FW response timeout for synx test cmd (timeout: %ums start: timestamp:[%lld:%06lld] end: timestamp:[%lld:%06lld])",
                v32,
                v25,
                v27 / 1000,
                v29,
                v31 / 1000);
              v7 = -110;
            }
          }
          goto LABEL_29;
        }
        v13 = (unsigned int)a2[9];
        v7 = v20;
        v14 = 8001;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_synx_send_test_cmd",
        v14,
        "Failed to get buf for hdl: %d rc: %d",
        v13,
        v7);
    }
    else
    {
      if ( v5 == 1 )
      {
        v6 = a2[9];
        LODWORD(v34) = 256;
        if ( v6 )
        {
          v7 = cam_icp_mgr_icp_resume(a1, &v34);
          if ( !v7 )
          {
            v8 = *(_QWORD *)(v4 + 3160);
            if ( v8 )
              hfi_set_debug_level(*(unsigned int *)(a1 + 156), v8, *(unsigned int *)(v4 + 3168));
            v7 = 0;
            goto LABEL_22;
          }
        }
        else
        {
          v7 = cam_icp_mgr_icp_power_collapse(a1, &v34);
          if ( !v7 )
          {
LABEL_22:
            if ( a2[9] )
              v17 = "Y";
            else
              v17 = "N";
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD))cam_print_log)(
              3,
              256,
              3,
              "cam_icp_mgr_synx_core_control",
              7951,
              "Synx test core control: %s done rc: %d",
              v17,
              v7);
            goto LABEL_29;
          }
        }
        if ( a2[9] )
          v16 = "Y";
        else
          v16 = "N";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_synx_core_control",
          7948,
          "[%s] Failed to process core control resume: %s",
          a1 + 112,
          v16);
        goto LABEL_22;
      }
      v7 = -22;
    }
LABEL_29:
    mutex_unlock(a1);
    goto LABEL_30;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_service_synx_test_cmds",
    8039,
    "Input params are Null:");
  v7 = -22;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v7;
}
