__int64 __fastcall swrm_runtime_resume(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w22
  int v4; // w21
  int v5; // w8
  __int64 v6; // x0
  __int64 irq_data; // x0
  __int64 v8; // x22
  int v9; // w25
  __int64 *i; // x25
  unsigned int v11; // w0
  int v12; // w25
  int v13; // w3
  char v14; // w8
  unsigned int *v15; // x0
  int v16; // w0
  unsigned __int16 v17; // w1
  unsigned int v18; // w2
  int v19; // w22
  __int64 v21; // x0
  int v22; // w8
  __int64 v23; // x0
  int v24; // w8
  int v25; // w9
  __int64 v26; // x1

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 8976);
  mutex_lock(v1 + 8832);
  if ( (unsigned int)swrm_request_hw_vote(v1, 0, 1) )
  {
    if ( (unsigned int)__ratelimit(&swrm_runtime_resume__rs, "swrm_runtime_resume") )
      dev_err(a1, "%s:lpass core hw enable failed\n", "swrm_runtime_resume");
    pm_runtime_set_autosuspend_delay(a1, 1);
    if ( *(_BYTE *)(v1 + 15750) == 1 )
    {
      v3 = 0;
      *(_BYTE *)(v1 + 15750) = 0;
      goto LABEL_73;
    }
LABEL_72:
    v3 = 0;
    goto LABEL_73;
  }
  v4 = swrm_request_hw_vote(v1, 1, 1);
  if ( v4 && (unsigned int)__ratelimit(&swrm_runtime_resume__rs_130, "swrm_runtime_resume") )
    dev_err(a1, "%s:lpass audio hw enable failed\n", "swrm_runtime_resume");
  v5 = *(_DWORD *)(v1 + 15336);
  if ( v5 == 3 || v5 == 4 && *(_BYTE *)(v1 + 15748) == 1 )
  {
    if ( *(_DWORD *)(v1 + 15704) )
    {
      v6 = *(unsigned int *)(v1 + 9124);
      if ( (int)v6 >= 1 )
      {
        irq_data = irq_get_irq_data(v6);
        if ( !irq_data )
        {
          if ( (unsigned int)__ratelimit(&swrm_runtime_resume__rs_131, "swrm_runtime_resume") )
          {
            printk(&unk_1118B, "swrm_runtime_resume");
            v3 = 0;
            goto LABEL_73;
          }
          goto LABEL_72;
        }
        v8 = irq_data;
        mutex_lock(v1 + 8928);
        if ( (*(_BYTE *)(*(_QWORD *)(v8 + 16) + 2LL) & 1) == 0 )
          disable_irq_nosync(*(unsigned int *)(v1 + 9124));
        mutex_unlock(v1 + 8928);
      }
      if ( *(_DWORD *)(v1 + 15744) && (unsigned int)__ratelimit(&swrm_runtime_resume__rs_132, "swrm_runtime_resume") )
        dev_err(a1, "%s:notifications disabled\n", "swrm_runtime_resume");
    }
    v9 = 1;
    if ( (unsigned int)swrm_clk_request(v1, 1) )
    {
      v3 = 0;
    }
    else
    {
      if ( *(_DWORD *)(v1 + 15704) && *(_DWORD *)(v1 + 15336) != 4 )
      {
        v15 = *(unsigned int **)(v1 + 9040);
        if ( v15 )
        {
          v16 = readl(v15);
          writel(v16 & 0xFFFFFFFD, *(unsigned int **)(v1 + 9040));
        }
        swr_master_write(v1, (*(_WORD *)(v1 + 9056) << 12) + 16480, 1u);
        swr_master_write(v1, (*(_WORD *)(v1 + 9056) << 12) + 16392, 8u);
        v17 = (*(_WORD *)(v1 + 9056) << 12) + 16388;
        v18 = *(_DWORD *)(v1 + 15836) | 8;
        *(_DWORD *)(v1 + 15836) = v18;
        swr_master_write(v1, v17, v18);
        usleep_range_state(100, 105, 2);
        if ( *(int *)(v1 + 9128) >= 17104898 )
        {
          v19 = -100;
          while ( (swr_master_read(v1, ((unsigned __int16)*(_DWORD *)(v1 + 9056) << 12) + 16484) & 1) == 0 )
          {
            usleep_range_state(500, 510, 2);
            if ( __CFADD__(v19++, 1) )
            {
              if ( (unsigned int)__ratelimit(&swrm_check_link_status__rs, "swrm_check_link_status") )
                dev_err(*(_QWORD *)(v1 + 8512), "%s: link status not %s\n", "swrm_check_link_status", "connected");
              break;
            }
          }
        }
      }
      else
      {
        for ( i = *(__int64 **)(v1 + 984); i != (__int64 *)(v1 + 984); i = (__int64 *)*i )
        {
          v11 = swr_device_up(i - 6);
          if ( v11 != -19 )
          {
            v3 = v11;
            if ( v11 )
            {
              if ( (unsigned int)__ratelimit(&swrm_runtime_resume__rs_133, "swrm_runtime_resume") )
                dev_err(a1, "%s: failed to wakeup swr dev %d\n", "swrm_runtime_resume", *((unsigned __int8 *)i + 16));
              swrm_clk_request(v1, 0);
              v9 = 0;
              goto LABEL_50;
            }
          }
        }
        mutex_lock(v1 + 8640);
        v12 = *(_DWORD *)(v1 + 8536);
        mutex_unlock(v1 + 8640);
        if ( v12 == 1 )
        {
          swr_master_write(v1, 8u, 1u);
          swr_master_write(v1, 8u, 1u);
          swr_master_write(v1, 0x1044u, 1u);
          swrm_master_init(v1);
          usleep_range_state(100, 105, 2);
          swrm_check_link_status(v1, 1);
          v13 = *(unsigned __int8 *)(v1 + 9050);
          v14 = (v13 + 1) & 0xF;
          if ( v13 == 14 )
            v14 = 0;
          *(_BYTE *)(v1 + 9050) = v14;
          swrm_cmd_fifo_wr_cmd(v1, 4, 0xFu, v13, 0x41u);
        }
        if ( *(_DWORD *)(v1 + 15336) == 4 )
        {
          mutex_unlock(v1 + 8832);
          swrm_cmd_fifo_wr_cmd(v1, 8, 0xFu, 0xFu, 0x60u);
          mutex_lock(v1 + 8832);
        }
      }
      v9 = 0;
      v3 = 0;
      *(_DWORD *)(v1 + 15336) = 2;
    }
  }
  else
  {
    v9 = 0;
    v3 = 0;
  }
LABEL_50:
  if ( !v4 && *(_DWORD *)(v1 + 15904) )
  {
    mutex_lock(v1 + 8736);
    v21 = *(_QWORD *)(v1 + 15856);
    if ( v21 )
    {
      v22 = *(_DWORD *)(v1 + 15876) - 1;
      *(_DWORD *)(v1 + 15876) = v22;
      if ( v22 < 0 )
      {
        *(_DWORD *)(v1 + 15876) = 0;
      }
      else if ( !v22 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v21, *(_QWORD *)(v1 + 8512));
      }
    }
    mutex_unlock(v1 + 8736);
  }
  mutex_lock(v1 + 8736);
  v23 = *(_QWORD *)(v1 + 15848);
  if ( v23 )
  {
    v24 = *(_DWORD *)(v1 + 15872) - 1;
    *(_DWORD *)(v1 + 15872) = v24;
    if ( v24 < 0 )
    {
      *(_DWORD *)(v1 + 15872) = 0;
    }
    else if ( !v24 )
    {
      digital_cdc_rsc_mgr_hw_vote_disable(v23, *(_QWORD *)(v1 + 8512));
    }
  }
  mutex_unlock(v1 + 8736);
  if ( v4 )
    v25 = 1;
  else
    v25 = v9;
  if ( v25 )
    v26 = 1;
  else
    v26 = (unsigned int)auto_suspend_timer;
  pm_runtime_set_autosuspend_delay(a1, v26);
  if ( *(_BYTE *)(v1 + 15750) == 1 )
    *(_BYTE *)(v1 + 15750) = 0;
LABEL_73:
  mutex_unlock(v1 + 8832);
  mutex_unlock(v1 + 8976);
  return v3;
}
