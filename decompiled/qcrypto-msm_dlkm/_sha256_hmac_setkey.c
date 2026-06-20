__int64 __fastcall sha256_hmac_setkey(__int64 a1, const void *a2, size_t n)
{
  _QWORD *v4; // x0
  int v5; // w20
  int v6; // w8
  __int64 result; // x0
  __int64 v8; // x1
  unsigned int v9; // w20

  *(_QWORD *)(a1 + 96) = 0;
  v4 = (_QWORD *)(a1 + 96);
  v4[6] = 0;
  v4[7] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v4[1] = 0;
  if ( (unsigned int)n > 0x40 )
  {
    *(_QWORD *)(a1 + 84) = 0x2000000001LL;
    result = sha_hmac_setkey(a1);
    if ( (_DWORD)result )
    {
      v9 = result;
      printk(&unk_1256B, v8);
      result = v9;
    }
    v6 = 64;
  }
  else
  {
    v5 = n;
    memcpy(v4, a2, (unsigned int)n);
    v6 = v5;
    result = 0;
  }
  *(_DWORD *)(a1 + 92) = v6;
  return result;
}
