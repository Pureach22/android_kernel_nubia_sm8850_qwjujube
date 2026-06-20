unsigned int *__fastcall qtee_get_si_object(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int *v8; // x19
  unsigned int v10; // w8
  unsigned int v16; // w9
  unsigned int v18; // w20
  _QWORD v19[3]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_DWORD)a1 != 0x80000000 )
  {
    v19[0] = &xa_si_objects;
    v19[1] = (unsigned int)a1;
    v19[2] = 0;
    v20 = 3;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    _rcu_read_lock(a1, a2, a3, a4, a5, a6, a7, a8);
    while ( 1 )
    {
      _X0 = (unsigned int *)xas_load(v19);
      v8 = _X0 == (unsigned int *)((char *)&trace_event_type_funcs_si_objcet_do_ctx_invoke_ret + 6) ? nullptr : _X0;
      if ( v8 != (unsigned int *)((char *)&trace_event_type_funcs_si_objcet_do_ctx_invoke_ret + 2) )
        break;
      v20 = 3;
    }
    if ( (unsigned __int64)v8 >= 2 )
    {
      _X0 = v8 + 2;
      v10 = v8[2];
      if ( v10 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v16 = __ldxr(_X0);
          while ( v16 == v10 && __stxr(v10 + 1, _X0) );
          if ( v16 == v10 )
            break;
          v10 = v16;
        }
        while ( v16 );
      }
      if ( (((v10 + 1) | v10) & 0x80000000) != 0 )
      {
        v18 = v10;
        _X0 = (unsigned int *)refcount_warn_saturate(_X0, 0);
        if ( v18 )
          goto LABEL_20;
      }
      else if ( v10 )
      {
LABEL_20:
        _rcu_read_unlock(_X0);
        goto LABEL_21;
      }
    }
    v8 = nullptr;
    goto LABEL_20;
  }
  v8 = (unsigned int *)&static_si_object_primordial;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v8;
}
