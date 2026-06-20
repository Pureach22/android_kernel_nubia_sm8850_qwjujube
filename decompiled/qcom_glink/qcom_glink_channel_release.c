__int64 __fastcall qcom_glink_channel_release(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  _QWORD *v4; // x24
  __int64 v5; // x20
  _QWORD *v6; // x24
  __int64 next; // x0
  __int64 *v8; // x21
  __int64 v9; // x0
  _QWORD *v10; // x23
  __int64 *v11; // x21
  __int64 v12; // x0
  _QWORD *v13; // x23
  __int64 *v14; // x21
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0
  int i; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 8);
  i = 0;
  if ( v2 )
    ipc_log_string(
      *(_QWORD *)(v2 + 256),
      "%s[%d:%d] %s: \n",
      *(const char **)(a1 + 8),
      *(_DWORD *)(a1 + 16),
      *(_DWORD *)(a1 + 20),
      "qcom_glink_channel_release");
  v3 = raw_spin_lock_irqsave(a1 + 4);
  v4 = *(_QWORD **)(a1 + 104);
  if ( v4 != (_QWORD *)(a1 + 104) )
  {
    do
    {
      v10 = (_QWORD *)*v4;
      v11 = v4 - 5;
      raw_spin_lock(a1 + 24);
      idr_remove(a1 + 32, *((unsigned int *)v4 - 8));
      raw_spin_unlock(a1 + 24);
      if ( *(v4 - 3) )
      {
        v9 = *v11;
      }
      else
      {
        v9 = 0;
        *v11 = 0;
      }
      kfree(v9);
      kfree(v4 - 5);
      v4 = v10;
    }
    while ( v10 != (_QWORD *)(a1 + 104) );
  }
  raw_spin_unlock_irqrestore(a1 + 4, v3);
  v5 = raw_spin_lock_irqsave(a1 + 24);
  v6 = *(_QWORD **)(a1 + 80);
  if ( v6 != (_QWORD *)(a1 + 80) )
  {
    do
    {
      v13 = (_QWORD *)*v6;
      v14 = v6 - 5;
      idr_remove(a1 + 32, *((unsigned int *)v6 - 8));
      if ( *(v6 - 3) )
      {
        v12 = *v14;
      }
      else
      {
        v12 = 0;
        *v14 = 0;
      }
      kfree(v12);
      kfree(v6 - 5);
      v6 = v13;
    }
    while ( v13 != (_QWORD *)(a1 + 80) );
  }
  i = 0;
  next = idr_get_next(a1 + 32, &i);
  if ( next )
  {
    v8 = (__int64 *)next;
    do
    {
      if ( v8[2] )
      {
        v15 = *v8;
      }
      else
      {
        v15 = 0;
        *v8 = 0;
      }
      kfree(v15);
      kfree(v8);
      ++i;
      v8 = (__int64 *)idr_get_next(a1 + 32, &i);
    }
    while ( v8 );
  }
  idr_destroy(a1 + 32);
  for ( i = 0; ; ++i )
  {
    v16 = idr_get_next(a1 + 56, &i);
    if ( !v16 )
      break;
    kfree(v16);
  }
  idr_destroy(a1 + 56);
  raw_spin_unlock_irqrestore(a1 + 24, v5);
  kfree(*(_QWORD *)(a1 + 8));
  result = kfree(a1 - 120);
  _ReadStatusReg(SP_EL0);
  return result;
}
