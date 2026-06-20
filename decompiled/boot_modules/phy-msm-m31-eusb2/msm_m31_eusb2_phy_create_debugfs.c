__int64 __fastcall msm_m31_eusb2_phy_create_debugfs(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x0
  __int64 dir; // x0
  __int64 v5; // x2
  __int64 v6; // x2
  __int64 v7; // x2
  __int64 result; // x0

  v1 = *(__int64 **)a1;
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 112LL);
  if ( !v3 )
    v3 = *v1;
  dir = debugfs_create_dir(v3, 0);
  *(_QWORD *)(a1 + 544) = dir;
  debugfs_create_x8("xcfgi_39_32", 420, dir, a1 + 552);
  v5 = *(_QWORD *)(a1 + 544);
  *(_BYTE *)(a1 + 552) = -1;
  debugfs_create_x8("xcfgi_71_64", 420, v5, a1 + 553);
  v6 = *(_QWORD *)(a1 + 544);
  *(_BYTE *)(a1 + 553) = -1;
  debugfs_create_x8("xcfgi_31_24", 420, v6, a1 + 554);
  v7 = *(_QWORD *)(a1 + 544);
  *(_BYTE *)(a1 + 554) = -1;
  result = debugfs_create_x8("xcfgi_7_0", 420, v7, a1 + 555);
  *(_BYTE *)(a1 + 555) = -1;
  return result;
}
