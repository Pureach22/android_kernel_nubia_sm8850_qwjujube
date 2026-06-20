__int64 __fastcall qcrypto_aead_setauthsize(__int64 a1, int a2)
{
  *(_DWORD *)(a1 + 228) = a2;
  return 0;
}
