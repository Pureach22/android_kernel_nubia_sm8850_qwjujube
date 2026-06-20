__int64 __fastcall cam_soc_bus_client_update_request(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x10
  __int64 v4; // x9
  _QWORD *v5; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x11
  __int64 result; // x0
  const char **v10; // x8
  unsigned int v11; // w20
  unsigned __int64 v12; // [xsp+18h] [xbp-18h]
  unsigned __int64 v13; // [xsp+20h] [xbp-10h]
  _QWORD *v14; // [xsp+28h] [xbp-8h]

  if ( (debug_bypass_drivers & 0x10) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_soc_bus_client_update_request",
      130,
      "Bypass icc set bw");
    return 0;
  }
  else
  {
    v2 = a1[1];
    if ( *(_DWORD *)(v2 + 20) <= a2 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_bus_client_update_request",
        136,
        "Invalid vote level=%d, usecases=%d",
        a2);
      return 4294967274LL;
    }
    else if ( a2 >= 9 )
    {
      __break(0x5512u);
      return ((__int64 (*)(void))cam_wrapper_icc_set_bw)();
    }
    else
    {
      v4 = v2 + 16LL * a2;
      v5 = (_QWORD *)*a1;
      v8 = *(_QWORD *)(v4 + 24);
      v7 = *(_QWORD *)(v4 + 32);
      if ( (debug_mdl & 0x2020000) != 0 && !debug_priority )
      {
        v14 = (_QWORD *)*a1;
        v12 = v7;
        v13 = v8;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2020000,
          4,
          "cam_soc_bus_client_update_request",
          145,
          "Bus client=[%s] index[%d] ab[%llu] ib[%llu]",
          *(const char **)v2,
          a2,
          v8,
          v7);
        v8 = v13;
        v5 = v14;
        v7 = v12;
      }
      result = cam_wrapper_icc_set_bw(*v5, v8 / 0x3E8, v7 / 0x3E8);
      if ( (_DWORD)result )
      {
        v10 = (const char **)a1[1];
        v11 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_bus_client_update_request",
          163,
          "Update request failed, client[%s], idx: %d",
          *v10,
          a2);
        return v11;
      }
    }
  }
  return result;
}
