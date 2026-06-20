__int64 __fastcall qcom_scm_lookup_wq(_QWORD *a1, unsigned int a2)
{
  __int64 v3; // x22
  __int64 v4; // x20
  __int64 v5; // x21
  _DWORD *v7; // x0
  int v8; // w0
  int v9; // w22
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2;
  v3 = a2;
  v4 = raw_spin_lock_irqsave(a1 + 27);
  v5 = idr_find(a1 + 24, v3);
  if ( !v5 )
  {
    v7 = (_DWORD *)devm_kmalloc(*a1, 32, 2336);
    if ( v7 )
    {
      v5 = (__int64)v7;
      *v7 = 0;
      _init_swait_queue_head(v7 + 2, "&x->wait", &init_completion___key);
      v8 = idr_alloc_u32(a1 + 24, v5, &v10, v3, 2080);
      if ( v8 < 0 )
      {
        v9 = v8;
        devm_kfree(*a1, v5);
        v5 = v9;
      }
    }
    else
    {
      v5 = -12;
    }
  }
  raw_spin_unlock_irqrestore(a1 + 27, v4);
  _ReadStatusReg(SP_EL0);
  return v5;
}
