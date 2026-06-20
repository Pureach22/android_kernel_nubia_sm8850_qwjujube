__int64 __fastcall dsi_phy_supplies_deinit(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w22
  __int64 v3; // x0
  unsigned int v4; // w22
  __int64 v5; // x0

  v1 = result;
  if ( *(_DWORD *)(result + 792) )
  {
    v2 = 0;
    do
    {
      v3 = *(_QWORD *)(*(_QWORD *)(v1 + 784) + 80LL * (int)v2);
      if ( v3 )
        result = devm_regulator_put(v3);
      else
        result = drm_dev_printk(
                   0,
                   &unk_248D72,
                   "*ERROR* [msm-dsi-error]: DSI_%d: vreg is NULL, should not reach here\n",
                   *(_DWORD *)(v1 + 8));
      ++v2;
    }
    while ( v2 < *(_DWORD *)(v1 + 792) );
  }
  if ( *(_DWORD *)(v1 + 808) )
  {
    v4 = 0;
    do
    {
      v5 = *(_QWORD *)(*(_QWORD *)(v1 + 800) + 80LL * (int)v4);
      if ( v5 )
        result = devm_regulator_put(v5);
      else
        result = drm_dev_printk(
                   0,
                   &unk_248D72,
                   "*ERROR* [msm-dsi-error]: DSI_%d: vreg is NULL, should not reach here\n",
                   *(_DWORD *)(v1 + 8));
      ++v4;
    }
    while ( v4 < *(_DWORD *)(v1 + 808) );
  }
  if ( *(_QWORD *)(v1 + 800) )
  {
    result = devm_kfree(*(_QWORD *)v1 + 16LL);
    *(_QWORD *)(v1 + 800) = 0;
    *(_DWORD *)(v1 + 808) = 0;
  }
  if ( *(_QWORD *)(v1 + 784) )
  {
    result = devm_kfree(*(_QWORD *)v1 + 16LL);
    *(_QWORD *)(v1 + 784) = 0;
    *(_DWORD *)(v1 + 792) = 0;
  }
  return result;
}
