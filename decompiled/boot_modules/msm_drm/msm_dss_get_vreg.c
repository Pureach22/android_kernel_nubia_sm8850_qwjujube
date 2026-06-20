unsigned __int64 __fastcall msm_dss_get_vreg(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x30
  unsigned __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x23
  __int64 v9; // x24
  __int64 i; // x20
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x19
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x23
  __int64 v17; // x8
  __int64 v18; // x20
  _QWORD *v19; // x19
  bool v20; // cc

  result = 0;
  if ( !a2 || !a3 )
    return result;
  if ( !a4 )
  {
    v17 = (unsigned int)(a3 - 1);
    if ( a3 - 1 >= 0 )
    {
      v18 = v17 + 1;
      v19 = (_QWORD *)(a2 + 72LL * (unsigned int)v17);
      do
      {
        if ( *v19 )
        {
          ((void (*)(void))regulator_put)();
          *v19 = 0;
        }
        v20 = v18-- <= 1;
        v19 -= 9;
      }
      while ( !v20 );
    }
    return 0;
  }
  if ( a3 < 1 )
    return 0;
  v7 = v4;
  v8 = 0;
  v9 = (unsigned int)a3;
  for ( i = a2 + 8; ; i += 72 )
  {
    v12 = regulator_get(a1, i);
    *(_QWORD *)(i - 8) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
      break;
    if ( v9 == ++v8 )
      return 0;
  }
  v13 = v12;
  printk(&unk_274416, v7);
  *(_QWORD *)(i - 8) = 0;
  if ( v8 )
  {
    v14 = v8 + 1;
    v15 = a2;
    do
    {
      v16 = 72LL * (unsigned int)(v14 - 2);
      regulator_set_load(*(_QWORD *)(v15 + v16), 0);
      regulator_put(*(_QWORD *)(a2 + v16));
      --v14;
      v15 = a2;
      *(_QWORD *)(a2 + v16) = 0;
    }
    while ( v14 > 1 );
  }
  return v13;
}
