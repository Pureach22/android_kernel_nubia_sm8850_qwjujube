__int64 __fastcall fastrpc_dspsignal_wait(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x20
  __int64 v6; // x23
  __int64 v7; // x1
  __int64 v8; // x8
  _DWORD *v9; // x21
  bool v10; // zf
  int v11; // w8
  __int64 v12; // x23
  __int64 v13; // x0
  int v14; // w8

  v4 = _usecs_to_jiffies(*(unsigned int *)(a2 + 8));
  v5 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v5 >= 0x400 )
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Waiting on bad signal %u\n", v5);
    LODWORD(v12) = -22;
    return (unsigned int)v12;
  }
  v6 = v4;
  v7 = raw_spin_lock_irqsave(a1 + 324);
  v8 = *(_QWORD *)(a1 + ((v5 >> 5) & 0x7FFFFF8) + 504);
  v9 = (_DWORD *)(v8 + 40LL * (unsigned __int8)v5);
  if ( v8 )
    v10 = v9 == nullptr;
  else
    v10 = 1;
  if ( !v10 )
  {
    v11 = v9[8];
    if ( v11 > 1 )
    {
      if ( v11 == 2 )
      {
        LODWORD(v12) = 0;
        *v9 = 0;
        v9[8] = 1;
        goto LABEL_24;
      }
      if ( v11 == 3 )
      {
LABEL_9:
        LODWORD(v12) = -4;
LABEL_24:
        raw_spin_unlock_irqrestore(a1 + 324, v7);
        return (unsigned int)v12;
      }
LABEL_23:
      LODWORD(v12) = 0;
      goto LABEL_24;
    }
    if ( v11 == 1 )
    {
      raw_spin_unlock_irqrestore(a1 + 324, v7);
      if ( v6 == 0xFFFFFFFFLL )
        v12 = (int)wait_for_completion_interruptible(v9);
      else
        v12 = wait_for_completion_interruptible_timeout(v9, v6);
      if ( !v12 )
      {
        LODWORD(v12) = -110;
        return (unsigned int)v12;
      }
      if ( v12 < 0 )
      {
        dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Wait for signal %u failed %d\n", v5, v12);
        return (unsigned int)v12;
      }
      v13 = raw_spin_lock_irqsave(a1 + 324);
      v14 = v9[8];
      v7 = v13;
      if ( !v14 || v14 == 3 )
        goto LABEL_9;
      if ( v14 == 2 )
      {
        LODWORD(v12) = 0;
        v9[8] = 1;
        goto LABEL_24;
      }
      goto LABEL_23;
    }
    if ( v11 )
      goto LABEL_23;
  }
  raw_spin_unlock_irqrestore(a1 + 324, v7);
  dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Unknown signal id %u\n", v5);
  LODWORD(v12) = -2;
  return (unsigned int)v12;
}
