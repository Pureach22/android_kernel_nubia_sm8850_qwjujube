__int64 __fastcall snapshot_context_queue(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  int v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 288) == 1 )
  {
    v3 = *(_QWORD *)(a2 + 40);
    v5 = a2 + 1640;
    v7 = 0;
    v6 = 6;
    kgsl_snapshot_add_section(v3, 5889, a3, adreno_snapshot_gmu_mem, &v5);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
