__int64 __fastcall sde_power_enable_power_domain(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  const char *v4; // x20
  __int64 v5; // x8
  int *v6; // x22
  unsigned __int64 v7; // x19
  __int64 v8; // x24
  char v10; // w23
  unsigned __int64 v11; // x0
  char v12; // w21
  unsigned int v13; // w0
  int v14; // w8
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w21
  unsigned int v18; // w19
  unsigned int v19; // w19

  if ( *(_DWORD *)(a1 + 472) < 2u )
    return 0;
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      printk(&unk_277E5C, "sde_power_get_pm_domain_name");
      printk(&unk_21A924, "sde_power_enable_power_domain");
      return 4294967274LL;
    }
    v4 = "core_int2_gdsc";
  }
  else
  {
    v4 = "core_gdsc";
  }
  v5 = a1 + 16LL * a2;
  v6 = (int *)(v5 + 480);
  if ( *(_DWORD *)(v5 + 484) )
  {
    v7 = *(_QWORD *)(v5 + 488);
    if ( a2 )
      goto LABEL_18;
  }
  else
  {
    if ( (a3 & 1) == 0 )
      goto LABEL_25;
    v8 = a1;
    v10 = a3;
    v11 = dev_pm_domain_attach_by_name(*(_QWORD *)(a1 + 96), v4);
    v7 = v11;
    *((_QWORD *)v6 + 1) = v11;
    if ( (!v11 || v11 >= 0xFFFFFFFFFFFFF001LL) && (_DWORD)v11 != -17 )
    {
      printk(&unk_277DF5, "sde_power_enable_power_domain");
      return (unsigned int)v7;
    }
    a3 = v10;
    a1 = v8;
    v6[1] = 1;
    if ( a2 )
      goto LABEL_18;
  }
  if ( (*(_BYTE *)(a1 + 468) & 1) != 0 && (sde_power_enable_power_domain_hw_mode & 1) == 0 )
  {
    sde_power_enable_power_domain_hw_mode = 1;
    v12 = a3;
    v13 = dev_pm_genpd_set_hwmode(v7, 1);
    a3 = v12;
    if ( v13 )
    {
      v18 = v13;
      printk(&unk_21E7BA, "sde_power_enable_power_domain");
      return v18;
    }
  }
LABEL_18:
  v14 = *v6;
  if ( (a3 & 1) == 0 )
  {
    if ( !v14 )
      return 0;
    v16 = _pm_runtime_idle(v7, 4);
    if ( (v16 & 0x80000000) != 0 && v16 != -17 )
    {
      v17 = v16;
      printk(&unk_269D8B, "sde_power_enable_power_domain");
      result = v17;
      if ( v17 != -11 )
        return result;
      usleep_range_state(1000, 1010, 2);
      _pm_runtime_resume(v7, 4);
      printk(&unk_277E1D, "sde_power_enable_power_domain");
      usleep_range_state(1000, 1010, 2);
      _pm_runtime_idle(v7, 4);
      printk(&unk_240127, "sde_power_enable_power_domain");
    }
LABEL_25:
    *v6 = 0;
    return 0;
  }
  if ( v14 == 1 )
    return 0;
  v15 = _pm_runtime_resume(v7, 4);
  if ( (v15 & 0x80000000) != 0 )
  {
    v19 = v15;
    printk(&unk_24D707, "sde_power_enable_power_domain");
    return v19;
  }
  else
  {
    *v6 = 1;
    return 0;
  }
}
