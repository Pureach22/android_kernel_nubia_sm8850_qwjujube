__int64 __fastcall gsi_register_device(unsigned int *src, __int64 *a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  void *v6; // x0
  __int64 v7; // x7
  unsigned int v8; // w4
  __int64 v9; // x1
  __int64 v10; // x0
  __int64 v11; // x4
  int v12; // w8
  __int64 v13; // x4
  __int64 v14; // x0
  long double v15; // q0
  __int64 v16; // x8
  int msis; // w0
  __int64 v18; // x8
  int max_channels; // w0
  __int64 v20; // x8
  unsigned int max_event_rings; // w0
  __int64 v22; // x8
  __int64 v23; // x0
  int v24; // w0
  __int64 v25; // x0
  unsigned int v26; // w20
  unsigned int glob_irq_en_gp_int1_mask; // w0
  __int64 v28; // x1
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x2
  __int64 v33; // x8
  __int64 v34; // x2
  __int64 v35; // x20
  unsigned int v36; // w22
  __int64 v37; // x8
  __int64 v38; // x2
  _QWORD *v39; // x8
  __int64 v40; // x8
  unsigned __int64 v41; // x23
  __int64 v42; // [xsp+0h] [xbp-10h] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = gsi_ctx;
  BYTE4(v42) = 0;
  LODWORD(v42) = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_register_device", 1487);
    result = 4294967288LL;
    goto LABEL_22;
  }
  if ( !src || !a2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params props=%pK dev_hdl=%pK\n", "gsi_register_device", 1492, src, a2);
    result = 4294967290LL;
    goto LABEL_22;
  }
  if ( *src - 14 <= 0xFFFFFFF2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params gsi_ver=%d\n", "gsi_register_device", 1497);
LABEL_7:
    result = 4294967290LL;
    goto LABEL_22;
  }
  if ( !*((_QWORD *)src + 11) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d notify callback must be provided\n", "gsi_register_device", 1502);
LABEL_11:
    result = 4294967290LL;
    goto LABEL_22;
  }
  if ( *((_QWORD *)src + 12) && !*((_QWORD *)src + 13) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d rel callback  must be provided\n", "gsi_register_device", 1507);
    goto LABEL_11;
  }
  if ( *(_BYTE *)(gsi_ctx + 176) == 1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d per already registered\n", "gsi_register_device", 1512);
LABEL_21:
    result = 4294967289LL;
    goto LABEL_22;
  }
  v6 = (void *)(gsi_ctx + 16);
  *(_DWORD *)(gsi_ctx + 28560) = 0;
  memcpy(v6, src, 0xA0u);
  v8 = src[2];
  if ( v8 != 1 )
  {
    dev_err(*(_QWORD *)(v2 + 8), "%s:%d do not support interrupt type %u\n", "gsi_register_device", 1582, v8);
    goto LABEL_21;
  }
  v9 = src[6];
  v10 = *(_QWORD *)(v2 + 8);
  if ( !(_DWORD)v9 )
  {
    dev_err(v10, "%s:%d bad irq specified %u\n", "gsi_register_device", 1520);
    goto LABEL_7;
  }
  if ( *((_QWORD *)src + 12) )
    v11 = 1;
  else
    v11 = 4;
  if ( (unsigned int)devm_request_threaded_irq(v10, v9, gsi_isr, 0, v11, "gsi", v2, v7, v42, v43) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to register isr for %u\n", "gsi_register_device", 1568, src[6]);
    result = 0xFFFFFFFFLL;
    goto LABEL_22;
  }
  v12 = irq_set_irq_wake(src[6], 1);
  v13 = src[6];
  v14 = *(_QWORD *)(gsi_ctx + 8);
  if ( v12 )
    v15 = dev_err(v14, "%s:%d failed to enable wake irq %u\n", "gsi_register_device", 1577, v13);
  else
    v15 = dev_err(v14, "%s:%d GSI irq is wake enabled %u\n", "gsi_register_device", 1579, v13);
  v16 = gsi_ctx;
  if ( *(_DWORD *)(gsi_ctx + 28680) )
  {
    msis = _gsi_allocate_msis(v15);
    v16 = gsi_ctx;
    if ( msis )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to allocate MSIs\n", "gsi_register_device", 1589);
      v35 = gsi_ctx;
      v36 = 0;
LABEL_64:
      devm_free_irq(*(_QWORD *)(v35 + 8), src[6]);
      result = v36;
      goto LABEL_22;
    }
  }
  if ( !*(_QWORD *)v16 )
  {
    v24 = gsi_map_base(*((_QWORD *)src + 4), src[10], *src);
    if ( v24 )
      goto LABEL_62;
    v16 = gsi_ctx;
  }
  *(_BYTE *)(v16 + 176) = 1;
  _mutex_init(v16 + 28512, "&gsi_ctx->mlock", &gsi_register_device___key, v15);
  v18 = gsi_ctx;
  *(_DWORD *)(gsi_ctx + 28580) = 0;
  *(_DWORD *)(v18 + 28584) = 0;
  max_channels = gsi_get_max_channels(*(unsigned int *)(v18 + 16));
  v20 = gsi_ctx;
  *(_DWORD *)(gsi_ctx + 28608) = max_channels;
  if ( !max_channels )
  {
    gsi_unmap_base();
    v31 = gsi_ctx;
    *(_QWORD *)gsi_ctx = 0;
    v32 = gsi_ctx;
    *(_QWORD *)(v31 + 28752) = 0;
    devm_free_irq(*(_QWORD *)(v32 + 8), src[6]);
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to get max channels\n", "gsi_register_device", 1651);
LABEL_61:
    gsi_unmap_base();
    v39 = (_QWORD *)gsi_ctx;
    v24 = -1;
    *(_QWORD *)(gsi_ctx + 28752) = 0;
    *v39 = 0;
LABEL_62:
    v35 = gsi_ctx;
    v36 = v24;
    v40 = *(unsigned int *)(gsi_ctx + 28680);
    if ( (_DWORD)v40 )
    {
      v41 = (unsigned __int64)(v40 + 63) >> 3;
      platform_device_msi_free_irqs_all(*(_QWORD *)(gsi_ctx + 8));
      v35 = gsi_ctx;
      memset((void *)(gsi_ctx + 28688), 0, v41 & 0x3FFFFFF8);
    }
    goto LABEL_64;
  }
  max_event_rings = gsi_get_max_event_rings(*(unsigned int *)(v20 + 16));
  v22 = gsi_ctx;
  *(_DWORD *)(gsi_ctx + 28612) = max_event_rings;
  if ( !max_event_rings )
  {
    gsi_unmap_base();
    v33 = gsi_ctx;
    *(_QWORD *)gsi_ctx = 0;
    v34 = gsi_ctx;
    *(_QWORD *)(v33 + 28752) = 0;
    devm_free_irq(*(_QWORD *)(v34 + 8), src[6]);
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to get max event rings\n", "gsi_register_device", 1662);
    goto LABEL_61;
  }
  if ( max_event_rings >= 0x20 )
  {
    dev_err(*(_QWORD *)(v22 + 8), "%s:%d max event rings are beyond absolute maximum\n", "gsi_register_device", 1668);
    goto LABEL_61;
  }
  if ( *((_BYTE *)src + 72) == 1 && src[19] > max_event_rings - 1 )
  {
    gsi_unmap_base();
    v37 = gsi_ctx;
    *(_QWORD *)gsi_ctx = 0;
    v38 = gsi_ctx;
    *(_QWORD *)(v37 + 28752) = 0;
    devm_free_irq(*(_QWORD *)(v38 + 8), src[6]);
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d MHI event ring start id %u is beyond max %u\n",
      "gsi_register_device",
      1681,
      src[19],
      *(_DWORD *)(gsi_ctx + 28612));
    goto LABEL_61;
  }
  *(_QWORD *)(v22 + 28568) = -1LL << max_event_rings;
  if ( *((_BYTE *)src + 72) == 1 )
    *(_QWORD *)(v22 + 28568) = (-1LL << max_event_rings) | (-1 << (src[20] + 1)) ^ (unsigned int)(-1 << src[19]);
  _gsi_config_type_irq(src[1], 0xFFFFFFFFLL);
  v23 = src[1];
  if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
  {
    _gsi_config_ch_irq(v23, 0xFFFFFFFFLL);
    _gsi_config_evt_irq(src[1], 0xFFFFFFFFLL);
    _gsi_config_ieob_irq(src[1], 0xFFFFFFFFLL, 0xFFFFFFFFLL);
  }
  else
  {
    _gsi_config_all_ch_irq(v23, 0xFFFFFFFFLL);
    _gsi_config_all_evt_irq(src[1], 0xFFFFFFFFLL);
    _gsi_config_all_ieob_irq(src[1], 0xFFFFFFFFLL);
  }
  v25 = _gsi_config_glob_irq(src[1], 0xFFFFFFFFLL, 0xFFFFFFFFLL);
  v26 = src[1];
  glob_irq_en_gp_int1_mask = gsihal_get_glob_irq_en_gp_int1_mask(v25);
  _gsi_config_glob_irq(v26, glob_irq_en_gp_int1_mask, 0);
  v28 = *(unsigned int *)(gsi_ctx + 20);
  LODWORD(v42) = 65793;
  ((void (__fastcall *)(__int64, __int64, __int64 *))gsihal_write_reg_n_fields)(5, v28, &v42);
  gsihal_write_reg_nk(32, *(unsigned int *)(gsi_ctx + 20), 0);
  v29 = gsi_ctx;
  if ( *(_DWORD *)(gsi_ctx + 16) >= 4u && src[2] )
  {
    gsihal_write_reg_nk(33, *(unsigned int *)(gsi_ctx + 20), 0);
    gsihal_write_reg_nk(34, *(unsigned int *)(gsi_ctx + 20), 0);
    v29 = gsi_ctx;
  }
  ((void (__fastcall *)(__int64, _QWORD, char *))gsihal_read_reg_n_fields)(
    35,
    *(unsigned int *)(v29 + 20),
    (char *)&v42 + 4);
  v30 = gsi_ctx;
  if ( BYTE4(v42) )
  {
    *(_BYTE *)(gsi_ctx + 28576) = 1;
  }
  else
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d Manager EE has not enabled GSI, GSI un-usable\n",
      "gsi_register_device",
      1740);
    v30 = gsi_ctx;
  }
  if ( *(_DWORD *)(v30 + 16) >= 2u )
  {
    gsihal_write_reg_nk(14, *(unsigned int *)(v30 + 20), 0);
    v30 = gsi_ctx;
  }
  *a2 = v30;
  result = 0;
  *(_DWORD *)(gsi_ctx + 29264) = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
