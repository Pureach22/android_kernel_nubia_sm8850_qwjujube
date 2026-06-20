__int64 __fastcall cam_csiphy_enable_hw(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  unsigned int v3; // w20
  unsigned int v4; // w21
  int v5; // w8
  __int64 (*v7)(void); // x8
  unsigned int v8; // w0
  unsigned int v9; // w9
  __int16 v10; // w8
  int v11; // w10
  unsigned __int64 v12; // x28
  __int64 i; // x24
  __int64 v14; // x8
  __int64 v15; // x23
  __int64 v16; // x1
  int v17; // w0
  const char *v18; // x6
  int v19; // w7
  unsigned int v20; // w19
  unsigned int v21; // w22
  int v22; // w0
  int v23; // w21
  char *string_from_level; // x20
  char *v25; // x0
  unsigned int v26; // w20
  unsigned int v27; // w0
  __int64 v28; // x1

  if ( a2 >= 4 )
  {
LABEL_15:
    __break(0x5512u);
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 120);
    v2 = a1;
    *(_DWORD *)(a1 + 120) = v5 + 1;
    if ( v5 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_enable_hw",
        208,
        "csiphy refcount = %d",
        v5 + 1);
      return 0;
    }
    v4 = a2;
    v7 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 112) + 112LL);
    if ( *((_DWORD *)v7 - 1) != -1852174336 )
      __break(0x8228u);
    v8 = v7();
    v9 = *(_DWORD *)(v2 + 1780);
    v3 = v8;
    if ( v9 )
    {
      v10 = debug_mdl;
      v11 = debug_priority;
      v12 = v2 + 2296 + ((unsigned __int64)v8 << 7);
      for ( i = 0; (unsigned int)i < v9; ++i )
      {
        if ( v10 < 0 && !v11 )
        {
          if ( (unsigned int)i > 0x1F || v3 > 9 )
            goto LABEL_15;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v10 & 0x8000,
            4,
            "cam_csiphy_enable_hw",
            218,
            "PHY:%d %s:%d",
            *(_DWORD *)(v2 + 932),
            *(const char **)(v2 + 2296 + 8 * i - 512),
            *(_DWORD *)(v12 + 4 * i));
          v10 = debug_mdl;
          v11 = debug_priority;
          v9 = *(_DWORD *)(v2 + 1780);
        }
      }
    }
  }
  *(_DWORD *)(v2 + 4496) = v3;
  v14 = v2 + 104LL * v4;
  v15 = v14 + 600;
  if ( *(_BYTE *)(v2 + 4112) == 1 && *(_BYTE *)(v14 + 688) == 1 )
    v16 = *(unsigned int *)(v14 + 684);
  else
    v16 = 0xFFFFFFFFLL;
  v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
          v2 + 912,
          v16,
          1,
          v3,
          1);
  if ( v17 )
  {
    v18 = *(const char **)(v2 + 936);
    v19 = *(unsigned __int8 *)(v2 + 4112);
    v20 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_enable_hw",
      229,
      "[%s] failed to enable platform resources, clk_drv_en=%d, use_hw_client=%d conn_csid_idx=%d, rc=%d",
      v18,
      v19,
      *(unsigned __int8 *)(v15 + 88),
      *(_DWORD *)(v15 + 84),
      v17);
    return v20;
  }
  if ( *(_BYTE *)(v2 + 4112) != 1 || *(_BYTE *)(v15 + 88) != 1 || *(_BYTE *)(v15 + 89) != 1 )
    goto LABEL_33;
  v21 = *(_DWORD *)(v2 + 3784);
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))cam_soc_util_set_clk_rate_level)(
          v2 + 912,
          *(unsigned int *)(v15 + 84),
          v3,
          v21,
          0);
  if ( v22 )
  {
    v23 = v22;
    string_from_level = cam_soc_util_get_string_from_level(v3);
    v25 = cam_soc_util_get_string_from_level(v21);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_enable_hw",
      244,
      "Failed to set the req clk_rate level[high low]: [%s %s] cesta_client_idx: %d rc: %d",
      string_from_level,
      v25,
      *(_DWORD *)(v15 + 84),
      v23);
    v26 = -22;
    goto LABEL_30;
  }
  v27 = cam_soc_util_cesta_channel_switch(*(_DWORD *)(v15 + 84), "csiphy_start");
  if ( !v27 )
  {
LABEL_33:
    cam_csiphy_reset(v2);
    return 0;
  }
  v26 = v27;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_enable_hw",
    253,
    "[%s] Failed to apply power states for crm client:%d rc:%d",
    *(const char **)(v2 + 936),
    *(_DWORD *)(v15 + 84),
    v27);
LABEL_30:
  if ( *(_BYTE *)(v2 + 4112) == 1 && *(_BYTE *)(v15 + 88) == 1 )
    v28 = *(unsigned int *)(v15 + 84);
  else
    v28 = 0xFFFFFFFFLL;
  ((void (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(v2 + 912, v28, 1, 1);
  return v26;
}
