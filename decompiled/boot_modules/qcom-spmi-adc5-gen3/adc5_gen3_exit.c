__int64 __fastcall adc5_gen3_exit(__int64 a1)
{
  _QWORD *v1; // x20
  unsigned int v2; // w21
  __int64 v3; // x8
  __int64 v4; // x8
  int v5; // w21
  int v6; // w8
  __int64 v7; // x9
  unsigned int v8; // w24
  __int64 v9; // x10
  __int64 v10; // x0
  __int64 v11; // x9
  _QWORD *v12; // x8
  _QWORD *v13; // x0
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 result; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 168);
  v17[0] = 0;
  mutex_lock(v1 + 12);
  if ( *((_DWORD *)v1 + 10) )
  {
    v2 = 0;
    do
    {
      v4 = v1[6];
      if ( *(_QWORD *)(v4 + 200LL * (int)v2 + 136) )
      {
        destroy_workqueue();
        v4 = v1[6];
      }
      v3 = v4 + 200LL * (int)v2++;
      *(_DWORD *)(v3 + 80) = 0;
    }
    while ( v2 < *((_DWORD *)v1 + 10) );
  }
  if ( (*((_DWORD *)v1 + 9) & 0x1FFFFFFF) != 0 )
  {
    v5 = 0;
    do
    {
      v6 = v5 + 7;
      v7 = v1[3];
      if ( v5 >= 0 )
        v6 = v5;
      v17[0] = 0;
      v8 = v6 >> 3;
      if ( (regmap_bulk_write(
              *v1,
              (unsigned int)*(unsigned __int16 *)(v7 + 24LL * (unsigned int)(v6 >> 3)) + 81,
              v17,
              1)
          & 0x80000000) != 0 )
        printk(&unk_95F2, 81, 1);
      v9 = v1[3];
      v10 = *v1;
      v17[0] = (v5 - 8 * v8) | 0x80;
      if ( (regmap_bulk_write(v10, (unsigned int)*(unsigned __int16 *)(v9 + 24LL * v8) + 80, v17, 1) & 0x80000000) != 0 )
        printk(&unk_95F2, 80, 1);
      v11 = v1[3];
      v17[0] = 1;
      if ( (regmap_bulk_write(*v1, (unsigned int)*(unsigned __int16 *)(v11 + 24LL * v8) + 229, v17, 1) & 0x80000000) != 0 )
        printk(&unk_95F2, 229, 1);
      ++v5;
    }
    while ( v5 < (unsigned int)(8 * *((_DWORD *)v1 + 9)) );
  }
  mutex_unlock(v1 + 12);
  if ( *((_DWORD *)v1 + 36) )
  {
    cancel_work_sync(v1 + 26);
    cancel_work_sync(v1 + 22);
  }
  v12 = (_QWORD *)v1[20];
  v13 = v1 + 19;
  if ( (_QWORD *)*v12 == v1 + 19 && (v14 = *v13, *(_QWORD **)(*v13 + 8LL) == v13) )
  {
    *(_QWORD *)(v14 + 8) = v12;
    *v12 = v14;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  v15 = v1[2];
  v1[19] = 0xDEAD000000000100LL;
  v1[20] = 0xDEAD000000000122LL;
  result = ipc_log_context_destroy(v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
