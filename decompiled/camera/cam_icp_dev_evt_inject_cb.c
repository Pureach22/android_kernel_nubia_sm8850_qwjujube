__int64 __fastcall cam_icp_dev_evt_inject_cb(__int64 a1)
{
  int v1; // w6
  __int64 v2; // x9
  __int64 i; // x8

  v1 = *(_DWORD *)(a1 + 48);
  v2 = 54;
  for ( i = g_icp_dev[0] + 480; *(_DWORD *)(i + 60) != v1; i += 552 )
  {
    if ( !--v2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_dev_evt_inject_cb",
        85,
        "No dev hdl found %d",
        v1);
      return 4294967277LL;
    }
  }
  cam_context_add_evt_inject(i, a1 + 16);
  return 0;
}
