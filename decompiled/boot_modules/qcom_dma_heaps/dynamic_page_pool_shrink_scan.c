__int64 __fastcall dynamic_page_pool_shrink_scan(__int64 a1, int *a2)
{
  int v2; // w19
  int v3; // w20
  _UNKNOWN **v4; // x22
  int v5; // w23
  int v6; // w0
  __int64 v7; // x19

  v2 = a2[2];
  if ( !v2 )
    return 0;
  v3 = *a2;
  mutex_lock(&pool_list_lock);
  v4 = (_UNKNOWN **)pool_list;
  if ( pool_list == (_UNKNOWN *)&pool_list )
  {
    v7 = 0;
  }
  else
  {
    v5 = 0;
    do
    {
      v6 = dynamic_page_pool_do_shrink((__int64)(v4 - 10), v3, v2);
      v2 -= v6;
      v5 += v6;
      if ( v2 < 1 )
        break;
      v4 = (_UNKNOWN **)*v4;
    }
    while ( v4 != &pool_list );
    v7 = v5;
  }
  mutex_unlock(&pool_list_lock);
  return v7;
}
