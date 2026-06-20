__int64 __fastcall qcedev_sha_init(__int64 result, __int64 a2)
{
  int v2; // w8
  int v3; // w8

  *(_DWORD *)(a2 + 192) = 0;
  *(_QWORD *)(a2 + 176) = 0;
  *(_QWORD *)(a2 + 184) = 0;
  *(_QWORD *)(a2 + 160) = 0;
  *(_QWORD *)(a2 + 168) = 0;
  *(_QWORD *)(a2 + 144) = 0;
  *(_QWORD *)(a2 + 152) = 0;
  *(_QWORD *)(a2 + 128) = 0;
  *(_QWORD *)(a2 + 136) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 120) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 128) = 1;
  v2 = *(_DWORD *)(result + 372);
  if ( v2 <= 1 )
  {
    if ( v2 )
    {
      if ( v2 != 1 )
        goto LABEL_10;
      goto LABEL_8;
    }
    goto LABEL_7;
  }
  if ( v2 == 3 )
  {
LABEL_8:
    *(_QWORD *)(a2 + 24) = 0x85AE67BB67E6096ALL;
    *(_QWORD *)(a2 + 32) = 0x3AF54FA572F36E3CLL;
    v3 = 32;
    *(_QWORD *)(a2 + 40) = 0x8C68059B7F520E51LL;
    *(_QWORD *)(a2 + 48) = 0x19CDE05BABD9831FLL;
    goto LABEL_9;
  }
  if ( v2 == 2 )
  {
LABEL_7:
    *(_DWORD *)(a2 + 40) = -253635901;
    v3 = 20;
    *(_QWORD *)(a2 + 24) = 0x89ABCDEF01234567LL;
    *(_QWORD *)(a2 + 32) = 0x76543210FEDCBA98LL;
LABEL_9:
    *(_DWORD *)(a2 + 56) = v3;
  }
LABEL_10:
  *(_BYTE *)(a2 + 194) = 1;
  return result;
}
