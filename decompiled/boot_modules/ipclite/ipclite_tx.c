__int64 __fastcall ipclite_tx(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w20
  int v10; // w8
  __int64 v11; // x21
  __int64 (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x0
  _DWORD *v16; // x8
  __int64 v17; // x20
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v8 = a3;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 696);
  v18[0] = a2;
  if ( v10 == 2 )
    goto LABEL_5;
  if ( v10 != 1 || **(_DWORD **)(a1 + 688) != 2 )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FE1B, "ipclite", "ipclite_tx");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_13;
        goto LABEL_12;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_12:
        ipclite_inmem_log("APPS:%s:Cannot Send, Channel not active\n", (__int64)"ERR", a3, a4, a5, a6, a7, a8, v18[0]);
    }
LABEL_13:
    result = 4294967201LL;
    goto LABEL_17;
  }
  *(_DWORD *)(a1 + 696) = 2;
LABEL_5:
  v11 = raw_spin_lock_irqsave(a1 + 24);
  v12 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
  v13 = *(_QWORD *)(a1 + 8);
  if ( *((_DWORD *)v12 - 1) != -1899415283 )
    __break(0x8229u);
  if ( (unsigned __int64)v12(v13) > 7 )
  {
    v15 = *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 100) = v8;
    v16 = *(_DWORD **)(v15 + 56);
    if ( *(v16 - 1) != -995833395 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v16)(v15, v18);
    v17 = a1 + 104LL * v8;
    mbox_send_message(*(_QWORD *)(v17 + 88), 0);
    mbox_client_txdone(*(_QWORD *)(v17 + 88), 0);
    raw_spin_unlock_irqrestore(a1 + 24, v11);
    result = 0;
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 24, v11);
    result = 4294967285LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
