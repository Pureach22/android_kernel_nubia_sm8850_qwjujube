__int64 __fastcall cam_context_dump_pf_info_to_hw(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 *v9; // x9
  void (__fastcall *v10)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *, __int64); // x8
  __int64 v11; // x10
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-30h] BYREF
  __int64 v15; // [xsp+8h] [xbp-28h]
  __int64 v16; // [xsp+10h] [xbp-20h] BYREF
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 *v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = nullptr;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  if ( a1 )
  {
    v9 = *(__int64 **)(a1 + 208);
    if ( v9 )
    {
      v10 = (void (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 *, __int64))v9[12];
      if ( v10 )
      {
        v11 = *(_QWORD *)(a1 + 264);
        v14 = a2;
        v15 = a3;
        LODWORD(v17) = 1;
        v16 = v11;
        v18 = &v14;
        v12 = *v9;
        if ( *((_DWORD *)v10 - 1) != 1863972096 )
          __break(0x8228u);
        v10(v12, &v16, a3, a4, a5, a6, a1, a8, v14, v15, v16, v17, v18, v19);
      }
      result = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        1,
        "cam_context_dump_pf_info_to_hw",
        1500,
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
      "cam_context_dump_pf_info_to_hw",
      1493,
      "Invalid input params %pK ",
      nullptr);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
