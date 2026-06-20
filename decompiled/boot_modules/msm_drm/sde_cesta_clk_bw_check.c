__int64 __fastcall sde_cesta_clk_bw_check(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  unsigned int v6; // w8
  _QWORD **v7; // x22
  _QWORD *v8; // x10
  unsigned __int64 v9; // x6
  unsigned __int64 v10; // x5
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x10
  unsigned __int64 v13; // x12
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x14
  unsigned __int64 v16; // x20
  int v17; // w9
  int v18; // w24
  __int64 v19; // x10
  unsigned __int64 v20; // x0
  _QWORD *v21; // x23
  unsigned int v22; // w19

  result = 0;
  if ( a1 && a2 )
  {
    if ( *(_DWORD *)(a1 + 4) )
      return 0;
    v5 = cesta_list_0;
    mutex_lock(cesta_list_0 + 800);
    if ( (*(_BYTE *)(a1 + 56) & 1) != 0 )
    {
      if ( !*(_BYTE *)a2 )
        goto LABEL_13;
    }
    else if ( (*(_BYTE *)a2 & 1) != 0 )
    {
      goto LABEL_13;
    }
    if ( *(_QWORD *)(a2 + 24) == *(_QWORD *)(a1 + 80)
      && *(_QWORD *)(a2 + 32) == *(_QWORD *)(a1 + 88)
      && *(_QWORD *)(a2 + 8) == *(_QWORD *)(a1 + 64) )
    {
LABEL_12:
      v6 = 0;
      goto LABEL_46;
    }
LABEL_13:
    v7 = (_QWORD **)(v5 + 784);
    v8 = *(_QWORD **)(v5 + 784);
    v9 = *(_QWORD *)(a2 + 32);
    v10 = *(_QWORD *)(a2 + 24);
    v11 = *(_QWORD *)(a2 + 8);
    if ( v8 != (_QWORD *)(v5 + 784) )
    {
      v11 = *(_QWORD *)(a2 + 8);
      v10 = *(_QWORD *)(a2 + 24);
      v9 = *(_QWORD *)(a2 + 32);
      do
      {
        if ( v8 - 13 != (_QWORD *)a1 && (*(_BYTE *)(v8 - 6) & 1) != 0 )
        {
          v11 += *(v8 - 5);
          v10 += *(v8 - 3);
          if ( v9 <= *(v8 - 2) )
            v9 = *(v8 - 2);
        }
        v8 = (_QWORD *)*v8;
      }
      while ( v8 != v7 );
    }
    v12 = *(unsigned int *)(v5 + 1144);
    if ( (_DWORD)v12 && (v13 = *(unsigned int *)(v5 + 1148), (_DWORD)v13) )
      v14 = 100 * (v11 / v12) / v13;
    else
      v14 = 0;
    if ( v11 <= v14 )
      v15 = v14;
    else
      v15 = v11;
    if ( v15 > 1000LL * *(_QWORD *)(v5 + 1136) )
    {
      printk(&unk_239879, "sde_cesta_clk_bw_check");
    }
    else
    {
      if ( v10 <= v9 )
        v16 = v9;
      else
        v16 = v10;
      if ( v16 <= *(_QWORD *)(v5 + 1152) )
      {
        v6 = *(_DWORD *)(v5 + 48);
        if ( v6 )
        {
          v17 = 0;
          while ( 1 )
          {
            v18 = v17;
            v19 = *(_QWORD *)(v5 + 56) + 120LL * v17;
            if ( *(_DWORD *)(v19 + 40) == 2 )
            {
              v20 = clk_round_rate(*(_QWORD *)v19);
              if ( (unsigned int)sde_power_clk_set_rate(
                                   v5 + 16,
                                   (const char *)(*(_QWORD *)(v5 + 56) + 120LL * v18 + 8),
                                   v20,
                                   1) )
              {
                printk(&unk_26DCD8, "sde_cesta_clk_bw_check");
                goto LABEL_42;
              }
              v6 = *(_DWORD *)(v5 + 48);
            }
            v17 = v18 + 1;
            if ( v18 + 1 >= v6 )
              goto LABEL_12;
          }
        }
        goto LABEL_46;
      }
      printk(&unk_27B395, "sde_cesta_clk_bw_check");
    }
LABEL_42:
    v21 = *v7;
    if ( *v7 == v7 )
    {
      v6 = -7;
    }
    else
    {
      do
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_cesta_clk_bw_check",
          365,
          -1,
          *((_DWORD *)v21 - 26),
          *((_DWORD *)v21 - 24),
          *((unsigned __int8 *)v21 - 48),
          *((unsigned __int8 *)v21 - 47),
          *(v21 - 3));
        printk(&unk_24A69B, "sde_cesta_clk_bw_check");
        v21 = (_QWORD *)*v21;
        v6 = -7;
      }
      while ( v21 != v7 );
    }
LABEL_46:
    v22 = v6;
    mutex_unlock(v5 + 800);
    return v22;
  }
  return result;
}
