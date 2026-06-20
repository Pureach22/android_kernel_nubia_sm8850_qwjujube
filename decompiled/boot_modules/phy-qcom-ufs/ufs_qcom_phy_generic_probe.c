unsigned __int64 __fastcall ufs_qcom_phy_generic_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x19
  __int64 resource_byname; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x22
  __int64 v13; // x23
  unsigned int v14; // w0
  unsigned int v15; // w25
  __int64 v16; // x24
  __int64 v17; // x0
  unsigned int v19; // w24

  v8 = a1 + 16;
  resource_byname = platform_get_resource_byname();
  v10 = devm_ioremap_resource(v8, resource_byname);
  *(_QWORD *)(a2 + 24) = v10;
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    v19 = v10;
    *(_QWORD *)(a2 + 24) = 0;
    dev_err(v8, "%s: ioremap for phy_mem resource failed %d\n", "ufs_qcom_phy_base_init", v10);
    dev_err(v8, "%s: phy base init failed %d\n", "ufs_qcom_phy_generic_probe", v19);
    return 0;
  }
  v11 = _devm_of_phy_provider_register(v8, 0, &_this_module, &of_phy_simple_xlate);
  if ( v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v8, "%s: failed to register phy %d\n", "ufs_qcom_phy_generic_probe", v11);
    return 0;
  }
  v12 = devm_phy_create(v8, 0, a3);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v8, "%s: failed to create phy %d\n", "ufs_qcom_phy_generic_probe", (unsigned int)v12);
    return 0;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "lanes-per-direction", a2 + 352, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(a2 + 352) = 1;
  v13 = *(_QWORD *)(a1 + 760);
  v14 = of_property_count_elems_of_size(v13, "qcom,ufs-phy-bsp-tuning", 4);
  if ( (int)v14 >= 1 )
  {
    v15 = v14 / 3;
    if ( !(v14 % 3) )
    {
      v16 = v14;
      v17 = devm_kmalloc(v8, v14, 3520);
      *(_QWORD *)(a2 + 448) = v17;
      if ( v17 )
      {
        *(_DWORD *)(a2 + 440) = v15;
        of_property_read_variable_u32_array(v13, "qcom,ufs-phy-bsp-tuning", v17, v16, 0);
      }
    }
  }
  pm_runtime_no_callbacks(v12);
  *(_QWORD *)(a2 + 416) = a4;
  *(_QWORD *)(a2 + 16) = v8;
  *(_QWORD *)(a2 + 472) = a2 + 472;
  *(_QWORD *)(a2 + 480) = a2 + 472;
  return v12;
}
