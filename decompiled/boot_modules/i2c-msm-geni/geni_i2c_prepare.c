__int64 __fastcall geni_i2c_prepare(_QWORD *a1)
{
  _BYTE *v2; // x21
  int v3; // w2
  unsigned int v4; // w20
  unsigned int qup_hw_version; // w0
  int v8; // w20
  __int64 v9; // x0
  unsigned __int64 v10; // x23
  char *v11; // x9
  unsigned __int16 *v12; // x25
  __int64 result; // x0
  __int64 v14; // x19
  __int64 v15; // x0

  if ( *((_DWORD *)a1 + 2270) )
    return 0;
  v2 = a1 + 1024;
  v3 = (unsigned __int8)((unsigned __int16)readl_relaxed((unsigned int *)(a1[620] + 104LL)) >> 8);
  if ( v3 == 3 )
  {
    if ( (unsigned int)readl_relaxed((unsigned int *)(a1[1] + 100LL)) )
    {
      *((_DWORD *)a1 + 2270) = 2;
      geni_se_select_mode(a1 + 620, 3);
      ipc_log_string(a1[637], "i2c in GSI ONLY mode\n");
      if ( !*a1 )
        goto LABEL_33;
LABEL_32:
      i2c_trace_log();
LABEL_33:
      if ( (v2[918] & 1) == 0 && (readl_relaxed((unsigned int *)(a1[1] + 3628LL)) & 0x8000) != 0 )
      {
        v15 = *a1;
        v2[921] = 1;
        dev_info(v15, "%s: RTL based SE\n", "geni_i2c_prepare");
      }
      if ( v2[914] == 1 )
      {
        ipc_log_string(a1[637], "%s: pm_runtime_get_sync bypassed\n", "geni_i2c_prepare");
        result = *a1;
        if ( !*a1 )
          return result;
        i2c_trace_log();
      }
      return 0;
    }
    if ( (v2[918] & 1) != 0 )
    {
      v4 = 16;
    }
    else
    {
      qup_hw_version = geni_se_get_qup_hw_version(a1 + 620);
      if ( ((qup_hw_version & 0xFFE0000) <= 0x90000 || qup_hw_version >> 28 != 3) && (qup_hw_version & 0xC0000000) == 0 )
        v8 = 4128768;
      else
        v8 = 16711680;
      v4 = (v8 & (unsigned int)readl_relaxed((unsigned int *)(a1[620] + 3620LL))) >> 16;
    }
    *((_DWORD *)a1 + 2270) = 1;
    *((_DWORD *)a1 + 4) = v4 - 1;
    v9 = geni_se_init(a1 + 620);
    if ( v2[921] == 1 )
    {
      v10 = *((unsigned int *)a1 + 1279);
      if ( (unsigned int)v10 < 4 )
      {
        v11 = (char *)&geni_i2c_hub_clk_map;
        goto LABEL_26;
      }
LABEL_45:
      __break(0x5512u);
      goto LABEL_46;
    }
    v10 = *((unsigned int *)a1 + 1279);
    if ( *((_DWORD *)a1 + 2239) == 3400000 )
    {
      if ( (unsigned int)v10 > 3 )
        goto LABEL_45;
      v11 = (char *)&geni_i2c_hs_clk_map;
    }
    else
    {
      if ( (unsigned int)v10 > 3 )
        goto LABEL_45;
      v11 = (char *)&geni_i2c_clk_map;
    }
LABEL_26:
    v12 = (unsigned __int16 *)&v11[12 * (unsigned int)v10];
    if ( (v2[918] & 1) == 0 )
      v9 = writel_relaxed(*((_DWORD *)a1 + 2240), (unsigned int *)(a1[1] + 124LL));
    if ( *((_DWORD *)a1 + 2239) == 3400000 )
    {
      writel_relaxed(0x1Cu, (unsigned int *)(a1[1] + 636LL));
      v9 = writel_relaxed(0x26u, (unsigned int *)(a1[1] + 616LL));
    }
    if ( v10 < 3 )
    {
      writel_relaxed((16 * v12[2]) | 1, (unsigned int *)(a1[1] + 72LL));
      writel_relaxed((v12[3] << 20) | (v12[4] << 10) | v12[5], (unsigned int *)(a1[1] + 632LL));
      __dsb(0xFu);
      geni_se_config_packing(a1 + 620, 8, 4, 1, 1, 1);
      ipc_log_string(a1[637], "i2c fifo/se-dma mode. fifo depth:%d\n", v4);
      if ( !*a1 )
        goto LABEL_33;
      goto LABEL_32;
    }
LABEL_46:
    __break(1u);
    return geni_i2c_lock_bus(v9);
  }
  dev_err(*a1, "Invalid proto %d\n", v3);
  if ( (v2[912] & 1) != 0 )
    return 4294967290LL;
  geni_se_resources_off(a1 + 620);
  geni_icc_disable(a1 + 620);
  if ( v2[918] != 1 )
    return 4294967290LL;
  v14 = a1[634];
  clk_disable(v14);
  clk_unprepare(v14);
  return 4294967290LL;
}
