__int64 __fastcall cam_icp_mgr_flush_info_dump(__int64 result, int a2)
{
  unsigned int v2; // w9
  __int16 v3; // w8
  int v4; // w10
  unsigned int i; // w24
  int v6; // w21
  __int64 v7; // x25
  unsigned int v8; // w9
  __int16 v9; // w8
  int v10; // w10
  unsigned int j; // w24
  int v12; // w21
  __int64 v13; // x25

  v2 = *(_DWORD *)(result + 24);
  if ( v2 )
  {
    v3 = debug_mdl;
    v4 = debug_priority;
    for ( i = 0; i < v2; ++i )
    {
      if ( (v3 & 0x100) != 0 && !v4 )
      {
        v6 = a2;
        v7 = result;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v3 & 0x100,
          4,
          "cam_icp_mgr_flush_info_dump",
          7661,
          "Flushing active request %lld in ctx %u",
          **(_QWORD **)(*(_QWORD *)(result + 32) + 8LL * (int)i),
          a2);
        v3 = debug_mdl;
        v4 = debug_priority;
        result = v7;
        v2 = *(_DWORD *)(v7 + 24);
        a2 = v6;
      }
    }
  }
  v8 = *(_DWORD *)(result + 8);
  if ( v8 )
  {
    v9 = debug_mdl;
    v10 = debug_priority;
    for ( j = 0; j < v8; ++j )
    {
      if ( (v9 & 0x100) != 0 && !v10 )
      {
        v12 = a2;
        v13 = result;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v9 & 0x100,
          4,
          "cam_icp_mgr_flush_info_dump",
          7667,
          "Flushing pending request %lld in ctx %u",
          **(_QWORD **)(*(_QWORD *)(result + 16) + 8LL * (int)j),
          a2);
        v9 = debug_mdl;
        v10 = debug_priority;
        result = v13;
        v8 = *(_DWORD *)(v13 + 8);
        a2 = v12;
      }
    }
  }
  return result;
}
