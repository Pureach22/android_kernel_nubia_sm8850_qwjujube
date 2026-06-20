__int64 __fastcall cam_context_dump_hw_acq_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 *v8; // x9
  void (__fastcall *v10)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v11; // x10
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h]
  __int64 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  if ( a1 )
  {
    v8 = *(__int64 **)(a1 + 208);
    if ( v8 )
    {
      v10 = (void (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v8[12];
      if ( v10 )
      {
        v11 = *(_QWORD *)(a1 + 264);
        LODWORD(v15) = 5;
        v14 = v11;
        v12 = *v8;
        if ( *((_DWORD *)v10 - 1) != 1863972096 )
          __break(0x8228u);
        v10(v12, &v14, a3, a4, a5, a6, a1, a8, v14, v15, v16, v17);
      }
      result = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_dump_hw_acq_info",
        1532,
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
      "cam_context_dump_hw_acq_info",
      1525,
      "Invalid input params");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
