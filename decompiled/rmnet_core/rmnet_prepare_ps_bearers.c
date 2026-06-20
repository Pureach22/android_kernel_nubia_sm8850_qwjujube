__int64 __fastcall rmnet_prepare_ps_bearers(__int64 result, unsigned __int8 *a2, __int64 a3)
{
  unsigned __int8 v4; // w22
  __int64 v6; // x21
  __int64 lock; // x0
  __int64 v8; // x24
  unsigned __int8 v9; // w23
  __int64 v10; // x21
  __int64 i; // x8
  __int64 v12; // x25
  __int64 v13; // x0
  __int64 v14; // x2
  char v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && a2 )
  {
    v4 = *a2;
    v6 = result;
    v15[0] = 0;
    lock = _rcu_read_lock();
    v8 = 0;
    v9 = 0;
    v10 = v6 + 16;
    do
    {
      for ( i = *(_QWORD *)(v10 + 8 * v8); i; v4 -= v15[0] )
      {
        v12 = i - 16;
        if ( i == 16 )
          break;
        v13 = *(_QWORD *)(i - 8);
        v15[0] = v4;
        v14 = a3 ? a3 + v9 : 0LL;
        lock = qmi_rmnet_prepare_ps_bearers(v13, v15, v14);
        i = *(_QWORD *)(v12 + 16);
        v9 += v15[0];
      }
      ++v8;
    }
    while ( v8 != 255 );
    result = _rcu_read_unlock(lock);
    *a2 = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
