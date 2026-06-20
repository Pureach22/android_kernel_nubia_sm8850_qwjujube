__int64 __fastcall qsmmuv500_init_cb(__int64 *a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x3
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v9)(_QWORD); // x8

  v3 = *a1;
  result = iommu_group_get_iommudata(*(_QWORD *)(a2 + 816));
  if ( *(_BYTE *)result == 1 )
  {
    v5 = *(_QWORD *)(v3 + 48);
    v6 = *(unsigned int *)(result + 4);
    v7 = *(_DWORD *)(v3 + 24) + (unsigned int)*((unsigned __int8 *)a1 + 48);
    if ( v5 && (v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v5 + 8)) != nullptr )
    {
      if ( *((_DWORD *)v8 - 1) != -1008624849 )
        __break(0x8228u);
      result = v8(v3, v7, 4, v6);
    }
    else
    {
      result = writel_relaxed_1(
                 v6,
                 (unsigned int *)(*(_QWORD *)(v3 + 8) + (int)((_DWORD)v7 << *(_DWORD *)(v3 + 28)) + 4LL));
    }
    v9 = *(__int64 (__fastcall **)(_QWORD))(a1[24] + 32);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != -1056074712 )
        __break(0x8228u);
      return v9(a1 + 23);
    }
  }
  return result;
}
