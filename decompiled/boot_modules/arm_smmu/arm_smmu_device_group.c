unsigned __int64 __fastcall arm_smmu_device_group(__int64 a1)
{
  __int64 v2; // x8
  __int64 *v3; // x23
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x8
  unsigned __int64 v9; // x20
  int v10; // w8
  __int64 v11; // x9
  int v12; // w13
  __int64 v13; // x12
  _QWORD *v14; // x10
  __int64 v15; // x14
  unsigned __int64 v17; // x0
  __int64 v18; // x8
  unsigned int (__fastcall *v19)(__int64, unsigned __int64); // x8
  unsigned int v20; // w8
  int v21; // w11
  __int64 v23; // [xsp+8h] [xbp-68h] BYREF
  unsigned __int64 v24; // [xsp+10h] [xbp-60h]
  _QWORD v25[11]; // [xsp+18h] [xbp-58h] BYREF

  v25[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 824);
  if ( v2 )
  {
    v3 = *(__int64 **)(v2 + 72);
    v4 = *(_QWORD *)(v2 + 56);
  }
  else
  {
    v3 = nullptr;
    v4 = 0;
  }
  v5 = *v3;
  mutex_lock(*v3 + 120);
  v6 = *(_QWORD *)(a1 + 744);
  v23 = 0;
  v24 = 0;
  memset(v25, 0, 80);
  v7 = _of_parse_phandle_with_args(v6, "qcom,iommu-group", 0, 0, 0, v25);
  v8 = v25[0];
  if ( v7 )
    v8 = 0;
  v23 = v8;
  if ( v8 )
  {
    if ( (int)bus_for_each_dev(&platform_bus_type, 0, &v23, _bus_lookup_iommu_group) >= 1
      || (int)bus_for_each_dev(&pci_bus_type, 0, &v23, _bus_lookup_iommu_group) >= 1 )
    {
      v9 = v24;
      goto LABEL_10;
    }
    v9 = generic_device_group(a1);
    if ( v9 < 0xFFFFFFFFFFFFF001LL )
    {
LABEL_10:
      if ( v9 )
        goto LABEL_27;
    }
  }
  v10 = *(_DWORD *)(v4 + 12);
  if ( !v10 )
    goto LABEL_22;
  v12 = 0;
  v13 = 0;
  v14 = v3 + 1;
  do
  {
    v15 = 24LL * *((__int16 *)v14 + v12);
    v11 = *(_QWORD *)(v5 + 112);
    v9 = *(_QWORD *)(v11 + v15);
    if ( v13 )
    {
      if ( v9 && v13 != v9 )
      {
        dev_err(a1, "ID:%x IDX:%x is already in a group!\n", *(_DWORD *)(v4 + 4LL * v12 + 16), *((__int16 *)v14 + v12));
        v9 = -22;
        goto LABEL_37;
      }
    }
    ++v12;
    v13 = *(_QWORD *)(v11 + v15);
  }
  while ( v10 != v12 );
  if ( v9 )
  {
    iommu_group_ref_get(*(_QWORD *)(v11 + v15));
  }
  else
  {
LABEL_22:
    if ( *(_UNKNOWN **)(a1 + 128) == &pci_bus_type )
      v17 = pci_device_group(a1);
    else
      v17 = generic_device_group(a1);
    v9 = v17;
    if ( v17 > 0xFFFFFFFFFFFFF000LL )
    {
      v9 = 0;
      goto LABEL_37;
    }
  }
LABEL_27:
  if ( v9 <= 0xFFFFFFFFFFFFF000LL )
  {
    v18 = *(_QWORD *)(v5 + 48);
    if ( !v18 )
      goto LABEL_42;
    v19 = *(unsigned int (__fastcall **)(__int64, unsigned __int64))(v18 + 88);
    if ( !v19 )
      goto LABEL_42;
    if ( *((_DWORD *)v19 - 1) != 1874222070 )
      __break(0x8228u);
    if ( v19(a1, v9) )
    {
      iommu_group_put(v9);
      v9 = -22;
    }
    else
    {
LABEL_42:
      if ( *(_DWORD *)(v4 + 12) )
      {
        v20 = 0;
        do
        {
          v21 = *((__int16 *)v3 + (int)v20++ + 4);
          *(_QWORD *)(*(_QWORD *)(v5 + 112) + 24LL * v21) = v9;
        }
        while ( v20 < *(_DWORD *)(v4 + 12) );
      }
    }
  }
LABEL_37:
  mutex_unlock(v5 + 120);
  _ReadStatusReg(SP_EL0);
  return v9;
}
