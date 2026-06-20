__int64 __fastcall dcc_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  _DWORD *resource_byname; // x0
  __int64 v6; // x0
  __int64 *v7; // x0
  __int64 *v8; // x22
  __int64 v9; // x0
  int v10; // w0
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 result; // x0
  unsigned int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w8
  _QWORD *v26; // x10
  __int64 v27; // x9
  int v28; // w8
  _QWORD v29[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v1 = a1 + 16;
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  v3 = devm_kmalloc(a1 + 16, 384, 3520);
  if ( !v3 )
    goto LABEL_36;
  v4 = v3;
  *(_QWORD *)(v3 + 16) = v1;
  *(_QWORD *)(a1 + 168) = v3;
  resource_byname = (_DWORD *)platform_get_resource_byname(a1, 512, "dcc-base");
  if ( !resource_byname )
    goto LABEL_14;
  *(_DWORD *)(v4 + 8) = resource_byname[2] - *resource_byname + 1;
  v6 = devm_ioremap(v1);
  *(_QWORD *)v4 = v6;
  if ( !v6 )
    goto LABEL_36;
  v7 = (__int64 *)platform_get_resource_byname(a1, 512, "dcc-ram-base");
  if ( !v7 )
    goto LABEL_14;
  v8 = v7;
  *(_DWORD *)(v4 + 80) = *((_DWORD *)v7 + 2) - *(_DWORD *)v7 + 1;
  v9 = devm_ioremap(v1);
  *(_QWORD *)(v4 + 72) = v9;
  if ( !v9 )
  {
LABEL_36:
    result = 4294967284LL;
    goto LABEL_37;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "dcc-ram-offset", v4 + 84, 1, 0) & 0x80000000) != 0 )
    goto LABEL_14;
  v10 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "ll-reg-offsets", 4);
  *(_DWORD *)(v4 + 356) = v10;
  if ( v10 <= 0 )
  {
    dev_info(v1, "ll-reg-offsets property doesn't exist\n");
    *(_DWORD *)(v4 + 356) = 0;
  }
  else if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "per-ll-reg-cnt", v4 + 352, 1, 0) & 0x80000000) != 0 )
  {
    goto LABEL_14;
  }
  if ( (*(_DWORD *)(*(_QWORD *)v4 + 4LL) & 0x200) != 0 )
  {
    v12 = *(_QWORD *)v4;
    *(_DWORD *)(v4 + 104) = 2;
    LODWORD(v12) = *(_DWORD *)(v12 + 16);
    *(_DWORD *)(v4 + 328) = v12;
    if ( (_DWORD)v12 )
      goto LABEL_16;
LABEL_14:
    result = 4294967274LL;
    goto LABEL_37;
  }
  if ( (~*(_DWORD *)(*(_QWORD *)v4 + 4LL) & 0x3F) != 0 )
  {
    *(_DWORD *)(v4 + 104) = 0;
    *(_DWORD *)(v4 + 328) = 8;
  }
  else
  {
    v11 = *(_QWORD *)v4;
    *(_DWORD *)(v4 + 104) = 1;
    LODWORD(v11) = *(_DWORD *)(v11 + 16);
    *(_DWORD *)(v4 + 328) = v11;
    if ( !(_DWORD)v11 )
      goto LABEL_14;
  }
LABEL_16:
  if ( (*(_DWORD *)(*(_QWORD *)v4 + 4LL) & 0x40) != 0 )
    LOBYTE(v14) = 16;
  else
    v14 = 32 - __clz(((unsigned int)(*(_DWORD *)(v4 + 84) + *(_DWORD *)(v4 + 80)) >> 2) - 1);
  *(_BYTE *)(v4 + 344) = v14;
  _mutex_init(v4 + 24, "&drvdata->mutex", &dcc_probe___key);
  v15 = devm_kmalloc(v1, 4LL * *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 88) = v15;
  if ( !v15 )
    goto LABEL_36;
  v16 = devm_kmalloc(v1, 4LL * *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 96) = v16;
  if ( !v16 )
    goto LABEL_36;
  v17 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 120) = v17;
  if ( !v17 )
    goto LABEL_36;
  v18 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 128) = v18;
  if ( !v18 )
    goto LABEL_36;
  v19 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 136) = v19;
  if ( !v19 )
    goto LABEL_36;
  v20 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 144) = v20;
  if ( !v20 )
    goto LABEL_36;
  v21 = devm_kmalloc(v1, 4LL * *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 320) = v21;
  if ( !v21 )
    goto LABEL_36;
  v22 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 336) = v22;
  if ( !v22 )
    goto LABEL_36;
  v23 = devm_kmalloc(v1, *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 376) = v23;
  if ( !v23 )
    goto LABEL_36;
  v24 = devm_kmalloc(v1, 16LL * *(unsigned int *)(v4 + 328), 3520);
  *(_QWORD *)(v4 + 312) = v24;
  if ( !v24 )
    goto LABEL_36;
  if ( *(_DWORD *)(v4 + 328) )
  {
    v25 = 0;
    do
    {
      v26 = (_QWORD *)(*(_QWORD *)(v4 + 312) + 16LL * (int)v25);
      *v26 = v26;
      v26[1] = v26;
      *(_DWORD *)(*(_QWORD *)(v4 + 320) + 4LL * (int)v25) = 0;
      *(_BYTE *)(*(_QWORD *)(v4 + 128) + (int)v25) = 1;
      *(_BYTE *)(*(_QWORD *)(v4 + 136) + (int)v25++) = 0;
    }
    while ( v25 < *(_DWORD *)(v4 + 328) );
  }
  _memset_io(*(_QWORD *)(v4 + 72), 0, *(unsigned int *)(v4 + 80));
  *(_BYTE *)(v4 + 332) = -1;
  result = dcc_sram_dev_init(v4);
  if ( !(_DWORD)result )
  {
    result = dcc_create_files(v1);
    if ( !(_DWORD)result )
    {
      dcc_configure_list(v4, *(_QWORD *)(a1 + 760));
      v30 = *(_QWORD *)(v4 + 72);
      v27 = *(unsigned int *)(v4 + 80);
      strcpy((char *)v29, "KDCCDATA");
      v31 = *v8;
      v32 = v27;
      v28 = msm_minidump_add_region(v29);
      result = 0;
      if ( v28 < 0 )
      {
        dev_err(*(_QWORD *)(v4 + 16), "Failed to add DCC data in Minidump\n");
        result = 0;
      }
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
