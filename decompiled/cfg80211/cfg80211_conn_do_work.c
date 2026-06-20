__int64 __fastcall cfg80211_conn_do_work(__int64 *a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v6; // x23
  int v7; // w8
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // x9
  int v11; // w8
  void *v12; // x3
  size_t v13; // x4
  _DWORD *v14; // x1
  __int64 v15; // x2
  __int64 *bss; // x0
  __int64 v17; // x1
  unsigned int v18; // w19
  __int64 v19; // x9
  __int64 v20; // x11
  bool v21; // w9
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x13
  __int64 v25; // x14
  __int64 v26; // x9
  __int64 v27; // x12
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x9
  __int64 v31; // x15
  __int64 v32; // x11
  __int64 v33; // x9
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x10
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x9
  unsigned int v42; // w22
  __int64 v48[4]; // [xsp+8h] [xbp-388h] BYREF
  __int64 v49; // [xsp+28h] [xbp-368h]
  __int64 v50; // [xsp+30h] [xbp-360h]
  __int64 v51; // [xsp+38h] [xbp-358h]
  __int64 v52; // [xsp+40h] [xbp-350h]
  __int64 v53; // [xsp+48h] [xbp-348h]
  __int64 v54; // [xsp+50h] [xbp-340h]
  __int64 v55; // [xsp+58h] [xbp-338h]
  __int64 s[102]; // [xsp+60h] [xbp-330h] BYREF

  s[101] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  if ( *a1 )
  {
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v49 = 0;
    memset(v48, 0, sizeof(v48));
    memset(s, 0, 0x328u);
    v6 = a1[10];
    if ( !v6 )
      goto LABEL_32;
    v7 = *(_DWORD *)(v6 + 400);
    v8 = v3 - 992;
    if ( v7 > 4 )
    {
      if ( v7 > 7 )
      {
        if ( v7 != 8 )
        {
          if ( v7 != 9 )
          {
            if ( v7 != 10 )
              goto LABEL_32;
            goto LABEL_31;
          }
          cfg80211_mlme_deauth((__int64 *)(v3 - 992), a1[4], *(int **)(v6 + 16), 0, 0, 3, 0);
          v6 = a1[10];
          if ( v6 )
          {
LABEL_31:
            kfree(*(_QWORD *)(v6 + 416));
            kfree(a1[10]);
            result = 0;
            a1[10] = 0;
            goto LABEL_33;
          }
LABEL_32:
          result = 0;
          goto LABEL_33;
        }
        *a2 = 3;
        goto LABEL_23;
      }
      if ( v7 != 5 )
      {
        if ( v7 != 7 )
          goto LABEL_32;
LABEL_23:
        cfg80211_mlme_deauth((__int64 *)(v3 - 992), a1[4], *(int **)(v6 + 16), 0, 0, 3, 0);
        result = 4294967189LL;
        goto LABEL_33;
      }
      if ( *(_QWORD *)(*(_QWORD *)v8 + 344LL) )
      {
        *(_DWORD *)(v6 + 400) = 6;
        v19 = a1[10];
        if ( *(_BYTE *)(v19 + 433) == 1 )
          s[2] = v19 + 410;
        v20 = *(_QWORD *)(v6 + 64);
        v21 = *(_DWORD *)(v6 + 76) != 0;
        s[1] = *(_QWORD *)(v6 + 56);
        LOBYTE(s[19]) = v21;
        v23 = *(_QWORD *)(v6 + 144);
        v22 = *(_QWORD *)(v6 + 152);
        s[3] = v20;
        v24 = *(_QWORD *)(v6 + 120);
        v25 = *(_QWORD *)(v6 + 160);
        s[12] = v23;
        s[13] = v22;
        v27 = *(_QWORD *)(v6 + 184);
        v26 = *(_QWORD *)(v6 + 192);
        v28 = *(_QWORD *)(v6 + 128);
        v29 = *(_QWORD *)(v6 + 136);
        s[14] = v25;
        s[17] = v27;
        s[18] = v26;
        v31 = *(_QWORD *)(v6 + 168);
        v30 = *(_QWORD *)(v6 + 176);
        s[10] = v28;
        s[11] = v29;
        s[15] = v31;
        s[16] = v30;
        v32 = *(_QWORD *)(v6 + 104);
        s[8] = *(_QWORD *)(v6 + 112);
        s[9] = v24;
        v33 = *(_QWORD *)(v6 + 88);
        s[4] = *(_QWORD *)(v6 + 80);
        s[5] = v33;
        LODWORD(v28) = *(_DWORD *)(v6 + 212);
        s[6] = *(_QWORD *)(v6 + 96);
        s[7] = v32;
        v34 = *(_QWORD *)(v6 + 220);
        HIDWORD(s[19]) = v28;
        v35 = *(_QWORD *)(v6 + 228);
        *(__int64 *)((char *)&s[21] + 1) = v34;
        v36 = *(_QWORD *)(v6 + 236);
        *(__int64 *)((char *)&s[22] + 1) = v35;
        LOWORD(v35) = *(_WORD *)(v6 + 244);
        *(__int64 *)((char *)&s[23] + 1) = v36;
        LOWORD(v36) = *(_WORD *)(v6 + 270);
        *(_WORD *)((char *)&s[24] + 1) = v35;
        v37 = *(_QWORD *)(v6 + 246);
        *(_WORD *)((char *)&s[27] + 3) = v36;
        v38 = *(_QWORD *)(v6 + 254);
        *(__int64 *)((char *)&s[24] + 3) = v37;
        v39 = *(_QWORD *)(v6 + 262);
        LODWORD(v32) = *(_DWORD *)(v6 + 292);
        *(__int64 *)((char *)&s[25] + 3) = v38;
        v40 = *(_QWORD *)(v6 + 272);
        *(__int64 *)((char *)&s[26] + 3) = v39;
        LODWORD(v39) = *(_DWORD *)(v6 + 280);
        *(__int64 *)((char *)&s[27] + 5) = v40;
        v41 = *(_QWORD *)(v6 + 284);
        *(_DWORD *)((char *)&s[28] + 5) = v39;
        *(_DWORD *)((char *)&s[30] + 1) = v32;
        *(__int64 *)((char *)&s[29] + 1) = v41;
        LOBYTE(s[99]) = -1;
        s[0] = (__int64)_cfg80211_get_bss(
                          v3,
                          *(_DWORD **)v6,
                          *(_QWORD *)(v6 + 16),
                          *(void **)(v6 + 32),
                          *(_QWORD *)(v6 + 40),
                          0,
                          2u,
                          1);
        if ( s[0] )
        {
          v42 = cfg80211_mlme_assoc((_BYTE **)(v3 - 992), a1[4], s, nullptr);
          cfg80211_put_bss(v3, (_QWORD *)s[0]);
          if ( !v42 )
            goto LABEL_32;
        }
        else
        {
          v42 = -2;
        }
        cfg80211_mlme_deauth((__int64 *)(v3 - 992), a1[4], *(int **)(v6 + 16), 0, 0, 3, 0);
        result = v42;
        goto LABEL_33;
      }
LABEL_36:
      __break(0x800u);
      result = 4294967201LL;
      goto LABEL_33;
    }
    if ( v7 > 1 )
    {
      if ( v7 == 2 )
      {
        if ( !*(_QWORD *)(*(_QWORD *)v8 + 336LL) )
          goto LABEL_36;
        v10 = *(_QWORD *)(v6 + 200);
        LOWORD(v51) = *(_WORD *)(v6 + 208);
        v11 = *(_DWORD *)(v6 + 48);
        v50 = v10;
        HIDWORD(v49) = v11;
        v12 = *(void **)(v6 + 32);
        v13 = *(_QWORD *)(v6 + 40);
        v14 = *(_DWORD **)v6;
        v15 = *(_QWORD *)(v6 + 16);
        *(_DWORD *)(v6 + 400) = 3;
        bss = _cfg80211_get_bss(v3, v14, v15, v12, v13, 0, 2u, 1);
        v17 = a1[4];
        v48[0] = (__int64)bss;
        LOBYTE(v54) = -1;
        v18 = cfg80211_mlme_auth((__int64 *)(v3 - 992), v17, v48);
        cfg80211_put_bss(v3, (_QWORD *)v48[0]);
        result = v18;
      }
      else
      {
        if ( v7 != 4 )
          goto LABEL_32;
        result = 4294967189LL;
        *a2 = 2;
      }
    }
    else if ( v7 )
    {
      if ( v7 != 1 )
        goto LABEL_32;
      result = cfg80211_conn_scan(a1);
    }
    else
    {
      result = 4294967294LL;
    }
LABEL_33:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  __asm { PRFM            #8, 0x16D3A4 }
  return _cfg80211_connect_result(a1, a2, a3);
}
