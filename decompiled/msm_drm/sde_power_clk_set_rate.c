__int64 __fastcall sde_power_clk_set_rate(__int64 a1, const char *a2, unsigned __int64 a3, int a4)
{
  int v8; // w7
  int v9; // w4
  int v11; // w25
  __int64 v12; // x24
  int v13; // w8
  __int64 v14; // x27
  __int64 v15; // x22
  __int64 v16; // x1
  unsigned int v17; // w21
  unsigned __int64 v18; // x8
  __int64 v19; // x9
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x8
  char v22; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    if ( a4 && *(_BYTE *)(a1 + 377) != 1 )
    {
      return 0;
    }
    else
    {
      mutex_lock(a1 + 48);
      if ( a4 || (v9 = *(_DWORD *)(a1 + 360), (v9 & 2) == 0) )
      {
        v11 = *(_DWORD *)(a1 + 32);
        if ( v11 )
        {
          v12 = *(_QWORD *)(a1 + 40);
          v13 = 0;
          while ( 1 )
          {
            v14 = v12 + 120LL * v13;
            v15 = v13;
            if ( !strcmp((const char *)(v14 + 8), a2) )
              break;
            v13 = v15 + 1;
            if ( v11 == (_DWORD)v15 + 1 )
              goto LABEL_11;
          }
          v18 = *(_QWORD *)(v14 + 56);
          v19 = 120 * v15;
          if ( v18 >= a3 )
            v20 = a3;
          else
            v20 = *(_QWORD *)(v14 + 56);
          if ( v18 )
            v21 = v20;
          else
            v21 = a3;
          *(_QWORD *)(v12 + v19 + 48) = v21;
          *(_DWORD *)(*(_QWORD *)(a1 + 40) + v19 + 68) = a4;
          _ReadStatusReg(SP_EL0);
          v17 = msm_dss_single_clk_set_rate(*(_QWORD *)(a1 + 40) + 120LL * (int)v15, v16);
        }
        else
        {
LABEL_11:
          v17 = -22;
        }
        mutex_unlock(a1 + 48);
        return v17;
      }
      else
      {
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_power_clk_set_rate", 1304, -1, v9, 60333, -1059143953, v8, v22);
        mutex_unlock(a1 + 48);
        return 4294967274LL;
      }
    }
  }
  else
  {
    printk(&unk_27E885, "sde_power_clk_set_rate");
    return 4294967274LL;
  }
}
