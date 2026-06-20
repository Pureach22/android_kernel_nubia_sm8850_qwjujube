__int64 __fastcall wcd_usbss_mux_set(__int64 a1, __int64 a2)
{
  __int64 drvdata; // x0
  __int64 v4; // x8
  __int64 v5; // x9
  int v6; // w9
  __int64 v8; // x19

  drvdata = typec_mux_get_drvdata();
  if ( !drvdata )
    return 4294967274LL;
  v4 = *(_QWORD *)(drvdata + 8);
  if ( !v4 )
    return 4294967274LL;
  v5 = *(_QWORD *)(a2 + 8);
  if ( v5 == 5 )
  {
    v6 = 1;
LABEL_8:
    if ( *(_DWORD *)(drvdata + 32) != v6 )
    {
      *(_DWORD *)(drvdata + 32) = v6;
      v8 = drvdata;
      pm_stay_awake(v4);
      queue_work_on(32, system_freezable_wq, v8 + 40);
    }
    return 0;
  }
  if ( v5 != 6 )
  {
    v6 = 0;
    goto LABEL_8;
  }
  return 0;
}
