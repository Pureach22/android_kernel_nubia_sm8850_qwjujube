__int64 __fastcall gh_msgq_send(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v10; // x23
  void *v11; // x0
  __int64 v12; // x0
  char v13; // w8
  unsigned int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v23; // w20
  __int64 v24; // [xsp+0h] [xbp-30h] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h]
  __int64 v26; // [xsp+10h] [xbp-20h]
  __int64 v27; // [xsp+18h] [xbp-18h]
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  result = 4294967274LL;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && a3 )
  {
    if ( a3 > 0xF0 )
    {
      result = 4294967289LL;
      goto LABEL_25;
    }
    v8 = *(_QWORD *)(a1 + 8);
    if ( !v8 )
      goto LABEL_21;
    v10 = a1;
    raw_spin_lock(v8 + 8);
    if ( *(_QWORD *)v8 != v10 )
    {
      printk(&unk_7200, "gh_msgq_send");
      v14 = -22;
      goto LABEL_24;
    }
    if ( (a4 & 0x100000000LL) != 0 && *(_QWORD *)(v8 + 16) == -1 )
    {
      if ( (unsigned int)__ratelimit(&gh_msgq_send__rs, "gh_msgq_send") )
      {
        v11 = &unk_747B;
LABEL_48:
        printk(v11, "gh_msgq_send");
        goto LABEL_23;
      }
      goto LABEL_23;
    }
    raw_spin_unlock(v8 + 8);
    if ( *(_QWORD *)(v8 + 16) == -1 )
    {
      v27 = 0;
      v28 = 0;
      v25 = 0;
      v26 = 0;
      v24 = 0;
      init_wait_entry(&v24, 0);
      while ( 1 )
      {
        v12 = prepare_to_wait_event(v8 + 72, &v24, 1);
        if ( *(_QWORD *)(v8 + 16) != -1 )
        {
          finish_wait(v8 + 72, &v24);
          goto LABEL_18;
        }
        if ( v12 )
          break;
        schedule();
      }
      if ( (_DWORD)v12 )
      {
LABEL_44:
        result = 4294966784LL;
        goto LABEL_25;
      }
    }
LABEL_18:
    raw_spin_lock(v8 + 8);
    if ( !*(_DWORD *)(v8 + 32) )
    {
      if ( (unsigned int)__ratelimit(&gh_msgq_send__rs_10, "gh_msgq_send") )
      {
        v11 = &unk_72C4;
        goto LABEL_48;
      }
LABEL_23:
      v14 = -11;
LABEL_24:
      raw_spin_unlock(v8 + 8);
      result = v14;
      goto LABEL_25;
    }
    raw_spin_unlock(v8 + 8);
    v13 = *(_BYTE *)(v8 + 64);
    if ( (a4 & 0x100000000LL) != 0 )
    {
      if ( *(_BYTE *)(v8 + 64) )
      {
LABEL_21:
        result = 4294967285LL;
        goto LABEL_25;
      }
    }
    while ( 1 )
    {
      if ( (v13 & 1) != 0 )
      {
        v27 = 0;
        v28 = 0;
        v25 = 0;
        v26 = 0;
        v24 = 0;
        init_wait_entry(&v24, 0);
        v15 = prepare_to_wait_event(v8 + 72, &v24, 1);
        if ( *(_BYTE *)(v8 + 64) == 1 )
        {
          while ( !v15 )
          {
            schedule();
            v15 = prepare_to_wait_event(v8 + 72, &v24, 1);
            if ( (*(_BYTE *)(v8 + 64) & 1) == 0 )
              goto LABEL_30;
          }
          if ( (_DWORD)v15 )
            goto LABEL_44;
        }
        else
        {
LABEL_30:
          finish_wait(v8 + 72, &v24);
        }
      }
      v16 = raw_spin_lock_irqsave(v8 + 56);
      v17 = *(_QWORD *)(v8 + 16);
      __asm { HVC             #0x601B }
      v24 = 0;
      if ( (_DWORD)v17 != 61 )
        break;
      *(_BYTE *)(v8 + 64) = 1;
      raw_spin_unlock_irqrestore(v8 + 56, v16, a2, (unsigned int)a4, 0, 0, 0, 0, v24);
      v13 = *(_BYTE *)(v8 + 64);
      if ( (a4 & 0x100000000LL) != 0 )
      {
        result = 4294967285LL;
        if ( (*(_BYTE *)(v8 + 64) & 1) != 0 )
          goto LABEL_25;
      }
    }
    if ( (int)v17 <= 9 )
    {
      if ( !(_DWORD)v17 )
      {
        *(_BYTE *)(v8 + 64) = a3 == 0;
        raw_spin_unlock_irqrestore(v8 + 56, v16, a2, (unsigned int)a4, 0, 0, 0, 0, v24);
        result = 0;
        goto LABEL_25;
      }
      if ( (_DWORD)v17 == -1 )
      {
        v23 = -95;
        goto LABEL_56;
      }
LABEL_55:
      v23 = -22;
      goto LABEL_56;
    }
    if ( (unsigned int)v17 <= 0x3C )
    {
      if ( ((1LL << v17) & 0x7C000040000000LL) != 0 )
      {
        v23 = -13;
LABEL_56:
        raw_spin_unlock_irqrestore(v8 + 56, v16, a2, (unsigned int)a4, 0, 0, 0, 0, v24);
        printk(&unk_7430, "__gh_msgq_send");
        result = v23;
        goto LABEL_25;
      }
      if ( ((1LL << v17) & 0x1000030000000000LL) != 0 )
      {
        v23 = -1;
        goto LABEL_56;
      }
      if ( ((1LL << v17) & 0x180000000LL) != 0 )
      {
        v23 = -16;
        goto LABEL_56;
      }
    }
    if ( (_DWORD)v17 == 10 )
    {
      v23 = -12;
      goto LABEL_56;
    }
    goto LABEL_55;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
