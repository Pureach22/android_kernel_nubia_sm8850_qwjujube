__int64 __fastcall hw_fence_utils_map_ipcc(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 v4; // x8
  unsigned int variable_u32_array; // w0
  int v6; // w2
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  int v13; // w8
  __int64 result; // x0
  unsigned int v15; // w19
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = v1;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  v16[0] = 0;
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v4 + 744), "qcom,ipcc-reg", v16, 2, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v15 = variable_u32_array;
    printk(&unk_27A46, "hw_fence_utils_map_ipcc", 1844, v3, variable_u32_array);
    result = v15;
  }
  else
  {
    v6 = HIDWORD(v16[0]);
    v7 = *(_QWORD *)a1;
    *(_QWORD *)(a1 + 600) = LODWORD(v16[0]);
    *(_DWORD *)(a1 + 616) = v6;
    v8 = devm_ioremap(v7);
    if ( v8 )
    {
      v13 = msm_hw_fence_debug_level;
      *(_QWORD *)(a1 + 608) = v8;
      if ( (~v13 & 0x10001) == 0 )
        printk(&unk_20493, "hw_fence_utils_map_ipcc", 1860, *(_QWORD *)(a1 + 600), *(unsigned int *)(a1 + 616));
      hw_fence_ipcc_enable_signaling(a1, v9, v10, v11, v12);
      result = 0;
    }
    else
    {
      printk(&unk_20459, "hw_fence_utils_map_ipcc", 1853, v3, v12);
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
