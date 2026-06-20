__int64 __fastcall gen7_ringbuffer_submit(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x21
  unsigned int v8; // w20
  char v9; // w8
  unsigned int v17; // w9

  v4 = a1 - 1320LL * *(int *)(a1 + 28);
  adreno_get_submit_time(v4 - 14352, a1, a2);
  adreno_profile_submit_time(a2);
  v5 = raw_spin_lock_irqsave(a1 + 1292);
  v6 = *(_QWORD *)(v4 + 5288);
  v7 = v5;
  if ( *(_DWORD *)(v4 + 6136) )
  {
    v8 = 0;
    if ( v6 != a1 )
      goto LABEL_8;
    v9 = 1;
  }
  else
  {
    if ( v6 != a1 )
    {
      v8 = 0;
      goto LABEL_8;
    }
    v8 = gen7_fenced_write((_QWORD *)(v4 - 14352), 2055, *(_DWORD *)(a1 + 16), 1);
    v9 = 0;
  }
  *(_BYTE *)(a1 + 1296) = v9;
LABEL_8:
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 16);
  raw_spin_unlock_irqrestore(a1 + 1292, v7);
  if ( v8 )
  {
    gmu_core_fault_snapshot(v4 - 14352, 0);
    _X8 = (unsigned int *)(v4 + 10096);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 | 0x80, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(v4 + 10048), v4 + 10056);
  }
  return v8;
}
