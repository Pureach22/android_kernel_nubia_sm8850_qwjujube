__int64 __fastcall sde_cp_clear_state_info(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x21
  char v11; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v8 = result;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_cp_clear_state_info", 5416, -1, 4369, -1059143953, a7, a8, v11);
    v9 = -832;
    do
    {
      v10 = v8 + v9;
      result = kfree(*(_QWORD *)(v8 + v9 + 6904));
      v9 += 16;
      *(_QWORD *)(v10 + 6904) = 0;
      *(_DWORD *)(v10 + 6912) = 0;
    }
    while ( v9 );
  }
  return result;
}
