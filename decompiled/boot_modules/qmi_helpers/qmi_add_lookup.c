__int64 __fastcall qmi_add_lookup(__int64 a1, int a2, int a3, int a4)
{
  _DWORD *v8; // x0
  _DWORD *v9; // x9
  _QWORD *v10; // x0
  _QWORD *v11; // x1
  _QWORD *v12; // x2

  v8 = (_DWORD *)_kmalloc_cache_noprof(_init_swait_queue_head, 3520, 48);
  v9 = v8;
  if ( !v8 )
    return 4294967284LL;
  *v8 = a2;
  v8[1] = a3;
  v10 = v8 + 8;
  v11 = (_QWORD *)(a1 + 128);
  v12 = *(_QWORD **)(a1 + 128);
  v9[2] = a4;
  if ( v12[1] != a1 + 128 || v10 == v11 || v12 == v10 )
  {
    _list_add_valid_or_report(v10);
  }
  else
  {
    v12[1] = v10;
    *((_QWORD *)v9 + 4) = v12;
    *((_QWORD *)v9 + 5) = v11;
    *v11 = v10;
  }
  qmi_send_new_lookup(a1, v9);
  return 0;
}
