__int64 __fastcall release_tx_buffers(__int64 a1)
{
  __int64 v1; // x23
  __int64 *v3; // x20
  __int64 v4; // x8
  __int64 *v5; // x27
  __int64 **v6; // x8
  __int64 *v7; // x9
  _QWORD *v8; // x8
  __int64 *v9; // x9
  __int64 v10; // x10
  __int64 result; // x0
  __int64 v12; // x8

  v1 = *(_QWORD *)(a1 + 136);
  if ( !v1 )
    return printk(&unk_22DBB3, "_release_tx_buffers");
  mutex_lock(v1 + 16);
  v3 = *(__int64 **)(a1 + 128);
  if ( v3 != (__int64 *)(a1 + 120) )
  {
    do
    {
      v4 = v3[5];
      v5 = (__int64 *)v3[1];
      if ( v4 )
      {
        if ( v3 == (__int64 *)&unk_68 )
        {
          printk(&unk_245CB0, "_hfi_clear_buffer");
        }
        else
        {
          *((_DWORD *)v3 - 14) = 0;
          *(v3 - 6) = 0;
          *(_DWORD *)(v4 + 64) = 1;
          *((_DWORD *)v3 + 12) = 0;
        }
      }
      v6 = (__int64 **)v3[1];
      if ( *v6 == v3 && (v7 = (__int64 *)*v3, *(__int64 **)(*v3 + 8) == v3) )
      {
        v7[1] = (__int64)v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      v3 = v5;
    }
    while ( v5 != (__int64 *)(a1 + 120) );
  }
  v8 = *(_QWORD **)(a1 + 112);
  v9 = (__int64 *)(a1 + 104);
  if ( *v8 == a1 + 104 && (v10 = *v9, *(__int64 **)(*v9 + 8) == v9) )
  {
    *(_QWORD *)(v10 + 8) = v8;
    *v8 = v10;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 104);
  }
  *(_QWORD *)(a1 + 104) = a1 + 104;
  *(_QWORD *)(a1 + 112) = v9;
  result = mutex_unlock(v1 + 16);
  if ( !a1 )
    return printk(&unk_245CB0, "_hfi_clear_buffer");
  v12 = *(_QWORD *)(a1 + 144);
  if ( !v12 )
    return printk(&unk_2686DF, "_hfi_clear_buffer");
  *(_DWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_DWORD *)(v12 + 64) = 1;
  *(_DWORD *)(a1 + 152) = 0;
  return result;
}
