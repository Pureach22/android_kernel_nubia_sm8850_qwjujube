__int64 __fastcall next_tgid(unsigned int *_X0, __int64 a2, __int64 a3)
{
  unsigned int *v3; // x19
  int v9; // w8
  unsigned int *v11; // x20
  __int64 v12; // x0
  __int64 v14; // x1
  unsigned int v16; // w8
  __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v3 = _X0;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a2;
  if ( a3 )
  {
    _X0 = (unsigned int *)(a3 + 64);
    __asm { PRFM            #0x11, [X0] }
    do
      v9 = __ldxr(_X0);
    while ( __stlxr(v9 - 1, _X0) );
    if ( v9 == 1 )
    {
      __dmb(9u);
      _X0 = (unsigned int *)_put_task_struct(a3);
    }
    else if ( v9 <= 0 )
    {
      _X0 = (unsigned int *)refcount_warn_saturate(_X0, 3);
    }
  }
  _rcu_read_lock(_X0);
  while ( 1 )
  {
    v18 = 0;
    _X0 = (unsigned int *)idr_get_next(v3, &v17);
    if ( !_X0 )
      break;
    v11 = _X0;
    LODWORD(v17) = pid_nr_ns(_X0, v3);
    v12 = pid_task(v11, 1);
    v18 = v12;
    if ( v12 )
    {
      _X0 = (unsigned int *)(v12 + 64);
      __asm { PRFM            #0x11, [X0] }
      do
        v16 = __ldxr(_X0);
      while ( __stxr(v16 + 1, _X0) );
      if ( v16 )
      {
        if ( (((v16 + 1) | v16) & 0x80000000) == 0 )
          break;
        v14 = 1;
      }
      else
      {
        v14 = 2;
      }
      _X0 = (unsigned int *)refcount_warn_saturate(_X0, v14);
      break;
    }
    LODWORD(v17) = v17 + 1;
  }
  _rcu_read_unlock(_X0);
  _ReadStatusReg(SP_EL0);
  return v17;
}
