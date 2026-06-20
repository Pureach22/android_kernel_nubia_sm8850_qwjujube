__int64 __fastcall glink_adc_probe(__int64 *a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x0
  __int64 v4; // x28
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned int child_node_count; // w0
  unsigned __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x24
  __int64 next_child_node; // x0
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x19
  unsigned int v14; // w0
  int v15; // w27
  char *v16; // x25
  __int64 v17; // x8
  unsigned __int64 v18; // x0
  unsigned int v19; // w19
  __int64 v20; // x8
  unsigned int v21; // w0
  __int64 v23; // x19
  const char *name; // x0
  __int64 v25; // x20
  const char *v26; // x0
  __int64 v27; // x8
  void (__fastcall *v28)(_QWORD); // x8
  unsigned int v29; // w20
  _QWORD *v30; // [xsp+10h] [xbp-40h]
  void *v31; // [xsp+18h] [xbp-38h] BYREF
  __int64 v32; // [xsp+20h] [xbp-30h]
  __int64 v33; // [xsp+28h] [xbp-28h]
  __int64 (__fastcall *v34)(); // [xsp+30h] [xbp-20h]
  __int64 v35; // [xsp+38h] [xbp-18h]
  int v36; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+48h] [xbp-8h]

  v1 = a1 + 2;
  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = nullptr;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v3 = devm_iio_device_alloc(a1 + 2, 144);
  if ( !v3 )
    goto LABEL_19;
  v4 = *(_QWORD *)(v3 + 1040);
  v5 = v3;
  *(_QWORD *)(v4 + 8) = v1;
  _mutex_init(v4 + 16, "&adc->lock", &glink_adc_probe___key);
  *(_DWORD *)(v4 + 64) = 0;
  _init_swait_queue_head(v4 + 72, "&x->wait", &init_completion___key);
  a1[21] = v4;
  LODWORD(v32) = 32784;
  v33 = v4;
  v34 = glink_adc_callback;
  v6 = *(_QWORD *)(v4 + 8);
  v31 = &unk_6C28;
  child_node_count = device_get_child_node_count(v6);
  *(_DWORD *)(v4 + 104) = child_node_count;
  if ( !child_node_count )
  {
    v19 = -22;
    goto LABEL_23;
  }
  v8 = 160LL * child_node_count;
  v9 = devm_kmalloc(*(_QWORD *)(v4 + 8), v8, 3520);
  *(_QWORD *)(v4 + 96) = v9;
  if ( !v9 )
  {
LABEL_19:
    v19 = -12;
    goto LABEL_23;
  }
  v10 = v9;
  v30 = v1;
  next_child_node = device_get_next_child_node(*(_QWORD *)(v4 + 8), 0);
  if ( !next_child_node )
  {
LABEL_16:
    v18 = pmic_glink_register_client(v30, &v31);
    *(_QWORD *)v4 = v18;
    if ( v18 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v5 + 104) = v30;
      *(_QWORD *)(v5 + 752) = a1[95];
      v20 = *a1;
      *(_QWORD *)(v5 + 1024) = &glink_adc_info;
      *(_QWORD *)(v5 + 1008) = v20;
      *(_DWORD *)v5 = 1;
      *(_QWORD *)(v5 + 992) = *(_QWORD *)(v4 + 96);
      *(_DWORD *)(v5 + 1000) = *(_DWORD *)(v4 + 104);
      v21 = _devm_iio_device_register(v30);
      if ( (v21 & 0x80000000) == 0 )
      {
        v19 = 0;
        goto LABEL_23;
      }
      v29 = v21;
      dev_err(v30, "iio device registration failed, ret=%d\n", v21);
      pmic_glink_unregister_client(*(_QWORD *)v4);
    }
    else
    {
      if ( (_DWORD)v18 == -517 )
      {
        v19 = -517;
        goto LABEL_23;
      }
      v29 = v18;
      dev_err(v30, "Error registering glink ADC, ret=%d\n", v18);
    }
    v19 = v29;
    goto LABEL_23;
  }
  v12 = next_child_node;
  v13 = 144;
  while ( 1 )
  {
    v36 = 0;
    v14 = fwnode_property_read_u32_array(v12, "reg", &v36, 1);
    if ( (v14 & 0x80000000) != 0 )
      break;
    v15 = (unsigned __int8)v36;
    if ( (unsigned int)(unsigned __int8)v36 - 4 < 0xFFFFFFFD )
      goto LABEL_24;
    if ( (unsigned __int8)v36 > 3u )
LABEL_35:
      __break(1u);
    v16 = (char *)&glink_adc_channels + 160 * (unsigned __int8)v36;
    v17 = *((_QWORD *)v16 + 18);
    if ( !v17 )
    {
LABEL_24:
      v23 = *(_QWORD *)(v4 + 8);
      name = (const char *)fwnode_get_name(v12);
      dev_err(v23, "%s invalid channel number %u\n", name, v15);
      v19 = -22;
      goto LABEL_26;
    }
    if ( v8 < v13 - 140 )
      goto LABEL_35;
    *(_DWORD *)(v10 + v13 - 140) = v36;
    if ( v8 <= v13 - 144 )
      goto LABEL_35;
    *(_DWORD *)(v10 + v13 - 144) = *(_DWORD *)v16;
    if ( v8 < v13 )
      goto LABEL_35;
    *(_QWORD *)(v10 + v13) = v17;
    fwnode_property_read_string(v12, "label");
    if ( v8 < v13 - 8 )
      goto LABEL_35;
    *(_QWORD *)(v10 + v13 - 8) = *(_QWORD *)(v10 + v13);
    if ( v8 < v13 - 96 )
      goto LABEL_35;
    *(_QWORD *)(v10 + v13 - 96) = *((_QWORD *)v16 + 6);
    v12 = device_get_next_child_node(*(_QWORD *)(v4 + 8), v12);
    v13 += 160LL;
    if ( !v12 )
      goto LABEL_16;
  }
  v25 = *(_QWORD *)(v4 + 8);
  v19 = v14;
  v26 = (const char *)fwnode_get_name(v12);
  dev_err(v25, "missing channel number %s, ret=%d\n", v26, v19);
LABEL_26:
  if ( v12 <= 0xFFFFFFFFFFFFF000LL )
  {
    v27 = *(_QWORD *)(v12 + 8);
    if ( v27 )
    {
      v28 = *(void (__fastcall **)(_QWORD))(v27 + 8);
      if ( v28 )
      {
        if ( *((_DWORD *)v28 - 1) != -643302289 )
          __break(0x8228u);
        v28(v12);
      }
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v19;
}
