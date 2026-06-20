__int64 __fastcall swrm_wcd_notify(__int64 a1, int a2, int *a3)
{
  __int64 v3; // x19
  int v5; // w8
  _QWORD *v6; // x24
  __int64 result; // x0
  unsigned int v8; // w0
  unsigned int v9; // w26
  int v10; // w8
  __int64 v12; // x21
  int *v15; // x8
  int v16; // w8
  __int64 v17; // x0
  unsigned int v20; // w0
  unsigned int v21; // w21
  int v23; // w20
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 *v26; // x26
  unsigned int v27; // w8
  unsigned int v28; // w28
  int v30; // w8
  __int64 v31; // x0
  int v36; // w8
  int v37; // w1
  const char *v39; // x1
  __int64 v40; // x0
  void *v41; // x0
  unsigned int v42; // w20
  __int64 v43; // x0
  _QWORD *v44; // x24
  unsigned int v45; // w26
  int v46; // w8

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&swrm_wcd_notify__rs, "swrm_wcd_notify") )
    {
      printk(&unk_10644, "swrm_wcd_notify");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 168);
  if ( !v3 )
  {
    if ( !(unsigned int)__ratelimit(&swrm_wcd_notify__rs_8, "swrm_wcd_notify") )
      return 4294967274LL;
    v39 = "%s: swrm is NULL\n";
    v40 = a1 + 16;
    goto LABEL_83;
  }
  if ( a2 <= 7 )
  {
    if ( a2 <= 4 )
    {
      if ( a2 != 1 )
      {
        if ( a2 == 2 )
        {
          mutex_lock(v3 + 8736);
          v23 = *(unsigned __int8 *)(v3 + 15748);
          mutex_unlock(v3 + 8736);
          if ( v23 != 1 )
            return 4294967280LL;
          v24 = mutex_lock(v3 + 8784);
          *(_QWORD *)(a1 + 536) = ktime_get_mono_fast_ns(v24);
          _pm_runtime_resume(a1 + 16, 4);
          v25 = mutex_lock(v3 + 8832);
          v26 = *(__int64 **)(v3 + 984);
          if ( v26 == (__int64 *)(v3 + 984) )
          {
            v27 = 0;
          }
          else
          {
            do
            {
              v25 = swr_reset_device(v26 - 6);
              v27 = 0;
              if ( (_DWORD)v25 != -19 && (_DWORD)v25 )
              {
                v28 = v25;
                if ( (unsigned int)__ratelimit(&swrm_wcd_notify__rs_16, "swrm_wcd_notify") )
                  dev_err(
                    *(_QWORD *)(v3 + 8512),
                    "%s: failed to reset swr device %d\n",
                    "swrm_wcd_notify",
                    *((unsigned __int8 *)v26 + 16));
                v25 = swrm_clk_request(v3, 0);
                v27 = v28;
              }
              v26 = (__int64 *)*v26;
            }
            while ( v26 != (__int64 *)(v3 + 984) );
          }
          v42 = v27;
          *(_QWORD *)(a1 + 536) = ktime_get_mono_fast_ns(v25);
          _pm_runtime_suspend(a1 + 16, 13);
          mutex_unlock(v3 + 8832);
          v43 = v3 + 8784;
          goto LABEL_108;
        }
        if ( a2 == 4 )
        {
          if ( a3 )
          {
            mutex_lock(v3 + 8784);
            v5 = *a3;
            *(_DWORD *)(v3 + 15352) = *a3;
            if ( v5 < 2 || *(_BYTE *)(v3 + 15356) )
            {
              v6 = *(_QWORD **)(v3 + 984);
              if ( v6 != (_QWORD *)(v3 + 984) )
              {
                do
                {
                  v8 = swr_set_device_group(v6 - 6, 0);
                  if ( v8 )
                  {
                    v9 = v8;
                    v10 = __ratelimit(&swrm_wcd_notify__rs_21, "swrm_wcd_notify");
                    v8 = v9;
                    if ( v10 )
                    {
                      dev_err(*(_QWORD *)(v3 + 8512), "%s: set num ch failed\n", "swrm_wcd_notify");
                      v8 = v9;
                    }
                  }
                  v6 = (_QWORD *)*v6;
                }
                while ( v6 != (_QWORD *)(v3 + 984) );
LABEL_105:
                v42 = v8;
LABEL_107:
                v43 = v3 + 8784;
LABEL_108:
                mutex_unlock(v43);
                return v42;
              }
            }
            else
            {
              v44 = *(_QWORD **)(v3 + 984);
              if ( v44 != (_QWORD *)(v3 + 984) )
              {
                do
                {
                  v8 = swr_set_device_group(v44 - 6, 15);
                  if ( v8 )
                  {
                    v45 = v8;
                    v46 = __ratelimit(&swrm_wcd_notify__rs_19, "swrm_wcd_notify");
                    v8 = v45;
                    if ( v46 )
                    {
                      dev_err(*(_QWORD *)(v3 + 8512), "%s: set num ch failed\n", "swrm_wcd_notify");
                      v8 = v45;
                    }
                  }
                  v44 = (_QWORD *)*v44;
                }
                while ( v44 != (_QWORD *)(v3 + 984) );
                goto LABEL_105;
              }
            }
            v42 = 0;
            goto LABEL_107;
          }
          v41 = &swrm_wcd_notify__rs_18;
LABEL_93:
          if ( (unsigned int)__ratelimit(v41, "swrm_wcd_notify") )
          {
            v40 = *(_QWORD *)(v3 + 8512);
            v39 = "%s: data is NULL\n";
            goto LABEL_83;
          }
          return 4294967274LL;
        }
        goto LABEL_79;
      }
      mutex_lock(v3 + 8784);
      if ( *(_DWORD *)(v3 + 15336) != 3 )
        swrm_device_down(a1 + 16);
      v31 = v3 + 8784;
LABEL_78:
      mutex_unlock(v31);
      return 0;
    }
    if ( a2 == 5 )
    {
      if ( !a3 )
      {
        v41 = &swrm_wcd_notify__rs_12;
        goto LABEL_93;
      }
      mutex_lock(v3 + 8784);
      v36 = *(_DWORD *)(v3 + 9132);
      v37 = *a3;
      if ( v36 != *a3 )
      {
        if ( *(_DWORD *)(v3 + 15336) != 3 )
        {
          *(_DWORD *)(v3 + 9132) = v37;
          *(_DWORD *)(v3 + 9136) = v37;
          swrm_switch_frame_shape(v3);
          swrm_device_suspend(a1 + 16);
        }
        usleep_range_state(10000, 10500, 2);
        v36 = *a3;
      }
      *(_DWORD *)(v3 + 9132) = v36;
      v31 = v3 + 8784;
      *(_DWORD *)(v3 + 9136) = v36;
      goto LABEL_78;
    }
    if ( a2 == 6 )
    {
      v12 = 8784;
      mutex_lock(v3 + 8784);
      mutex_lock(v3 + 8736);
      *(_BYTE *)(v3 + 15748) = 0;
      mutex_unlock(v3 + 8736);
      if ( *(_DWORD *)(v3 + 15336) != 3 )
        swrm_device_down(a1 + 16);
      mutex_lock(v3 + 8736);
      if ( *(_DWORD *)(v3 + 15872) )
        digital_cdc_rsc_mgr_hw_vote_disable(*(_QWORD *)(v3 + 15848), *(_QWORD *)(v3 + 8512));
      v30 = *(_DWORD *)(v3 + 15876);
      *(_DWORD *)(v3 + 15872) = 0;
      if ( v30 )
        digital_cdc_rsc_mgr_hw_vote_disable(*(_QWORD *)(v3 + 15856), *(_QWORD *)(v3 + 8512));
      *(_DWORD *)(v3 + 15876) = 0;
      mutex_unlock(v3 + 8736);
      mutex_lock(v3 + 8832);
      *(_DWORD *)(v3 + 15336) = 4;
      mutex_unlock(v3 + 8832);
    }
    else
    {
      v16 = *(_DWORD *)(v3 + 8536);
      *(_DWORD *)(v3 + 8544) = 0;
      if ( v16
        && !wait_for_completion_timeout(v3 + 8544, 125)
        && (unsigned int)__ratelimit(&swrm_wcd_notify__rs_14, "swrm_wcd_notify") )
      {
        dev_err(*(_QWORD *)(v3 + 8512), "%s: clock voting not zero\n", "swrm_wcd_notify");
      }
      if ( *(_DWORD *)(v3 + 15336) == 2 || pm_runtime_autosuspend_expiration(*(_QWORD *)(v3 + 8512)) )
      {
        v17 = *(_QWORD *)(v3 + 8512);
        *(_DWORD *)(v3 + 15336) = 5;
        pm_runtime_set_autosuspend_delay(v17, 1);
        usleep_range_state(50000, 50100, 2);
        *(_DWORD *)(v3 + 15336) = 4;
      }
      v12 = 8736;
      mutex_lock(v3 + 8736);
      *(_BYTE *)(v3 + 15748) = 1;
    }
LABEL_64:
    v31 = v3 + v12;
    goto LABEL_78;
  }
  if ( a2 <= 10 )
  {
    if ( a2 != 8 )
    {
      if ( a2 != 9 )
      {
        if ( a3 )
        {
          v12 = 8784;
          mutex_lock(v3 + 8784);
          if ( *(_DWORD *)(v3 + 15880) != *a3 )
          {
            v15 = a3;
            if ( *(_DWORD *)(v3 + 15336) == 2 )
            {
              *(_BYTE *)(v3 + 15750) = 1;
              swrm_device_suspend(a1 + 16);
              v15 = a3;
              if ( *(_DWORD *)(v3 + 15336) == 2 )
                *(_BYTE *)(v3 + 15750) = 0;
            }
            *(_DWORD *)(v3 + 15880) = *v15;
          }
          goto LABEL_64;
        }
        if ( (unsigned int)__ratelimit(&swrm_wcd_notify__rs_10, "swrm_wcd_notify") )
        {
          dev_err(*(_QWORD *)(v3 + 8512), "%s: data is NULL for id:%d\n", "swrm_wcd_notify", 10);
          return 4294967274LL;
        }
        return 4294967274LL;
      }
      if ( !a3 )
      {
        if ( (unsigned int)__ratelimit(&swrm_wcd_notify__rs_26, "swrm_wcd_notify") )
        {
          dev_err(*(_QWORD *)(v3 + 8512), "%s: data is NULL for id=%d\n", "swrm_wcd_notify", 9);
          return 4294967274LL;
        }
        return 4294967274LL;
      }
      mutex_lock(v3 + 8784);
      if ( *a3 )
      {
        v20 = swrm_alloc_port_mem(a1 + 16, v3, (unsigned int)a3[1]);
        if ( !v20 )
        {
          swrm_copy_port_config(v3, a3, (unsigned int)*a3);
          v20 = 0;
        }
        v21 = v20;
      }
      else
      {
        v21 = -22;
      }
LABEL_96:
      mutex_unlock(v3 + 8784);
      return v21;
    }
    if ( a3 )
    {
      mutex_lock(v3 + 8784);
      *(_DWORD *)(v3 + 15744) = *a3;
      v21 = swrm_register_wake_irq(v3);
      if ( v21 && (unsigned int)__ratelimit(&swrm_wcd_notify__rs_24, "swrm_wcd_notify") )
        dev_err(*(_QWORD *)(v3 + 8512), "%s: register wake_irq failed\n", "swrm_wcd_notify");
      goto LABEL_96;
    }
    if ( !(unsigned int)__ratelimit(&swrm_wcd_notify__rs_22, "swrm_wcd_notify") )
      return 4294967274LL;
    v40 = *(_QWORD *)(v3 + 8512);
    v39 = "%s: reg wake irq data is NULL\n";
LABEL_83:
    dev_err(v40, v39, "swrm_wcd_notify");
    return 4294967274LL;
  }
  if ( (unsigned int)(a2 - 11) < 2 )
    return 0;
LABEL_79:
  result = __ratelimit(&swrm_wcd_notify__rs_28, "swrm_wcd_notify");
  if ( (_DWORD)result )
  {
    dev_err(*(_QWORD *)(v3 + 8512), "%s: swr master unknown id %d\n", "swrm_wcd_notify", a2);
    return 0;
  }
  return result;
}
