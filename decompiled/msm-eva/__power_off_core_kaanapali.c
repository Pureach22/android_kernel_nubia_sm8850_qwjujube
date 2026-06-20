__int64 __fastcall _power_off_core_kaanapali(__int64 a1)
{
  int v2; // w0
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x8
  void (__fastcall *v6)(_QWORD); // x8
  char *v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w20
  int i; // w23
  unsigned int v12; // w0
  unsigned int v13; // w22
  __int64 v14; // x8
  void (__fastcall *v15)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8

  v2 = _read_register(a1, 0xF8068u);
  if ( (v2 & 0x80000000) == 0 )
  {
    if ( (unsigned int)_read_register(a1, 0x1F004u) )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_891CB, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        if ( a1 )
          goto LABEL_6;
      }
      else if ( a1 )
      {
LABEL_6:
        v5 = *(_QWORD *)(a1 + 2512);
        if ( v5 )
        {
          v6 = *(void (__fastcall **)(_QWORD))(v5 + 72);
          if ( v6 )
          {
            if ( *((_DWORD *)v6 - 1) != -639316779 )
              __break(0x8228u);
            v6(a1);
          }
        }
      }
    }
LABEL_67:
    _disable_gdsc(a1, "core");
    v7 = "core_clk";
    goto LABEL_68;
  }
  if ( (v2 & 2) != 0 || !msm_cvp_fw_low_power_mode )
  {
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_8D859, &unk_8DA84, v3, v4);
    v10 = _read_register(a1, 0xB0088u);
    if ( v10 )
    {
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
        printk(&unk_8FD4F, &unk_8DA84, v8, v9);
      _write_register(a1, 0xB0088u, 0);
    }
    if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
    {
      usleep_range_state(1000, 2000, 2);
      if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
      {
        usleep_range_state(1000, 2000, 2);
        if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
        {
          usleep_range_state(1000, 2000, 2);
          if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
          {
            usleep_range_state(1000, 2000, 2);
            if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
            {
              usleep_range_state(1000, 2000, 2);
              if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
              {
                usleep_range_state(1000, 2000, 2);
                if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
                {
                  usleep_range_state(1000, 2000, 2);
                  if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
                  {
                    usleep_range_state(1000, 2000, 2);
                    if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
                    {
                      usleep_range_state(1000, 2000, 2);
                      if ( (_read_register(a1, 0x50u) & 0x400000) == 0 )
                      {
                        usleep_range_state(1000, 2000, 2);
                        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
                        {
                          v20 = _ReadStatusReg(SP_EL0);
                          printk(&unk_88910, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), "warn");
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    _write_register(a1, 0x1A018u, 1u);
    _write_register(a1, 0xE0008u, 1u);
    for ( i = 0; i != 2000; ++i )
    {
      v12 = _read_register(a1, 0xE000Cu);
      v13 = v12;
      if ( (v12 & 2) == 0 && (v12 & 5) != 4 )
        break;
      _write_register(a1, 0xE0008u, 0);
      usleep_range_state(10, 20, 2);
      _write_register(a1, 0x1A018u, 1u);
      _write_register(a1, 0xE0008u, 1u);
      usleep_range_state(1000, 1200, 2);
    }
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8CDEA, &unk_8DA84, "__enter_core_noc_lpi", v13);
      if ( i != 2000 )
        goto LABEL_50;
    }
    else if ( i != 2000 )
    {
      goto LABEL_50;
    }
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v19 = _ReadStatusReg(SP_EL0);
      printk(&unk_89AF0, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), "warn");
      if ( a1 )
        goto LABEL_45;
    }
    else if ( a1 )
    {
LABEL_45:
      v14 = *(_QWORD *)(a1 + 2512);
      if ( v14 )
      {
        v15 = *(void (__fastcall **)(_QWORD))(v14 + 72);
        if ( v15 )
        {
          if ( *((_DWORD *)v15 - 1) != -639316779 )
            __break(0x8228u);
          v15(a1);
        }
      }
    }
LABEL_50:
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0xE000Cu);
    usleep_range_state(1000, 2000, 2);
    _write_register(a1, 0xE0008u, 0);
    _write_register(a1, 0x1F000u, 0xFFFF0000);
    _write_register(a1, 0x1F000u, 0xFFFF5FBF);
    if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
    {
      usleep_range_state(1000, 2000, 2);
      if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
      {
        usleep_range_state(1000, 2000, 2);
        if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
        {
          usleep_range_state(1000, 2000, 2);
          if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
          {
            usleep_range_state(1000, 2000, 2);
            if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
            {
              usleep_range_state(1000, 2000, 2);
              if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
              {
                usleep_range_state(1000, 2000, 2);
                if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
                {
                  usleep_range_state(1000, 2000, 2);
                  if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
                  {
                    usleep_range_state(1000, 2000, 2);
                    if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
                    {
                      usleep_range_state(1000, 2000, 2);
                      if ( (_read_register(a1, 0x1F004u) & 0x5FBF) == 0 )
                      {
                        usleep_range_state(1000, 2000, 2);
                        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
                        {
                          v21 = _ReadStatusReg(SP_EL0);
                          printk(&unk_910E4, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), "warn");
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    _write_register(a1, 0x1F008u, 0x5FBFu);
    _write_register(a1, 0x1F008u, 0);
    _write_register(a1, 0x1F000u, 0xFFFF0000);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    _read_register(a1, 0x1F004u);
    usleep_range_state(1000, 2000, 2);
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v18 = _ReadStatusReg(SP_EL0);
      printk(&unk_910E4, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), "warn");
    }
    _write_register(a1, 0x1F000u, 0xFFFF0000);
    _write_register(a1, 0x1F000u, 0);
    _write_register(a1, 0xA0160u, 3u);
    _write_register(a1, 0xA0160u, 2u);
    _write_register(a1, 0xA0160u, 0);
    _write_register(a1, 0xB0088u, v10);
    goto LABEL_67;
  }
  _disable_gdsc(a1, "core");
  msm_cvp_disable_unprepare_clk(a1, "core_clk");
  v7 = "core_freerun_clk";
LABEL_68:
  msm_cvp_disable_unprepare_clk(a1, v7);
  return 0;
}
