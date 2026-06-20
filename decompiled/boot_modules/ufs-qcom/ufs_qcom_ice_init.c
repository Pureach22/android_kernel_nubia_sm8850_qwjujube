__int64 __fastcall ufs_qcom_ice_init(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  unsigned int v5; // w8

  v1 = *(_QWORD *)(a1 + 16);
  v3 = *(_QWORD *)(v1 + 64);
  v4 = of_qcom_ice_get(v3);
  if ( v4 == -95 )
  {
    dev_warn(v3, "Disabling inline encryption support\n");
    return 0;
  }
  else if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 152) = v4;
    v5 = 0;
    *(_DWORD *)(v1 + 3000) |= 0x100u;
  }
  else if ( v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    return 0;
  }
  else
  {
    return (unsigned int)v4;
  }
  return v5;
}
