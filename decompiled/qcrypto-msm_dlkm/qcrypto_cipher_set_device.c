__int64 __fastcall qcrypto_cipher_set_device(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 *v6; // x21
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 64);
  v4 = *(_QWORD *)(v2 + 56);
  v5 = raw_spin_lock_irqsave(v4 + 52);
  v6 = (__int64 *)(v4 + 112);
  do
    v6 = (__int64 *)*v6;
  while ( v6 != (__int64 *)(v4 + 112) && *((_DWORD *)v6 + 25) != a2 );
  raw_spin_unlock_irqrestore(v4 + 52, v5);
  if ( v6 && *((_DWORD *)v6 + 25) == a2 )
  {
    result = 0;
    *(_QWORD *)(v2 + 48) = v6;
  }
  else
  {
    printk(&unk_11BED, a2);
    return 4294967277LL;
  }
  return result;
}
