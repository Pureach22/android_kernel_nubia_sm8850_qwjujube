__int64 __fastcall qcrypto_cipher_set_device_hw(__int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x21
  __int64 v6; // x23
  __int64 v7; // x1
  __int64 *i; // x22
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 64);
  v6 = *(_QWORD *)(v3 + 56);
  v7 = raw_spin_lock_irqsave(v6 + 52);
  for ( i = *(__int64 **)(v6 + 112); i != (__int64 *)(v6 + 112); i = (__int64 *)*i )
  {
    if ( *((_DWORD *)i + 25) == a2 && *((_DWORD *)i + 26) == a3 )
      break;
  }
  raw_spin_unlock_irqrestore(v6 + 52, v7);
  if ( i && *((_DWORD *)i + 25) == a2 && *((_DWORD *)i + 26) == a3 )
  {
    result = 0;
    *(_QWORD *)(v3 + 48) = i;
  }
  else
  {
    printk(&unk_11BED, a2);
    return 4294967277LL;
  }
  return result;
}
