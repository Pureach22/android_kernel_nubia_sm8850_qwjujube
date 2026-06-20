__int64 __fastcall cam_cpas_csid_input_core_info_update(int a1, int a2, char a3)
{
  __int64 v3; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w19
  _DWORD v8[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v3 = *(_QWORD *)(g_cpas_intf + 480);
    v4 = *(_DWORD **)(v3 + 88);
    if ( v4 )
    {
      v8[0] = a1;
      v5 = *(_QWORD *)(v3 + 112);
      v8[1] = a2;
      v8[2] = a3 & 1;
      if ( *(v4 - 1) != -1055839300 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *, __int64))v4)(v5, 17, v8, 12);
      if ( (_DWORD)result )
      {
        v7 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_csid_input_core_info_update",
          311,
          "Failed in process_cmd, rc=%d",
          result);
        result = v7;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_csid_input_core_info_update",
        313,
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
      "cam_cpas_csid_input_core_info_update",
      296,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
