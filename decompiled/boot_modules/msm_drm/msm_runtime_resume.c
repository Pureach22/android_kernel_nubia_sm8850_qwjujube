__int64 __fastcall msm_runtime_resume(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 56LL);
  _drm_dev_dbg(0, 0, 1, "\n");
  if ( *(_QWORD *)(v1 + 536) || *(_DWORD *)(v1 + 5912) )
    return 0;
  else
    return sde_power_resource_enable(v1 + 16, 1);
}
