unsigned int *__fastcall qcom_smd_destroy_ept(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x0
  unsigned int *result; // x0
  int v19; // w8

  v1 = *(_QWORD *)(a1 + 104);
  v3 = *(_QWORD *)(v1 + 8);
  v4 = raw_spin_lock_irqsave(v1 + 144);
  *(_QWORD *)(v3 + 16) = 0;
  raw_spin_unlock_irqrestore(v1 + 144, v4);
  kfree(*(_QWORD *)(v1 + 136));
  v5 = *(_DWORD *)(v1 + 32);
  *(_QWORD *)(v1 + 136) = 0;
  if ( !v5 )
    goto LABEL_17;
  v6 = *(_QWORD *)(v1 + 72);
  if ( v6 )
  {
    *(_DWORD *)(v6 + 4) = 0;
    v7 = *(_QWORD *)(v1 + 72);
    if ( v7 )
      goto LABEL_4;
  }
  else
  {
    *(_BYTE *)(*(_QWORD *)(v1 + 64) + 4LL) = 0;
    v7 = *(_QWORD *)(v1 + 72);
    if ( v7 )
    {
LABEL_4:
      *(_DWORD *)(v7 + 8) = 0;
      v8 = *(_QWORD *)(v1 + 72);
      if ( v8 )
        goto LABEL_5;
LABEL_11:
      *(_BYTE *)(*(_QWORD *)(v1 + 64) + 6LL) = 0;
      v9 = *(_DWORD **)(v1 + 72);
      if ( v9 )
        goto LABEL_7;
      goto LABEL_6;
    }
  }
  *(_BYTE *)(*(_QWORD *)(v1 + 64) + 5LL) = 0;
  v8 = *(_QWORD *)(v1 + 72);
  if ( !v8 )
    goto LABEL_11;
LABEL_5:
  *(_DWORD *)(v8 + 12) = 0;
  v9 = *(_DWORD **)(v1 + 72);
  if ( !v9 )
LABEL_6:
    v9 = *(_DWORD **)(v1 + 64);
LABEL_7:
  *v9 = 0;
  v10 = *(_QWORD *)(v1 + 72);
  if ( v10 )
    *(_DWORD *)(v10 + 28) = 1;
  else
    *(_BYTE *)(*(_QWORD *)(v1 + 64) + 10LL) = 1;
  v11 = *(_QWORD *)v1;
  *(_DWORD *)(v1 + 32) = 0;
  v12 = *(_QWORD *)(v11 + 1016);
  if ( v12 )
  {
    mbox_send_message(v12, 0);
    mbox_client_txdone(*(_QWORD *)(v11 + 1016), 0);
  }
  else
  {
    regmap_write(*(_QWORD *)(v11 + 944), *(unsigned int *)(v11 + 952), 1LL << *(_DWORD *)(v11 + 956));
  }
LABEL_17:
  qcom_smd_channel_reset((__int64 *)v1);
  result = (unsigned int *)(a1 + 8);
  *(_QWORD *)(v1 + 8) = 0;
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr(result);
  while ( __stlxr(v19 - 1, result) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    return (unsigned int *)kfree(a1);
  }
  else if ( v19 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
