__int64 __fastcall getMostFrequent(__int16 *a1, _QWORD *a2)
{
  int v3; // w21
  int v4; // w22
  __int64 v6; // x8
  int v7; // w22
  int v8; // w8
  int v9; // w9
  int v10; // w1
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x11
  int i; // w8
  __int64 v23; // x9
  __int64 v24; // x26
  _DWORD *v25; // x8
  _DWORD *v26; // x9
  __int64 v27; // x24
  int v28; // w2
  __int64 v29; // x24

  if ( !a1 )
  {
    printk(&unk_61D9B);
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    printk(&unk_6210A);
    return 4294967294LL;
  }
  v3 = *((_DWORD *)a1 + 7);
  v4 = *((_DWORD *)a1 + 8);
  if ( v3 == v4 )
  {
    printk(&unk_6364C);
    return 4294967293LL;
  }
  if ( *((int *)a1 + 6) >= 1 )
  {
    v6 = 0;
    do
      *(_DWORD *)(*((_QWORD *)a1 + 2) + 4 * v6++) = 1;
    while ( v6 < *((int *)a1 + 6) );
  }
  if ( *a1 >= 1 )
  {
    printk(&unk_672C7);
    printk(&unk_61DB7);
    if ( *((int *)a1 + 6) >= 1 )
    {
      v29 = 0;
      do
      {
        printk(&unk_65C5F);
        ++v29;
      }
      while ( v29 < *((int *)a1 + 6) );
    }
    printk(&unk_640C4);
    if ( v4 > 0 )
      goto LABEL_10;
    goto LABEL_9;
  }
  if ( v4 <= 0 )
LABEL_9:
    v4 = *((_DWORD *)a1 + 6);
LABEL_10:
  v7 = v4 - 1;
  while ( v7 != v3 )
  {
    if ( *a1 > 0 )
      printk(&unk_63672);
    if ( *(int *)(*((_QWORD *)a1 + 2) + 4LL * v7) <= 0 )
    {
      if ( v7 <= 0 )
        v7 = *((_DWORD *)a1 + 6);
      --v7;
    }
    else
    {
      for ( i = *((_DWORD *)a1 + 7); i != v7; i = ((int)v24 + 1) % *((_DWORD *)a1 + 6) )
      {
        v23 = *((_QWORD *)a1 + 1);
        v24 = i;
        if ( *a1 >= 1 )
        {
          printk(&unk_66436);
          v23 = *((_QWORD *)a1 + 1);
        }
        v25 = (_DWORD *)(v23 + 88LL * v7);
        v26 = (_DWORD *)(v23 + 88LL * (int)v24);
        if ( *v25 == *v26 && v25[1] == v26[1] && v25[2] == v26[2] && v25[3] == v26[3] )
        {
          ++*(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL * v7);
          *(_DWORD *)(*((_QWORD *)a1 + 2) + 4 * v24) = 0;
          if ( *a1 >= 1 )
            printk(&unk_63AB2);
        }
      }
      if ( v7 <= 0 )
        v7 = *((_DWORD *)a1 + 6);
      --v7;
      if ( *a1 >= 1 )
      {
        printk(&unk_61DB7);
        if ( *((int *)a1 + 6) >= 1 )
        {
          v27 = 0;
          do
          {
            printk(&unk_65C5F);
            ++v27;
          }
          while ( v27 < *((int *)a1 + 6) );
        }
        printk(&unk_640C4);
        printk(&unk_62FEF);
      }
    }
  }
  v8 = *((_DWORD *)a1 + 7);
  v9 = *((_DWORD *)a1 + 8);
  if ( v9 == v8 )
  {
    v10 = -1;
  }
  else
  {
    v28 = 0;
    v10 = -1;
    do
    {
      if ( *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL * v9) > v28 )
      {
        v28 = *(_DWORD *)(*((_QWORD *)a1 + 2) + 4LL * v9);
        v10 = v9;
      }
      if ( v9 <= 0 )
        v9 = *((_DWORD *)a1 + 6);
      --v9;
    }
    while ( v9 != v8 );
  }
  v11 = (_QWORD *)(*((_QWORD *)a1 + 1) + 88LL * v10);
  v13 = v11[1];
  v12 = v11[2];
  *a2 = *v11;
  a2[1] = v13;
  a2[2] = v12;
  v14 = v11[6];
  v15 = v11[3];
  v16 = v11[4];
  a2[5] = v11[5];
  a2[6] = v14;
  a2[3] = v15;
  a2[4] = v16;
  v18 = v11[9];
  v17 = v11[10];
  v20 = v11[7];
  v19 = v11[8];
  a2[9] = v18;
  a2[10] = v17;
  a2[7] = v20;
  a2[8] = v19;
  if ( *a1 >= 1 )
    printk(&unk_6644F);
  return 0;
}
