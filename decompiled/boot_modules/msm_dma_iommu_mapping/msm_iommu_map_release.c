__int64 __fastcall msm_iommu_map_release(__int64 a1)
{
  __int64 *v1; // x19
  __int64 v2; // x10
  _QWORD *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x4
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v1 = (__int64 *)(a1 - 72);
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 24);
  v3 = *(_QWORD **)(a1 - 64);
  v9 = *(_DWORD *)(a1 - 16);
  v10 = v9;
  v8 = v2;
  if ( *v3 == a1 - 72 && (v4 = *v1, *(__int64 **)(*v1 + 8) == v1) )
  {
    *(_QWORD *)(v4 + 8) = v3;
    *v3 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 - 72);
    a1 = v7;
  }
  v5 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(a1 - 72) = 0xDEAD000000000100LL;
  *(_QWORD *)(a1 - 64) = 0xDEAD000000000122LL;
  if ( (v5 & 0x20) == 0 )
    *(_QWORD *)(a1 + 8) = v5 | 0x20;
  dma_unmap_sg_attrs(*(_QWORD *)(a1 - 32), *(_QWORD *)(a1 - 24), *(unsigned int *)(a1 - 16), *(unsigned int *)(a1 - 12));
  sg_free_table(&v8);
  result = kfree(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
