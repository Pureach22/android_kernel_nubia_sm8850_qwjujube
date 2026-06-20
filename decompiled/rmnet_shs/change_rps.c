__int64 __fastcall change_rps(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w8
  __int16 v10; // w9
  unsigned __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // t1
  __int64 v14; // x0
  unsigned __int64 v21; // x10
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v3 = *(_QWORD *)(a1 + 64);
  if ( v3 )
  {
    result = 0;
    *(_WORD *)(v3 + 24) = a2;
    *(_DWORD *)v3 = 1;
    if ( (((unsigned __int8)word_1949D >> a2) & 1) != 0 )
      ++qword_1A248;
    else
      ++qword_1A240;
  }
  else
  {
    _X9 = &v22[a2 >> 6];
    __asm { PRFM            #0x11, [X9] }
    do
      v21 = __ldxr(_X9);
    while ( __stxr(v21 | (1LL << a2), _X9) );
    v6 = 2 * _sw_hweight64(LODWORD(v22[0])) + 24;
    if ( v6 <= 0x40 )
      v7 = 64;
    else
      v7 = v6;
    v8 = _kmalloc_noprof(v7, 2336);
    if ( v8 )
    {
      v9 = (unsigned __int8)word_1949D >> a2;
      v10 = a2;
      v11 = v8;
      *(_WORD *)(v8 + 24) = v10;
      _ZF = (v9 & 1) == 0;
      v12 = 72;
      *(_DWORD *)v8 = 1;
      if ( _ZF )
        v12 = 64;
      ++*(_QWORD *)((char *)&rmnet_shs_switch_reason + v12);
      _rcu_read_lock();
      v13 = *(_QWORD *)(a1 + 64);
      atomic_store(v11, (unsigned __int64 *)(a1 + 64));
      v14 = kfree(v13);
      _rcu_read_unlock(v14);
      result = 0;
    }
    else
    {
      result = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
