__int64 __fastcall get_gpuaddr(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        unsigned __int64 a4,
        unsigned __int64 a5,
        __int64 a6)
{
  __int64 v12; // x25
  __int64 v13; // x8
  __int64 v14; // x26
  unsigned __int64 v15; // x23
  __int64 v16; // x0
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  __int64 result; // x0
  unsigned int inserted; // w21

  raw_spin_lock(a1);
  v12 = a6 - 1;
  if ( HIDWORD(a4) && (v13 = *(_QWORD *)(a1 + 176)) != 0 )
  {
    v14 = -a6;
    v15 = (v13 + v12) & -a6;
    if ( v15 + a5 <= a4 )
    {
      *(_QWORD *)(a1 + 176) = v15 + a5;
      if ( v15 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_23;
    }
  }
  else
  {
    v14 = -a6;
  }
  v16 = rb_first(a1 + 120);
  v17 = v14 & (v12 + a3);
  if ( v16 )
  {
    v15 = v17;
    while ( 1 )
    {
      while ( 1 )
      {
        v19 = *(_QWORD *)(v16 - 16);
        if ( v19 >= v17 )
          break;
        v18 = *(_QWORD *)(v16 - 8) + v19;
        if ( v18 > v17 )
          v15 = (v18 + v12) & v14;
        v16 = rb_next();
        if ( !v16 )
          goto LABEL_20;
      }
      if ( v19 >= a4 )
        goto LABEL_20;
      if ( v19 > v15 && v19 - v15 >= a5 )
        break;
      v20 = *(_QWORD *)(v16 - 8) + v19;
      if ( v20 >= a4 )
        goto LABEL_22;
      v15 = (v20 + v12) & v14;
      v16 = rb_next();
      if ( !v16 )
        goto LABEL_20;
    }
  }
  else
  {
    v15 = v17;
LABEL_20:
    if ( v15 + a5 > a4 )
      goto LABEL_22;
  }
  if ( v15 == -12 )
  {
LABEL_22:
    raw_spin_unlock(a1);
    return 4294967284LL;
  }
LABEL_23:
  inserted = insert_gpuaddr(a1, v15, a5);
  raw_spin_unlock(a1);
  result = inserted;
  if ( !inserted )
  {
    a2[3] = v15;
    *a2 = a1;
  }
  return result;
}
