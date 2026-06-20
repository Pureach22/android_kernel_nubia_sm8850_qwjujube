__int64 __fastcall ieee80211_color_change(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x20
  __int64 *v4; // x19
  _BYTE *v5; // x22
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v10; // x0
  unsigned int v11; // w8
  __int64 v12; // x2
  __int64 v13; // x21
  __int64 v14; // x8
  unsigned int v15; // w20
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a3 + 362);
  v16 = 0;
  if ( v3 >= 0xF )
  {
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_9;
  }
  v4 = *(__int64 **)(a2 + 8 * v3 + 7256);
  if ( !v4 )
  {
    result = 4294967229LL;
    goto LABEL_9;
  }
  v5 = (_BYTE *)v4[118];
  if ( (v5[304] & 1) != 0 )
  {
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (v5[840] & 1) != 0 || (v5[830] & 1) != 0 )
  {
    result = 4294967280LL;
    goto LABEL_9;
  }
  v7 = *v4;
  v18 = 0;
  if ( *(_DWORD *)(v7 + 4720) != 3 )
  {
    result = 4294967201LL;
    goto LABEL_9;
  }
  v10 = cfg80211_beacon_dup(a3 + 184);
  v4[71] = v10;
  if ( !v10 )
  {
    result = 4294967284LL;
    goto LABEL_9;
  }
  v11 = *(unsigned __int8 *)(a3 + 360);
  v12 = a3;
  if ( v11 < 2 )
  {
    v13 = 0;
LABEL_18:
    v5[840] = 1;
    v5[841] = *(_BYTE *)(v12 + 361);
    cfg80211_bss_color_notify(*(_QWORD *)(a2 + 4296), 143, *(unsigned __int8 *)(v12 + 360), 0, (unsigned int)v3);
    if ( v13 )
      ieee80211_color_change_bss_config_notify(v4, 0, 0, v13);
    else
      ieee80211_color_change_finalize(v4);
    result = 0;
    goto LABEL_9;
  }
  v17 = *(_DWORD *)(a3 + 176);
  LOBYTE(v18) = v11;
  result = ieee80211_assign_beacon(v7, v4, a3, 0, &v17, &v16);
  if ( (result & 0x80000000) == 0 )
  {
    v13 = v16;
    v12 = a3;
    goto LABEL_18;
  }
  v14 = v4[71];
  if ( v14 )
  {
    v15 = result;
    kfree(*(_QWORD *)(v14 + 72));
    kfree(*(_QWORD *)(v4[71] + 80));
    kfree(v4[71]);
    result = v15;
    v4[71] = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
