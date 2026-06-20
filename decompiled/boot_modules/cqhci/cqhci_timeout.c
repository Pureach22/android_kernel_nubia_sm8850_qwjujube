bool __fastcall cqhci_timeout(_QWORD *a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x20
  int v7; // w21
  __int64 v8; // x26
  __int64 v9; // x0
  __int64 v10; // x25
  __int64 v11; // x24
  __int64 v13; // x8
  __int64 v14; // x4
  __int64 v15; // x1
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4

  v3 = a1[183];
  if ( *(_QWORD *)(a2 + 8) )
    v7 = 31;
  else
    v7 = *(_DWORD *)(a2 + 124);
  v8 = *(_QWORD *)(v3 + 184) + 16LL * v7;
  v9 = raw_spin_lock_irqsave(v3 + 24);
  v10 = *(_QWORD *)v8;
  v11 = v9;
  if ( *(_QWORD *)v8 == a2 )
  {
    *(_DWORD *)(v8 + 8) |= 1u;
    v13 = a1[183];
    if ( (*(_BYTE *)(v13 + 61) & 1) == 0 )
    {
      *(_BYTE *)(v13 + 61) = 1;
      _wake_up(v13 + 160, 3, 1, 0);
    }
    *a3 = *(_BYTE *)(v3 + 61);
    raw_spin_unlock_irqrestore(v3 + 24, v11);
    v15 = a1[15];
    if ( !v15 )
      v15 = a1[1];
    printk(&unk_9FCC, v15, (unsigned int)v7, *(unsigned int *)(v3 + 40), v14);
    cqhci_dumpregs((__int64 (__fastcall ***)(_QWORD))v3, v16, v17, v18, v19);
  }
  else
  {
    raw_spin_unlock_irqrestore(v3 + 24, v9);
  }
  return v10 == a2;
}
