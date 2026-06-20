__int64 __fastcall qcom_ice_probe(__int64 a1)
{
  unsigned __int64 v2; // x19
  unsigned __int64 v3; // x0

  v2 = devm_platform_ioremap_resource(a1, 0);
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_warn(a1 + 16, "ICE registers not found\n");
  }
  else
  {
    v3 = qcom_ice_create(a1 + 16, v2);
    LODWORD(v2) = v3;
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 168) = v3;
      LODWORD(v2) = 0;
    }
  }
  return (unsigned int)v2;
}
