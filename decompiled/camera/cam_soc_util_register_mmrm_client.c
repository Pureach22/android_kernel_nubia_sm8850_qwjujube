__int64 __fastcall cam_soc_util_register_mmrm_client(
        int a1,
        __int64 a2,
        char a3,
        __int64 a4,
        const char *a5,
        _QWORD *a6)
{
  char v12; // w0
  __int64 v13; // x3
  int v14; // w9
  int v15; // w8
  int v16; // w8
  const void *v17; // x0
  __int64 result; // x0
  const char *v19; // x6
  const char *v20; // x6
  const void *v21; // x20
  char v22; // [xsp+1Ch] [xbp-C4h]
  __int64 v23; // [xsp+20h] [xbp-C0h] BYREF
  __int64 v24; // [xsp+28h] [xbp-B8h]
  _QWORD v25[16]; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v26; // [xsp+B0h] [xbp-30h]
  unsigned __int64 v27; // [xsp+B8h] [xbp-28h]
  __int64 v28; // [xsp+C0h] [xbp-20h]
  __int64 v29; // [xsp+C8h] [xbp-18h]
  __int64 (__fastcall *v30)(__int64); // [xsp+D0h] [xbp-10h]
  __int64 v31; // [xsp+D8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v26 = 0;
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v23 = 0;
  if ( a6 )
  {
    *a6 = 0;
    if ( (debug_bypass_drivers & 4) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        2,
        "cam_soc_util_register_mmrm_client",
        913,
        "Bypass register mmrm client");
    }
    else
    {
      v12 = mmrm_client_check_scaling_supported(0, 1);
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        if ( (v12 & 1) != 0 )
          v19 = "Y";
        else
          v19 = "N";
        v22 = v12;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_is_mmrm_supported_on_current_chip",
          870,
          "is mmrm supported: %s",
          v19);
        if ( (v22 & 1) != 0 )
          goto LABEL_6;
      }
      else if ( (v12 & 1) != 0 )
      {
LABEL_6:
        v13 = *(_QWORD *)(a4 + 24);
        if ( *(_BYTE *)(a4 + 3200) )
          v14 = 3;
        else
          v14 = 0;
        if ( *(_BYTE *)(a4 + 3200) )
          v15 = 2;
        else
          v15 = 0;
        v27 = __PAIR64__(v15, v14);
        v26 = a2;
        LODWORD(v23) = 0;
        LODWORD(v24) = 1;
        HIDWORD(v24) = a1;
        snprintf((char *)v25, 0x80u, "%s_%s", v13, a5);
        if ( (a3 & 1) != 0 )
          v16 = 2;
        else
          v16 = 1;
        LODWORD(v28) = v16;
        v29 = a4;
        v30 = cam_mmrm_notifier_callback;
        v17 = (const void *)mmrm_client_register(&v23);
        if ( !v17 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_register_mmrm_client",
            947,
            "MMRM Register failed Dev %s clk %s id %d",
            *(const char **)(a4 + 24),
            a5,
            a1);
          result = 4294967274LL;
          goto LABEL_23;
        }
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          v20 = *(const char **)(a4 + 24);
          v21 = v17;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_register_mmrm_client",
            953,
            "MMRM Register success Dev %s is_nrt_dev %d clk %s id %d handle=%pK",
            v20,
            a3 & 1,
            a5,
            a1,
            v17);
          v17 = v21;
        }
        *a6 = v17;
      }
    }
    result = 0;
    goto LABEL_23;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_register_mmrm_client",
    906,
    "Invalid mmrm input");
  result = 4294967274LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
