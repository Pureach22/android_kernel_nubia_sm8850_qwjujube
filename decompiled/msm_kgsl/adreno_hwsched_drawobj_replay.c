__int64 __fastcall adreno_hwsched_drawobj_replay(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned int v7; // w8
  unsigned int v8; // w9
  unsigned int v10; // w8
  unsigned int v11; // w9
  bool v12; // cf
  unsigned int v13; // w8

  v2 = *(_QWORD *)(a2 + 8);
  if ( (*(_BYTE *)(a2 + 16) & 4) != 0 )
  {
    if ( !v2
      || (*(_QWORD *)(v2 + 32) & 2) != 0
      || (*(_QWORD *)(v2 + 32) & 4) != 0
      || (v6 = *(_QWORD *)(v2 + 1648), v7 = *(_DWORD *)(a2 + 20), v8 = *(_DWORD *)(v6 + 16), v7 == v8)
      || (v7 <= v8 || ((v7 - v8) & 0x80000000) != 0)
      && ((v10 = v7 ^ 0x80000000, v11 = v8 ^ 0x80000000, v12 = v10 >= v11, v13 = v10 - v11, v13 == 0 || !v12)
       || v13 >= 0x80000001) )
    {
      adreno_hwsched_hw_syncobj_destroy(a2);
      return 0;
    }
  }
  else if ( (kgsl_check_timestamp(a1, *(_QWORD *)(a2 + 8), *(unsigned int *)(a2 + 20)) & 1) != 0
         || (v5 = *(_QWORD *)(a2 + 8)) == 0
         || (*(_QWORD *)(v5 + 32) & 2) != 0
         || (*(_QWORD *)(v5 + 32) & 4) != 0 )
  {
    adreno_hwsched_retire_cmdobj(a1 + 20904, a2);
    return 0;
  }
  return 1;
}
