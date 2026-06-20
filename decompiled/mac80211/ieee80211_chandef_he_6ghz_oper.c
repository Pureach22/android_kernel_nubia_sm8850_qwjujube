unsigned int *__fastcall ieee80211_chandef_he_6ghz_oper(__int64 a1, unsigned int *a2, unsigned __int8 *a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x9
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  unsigned __int8 *v8; // x20
  unsigned int v12; // w0
  unsigned int *result; // x0
  int v14; // w8
  unsigned int *v15; // x20
  unsigned int v16; // w0
  unsigned __int8 *v17; // x8
  unsigned int v18; // w9
  int v19; // w9
  int v20; // w8
  int v21; // w8
  __int64 v22; // x0
  int v23; // w9
  unsigned int v24; // kr04_4
  __int64 v25; // x0
  unsigned int v26; // w0
  __int16 v27; // w8
  __int64 v28; // x9
  __int64 v29; // x10
  _DWORD *v30; // [xsp+8h] [xbp-28h] BYREF
  __int64 v31; // [xsp+10h] [xbp-20h]
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a4 + 8);
  v30 = *(_DWORD **)a4;
  v31 = v4;
  v5 = *(_QWORD *)(a4 + 24);
  v32 = *(_QWORD *)(a4 + 16);
  v33 = v5;
  if ( *v30 == 3 )
  {
    if ( !a2 )
      goto LABEL_43;
    v6 = *a2;
    if ( (v6 & 0x20000) == 0 )
      goto LABEL_43;
    v7 = 9;
    if ( (v6 & 0x4000) == 0 )
      v7 = 6;
    v8 = (unsigned __int8 *)a2 + v7 + ((v6 >> 15) & 1);
    if ( !v8 )
      goto LABEL_43;
    v12 = ieee80211_channel_to_freq_khz(*v8, 3);
    result = (unsigned int *)ieee80211_get_channel_khz(*(_QWORD *)(a1 + 72), 1000 * (v12 / 0x3E8));
    v30 = result;
    if ( result )
    {
      if ( !a3 || (*a3 & 1) == 0 )
      {
        if ( (v8[1] & 3u) > 1 )
        {
          if ( (v8[1] & 3) == 2 )
          {
            v14 = 3;
          }
          else
          {
            v20 = v8[3];
            LODWORD(v31) = 3;
            if ( !v20 )
            {
LABEL_31:
              v24 = ieee80211_channel_to_freq_khz(v8[2], 3);
              v25 = v8[3];
              HIDWORD(v31) = v24 / 0x3E8;
              LODWORD(v32) = (unsigned int)ieee80211_channel_to_freq_khz(v25, 3) / 0x3E8;
              goto LABEL_41;
            }
            v21 = v20 - v8[2];
            if ( v21 < 0 )
              v21 = -v21;
            if ( v21 == 8 )
            {
              v22 = v8[3];
              LODWORD(v31) = 5;
              HIDWORD(v31) = (unsigned int)ieee80211_channel_to_freq_khz(v22, 3) / 0x3E8;
              goto LABEL_41;
            }
            v14 = 4;
          }
        }
        else if ( (v8[1] & 3) != 0 )
        {
          v14 = 2;
        }
        else
        {
          v14 = 1;
        }
        LODWORD(v31) = v14;
        goto LABEL_31;
      }
      v15 = result;
      v16 = ieee80211_channel_to_freq_khz(a3[6], *result);
      v17 = a3;
      v18 = a3[5] & 7;
      HIDWORD(v31) = v16 / 0x3E8;
      if ( v18 <= 1 )
      {
        if ( v18 )
          v23 = 2;
        else
          v23 = 1;
      }
      else
      {
        if ( v18 != 2 )
        {
          if ( v18 == 3 )
          {
            v19 = 5;
          }
          else
          {
            if ( v18 != 4 )
            {
LABEL_37:
              if ( (~*v17 & 3) != 0 )
                v27 = 0;
              else
                v27 = *((_WORD *)v17 + 4);
              HIWORD(v33) = v27;
LABEL_41:
              if ( (cfg80211_chandef_valid(&v30) & 1) != 0 )
              {
                v28 = v31;
                result = (_DWORD *)&unk_1;
                *(_QWORD *)a4 = v30;
                *(_QWORD *)(a4 + 8) = v28;
                v29 = v33;
                *(_QWORD *)(a4 + 16) = v32;
                *(_QWORD *)(a4 + 24) = v29;
                goto LABEL_44;
              }
LABEL_43:
              result = nullptr;
              goto LABEL_44;
            }
            v19 = 13;
          }
          LODWORD(v31) = v19;
          v26 = ieee80211_channel_to_freq_khz(a3[7], *v15);
          v17 = a3;
          HIDWORD(v31) = v26 / 0x3E8;
          goto LABEL_37;
        }
        v23 = 3;
      }
      LODWORD(v31) = v23;
      goto LABEL_37;
    }
  }
  else
  {
    result = (_DWORD *)&unk_1;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
