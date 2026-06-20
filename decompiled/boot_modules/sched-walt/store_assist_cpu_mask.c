__int64 __fastcall store_assist_cpu_mask(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  __int64 v6; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v5 = kstrtoull(a2, 0, v8);
  if ( v5 < 0 )
  {
    a3 = v5;
  }
  else
  {
    temp_bitmap = v8[0];
    v6 = raw_spin_lock_irqsave(&state_lock);
    *(_QWORD *)(a1 + 280) = temp_bitmap;
    raw_spin_unlock_irqrestore(&state_lock, v6);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
