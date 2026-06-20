__int64 __fastcall iommu_debug_dma_map_read(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  int v11; // w0
  __int64 v12; // [xsp+8h] [xbp-78h] BYREF
  _QWORD v13[12]; // [xsp+10h] [xbp-70h] BYREF
  int v14; // [xsp+70h] [xbp-10h]
  __int64 v15; // [xsp+78h] [xbp-8h]

  result = 0;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a4;
  v7 = *(_QWORD *)(a1 + 32);
  v14 = 0;
  memset(v13, 0, sizeof(v13));
  if ( !v6 )
  {
    v12 = *(_QWORD *)(v7 + 136);
    v11 = scnprintf(v13, 100, "%pa\n", &v12);
    result = simple_read_from_buffer(a2, a3, a4, v13, v11);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
