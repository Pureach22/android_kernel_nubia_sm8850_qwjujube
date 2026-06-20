__int64 __fastcall dynamic_page_pool_shrink_high_and_low(__int64 *a1, int a2, int a3)
{
  __int64 v6; // x21
  __int64 v7; // t1

  mutex_lock(&pool_list_lock);
  if ( a2 >= 1 )
  {
    v6 = (unsigned int)a2 - 1LL;
    do
    {
      v7 = *a1++;
      a3 -= dynamic_page_pool_do_shrink(v7, 2, (unsigned int)a3);
    }
    while ( a3 >= 1 && v6-- != 0 );
  }
  return mutex_unlock(&pool_list_lock);
}
