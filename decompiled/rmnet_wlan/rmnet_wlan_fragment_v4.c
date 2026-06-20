__int64 __fastcall rmnet_wlan_fragment_v4(__int64 a1, __int16 a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w10
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x9
  int v9; // [xsp+Ch] [xbp-34h]
  __int64 v10; // [xsp+10h] [xbp-30h]
  __int64 v11; // [xsp+18h] [xbp-28h]
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -1;
  v4 = *(unsigned __int8 *)(a3 + 5);
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  if ( v4 <= 0x32 && ((1LL << v4) & 0x4000000020040LL) != 0 )
  {
    v5 = *(_QWORD *)(a1 + 216);
    v6 = *(unsigned __int16 *)(a1 + 184);
    BYTE4(v14) = 4;
    v7 = v5 + v6;
    v9 = *(_DWORD *)(v7 + 12);
    HIDWORD(v11) = *(_DWORD *)(v7 + 16);
    HIDWORD(v13) = *(unsigned __int16 *)(v7 + 4) << 16;
    LODWORD(v7) = *(unsigned __int16 *)(v7 + 6);
    LOWORD(v14) = a2;
    WORD1(v14) = bswap32(v7 & 0xFFFFFF1F) >> 16;
    v3 = rmnet_wlan_fragment_handle();
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
