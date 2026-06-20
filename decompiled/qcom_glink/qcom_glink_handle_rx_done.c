__int64 __fastcall qcom_glink_handle_rx_done(_QWORD *a1, unsigned int a2, unsigned int a3, char a4)
{
  void (*v8)(void); // x8
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 v15; // x23
  __int64 v16; // x8
  __int64 result; // x0
  __int64 v18; // x1
  unsigned int v24; // w8
  int v26; // w8

  v8 = *(void (**)(void))(a1[2] + 24LL);
  if ( *((_DWORD *)v8 - 1) != -290755086 )
    __break(0x8228u);
  v8();
  if ( !a1 )
    return dev_err(*a1, "invalid channel id received\n");
  v9 = raw_spin_lock_irqsave((char *)a1 + 156);
  v10 = idr_find(a1 + 23, a2);
  if ( !v10 )
  {
    raw_spin_unlock_irqrestore((char *)a1 + 156, v9);
    return dev_err(*a1, "invalid channel id received\n");
  }
  v11 = v10;
  _X19 = (unsigned int *)(v10 + 120);
  __asm { PRFM            #0x11, [X19] }
  do
    v24 = __ldxr(_X19);
  while ( __stxr(v24 + 1, _X19) );
  if ( v24 )
  {
    if ( (((v24 + 1) | v24) & 0x80000000) == 0 )
      goto LABEL_7;
    v18 = 1;
  }
  else
  {
    v18 = 2;
  }
  refcount_warn_saturate(v10 + 120, v18);
LABEL_7:
  raw_spin_unlock_irqrestore((char *)a1 + 156, v9);
  v13 = raw_spin_lock_irqsave(v11 + 144);
  v14 = idr_find(v11 + 176, a3);
  if ( v14 )
  {
    *(_BYTE *)(v14 + 25) = 0;
    v15 = v14;
    v16 = *(_QWORD *)(v11 + 112);
    if ( v16 )
      ipc_log_string(
        *(_QWORD *)(v16 + 256),
        "%s[%d:%d] %s: reuse:%d iid:%d\n",
        *(const char **)(v11 + 128),
        *(_DWORD *)(v11 + 136),
        *(_DWORD *)(v11 + 140),
        "qcom_glink_handle_rx_done",
        a4 & 1,
        *(_DWORD *)(v14 + 8));
    if ( (a4 & 1) != 0 )
    {
      raw_spin_unlock_irqrestore(v11 + 144, v13);
      *(_BYTE *)(v11 + 396) = 1;
      result = _wake_up(v11 + 400, 3, 0, 0);
    }
    else
    {
      idr_remove(v11 + 176, *(unsigned int *)(v15 + 8));
      kfree(v15);
      result = raw_spin_unlock_irqrestore(v11 + 144, v13);
    }
    __asm { PRFM            #0x11, [X19] }
    do
      v26 = __ldxr(_X19);
    while ( __stlxr(v26 - 1, _X19) );
    if ( v26 != 1 )
      goto LABEL_26;
LABEL_13:
    __dmb(9u);
    return qcom_glink_channel_release(_X19);
  }
  raw_spin_unlock_irqrestore(v11 + 144, v13);
  result = dev_err(*a1, "invalid intent id received\n");
  __asm { PRFM            #0x11, [X19] }
  do
    v26 = __ldxr(_X19);
  while ( __stlxr(v26 - 1, _X19) );
  if ( v26 == 1 )
    goto LABEL_13;
LABEL_26:
  if ( v26 <= 0 )
    return refcount_warn_saturate(_X19, 3);
  return result;
}
