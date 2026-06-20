__int64 __fastcall cam_ife_mgr_cmd_get_last_consumed_addr(__int64 a1, int *a2)
{
  int v2; // w6
  __int64 v3; // x8
  __int64 **v4; // x8
  __int64 *i; // x9
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64, int *, __int64); // x9
  __int64 v9; // x0

  v2 = *a2;
  if ( *a2 == 2 )
  {
    v3 = 224;
  }
  else
  {
    if ( v2 != 7 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_cmd_get_last_consumed_addr",
        16417,
        "invalid hw_type:%d",
        v2);
      return 4294967274LL;
    }
    v3 = 240;
  }
  v4 = (__int64 **)(a1 + v3);
  for ( i = *v4; i != (__int64 *)v4; i = (__int64 *)*i )
  {
    if ( *((_DWORD *)i + 4) )
    {
      v6 = i[4];
      if ( v6 || (v6 = i[5]) != 0 )
      {
        v7 = *(_QWORD *)(v6 + 16);
        v8 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v7 + 88);
        v9 = *(_QWORD *)(v7 + 112);
        if ( *((_DWORD *)v8 - 1) != -1055839300 )
          __break(0x8229u);
        return v8(v9, 37, a2, 32);
      }
    }
  }
  return 4294967274LL;
}
