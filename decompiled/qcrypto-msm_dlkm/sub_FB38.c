__int64 __fastcall sub_FB38(int a1, int a2, size_t a3)
{
  __int64 v3; // x16
  char v4; // b22

  *(_BYTE *)(v3 + 2726) = v4;
  return sha256_hmac_setkey(a1, a2, a3);
}
