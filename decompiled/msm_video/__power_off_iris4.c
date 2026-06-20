__int64 __fastcall _power_off_iris4(__int64 a1)
{
  __int64 v2; // x8
  unsigned int (__fastcall *v3)(__int64, __int64); // x20
  __int64 min_clock_index; // x1
  __int64 v5; // x8
  unsigned int (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x8
  unsigned int v8; // w23
  __int64 v9; // x25
  bool v10; // w22
  int v11; // w24
  __int64 v12; // x26
  void *v13; // x0
  const char *v14; // x4
  unsigned int v15; // w20
  int v16; // w20
  __int64 v17; // x8
  unsigned int (__fastcall *v18)(__int64, const char *); // x8
  __int64 v19; // x8
  unsigned int (__fastcall *v20)(__int64, const char *); // x8
  __int64 v21; // x8
  _DWORD *v22; // x8
  __int64 v23; // x8
  unsigned int (__fastcall *v24)(__int64, __int64); // x8
  __int64 v25; // x1
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (is_core_sub_state(a1, 1) & 1) != 0 )
  {
    if ( a1 )
    {
      v2 = *(_QWORD *)(a1 + 6552);
      if ( v2 )
      {
        v3 = *(unsigned int (__fastcall **)(__int64, __int64))(v2 + 104);
        if ( !v3 )
          goto LABEL_9;
        min_clock_index = (unsigned int)get_min_clock_index(a1);
        if ( *((_DWORD *)v3 - 1) != -1742341011 )
          __break(0x8234u);
        if ( v3(a1, min_clock_index) && (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_9528C, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4");
          v5 = *(_QWORD *)(a1 + 6552);
          if ( !v5 )
            goto LABEL_16;
        }
        else
        {
LABEL_9:
          v5 = *(_QWORD *)(a1 + 6552);
          if ( !v5 )
            goto LABEL_16;
        }
        v6 = *(unsigned int (__fastcall **)(_QWORD))(v5 + 80);
        if ( v6 )
        {
          if ( *((_DWORD *)v6 - 1) != -1850880742 )
            __break(0x8228u);
          if ( v6(a1) && (msm_vidc_debug & 1) != 0 )
            printk(&unk_8B16E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4");
        }
      }
    }
LABEL_16:
    v7 = *(_QWORD *)(a1 + 3912);
    v27 = 0;
    v8 = *(_DWORD *)(v7 + 40);
    if ( v8 )
    {
      v9 = *(_QWORD *)(v7 + 32);
      v10 = 0;
      v11 = 0;
      while ( 1 )
      {
        v12 = v9 + 16LL * v11;
        if ( !strcmp(*(const char **)v12, "apv") && (*(_BYTE *)(v12 + 9) & 1) == 0 )
          break;
        v10 = ++v11 >= v8;
        if ( v8 == v11 )
          goto LABEL_22;
      }
      if ( (msm_vidc_debug & 2) == 0 )
      {
LABEL_22:
        if ( !v10 )
          goto LABEL_78;
        goto LABEL_23;
      }
      printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
      if ( v10 )
        goto LABEL_23;
      goto LABEL_78;
    }
LABEL_23:
    if ( (unsigned int)_read_register(a1, 0xB0008u, &v27) )
      goto LABEL_24;
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 3912) + 328LL) == 4 || (v27 & 0x8000000) != 0 )
      goto LABEL_78;
    if ( (unsigned int)_read_register(a1, 0xB0088u, &v27) )
      goto LABEL_24;
    if ( (v27 & 2) != 0 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8E079, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
      if ( (unsigned int)_write_register(a1, 0xB0088u, 0) )
        goto LABEL_24;
    }
    if ( (unsigned int)_write_register_masked(a1, 0xE0000u, 1, 1) || (unsigned int)_read_register(a1, 0xE0004u, &v27) )
      goto LABEL_24;
    v16 = 1000;
    while ( (v27 & 1) == 0 && (v27 & 6) != 0 )
    {
      if ( (unsigned int)_write_register_masked(a1, 0xE0000u, 0, 1) )
        goto LABEL_24;
      usleep_range_state(10, 20, 2);
      if ( (unsigned int)_write_register_masked(a1, 0xE0000u, 1, 1) || (unsigned int)_read_register(a1, 0xE0004u, &v27) )
        goto LABEL_24;
      if ( !--v16 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_85640, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
        break;
      }
    }
    if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xE0004u, 1, 1, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
      printk(&unk_9059F, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
    if ( (unsigned int)_write_register_masked(a1, 0xE0000u, 0, 1)
      || (unsigned int)_write_register(a1, 0x1F000u, 0x80200u) )
    {
      goto LABEL_24;
    }
    if ( (unsigned int)_read_register_with_poll_timeout(a1, 0x1F004u, -1, 524800, 0xC8u, 0x7D0u)
      && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8326E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
    }
    if ( (unsigned int)_write_register(a1, 0x1F008u, 0x80200u)
      || (unsigned int)_write_register(a1, 0x1F008u, 0)
      || (unsigned int)_write_register(a1, 0x1F000u, 0) )
    {
      goto LABEL_24;
    }
    if ( (unsigned int)_read_register_with_poll_timeout(a1, 0x1F004u, -1, 0, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8326E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
    if ( (unsigned int)_write_register(a1, 0xA0174u, 3u)
      || (unsigned int)_write_register(a1, 0xA0174u, 2u)
      || (unsigned int)_write_register(a1, 0xA0174u, 0) )
    {
LABEL_24:
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_78;
      v13 = &unk_81E1B;
      v14 = "__power_off_iris4";
    }
    else
    {
      if ( !a1 )
        goto LABEL_78;
      v17 = *(_QWORD *)(a1 + 6552);
      if ( !v17 )
        goto LABEL_78;
      v18 = *(unsigned int (__fastcall **)(__int64, const char *))(v17 + 64);
      if ( !v18 )
        goto LABEL_70;
      if ( *((_DWORD *)v18 - 1) != 841426229 )
        __break(0x8228u);
      if ( v18(a1, "apv") && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_88CBE, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_apv");
        v19 = *(_QWORD *)(a1 + 6552);
        if ( !v19 )
          goto LABEL_78;
      }
      else
      {
LABEL_70:
        v19 = *(_QWORD *)(a1 + 6552);
        if ( !v19 )
          goto LABEL_78;
      }
      v20 = *(unsigned int (__fastcall **)(__int64, const char *))(v19 + 112);
      if ( !v20 )
        goto LABEL_78;
      if ( *((_DWORD *)v20 - 1) != 841426229 )
        __break(0x8228u);
      if ( !v20(a1, "video_cc_mvs0a_clk") || (msm_vidc_debug & 1) == 0 )
      {
LABEL_78:
        if ( (unsigned int)_power_off_iris4_hardware(a1) && (msm_vidc_debug & 1) != 0 )
          printk(&unk_93786, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4");
        if ( (unsigned int)_power_off_iris4_controller(a1) && (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_84AEE, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4");
          if ( a1 )
            goto LABEL_84;
        }
        else if ( a1 )
        {
LABEL_84:
          v21 = *(_QWORD *)(a1 + 6552);
          if ( v21 )
          {
            v22 = *(_DWORD **)(v21 + 96);
            if ( !v22 )
            {
              v15 = 0;
              v23 = *(_QWORD *)(a1 + 6544);
              if ( !v23 )
                goto LABEL_103;
              goto LABEL_94;
            }
            if ( *(v22 - 1) != -219393110 )
              __break(0x8228u);
            v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v22)(a1, 0, 0);
            if ( v15 && (msm_vidc_debug & 1) != 0 )
            {
              printk(&unk_97641, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4");
              v23 = *(_QWORD *)(a1 + 6544);
              if ( !v23 )
                goto LABEL_103;
LABEL_94:
              v24 = *(unsigned int (__fastcall **)(__int64, __int64))(v23 + 48);
              if ( v24 )
              {
                v25 = *(unsigned int *)(a1 + 3920);
                if ( *((_DWORD *)v24 - 1) != -2114196824 )
                  __break(0x8228u);
                if ( v24(a1, v25) )
                  goto LABEL_104;
              }
              goto LABEL_103;
            }
          }
          else
          {
            v15 = 0;
          }
          v23 = *(_QWORD *)(a1 + 6544);
          if ( v23 )
            goto LABEL_94;
LABEL_103:
          disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 8LL));
LABEL_104:
          msm_vidc_change_core_sub_state(a1, 1, 0, "__power_off_iris4");
          goto LABEL_105;
        }
        v15 = 0;
        goto LABEL_103;
      }
      v13 = &unk_87F1A;
      v14 = "__power_off_iris4_apv";
    }
    printk(v13, "err ", 0xFFFFFFFFLL, "codec", v14);
    goto LABEL_78;
  }
  v15 = 0;
LABEL_105:
  _ReadStatusReg(SP_EL0);
  return v15;
}
