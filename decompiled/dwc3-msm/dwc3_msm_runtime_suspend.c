__int64 __fastcall dwc3_msm_runtime_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x20

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 40);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 168);
    dwc3_dbg_print(*(_QWORD *)(v1 + 1256), 0xFFu, "RT Sus", 0, (const char *)&unk_16A05);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 368);
      device_wakeup_disable(v4);
      device_set_wakeup_capable(v4, 0);
    }
  }
  else
  {
    dwc3_dbg_print(*(_QWORD *)(v1 + 1256), 0xFFu, "RT Sus", 0, (const char *)&unk_16A05);
  }
  return dwc3_msm_suspend(v1, 0);
}
