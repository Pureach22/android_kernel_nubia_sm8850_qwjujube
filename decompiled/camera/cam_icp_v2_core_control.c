__int64 __fastcall cam_icp_v2_core_control(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w19
  const char *v5; // x6
  __int64 v6; // x8
  unsigned int v7; // w9
  __int64 v8; // x6
  const char *v9; // x3
  const char *v10; // x5
  __int64 v11; // x2
  __int64 v12; // x4
  __int64 v13; // x8
  unsigned int v14; // w6
  __int64 v15; // x19
  __int64 v16; // x0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 3680) + 105LL) == 1 )
  {
    v4 = qcom_scm_set_remote_state(a2, *(unsigned int *)(*(_QWORD *)(a1 + 3392) + 12LL));
    if ( v4 )
    {
      if ( a2 == 1 )
        v5 = "resume";
      else
        v5 = "suspend";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v2_core_control",
        987,
        "remote state set to %s failed rc=%d",
        v5,
        v4);
      v6 = *(_QWORD *)(a1 + 3680);
      if ( *(_DWORD *)(v6 + 24) < 8u )
      {
        v7 = *(_DWORD *)(v6 + 56);
        if ( v7 <= 7 )
        {
          v8 = (unsigned int)cam_io_r_mb(*(_QWORD *)(a1 + 384 + 24LL * v7) + *(unsigned int *)(*(_QWORD *)(v6 + 16)
                                                                                             + 24LL));
          v9 = "__cam_icp_v2_core_reg_dump";
          v10 = "ICP PFault status:0x%x";
          v11 = 3;
          v12 = 955;
LABEL_21:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            256,
            v11,
            v9,
            v12,
            v10,
            v8);
          goto LABEL_22;
        }
      }
LABEL_24:
      __break(0x5512u);
      JUMPOUT(0x2442C0);
    }
  }
  else
  {
    if ( (cam_presil_mode_enabled(a1) & 1) == 0 )
    {
      if ( a2 == 1 )
      {
        v4 = _cam_icp_v2_power_resume(a1);
        if ( !v4 )
          goto LABEL_22;
        v9 = "cam_icp_v2_core_control";
        v10 = "ICP resume failed rc=%d";
        v11 = 1;
        v12 = 999;
      }
      else
      {
        v13 = *(_QWORD *)(a1 + 3680);
        v18 = 0;
        v14 = *(_DWORD *)(v13 + 36);
        if ( (v14 & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "__cam_icp_v2_power_collapse",
            491,
            "No reg base idx found for ICP_SYS: %d",
            v14);
          v4 = -22;
        }
        else
        {
          if ( v14 > 7 )
            goto LABEL_24;
          v15 = *(_QWORD *)(a1 + 24LL * v14 + 384);
          v16 = cam_common_read_poll_timeout((const void *)(v15 + 12), 0x64u, 10000, 0x80u, 128, &v18);
          if ( !(_DWORD)v16 )
          {
            cam_io_w_mb(v16, v15 + 4);
            v4 = 0;
            goto LABEL_22;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "__cam_icp_v2_power_collapse",
            506,
            "WFI poll timed out: status=0x%08x",
            v18);
          v4 = -110;
        }
        v9 = "cam_icp_v2_core_control";
        v10 = "ICP collapse failed rc=%d";
        v11 = 1;
        v12 = 1003;
      }
      v8 = v4;
      goto LABEL_21;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      3,
      "cam_icp_v2_core_control",
      992,
      "PRESIL-ICP-B2B-HFI-INIT no PC no resume return 0");
    v4 = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v4;
}
