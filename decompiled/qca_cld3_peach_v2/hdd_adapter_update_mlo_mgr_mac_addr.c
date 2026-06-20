__int64 __fastcall hdd_adapter_update_mlo_mgr_mac_addr(__int64 result)
{
  char v1; // w9
  int v2; // w9
  int v3; // w11
  __int16 v4; // w9
  int v5; // w11
  __int16 v6; // w10
  int v7; // w11
  __int16 v8; // w10
  __int64 v9; // x8
  int v10; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int128 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(result + 52800);
  v12 = 0u;
  v11 = 0;
  if ( (v1 & 1) != 0 )
  {
    v2 = 0;
    if ( result && result != -52840 )
    {
      v3 = *(_DWORD *)(result + 52912);
      v4 = *(_WORD *)(result + 52916);
      LOBYTE(v11) = *(_BYTE *)(result + 52848);
      *(_DWORD *)((char *)&v11 + 1) = v3;
      *(_WORD *)((char *)&v11 + 5) = v4;
      if ( result == -58928 )
      {
        v2 = 1;
      }
      else
      {
        v5 = *(_DWORD *)(result + 59000);
        v6 = *(_WORD *)(result + 59004);
        HIBYTE(v11) = *(_BYTE *)(result + 58936);
        LODWORD(v12) = v5;
        WORD2(v12) = v6;
        if ( result == -65016 )
        {
          v2 = 2;
        }
        else
        {
          v7 = *(_DWORD *)(result + 65088);
          v8 = *(_WORD *)(result + 65092);
          BYTE6(v12) = *(_BYTE *)(result + 65024);
          v2 = 3;
          *(_DWORD *)((char *)&v12 + 7) = v7;
          *(_WORD *)((char *)&v12 + 11) = v8;
        }
      }
    }
    v9 = *(_QWORD *)(result + 52832);
    v10 = v2;
    result = mlo_mgr_update_link_info_mac_addr(*(_QWORD *)(v9 + 32), &v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
