__int64 __fastcall gen7_gmu_version_info(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w2
  unsigned int v4; // w3
  __int64 v6; // x10

  v1 = *(_QWORD *)(a1 + 14264);
  gmu_core_regread(a1, 119800, a1 + 8264);
  gmu_core_regread(a1, 119801, a1 + 8268);
  gmu_core_regread(a1, 119802, a1 + 8272);
  gmu_core_regread(a1, 119803, a1 + 8276);
  gmu_core_regread(a1, 119804, a1 + 8280);
  v3 = *(_DWORD *)(a1 + 8264);
  v4 = *(_DWORD *)(v1 + 88);
  if ( v3 >= v4 )
    return 0;
  if ( (gen7_gmu_version_info___print_once & 1) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 1544);
    gen7_gmu_version_info___print_once = 1;
    dev_err(v6 + 16, "GMU FW version 0x%x error (expected 0x%x)\n", v3, v4);
  }
  return 4294967274LL;
}
