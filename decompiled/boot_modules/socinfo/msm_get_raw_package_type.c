__int64 __fastcall msm_get_raw_package_type(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w2

  if ( socinfo )
    v4 = *(_DWORD *)(socinfo + 216);
  else
    v4 = 0;
  return (int)sysfs_emit(a3, "0x%x\n", v4);
}
