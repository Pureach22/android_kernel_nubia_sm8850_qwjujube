__int64 __fastcall cam_cpas_update_axi_floor_lvl(int a1, int a2)
{
  __int64 v2; // x8
  _DWORD *v3; // x9
  __int64 v4; // x8
  __int64 result; // x0
  unsigned int v6; // w19
  _DWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v2 = *(_QWORD *)(g_cpas_intf + 480);
    v3 = *(_DWORD **)(v2 + 88);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v2 + 112);
      v7[0] = a1;
      v7[1] = a2;
      if ( *(v3 - 1) != -1055839300 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64))v3)(v4, 7, v7, 8);
      if ( (_DWORD)result )
      {
        v6 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_update_axi_floor_lvl",
          712,
          "Failed in process_cmd CAM_CPAS_HW_AXI_FLOOR_LVL, rc=%d",
          result);
        result = v6;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_update_axi_floor_lvl",
        714,
        "Invalid process_cmd ops");
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_update_axi_floor_lvl",
      696,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
