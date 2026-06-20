__int64 __fastcall gh_msgq_recv_state(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        _QWORD *a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 result; // x0
  __int64 v11; // x24
  __int64 v14; // x25
  void *v15; // x0
  char v16; // w8
  __int64 v17; // x19
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v25; // x20
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  result = 4294967274LL;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && a3 && a4 )
  {
    if ( a3 > 0xF0 )
    {
      result = 4294967289LL;
      goto LABEL_26;
    }
    v11 = *(_QWORD *)(a1 + 8);
    if ( !v11 )
      goto LABEL_22;
    v14 = a1;
    raw_spin_lock(v11 + 8);
    if ( *(_QWORD *)v11 != v14 )
    {
      printk(&unk_7200, "gh_msgq_recv_state");
      v17 = 4294967274LL;
      goto LABEL_25;
    }
    if ( (a5 & 0x100000000LL) != 0 && *(_QWORD *)(v11 + 24) == -1 )
    {
      if ( (unsigned int)__ratelimit(&gh_msgq_recv_state__rs, "gh_msgq_recv_state") )
      {
        v15 = &unk_7250;
LABEL_49:
        printk(v15, "gh_msgq_recv_state");
        goto LABEL_24;
      }
      goto LABEL_24;
    }
    raw_spin_unlock(v11 + 8);
    if ( *(_QWORD *)(v11 + 24) != -1 )
      goto LABEL_19;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v26 = 0;
    init_wait_entry(&v26, 0);
    while ( 1 )
    {
      result = prepare_to_wait_event(v11 + 96, &v26, a6);
      if ( *(_QWORD *)(v11 + 24) != -1 )
      {
        finish_wait(v11 + 96, &v26);
        goto LABEL_19;
      }
      if ( result )
        break;
      schedule();
    }
    if ( !(_DWORD)result )
    {
LABEL_19:
      raw_spin_lock(v11 + 8);
      if ( !*(_DWORD *)(v11 + 36) )
      {
        if ( (unsigned int)__ratelimit(&gh_msgq_recv_state__rs_23, "gh_msgq_recv_state") )
        {
          v15 = &unk_7161;
          goto LABEL_49;
        }
LABEL_24:
        v17 = 4294967285LL;
LABEL_25:
        raw_spin_unlock(v11 + 8);
        result = v17;
        goto LABEL_26;
      }
      raw_spin_unlock(v11 + 8);
      v16 = *(_BYTE *)(v11 + 65);
      if ( (a5 & 0x100000000LL) != 0 && *(_BYTE *)(v11 + 65) )
      {
LABEL_22:
        result = 4294967285LL;
        goto LABEL_26;
      }
      while ( 1 )
      {
        if ( (v16 & 1) != 0 )
        {
          v29 = 0;
          v30 = 0;
          v27 = 0;
          v28 = 0;
          v26 = 0;
          init_wait_entry(&v26, 0);
          result = prepare_to_wait_event(v11 + 96, &v26, a6);
          if ( *(_BYTE *)(v11 + 65) == 1 )
          {
            while ( !result )
            {
              schedule();
              result = prepare_to_wait_event(v11 + 96, &v26, a6);
              if ( (*(_BYTE *)(v11 + 65) & 1) == 0 )
                goto LABEL_31;
            }
            if ( (_DWORD)result )
              goto LABEL_26;
          }
          else
          {
LABEL_31:
            finish_wait(v11 + 96, &v26);
          }
        }
        v18 = raw_spin_lock_irqsave(v11 + 60);
        v19 = *(_QWORD *)(v11 + 24);
        __asm { HVC             #0x601C }
        v26 = 0;
        if ( (_DWORD)v19 != 60 )
          break;
        *(_BYTE *)(v11 + 65) = 1;
        raw_spin_unlock_irqrestore(v11 + 60, v18, a3, 0, 0, 0, 0, 0, v26);
        v16 = *(_BYTE *)(v11 + 65);
        if ( (a5 & 0x100000000LL) != 0 )
        {
          result = 4294967285LL;
          if ( (*(_BYTE *)(v11 + 65) & 1) != 0 )
            goto LABEL_26;
        }
      }
      if ( (int)v19 <= 9 )
      {
        if ( !(_DWORD)v19 )
        {
          *a4 = a2;
          *(_BYTE *)(v11 + 65) = a3 == 0;
          raw_spin_unlock_irqrestore(v11 + 60, v18, a3, 0, 0, 0, 0, 0, v26);
          result = 0;
          goto LABEL_26;
        }
        if ( (_DWORD)v19 == -1 )
        {
          v25 = 4294967201LL;
          goto LABEL_57;
        }
LABEL_56:
        v25 = 4294967274LL;
        goto LABEL_57;
      }
      if ( (unsigned int)v19 <= 0x3D )
      {
        if ( ((1LL << v19) & 0x7C000040000000LL) != 0 )
        {
          v25 = 4294967283LL;
LABEL_57:
          raw_spin_unlock_irqrestore(v11 + 60, v18, a3, 0, 0, 0, 0, 0, v26);
          printk(&unk_719F, "__gh_msgq_recv");
          result = v25;
          goto LABEL_26;
        }
        if ( ((1LL << v19) & 0x2000030000000000LL) != 0 )
        {
          v25 = 0xFFFFFFFFLL;
          goto LABEL_57;
        }
        if ( ((1LL << v19) & 0x180000000LL) != 0 )
        {
          v25 = 4294967280LL;
          goto LABEL_57;
        }
      }
      if ( (_DWORD)v19 == 10 )
      {
        v25 = 4294967284LL;
        goto LABEL_57;
      }
      goto LABEL_56;
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
