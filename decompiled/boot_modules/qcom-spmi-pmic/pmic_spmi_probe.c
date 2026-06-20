__int64 __fastcall pmic_spmi_probe(__int64 a1)
{
  void *v2; // x1
  unsigned __int64 inited; // x0
  unsigned __int64 v4; // x20
  unsigned __int64 device_by_of_node; // x22
  __int64 v6; // x0
  __int64 v7; // x21
  int match_data; // w0
  int v9; // w24
  __int64 v10; // x0
  __int64 parent; // x22
  __int64 next_child; // x0
  __int64 v13; // x23
  int v14; // w0
  int v15; // w0
  int v16; // w8
  unsigned int v17; // w8
  _QWORD *v18; // x8
  __int64 v19; // x9
  __int64 v20; // x10
  int v21; // w23
  __int64 v22; // x8
  __int64 v23; // x11
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( of_find_property(*(_QWORD *)(a1 + 744), "qcom,can-sleep", 0) )
    v2 = &spmi_regmap_can_sleep_config;
  else
    v2 = &spmi_regmap_config;
  inited = _devm_regmap_init_spmi_ext(a1, v2, 0, 0);
  v4 = inited;
  if ( inited >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(device_by_of_node) = inited;
    goto LABEL_41;
  }
  v6 = devm_kmalloc(a1, 40, 3520);
  if ( !v6 )
  {
    LODWORD(device_by_of_node) = -12;
    goto LABEL_41;
  }
  v7 = v6;
  match_data = device_get_match_data(a1);
  v9 = *(unsigned __int8 *)(a1 + 920);
  *(_DWORD *)v7 = match_data;
  if ( !(v9 % match_data) )
  {
    v15 = regmap_read(v4, 260, v7 + 8);
    if ( (v15 & 0x80000000) == 0 )
    {
      if ( *(_DWORD *)(v7 + 8) != 81 )
        goto LABEL_39;
      v15 = regmap_read(v4, 261, v7 + 12);
      if ( v15 < 0 )
        goto LABEL_40;
      *(_QWORD *)(v7 + 32) = of_match_device(&_mod_of__pmic_spmi_id_table_device_table, a1) + 64;
      v15 = regmap_read(v4, 257, v7 + 24);
      if ( v15 < 0 )
        goto LABEL_40;
      v15 = regmap_read(v4, 258, v7 + 20);
      if ( v15 < 0 )
        goto LABEL_40;
      v15 = regmap_read(v4, 259, v7 + 16);
      if ( v15 < 0 )
        goto LABEL_40;
      v16 = *(_DWORD *)(v7 + 12);
      if ( v16 != 27 && v16 != 21 )
      {
LABEL_25:
        switch ( v16 )
        {
          case 1:
            goto LABEL_28;
          case 5:
            *(_DWORD *)(v7 + 20) = *(_DWORD *)(v7 + 24);
            break;
          case 4:
LABEL_28:
            v17 = *(_DWORD *)(v7 + 16);
            if ( v17 <= 1 )
              *(_DWORD *)(v7 + 16) = v17 + 1;
            break;
        }
LABEL_39:
        mutex_lock(&pmic_spmi_revid_lock);
        *(_QWORD *)(a1 + 152) = v7;
        mutex_unlock(&pmic_spmi_revid_lock);
        devm_regmap_qti_debugfs_register(a1, v4);
        v15 = devm_of_platform_populate(a1);
        goto LABEL_40;
      }
      v15 = regmap_read(v4, 498, v7 + 28);
      if ( (v15 & 0x80000000) == 0 )
      {
        v16 = *(_DWORD *)(v7 + 12);
        goto LABEL_25;
      }
    }
LABEL_40:
    LODWORD(device_by_of_node) = v15;
    goto LABEL_41;
  }
  v10 = *(_QWORD *)(a1 + 744);
  v25 = 0;
  parent = of_get_parent(v10);
  next_child = of_get_next_child(parent, 0);
  if ( next_child )
  {
    v13 = next_child;
    while ( 1 )
    {
      v14 = of_property_read_u32_index(v13, &unk_8760, 0, &v25);
      if ( v14 )
      {
        device_by_of_node = v14;
        goto LABEL_32;
      }
      if ( v25 == v9 + 1 - *(_DWORD *)v7 )
        break;
      v13 = of_get_next_child(parent, v13);
      if ( !v13 )
        goto LABEL_13;
    }
    device_by_of_node = spmi_find_device_by_of_node(v13);
    if ( !device_by_of_node )
    {
      LODWORD(device_by_of_node) = -517;
      goto LABEL_38;
    }
LABEL_32:
    if ( device_by_of_node < 0xFFFFFFFFFFFFF001LL )
    {
      mutex_lock(&pmic_spmi_revid_lock);
      v18 = *(_QWORD **)(device_by_of_node + 152);
      if ( v18 )
      {
        v20 = v18[3];
        v19 = v18[4];
        v21 = 0;
        v23 = v18[1];
        v22 = v18[2];
        *(_QWORD *)(v7 + 24) = v20;
        *(_QWORD *)(v7 + 32) = v19;
        *(_QWORD *)(v7 + 8) = v23;
        *(_QWORD *)(v7 + 16) = v22;
      }
      else
      {
        v21 = -517;
      }
      mutex_unlock(&pmic_spmi_revid_lock);
      put_device(device_by_of_node);
      LODWORD(device_by_of_node) = v21;
    }
  }
  else
  {
LABEL_13:
    LODWORD(device_by_of_node) = -61;
  }
LABEL_38:
  if ( !(_DWORD)device_by_of_node )
    goto LABEL_39;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)device_by_of_node;
}
