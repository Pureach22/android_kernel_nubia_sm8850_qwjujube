__int64 __fastcall mhi_init_irq_setup(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x20
  __int64 v4; // x25
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 result; // x0
  unsigned int v8; // w8
  int v9; // w21
  __int64 v10; // x3
  unsigned int v11; // w0
  __int64 v12; // x22
  unsigned int v13; // w22
  __int64 v14; // x23
  __int64 v15; // x20

  v1 = *(_QWORD *)(a1 + 616);
  v3 = *(_QWORD *)(a1 + 248);
  v4 = *(_QWORD *)(a1 + 16);
  v5 = **(unsigned int **)(a1 + 200);
  if ( v1 )
    v6 = v1;
  else
    v6 = 16512;
  result = request_threaded_irq(v5, mhi_intvec_handler, mhi_intvec_threaded_handler, v6, "bhi", a1);
  if ( (_DWORD)result )
    return result;
  disable_irq(**(unsigned int **)(a1 + 200));
  v8 = *(_DWORD *)(a1 + 212);
  if ( !v8 )
    return 0;
  v9 = 0;
  while ( 1 )
  {
    if ( (*(_BYTE *)(v3 + 258) & 1) != 0 )
      goto LABEL_7;
    v10 = *(unsigned int *)(v3 + 24);
    if ( (unsigned int)v10 >= *(_DWORD *)(a1 + 224) )
      break;
    v11 = request_threaded_irq(
            *(unsigned int *)(*(_QWORD *)(a1 + 200) + 4 * v10),
            mhi_irq_handler,
            0,
            v6 | 0x200000,
            "mhi",
            v3);
    if ( v11 )
    {
      v13 = v11;
      v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(
        v4 + 40,
        "[E][%s] Error requesting irq:%d for ev:%d\n",
        "mhi_init_irq_setup",
        *(_DWORD *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v3 + 24)),
        v9);
      if ( v14 && *(_DWORD *)(v14 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v14 + 32),
          "[E][%s] Error requesting irq:%d for ev:%d\n",
          "mhi_init_irq_setup",
          *(_DWORD *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v3 + 24)),
          v9);
      goto LABEL_21;
    }
    disable_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v3 + 24)));
    v8 = *(_DWORD *)(a1 + 212);
LABEL_7:
    ++v9;
    v3 += 264;
    if ( v9 >= v8 )
      return 0;
  }
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  dev_err(v4 + 40, "[E][%s] irq %d not available for event ring\n", "mhi_init_irq_setup", v10);
  if ( v12 && *(_DWORD *)(v12 + 24) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v12 + 32),
      "[E][%s] irq %d not available for event ring\n",
      "mhi_init_irq_setup",
      *(_DWORD *)(v3 + 24));
  v13 = -22;
LABEL_21:
  if ( ((v9 - 1) & 0x80000000) == 0 )
  {
    v15 = v3 - 264;
    do
    {
      if ( (*(_BYTE *)(v15 + 258) & 1) == 0 )
        free_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v15 + 24)), v15);
      --v9;
      v15 -= 264;
    }
    while ( v9 > 0 );
  }
  free_irq(**(unsigned int **)(a1 + 200), a1);
  return v13;
}
