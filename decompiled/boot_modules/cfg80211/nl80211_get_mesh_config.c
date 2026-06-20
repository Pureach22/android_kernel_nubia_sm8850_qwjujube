__int64 __fastcall nl80211_get_mesh_config(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x8
  int v5; // w9
  __int64 (__fastcall *v7)(__int64, __int64, __int64 *); // x8
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x19
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x23
  __int64 v14; // x24
  _WORD *v15; // x23
  int v16; // w0
  __int64 v17; // [xsp+8h] [xbp-68h] BYREF
  __int64 v18; // [xsp+10h] [xbp-60h]
  __int64 v19; // [xsp+18h] [xbp-58h]
  __int64 v20; // [xsp+20h] [xbp-50h]
  __int64 v21; // [xsp+28h] [xbp-48h]
  __int64 v22; // [xsp+30h] [xbp-40h]
  __int64 v23; // [xsp+38h] [xbp-38h]
  __int64 v24; // [xsp+40h] [xbp-30h]
  __int64 v25; // [xsp+48h] [xbp-28h]
  void *v26; // [xsp+50h] [xbp-20h]
  __int64 v27; // [xsp+58h] [xbp-18h]
  int v28; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+68h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a2 + 6);
  v3 = *((_QWORD *)a2 + 7);
  v26 = nullptr;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v4 = *(_QWORD *)(v3 + 992);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v5 = *(_DWORD *)(v4 + 8);
  v17 = 0;
  if ( v5 != 7 || !*(_QWORD *)(*(_QWORD *)v2 + 232LL) )
  {
    result = 4294967201LL;
    goto LABEL_9;
  }
  if ( !*(_BYTE *)(v4 + 384) )
  {
    v27 = 0;
    v25 = 0xA00000001LL;
    v26 = &_ksymtab_cfg80211_pmsr_report;
    v21 = 0x320064000ALL;
    v22 = 0x10013880000LL;
    v23 = 0x300000000LL;
    v24 = 0x7D0138800001770LL;
    v17 = *(_QWORD *)default_mesh_config;
    v18 = 0x32011F1F03LL;
    v19 = 0x3E800000004LL;
    v20 = 0x138800000064LL;
LABEL_11:
    v9 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( v9 )
    {
      v10 = v9;
      v11 = genlmsg_put(v9, a2[1], *a2, &nl80211_fam, 0, 28);
      if ( !v11 )
        goto LABEL_47;
      v12 = v11;
      v13 = *(_QWORD *)(v10 + 216);
      v14 = *(unsigned int *)(v10 + 208);
      if ( (nla_put(v10, 35, 0, 0) & 0x80000000) != 0 )
        goto LABEL_47;
      v15 = (_WORD *)(v13 + v14);
      if ( !v15 )
        goto LABEL_47;
      v28 = *(_DWORD *)(v3 + 224);
      if ( (unsigned int)nla_put(v10, 3, 4, &v28) )
        goto LABEL_47;
      LOWORD(v28) = v17;
      if ( (unsigned int)nla_put(v10, 1, 2, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD1(v17);
      if ( (unsigned int)nla_put(v10, 2, 2, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD2(v17);
      if ( (unsigned int)nla_put(v10, 3, 2, &v28) )
        goto LABEL_47;
      LOWORD(v28) = HIWORD(v17);
      if ( (unsigned int)nla_put(v10, 4, 2, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = v18;
      if ( (unsigned int)nla_put(v10, 5, 1, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE1(v18);
      if ( (unsigned int)nla_put(v10, 6, 1, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE2(v18);
      if ( (unsigned int)nla_put(v10, 15, 1, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE3(v18);
      if ( (unsigned int)nla_put(v10, 7, 1, &v28) )
        goto LABEL_47;
      v28 = HIDWORD(v18);
      if ( (unsigned int)nla_put(v10, 21, 4, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = v19;
      if ( (unsigned int)nla_put(v10, 8, 1, &v28) )
        goto LABEL_47;
      v28 = HIDWORD(v19);
      if ( (unsigned int)nla_put(v10, 9, 4, &v28) )
        goto LABEL_47;
      LOWORD(v28) = v20;
      if ( (unsigned int)nla_put(v10, 10, 2, &v28) )
        goto LABEL_47;
      v28 = HIDWORD(v20);
      if ( (unsigned int)nla_put(v10, 11, 4, &v28) )
        goto LABEL_47;
      LOWORD(v28) = v21;
      if ( (unsigned int)nla_put(v10, 12, 2, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD1(v21);
      if ( (unsigned int)nla_put(v10, 18, 2, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD2(v21);
      if ( (unsigned int)nla_put(v10, 13, 2, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE6(v21);
      if ( (unsigned int)nla_put(v10, 14, 1, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD1(v22);
      if ( (unsigned int)nla_put(v10, 16, 2, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE4(v22);
      if ( (unsigned int)nla_put(v10, 17, 1, &v28) )
        goto LABEL_47;
      LOBYTE(v28) = BYTE5(v22);
      if ( (unsigned int)nla_put(v10, 19, 1, &v28) )
        goto LABEL_47;
      v28 = v23;
      if ( (unsigned int)nla_put(v10, 20, 4, &v28) )
        goto LABEL_47;
      v28 = WORD2(v23);
      if ( (unsigned int)nla_put(v10, 22, 4, &v28) )
        goto LABEL_47;
      v28 = v24;
      if ( (unsigned int)nla_put(v10, 23, 4, &v28) )
        goto LABEL_47;
      LOWORD(v28) = WORD2(v24);
      if ( (unsigned int)nla_put(v10, 24, 2, &v28)
        || (LOWORD(v28) = HIWORD(v24), (unsigned int)nla_put(v10, 25, 2, &v28))
        || (v28 = v25, (unsigned int)nla_put(v10, 26, 4, &v28))
        || (LOWORD(v28) = WORD2(v25), (unsigned int)nla_put(v10, 27, 2, &v28))
        || (v28 = (int)v26, (unsigned int)nla_put(v10, 28, 4, &v28))
        || (LOBYTE(v28) = HIBYTE(v21), (unsigned int)nla_put(v10, 29, 1, &v28))
        || (LOBYTE(v28) = BYTE4(v26), (unsigned int)nla_put(v10, 30, 1, &v28))
        || (LOBYTE(v28) = v22, (unsigned int)nla_put(v10, 31, 1, &v28)) )
      {
LABEL_47:
        sk_skb_reason_drop(0, v10, 2);
        result = 4294967191LL;
      }
      else
      {
        *v15 = *(_DWORD *)(v10 + 216) + *(_DWORD *)(v10 + 208) - (_WORD)v15;
        *(_DWORD *)(v12 - 20) = *(_DWORD *)(v10 + 216) + *(_DWORD *)(v10 + 208) - (v12 - 20);
        v16 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v10, a2[1], 64);
        result = v16 & (unsigned int)(v16 >> 31);
      }
    }
    else
    {
      result = 4294967284LL;
    }
    goto LABEL_9;
  }
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v2 + 232LL);
  if ( *((_DWORD *)v7 - 1) != -829450727 )
    __break(0x8228u);
  result = v7(v2 + 992, v3, &v17);
  if ( !(_DWORD)result )
    goto LABEL_11;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
