unsigned __int64 __fastcall qsmmuv500_tbu_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 result; // x0
  int is_compatible; // w22
  __int64 v7; // x0
  unsigned __int64 v8; // x20
  int variable_u32_array; // w0
  __int64 v10; // x0
  unsigned int *v11; // x8
  __int64 property; // x0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v3 = devm_kmalloc(a1 + 16, 80, 3520);
  if ( !v3 )
  {
LABEL_13:
    result = 4294967284LL;
    goto LABEL_23;
  }
  v4 = v3;
  *(_QWORD *)(v3 + 16) = v1;
  result = arm_smmu_init_power_resources(v1);
  *(_QWORD *)(v4 + 48) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_23;
  is_compatible = of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,qtb500");
  v7 = devm_krealloc(v1, v4, 88, 3264);
  v8 = v7;
  if ( !is_compatible )
  {
    if ( v7 )
    {
      *(_QWORD *)(v7 + 40) = arm_tbu_impl;
      property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,micro-idle", 0);
      *(_BYTE *)(v8 + 80) = property != 0;
      if ( property )
      {
        *(_QWORD *)(*(_QWORD *)(v8 + 48) + 104LL) = arm_tbu_micro_idle_wake;
        *(_QWORD *)(*(_QWORD *)(v8 + 48) + 112LL) = arm_tbu_micro_idle_allow;
      }
      if ( v8 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_18;
      goto LABEL_7;
    }
LABEL_19:
    result = 4294967284LL;
    goto LABEL_23;
  }
  if ( !v7 )
    goto LABEL_19;
  *(_QWORD *)(v7 + 40) = qtb500_impl;
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,num-qtb-ports", v7 + 84, 1, 0);
  if ( (variable_u32_array & 0x80000000) == 0 )
  {
    *(_BYTE *)(v8 + 80) = of_find_property(*(_QWORD *)(a1 + 760), "qcom,no-qtb-atos-halt", 0) != 0;
    if ( v8 < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_7;
LABEL_18:
    result = (unsigned int)v8;
    goto LABEL_23;
  }
  v8 = variable_u32_array;
  if ( (unsigned __int64)variable_u32_array >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_18;
LABEL_7:
  *(_QWORD *)v8 = v8;
  *(_QWORD *)(v8 + 8) = v8;
  *(_DWORD *)(v8 + 68) = 0;
  if ( !platform_get_resource(a1, 512, 0) )
  {
    result = 4294967274LL;
    goto LABEL_23;
  }
  v10 = devm_ioremap(v1);
  *(_QWORD *)(v8 + 32) = v10;
  if ( !v10 )
    goto LABEL_13;
  v11 = (unsigned int *)of_get_property(*(_QWORD *)(a1 + 760), "qcom,stream-id-range", &v13);
  result = 4294967274LL;
  if ( v11 )
  {
    if ( v13 >= 8 )
    {
      *(_DWORD *)(v8 + 56) = bswap32(*v11);
      *(_DWORD *)(v8 + 60) = bswap32(v11[1]);
      result = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,iova-width", v8 + 64, 1, 0);
      if ( (result & 0x80000000) == 0 )
      {
        result = 0;
        *(_QWORD *)(a1 + 168) = v8;
      }
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
