__int64 __fastcall swrm_runtime_suspend(__int64 a1)
{
  __int64 v1; // x19
  int v4; // w25
  int v5; // w20
  bool v6; // w24
  unsigned int v7; // w25
  int v8; // w0
  __int64 *i; // x26
  unsigned int v10; // w0
  __int64 v11; // x2
  __int64 v12; // x1
  int v13; // w26
  __int64 irq_data; // x0
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x0
  int v19; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v1 + 15336) == 5 )
  {
    *(_DWORD *)(v1 + 15336) = 4;
    return 0;
  }
  mutex_lock(v1 + 8976);
  mutex_lock(v1 + 8832);
  mutex_lock(v1 + 15360);
  v4 = *(_DWORD *)(v1 + 15336);
  mutex_unlock(v1 + 15360);
  v5 = swrm_request_hw_vote(v1, 0, 1);
  if ( !v5 || !(unsigned int)__ratelimit(&swrm_runtime_suspend__rs, "swrm_runtime_suspend") )
  {
    if ( *(_DWORD *)(v1 + 15904) )
      goto LABEL_6;
LABEL_9:
    v6 = 0;
    if ( v4 == 4 )
      goto LABEL_14;
    goto LABEL_10;
  }
  dev_err(a1, "%s:lpass core hw enable failed\n", "swrm_runtime_suspend");
  if ( !*(_DWORD *)(v1 + 15904) )
    goto LABEL_9;
LABEL_6:
  v6 = (unsigned int)swrm_request_hw_vote(v1, 1, 1) != 0;
  if ( v4 == 4 )
    goto LABEL_14;
LABEL_10:
  if ( v4 != 2 )
  {
LABEL_53:
    v7 = 0;
    *(_DWORD *)(v1 + 15336) = 3;
LABEL_54:
    if ( *(_DWORD *)(v1 + 15904) )
      goto LABEL_55;
LABEL_51:
    if ( *(_DWORD *)(v1 + 15336) != 2 )
      goto LABEL_56;
    goto LABEL_62;
  }
  if ( *(_BYTE *)(v1 + 8409) )
  {
    v7 = -16;
    if ( *(_DWORD *)(v1 + 15904) )
      goto LABEL_55;
    goto LABEL_51;
  }
LABEL_14:
  if ( *(_DWORD *)(v1 + 15704) && *(_DWORD *)(v1 + 15336) != 4 )
  {
    v11 = *(_DWORD *)(v1 + 15836) & 0xFFFFFFF7;
    v12 = (*(unsigned __int16 *)(v1 + 9056) << 12) + 16388;
    *(_DWORD *)(v1 + 15836) = v11;
    swr_master_write(v1, v12, v11);
    mutex_unlock(v1 + 8832);
    swrm_cmd_fifo_wr_cmd(v1, 2, 15, 15, 68);
    mutex_lock(v1 + 8832);
    usleep_range_state(100, 105, 2);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&swrm_runtime_suspend__rs_38, "swrm_runtime_suspend") )
      dev_err(a1, "%s: clk stop mode not supported or SSR entry\n", "swrm_runtime_suspend");
    if ( *(_DWORD *)(v1 + 15336) != 4 )
    {
      mutex_unlock(v1 + 8832);
      if ( *(_DWORD *)(v1 + 9052) != 5 )
        swrm_cmd_fifo_wr_cmd(v1, 8, 15, 15, 96);
      mutex_lock(v1 + 8832);
      swr_master_write(v1, (*(unsigned __int16 *)(v1 + 9056) << 12) + 16388, 1965565);
      v8 = swr_master_read(v1, 4168);
      swr_master_write(v1, 4168, v8 | 2u);
      swr_master_write(v1, 4, 0);
      for ( i = *(__int64 **)(v1 + 984); i != (__int64 *)(v1 + 984); i = (__int64 *)*i )
      {
        v10 = swr_device_down(i - 6);
        if ( v10 != -19 && v10 )
        {
          v7 = v10;
          if ( !(unsigned int)__ratelimit(&swrm_runtime_suspend__rs_40, "swrm_runtime_suspend") )
            goto LABEL_54;
          dev_err(a1, "%s: failed to shutdown swr dev %d\n", "swrm_runtime_suspend", *((unsigned __int8 *)i + 16));
          if ( *(_DWORD *)(v1 + 15904) )
            goto LABEL_55;
          goto LABEL_51;
        }
      }
    }
  }
  if ( *(int *)(v1 + 9128) >= 17104898 )
  {
    v13 = -100;
    while ( (swr_master_read(v1, (unsigned int)((*(_DWORD *)(v1 + 9056) << 12) + 16484)) & 1) != 0 )
    {
      usleep_range_state(500, 510, 2);
      if ( __CFADD__(v13++, 1) )
      {
        if ( (unsigned int)__ratelimit(&swrm_check_link_status__rs, "swrm_check_link_status") )
          dev_err(*(_QWORD *)(v1 + 8512), "%s: link status not %s\n", "swrm_check_link_status", "disconnected");
        break;
      }
    }
  }
  if ( (unsigned int)swrm_clk_request(v1, 0) )
  {
    if ( (unsigned int)__ratelimit(&swrm_runtime_suspend__rs_42, "swrm_runtime_suspend") )
      dev_err(a1, "%s: swrmn clk failed\n", "swrm_runtime_suspend");
    goto LABEL_50;
  }
  if ( *(_DWORD *)(v1 + 15704) )
  {
    if ( *(int *)(v1 + 9124) < 1 )
    {
      if ( *(_DWORD *)(v1 + 15744) )
      {
        if ( (unsigned int)__ratelimit(&swrm_runtime_suspend__rs_44, "swrm_runtime_suspend") )
          dev_err(a1, "%s:notifications disabled\n", "swrm_runtime_suspend");
        *(_BYTE *)(v1 + 15749) = 0;
      }
    }
    else
    {
      irq_data = irq_get_irq_data();
      if ( irq_data && (*(_BYTE *)(*(_QWORD *)(irq_data + 16) + 2LL) & 1) != 0 )
        enable_irq(*(unsigned int *)(v1 + 9124));
    }
  }
  if ( v4 != 4 )
    goto LABEL_53;
LABEL_50:
  v7 = 0;
  if ( !*(_DWORD *)(v1 + 15904) )
    goto LABEL_51;
LABEL_55:
  if ( !v6 )
  {
LABEL_56:
    mutex_lock(v1 + 8736);
    v16 = *(_QWORD *)(v1 + 15856);
    if ( v16 )
    {
      v17 = *(_DWORD *)(v1 + 15876) - 1;
      *(_DWORD *)(v1 + 15876) = v17;
      if ( v17 < 0 )
      {
        *(_DWORD *)(v1 + 15876) = 0;
      }
      else if ( !v17 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v16, *(_QWORD *)(v1 + 8512));
      }
    }
    mutex_unlock(v1 + 8736);
  }
LABEL_62:
  if ( !v5 )
  {
    mutex_lock(v1 + 8736);
    v18 = *(_QWORD *)(v1 + 15848);
    if ( v18 )
    {
      v19 = *(_DWORD *)(v1 + 15872) - 1;
      *(_DWORD *)(v1 + 15872) = v19;
      if ( v19 < 0 )
      {
        *(_DWORD *)(v1 + 15872) = 0;
      }
      else if ( !v19 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v18, *(_QWORD *)(v1 + 8512));
      }
    }
    mutex_unlock(v1 + 8736);
  }
  mutex_unlock(v1 + 8832);
  mutex_unlock(v1 + 8976);
  return v7;
}
