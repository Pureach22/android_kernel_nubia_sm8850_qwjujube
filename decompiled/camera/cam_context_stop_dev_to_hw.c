__int64 __fastcall cam_context_stop_dev_to_hw(__int64 a1)
{
  __int64 result; // x0
  __int64 *v3; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[1] = 0;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 208) )
    {
      if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
      {
        _warn_printk("Invalid execution context\n");
        __break(0x800u);
        result = 4294967274LL;
      }
      else
      {
        result = cam_context_flush_ctx_to_hw(a1);
        if ( !(_DWORD)result )
        {
          v3 = *(__int64 **)(a1 + 208);
          v4 = (_DWORD *)v3[6];
          if ( v4 )
          {
            v6[0] = *(_QWORD *)(a1 + 264);
            v5 = *v3;
            if ( *(v4 - 1) != 1863972096 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD *))v4)(v5, v6);
          }
          result = 0;
        }
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_stop_dev_to_hw",
        1304,
        "[%s][%d] HW interface is not ready",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      result = 4294967282LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_stop_dev_to_hw",
      1297,
      "Invalid input param");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
