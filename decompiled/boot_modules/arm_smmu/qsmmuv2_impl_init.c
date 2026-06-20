__int64 __fastcall qsmmuv2_impl_init(_QWORD *a1)
{
  _DWORD *v2; // x0
  __int64 v3; // x19
  _DWORD *v4; // x20
  int is_compatible; // w0
  __int64 v6; // x25
  void *v7; // x8
  bool v8; // zf
  __int64 v9; // x0
  char v10; // w8
  int v11; // w2
  unsigned __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x21
  unsigned __int64 v15; // x23
  __int64 v16; // x24
  int variable_u32_array; // w0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x10
  __int64 v20; // x9
  int v21; // w12
  unsigned __int64 v22; // x11
  _DWORD *v23; // x10
  int v24; // w12
  unsigned __int64 v25; // x13
  int v26; // w8
  int v27; // w25
  __int64 v28; // x8
  unsigned __int64 StatusReg; // x26
  __int64 v30; // x27
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_DWORD *)devm_kmalloc(*a1, 352, 3520);
  if ( !v2 )
    goto LABEL_27;
  v3 = (__int64)(v2 + 6);
  v4 = v2;
  *v2 = 0;
  memcpy(v2 + 6, a1, 0x148u);
  is_compatible = of_device_is_compatible(*(_QWORD *)(*a1 + 744LL), "qcom,adreno-smmu");
  v6 = *((_QWORD *)v4 + 3);
  v7 = &qsmmuv2_adreno_impl;
  v8 = is_compatible == 0;
  v9 = *(_QWORD *)(v6 + 744);
  if ( v8 )
    v7 = &qsmmuv2_impl;
  *((_QWORD *)v4 + 9) = v7;
  v32 = 0;
  if ( !of_find_property(v9, "attach-impl-defs", &v32) )
    goto LABEL_28;
  v10 = v32;
  v11 = v32 >> 2;
  v32 >>= 2;
  if ( (v10 & 4) != 0 )
  {
    dev_err(v6, "Invalid number of attach-impl-defs registers: %d\n", v11);
    v3 = -22;
    goto LABEL_28;
  }
  v12 = 8LL * v11;
  v13 = devm_kmalloc(v6, v12, 3520);
  if ( !v13 || (v14 = v13, v15 = 8LL * v32, (v16 = _kmalloc_noprof(v15, 3520)) == 0) )
  {
LABEL_27:
    v3 = -12;
    goto LABEL_28;
  }
  while ( 1 )
  {
    variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v6 + 744), "attach-impl-defs", v16, v32, 0);
    if ( variable_u32_array < 0 )
      break;
    v18 = (unsigned int)v32;
    if ( v32 < 1 )
    {
LABEL_23:
      kfree(v16);
      v26 = v32;
      *((_QWORD *)v4 + 1) = v14;
      v4[4] = v26 / 2;
      goto LABEL_28;
    }
    v19 = 0;
    v20 = 1;
    while ( v15 > v19 )
    {
      if ( v12 <= v19 )
        break;
      if ( (v19 & 0x8000000000000000LL) != 0 )
        break;
      if ( v15 <= v19 )
        break;
      if ( (v19 & 0x8000000000000000LL) != 0 )
        break;
      if ( v12 <= v19 )
        break;
      v21 = *(_DWORD *)(v16 + v19);
      v22 = v19 + 4;
      v23 = (_DWORD *)(v14 + v19);
      *v23 = v21;
      if ( v15 < v22 || v12 < v22 || (v22 & 0x8000000000000000LL) != 0 || v15 < v22 || v12 < v22 )
        break;
      v24 = *(_DWORD *)(v16 + 4 * v20);
      v25 = v20 + 1;
      v20 += 2;
      v23[1] = v24;
      v19 = v22 + 4;
      if ( v25 >= v18 )
        goto LABEL_23;
    }
    __break(1u);
    v28 = v32;
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    v15 = 8 * v28;
    *(_QWORD *)(StatusReg + 80) = &arm_smmu_parse_impl_def_registers__alloc_tag;
    v16 = _kmalloc_noprof(8 * v28, 3520);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v16 )
      goto LABEL_27;
  }
  v27 = variable_u32_array;
  kfree(v16);
  v3 = v27;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v3;
}
