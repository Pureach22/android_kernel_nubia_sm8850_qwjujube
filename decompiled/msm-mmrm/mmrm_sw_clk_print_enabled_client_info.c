__int64 __fastcall mmrm_sw_clk_print_enabled_client_info(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  unsigned int v8; // w23
  unsigned __int64 v9; // x8
  __int64 v10; // x21
  _BOOL4 v11; // w9
  __int64 v12; // x24
  unsigned __int64 v13; // x25
  __int64 v14; // x9
  __int64 v15; // x4
  unsigned int v16; // w5
  __int64 v17; // x10

  v6 = scnprintf(a2, a3, "  csid    clk_rate     vdd_level   cur_ma   num_hw_blocks\n");
  v8 = a3 - v6;
  v9 = *(unsigned int *)(a1 + 72);
  v10 = a2 + (unsigned int)v6;
  v11 = a3 - (unsigned int)v6 > 1;
  if ( (_DWORD)v9 && v8 >= 2 )
  {
    v12 = 684;
    v13 = 1;
    while ( 1 )
    {
      v14 = *(_QWORD *)(a1 + 64);
      if ( v14 + v12 != 684 )
      {
        v15 = *(_QWORD *)(v14 + v12 - 20);
        if ( v15 )
        {
          v16 = *(_DWORD *)(v14 + v12 - 12);
          if ( v16 >= 9 || (v17 = *(unsigned int *)(a1 + 132), (unsigned int)v17 > 8) )
          {
            __break(0x5512u);
            return mmrm_sw_print_client_data(v6, v7);
          }
          v6 = scnprintf(
                 v10,
                 v8,
                 "0x%x    %llu   %u   %u   %u\n",
                 *(_DWORD *)(v14 + v12 - 524),
                 v15,
                 v16,
                 *(_DWORD *)(v14 + v12) * *(_DWORD *)(v14 + v12 + 4 * v17 + 36LL * v16 - 356),
                 *(_DWORD *)(v14 + v12));
          v9 = *(unsigned int *)(a1 + 72);
          v10 += (unsigned int)v6;
          v8 -= v6;
        }
      }
      v11 = v8 > 1;
      if ( v13 < v9 )
      {
        v12 += 720;
        ++v13;
        if ( v8 > 1 )
          continue;
      }
      break;
    }
  }
  if ( v11 )
    v8 -= scnprintf(v10, v8, "aggreg_val(%u) aggreg_level(%u)\n", *(_DWORD *)(a1 + 128), *(_DWORD *)(a1 + 132));
  return a3 - v8;
}
