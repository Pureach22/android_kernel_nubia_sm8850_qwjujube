__int64 __fastcall cam_cdm_stream_on(unsigned int a1)
{
  __int64 result; // x0
  int v3; // w6
  __int64 v4; // x9
  __int64 (__fastcall *v5)(__int64, int *, __int64); // x8
  __int64 v6; // x0
  unsigned int v7; // w19
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1;
  if ( (unsigned int)get_cdm_mgr_refcount() )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_stream_on",
      325,
      "CDM intf mgr get refcount failed");
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v3 = HIWORD(a1) & 0xF;
    v4 = *(_QWORD *)&cdm_mgr[72 * v3 + 72];
    if ( v4 && (v5 = *(__int64 (__fastcall **)(__int64, int *, __int64))(v4 + 56)) != nullptr )
    {
      v6 = *(_QWORD *)(v4 + 112);
      if ( *((_DWORD *)v5 - 1) != 1989616049 )
        __break(0x8228u);
      v7 = v5(v6, &v8, 4);
      if ( (v7 & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_stream_on",
          339,
          "hw start failed handle=%x",
          v8);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_stream_on",
        343,
        "hw idx %d doesn't have start ops",
        v3);
      v7 = -22;
    }
    put_cdm_mgr_refcount();
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
