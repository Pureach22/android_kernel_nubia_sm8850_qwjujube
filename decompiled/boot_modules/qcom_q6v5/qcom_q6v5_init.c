__int64 __fastcall qcom_q6v5_init(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        char a8,
        __int64 a9)
{
  __int64 v9; // x19
  __int64 v13; // x0
  __int64 result; // x0
  unsigned int v15; // w0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x1
  const char *v19; // x2
  const char *v20; // x1
  unsigned int v21; // w19
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x0
  unsigned int v24; // w20

  v9 = a2 + 16;
  *(_QWORD *)a1 = a2 + 16;
  *(_QWORD *)(a1 + 8) = a3;
  *(_DWORD *)(a1 + 272) = a4;
  *(_DWORD *)(a1 + 276) = a5;
  *(_DWORD *)(a1 + 280) = a6;
  *(_QWORD *)(a1 + 296) = a9;
  *(_BYTE *)(a1 + 320) = a8;
  *(_QWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 144) = 0;
  _init_swait_queue_head(a1 + 152, "&x->wait", &init_completion___key);
  *(_DWORD *)(a1 + 176) = 0;
  _init_swait_queue_head(a1 + 184, "&x->wait", &init_completion___key);
  v13 = wakeup_source_register(*(_QWORD *)a1, "remoteproc SSR wake lock");
  *(_QWORD *)(a1 + 336) = v13;
  if ( !v13 )
  {
    dev_err(v9, "failed to allocate wakeup source\n");
    return 4294967284LL;
  }
  result = platform_get_irq_byname(a2, "wdog");
  *(_DWORD *)(a1 + 64) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  v15 = devm_request_threaded_irq(v9, (unsigned int)result, 0, q6v5_wdog_interrupt, 8193, "q6v5 wdog", a1);
  if ( v15 )
  {
    v20 = "failed to acquire wdog IRQ\n";
LABEL_35:
    v24 = v15;
    dev_err(v9, v20);
    return v24;
  }
  result = platform_get_irq_byname(a2, "fatal");
  *(_DWORD *)(a1 + 68) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  v15 = devm_request_threaded_irq(v9, (unsigned int)result, 0, q6v5_fatal_interrupt, 8193, "q6v5 fatal", a1);
  if ( v15 )
  {
    v20 = "failed to acquire fatal IRQ\n";
    goto LABEL_35;
  }
  result = platform_get_irq_byname(a2, "ready");
  *(_DWORD *)(a1 + 72) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  v15 = devm_request_threaded_irq(v9, (unsigned int)result, 0, q6v5_ready_interrupt, 8193, "q6v5 ready", a1);
  if ( v15 )
  {
    v20 = "failed to acquire ready IRQ\n";
    goto LABEL_35;
  }
  result = platform_get_irq_byname(a2, "handover");
  *(_DWORD *)(a1 + 76) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  v15 = devm_request_threaded_irq(v9, (unsigned int)result, 0, q6v5_handover_interrupt, 8193, "q6v5 handover", a1);
  if ( v15 )
  {
    v20 = "failed to acquire handover IRQ\n";
    goto LABEL_35;
  }
  disable_irq(*(unsigned int *)(a1 + 76));
  result = platform_get_irq_byname(a2, "stop-ack");
  *(_DWORD *)(a1 + 80) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  v15 = devm_request_threaded_irq(v9, (unsigned int)result, 0, q6v5_stop_interrupt, 8193, "q6v5 stop", a1);
  if ( v15 )
  {
    v20 = "failed to acquire stop-ack IRQ\n";
    goto LABEL_35;
  }
  v16 = devm_qcom_smem_state_get(v9, "stop", a1 + 56);
  *(_QWORD *)(a1 + 16) = v16;
  if ( v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v9, "failed to acquire stop state\n");
    return *(unsigned int *)(a1 + 16);
  }
  *(_QWORD *)(a1 + 288) = devm_kstrdup_const(v9, a7, 3264);
  v17 = qmp_get(v9);
  v18 = v17;
  *(_QWORD *)(a1 + 32) = v17;
  if ( v17 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( !*(_QWORD *)(a1 + 288) )
    {
      if ( a7 )
      {
        v21 = -12;
      }
      else
      {
        dev_err(v9, "load state resource string empty\n");
        v18 = *(_QWORD *)(a1 + 32);
        v21 = -22;
      }
      qmp_put(v18);
      return v21;
    }
  }
  else
  {
    if ( v17 != -19 )
    {
      v19 = "failed to acquire load state\n";
      return dev_err_probe(v9, v18, v19);
    }
    *(_QWORD *)(a1 + 32) = 0;
  }
  v22 = devm_of_icc_get(v9, "rproc_ddr");
  *(_QWORD *)(a1 + 40) = v22;
  if ( v22 >= 0xFFFFFFFFFFFFF001LL )
  {
    v18 = v22;
    if ( v22 != -61 )
    {
      v19 = "failed to acquire rproc_ddr interconnect path\n";
      return dev_err_probe(v9, v18, v19);
    }
    *(_QWORD *)(a1 + 40) = 0;
  }
  v23 = devm_of_icc_get(v9, "crypto_ddr");
  *(_QWORD *)(a1 + 48) = v23;
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
  {
    v18 = v23;
    if ( v23 != -61 )
    {
      v19 = "failed to acquire crypto_ddr interconnect path\n";
      return dev_err_probe(v9, v18, v19);
    }
    *(_QWORD *)(a1 + 48) = 0;
  }
  *(_QWORD *)(a1 + 104) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 112) = a1 + 112;
  *(_QWORD *)(a1 + 120) = a1 + 112;
  *(_QWORD *)(a1 + 128) = qcom_q6v5_crash_handler_work;
  return 0;
}
