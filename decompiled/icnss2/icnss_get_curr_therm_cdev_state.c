__int64 __fastcall icnss_get_curr_therm_cdev_state(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v3; // x21
  __int64 *v6; // x23

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 5544);
  v6 = (__int64 *)(v3 + 5528);
  while ( 1 )
  {
    v6 = (__int64 *)*v6;
    if ( v6 == (__int64 *)(v3 + 5528) )
      break;
    if ( *((_DWORD *)v6 + 4) == a3 )
    {
      *a2 = v6[3];
      mutex_unlock(v3 + 5544);
      ipc_log_string(icnss_ipc_log_context, "icnss2: Cooling device current state: %ld, for cdev id %d", v6[3], a3);
      return 0;
    }
  }
  mutex_unlock(v3 + 5544);
  ipc_log_string(icnss_ipc_log_context, "icnss2: Cooling device ID not found: %d", a3);
  return 4294967274LL;
}
