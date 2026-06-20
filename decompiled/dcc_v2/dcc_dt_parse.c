__int64 __fastcall dcc_dt_parse(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w22
  char *v6; // x21
  int v7; // w8
  __int64 property; // x0
  unsigned int v9; // w8
  __int64 v10; // x20
  unsigned int v11; // w21
  int v12; // w0
  int v13; // w8
  unsigned int v14; // w1
  unsigned int v15; // w2
  int v16; // w3
  unsigned int v17; // w27
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // w10
  int v22; // w10
  _QWORD *v23; // x8
  __int64 v24; // x2
  _QWORD *v25; // x1
  __int64 v26; // x8
  unsigned int v27; // w19
  __int64 v28; // x8
  char *s1; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v30; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v30 = 0;
  s1 = nullptr;
  result = of_property_read_variable_u32_array(a2, "qcom,curr-link-list", &v30, 1, 0);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_38;
  if ( v30 >= *(_DWORD *)(a1 + 328) )
  {
    dev_err(*(_QWORD *)(a1 + 16), "List configuration failed.\n");
LABEL_37:
    result = 0;
    goto LABEL_38;
  }
  *(_BYTE *)(a1 + 332) = v30;
  if ( of_find_property(a2, "qcom,ap-qad-override", 0) )
    *(_BYTE *)(*(_QWORD *)(a1 + 376) + *(unsigned __int8 *)(a1 + 332)) = 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 88) + 4LL * v30) = 0;
  v5 = of_property_read_string(a2, "qcom,data-sink", &s1);
  if ( !v5 )
  {
    v6 = s1;
    if ( !strcmp(s1, "sram") )
    {
      v7 = 0;
    }
    else
    {
      if ( strcmp(v6, "atb") )
      {
        v28 = *(unsigned int *)(*(_QWORD *)(a1 + 88) + 4LL * v30);
        if ( (unsigned int)v28 > 1 )
        {
          __break(0x5512u);
          return dcc_v2_freeze();
        }
        dev_err(*(_QWORD *)(a1 + 16), "Unknown sink type for DCC Using '%s' as data sink\n", (&str_dcc_data_sink)[v28]);
        goto LABEL_11;
      }
      v7 = 1;
    }
    *(_DWORD *)(*(_QWORD *)(a1 + 88) + 4LL * v30) = v7;
  }
LABEL_11:
  property = of_get_property(a2, "qcom,link-list", &v31);
  if ( !property )
  {
    result = v5;
    goto LABEL_38;
  }
  v9 = v31;
  v10 = property;
  result = v5;
  v31 >>= 2;
  if ( v9 < 4 )
    goto LABEL_38;
  v11 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v12 = -22;
    v13 = bswap32(*(_DWORD *)(v10 + 4LL * (int)v11));
    v14 = bswap32(*(_DWORD *)(v10 + 4LL * (int)(v11 + 1)));
    v15 = bswap32(*(_DWORD *)(v10 + 4LL * (int)(v11 + 2)));
    if ( v13 > 1 )
      break;
    v16 = bswap32(*(_DWORD *)(v10 + 4LL * (int)(v11 + 3)));
    if ( v13 )
    {
      if ( v13 != 1 )
        goto LABEL_34;
      v12 = dcc_add_write(a1, v14, v15, v16);
    }
    else
    {
      v12 = dcc_config_add(a1, v14, v15, v16);
    }
LABEL_15:
    if ( v12 )
      goto LABEL_34;
LABEL_16:
    v11 += 4;
    if ( v11 >= v31 )
      goto LABEL_37;
  }
  if ( v13 != 2 )
  {
    if ( v13 != 3 )
      goto LABEL_34;
    v12 = dcc_rd_mod_wr_add(a1, v14, v15);
    goto LABEL_15;
  }
  v17 = v14;
  v18 = _kmalloc_cache_noprof(strcmp, 3520, 56);
  if ( v18 )
  {
    v19 = *(_QWORD *)(a1 + 320);
    v20 = *(unsigned __int8 *)(a1 + 332);
    if ( v17 >= 0xFF )
      v21 = 255;
    else
      v21 = v17;
    *(_DWORD *)(v18 + 16) = v21;
    v22 = *(_DWORD *)(v19 + 4 * v20);
    *(_DWORD *)(v19 + 4 * v20) = v22 + 1;
    v23 = (_QWORD *)(v18 + 40);
    *(_DWORD *)(v18 + 12) = v22;
    *(_DWORD *)(v18 + 32) = 1;
    *(_QWORD *)(v18 + 40) = v18 + 40;
    *(_QWORD *)(v18 + 48) = v18 + 40;
    v24 = *(_QWORD *)(a1 + 312) + 16LL * *(unsigned __int8 *)(a1 + 332);
    v25 = *(_QWORD **)(v24 + 8);
    if ( v18 + 40 == v24 || v25 == v23 || *v25 != v24 )
    {
      _list_add_valid_or_report(v18 + 40, v25);
    }
    else
    {
      *(_QWORD *)(v24 + 8) = v23;
      *(_QWORD *)(v18 + 40) = v24;
      *(_QWORD *)(v18 + 48) = v25;
      *v25 = v23;
    }
    goto LABEL_16;
  }
  v12 = -12;
LABEL_34:
  v26 = *(_QWORD *)(a1 + 16);
  v27 = v12;
  dev_err(v26, "DCC init time config failed err:%d\n", v12);
  result = v27;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
