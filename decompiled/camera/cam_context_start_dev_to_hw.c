__int64 __fastcall cam_context_start_dev_to_hw(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 *v8; // x9
  _DWORD *v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  unsigned int v12; // w20
  _QWORD v13[4]; // [xsp+10h] [xbp-20h] BYREF

  v13[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[1] = 0;
  v13[2] = 0;
  if ( a1 && a2 )
  {
    v8 = *(__int64 **)(a1 + 208);
    if ( v8 )
    {
      if ( *(_QWORD *)a2 == *(_QWORD *)(a1 + 56) )
      {
        v9 = (_DWORD *)v8[5];
        if ( v9 )
        {
          v13[0] = *(_QWORD *)(a1 + 264);
          v10 = *v8;
          if ( *(v9 - 1) != 1863972096 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, _DWORD *))v9)(
                     v10,
                     v13,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a2);
          if ( (_DWORD)result )
          {
            v12 = result;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x80000,
              1,
              "cam_context_start_dev_to_hw",
              1282,
              "[%s][%d] Start HW failed",
              (const char *)a1,
              *(_DWORD *)(a1 + 32));
            result = v12;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          1,
          "cam_context_start_dev_to_hw",
          1270,
          "[%s][%d] Invalid session hdl[%d], dev_handle[%d]",
          (const char *)a1,
          *(_DWORD *)(a1 + 32),
          *a2,
          a2[1]);
        result = 0xFFFFFFFFLL;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_start_dev_to_hw",
        1260,
        "[%s][%d] HW interface is not ready",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      result = 4294967282LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_start_dev_to_hw",
      1253,
      "Invalid input params %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
