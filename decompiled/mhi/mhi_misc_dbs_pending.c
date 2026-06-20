__int64 __fastcall mhi_misc_dbs_pending(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x8

  v1 = *(_QWORD *)(*(_QWORD *)(result + 16) + 192LL);
  if ( *(_QWORD *)(v1 + 72) && *(_DWORD *)(v1 + 92) )
  {
    v2 = result;
    result = mhi_write_reg(result);
    v3 = *(_QWORD *)(*(_QWORD *)(v2 + 16) + 192LL);
    if ( v3 )
    {
      if ( !*(_DWORD *)(v3 + 24) )
        result = ipc_log_string(
                   *(_QWORD *)(v3 + 32),
                   "[D][%s] Completed BW response: %d\n",
                   "mhi_misc_dbs_pending",
                   *(_DWORD *)(v3 + 92));
    }
    *(_DWORD *)(v1 + 92) = 0;
  }
  return result;
}
