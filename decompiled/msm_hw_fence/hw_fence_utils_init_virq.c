__int64 __fastcall hw_fence_utils_init_virq(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x19
  __int64 compatible_node; // x0
  unsigned int variable_u32_array; // w0
  __int64 v6; // x4
  unsigned __int64 v7; // x0
  __int64 v8; // x4
  unsigned int v9; // w19
  __int64 v11; // x30
  __int64 v12; // x30

  v3 = v1;
  compatible_node = of_find_compatible_node(*(_QWORD *)(*(_QWORD *)a1 + 744LL), 0, "qcom,msm-hw-fence-db");
  if ( compatible_node )
  {
    variable_u32_array = of_property_read_variable_u32_array(compatible_node, "gunyah-label", a1 + 468, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v11 = v3;
      v9 = variable_u32_array;
      printk(&unk_20C86, "hw_fence_utils_init_virq", 566, v11, variable_u32_array);
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
        printk(&unk_2AF47, "hw_fence_utils_init_virq", 570, *(unsigned int *)(a1 + 468), v6);
      v7 = gh_dbl_rx_register(*(unsigned int *)(a1 + 468), hw_fence_cb, a1);
      *(_QWORD *)(a1 + 472) = v7;
      if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
      {
        return 0;
      }
      else
      {
        v12 = v3;
        v9 = v7;
        printk(&unk_2B461, "hw_fence_utils_init_virq", 574, v12, v8);
      }
    }
  }
  else
  {
    printk(&unk_24584, "hw_fence_utils_init_virq", 560, v3, "qcom,msm-hw-fence-db");
    return (unsigned int)-22;
  }
  return v9;
}
