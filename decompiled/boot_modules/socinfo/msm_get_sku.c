__int64 __fastcall msm_get_sku(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v4; // x2

  if ( sku )
    v4 = (const char *)sku;
  else
    v4 = "Unknown";
  return (int)sysfs_emit(a3, "%s\n", v4);
}
