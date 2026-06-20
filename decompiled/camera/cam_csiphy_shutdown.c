__int64 __fastcall cam_csiphy_shutdown(__int64 result)
{
  unsigned int v1; // w8
  unsigned int v2; // w6
  __int64 v3; // x19
  __int64 v4; // x28
  unsigned __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x24
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x4
  const char *v11; // x5
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  unsigned int v14; // w8
  unsigned int v15; // w8

  v1 = *(_DWORD *)(result + 104);
  if ( !v1 )
    return result;
  v2 = *(_DWORD *)(result + 80);
  v3 = result;
  if ( !v2 )
  {
    if ( !*(_DWORD *)(result + 84) )
      return result;
    v2 = 0;
    if ( v1 == 2 )
      goto LABEL_10;
    goto LABEL_9;
  }
  if ( v2 >= 3 )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x8000,
               2,
               "cam_csiphy_shutdown",
               2142,
               "acquire count is invalid: %u",
               v2);
    v1 = *(_DWORD *)(v3 + 104);
    v2 = 3;
    *(_DWORD *)(v3 + 80) = 3;
  }
  if ( v1 != 2 )
  {
LABEL_9:
    if ( !*(_DWORD *)(v3 + 84) )
      goto LABEL_49;
  }
LABEL_10:
  if ( v2 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = v3 + v4;
      if ( *(_BYTE *)(v3 + v4 + 603) )
        result = cam_csiphy_program_secure_mode(v3, 0, (unsigned int)v5, 1);
      *(_BYTE *)(v6 + 603) = 0;
      if ( *(_BYTE *)(v3 + 4112) != 1 )
        goto LABEL_21;
      v7 = v3 + v4;
      if ( *(_BYTE *)(v3 + v4 + 688) != 1 )
        goto LABEL_21;
      if ( (unsigned int)cam_soc_util_set_src_clk_rate(v3 + 912, *(_DWORD *)(v7 + 684), 0, 0) )
      {
        v8 = *(unsigned int *)(v3 + 932);
        v9 = *(unsigned int *)(v7 + 684);
        v10 = 2166;
        v11 = "[%d] Failed in setting clk rate for %d";
      }
      else
      {
        result = cam_soc_util_cesta_channel_switch(*(_DWORD *)(v7 + 684), "csiphy_shutdown");
        if ( !(_DWORD)result )
          goto LABEL_21;
        v8 = *(unsigned int *)(v7 + 684);
        v9 = (unsigned int)result;
        v10 = 2173;
        v11 = "Failed to apply power states for cesta client:%d rc:%d";
      }
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                 3,
                 0x8000,
                 1,
                 "cam_csiphy_shutdown",
                 v10,
                 v11,
                 v8,
                 v9);
LABEL_21:
      v1 = debug_mdl;
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        result = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   (unsigned __int16)debug_mdl & 0x8000,
                   4,
                   "cam_csiphy_reset_phyconfig_param",
                   469,
                   "Resetting phyconfig param at index: %d",
                   v5);
        if ( v4 == 312 )
          goto LABEL_48;
      }
      else if ( v4 == 312 )
      {
        goto LABEL_48;
      }
      ++v5;
      v12 = v3 + v4;
      *(_QWORD *)(v6 + 600) = 0;
      *(_QWORD *)(v6 + 608) = 0;
      v4 += 104;
      *(_QWORD *)(v6 + 616) = 0;
      v13 = *(unsigned int *)(v3 + 80);
      *(_WORD *)(v12 + 628) = 0;
      *(_DWORD *)(v12 + 648) = -1;
      *(_DWORD *)(v12 + 624) = -1;
      *(_DWORD *)(v12 + 684) = -1;
      *(_WORD *)(v12 + 688) = 0;
      *(_QWORD *)(v12 + 696) = 0;
      *(_BYTE *)(v12 + 690) = 0;
    }
    while ( v5 < v13 );
  }
  mutex_lock(&active_csiphy_cnt_mutex);
  if ( *(_BYTE *)(v3 + 4728) == 1 && active_csiphy_hw_cnt >= 1 )
  {
    --active_csiphy_hw_cnt;
    cam_csiphy_program_common_registers(v3, 1, 0);
  }
  mutex_unlock(&active_csiphy_cnt_mutex);
  cam_csiphy_reset(v3);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
             v3 + 912,
             0xFFFFFFFFLL,
             1,
             1);
  v1 = *(_DWORD *)(v3 + 932);
  if ( v1 > 7 )
    goto LABEL_48;
  if ( *((_DWORD *)&g_phy_data + 14 * v1 + 9) == 255 )
    result = cam_cpas_stop(*(_DWORD *)(v3 + 88));
  v2 = *(_DWORD *)(v3 + 80);
  *(_DWORD *)(v3 + 104) = 1;
  do
  {
    if ( !v2 )
      break;
    result = *(unsigned int *)(v3 + 648);
    if ( (_DWORD)result != -1 )
    {
      result = cam_destroy_device_hdl(result);
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x8000,
                   1,
                   "cam_csiphy_shutdown",
                   2206,
                   "Failed at destroying the device hdl: 0x%x",
                   *(_DWORD *)(v3 + 648));
    }
    v14 = *(_DWORD *)(v3 + 80);
    *(_QWORD *)(v3 + 648) = -1;
    if ( v14 < 2 )
      break;
    result = *(unsigned int *)(v3 + 752);
    if ( (_DWORD)result != -1 )
    {
      result = cam_destroy_device_hdl(result);
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x8000,
                   1,
                   "cam_csiphy_shutdown",
                   2206,
                   "Failed at destroying the device hdl: 0x%x",
                   *(_DWORD *)(v3 + 752));
    }
    v15 = *(_DWORD *)(v3 + 80);
    *(_QWORD *)(v3 + 752) = -1;
    if ( v15 < 3 )
      break;
    result = *(unsigned int *)(v3 + 856);
    if ( (_DWORD)result != -1 )
    {
      result = cam_destroy_device_hdl(result);
      if ( (_DWORD)result )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x8000,
                   1,
                   "cam_csiphy_shutdown",
                   2206,
                   "Failed at destroying the device hdl: 0x%x",
                   *(_DWORD *)(v3 + 856));
    }
    v1 = *(_DWORD *)(v3 + 80);
    *(_QWORD *)(v3 + 856) = -1;
    if ( v1 <= 3 )
      break;
LABEL_48:
    __break(0x5512u);
LABEL_49:
    ;
  }
  while ( v1 == 1 );
  *(_DWORD *)(v3 + 120) = 0;
  *(_QWORD *)(v3 + 80) = 0;
  *(_DWORD *)(v3 + 92) = 0;
  *(_DWORD *)(v3 + 104) = 0;
  return result;
}
