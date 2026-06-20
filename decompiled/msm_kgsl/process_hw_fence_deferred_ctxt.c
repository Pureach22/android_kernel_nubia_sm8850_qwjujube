__int64 __fastcall process_hw_fence_deferred_ctxt(__int64 a1, _QWORD *a2, unsigned int a3)
{
  _QWORD *v6; // x23
  _QWORD **v7; // x25
  unsigned int v8; // w26
  _QWORD *v9; // x22
  unsigned int v10; // w8
  unsigned int v11; // w8
  bool v12; // cf
  unsigned int v13; // w8
  char v14; // w0
  char v15; // w28
  __int64 v16; // x2
  __int64 result; // x0
  _QWORD *v18; // x8
  __int64 v19; // x9
  _QWORD *v20; // x1

  raw_spin_lock((char *)a2 + 404);
  v6 = (_QWORD *)a2[257];
  v7 = (_QWORD **)(a2 + 257);
  if ( v6 != a2 + 257 )
  {
    v8 = a3 ^ 0x80000000;
    v9 = a2 + 259;
    do
    {
      v10 = *((_DWORD *)v6 - 10);
      if ( v10 != a3 )
      {
        if ( v10 > a3 && ((v10 - a3) & 0x80000000) == 0 )
          break;
        v11 = v10 ^ 0x80000000;
        v12 = v11 >= v8;
        v13 = v11 - v8;
        if ( v13 != 0 && v12 && v13 <= 0x80000000 )
          break;
      }
      raw_spin_unlock((char *)a2 + 404);
      if ( v6 == (_QWORD *)&_crc_kgsl_del_rcu_notifier )
        return 0;
      v14 = kgsl_check_timestamp(a1, a2, a3);
      if ( !a2 || (v14 & 1) != 0 || (a2[4] & 2) != 0 || (a2[4] & 4) != 0 )
      {
        v15 = 1;
        v16 = 1;
      }
      else
      {
        v15 = 0;
        v16 = 0;
      }
      result = gen7_send_hw_fence_hfi_wait_ack(a1, (__int64)(v6 - 8), v16);
      if ( (_DWORD)result )
        return result;
      raw_spin_lock((char *)a2 + 404);
      if ( (v15 & 1) != 0 )
      {
        adreno_hwsched_remove_hw_fence_entry(a1, v6 - 8);
      }
      else
      {
        v18 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v18 == v6 && (v19 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
        {
          *(_QWORD *)(v19 + 8) = v18;
          *v18 = v19;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        v20 = (_QWORD *)a2[260];
        if ( v6 == v9 || v20 == v6 || (_QWORD *)*v20 != v9 )
        {
          _list_add_valid_or_report(v6, v20);
        }
        else
        {
          a2[260] = v6;
          *v6 = v9;
          v6[1] = v20;
          *v20 = v6;
        }
      }
      raw_spin_unlock((char *)a2 + 404);
      raw_spin_lock((char *)a2 + 404);
      v6 = *v7;
    }
    while ( *v7 != v7 );
  }
  raw_spin_unlock((char *)a2 + 404);
  return 0;
}
