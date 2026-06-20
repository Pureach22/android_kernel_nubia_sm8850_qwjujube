__int64 __fastcall ipc_log_extract(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w20
  __int64 lock_irqsave; // x21
  int v8; // w8
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 *v11; // x8
  _DWORD *v12; // x28
  _QWORD v14[2]; // [xsp+8h] [xbp-138h] BYREF
  int v15; // [xsp+18h] [xbp-128h]
  int v16; // [xsp+1Ch] [xbp-124h]
  __int16 v17; // [xsp+24h] [xbp-11Ch] BYREF
  _DWORD s[66]; // [xsp+28h] [xbp-118h] BYREF
  __int64 v19; // [xsp+130h] [xbp-10h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 1020 )
  {
    memset(s, 0, sizeof(s));
    v14[1] = a2;
    v16 = 0;
    v14[0] = 0;
    v15 = a3;
    lock_irqsave = raw_read_lock_irqsave(&context_list_lock_lha1);
    raw_spin_lock(a1 + 160);
    if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
      goto LABEL_4;
    if ( a1 )
    {
      v8 = a3;
      do
      {
        v9 = *(_QWORD *)(a1 + 120);
        v10 = *(_QWORD *)(a1 + 104);
        if ( v9 == v10 && *(unsigned __int16 *)(v9 + 64) == *(unsigned __int16 *)(v10 + 14) )
          break;
        v17 = 0;
        ((void (__fastcall *)(__int64, __int16 *, __int64))ipc_log_read)(a1, &v17, 2);
        s[65] = 2;
        LOWORD(s[0]) = v17;
        ((void (__fastcall *)(__int64, _DWORD *))ipc_log_read)(a1, &s[1]);
        v11 = (__int64 *)(a1 + 144);
        while ( 1 )
        {
          v11 = (__int64 *)*v11;
          if ( v11 == (__int64 *)(a1 + 144) )
            break;
          if ( *((_DWORD *)v11 + 4) == LOBYTE(s[0]) )
          {
            v12 = (_DWORD *)v11[3];
            goto LABEL_14;
          }
        }
        v12 = nullptr;
LABEL_14:
        raw_spin_unlock(a1 + 160);
        raw_read_unlock_irqrestore(&context_list_lock_lha1, lock_irqsave);
        if ( v12 )
        {
          if ( *(v12 - 1) != -578754878 )
            __break(0x823Cu);
          ((void (__fastcall *)(_DWORD *, _QWORD *))v12)(s, v14);
        }
        else
        {
          printk(&unk_83C9, "ipc_log_extract");
        }
        lock_irqsave = raw_read_lock_irqsave(&context_list_lock_lha1);
        raw_spin_lock(a1 + 160);
        v8 = v15;
      }
      while ( v15 > 1019 );
    }
    else
    {
      v8 = a3;
    }
    v3 = a3 - v8;
    if ( v3 )
      goto LABEL_25;
    if ( (*(_BYTE *)(a1 + 204) & 1) != 0 )
    {
LABEL_4:
      v3 = -5;
    }
    else
    {
      v3 = 0;
      *(_DWORD *)(a1 + 168) = 0;
    }
LABEL_25:
    raw_spin_unlock(a1 + 160);
    raw_read_unlock_irqrestore(&context_list_lock_lha1, lock_irqsave);
    goto LABEL_26;
  }
  v3 = -22;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return v3;
}
