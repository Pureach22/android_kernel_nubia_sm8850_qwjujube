__int64 __fastcall cam_hw_cdm_get_cdm_config(__int64 a1)
{
  __int64 v2; // x23
  unsigned int v3; // w0
  unsigned int v4; // w20
  _BOOL8 hw_reg; // x0
  __int64 v6; // x6
  __int64 v7; // x7
  const char *v8; // x5
  __int64 v9; // x4
  unsigned int *v10; // x8
  __int64 v11; // x0
  int v12; // w0
  _UNKNOWN **ops; // x0
  int v15; // [xsp+10h] [xbp-10h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
         a1 + 96,
         0xFFFFFFFFLL,
         1,
         *(unsigned int *)(a1 + 2968),
         1);
  if ( v3 )
  {
    v4 = v3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_get_cdm_config",
      1945,
      "Enable platform failed for dev %s",
      *(const char **)(a1 + 120));
    goto LABEL_30;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_get_cdm_config",
      1949,
      "%s%u init success",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116));
  *(_DWORD *)(a1 + 92) = 1;
  hw_reg = cam_cdm_read_hw_reg(a1, ***(_DWORD ***)(v2 + 232), (int *)(v2 + 216));
  if ( hw_reg )
  {
    v6 = *(_QWORD *)(a1 + 152);
    v7 = *(unsigned int *)(a1 + 116);
    v8 = "Failed to read HW Version for %s%u";
    v9 = 1956;
  }
  else
  {
    v10 = *(unsigned int **)(**(_QWORD **)(v2 + 232) + 8LL);
    if ( !v10 || !(hw_reg = cam_cdm_read_hw_reg(a1, *v10, (int *)(v2 + 220))) )
    {
      if ( (cam_presil_mode_enabled(hw_reg) & 1) != 0 )
      {
        v11 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 760LL);
        v16 = 0;
        v15 = 0;
        if ( (of_property_read_variable_u32_array(v11, "override-cdm-family", &v16, 1, 0) & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            3,
            "cam_hw_cdm_get_cdm_config",
            1999,
            "no cdm family override,using current hw family 0x%x",
            *(_DWORD *)(v2 + 220));
        else
          *(_DWORD *)(v2 + 220) = v16;
        if ( (of_property_read_variable_u32_array(
                *(_QWORD *)(*(_QWORD *)(a1 + 96) + 760LL),
                "override-cdm-version",
                &v15,
                1,
                0)
            & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            3,
            "cam_hw_cdm_get_cdm_config",
            2008,
            "no cdm version override,using current hw version 0x%x",
            *(_DWORD *)(v2 + 216));
        else
          *(_DWORD *)(v2 + 216) = v15;
      }
      v12 = *(_DWORD *)(v2 + 216);
      if ( (debug_mdl & 1) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_get_cdm_config",
          2018,
          "%s%d Hw version read success family =%x hw =%x",
          *(const char **)(a1 + 152),
          *(_DWORD *)(a1 + 116),
          *(_DWORD *)(v2 + 220),
          v12);
        v12 = *(_DWORD *)(v2 + 216);
      }
      ops = cam_cdm_get_ops(v12, nullptr, 0);
      v4 = 0;
      *(_QWORD *)(v2 + 240) = ops;
      if ( !ops )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_get_cdm_config",
          2025,
          "Failed to util ops for cdm hw name %s",
          (const char *)(v2 + 4));
        v4 = -22;
      }
      goto LABEL_24;
    }
    v6 = *(_QWORD *)(a1 + 152);
    v7 = *(unsigned int *)(a1 + 116);
    v8 = "Failed to read %s%d family Version";
    v9 = 1966;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    1,
    1,
    "cam_hw_cdm_get_cdm_config",
    v9,
    v8,
    v6,
    v7);
  v4 = -5;
LABEL_24:
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
                       a1 + 96,
                       0xFFFFFFFFLL,
                       1,
                       1) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_get_cdm_config",
      2036,
      "disable platform failed for dev %s",
      *(const char **)(a1 + 120));
  }
  else
  {
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_get_cdm_config",
        2039,
        "%s%d Deinit success",
        *(const char **)(a1 + 152),
        *(_DWORD *)(a1 + 116));
    *(_DWORD *)(a1 + 92) = 0;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v4;
}
