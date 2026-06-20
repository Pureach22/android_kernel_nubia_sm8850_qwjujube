__int64 __fastcall notify_adc_tm_fn(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 *i; // x9
  int v5; // w11
  __int64 *j; // x9
  int v7; // w12
  int v8; // w12
  unsigned int v9; // w0
  __int64 v10; // x2
  unsigned int v11; // w0
  __int64 v12; // x2
  __int64 result; // x0
  __int64 *v14; // x19
  __int64 *k; // x20
  __int64 *v16; // t1
  __int64 v17; // x9
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x1
  __int64 v20; // x9
  _DWORD *v21; // x8
  __int64 v22; // x1

  v1 = *(_QWORD *)(a1 - 88);
  v3 = a1 - 144;
  mutex_lock(v1 + 96);
  if ( *(_BYTE *)(a1 - 39) == 1 )
  {
    for ( i = *(__int64 **)(a1 + 32); i != (__int64 *)(a1 + 32); i = (__int64 *)*i )
    {
      if ( *((_BYTE *)i + 35) == 1 )
      {
        v5 = *((_DWORD *)i + 9);
        *((_BYTE *)i + 35) = 0;
        *((_BYTE *)i + 32) = 1;
        *((_DWORD *)i + 9) = 4 * (v5 != 2);
      }
    }
    *(_BYTE *)(a1 - 39) = 0;
  }
  if ( *(_BYTE *)(a1 - 40) == 1 )
  {
    for ( j = *(__int64 **)(a1 + 32); j != (__int64 *)(a1 + 32); j = (__int64 *)*j )
    {
      if ( *((_BYTE *)j + 34) == 1 )
      {
        v7 = *((_DWORD *)j + 9);
        *(_WORD *)((char *)j + 33) = 1;
        if ( v7 == 2 )
          v8 = 1;
        else
          v8 = 3;
        *((_DWORD *)j + 9) = v8;
      }
    }
    *(_BYTE *)(a1 - 40) = 0;
  }
  v9 = adc_tm_gen3_manage_thresholds(v3);
  if ( (v9 & 0x80000000) != 0 )
    printk(&unk_92ED, v9, v10);
  v11 = adc_tm5_gen3_configure(v3);
  if ( (v11 & 0x80000000) != 0 )
    printk(&unk_9A3C, v11, v12);
  result = mutex_unlock(v1 + 96);
  v16 = *(__int64 **)(a1 + 32);
  v14 = (__int64 *)(a1 + 32);
  for ( k = v16; k != v14; k = (__int64 *)*k )
  {
    if ( *((_BYTE *)k + 32) == 1 )
    {
      v17 = k[2];
      v18 = *(__int64 (__fastcall **)(__int64, __int64))(v17 + 32);
      if ( v18 )
      {
        v19 = *(_QWORD *)(v17 + 24);
        if ( *((_DWORD *)v18 - 1) != -1236019055 )
          __break(0x8228u);
        result = v18(1, v19);
        *((_BYTE *)k + 32) = 0;
      }
    }
    if ( *((_BYTE *)k + 33) == 1 )
    {
      v20 = k[2];
      v21 = *(_DWORD **)(v20 + 32);
      if ( v21 )
      {
        v22 = *(_QWORD *)(v20 + 24);
        if ( *(v21 - 1) != -1236019055 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_QWORD, __int64))v21)(0, v22);
        *((_BYTE *)k + 33) = 0;
      }
    }
  }
  return result;
}
