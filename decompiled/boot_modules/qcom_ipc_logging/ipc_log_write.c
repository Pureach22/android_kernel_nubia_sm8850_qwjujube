__int64 __fastcall ipc_log_write(__int64 a1, __int64 a2)
{
  __int64 lock_irqsave; // x20
  __int64 v5; // x10
  __int64 v6; // x11
  unsigned int v7; // w8
  unsigned __int64 v8; // x9
  signed int v9; // w24
  __int64 v10; // x8
  unsigned __int64 v11; // x9
  void *v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 result; // x0
  __int16 dest; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    result = printk(&unk_840E, "ipc_log_write");
    goto LABEL_24;
  }
  lock_irqsave = raw_read_lock_irqsave(&context_list_lock_lha1);
  raw_spin_lock(a1 + 160);
LABEL_8:
  v7 = *(_DWORD *)(a2 + 260);
  while ( *(_DWORD *)(a1 + 128) <= v7 )
  {
    v6 = *(_QWORD *)(a1 + 104);
    v5 = *(_QWORD *)(a1 + 112);
    if ( v5 != v6 || *(unsigned __int16 *)(v5 + 12) != *(unsigned __int16 *)(v6 + 14) )
    {
      dest = 0;
      ipc_log_drop(a1, &dest);
      ipc_log_drop(a1, nullptr);
      goto LABEL_8;
    }
  }
  v8 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 104) + 14LL);
  if ( 4024 - v8 >= (int)v7 )
    v9 = *(_DWORD *)(a2 + 260);
  else
    v9 = 4024 - v8;
  if ( v8 >= 0xFB9 )
    goto LABEL_28;
  v10 = *(_QWORD *)(a1 + 104);
  v11 = *(unsigned __int16 *)(v10 + 14);
  if ( v11 > 0xFB8 )
    goto LABEL_28;
  v12 = memcpy((void *)(v10 + v11 + 72), (const void *)(a2 + 2), v9);
  if ( v9 != *(_DWORD *)(a2 + 260) )
  {
    v13 = sched_clock(v12);
    *(_WORD *)(*(_QWORD *)(a1 + 104) + 14LL) += v9;
    *(_QWORD *)(*(_QWORD *)(a1 + 104) + 32LL) = v13;
    v14 = *(_QWORD *)(a1 + 104);
    if ( v14 )
    {
      if ( *(_QWORD *)(a1 + 96) == v14 )
      {
        v15 = *(_QWORD *)(a1 + 88);
        *(_QWORD *)(a1 + 104) = v15;
        if ( v15 )
          goto LABEL_18;
      }
      else
      {
        v15 = *(_QWORD *)(v14 + 48) - 48LL;
        *(_QWORD *)(a1 + 104) = v15;
        if ( v15 )
        {
LABEL_18:
          *(_WORD *)(v15 + 14) = 0;
          *(_QWORD *)(*(_QWORD *)(a1 + 104) + 24LL) = v13;
          if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 104) + 14LL) <= 0xFB8u && (unsigned int)v9 <= 0xFF )
          {
            v16 = *(_QWORD *)(a1 + 104);
            v17 = *(unsigned __int16 *)(v16 + 14);
            if ( v17 <= 0xFB8 )
            {
              memcpy((void *)(v16 + v17 + 72), (const void *)(a2 + 2 + v9), *(_DWORD *)(a2 + 260) - v9);
              v9 = *(_DWORD *)(a2 + 260) - v9;
              goto LABEL_22;
            }
          }
LABEL_28:
          __break(0x5512u);
        }
      }
    }
    __break(0x800u);
    goto LABEL_23;
  }
LABEL_22:
  *(_WORD *)(*(_QWORD *)(a1 + 104) + 14LL) += v9;
  *(_DWORD *)(a1 + 128) -= *(_DWORD *)(a2 + 260);
  complete(a1 + 168);
LABEL_23:
  raw_spin_unlock(a1 + 160);
  result = raw_read_unlock_irqrestore(&context_list_lock_lha1, lock_irqsave);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
