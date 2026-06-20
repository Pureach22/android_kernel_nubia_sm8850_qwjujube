__int64 __fastcall sde_connector_complete_qsync_commit(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !result || !a2 )
    return printk(&unk_223EAA, "sde_connector_complete_qsync_commit");
  if ( *(_BYTE *)(result + 4680) == 1 && *(_DWORD *)(result + 4676) == 2 )
  {
    *(_DWORD *)(result + 4676) = 0;
    *(_DWORD *)a2 = 0;
    *(_BYTE *)(a2 + 4) = 1;
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_connector_complete_qsync_commit",
             1354,
             -1,
             *(_DWORD *)(result + 64),
             *(_DWORD *)(result + 4676),
             -1059143953,
             a8,
             vars0);
  }
  return result;
}
