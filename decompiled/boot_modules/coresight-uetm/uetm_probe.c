unsigned __int64 __fastcall uetm_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned __int64 result; // x0
  __int64 v8; // x0
  bool v9; // w9
  __int64 v10; // x0
  __int64 property; // x0
  char v12; // w8
  int v13; // w21
  __int64 v14; // x0
  _DWORD *v15; // x8
  int v16; // w9
  int v17; // w8
  __int64 v18; // x1
  int v19; // w2
  __int64 v20; // x0
  __int64 platform_data; // x21
  _QWORD v22[2]; // [xsp+0h] [xbp-70h] BYREF
  void *v23; // [xsp+10h] [xbp-60h]
  __int64 v24; // [xsp+18h] [xbp-58h]
  __int64 v25; // [xsp+20h] [xbp-50h]
  _UNKNOWN **v26; // [xsp+28h] [xbp-48h]
  __int64 v27; // [xsp+30h] [xbp-40h]
  __int64 v28; // [xsp+38h] [xbp-38h]
  __int64 v29; // [xsp+40h] [xbp-30h]
  __int64 v30; // [xsp+48h] [xbp-28h]
  int v31; // [xsp+54h] [xbp-1Ch] BYREF
  _BYTE v32[15]; // [xsp+58h] [xbp-18h] BYREF
  __int64 v33; // [xsp+68h] [xbp-8h]

  v1 = a1 + 16;
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  v23 = nullptr;
  v24 = 0;
  v22[0] = 0;
  v22[1] = 0;
  v3 = devm_kmalloc(a1 + 16, 72, 3520);
  if ( !v3 )
    goto LABEL_36;
  v4 = v3;
  v5 = devm_kmalloc(v1, 432, 3520);
  if ( !v5 )
    goto LABEL_36;
  *(_QWORD *)(v4 + 64) = v5;
  v6 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(a1 + 168) = v4;
  result = of_property_read_variable_u32_array(v6, "cluster", &v31, 1, 0);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_37;
  v8 = *(_QWORD *)(a1 + 760);
  *(_BYTE *)(v4 + 53) = v31;
  v9 = of_find_property(v8, "qcom,uncore_uetm", 0) != 0;
  v10 = *(_QWORD *)(a1 + 760);
  *(_BYTE *)(v4 + 56) = v9;
  property = of_find_property(v10, "qcom,qmx_uetm", 0);
  v12 = *(_BYTE *)(v4 + 56);
  *(_BYTE *)(v4 + 57) = property != 0;
  if ( (v12 & 1) == 0 && !property )
  {
    result = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "core", &v31, 1, 0);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_37;
    *(_BYTE *)(v4 + 52) = v31;
  }
  if ( !uetm_cnt )
    goto LABEL_25;
  v13 = 0;
  *(_DWORD *)&v32[11] = 0;
  *(_QWORD *)&v32[4] = 0;
  while ( 1 )
  {
    v14 = ph;
    v15 = *(_DWORD **)(ops + 8);
    *(_DWORD *)v32 = v13;
    if ( *(v15 - 1) != 1134762728 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, _BYTE *, __int64, __int64, __int64, __int64))v15)(
           v14,
           v32,
           1430606925,
           2,
           4,
           15) )
    {
      goto LABEL_10;
    }
    if ( *(_BYTE *)(v4 + 56) == 1 )
    {
      if ( v32[13] == *(unsigned __int8 *)(v4 + 53) && v32[0] == 4 )
        goto LABEL_24;
      goto LABEL_10;
    }
    v16 = *(unsigned __int8 *)(v4 + 53);
    if ( *(_BYTE *)(v4 + 57) != 1 )
      break;
    if ( v32[13] == v16 && v32[0] == 5 )
      goto LABEL_24;
LABEL_10:
    if ( ++v13 >= (unsigned int)uetm_cnt )
      goto LABEL_24;
  }
  if ( v32[13] != v16 || v32[14] != *(unsigned __int8 *)(v4 + 52) )
    goto LABEL_10;
LABEL_24:
  if ( v13 == uetm_cnt )
    goto LABEL_25;
  v17 = v32[0];
  v18 = *(_QWORD *)&v32[1];
  v19 = *(_DWORD *)&v32[9];
  *(_DWORD *)(v4 + 40) = v13;
  *(_QWORD *)(v4 + 32) = v18;
  *(_DWORD *)(v4 + 48) = v19;
  *(_DWORD *)(v4 + 20) = v17;
  switch ( v17 )
  {
    case 2:
LABEL_31:
      *(_BYTE *)(v4 + 24) = v17;
      *(_DWORD *)(v4 + 16) = 0;
      v20 = devm_ioremap(v1);
      *(_QWORD *)v4 = v20;
      if ( v20 )
      {
        platform_data = coresight_get_platform_data(v1);
        v27 = coresight_alloc_device_name(&uetm_devs, v1);
        if ( v27 )
        {
          v26 = &uetm_groups;
          v24 = platform_data;
          v25 = v1;
          v23 = &uetm_cs_ops;
          v22[0] = 0x200000003LL;
          result = coresight_register(v22);
          *(_QWORD *)(v4 + 8) = result;
          if ( result <= 0xFFFFFFFFFFFFF000LL )
            result = 0;
          else
            result = (unsigned int)result;
          goto LABEL_37;
        }
      }
LABEL_36:
      result = 4294967284LL;
      goto LABEL_37;
    case 5:
      LOBYTE(v17) = 4;
      goto LABEL_31;
    case 4:
      goto LABEL_31;
  }
LABEL_25:
  result = 4294967274LL;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
