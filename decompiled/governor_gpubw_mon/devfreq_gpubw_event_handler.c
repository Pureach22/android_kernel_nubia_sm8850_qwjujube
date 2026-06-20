__int64 __fastcall devfreq_gpubw_event_handler(_QWORD *a1, int a2)
{
  const char **v2; // x8
  const char *v5; // x0
  unsigned int v6; // w20
  __int64 v7; // x21
  __int64 v8; // x22
  int v9; // w20
  _DWORD *v10; // x0
  __int64 v11; // x8
  unsigned int v12; // w10
  unsigned int v13; // w8
  int v14; // w11
  unsigned int v15; // w12
  unsigned int v16; // w8
  unsigned int i; // w10
  __int64 v18; // x11
  _QWORD *v19; // x20
  _QWORD *v20; // x8
  int v21; // w9
  unsigned int v22; // w8

  v2 = (const char **)a1[20];
  v5 = v2[14];
  if ( !v5 )
    v5 = *v2;
  if ( !strcmp(v5, "kgsl-busmon") )
  {
    mutex_lock(a1 + 2);
    switch ( a2 )
    {
      case 4:
        v20 = (_QWORD *)a1[148];
        if ( v20 )
        {
          v6 = 0;
          v20[9] = 0;
          v20[6] = 0;
          v20[7] = 0;
          goto LABEL_33;
        }
        break;
      case 2:
        v19 = (_QWORD *)a1[148];
        device_remove_file(a1 + 8, &dev_attr_sampling_interval);
        device_remove_file(a1 + 8, &dev_attr_cur_ab);
        if ( v19 )
        {
          kfree(v19[12]);
          kfree(v19[13]);
          kfree(v19[14]);
          kfree(v19[15]);
        }
        v6 = 0;
        a1[148] = 0;
        goto LABEL_33;
      case 1:
        v7 = a1[122];
        v8 = *(_QWORD *)(v7 - 8);
        a1[148] = v8;
        v9 = 4 * *(_DWORD *)(v8 + 80);
        *(_QWORD *)(v8 + 96) = _kmalloc_noprof(v9, 3520);
        *(_QWORD *)(v8 + 104) = _kmalloc_noprof(v9, 3520);
        *(_QWORD *)(v8 + 112) = _kmalloc_noprof(v9, 3520);
        v10 = (_DWORD *)_kmalloc_noprof(v9, 3520);
        v11 = *(_QWORD *)(v8 + 96);
        *(_QWORD *)(v8 + 120) = v10;
        if ( v11 && *(_QWORD *)(v8 + 104) )
        {
          v6 = -12;
          if ( !*(_QWORD *)(v8 + 112) || !v10 )
            goto LABEL_33;
          v12 = *(_DWORD *)(v8 + 80);
          if ( v12 )
          {
            v13 = 0;
            v14 = 10;
            do
            {
              v15 = (unsigned int)(100 * *(_DWORD *)(*(_QWORD *)(v8 + 128) + 4LL * (int)v13))
                  / *(_DWORD *)(*(_QWORD *)(v8 + 128) + 4LL * (v12 - 1));
              *(_DWORD *)(*(_QWORD *)(v8 + 112) + 4LL * (int)v13) = v15 - 5;
              *(_DWORD *)(*(_QWORD *)(v8 + 120) + 4LL * (int)v13++) = v14 - 10;
              v14 = v15;
              v12 = *(_DWORD *)(v8 + 80);
            }
            while ( v13 < v12 );
            v10 = *(_DWORD **)(v8 + 120);
          }
          *v10 = 0;
          v16 = *(_DWORD *)(v8 + 80);
          if ( v16 )
          {
            for ( i = 0; i < v16; ++i )
            {
              v18 = *(_QWORD *)(v8 + 120);
              if ( *(int *)(v18 + 4LL * (int)i) <= 9 )
              {
                *(_DWORD *)(v18 + 4LL * (int)i) = 10;
                v16 = *(_DWORD *)(v8 + 80);
              }
            }
            if ( v16 )
            {
              *(_DWORD *)(*(_QWORD *)(v8 + 112) + 4LL * (v16 - 1)) = 100;
              if ( *(_DWORD *)(v8 + 80) )
              {
                v21 = *(_DWORD *)(v8 + 84);
                v22 = 0;
                do
                {
                  *(_DWORD *)(*(_QWORD *)(v8 + 96) + 4LL * (int)v22) = *(_DWORD *)(*(_QWORD *)(v8 + 112) + 4LL * (int)v22)
                                                                     * v21
                                                                     / 0x64u;
                  *(_DWORD *)(*(_QWORD *)(v8 + 104) + 4LL * (int)v22) = *(_DWORD *)(*(_QWORD *)(v8 + 120)
                                                                                  + 4LL * (int)v22)
                                                                      * v21
                                                                      / 0x64u;
                  ++v22;
                }
                while ( v22 < *(_DWORD *)(v8 + 80) );
              }
            }
          }
          *(_DWORD *)(v7 - 28) = 50000;
          device_create_file(a1 + 8, &dev_attr_sampling_interval);
          device_create_file(a1 + 8, &dev_attr_cur_ab);
          break;
        }
        v6 = -12;
LABEL_33:
        mutex_unlock(a1 + 2);
        return v6;
    }
    v6 = 0;
    goto LABEL_33;
  }
  return (unsigned int)-22;
}
