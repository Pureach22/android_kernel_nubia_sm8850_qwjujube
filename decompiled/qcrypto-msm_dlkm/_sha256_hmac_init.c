__int64 __fastcall sha256_hmac_init(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x12
  __int64 v4; // x11
  __int64 v5; // x9

  v1 = *(_QWORD *)(a1 + 32);
  v2 = *(_QWORD *)(v1 + 56);
  ++qword_11A88;
  *(_QWORD *)(a1 + 226) = 0;
  *(_QWORD *)(a1 + 480) = 0x19CDE05BABD9831FLL;
  *(_WORD *)(a1 + 224) = 1;
  *(_DWORD *)(a1 + 292) = 0;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 234) = 0;
  *(_QWORD *)(a1 + 242) = 0;
  *(_QWORD *)(a1 + 250) = 0;
  *(_QWORD *)(a1 + 258) = 0;
  *(_QWORD *)(a1 + 266) = 0;
  *(_QWORD *)(a1 + 274) = 0;
  *(_QWORD *)(a1 + 282) = 0;
  *(_QWORD *)(a1 + 472) = 0x8C68059B7F520E51LL;
  *(_QWORD *)(a1 + 464) = 0x3AF54FA572F36E3CLL;
  *(_QWORD *)(a1 + 456) = 0x85AE67BB67E6096ALL;
  *(_DWORD *)(v1 + 72) = 32;
  if ( *(_BYTE *)(v2 + 19) == 1 )
  {
    *(_DWORD *)(v1 + 68) = 3;
    return 0;
  }
  else
  {
    *(_DWORD *)(v1 + 68) = 1;
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
