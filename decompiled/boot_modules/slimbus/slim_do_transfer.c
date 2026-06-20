__int64 __fastcall slim_do_transfer(_QWORD *a1, unsigned __int8 *a2)
{
  bool v4; // w22
  int v5; // w9
  int v6; // w8
  unsigned __int8 v7; // w9
  char v8; // w23
  __int64 v9; // x24
  int v10; // w0
  int v11; // w2
  _DWORD *v12; // x8
  int v13; // w0
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 result; // x0
  __int64 v17; // x21
  unsigned int v18; // w19
  __int64 v19; // x21
  unsigned int v20; // w0
  __int64 v21; // x21
  unsigned int v22; // w21
  unsigned int v23; // w22
  __int64 v24; // x21
  __int64 v25; // x8
  unsigned int v26; // w9
  unsigned int v33; // w11
  unsigned int v34; // w21
  _QWORD v35[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v36[3]; // [xsp+18h] [xbp-18h] BYREF

  v4 = 0;
  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a1 + 44);
  v6 = a2[1];
  v35[0] = 0;
  v35[1] = 0;
  v36[0] = v36;
  v36[1] = v36;
  if ( v5 == 1 && !v6 )
    v4 = (a2[2] & 0xE0) == 64;
  v7 = a2[2];
  a2[6] = 0;
  v8 = (v7 - 32) & 0xBE | v6;
  if ( v8 )
    goto LABEL_5;
  v19 = raw_spin_lock_irqsave(a1 + 21);
  v20 = idr_alloc_cyclic(a1 + 18, a2, 1, 256, 2080);
  if ( (v20 & 0x80000000) != 0 )
  {
    v18 = v20;
    raw_spin_unlock_irqrestore(a1 + 21, v19);
    goto LABEL_23;
  }
  a2[6] = v20;
  raw_spin_unlock_irqrestore(a1 + 21, v19);
  if ( *(_QWORD *)(*((_QWORD *)a2 + 1) + 24LL) )
  {
LABEL_5:
    v9 = 0;
    if ( v4 )
      goto LABEL_8;
  }
  else
  {
    v9 = *((_QWORD *)a2 + 2);
    *((_QWORD *)a2 + 2) = v35;
    if ( v4 )
      goto LABEL_8;
  }
  v10 = _pm_runtime_resume(*a1, 4);
  if ( v10 < 0 )
  {
    v23 = v10;
    dev_err(*a1, "runtime resume failed ret:%d\n", v10);
    v24 = raw_spin_lock_irqsave(a1 + 21);
    idr_remove(a1 + 18, a2[6]);
    raw_spin_unlock_irqrestore(a1 + 21, v24);
    v25 = *a1;
    v26 = *(_DWORD *)(*a1 + 480LL);
    do
    {
      if ( !v26 )
        break;
      _X13 = (unsigned int *)(v25 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v33 = __ldxr(_X13);
        if ( v33 != v26 )
          break;
        if ( !__stlxr(v26 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v33 == v26;
      v26 = v33;
    }
    while ( !_ZF );
    _pm_runtime_set_status(*a1, 2);
    if ( v8 )
    {
      result = v23;
    }
    else
    {
      result = v23;
      if ( !*(_QWORD *)(*((_QWORD *)a2 + 1) + 24LL) )
        *((_QWORD *)a2 + 2) = v9;
    }
    goto LABEL_24;
  }
  v11 = *((_DWORD *)a1 + 44);
  if ( !v11 )
  {
LABEL_8:
    v12 = (_DWORD *)a1[33];
    if ( *(v12 - 1) != 12333069 )
      __break(0x8228u);
    v13 = ((__int64 (__fastcall *)(_QWORD *, unsigned __int8 *))v12)(a1, a2);
    if ( v13 )
    {
      if ( v13 != -110 )
        goto LABEL_27;
    }
    else
    {
      if ( v8
        || *(_QWORD *)(*((_QWORD *)a2 + 1) + 24LL)
        || (v14 = *((_QWORD *)a2 + 2),
            v15 = _msecs_to_jiffies((unsigned int)*a2 + 250),
            (unsigned int)wait_for_completion_timeout(v14, v15)) )
      {
        result = 0;
        if ( v4 )
          goto LABEL_24;
        goto LABEL_15;
      }
      *((_QWORD *)a2 + 2) = 0;
    }
    v21 = raw_spin_lock_irqsave(a1 + 21);
    idr_remove(a1 + 18, a2[6]);
    raw_spin_unlock_irqrestore(a1 + 21, v21);
    v13 = -110;
LABEL_27:
    v22 = v13;
    dev_err(*a1, "Tx:MT:0x%x, MC:0x%x, LA:0x%x failed:%d\n", a2[1], a2[2], a2[7], v13);
    result = v22;
    if ( v4 )
      goto LABEL_24;
LABEL_15:
    if ( (_DWORD)result == -110 )
    {
LABEL_17:
      v17 = *a1;
      v18 = result;
      *(_QWORD *)(v17 + 520) = ktime_get_mono_fast_ns(result);
      _pm_runtime_suspend(*a1, 13);
LABEL_23:
      result = v18;
      goto LABEL_24;
    }
    goto LABEL_16;
  }
  v34 = v10;
  dev_err(*a1, "ctrl wrong state:%d, ret:%d\n", v11, v10);
  if ( !v8 && !*(_QWORD *)(*((_QWORD *)a2 + 1) + 24LL) )
    *((_QWORD *)a2 + 2) = v9;
  result = v34;
  if ( v34 == -110 )
    goto LABEL_17;
LABEL_16:
  if ( !a2[6] )
    goto LABEL_17;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
