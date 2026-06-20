__int64 __fastcall qcrypto_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x20
  void (__fastcall *v4)(__int64); // x8
  __int64 v5; // x0
  __int64 v6; // x0
  int v7; // w8
  unsigned int v8; // w22

  v1 = *(_QWORD *)(a1 + 168);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 32);
  if ( *(_BYTE *)(v2 + 35) != 1 )
    return 0;
  v3 = raw_spin_lock_irqsave(v2 + 52);
  if ( *(_DWORD *)(v1 + 112) == 4 )
  {
    raw_spin_unlock_irqrestore(v2 + 52, v3);
    if ( timer_delete_sync )
    {
      qcrypto_ce_set_bus(v1, 1);
      v4 = (void (__fastcall *)(__int64))timer_delete_sync;
      v5 = *(_QWORD *)(v1 + 16);
      if ( *((_DWORD *)timer_delete_sync - 1) != -1066802076 )
        __break(0x8228u);
      v4(v5);
      qcrypto_ce_set_bus(v1, 0);
    }
    v6 = raw_spin_lock_irqsave(v2 + 52);
    v7 = *(_DWORD *)(v1 + 224);
    *(_DWORD *)(v1 + 112) = 0;
    v3 = v6;
    *(_BYTE *)(v1 + 232) = 0;
    *(_DWORD *)(v1 + 224) = v7 + 1;
    if ( (*(_DWORD *)(v2 + 216) || *(_DWORD *)(v1 + 72)) && (*(_BYTE *)(v1 + 116) & 1) == 0 )
    {
      queue_work_on(32, system_wq, v1 + 192);
      v8 = 0;
      *(_BYTE *)(v1 + 116) = 1;
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    v8 = -16;
  }
  raw_spin_unlock_irqrestore(v2 + 52, v3);
  return v8;
}
