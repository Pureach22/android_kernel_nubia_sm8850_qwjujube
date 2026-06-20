__int64 __fastcall a6xx_ringbuffer_submit(__int64 a1, _QWORD *a2, char a3)
{
  __int64 v6; // x22
  unsigned __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x21
  char v12; // w8
  unsigned int v20; // w9

  v6 = a1 - 1320LL * *(int *)(a1 + 28);
  adreno_get_submit_time(v6 - 14352, a1, a2);
  adreno_profile_submit_time(a2);
  if ( (a3 & 1) != 0 && (*(_BYTE *)(*(_QWORD *)(v6 - 88) + 33LL) & 8) == 0 )
  {
    v7 = adreno_ringbuffer_allocspace(a1, 3);
    v8 = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      return v8;
    *(_DWORD *)v7 = 1885470722;
    *(_QWORD *)(v7 + 4) = *(_QWORD *)(*(_QWORD *)(v6 - 14304) + 24LL) + 32LL * *(int *)(a1 + 28);
  }
  v9 = raw_spin_lock_irqsave(a1 + 1292);
  v10 = *(_QWORD *)(v6 + 5288);
  v11 = v9;
  if ( *(_DWORD *)(v6 + 6136) )
  {
    v8 = 0;
    if ( v10 != a1 )
      goto LABEL_12;
    v12 = 1;
  }
  else
  {
    if ( v10 != a1 )
    {
      v8 = 0;
      goto LABEL_12;
    }
    v8 = a6xx_fenced_write((_QWORD *)(v6 - 14352), 2055, *(_DWORD *)(a1 + 16), 1);
    v12 = 0;
  }
  *(_BYTE *)(a1 + 1296) = v12;
LABEL_12:
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 16);
  raw_spin_unlock_irqrestore(a1 + 1292, v11);
  if ( v8 )
  {
    gmu_core_fault_snapshot(v6 - 14352, 0);
    _X8 = (unsigned int *)(v6 + 10096);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 | 0x80, _X8) );
    __dmb(0xAu);
    kthread_queue_work(*(_QWORD *)(v6 + 10048), v6 + 10056);
  }
  return v8;
}
