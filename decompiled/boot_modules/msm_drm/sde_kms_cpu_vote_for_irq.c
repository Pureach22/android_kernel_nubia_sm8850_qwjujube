__int64 __fastcall sde_kms_cpu_vote_for_irq(__int64 a1, char a2)
{
  __int64 v4; // x21
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int v16; // w8
  unsigned int v17; // w8

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
  mutex_lock(v4 + 64);
  if ( (a2 & 1) != 0 )
  {
    _X9 = (unsigned int *)(a1 + 3760);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v12 = __ldxr(_X9);
      v13 = v12 + 1;
    }
    while ( __stlxr(v13, _X9) );
    __dmb(0xBu);
    if ( v13 == 1 )
      sde_kms_update_pm_qos_irq_request(a1, (__int64 *)(a1 + 3752));
  }
  else
  {
    _X9 = (unsigned int *)(a1 + 3760);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v16 = __ldxr(_X9);
      v17 = v16 - 1;
    }
    while ( __stlxr(v17, _X9) );
    __dmb(0xBu);
    if ( !v17 )
      sde_kms_remove_pm_qos_irq_request(a1, (_DWORD *)(a1 + 3752));
  }
  return mutex_unlock(v4 + 64);
}
