__int64 __fastcall sde_encoder_vhm_wakelock(
        __int64 result,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  char v8; // w29
  __int64 v9; // x8
  int v10; // w4
  __int64 v11; // x19

  if ( *(_BYTE *)(result + 749) == 1 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)result + 56LL);
    v10 = *(_DWORD *)(result + 4916);
    if ( *(_QWORD *)(*(_QWORD *)(v9 + 8) + 2128LL) )
    {
      return sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_vhm_wakelock", 2277, -1, v10, a2 & 1, -1059143953, a8, v8);
    }
    else if ( (a2 & 1) == 0 || v10 )
    {
      if ( (a2 & 1) == 0 && v10 == 1 )
      {
        v11 = result;
        result = sde_power_wakelock_ctrl(v9 + 16, 0);
        *(_DWORD *)(v11 + 4916) = 0;
      }
    }
    else
    {
      *(_DWORD *)(result + 4916) = 1;
      return sde_power_wakelock_ctrl(v9 + 16, 1);
    }
  }
  return result;
}
