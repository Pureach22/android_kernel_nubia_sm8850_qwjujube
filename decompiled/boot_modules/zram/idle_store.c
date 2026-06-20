__int64 __fastcall idle_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v5; // x20
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x21
  int v8; // w22
  __int64 v9; // x8
  __int64 v11; // x24
  __int64 v12; // x9
  int *v13; // x9
  int v14; // w10
  int v15; // t1

  v5 = *(__int64 **)(*(_QWORD *)(a1 - 224) + 88LL);
  if ( (sysfs_streq(a3, "all") & 1) == 0 )
    return -22;
  down_read(v5 + 4);
  v6 = v5[27];
  if ( v6 )
  {
    if ( v6 >= 0x1000 )
    {
      v7 = v6 >> 12;
      v8 = 1;
      do
      {
        v11 = 16LL * (unsigned int)(v8 - 1);
        raw_spin_lock(*v5 + v11 + 12);
        v9 = *v5;
        v12 = *v5 + v11;
        v15 = *(_DWORD *)(v12 + 8);
        v13 = (int *)(v12 + 8);
        v14 = v15;
        if ( (v15 & 0x1FFF) != 0 )
        {
          if ( (v14 & 0x8000) != 0 )
            goto LABEL_6;
        }
        else if ( (v14 & 0x6000) == 0 || (v14 & 0x8000) != 0 )
        {
          goto LABEL_6;
        }
        *v13 = v14 | 0x20000;
        v9 = *v5;
LABEL_6:
        raw_spin_unlock(v9 + 16LL * (unsigned int)(v8 - 1) + 12);
      }
      while ( v7 > v8++ );
    }
  }
  else
  {
    a4 = -22;
  }
  up_read(v5 + 4);
  return a4;
}
