__int64 __fastcall sde_crtc_cancel_delayed_work(__int64 result)
{
  __int64 v1; // x19
  char v2; // w0
  int v3; // w7
  char v4; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    if ( *(_QWORD *)(result + 2008) )
    {
      v1 = result;
      v2 = kthread_cancel_delayed_work_sync(result + 7776);
      return sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_crtc_cancel_delayed_work",
               9237,
               -1,
               *(_DWORD *)(v1 + 112),
               v2 & 1,
               -1059143953,
               v3,
               v4);
    }
  }
  return result;
}
