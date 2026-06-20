__int64 __fastcall kgsl_iommu_get_gpuaddr(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x21
  int v6; // w10
  bool v7; // zf
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x22
  __int64 v11; // x24
  __int64 v12; // x23
  __int64 result; // x0

  if ( !a2 )
  {
    v4 = 0xB3FF61CA7851BE11LL;
    goto LABEL_7;
  }
  v4 = *(_QWORD *)(a2 + 72);
  if ( (v4 & 0x10000000) != 0 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  if ( (v4 & 8) != 0 && *(_DWORD *)(a1 + 24) != 1 )
    return 4294967274LL;
LABEL_7:
  if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
    v5 = (*(_QWORD *)(a2 + 40) + 0x1FFFLL) & 0xFFFFFFFFFFFFF000LL;
  else
    v5 = *(_QWORD *)(a2 + 40);
  if ( (unsigned int)(1 << SBYTE2(v4)) <= 0x1000 )
    v6 = 4096;
  else
    v6 = 1 << SBYTE2(v4);
  v7 = (v4 & 0x100000000LL) == 0;
  v8 = 136;
  if ( v7 )
  {
    v9 = 128;
  }
  else
  {
    v8 = 168;
    v9 = 160;
  }
  v10 = v6;
  v11 = *(_QWORD *)(a1 + v8);
  v12 = *(_QWORD *)(a1 + v9);
  result = get_gpuaddr(a1, a2, v12, v11, v5, v6);
  if ( (_DWORD)result == -12 )
  {
    _flush_workqueue(qword_3A908);
    return get_gpuaddr(a1, a2, v12, v11, v5, v10);
  }
  return result;
}
