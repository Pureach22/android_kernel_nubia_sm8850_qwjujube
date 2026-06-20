__int64 __fastcall ieee80211_change_chanctx(__int64 a1, __int64 a2, __int64 a3, __int64 *a4, _QWORD *a5)
{
  unsigned int v5; // w8
  _QWORD *v7; // x21
  __int64 v8; // x27
  int v9; // w28
  int v10; // w23
  _QWORD *v11; // x25
  int v12; // w19
  int v13; // w26
  __int64 v16; // x8
  int v18; // w8
  _QWORD *v19; // x10
  _QWORD *v20; // x10
  int v21; // w8
  int v22; // w9
  _BOOL4 v23; // w9
  bool v24; // zf
  int v25; // w8
  int v26; // w26
  __int64 v27; // x9
  __int64 v28; // x11
  __int64 v29; // x12
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x11
  int v33; // w23
  _DWORD *v34; // x8
  int v35; // [xsp+Ch] [xbp-34h]
  int v36; // [xsp+10h] [xbp-30h]
  int v37; // [xsp+14h] [xbp-2Ch]
  int v38; // [xsp+18h] [xbp-28h]
  int v39; // [xsp+1Ch] [xbp-24h]
  __int64 v40; // [xsp+20h] [xbp-20h]
  int v41; // [xsp+2Ch] [xbp-14h]

  v5 = *((_DWORD *)a4 + 2);
  v7 = (_QWORD *)(a2 + 152);
  v8 = *(_QWORD *)(a2 + 152);
  v9 = *(_DWORD *)(a2 + 168);
  v10 = *(unsigned __int16 *)(a2 + 180);
  v41 = *(unsigned __int16 *)(a2 + 182);
  v11 = (_QWORD *)(a2 + 216);
  v13 = *(_DWORD *)(a2 + 160);
  v12 = *(_DWORD *)(a2 + 164);
  v40 = *(_QWORD *)(a2 + 216);
  v38 = *(_DWORD *)(a2 + 228);
  v39 = *(_DWORD *)(a2 + 224);
  v36 = *(_DWORD *)(a2 + 232);
  v37 = *(unsigned __int16 *)(a2 + 244);
  v35 = *(unsigned __int16 *)(a2 + 246);
  if ( v5 >= 6 && v5 != 13 )
    __break(0x800u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))ieee80211_chan_bw_change)(a1, a3, 0, 1);
  if ( v8 == *a4
    && v13 == *((_DWORD *)a4 + 2)
    && v12 == *((_DWORD *)a4 + 3)
    && v10 == *((unsigned __int16 *)a4 + 14)
    && v9 == *((_DWORD *)a4 + 4)
    && v41 == *((unsigned __int16 *)a4 + 15) )
  {
    v16 = a4[4];
    if ( !(v40 | v16)
      || v40 == v16
      && v39 == *((_DWORD *)a4 + 10)
      && v38 == *((_DWORD *)a4 + 11)
      && v37 == *((unsigned __int16 *)a4 + 30)
      && v36 == *((_DWORD *)a4 + 12)
      && v35 == *((unsigned __int16 *)a4 + 31) )
    {
      return ieee80211_recalc_chanctx_min_def(a1, a2);
    }
  }
  v18 = -2;
  v19 = (_QWORD *)(a2 + 32);
  do
  {
    v19 = (_QWORD *)*v19;
    ++v18;
  }
  while ( v19 != (_QWORD *)(a2 + 32) );
  v20 = (_QWORD *)(a2 + 48);
  do
  {
    v20 = (_QWORD *)*v20;
    ++v18;
  }
  while ( v20 != (_QWORD *)(a2 + 48) );
  if ( v18 >= 2 && !cfg80211_chandef_compatible(v7, a4) )
    __break(0x800u);
  ieee80211_remove_wbrf(a1, v7);
  v21 = *(_DWORD *)(a2 + 160);
  v22 = *((_DWORD *)a4 + 2);
  if ( *(_QWORD *)(a2 + 152) == *a4
    && v21 == v22
    && *(_DWORD *)(a2 + 164) == *((_DWORD *)a4 + 3)
    && *(unsigned __int16 *)(a2 + 180) == *((unsigned __int16 *)a4 + 14)
    && *(_DWORD *)(a2 + 168) == *((_DWORD *)a4 + 4)
    && *(unsigned __int16 *)(a2 + 182) == *((unsigned __int16 *)a4 + 15) )
  {
    v23 = 0;
  }
  else
  {
    v24 = v21 == v22;
    v23 = v21 != v22;
    if ( v24 )
      v25 = 64;
    else
      v25 = 65;
    if ( *(unsigned __int16 *)(a2 + 182) != *((unsigned __int16 *)a4 + 15) )
      v23 = v25;
  }
  if ( *v11 == a4[4]
    && *(_DWORD *)(a2 + 224) == *((_DWORD *)a4 + 10)
    && *(_DWORD *)(a2 + 228) == *((_DWORD *)a4 + 11)
    && *(unsigned __int16 *)(a2 + 244) == *((unsigned __int16 *)a4 + 30)
    && *(_DWORD *)(a2 + 232) == *((_DWORD *)a4 + 12) )
  {
    if ( *(unsigned __int16 *)(a2 + 246) == *((unsigned __int16 *)a4 + 31) )
      v26 = v23;
    else
      v26 = v23 | 0x20;
  }
  else
  {
    v26 = v23 | 0x20;
  }
  v27 = a4[3];
  v28 = *a4;
  v29 = a4[1];
  v7[2] = a4[2];
  v7[3] = v27;
  *v7 = v28;
  v7[1] = v29;
  v30 = a4[7];
  v32 = a4[4];
  v31 = a4[5];
  v11[2] = a4[6];
  v11[3] = v30;
  *v11 = v32;
  v11[1] = v31;
  v33 = ieee80211_recalc_chanctx_min_def(a1, a2, a5, 0);
  ieee80211_add_wbrf(a1, v7);
  v34 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 608LL);
  if ( v34 )
  {
    if ( (*(_BYTE *)(a2 + 84) & 1) == 0 )
    {
      __break(0x800u);
      v34 = *(_DWORD **)(*(_QWORD *)(a1 + 464) + 608LL);
    }
    if ( *(v34 - 1) != 1043050079 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v34)(a1, v7, v33 | (unsigned int)v26);
  }
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ieee80211_chan_bw_change)(a1, a3, 0, 0);
}
