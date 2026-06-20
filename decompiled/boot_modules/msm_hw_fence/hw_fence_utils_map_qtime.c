__int64 __fastcall hw_fence_utils_map_qtime(__int64 *a1)
{
  __int64 v1; // x30
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned int variable_u32_array; // w0
  int v6; // w2
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x30
  unsigned int v13; // w19
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = v1;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v14[0] = 0;
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v4 + 744), "qcom,qtime-reg", v14, 2, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v12 = v3;
    v13 = variable_u32_array;
    printk(&unk_25083, "hw_fence_utils_map_qtime", 1876, v12, variable_u32_array);
    result = v13;
  }
  else
  {
    v6 = HIDWORD(v14[0]);
    v7 = *a1;
    a1[82] = LODWORD(v14[0]);
    *((_DWORD *)a1 + 168) = v6;
    v8 = devm_ioremap(v7);
    if ( v8 )
    {
      v10 = v8;
      result = 0;
      a1[83] = v10;
    }
    else
    {
      printk(&unk_2AFD3, "hw_fence_utils_map_qtime", 1885, v3, v9);
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
