__int64 __fastcall notifier_vm_cb(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  if ( a2 == 3 && a3 )
    mem_buf_relinquish_all_mem(*a3);
  return 0;
}
