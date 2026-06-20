__int64 __fastcall cam_cpas_update_ahb_vote(unsigned int a1, __int64 a2)
{
  __int64 v2; // x9
  _DWORD *v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v2 = *(_QWORD *)(g_cpas_intf + 480);
    v3 = *(_DWORD **)(v2 + 88);
    if ( v3 )
    {
      v7[1] = a2;
      v7[0] = a1;
      v4 = *(_QWORD *)(v2 + 112);
      if ( *(v3 - 1) != -1055839300 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v3)(v4, 5, v7, 16);
      if ( (_DWORD)result )
      {
        v6 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_update_ahb_vote",
          779,
          "Failed in process_cmd, rc=%d",
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
        "cam_cpas_update_ahb_vote",
        781,
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
      "cam_cpas_update_ahb_vote",
      764,
      "cpas intf not initialized");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
