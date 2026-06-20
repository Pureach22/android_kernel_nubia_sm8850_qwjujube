__int64 __fastcall qcom_glink_announce_create(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 next; // x0
  __int64 v6; // x23
  __int64 result; // x0
  __int64 property; // x0
  int v9; // w8
  unsigned __int64 v10; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x21
  __int64 v13; // x8
  const char *v14; // x2
  int v15; // w3
  int v16; // w4
  unsigned int v17; // w19
  unsigned int *v18; // x22
  int v19; // w23
  unsigned int v20; // w8
  unsigned int v21; // w24
  __int64 v22; // x21
  int i; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 968);
  v2 = *(_QWORD *)(a1 + 744);
  i = 0;
  v3 = *(_QWORD *)(v1 + 112);
  if ( v3 )
    ipc_log_string(
      *(_QWORD *)(v3 + 256),
      "%s[%d:%d] %s: Entered\n",
      *(const char **)(v1 + 128),
      *(_DWORD *)(v1 + 136),
      *(_DWORD *)(v1 + 140),
      "qcom_glink_announce_create");
  if ( (completion_done(v1 + 280) & 1) == 0 )
  {
    result = 0;
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(v3 + 216) & 1) == 0 )
  {
    *(_BYTE *)(v1 + 424) = 1;
    v4 = raw_spin_lock_irqsave(v1 + 144);
    for ( i = 0; ; ++i )
    {
      next = idr_get_next(v1 + 152, &i);
      if ( !next )
        break;
      if ( (*(_BYTE *)(next + 24) & 1) == 0 && (*(_BYTE *)(next + 26) & 1) == 0 )
      {
        v6 = next;
        raw_spin_unlock_irqrestore(v1 + 144, v4);
        qcom_glink_advertise_intent(v3, v1, v6);
        v4 = raw_spin_lock_irqsave(v1 + 144);
      }
    }
    raw_spin_unlock_irqrestore(v1 + 144, v4);
    property = of_find_property(v2, "qcom,intents", 0);
    if ( property )
    {
      v9 = *(_DWORD *)(property + 8);
      if ( (unsigned int)v9 < 8 )
        goto LABEL_14;
      v18 = *(unsigned int **)(property + 16);
      v19 = v9 >> 3;
    }
    else
    {
      v18 = (unsigned int *)&unk_D51C;
      v19 = 2;
    }
    do
    {
      v20 = v18[1];
      if ( v20 )
      {
        v21 = bswap32(v20);
        v22 = (int)bswap32(*v18);
        do
        {
          --v21;
          qcom_glink_queue_rx_intent_alloc(v1, v22, 1, 0);
        }
        while ( v21 );
      }
      --v19;
      v18 += 2;
    }
    while ( v19 );
  }
LABEL_14:
  v10 = kthread_create_on_node(qcom_glink_rx_thread, v1, 0xFFFFFFFFLL, "glink-%s", *(const char **)(v1 + 128));
  if ( v10 < 0xFFFFFFFFFFFFF001LL )
  {
    v12 = v10;
    wake_up_process(v10);
    *(_QWORD *)(v1 + 216) = v12;
    result = of_find_property(v2, "qcom,ch-sched-rt", 0);
    if ( result )
    {
      sched_set_fifo_low(*(_QWORD *)(v1 + 216));
      result = 0;
    }
  }
  else
  {
    v11 = *(_QWORD *)(v1 + 112);
    *(_QWORD *)(v1 + 216) = v10;
    if ( v11 )
    {
      ipc_log_string(
        *(_QWORD *)(v11 + 256),
        "%s[%d:%d] %s: channel thread failed to run\n",
        *(const char **)(v1 + 128),
        *(_DWORD *)(v1 + 136),
        *(_DWORD *)(v1 + 140),
        "qcom_glink_announce_create");
      if ( (unsigned int)__ratelimit(&qcom_glink_announce_create__rs, "qcom_glink_announce_create") )
        dev_err(**(_QWORD **)(v1 + 112), "[%s]: channel thread failed to run\n", "qcom_glink_announce_create");
    }
    result = *(unsigned int *)(v1 + 216);
    *(_QWORD *)(v1 + 216) = 0;
  }
  v13 = *(_QWORD *)(v1 + 112);
  if ( v13 )
  {
    v14 = *(const char **)(v1 + 128);
    v15 = *(_DWORD *)(v1 + 136);
    v16 = *(_DWORD *)(v1 + 140);
    v17 = result;
    ipc_log_string(*(_QWORD *)(v13 + 256), "%s[%d:%d] %s: Exit\n", v14, v15, v16, "qcom_glink_announce_create");
    result = v17;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
