__int64 __fastcall sha1_hmac_init(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x12
  __int64 v4; // x10
  __int64 v5; // x9

  v1 = *(_QWORD *)(a1 + 32);
  v2 = *(_QWORD *)(v1 + 56);
  ++qword_11A80;
  *(_QWORD *)(a1 + 226) = 0;
  *(_WORD *)(a1 + 224) = 1;
  *(_DWORD *)(a1 + 292) = 0;
  *(_DWORD *)(a1 + 472) = -253635901;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 464) = 0x76543210FEDCBA98LL;
  *(_QWORD *)(a1 + 234) = 0;
  *(_QWORD *)(a1 + 242) = 0;
  *(_QWORD *)(a1 + 250) = 0;
  *(_QWORD *)(a1 + 258) = 0;
  *(_QWORD *)(a1 + 266) = 0;
  *(_QWORD *)(a1 + 274) = 0;
  *(_QWORD *)(a1 + 282) = 0;
  *(_QWORD *)(a1 + 456) = 0x89ABCDEF01234567LL;
  *(_DWORD *)(v1 + 72) = 20;
  if ( *(_BYTE *)(v2 + 19) == 1 )
  {
    *(_DWORD *)(v1 + 68) = 2;
    return 0;
  }
  else
  {
    *(_DWORD *)(v1 + 68) = 0;
    v4 = 0;
    v5 = *(_QWORD *)(a1 + 32) + 80LL;
    do
    {
      *(_BYTE *)(a1 + 226 + v4) = *(_BYTE *)(v5 + v4) ^ 0x36;
      ++v4;
    }
    while ( v4 != 64 );
    *(_DWORD *)(a1 + 292) = 64;
    return 0;
  }
}
