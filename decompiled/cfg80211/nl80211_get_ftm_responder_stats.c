__int64 __fastcall nl80211_get_ftm_responder_stats(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w10
  bool v8; // zf
  unsigned __int64 v9; // x9
  __int64 (__fastcall *v11)(__int64, __int64, __int64 *); // x8
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x21
  __int64 v18; // x23
  _WORD *v19; // x21
  __int16 v20; // w8
  int v21; // w0
  __int64 v22; // [xsp+0h] [xbp-40h] BYREF
  __int64 v23; // [xsp+8h] [xbp-38h]
  __int64 v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  _QWORD v28[2]; // [xsp+30h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a2 + 6);
  v3 = *((_QWORD *)a2 + 7);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v4 = *((_QWORD *)a2 + 4);
  v22 = 0;
  v23 = 0;
  v5 = *(_QWORD *)(v3 + 992);
  v6 = *(_QWORD *)(v4 + 2504);
  v7 = *(_DWORD *)(v5 + 8);
  v8 = v7 == 3;
  if ( !v6 )
    goto LABEL_5;
  if ( v7 != 3 )
  {
LABEL_13:
    result = 4294967201LL;
    goto LABEL_16;
  }
  v9 = *(unsigned __int8 *)(v6 + 4);
  v8 = v9 == 14;
  if ( v9 > 0xE )
  {
    __break(0x5512u);
LABEL_5:
    if ( !v8 )
      goto LABEL_13;
    LODWORD(v9) = 0;
  }
  if ( !*(_DWORD *)(v5 + 72LL * (unsigned int)v9 + 400) )
    goto LABEL_13;
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v2 + 872LL);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != -1120472888 )
      __break(0x8228u);
    result = v11(v2 + 992, v3, &v22);
  }
  else
  {
    result = 4294967201LL;
  }
  if ( !(_DWORD)result )
  {
    if ( !(_DWORD)v22 )
    {
      result = 4294967235LL;
      goto LABEL_16;
    }
    v13 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( !v13 )
    {
      result = 4294967284LL;
      goto LABEL_16;
    }
    v14 = v13;
    v15 = genlmsg_put(v13, a2[1], *a2, &nl80211_fam, 0, 130);
    if ( !v15 )
      goto LABEL_21;
    v16 = v15;
    LODWORD(v28[0]) = *(_DWORD *)(v3 + 224);
    if ( (unsigned int)nla_put(v14, 3, 4, v28) )
      goto LABEL_21;
    v17 = *(_QWORD *)(v14 + 216);
    v18 = *(unsigned int *)(v14 + 208);
    if ( (nla_put(v14, 271, 0, 0) & 0x80000000) != 0 )
      goto LABEL_21;
    v19 = (_WORD *)(v17 + v18);
    if ( !v19 )
      goto LABEL_21;
    v20 = v22;
    if ( (v22 & 2) != 0 )
    {
      LODWORD(v28[0]) = HIDWORD(v22);
      if ( (unsigned int)nla_put(v14, 1, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 4) != 0 )
    {
      LODWORD(v28[0]) = v23;
      if ( (unsigned int)nla_put(v14, 2, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 8) != 0 )
    {
      LODWORD(v28[0]) = HIDWORD(v23);
      if ( (unsigned int)nla_put(v14, 3, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 0x10) != 0 )
    {
      LODWORD(v28[0]) = v24;
      if ( (unsigned int)nla_put(v14, 4, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 0x20) != 0 )
    {
      LODWORD(v28[0]) = HIDWORD(v24);
      if ( (unsigned int)nla_put(v14, 5, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 0x40) != 0 )
    {
      v28[0] = v25;
      if ( (unsigned int)nla_put_64bit(v14, 6, 8, v28, 10) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 0x80) != 0 )
    {
      LODWORD(v28[0]) = v26;
      if ( (unsigned int)nla_put(v14, 7, 4, v28) )
        goto LABEL_21;
      v20 = v22;
    }
    if ( (v20 & 0x100) == 0 )
    {
LABEL_50:
      if ( (v20 & 0x200) == 0 || (LODWORD(v28[0]) = v27, !(unsigned int)nla_put(v14, 9, 4, v28)) )
      {
        *v19 = *(_DWORD *)(v14 + 216) + *(_DWORD *)(v14 + 208) - (_WORD)v19;
        *(_DWORD *)(v16 - 20) = *(_DWORD *)(v14 + 216) + *(_DWORD *)(v14 + 208) - (v16 - 20);
        v21 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v14, a2[1], 64);
        result = v21 & (unsigned int)(v21 >> 31);
        goto LABEL_16;
      }
      goto LABEL_21;
    }
    LODWORD(v28[0]) = HIDWORD(v26);
    if ( !(unsigned int)nla_put(v14, 8, 4, v28) )
    {
      v20 = v22;
      goto LABEL_50;
    }
LABEL_21:
    sk_skb_reason_drop(0, v14, 2);
    result = 4294967191LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
