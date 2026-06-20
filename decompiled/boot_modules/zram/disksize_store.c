__int64 __fastcall disksize_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v5; // x19
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  __int64 pool; // x0
  unsigned __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  char v16; // w8
  __int64 v17; // x0
  _QWORD *v19; // x0

  v5 = *(__int64 **)(*(_QWORD *)(a1 - 224) + 88LL);
  v6 = memparse(a3, 0);
  if ( v6 )
  {
    v7 = v6;
    down_write(v5 + 4);
    if ( v5[27] )
    {
      printk(&unk_B3EC);
      a4 = -16;
      goto LABEL_17;
    }
    v8 = v7 + 4095;
    v9 = v8 >> 12;
    v10 = vzalloc_noprof(16 * (v8 >> 12));
    *v5 = v10;
    if ( v10 )
    {
      pool = zs_create_pool(v5[3] + 12);
      v5[1] = pool;
      if ( pool )
      {
        v12 = v8 & 0xFFFFFFFFFFFFF000LL;
        if ( !huge_class_size )
          huge_class_size = zs_huge_class_size();
        if ( v12 )
        {
          v13 = 12;
          do
          {
            --v9;
            *(_DWORD *)(*v5 + v13) = 0;
            v13 += 16;
          }
          while ( v9 );
        }
        v14 = v5[28];
        if ( v14 )
        {
          v15 = zcomp_create(v14);
          if ( v15 >= 0xFFFFFFFFFFFFF001LL )
          {
            LODWORD(a4) = v15;
            printk(&unk_B66D);
            v19 = (_QWORD *)v5[2];
            v5[2] = 0;
            if ( v19 )
            {
              zcomp_destroy(v19);
              --*((_BYTE *)v5 + 232);
            }
            zram_meta_free(v5, v12);
            a4 = (int)a4;
            goto LABEL_17;
          }
          v16 = *((_BYTE *)v5 + 232);
          v5[2] = v15;
          *((_BYTE *)v5 + 232) = v16 + 1;
        }
        v17 = v5[3];
        v5[27] = v12;
        set_capacity_and_notify(v17, v12 >> 9);
LABEL_17:
        up_write(v5 + 4);
        return a4;
      }
      vfree(*v5);
    }
    a4 = -12;
    goto LABEL_17;
  }
  return -22;
}
