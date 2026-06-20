__int64 __fastcall wcd939x_bind(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int v4; // w0
  unsigned int v5; // w22
  __int64 matching_swr_slave_device; // x0
  __int64 v7; // x0
  const char *v9; // x3
  unsigned int v10; // w8
  __int64 v11; // x0
  __int64 inited; // x0
  __int64 v13; // x0
  int v14; // w23
  __int64 v15; // x10
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x0
  _BYTE v20[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v21[4]; // [xsp+10h] [xbp-10h] BYREF
  int v22; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 144);
  v2 = *(_QWORD *)(a1 + 152);
  v22 = 0;
  v21[0] = 0;
  v20[0] = 0;
  usleep_range_state(5000, 5010, 2);
  v4 = component_bind_all(a1, v2);
  if ( v4 )
  {
    v5 = v4;
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs, "wcd939x_bind") )
      dev_err(a1, "%s: Slave bind failed, ret = %d\n", "wcd939x_bind", v5);
    goto LABEL_12;
  }
  matching_swr_slave_device = get_matching_swr_slave_device(*(_QWORD *)(v3 + 8));
  *(_QWORD *)(v2 + 40) = matching_swr_slave_device;
  if ( !matching_swr_slave_device )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_119, "wcd939x_bind") )
      dev_err(a1, "%s: Could not find RX swr slave device\n", "wcd939x_bind");
    goto LABEL_10;
  }
  v7 = get_matching_swr_slave_device(*(_QWORD *)(v3 + 16));
  *(_QWORD *)(v2 + 48) = v7;
  if ( !v7 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_121, "wcd939x_bind") )
      dev_err(a1, "%s: Could not find TX swr slave device\n", "wcd939x_bind");
LABEL_10:
    v5 = -19;
LABEL_11:
    component_unbind_all(a1, v2);
    goto LABEL_12;
  }
  swr_init_port_params(v7, 4, v2 + 3080);
  swr_read(*(_QWORD *)(v2 + 48), *(unsigned __int8 *)(*(_QWORD *)(v2 + 48) + 64LL), 13314, v21, 1);
  swr_read(*(_QWORD *)(v2 + 48), *(unsigned __int8 *)(*(_QWORD *)(v2 + 48) + 64LL), 12527, v20, 1);
  if ( v21[0] )
  {
    if ( v21[0] == 1 )
    {
      v9 = "WCD939X_2_0";
      *(_DWORD *)(v2 + 3176) = 2;
      wcd939x_version = 2;
      goto LABEL_21;
    }
    v10 = *(_DWORD *)(v2 + 3176);
  }
  else
  {
    v10 = (v20[0] & 3) != 0;
    *(_DWORD *)(v2 + 3176) = v10;
  }
  wcd939x_version = v10;
  if ( v10 > 2 )
    v9 = nullptr;
  else
    v9 = off_26800[v10];
LABEL_21:
  dev_info(a1, "%s: wcd9395 version: %s\n", "wcd939x_bind", v9);
  v11 = *(_QWORD *)(v2 + 48);
  qword_31D8 = (__int64)wcd939x_readable_register;
  inited = _devm_regmap_init_swr(v11, &wcd939x_regmap_config, 0, 0);
  *(_QWORD *)(v2 + 32) = inited;
  if ( !inited )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_124, "wcd939x_bind") )
      dev_err(a1, "%s: Regmap init failed\n", "wcd939x_bind");
    v5 = 0;
    goto LABEL_11;
  }
  v13 = regmap_read(inited, 13505, &v22);
  if ( wcd939x_version == 2 && v22 <= 2 )
    wcd_usbss_update_default_trim(v13);
  wcd939x_update_regmap_cache(v2);
  if ( dword_8A8 >= 1 )
  {
    v14 = 0;
    do
    {
      regmap_write(*(_QWORD *)(v2 + 32), (unsigned int)(v14 + 13428), 0);
      ++v14;
    }
    while ( v14 < dword_8A8 );
  }
  qword_8F0 = v2;
  v15 = *(_QWORD *)(v2 + 32);
  *(_QWORD *)(v2 + 328) = &wcd939x_regmap_irq_chip;
  *(_QWORD *)(v2 + 336) = "WCD939X";
  *(_QWORD *)(v2 + 360) = a1;
  *(_QWORD *)(v2 + 344) = v15;
  v16 = wcd_irq_init(v2 + 328, v2 + 320);
  if ( v16 )
  {
    v5 = v16;
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_127, "wcd939x_bind") )
      dev_err(*(_QWORD *)v2, "%s: IRQ init failed: %d\n", "wcd939x_bind", v5);
    goto LABEL_11;
  }
  *(_QWORD *)(*(_QWORD *)(v2 + 48) + 1000LL) = *(_QWORD *)(v2 + 320);
  v17 = wcd939x_set_micbias_data(v2, v3);
  if ( (v17 & 0x80000000) != 0 )
  {
    v5 = v17;
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_129, "wcd939x_bind") )
      dev_err(a1, "%s: bad micbias pdata\n", "wcd939x_bind");
    goto LABEL_40;
  }
  wcd_request_irq(v2 + 328, 12, "HPHR PDM WD INT", wcd939x_wd_handle_irq, 0);
  wcd_request_irq(v2 + 328, 11, "HPHL PDM WD INT", wcd939x_wd_handle_irq, 0);
  wcd_request_irq(v2 + 328, 13, "EAR PDM WD INT", wcd939x_wd_handle_irq, 0);
  wcd_disable_irq(v2 + 328, 12);
  wcd_disable_irq(v2 + 328, 11);
  wcd_disable_irq(v2 + 328, 13);
  v18 = snd_soc_register_component(a1, &soc_codec_dev_wcd939x, &wcd939x_dai, 1);
  if ( v18 )
  {
    v5 = v18;
    if ( (unsigned int)__ratelimit(&wcd939x_bind__rs_134, "wcd939x_bind") )
      dev_err(a1, "%s: Codec registration failed\n", "wcd939x_bind");
LABEL_40:
    wcd_irq_exit(v2 + 328, *(_QWORD *)(v2 + 320));
    goto LABEL_11;
  }
  v19 = *(_QWORD *)(v2 + 48);
  *(_BYTE *)(v2 + 3216) = 1;
  wcd939x_slave_register_notify(v19, wcd939x_handle_swrslv_reset, v2);
  v5 = wcd_init_mb_regulator(a1);
  if ( (v5 & 0x80000000) != 0 )
  {
    dev_err(a1, "Initialize wcd mb regulator failed, rc = %d\n", v5);
    v5 = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v5;
}
