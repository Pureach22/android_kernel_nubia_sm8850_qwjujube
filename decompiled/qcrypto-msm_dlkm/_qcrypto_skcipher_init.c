__int64 __fastcall qcrypto_skcipher_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x20
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)a1 = 456;
  if ( v2 == 104 )
  {
    printk(&unk_122E0, a2);
    return 4294967274LL;
  }
  else
  {
    *(_DWORD *)(a1 + 72) = 0;
    v4 = a1 + 40;
    *(_QWORD *)(a1 + 64) = *(_QWORD *)(v2 + 1320);
    get_random_bytes(a1 + 144, 16);
    result = 0;
    *(_QWORD *)(a1 + 56) = 0;
    *(_QWORD *)(a1 + 40) = v4;
    *(_QWORD *)(a1 + 48) = v4;
    *(_DWORD *)(a1 + 76) = 5;
  }
  return result;
}
