__int64 __fastcall comp_request_submit(_QWORD *a1)
{
  int v2; // w21
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 v5; // x9
  __int64 v6; // x10
  void *v7; // x2

  mutex_lock(&unk_3F0);
  v2 = zram_req_queue(a1);
  mutex_unlock(&unk_3F0);
  if ( v2 )
  {
    v3 = (_QWORD *)_kmalloc_cache_noprof(mutex_lock, 3328, 48);
    v4 = v3;
    if ( !v3 )
    {
      printk(&unk_B3A6);
      return 4294967284LL;
    }
    v5 = a1[1];
    v3[2] = *a1;
    v3[3] = v5;
    v6 = a1[3];
    v3[4] = a1[2];
    v3[5] = v6;
    mutex_lock(&unk_430);
    v7 = off_420;
    if ( off_420 == (_UNKNOWN *)v4 || v4 == &off_420 || *((_UNKNOWN ***)off_420 + 1) != &off_420 )
    {
      _list_add_valid_or_report(v4, &off_420);
    }
    else
    {
      *((_QWORD *)off_420 + 1) = v4;
      *v4 = v7;
      v4[1] = &off_420;
      off_420 = v4;
    }
    ++dword_460;
    mutex_unlock(&unk_430);
  }
  return 0;
}
