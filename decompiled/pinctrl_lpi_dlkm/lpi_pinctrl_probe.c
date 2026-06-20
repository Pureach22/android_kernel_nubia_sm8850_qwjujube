__int64 __fastcall lpi_pinctrl_probe(_QWORD *a1)
{
  unsigned int variable_u32_array; // w0
  unsigned int v3; // w0
  int v4; // w8
  unsigned int v5; // w0
  _DWORD *v6; // x23
  int v7; // w0
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  unsigned int v10; // w19
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  char *v14; // x10
  unsigned __int64 v15; // x12
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x9
  __int64 v20; // x10
  char *v21; // x10
  unsigned __int64 v22; // x12
  __int64 **v23; // x0
  __int64 **v24; // x24
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned __int64 v27; // x27
  __int64 v28; // x0
  unsigned __int64 v29; // x22
  __int64 v30; // x28
  __int64 v31; // x0
  __int64 v32; // x25
  __int64 v33; // x0
  __int64 v34; // x21
  __int64 v35; // x8
  __int64 v36; // x1
  int v37; // w9
  __int64 v38; // x0
  int v39; // w16
  __int64 v40; // x19
  __int64 v41; // x14
  __int64 v42; // x26
  unsigned __int64 v43; // x24
  unsigned __int64 v44; // x20
  char **v45; // x15
  _DWORD *v46; // x8
  int v47; // w10
  __int64 v48; // x1
  _DWORD *v49; // x21
  char **v50; // x23
  __int64 v51; // x0
  __int16 v53; // w19
  __int64 *v54; // x8
  unsigned __int64 v55; // x0
  unsigned int v56; // w0
  __int64 v57; // x1
  unsigned int v58; // w0
  unsigned int v59; // w0
  unsigned int v60; // w0
  unsigned __int64 v61; // x0
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x0
  unsigned __int64 v64; // x8
  __int64 v65; // [xsp+0h] [xbp-40h]
  __int64 **v66; // [xsp+8h] [xbp-38h]
  __int64 v67; // [xsp+10h] [xbp-30h]
  _QWORD *v68; // [xsp+18h] [xbp-28h]
  __int64 *v69; // [xsp+20h] [xbp-20h]
  unsigned int v70; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v71[2]; // [xsp+30h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71[0] = 0;
  v70 = 0;
  if ( (audio_notifier_probe_status() & 1) == 0 )
  {
    printk(&unk_8257, "lpi_pinctrl_probe");
    v10 = -517;
    goto LABEL_69;
  }
  variable_u32_array = of_property_read_variable_u32_array(a1[95], "reg", v71, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v10 = variable_u32_array;
    dev_err(a1 + 2, "missing base address\n");
    goto LABEL_69;
  }
  v3 = of_property_read_variable_u32_array(a1[95], "qcom,gpios-count", (char *)v71 + 4, 1, 0);
  if ( (v3 & 0x80000000) != 0 )
  {
    v10 = v3;
    goto LABEL_69;
  }
  v4 = HIDWORD(v71[0]);
  if ( HIDWORD(v71[0]) >= 0x21 )
  {
    __break(0x800u);
    v4 = HIDWORD(v71[0]);
  }
  v5 = of_property_read_variable_u32_array(a1[95], "qcom,lpi-offset-tbl", &lpi_offset, v4, 0);
  if ( (v5 & 0x80000000) != 0 )
  {
    v10 = v5;
    dev_err(a1 + 2, "error in reading lpi offset table: %d\n", v5);
    goto LABEL_69;
  }
  v6 = &lpi_slew_offset;
  v68 = a1;
  v69 = a1 + 2;
  v7 = of_property_read_variable_u32_array(a1[95], "qcom,lpi-slew-offset-tbl", &lpi_slew_offset, SHIDWORD(v71[0]), 0);
  v8 = HIDWORD(v71[0]);
  if ( v7 < 0 && SHIDWORD(v71[0]) >= 1 )
  {
    if ( HIDWORD(v71[0]) >= 3 )
    {
      v11 = HIDWORD(v71[0]) - 1LL;
      if ( v11 >= 0x64 )
        v11 = 100;
      v12 = v11 + 1;
      v13 = v12 & 1;
      if ( (v12 & 1) == 0 )
        v13 = 2;
      v9 = v12 - v13;
      v14 = (char *)&unk_8834;
      v15 = v9;
      do
      {
        v15 -= 2LL;
        *(_QWORD *)(v14 - 4) = -1;
        v14 += 8;
      }
      while ( v15 );
    }
    else
    {
      v9 = 0;
    }
    while ( v9 != 100 )
    {
      if ( (v9 & 0x3FFFFFFFFFFFFFFFLL) == 0x64 )
        goto LABEL_97;
      *((_DWORD *)&lpi_slew_offset + v9++) = -1;
      if ( v8 == v9 )
        goto LABEL_21;
    }
LABEL_98:
    __break(0x5512u);
  }
LABEL_21:
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,lpi-slew-base-tbl", &lpi_slew_base, (int)v8, 0) & 0x80000000) != 0 )
  {
    v16 = HIDWORD(v71[0]);
    if ( SHIDWORD(v71[0]) >= 1 )
    {
      if ( HIDWORD(v71[0]) >= 3 )
      {
        v18 = HIDWORD(v71[0]) - 1LL;
        if ( v18 >= 0x64 )
          v18 = 100;
        v19 = v18 + 1;
        v20 = v19 & 1;
        if ( (v19 & 1) == 0 )
          v20 = 2;
        v17 = v19 - v20;
        v21 = (char *)&unk_89C4;
        v22 = v17;
        do
        {
          v22 -= 2LL;
          *(_QWORD *)(v21 - 4) = -1;
          v21 += 8;
        }
        while ( v22 );
      }
      else
      {
        v17 = 0;
      }
      while ( v17 != 100 )
      {
        if ( (v17 & 0x3FFFFFFFFFFFFFFFLL) == 0x64 )
          goto LABEL_97;
        *((_DWORD *)&lpi_slew_base + v17++) = -1;
        if ( v16 == v17 )
          goto LABEL_34;
      }
      goto LABEL_98;
    }
  }
LABEL_34:
  v23 = (__int64 **)devm_kmalloc(v69, 768, 3520);
  if ( !v23 )
    goto LABEL_68;
  v24 = v23;
  *v23 = v69;
  a1[21] = v23;
  v25 = a1[95];
  v70 = 0;
  if ( (of_property_read_variable_u32_array(v25, "qcom,slew-reg", &v70, 1, 0) & 0x80000000) != 0 )
  {
    v26 = 0;
  }
  else
  {
    v26 = devm_ioremap(v69, v70, 4096);
    if ( !v26 )
    {
      dev_err(v69, "%s devm_ioremap failed for slew rate reg\n", "lpi_pinctrl_probe");
LABEL_91:
      v10 = -12;
      goto LABEL_69;
    }
  }
  if ( !is_mul_ok(SHIDWORD(v71[0]), 0x18u) )
    goto LABEL_68;
  v67 = v26;
  v27 = 24LL * SHIDWORD(v71[0]);
  v28 = devm_kmalloc(v69, v27, 3520);
  if ( !v28
    || (v71[0] & 0x8000000000000000LL) != 0
    || (v29 = (unsigned __int64)HIDWORD(v71[0]) << 6, v30 = v28, (v31 = devm_kmalloc(v69, v29, 3520)) == 0)
    || (v32 = v31, (v33 = devm_kmalloc(v69, 88, 3520)) == 0) )
  {
LABEL_68:
    v10 = -12;
    goto LABEL_69;
  }
  v34 = v33;
  *(_QWORD *)(v33 + 24) = lpi_gpio_pinctrl_ops;
  *(_QWORD *)(v33 + 32) = &lpi_gpio_pinmux_ops;
  v35 = v68[16];
  *(_QWORD *)(v33 + 40) = &lpi_gpio_pinconf_ops;
  *(_QWORD *)(v33 + 48) = &_this_module;
  if ( !v35 )
    v35 = *v69;
  v36 = LODWORD(v71[0]);
  v37 = HIDWORD(v71[0]);
  *(_QWORD *)v33 = v35;
  *(_QWORD *)(v33 + 8) = v30;
  *(_DWORD *)(v33 + 16) = v37;
  v38 = devm_ioremap(v69, v36, 0x20000);
  if ( !v38 )
  {
    dev_err(v69, "%s devm_ioremap failed\n", "lpi_pinctrl_probe");
    goto LABEL_91;
  }
  v39 = HIDWORD(v71[0]);
  v40 = v38;
  v65 = v34;
  v66 = v24;
  v24[80] = (__int64 *)v38;
  if ( v39 >= 1 )
  {
    v41 = v67;
    v42 = 0;
    v43 = 0;
    v44 = 40;
    v45 = lpi_gpio_groups;
    while ( (__int64)(v43 + 16) >= 0 )
    {
      if ( v27 <= v43 + 16 )
        break;
      v46 = (_DWORD *)(v44 - 40 + v32);
      *(_QWORD *)(v30 + v43 + 16) = v46;
      if ( (v43 & 0x8000000000000000LL) != 0 || v27 <= v43 )
        break;
      *(_DWORD *)(v30 + v43) = v42;
      if ( v44 == 2088 )
        goto LABEL_98;
      if ( (v42 & 0x1FFFFFFFFFFFFFFFLL) == 0x20 )
        break;
      if ( (__int64)(v43 + 8) < 0 )
        break;
      if ( v27 <= v43 + 8 )
        break;
      *(_QWORD *)(v30 + v43 + 8) = v45[v42];
      if ( v29 < v44 - 16 )
        break;
      *(_QWORD *)(v32 + v44 - 16) = v40;
      if ( v29 < v44 - 8 )
        break;
      *(_QWORD *)(v32 + v44 - 8) = v41;
      if ( v29 < v44 - 24 )
        break;
      *(_QWORD *)(v32 + v44 - 24) = v40;
      if ( v29 < v44 - 36 )
        break;
      v47 = *((_DWORD *)&lpi_offset + v42);
      *(_DWORD *)(v32 + v44 - 36) = v47;
      if ( v29 < v44 - 32 )
        break;
      *(_DWORD *)(v32 + v44 - 32) = v6[v42];
      if ( v29 <= v44 - 40 )
        break;
      *v46 = v47;
      if ( v29 < v44 )
        break;
      v48 = *((unsigned int *)&lpi_slew_base + v42);
      *(_QWORD *)(v32 + v44) = 0;
      if ( (unsigned int)(v48 + 1) >= 2 )
      {
        v49 = v6;
        v50 = v45;
        v51 = devm_ioremap(v69, v48, 4);
        if ( v29 < v44 )
          break;
        v39 = HIDWORD(v71[0]);
        v41 = v67;
        v45 = v50;
        v6 = v49;
        *(_QWORD *)(v32 + v44) = v51;
      }
      ++v42;
      v43 += 24LL;
      v44 += 64LL;
      if ( v42 >= v39 )
        goto LABEL_70;
    }
LABEL_97:
    __break(1u);
    goto LABEL_98;
  }
LABEL_70:
  v53 = v39;
  memcpy(v66 + 2, &lpi_gpio_template, 0x270u);
  *((_DWORD *)v66 + 46) = -1;
  *((_WORD *)v66 + 94) = v53;
  v54 = (__int64 *)v68[16];
  v66[4] = v69;
  if ( !v54 )
    v54 = (__int64 *)*v69;
  v66[2] = v54;
  *((_DWORD *)v66 + 152) = 2;
  *((_BYTE *)v66 + 200) = 0;
  _mutex_init(v66 + 83, "&state->slew_access_lock", &lpi_pinctrl_probe___key);
  _mutex_init(v66 + 90, "&state->core_hw_vote_lock", &lpi_pinctrl_probe___key_15);
  v55 = devm_pinctrl_register(v69, v65, v66);
  v66[1] = (__int64 *)v55;
  if ( v55 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v55;
    goto LABEL_69;
  }
  v56 = gpiochip_add_data_with_key(v66 + 2, v66, 0, 0);
  if ( v56 )
  {
    v10 = v56;
    dev_err(*v66, "can't add gpio chip\n");
    goto LABEL_69;
  }
  v57 = v68[16];
  if ( !v57 )
    v57 = *v69;
  v58 = gpiochip_add_pin_range(v66 + 2, v57, 0, 0, HIDWORD(v71[0]));
  if ( v58 )
  {
    v10 = v58;
    dev_err(v69, "failed to add pin range\n");
LABEL_96:
    gpiochip_remove(v66 + 2);
    goto LABEL_69;
  }
  lpi_dev = (__int64)v69;
  lpi_dev_up = 1;
  initial_boot = 1;
  v59 = snd_event_client_register(v69, lpi_pinctrl_ssr_ops, 0);
  if ( v59 )
  {
    v10 = v59;
    dev_err(v69, "%s: snd_event registration failed, ret [%d]\n", "lpi_pinctrl_probe", v59);
    goto LABEL_96;
  }
  snd_event_notify(v69, 1);
  v60 = audio_notifier_register("lpi_tlmm", 0, &service_nb);
  if ( (v60 & 0x80000000) != 0 )
  {
    v10 = v60;
    printk(&unk_83CA, "lpi_pinctrl_probe");
    goto LABEL_96;
  }
  v61 = devm_clk_get(v69, "lpass_core_hw_vote");
  if ( v61 <= 0xFFFFFFFFFFFFF000LL )
    v62 = v61;
  else
    v62 = 0;
  v66[81] = (__int64 *)v62;
  v63 = devm_clk_get(v69, "lpass_audio_hw_vote");
  *((_BYTE *)v66 + 712) = 0;
  if ( v63 <= 0xFFFFFFFFFFFFF000LL )
    v64 = v63;
  else
    v64 = 0;
  v66[82] = (__int64 *)v64;
  pm_runtime_set_autosuspend_delay(v69, 100);
  _pm_runtime_use_autosuspend(v69, 1);
  _pm_runtime_set_status(v69, 2);
  pm_runtime_enable(v69);
  v10 = 0;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v10;
}
