__int64 __fastcall add_waiter(__int64 a1, int a2, _QWORD *a3)
{
  _QWORD *v6; // x22
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 result; // x0

  a3[15] = 0;
  a3[12] = 0;
  a3[13] = 0;
  a3[9] = 0;
  a3[10] = 0;
  a3[7] = 0;
  a3[8] = 0;
  a3[5] = 0;
  a3[6] = 0;
  a3[3] = 0;
  a3[4] = 0;
  a3[1] = 0;
  a3[2] = 0;
  *a3 = 0;
  a3[14] = 0;
  v6 = a3 + 14;
  a3[11] = 0;
  _init_swait_queue_head(a3 + 11, "&x->wait", &init_completion___key_0);
  raw_write_lock_irq(a1 + 4);
  v7 = a1 + 16;
  v8 = *(_QWORD **)(a1 + 24);
  if ( v6 == (_QWORD *)(a1 + 16) || v8 == v6 || *v8 != v7 )
  {
    _list_add_valid_or_report(v6, v8);
  }
  else
  {
    *(_QWORD *)(a1 + 24) = v6;
    a3[14] = v7;
    a3[15] = v8;
    *v8 = v6;
  }
  result = raw_write_unlock_irq(a1 + 4);
  *(_DWORD *)a3 = a2;
  return result;
}
