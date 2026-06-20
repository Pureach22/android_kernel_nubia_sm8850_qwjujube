__int64 __fastcall kgsl_pwrctrl_pwrlevel_change(__int64 a1)
{
  unsigned int v1; // w23
  __int64 result; // x0
  unsigned int v4; // w20
  unsigned int v5; // w21
  __int64 updated; // x0
  int v7; // w8
  __int64 v8; // x1
  _DWORD *v9; // x8
  _DWORD *v10; // x8
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  int v14; // w21
  const char *v15; // x22
  int v16; // w0
  __int64 v17; // x20
  unsigned int v18; // w20
  int v19; // w0
  __int64 v20; // x20
  int v21; // w0
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w21

  v1 = *(_DWORD *)(a1 + 10040);
  result = ((__int64 (*)(void))kgsl_pwrctrl_adjust_pwrlevel)();
  if ( (_DWORD)result == v1 )
    return result;
  v4 = result;
  v5 = result;
  updated = kgsl_pwrscale_update_stats(a1);
  v7 = *(_DWORD *)(a1 + 10372);
  *(_DWORD *)(a1 + 10040) = v4;
  *(_DWORD *)(a1 + 10044) = v1;
  if ( (v7 < 0 || v4 < v1) && (*(_QWORD *)(a1 + 10372) = 0, v4 < v1) )
  {
    updated = kgsl_bus_update(a1, 1);
    v5 = *(_DWORD *)(a1 + 10040);
    if ( v5 >= 0x21 )
      goto LABEL_46;
  }
  else if ( v5 >= 0x21 )
  {
    goto LABEL_46;
  }
  if ( *(_DWORD *)(a1 + 11120) == 2 )
  {
    v8 = *(unsigned int *)(a1 + 10044);
    if ( (_DWORD)v8 != v5 )
    {
      v9 = *(_DWORD **)(*(_QWORD *)(a1 + 8752) + 224LL);
      if ( *(v9 - 1) != -50502248 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v9)(a1, v8, v5, 0);
      v5 = *(_DWORD *)(a1 + 10040);
    }
  }
  v10 = *(_DWORD **)(*(_QWORD *)(a1 + 8752) + 248LL);
  if ( *(v10 - 1) != -1642886764 )
    __break(0x8228u);
  updated = ((__int64 (__fastcall *)(__int64, _QWORD))v10)(a1, v5);
  v11 = *(unsigned int *)(a1 + 9120);
  if ( !(_DWORD)v11 )
  {
LABEL_22:
    if ( v4 <= v1 )
      goto LABEL_24;
    goto LABEL_23;
  }
  if ( (unsigned int)v11 >= 0x13
    || (*(_DWORD *)(a1 + 9124) >= *(_DWORD *)(a1 + 10040) ? (v12 = 200000000) : (v12 = 19200000),
        updated = clk_round_rate(*(_QWORD *)(a1 + 8840 + 8 * v11), v12),
        v13 = *(unsigned int *)(a1 + 9120),
        (unsigned int)v13 > 0x12) )
  {
LABEL_46:
    __break(0x5512u);
    return kgsl_pwrctrl_adjust_pwrlevel(updated);
  }
  v14 = updated;
  v15 = clocks[v13];
  v16 = clk_set_rate(*(_QWORD *)(a1 + 8840 + 8 * v13), (unsigned int)updated);
  if ( !v16 )
    goto LABEL_22;
  _warn_printk("%s set freq %d failed:%d\n", v15, v14, v16);
  __break(0x800u);
  if ( v4 > v1 )
LABEL_23:
    kgsl_bus_update(a1, 1);
LABEL_24:
  result = *(_QWORD *)(a1 + 8992);
  if ( result )
  {
    if ( *(_DWORD *)(a1 + 10040) || (*(_BYTE *)(a1 + 10448) & 1) != 0 )
    {
      if ( !*(_DWORD *)(a1 + 10044) && *(_BYTE *)(a1 + 10448) == 1 )
      {
        v17 = *(_QWORD *)(a1 + 8992);
        clk_disable(result);
        result = clk_unprepare(v17);
        *(_BYTE *)(a1 + 10448) = 0;
      }
      goto LABEL_35;
    }
    v18 = *(_DWORD *)(a1 + 10444);
    v19 = clk_set_rate(result, v18);
    if ( v19 )
    {
      _warn_printk("%s set freq %d failed:%d\n", "bimc_gpu_clk", v18, v19);
      __break(0x800u);
    }
    v20 = *(_QWORD *)(a1 + 8992);
    v21 = clk_prepare(v20);
    if ( v21 )
    {
      v23 = v21;
    }
    else
    {
      result = clk_enable(v20);
      if ( !(_DWORD)result )
      {
LABEL_34:
        *(_BYTE *)(a1 + 10448) = 1;
        goto LABEL_35;
      }
      v23 = result;
      clk_unprepare(v20);
    }
    result = dev_err(*(_QWORD *)a1, "GPU clock %s enable error:%d\n", "bimc_gpu_clk", v23);
    goto LABEL_34;
  }
LABEL_35:
  if ( *(_DWORD *)(a1 + 11120) == 2 && *(_DWORD *)(a1 + 10044) != *(_DWORD *)(a1 + 10040) )
  {
    v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8752) + 224LL);
    if ( *((_DWORD *)v22 - 1) != -50502248 )
      __break(0x8228u);
    return v22(a1);
  }
  return result;
}
