__int64 __fastcall qcrypto_cra_aead_rfc4309_ccm_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)(a1 + 4) = 456;
  if ( v2 == 1032 )
  {
    printk(&unk_122E0, a2);
    result = 4294967274LL;
  }
  else
  {
    *(_DWORD *)(a1 + 72) = 0;
    *(_QWORD *)(a1 + 64) = *(_QWORD *)(v2 + 392);
    get_random_bytes(a1 + 144, 16);
    result = 0;
    *(_QWORD *)(a1 + 56) = 0;
    *(_QWORD *)(a1 + 40) = a1 + 40;
    *(_QWORD *)(a1 + 48) = a1 + 40;
  }
  *(_DWORD *)(a1 + 76) = 4;
  return result;
}
