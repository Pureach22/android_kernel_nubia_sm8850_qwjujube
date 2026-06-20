__int64 __fastcall gsi_common_tx_tre_optimization(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5)
{
  int v9; // w23
  int v10; // w25
  __int64 v11; // x27
  unsigned int v12; // w24

  if ( a2 % a3 )
    v9 = a2 / a3 + 1;
  else
    v9 = a2 / a3;
  if ( v9 < 1 )
  {
    v12 = 1;
LABEL_13:
    gsi_common_tre_process(a1, a2, a3, a5);
    ipc_log_string(*(_QWORD *)(a1 + 18480), "%s:  timeout :%d\n", "gsi_common_tx_tre_optimization", v12);
  }
  else
  {
    v10 = 0;
    v11 = a4;
    v12 = 1;
    while ( 1 )
    {
      if ( v9 != *(_DWORD *)(a1 + 9232) )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 18480),
          "%s: calling wait for_completion ix:%d irq_cnt:%d\n",
          "gsi_common_tx_tre_optimization",
          v10,
          *(_DWORD *)(a1 + 9232));
        v12 = wait_for_completion_timeout(*(_QWORD *)(a1 + 8), v11);
        **(_DWORD **)(a1 + 8) = 0;
        if ( !v12 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 18480), "%s: msg xfer timeout\n", "gsi_common_tx_tre_optimization");
          return v12;
        }
        if ( **(_BYTE **)(a1 + 18496) == 1 )
          break;
      }
      ipc_log_string(*(_QWORD *)(a1 + 18480), "%s: maxirq_cnt:%d i:%d\n", "gsi_common_tx_tre_optimization", v9, v10);
      gsi_common_tre_process(a1, a2, a3, a5);
      if ( *(_DWORD *)(a1 + 256) < a2 )
        return v12;
      if ( ++v10 >= v9 )
        goto LABEL_13;
    }
    ipc_log_string(*(_QWORD *)(a1 + 18480), "%s: gsi error\n", "gsi_common_tx_tre_optimization");
    return (unsigned int)-5;
  }
  return v12;
}
