__int64 __fastcall qmi_txn_init(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4)
{
  unsigned int v8; // w0
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned int v11; // w20
  unsigned int v13; // w21

  a2[7] = 0;
  a2[8] = 0;
  a2[5] = 0;
  a2[6] = 0;
  a2[4] = 0;
  a2[1] = 0;
  a2[2] = 0;
  *a2 = 0;
  a2[3] = 0;
  _init_swait_queue_head(a2 + 3, "&x->wait", &init_completion___key);
  *a2 = a1;
  a2[7] = a3;
  a2[8] = a4;
  mutex_lock(a1 + 248);
  v8 = idr_alloc_cyclic(a1 + 224, a2, 0, 0xFFFF, 3264);
  if ( (v8 & 0x80000000) != 0 )
  {
    v13 = v8;
    printk(&unk_85AD, v9, v10);
    v8 = v13;
  }
  *((_WORD *)a2 + 4) = v8;
  v11 = v8;
  mutex_unlock(a1 + 248);
  return v11;
}
