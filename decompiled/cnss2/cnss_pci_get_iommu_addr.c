__int64 __fastcall cnss_pci_get_iommu_addr(__int64 *a1)
{
  __int64 v2; // x20
  __int64 node_by_name; // x0
  unsigned __int64 property; // x0
  __int64 v5; // x8
  unsigned __int64 v6; // x21
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v13 = 0;
  node_by_name = of_find_node_by_name(*(_QWORD *)(v2 + 944), "cnss_pci0_iommu_region_partition");
  if ( node_by_name
    && (property = of_get_property(node_by_name, "iommu-addresses", &v13)) != 0
    && (v5 = v13, a1[35] = 0, v5 &= 0xFFFFFFFFFFFFFFFCLL, v6 = property + v5, property < property + v5) )
  {
    do
    {
      while ( 1 )
      {
        v9 = *(_QWORD *)(v2 + 944);
        v11 = 0;
        v12 = 0;
        property = of_translate_dma_region(v9, property + 4, &v12, &v11);
        v10 = a1[35];
        if ( !v10 )
          break;
        a1[36] = v12 - v10;
        if ( property >= v6 )
          goto LABEL_11;
      }
      v8 = v11;
      a1[35] = v11;
    }
    while ( property < v6 );
    if ( !v8 )
      goto LABEL_4;
LABEL_11:
    if ( a1[36] )
      result = 0;
    else
      result = 4294967274LL;
  }
  else
  {
LABEL_4:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
