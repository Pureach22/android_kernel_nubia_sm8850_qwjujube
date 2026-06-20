__int64 __fastcall arm_smmu_capable(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  unsigned int v4; // w8

  v2 = *(_QWORD *)(a1 + 824);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 72);
  else
    v3 = 0;
  v4 = 1;
  if ( (_DWORD)a2 == 4 || (_DWORD)a2 == 1 )
    return v4;
  if ( (_DWORD)a2 )
    return 0;
  return (*(_BYTE *)(*(_QWORD *)v3 + 32LL) & 1) != 0 || (unsigned int)device_get_dma_attr(a1, a2) == 2;
}
