__int64 __fastcall dsi_ctrl_isr_configure(__int64 result, char a2)
{
  __int64 v2; // x19
  unsigned int irq; // w20
  unsigned int v5; // w0
  __int64 v6; // x1
  __int64 v7; // x3
  void *v8; // x1
  const char *v9; // x2

  if ( result )
  {
    v2 = result;
    mutex_lock(result + 32);
    if ( (a2 & 1) == 0 )
    {
      if ( *(_QWORD *)v2 )
      {
        v6 = *(unsigned int *)(v2 + 1660);
        if ( (v6 & 0x80000000) == 0 )
        {
          devm_free_irq(*(_QWORD *)v2 + 16LL, v6, v2);
          *(_DWORD *)(v2 + 1660) = -1;
        }
      }
      return mutex_unlock(v2 + 32);
    }
    if ( *(_DWORD *)(v2 + 1660) == -1 )
    {
      *(_DWORD *)(v2 + 2000) = 0;
      _init_swait_queue_head(v2 + 2008, "&x->wait", &init_completion___key_6);
      *(_DWORD *)(v2 + 2032) = 0;
      _init_swait_queue_head(v2 + 2040, "&x->wait", &init_completion___key_6);
      *(_DWORD *)(v2 + 2064) = 0;
      _init_swait_queue_head(v2 + 2072, "&x->wait", &init_completion___key_6);
      *(_DWORD *)(v2 + 2096) = 0;
      _init_swait_queue_head(v2 + 2104, "&x->wait", &init_completion___key_6);
      irq = platform_get_irq(*(_QWORD *)v2, 0);
      if ( (irq & 0x80000000) != 0 )
      {
        v7 = *(_QWORD *)(v2 + 16);
        v8 = &unk_248D72;
        v9 = "*ERROR* [msm-dsi-error]: %s: Failed to get IRQ number, %d\n";
      }
      else
      {
        v5 = devm_request_threaded_irq(*(_QWORD *)v2 + 16LL, irq, &dsi_ctrl_isr, 0, 0, "dsi_ctrl");
        if ( v5 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: %s: Failed to request IRQ, %d\n",
            *(_QWORD *)(v2 + 16),
            v5);
          return mutex_unlock(v2 + 32);
        }
        *(_DWORD *)(v2 + 1660) = irq;
        disable_irq_nosync(irq);
        v7 = *(_QWORD *)(v2 + 16);
        v8 = &unk_2597DF;
        v9 = "[msm-dsi-info]: %s: IRQ %d registered\n";
      }
      drm_dev_printk(0, v8, v9, v7, irq);
    }
    return mutex_unlock(v2 + 32);
  }
  return result;
}
