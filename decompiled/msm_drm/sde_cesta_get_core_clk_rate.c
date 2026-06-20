__int64 __fastcall sde_cesta_get_core_clk_rate(int a1)
{
  __int64 result; // x0
  __int64 v3; // x22
  int v4; // w20
  __int64 v5; // x23
  int v6; // w21
  const char *v7; // x25
  __int64 v8; // x21
  _QWORD *v9; // x8
  __int64 v10; // x20
  unsigned __int64 v11; // x19
  __int64 v12; // x21

  result = 0;
  if ( !a1 )
  {
    v3 = cesta_list_0;
    if ( cesta_list_0 )
    {
      v4 = *(_DWORD *)(cesta_list_0 + 48);
      if ( !v4 )
        goto LABEL_19;
      v5 = *(_QWORD *)(cesta_list_0 + 56);
      v6 = 0;
      while ( 1 )
      {
        v7 = (const char *)(v5 + 120LL * v6);
        if ( !strcmp(v7 + 8, "core_clk") )
          break;
        if ( v4 == ++v6 )
          goto LABEL_19;
      }
      v8 = *(_QWORD *)v7;
      if ( *(_QWORD *)v7 )
      {
        mutex_lock(v3 + 800);
        v9 = *(_QWORD **)(v3 + 784);
        if ( v9 == (_QWORD *)(v3 + 784) )
        {
          LODWORD(v11) = 0;
          LODWORD(v10) = 0;
        }
        else
        {
          v10 = 0;
          v11 = 0;
          do
          {
            if ( *((_BYTE *)v9 - 48) == 1 )
            {
              v10 += *(v9 - 3);
              if ( v11 <= *(v9 - 2) )
                v11 = *(v9 - 2);
            }
            v9 = (_QWORD *)*v9;
          }
          while ( v9 != (_QWORD *)(v3 + 784) );
        }
        v12 = clk_round_rate(v8);
        mutex_unlock(v3 + 800);
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_get_core_clk_rate", 798, -1, 0, v12, v10, v11, 239);
        return v12;
      }
      else
      {
LABEL_19:
        printk(&unk_221DCE, "sde_cesta_get_core_clk_rate");
        return 0;
      }
    }
  }
  return result;
}
