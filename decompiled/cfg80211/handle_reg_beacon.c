__int64 __fastcall handle_reg_beacon(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  int v11; // w8
  __int64 (*v12)(void); // x8
  __int64 v13; // [xsp+0h] [xbp-50h]
  _QWORD v14[9]; // [xsp+8h] [xbp-48h] BYREF

  v14[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a3 + 16);
  if ( (unsigned int)v3 >= 6 )
    __break(0x5512u);
  v4 = **(_QWORD **)(result + 8 * v3 + 328) + ((unsigned __int64)a2 << 6);
  if ( *(_DWORD *)(v4 + 4) == *(_DWORD *)(a3 + 20)
    && *(unsigned __int16 *)(v4 + 8) == *(unsigned __int16 *)(a3 + 24)
    && (*(_BYTE *)(v4 + 28) & 1) == 0 )
  {
    v13 = result;
    *(_BYTE *)(v4 + 28) = 1;
    result = reg_is_world_roaming();
    if ( (result & 1) != 0 && (*(_BYTE *)(v13 + 104) & 4) == 0 )
    {
      v5 = *(_QWORD *)(v4 + 24);
      v6 = *(_QWORD *)v4;
      v7 = *(_QWORD *)(v4 + 8);
      v14[2] = *(_QWORD *)(v4 + 16);
      v14[3] = v5;
      v14[0] = v6;
      v14[1] = v7;
      v8 = *(_QWORD *)(v4 + 56);
      v9 = *(_QWORD *)(v4 + 32);
      v10 = *(_QWORD *)(v4 + 40);
      v14[6] = *(_QWORD *)(v4 + 48);
      v14[7] = v8;
      v14[4] = v9;
      v14[5] = v10;
      v11 = *(_DWORD *)(v4 + 12);
      if ( (v11 & 2) != 0 )
      {
        *(_DWORD *)(v4 + 12) = v11 & 0xFFFFFFFD;
        nl80211_send_beacon_hint_event(v13, (__int64)v14, v4);
        result = v13;
        if ( (*(_BYTE *)(v13 + 103) & 2) != 0 )
        {
          v12 = *(__int64 (**)(void))(v13 + 376);
          if ( v12 )
          {
            if ( *((_DWORD *)v12 - 1) != -1916906463 )
              __break(0x8228u);
            result = v12();
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
