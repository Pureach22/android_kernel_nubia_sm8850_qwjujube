__int64 __fastcall scheduler_mq_get(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x8
  __int64 v4; // x8
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  *(_QWORD *)(a1 + 8) = raw_spin_lock_irqsave(a1);
  v2 = qdf_list_remove_front((_DWORD *)(a1 + 16), v6);
  raw_spin_unlock_irqrestore(a1, *(_QWORD *)(a1 + 8));
  v3 = v6[0];
  _ReadStatusReg(SP_EL0);
  v4 = v3 - 32;
  if ( v2 )
    return 0;
  else
    return v4;
}
