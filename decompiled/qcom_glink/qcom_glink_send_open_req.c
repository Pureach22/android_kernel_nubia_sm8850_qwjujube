__int64 __fastcall qcom_glink_send_open_req(__int64 a1, __int64 a2)
{
  const char *v4; // x0
  size_t v5; // x21
  __int64 v7; // x23
  unsigned int v8; // w22
  __int64 v9; // x8
  const char *v10; // x22
  size_t v11; // x2
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v15; // x1
  unsigned int v21; // w8
  _WORD v22[2]; // [xsp+0h] [xbp-30h] BYREF
  int v23; // [xsp+4h] [xbp-2Ch]
  _QWORD v24[5]; // [xsp+8h] [xbp-28h] BYREF

  v24[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const char **)(a2 + 128);
  memset(v24, 0, 32);
  v5 = strlen(v4);
  for ( _X0 = (unsigned int *)(a2 + 120); ; _X0 = (unsigned int *)_fortify_panic(31, 32, v11) )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v21 = __ldxr(_X0);
    while ( __stxr(v21 + 1, _X0) );
    if ( v21 )
    {
      if ( (((v21 + 1) | v21) & 0x80000000) == 0 )
        goto LABEL_3;
      v15 = 1;
    }
    else
    {
      v15 = 2;
    }
    refcount_warn_saturate(_X0, v15);
LABEL_3:
    v7 = raw_spin_lock_irqsave(a1 + 156);
    v8 = idr_alloc_cyclic(a1 + 160, a2, 1, 0x10000, 2080);
    raw_spin_unlock_irqrestore(a1 + 156, v7);
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_11;
    v9 = *(_QWORD *)(a2 + 112);
    *(_DWORD *)(a2 + 136) = v8;
    if ( v9 )
    {
      ipc_log_string(
        *(_QWORD *)(v9 + 256),
        "%s[%d:%d] %s: \n",
        *(const char **)(a2 + 128),
        v8,
        *(_DWORD *)(a2 + 140),
        "qcom_glink_send_open_req");
      v8 = *(_DWORD *)(a2 + 136);
    }
    v22[1] = v8;
    v10 = *(const char **)(a2 + 128);
    v22[0] = 2;
    v23 = v5 + 1;
    v11 = strlen(v10) + 1;
    if ( v11 < 0x21 )
      break;
  }
  memcpy(v24, v10, v11);
  v8 = qcom_glink_tx(a1, (__int64)v22, ((v5 >> 3 << 35) + 0x1000000000LL) >> 32, 0, 0, 1);
  if ( v8 )
  {
    v12 = *(_QWORD *)(a2 + 112);
    if ( v12 )
      ipc_log_string(
        *(_QWORD *)(v12 + 256),
        "%s[%d:%d] %s: remote_idr\n",
        *(const char **)(a2 + 128),
        *(_DWORD *)(a2 + 136),
        *(_DWORD *)(a2 + 140),
        "qcom_glink_send_open_req");
    v13 = raw_spin_lock_irqsave(a1 + 156);
    idr_remove(a1 + 160, *(unsigned int *)(a2 + 136));
    *(_DWORD *)(a2 + 136) = 0;
    raw_spin_unlock_irqrestore(a1 + 156, v13);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v8;
}
