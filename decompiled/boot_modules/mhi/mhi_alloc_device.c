__int64 __fastcall mhi_alloc_device(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x8

  v2 = _kmalloc_cache_noprof(release_firmware, 3520, 984);
  if ( !v2 )
    return -12;
  v3 = v2;
  device_initialize(v2 + 40);
  v4 = *(_QWORD *)(a1 + 16);
  result = v3;
  *(_QWORD *)(v3 + 168) = mhi_bus_type;
  *(_QWORD *)(v3 + 848) = mhi_release_device;
  if ( v4 )
    v6 = v4 + 40;
  else
    v6 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(v3 + 136) = v6;
  *(_QWORD *)(v3 + 16) = a1;
  *(_DWORD *)(v3 + 972) = 0;
  return result;
}
