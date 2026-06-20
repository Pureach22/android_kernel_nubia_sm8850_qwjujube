__int64 __fastcall po_show(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v10; // x19
  unsigned int v11; // w21
  unsigned int v17; // w8
  const char *v18; // x3
  __int64 v20; // x20

  _X0 = (unsigned int *)_rcu_read_lock(a1, a2, a3, a4, a5, a6, a7, a8);
  v10 = primordial_object;
  if ( (unsigned __int64)primordial_object < 2 )
    goto LABEL_20;
  _X0 = (unsigned int *)(primordial_object + 8);
  v11 = *(_DWORD *)(primordial_object + 8);
  if ( v11 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v17 = __ldxr(_X0);
      while ( v17 == v11 && __stxr(v11 + 1, _X0) );
      if ( v17 == v11 )
        break;
      v11 = v17;
    }
    while ( v17 );
  }
  if ( (((v11 + 1) | v11) & 0x80000000) == 0 )
  {
    if ( v11 )
      goto LABEL_11;
LABEL_20:
    _rcu_read_unlock(_X0);
    return 0;
  }
  _X0 = (unsigned int *)refcount_warn_saturate(_X0, 0);
  if ( !v11 )
    goto LABEL_20;
LABEL_11:
  _rcu_read_unlock(_X0);
  if ( !v10 )
    return 0;
  if ( v10 == 1 )
  {
    v18 = "root";
  }
  else if ( *(_QWORD *)v10 )
  {
    v18 = *(const char **)v10;
  }
  else
  {
    v18 = "noname";
  }
  v20 = (int)scnprintf(a3, 4096, "%s %d\n", v18, *(_DWORD *)(v10 + 8) - 1);
  put_si_object(v10);
  return v20;
}
