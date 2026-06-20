__int64 __fastcall adreno_snapshot_gmu_versions(_DWORD *a1, __int64 a2)
{
  int v4; // w9
  int v5; // w9
  int v6; // w9
  int v7; // w9
  int v8; // w9
  __int64 result; // x0
  _DWORD v10[2]; // [xsp+0h] [xbp-30h] BYREF
  _DWORD v11[2]; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v12[2]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v13[2]; // [xsp+18h] [xbp-18h] BYREF
  _DWORD v14[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[2066];
  v10[0] = 15;
  v10[1] = v4;
  v5 = a1[2067];
  v11[0] = 16;
  v11[1] = v5;
  v6 = a1[2068];
  v12[0] = 17;
  v12[1] = v6;
  v7 = a1[2069];
  v13[0] = 18;
  v13[1] = v7;
  v8 = a1[2070];
  v14[0] = 19;
  v14[1] = v8;
  kgsl_snapshot_add_section(a1, 2305, a2, snapshot_gmu_version, v10);
  kgsl_snapshot_add_section(a1, 2305, a2, snapshot_gmu_version, v11);
  kgsl_snapshot_add_section(a1, 2305, a2, snapshot_gmu_version, v12);
  kgsl_snapshot_add_section(a1, 2305, a2, snapshot_gmu_version, v13);
  result = kgsl_snapshot_add_section(a1, 2305, a2, snapshot_gmu_version, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
