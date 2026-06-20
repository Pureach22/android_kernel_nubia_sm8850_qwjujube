__int64 ipclite_hw_mutex_acquire()
{
  __int64 result; // x0
  unsigned int v1; // w19

  if ( ipclite )
  {
    result = _hwspin_lock_timeout(*(_QWORD *)(ipclite + 6456), 1000, 1, ipclite + 6464);
    if ( (_DWORD)result )
    {
      v1 = result;
      printk(&unk_EAD6, "ipclite", "ipclite_hw_mutex_acquire");
      return v1;
    }
    else
    {
      **(_DWORD **)(ipclite + 6352) = 0;
    }
  }
  else
  {
    printk(&unk_F98D, "ipclite", "ipclite_hw_mutex_acquire");
    return 4294967284LL;
  }
  return result;
}
