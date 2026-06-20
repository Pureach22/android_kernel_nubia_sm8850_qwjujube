__int64 __fastcall nl80211_channel_switch(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x22
  int v3; // w25
  _QWORD *v4; // x26
  _QWORD *v5; // x21
  _BYTE *v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w23
  __int64 result; // x0
  __int64 v10; // x20
  __int64 v11; // x24
  int v12; // w8
  int v13; // w27
  __int64 v14; // x8
  __int64 v15; // x1
  unsigned int v16; // w8
  __int64 v17; // x3
  unsigned int v18; // w0
  unsigned int v19; // w22
  __int64 v20; // x21
  unsigned int v21; // w8
  __int64 v22; // x22
  unsigned int v23; // w0
  unsigned int v24; // w8
  __int64 v25; // x8
  __int64 v26; // x4
  unsigned int v27; // w0
  unsigned __int64 StatusReg; // x27
  __int64 v29; // x28
  _QWORD s[53]; // [xsp+8h] [xbp-1C8h] BYREF
  __int64 v31; // [xsp+1B4h] [xbp-1Ch] BYREF
  char v32; // [xsp+1BCh] [xbp-14h]
  __int16 v33; // [xsp+1BDh] [xbp-13h]
  char v34; // [xsp+1BFh] [xbp-11h]
  __int64 v35; // [xsp+1C0h] [xbp-10h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (_QWORD *)a2[4];
  v6 = (_BYTE *)a2[6];
  v7 = v5[313];
  if ( v7 )
    v8 = *(unsigned __int8 *)(v7 + 4);
  else
    v8 = 0;
  if ( *(_QWORD *)(*(_QWORD *)v6 + 728LL) && (v6[1094] & 0x80) != 0 )
  {
    v10 = a2[7];
    result = 4294967201LL;
    v11 = *(_QWORD *)(v10 + 992);
    v12 = *(_DWORD *)(v11 + 8);
    if ( v12 > 6 )
    {
      if ( v12 != 7 )
      {
        if ( v12 != 9 )
          goto LABEL_7;
LABEL_14:
        if ( v8 > 0xE )
        {
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v29 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &nl80211_channel_switch__alloc_tag;
          v20 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
          *(_QWORD *)(StatusReg + 80) = v29;
          if ( v20 )
          {
LABEL_41:
            v23 = _nla_parse(
                    v20,
                    335,
                    *(_QWORD *)(v2[4] + 1480LL) + 4LL,
                    (unsigned __int16)(**(_WORD **)(v2[4] + 1480LL) - 4),
                    &nl80211_policy,
                    0,
                    v2[8]);
            if ( v23 )
              goto LABEL_32;
            v23 = nl80211_parse_beacon(v6, v20, v4 + 4, v2[8]);
            if ( v23 )
              goto LABEL_32;
            v26 = *(_QWORD *)(v20 + 1488);
            if ( !v26 )
              goto LABEL_47;
            v23 = nl80211_parse_counter_offsets(v6, s[6], s[17], BYTE2(s[51]), v26, &s[26], &s[28]);
            if ( v23 )
              goto LABEL_32;
            v27 = nl80211_parse_counter_offsets(
                    v6,
                    s[10],
                    s[21],
                    BYTE2(s[51]),
                    *(_QWORD *)(v20 + 1496),
                    &s[27],
                    (char *)&s[28] + 4);
            v15 = (__int64)v2;
            v19 = v27;
            if ( v27 )
              goto LABEL_33;
LABEL_31:
            v22 = v15;
            v23 = nl80211_parse_chandef((__int64)v6, v15, 0, (__int64)s);
            if ( v23 )
            {
LABEL_32:
              v19 = v23;
              goto LABEL_33;
            }
            v24 = *(_DWORD *)(v11 + 8);
            v32 = 1;
            v31 = v24;
            v33 = 0;
            v34 = 0;
            if ( (cfg80211_reg_check_beaconing((__int64)(v6 + 992), (__int64)s, (unsigned int *)&v31) & 1) != 0 )
            {
              v23 = ((__int64 (__fastcall *)(_QWORD, _QWORD *, _QWORD))cfg80211_chandef_dfs_required)(
                      *(_QWORD *)v11,
                      s,
                      *(unsigned int *)(v11 + 8));
              if ( (v23 & 0x80000000) != 0 )
                goto LABEL_32;
              if ( v23 )
              {
                v25 = *(_QWORD *)(v22 + 32);
                LOBYTE(s[51]) = 1;
                if ( v3 && !*(_QWORD *)(v25 + 1528) )
                  goto LABEL_47;
              }
              else
              {
                v25 = *(_QWORD *)(v22 + 32);
              }
              if ( *(_QWORD *)(v25 + 1472) )
                BYTE1(s[51]) = 1;
              BYTE3(s[51]) = v8;
              v23 = rdev_channel_switch(v6, v10, s);
              goto LABEL_32;
            }
LABEL_47:
            v19 = -22;
            goto LABEL_33;
          }
LABEL_53:
          v19 = -12;
          goto LABEL_33;
        }
        if ( *(_DWORD *)(v11 + 72LL * v8 + 400) )
        {
          v2 = a2;
          v3 = 0;
          v13 = 1;
LABEL_21:
          v4 = s;
          memset(s, 0, sizeof(s));
          LOBYTE(s[15]) = -1;
          if ( v5[38] )
          {
            v14 = v5[183];
            if ( v14 )
            {
              v15 = (__int64)v2;
              if ( v13 )
              {
                if ( v5[185] )
                {
                  v16 = *(_DWORD *)(v14 + 4);
                  if ( v16 <= 0xFF )
                  {
                    v17 = v2[8];
                    BYTE2(s[51]) = v16;
                    v18 = nl80211_parse_beacon(v6, v5, &s[29], v17);
                    if ( v18 )
                    {
                      v19 = v18;
                      v20 = 0;
LABEL_33:
                      kfree(s[38]);
                      kfree(s[13]);
                      kfree(s[39]);
                      kfree(s[14]);
                      kfree(v20);
                      result = v19;
                      goto LABEL_7;
                    }
                    v20 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
                    if ( v20 )
                      goto LABEL_41;
                    goto LABEL_53;
                  }
                }
              }
              else
              {
                v21 = *(_DWORD *)(v14 + 4);
                if ( v21 <= 0xFF )
                {
                  v20 = 0;
                  BYTE2(s[51]) = v21;
                  goto LABEL_31;
                }
              }
            }
          }
          result = 4294967274LL;
          goto LABEL_7;
        }
LABEL_18:
        result = 4294967189LL;
        goto LABEL_7;
      }
      if ( !*(_BYTE *)(v11 + 384) )
        goto LABEL_18;
    }
    else
    {
      if ( v12 != 1 )
      {
        if ( v12 != 3 )
          goto LABEL_7;
        goto LABEL_14;
      }
      if ( !*(_BYTE *)(v11 + 356) )
        goto LABEL_18;
    }
    v2 = a2;
    v13 = 0;
    v3 = 1;
    goto LABEL_21;
  }
  result = 4294967201LL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
