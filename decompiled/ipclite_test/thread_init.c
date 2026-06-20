__int64 __fastcall thread_init(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x20
  __int64 result; // x0

  *(_BYTE *)(a1 + 112) = 0;
  _init_waitqueue_head(a1 + 88, "&th_data->wq", &thread_init___key);
  v4 = kthread_create_on_node(a2, a1, 0xFFFFFFFFLL, "test thread");
  v5 = v4;
  if ( v4 > 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)a1 = v4;
    printk(&unk_AA01, "ipclite_test", "thread_init");
    return 4294967274LL;
  }
  else
  {
    wake_up_process(v4);
    result = 0;
    *(_QWORD *)a1 = v5;
  }
  return result;
}
