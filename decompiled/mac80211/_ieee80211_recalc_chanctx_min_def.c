__int64 __fastcall ieee80211_recalc_chanctx_min_def(__int64 a1, __int64 a2, _QWORD *a3, char a4)
{
  _QWORD *v5; // x23
  __int64 v6; // x9
  __int64 result; // x0
  __int64 v8; // x10
  _QWORD *v11; // x25
  _QWORD *v12; // x28
  unsigned int v13; // w24
  __int64 v14; // x20
  unsigned int max_required_bw; // w8
  _QWORD *v16; // x0
  int v17; // w9
  int v18; // w9
  _QWORD *v19; // x27
  unsigned int v20; // w28
  unsigned int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x10
  int v26; // w12
  __int64 v27; // x9
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 i; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v5 = (_QWORD *)(a2 + 152);
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(*(_DWORD *)(a2 + 160) - 6) < 7 || *(_BYTE *)(a2 + 254) == 1 )
  {
    v6 = *(_QWORD *)(a2 + 160);
    result = 0;
    *(_QWORD *)(a2 + 184) = *v5;
    *(_QWORD *)(a2 + 192) = v6;
    v8 = *(_QWORD *)(a2 + 176);
    *(_QWORD *)(a2 + 200) = *(_QWORD *)(a2 + 168);
    *(_QWORD *)(a2 + 208) = v8;
    goto LABEL_55;
  }
  if ( a3 && (a4 & 1) != 0 )
  {
    __break(0x800u);
    v13 = *(_DWORD *)(a2 + 160);
  }
  else
  {
    v11 = *(_QWORD **)(a1 + 4616);
    v12 = (_QWORD *)(a1 + 4616);
    if ( v11 != (_QWORD *)(a1 + 4616) )
    {
      v13 = 0;
      while ( (v11[204] & 1) == 0 )
      {
LABEL_8:
        v11 = (_QWORD *)*v11;
        if ( v11 == v12 )
          goto LABEL_38;
      }
      v14 = 0;
      while ( 1 )
      {
        v16 = (_QWORD *)v11[v14 + 571];
        if ( v16 )
        {
          if ( (a4 & 1) != 0 )
          {
            if ( v16[46] != a2 )
              goto LABEL_14;
          }
          else if ( v16 != a3 && *(_QWORD **)(v16[118] + 832LL) != v5 )
          {
            goto LABEL_14;
          }
          v17 = *(_DWORD *)(*v16 + 4720LL);
          max_required_bw = 0;
          if ( v17 <= 4 )
          {
            if ( v17 > 2 )
            {
              max_required_bw = ieee80211_get_max_required_bw();
            }
            else if ( v17 )
            {
              if ( v17 == 1 )
              {
LABEL_35:
                max_required_bw = *(_DWORD *)(v16[118] + 144LL);
              }
              else if ( v17 == 2 )
              {
                v19 = v12;
                v20 = *(_DWORD *)(v16[118] + 144LL);
                v21 = ieee80211_get_max_required_bw();
                if ( v20 <= v21 )
                  max_required_bw = v21;
                else
                  max_required_bw = v20;
                v12 = v19;
              }
            }
            else
            {
LABEL_11:
              max_required_bw = 0;
              __break(0x800u);
            }
LABEL_12:
            if ( v13 <= max_required_bw )
              v13 = max_required_bw;
            goto LABEL_14;
          }
          if ( (unsigned int)v17 > 0xD )
            goto LABEL_12;
          v18 = 1 << v17;
          if ( (v18 & 0x2360) != 0 )
            goto LABEL_11;
          if ( (v18 & 0x880) != 0 )
            goto LABEL_35;
          if ( (v18 & 0x1400) == 0 )
            goto LABEL_12;
        }
LABEL_14:
        if ( ++v14 == 15 )
          goto LABEL_8;
      }
    }
    v13 = 0;
LABEL_38:
    v22 = *(_QWORD *)(a1 + 5384);
    if ( v22 && *(_QWORD **)(v22 + 5640) == v5 && v13 <= *(_DWORD *)(a2 + 160) )
      v13 = *(_DWORD *)(a2 + 160);
  }
  v23 = v5[1];
  v29 = *v5;
  v30 = v23;
  v24 = v5[3];
  v31 = v5[2];
  for ( i = v24; (unsigned int)v30 > v13; LODWORD(v23) = v30 )
    ieee80211_chandef_downgrade(&v29, 0);
  if ( *(_QWORD *)(a2 + 184) == v29
    && *(_DWORD *)(a2 + 192) == (_DWORD)v23
    && *(_DWORD *)(a2 + 196) == HIDWORD(v30)
    && *(unsigned __int16 *)(a2 + 212) == WORD2(i)
    && *(_DWORD *)(a2 + 200) == (_DWORD)v31
    && *(unsigned __int16 *)(a2 + 214) == HIWORD(i) )
  {
    result = 0;
  }
  else
  {
    v25 = v30;
    v26 = *(unsigned __int8 *)(a2 + 84);
    *(_QWORD *)(a2 + 184) = v29;
    *(_QWORD *)(a2 + 192) = v25;
    v27 = i;
    if ( v26 )
      result = 16;
    else
      result = 0;
    *(_QWORD *)(a2 + 200) = v31;
    *(_QWORD *)(a2 + 208) = v27;
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
