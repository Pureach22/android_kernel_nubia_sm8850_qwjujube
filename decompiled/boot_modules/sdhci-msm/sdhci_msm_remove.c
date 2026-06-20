__int64 __fastcall sdhci_msm_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 *v3; // x24
  _BOOL8 v4; // x1
  __int64 *v5; // x25
  unsigned int v6; // w26
  __int64 v7; // x8
  __int64 v8; // x23
  char v9; // w8
  __int64 v10; // x8
  unsigned __int64 v11; // x22
  unsigned __int64 v12; // x8
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x23
  unsigned __int64 v17; // x22
  unsigned int v18; // w8
  unsigned int v24; // w10
  unsigned __int64 v25; // x21
  __int64 v26; // x20

  if ( of_find_property(*(_QWORD *)(a1 + 760), "non-removable", 0) && (is_bootdevice_sdhci & 1) == 0 )
    return dev_err(a1 + 16, "SDHCI is not boot dev.\n");
  v2 = *(_QWORD *)(a1 + 168);
  v3 = *(__int64 **)(v2 + 1872);
  v4 = (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v2 + 24) + 48LL)) == -1;
  sdhci_remove_host(v2, v4);
  if ( *(_BYTE *)(v2 + 1548) == 1 )
    dev_pm_opp_of_remove_table(a1 + 16);
  dev_pm_opp_clear_config(*(unsigned int *)(v2 + 1544));
  _pm_runtime_resume(a1 + 16, 4);
  if ( v3 )
  {
    v5 = (__int64 *)*v3;
    msleep(50);
    if ( *((_DWORD *)v3 + 2) )
    {
      v6 = 0;
      do
      {
        v7 = v5[4];
        v8 = v5[2];
        if ( *(_QWORD *)(v7 + 752) && *(_BYTE *)(v7 + 760) == 1 )
          ipc_log_string();
        v9 = 0;
        do
        {
          v10 = -1LL << v9;
          v11 = (unsigned int)v10 & *(_DWORD *)v5;
          if ( ((unsigned int)v10 & *(_DWORD *)v5) == 0 )
            break;
          if ( (dev_pm_qos_update_request(v8, 0x7FFFFFFF) & 0x80000000) != 0 )
            goto LABEL_18;
          v8 += 80;
          v12 = __clz(__rbit64(v11));
          _CF = v12 >= 0x1F;
          v9 = v12 + 1;
        }
        while ( !_CF );
        *((_BYTE *)v5 + 24) = 0;
        *((_BYTE *)v5 + 41) = 1;
LABEL_18:
        v14 = *v5;
        v15 = (unsigned int)*v5;
        if ( (unsigned int)*v5 )
        {
          v16 = v5[2];
          do
          {
            v17 = __clz(__rbit64(v15));
            if ( *(_QWORD *)(v16 + 72) )
            {
              if ( (dev_pm_qos_remove_request(v16) & 0x80000000) != 0 || v17 > 0x1E )
                break;
              v14 = *v5;
            }
            else if ( v17 > 0x1E )
            {
              break;
            }
            v16 += 80;
            v15 = (unsigned int)(-2LL << v17) & (unsigned int)v14;
          }
          while ( ((unsigned int)(-2LL << v17) & (unsigned int)v14) != 0 );
        }
        ++v6;
        v5 += 6;
      }
      while ( v6 < *((_DWORD *)v3 + 2) );
    }
    destroy_workqueue(*(_QWORD *)(v2 + 1864));
  }
  _pm_runtime_disable(a1 + 16, 1);
  v18 = *(_DWORD *)(a1 + 496);
  do
  {
    if ( !v18 )
      break;
    _X12 = (unsigned int *)(a1 + 496);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v24 = __ldxr(_X12);
      if ( v24 != v18 )
        break;
      if ( !__stlxr(v18 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v24 == v18;
    v18 = v24;
  }
  while ( !_ZF );
  clk_bulk_disable(4, v2 + 1448);
  clk_bulk_unprepare(4, v2 + 1448);
  v25 = *(_QWORD *)(v2 + 1432);
  if ( v25 <= 0xFFFFFFFFFFFFF000LL )
  {
    clk_disable(*(_QWORD *)(v2 + 1432));
    clk_unprepare(v25);
  }
  if ( (*(_BYTE *)(v2 + 1641) & 1) == 0 )
  {
    sdhci_msm_bus_get_and_set_vote(v2, 0);
    v26 = *(_QWORD *)(v2 + 1648);
    if ( *(_QWORD *)(v26 + 40) )
      icc_put();
    if ( *(_QWORD *)(v26 + 48) )
      icc_put();
  }
  return sdhci_pltfm_free(a1);
}
