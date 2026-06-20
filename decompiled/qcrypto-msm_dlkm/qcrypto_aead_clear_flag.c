__int64 __fastcall qcrypto_aead_clear_flag(__int64 a1, int a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 32);
  *(_DWORD *)(v2 + 64) &= ~a2;
  return 0;
}
