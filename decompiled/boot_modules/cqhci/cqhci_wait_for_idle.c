__int64 __fastcall cqhci_wait_for_idle(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x1
  char v3; // w8
  char v4; // w22
  unsigned int v5; // w19
  __int64 v6; // x0
  char v7; // w19
  char v8; // w22
  __int64 v9; // x0
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 1464);
  v2 = raw_spin_lock_irqsave(v1 + 24);
  v3 = *(_BYTE *)(v1 + 61);
  v4 = (*(_DWORD *)(v1 + 40) == 0) | v3;
  if ( (v3 & 1) != 0 )
    v5 = -16;
  else
    v5 = 0;
  *(_BYTE *)(v1 + 60) = ((*(_DWORD *)(v1 + 40) == 0) | v3 & 1) == 0;
  raw_spin_unlock_irqrestore(v1 + 24, v2);
  if ( (v4 & 1) == 0 )
  {
    memset(v11, 0, 40);
    init_wait_entry(v11, 0);
    while ( 1 )
    {
      prepare_to_wait_event(v1 + 160, v11, 2);
      v6 = raw_spin_lock_irqsave(v1 + 24);
      v7 = *(_BYTE *)(v1 + 61);
      v8 = (*(_DWORD *)(v1 + 40) == 0) | v7;
      *(_BYTE *)(v1 + 60) = ((*(_DWORD *)(v1 + 40) == 0) | v7 & 1) == 0;
      v9 = raw_spin_unlock_irqrestore(v1 + 24, v6);
      if ( (v8 & 1) != 0 )
        break;
      schedule(v9);
    }
    if ( (v7 & 1) != 0 )
      v5 = -16;
    else
      v5 = 0;
    finish_wait(v1 + 160, v11);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
