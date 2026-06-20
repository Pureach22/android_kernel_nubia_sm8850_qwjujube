__int64 __fastcall drm_dsc_pps_payload_pack(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  unsigned __int8 *v4; // x10
  int v5; // w11
  int v6; // t1

  *(_QWORD *)(result + 112) = 0;
  *(_QWORD *)(result + 120) = 0;
  v2 = 0;
  *(_QWORD *)(result + 96) = 0;
  *(_QWORD *)(result + 104) = 0;
  *(_QWORD *)(result + 80) = 0;
  *(_QWORD *)(result + 88) = 0;
  *(_QWORD *)(result + 64) = 0;
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 48) = 0;
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 32) = 0;
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 16) = 0;
  *(_QWORD *)(result + 24) = 0;
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 8) = 0;
  *(_BYTE *)result = *(_BYTE *)(a2 + 126) | (16 * *(_BYTE *)(a2 + 127));
  *(_BYTE *)(result + 3) = *(_BYTE *)a2 | (16 * *(_BYTE *)(a2 + 1));
  *(_BYTE *)(result + 4) = *(_BYTE *)(a2 + 17) & 3
                         | (4 * *(_BYTE *)(a2 + 120))
                         | (8 * *(_BYTE *)(a2 + 8))
                         | (16 * *(_BYTE *)(a2 + 2))
                         | (32 * *(_BYTE *)(a2 + 26));
  *(_BYTE *)(result + 5) = *(_BYTE *)(a2 + 16);
  *(_WORD *)(result + 6) = bswap32(*(unsigned __int16 *)(a2 + 12)) >> 16;
  *(_WORD *)(result + 8) = bswap32(*(unsigned __int16 *)(a2 + 10)) >> 16;
  *(_WORD *)(result + 10) = bswap32(*(unsigned __int16 *)(a2 + 6)) >> 16;
  *(_WORD *)(result + 12) = bswap32(*(unsigned __int16 *)(a2 + 4)) >> 16;
  *(_WORD *)(result + 14) = bswap32(*(unsigned __int16 *)(a2 + 122)) >> 16;
  *(_BYTE *)(result + 16) = *(_BYTE *)(a2 + 23) & 3;
  *(_BYTE *)(result + 17) = *(_BYTE *)(a2 + 22);
  *(_WORD *)(result + 18) = bswap32(*(unsigned __int16 *)(a2 + 24)) >> 16;
  *(_BYTE *)(result + 21) = *(_BYTE *)(a2 + 108);
  *(_WORD *)(result + 22) = bswap32(*(unsigned __int16 *)(a2 + 112)) >> 16;
  *(_BYTE *)(result + 24) = *(_BYTE *)(a2 + 111) & 0xF;
  *(_BYTE *)(result + 25) = *(_BYTE *)(a2 + 110);
  *(_BYTE *)(result + 27) = *(_BYTE *)(a2 + 27);
  *(_WORD *)(result + 28) = bswap32(*(unsigned __int16 *)(a2 + 114)) >> 16;
  *(_WORD *)(result + 30) = bswap32(*(unsigned __int16 *)(a2 + 116)) >> 16;
  *(_WORD *)(result + 32) = bswap32(*(unsigned __int16 *)(a2 + 28)) >> 16;
  *(_WORD *)(result + 34) = bswap32(*(unsigned __int16 *)(a2 + 118)) >> 16;
  *(_BYTE *)(result + 36) = *(_BYTE *)(a2 + 106);
  *(_BYTE *)(result + 37) = *(_BYTE *)(a2 + 107);
  v3 = *(unsigned __int16 *)(a2 + 104);
  *(_BYTE *)(result + 40) = 6;
  *(_WORD *)(result + 38) = bswap32(v3) >> 16;
  *(_BYTE *)(result + 41) = *(_BYTE *)(a2 + 20);
  LOBYTE(v3) = *(_BYTE *)(a2 + 19);
  *(_BYTE *)(result + 43) = 51;
  v4 = (unsigned __int8 *)(a2 + 60);
  *(_BYTE *)(result + 42) = v3;
  *(_BYTE *)(result + 44) = *(_BYTE *)(a2 + 30);
  *(_BYTE *)(result + 45) = *(_BYTE *)(a2 + 32);
  *(_BYTE *)(result + 46) = *(_BYTE *)(a2 + 34);
  *(_BYTE *)(result + 47) = *(_BYTE *)(a2 + 36);
  *(_BYTE *)(result + 48) = *(_BYTE *)(a2 + 38);
  *(_BYTE *)(result + 49) = *(_BYTE *)(a2 + 40);
  *(_BYTE *)(result + 50) = *(_BYTE *)(a2 + 42);
  *(_BYTE *)(result + 51) = *(_BYTE *)(a2 + 44);
  *(_BYTE *)(result + 52) = *(_BYTE *)(a2 + 46);
  *(_BYTE *)(result + 53) = *(_BYTE *)(a2 + 48);
  *(_BYTE *)(result + 54) = *(_BYTE *)(a2 + 50);
  *(_BYTE *)(result + 55) = *(_BYTE *)(a2 + 52);
  *(_BYTE *)(result + 56) = *(_BYTE *)(a2 + 54);
  *(_BYTE *)(result + 57) = *(_BYTE *)(a2 + 56);
  do
  {
    v5 = (*(v4 - 1) << 6) | (*(v4 - 2) << 11);
    v6 = *v4;
    v4 += 3;
    *(_WORD *)(result + 58 + v2) = bswap32(v5 | v6) >> 16;
    v2 += 2;
  }
  while ( v2 != 30 );
  *(_BYTE *)(result + 88) = *(_BYTE *)(a2 + 128) | (2 * *(_BYTE *)(a2 + 129));
  *(_BYTE *)(result + 89) = *(_BYTE *)(a2 + 130);
  *(_WORD *)(result + 90) = bswap32(*(unsigned __int16 *)(a2 + 132)) >> 16;
  *(_WORD *)(result + 92) = bswap32(*(unsigned __int16 *)(a2 + 134)) >> 16;
  return result;
}
