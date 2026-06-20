__int64 __fastcall dsi_ctrl_transfer_unprepare(__int64 result, int a2)
{
  __int16 v2; // w19
  __int64 v3; // x20
  __int64 v4; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v2 = a2;
    *(_DWORD *)(result + 2920) = a2;
    if ( (a2 & 0x40) != 0 )
    {
      v3 = result;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_ctrl_transfer_unprepare",
        3780,
        -1,
        4369,
        *(_DWORD *)(result + 8),
        a2,
        -1059143953,
        vars0);
      if ( (v2 & 0x200) != 0 )
      {
        v4 = *(_QWORD *)(v3 + 2840);
        *(_BYTE *)(v3 + 2848) = 1;
        return queue_work_on(32, v4, v3 + 2808);
      }
      else
      {
        *(_BYTE *)(v3 + 2848) = 0;
        return dsi_ctrl_post_cmd_transfer(v3);
      }
    }
  }
  return result;
}
