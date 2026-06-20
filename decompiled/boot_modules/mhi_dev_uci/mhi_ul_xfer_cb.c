__int64 __fastcall mhi_ul_xfer_cb(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 192);
  if ( *(_QWORD *)(v2 + 352) && !*(_DWORD *)(v2 + 360) )
    ipc_log_string();
  result = kfree(*(_QWORD *)a2);
  if ( !*(_DWORD *)(a2 + 20) )
    return _wake_up(v2 + 96, 3, 1, 0);
  return result;
}
