__int64 __fastcall zram_meta_free(_QWORD *a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // x21
  __int64 v4; // x20

  if ( a2 >= 0x1000 )
  {
    v3 = a2 >> 12;
    v4 = 0;
    do
      zram_free_page(a1, v4++);
    while ( v3 != v4 );
  }
  zs_destroy_pool(a1[1]);
  return vfree(*a1);
}
