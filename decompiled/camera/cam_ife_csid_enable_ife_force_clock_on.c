__int64 __fastcall cam_ife_csid_enable_ife_force_clock_on(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  int v8; // w6
  unsigned int v9; // w19

  if ( a1 )
  {
    result = cam_cpas_reg_write(**(_DWORD **)(a1 + 3296), 0, a2 + 4 * *(_DWORD *)(a1 + 20), 1, 1, a6);
    if ( (_DWORD)result )
    {
      v8 = *(_DWORD *)(a1 + 20);
      v9 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_enable_ife_force_clock_on",
        263,
        "CPASS set IFE:%d Force clock On failed",
        v8);
      return v9;
    }
    else if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_enable_ife_force_clock_on",
        266,
        "CPASS set IFE:%d Force clock On",
        *(_DWORD *)(a1 + 20));
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_enable_ife_force_clock_on",
      251,
      "Error Invalid params");
    return 4294967274LL;
  }
  return result;
}
