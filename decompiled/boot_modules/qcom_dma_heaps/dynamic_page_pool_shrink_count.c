__int64 __fastcall dynamic_page_pool_shrink_count(__int64 a1, int *a2)
{
  int v2; // w19
  _UNKNOWN **v3; // x21
  int v4; // w22
  int v5; // w0
  __int64 v6; // x19

  v2 = *a2;
  mutex_lock(&pool_list_lock);
  v3 = (_UNKNOWN **)pool_list;
  if ( pool_list == (_UNKNOWN *)&pool_list )
  {
    v6 = 0;
  }
  else
  {
    v4 = 0;
    do
    {
      v5 = dynamic_page_pool_do_shrink((__int64)(v3 - 10), v2, 0);
      v3 = (_UNKNOWN **)*v3;
      v4 += v5;
    }
    while ( v3 != &pool_list );
    v6 = v4;
  }
  mutex_unlock(&pool_list_lock);
  return v6;
}
