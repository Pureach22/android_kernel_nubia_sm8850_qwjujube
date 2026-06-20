__int64 __fastcall sde_core_perf_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char *a5)
{
  int v5; // w21
  __int64 v7; // x8
  __int64 result; // x0
  __int64 phandle; // x0
  __int64 clk; // x0
  __int64 max_rate; // x0

  if ( a1 && a2 && a3 && (v5 = a4, a4) && a5 )
  {
    v7 = *(_QWORD *)(a2 + 56);
    *(_QWORD *)a1 = a2;
    *(_QWORD *)(a1 + 16) = a3;
    *(_QWORD *)(a1 + 24) = a4;
    *(_QWORD *)(a1 + 32) = a5;
    *(_BYTE *)(a1 + 132) = 0;
    *(_DWORD *)(a1 + 128) = 0;
    if ( *(_DWORD *)(v7 + 5912) == 1 )
    {
      *(_DWORD *)(a1 + 152) = *(_DWORD *)(a3 + 19880);
      *(_QWORD *)(a1 + 56) = *(unsigned int *)(a3 + 19884);
      return 0;
    }
    else
    {
      phandle = sde_cesta_get_phandle(**(unsigned int **)(a2 + 64));
      *(_QWORD *)(a1 + 160) = phandle;
      if ( phandle )
        v5 = phandle;
      clk = sde_power_clk_get_clk(v5, a5);
      *(_QWORD *)(a1 + 40) = clk;
      if ( clk )
      {
        max_rate = sde_power_clk_get_max_rate(v5, a5);
        *(_QWORD *)(a1 + 56) = max_rate;
        if ( !max_rate )
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "optional max core clk rate, use default\n");
          *(_QWORD *)(a1 + 56) = 320000000;
        }
        result = 0;
        *(_DWORD *)(a1 + 152) = -1;
      }
      else
      {
        printk(&unk_2160BA, "sde_core_perf_init");
        debugfs_remove(*(_QWORD *)(a1 + 8));
        *(_QWORD *)(a1 + 56) = 0;
        *(_QWORD *)a1 = 0;
        *(_QWORD *)(a1 + 8) = 0;
        *(_QWORD *)(a1 + 16) = 0;
        *(_QWORD *)(a1 + 24) = 0;
        *(_QWORD *)(a1 + 32) = 0;
        *(_QWORD *)(a1 + 40) = 0;
        return 4294967277LL;
      }
    }
  }
  else
  {
    printk(&unk_27D28A, "sde_core_perf_init");
    return 4294967274LL;
  }
  return result;
}
