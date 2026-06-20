__int64 __fastcall kgsl_bus_init(_QWORD *a1, __int64 a2)
{
  __int64 node_opts_by_path; // x0
  int v5; // w3
  int v6; // w0
  __int64 v7; // x25
  __int64 v8; // x0
  unsigned __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x8
  int v13; // w0
  unsigned __int64 v14; // x21
  __int64 v15; // x22
  unsigned __int64 v16; // x24
  int v17; // w8
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x26
  unsigned int v20; // w27
  unsigned int *v21; // x28
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w9
  unsigned __int64 StatusReg; // x22
  __int64 v26; // x23
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v29; // [xsp+10h] [xbp-20h]
  __int64 v30; // [xsp+18h] [xbp-18h]
  __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)s = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  if ( !node_opts_by_path )
    goto LABEL_13;
  if ( (of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", s, 1, 0) & 0x80000000) != 0 )
    goto LABEL_13;
  v5 = *(_DWORD *)s;
  if ( (*(_DWORD *)s & 0x80000000) != 0 )
    goto LABEL_13;
  v30 = 0;
  v31 = 0;
  *(_QWORD *)s = 0;
  v29 = 0;
  snprintf(s, 0x20u, "qcom,bus-table-ddr%d", v5);
  v6 = of_property_count_elems_of_size(*(_QWORD *)(a2 + 760), s, 4);
  if ( v6 < 1 )
  {
    v12 = -22;
LABEL_12:
    a1[1299] = v12;
LABEL_13:
    v13 = of_property_count_elems_of_size(*(_QWORD *)(a2 + 760), "qcom,bus-table-ddr", 4);
    if ( v13 < 1 )
    {
      LODWORD(v14) = -22;
      goto LABEL_37;
    }
    v7 = (unsigned int)v13;
    v14 = _kmalloc_noprof(4LL * (unsigned int)v13, 3520);
    if ( !v14 )
      goto LABEL_36;
    goto LABEL_15;
  }
  v7 = (unsigned int)v6;
  v8 = _kmalloc_noprof(4LL * (unsigned int)v6, 3520);
  v9 = v8;
  if ( !v8 )
  {
    v12 = -12;
    goto LABEL_12;
  }
  v10 = 0;
  v11 = v8;
  do
  {
    of_property_read_u32_index(*(_QWORD *)(a2 + 760), s, (unsigned int)v10++, v11);
    v11 += 4;
  }
  while ( v7 != v10 );
  a1[1299] = v9;
  if ( v9 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_13;
  while ( 1 )
  {
    v17 = *((_DWORD *)a1 + 2517);
    *((_DWORD *)a1 + 2600) = v7;
    if ( v17 == 1 )
      break;
    v19 = 0;
    v20 = v7 - 1;
    v21 = (unsigned int *)a1 + 2289;
    while ( v19 != 33 )
    {
      if ( *(v21 - 2) >= (unsigned int)v7 )
      {
        dev_err(*a1, "Bus setting for GPU freq %d is out of bounds\n", *(v21 - 3));
        *(v21 - 2) = v20;
      }
      v23 = *v21;
      if ( *v21 >= (unsigned int)v7 )
      {
        dev_err(*a1, "Bus max for GPU freq %d is out of bounds\n", *(v21 - 3));
        v23 = v7 - 1;
        *v21 = v20;
      }
      v24 = *(v21 - 1);
      if ( v24 >= (unsigned int)v7 )
      {
        dev_err(*a1, "Bus min for GPU freq %d is out of bounds\n", *(v21 - 3));
        v22 = *v21;
        *(v21 - 1) = v20;
        if ( v20 > v22 )
          goto LABEL_33;
      }
      else if ( v24 > v23 )
      {
LABEL_33:
        dev_err(*a1, "Bus min is bigger than bus max for GPU freq %d\n", *(v21 - 3));
        *(v21 - 1) = *v21;
      }
      ++v19;
      v21 += 7;
      if ( v19 >= (unsigned int)(*((_DWORD *)a1 + 2517) - 1) )
        goto LABEL_19;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v26 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &kgsl_bus_get_table__alloc_tag;
    v14 = _kmalloc_noprof(4 * v7, 3520);
    *(_QWORD *)(StatusReg + 80) = v26;
    if ( !v14 )
    {
LABEL_36:
      LODWORD(v14) = -12;
      goto LABEL_37;
    }
LABEL_15:
    v15 = 0;
    v16 = v14;
    do
    {
      of_property_read_u32_index(*(_QWORD *)(a2 + 760), "qcom,bus-table-ddr", (unsigned int)v15++, v16);
      v16 += 4LL;
    }
    while ( v7 != v15 );
    a1[1299] = v14;
    if ( v14 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_37:
      a1[1299] = 0;
      goto LABEL_38;
    }
  }
LABEL_19:
  v18 = of_icc_get(a2 + 16, "gpu_icc_path");
  a1[1307] = v18;
  if ( v18 < 0xFFFFFFFFFFFFF001LL || (gmu_core_scales_bandwidth(a1) & 1) != 0 )
  {
    LODWORD(v14) = 0;
  }
  else
  {
    _warn_printk("The CPU has no way to set the GPU bus levels\n");
    __break(0x800u);
    kfree(a1[1299]);
    LODWORD(v14) = *((_DWORD *)a1 + 2614);
    a1[1299] = 0;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v14;
}
