__int64 __fastcall nl80211_probe_client(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x21
  int v3; // w8
  __int64 v5; // x8
  __int64 v7; // x23
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x22
  __int64 v12; // x2
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64 *); // x9
  int v14; // w0
  unsigned int v15; // w19
  __int64 result; // x0
  int v17; // w0
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a2 + 7);
  v3 = *(_DWORD *)(*(_QWORD *)(v2 + 992) + 8LL);
  if ( v3 != 9 && v3 != 3 )
    goto LABEL_16;
  v5 = *((_QWORD *)a2 + 4);
  v18 = 0;
  v7 = *((_QWORD *)a2 + 6);
  if ( !*(_QWORD *)(v5 + 48) )
  {
    result = 4294967274LL;
    goto LABEL_19;
  }
  if ( !*(_QWORD *)(*(_QWORD *)v7 + 632LL) )
  {
LABEL_16:
    result = 4294967201LL;
    goto LABEL_19;
  }
  v8 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_19;
  }
  v9 = v8;
  v10 = genlmsg_put(v8, a2[1], *a2, &nl80211_fam, 0, 84);
  if ( v10 )
  {
    v11 = v10;
    v12 = *(_QWORD *)(*((_QWORD *)a2 + 4) + 48LL) + 4LL;
    v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64 *))(*(_QWORD *)v7 + 632LL);
    if ( *((_DWORD *)v13 - 1) != 1175821457 )
      __break(0x8229u);
    v14 = v13(v7 + 992, v2, v12, &v18);
    if ( v14 )
      goto LABEL_15;
    v19[0] = v18;
    if ( !(unsigned int)nla_put_64bit(v9, 88, 8, v19, 229) )
    {
      *(_DWORD *)(v11 - 20) = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (v11 - 20);
      v17 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v9, a2[1], 64);
      result = v17 & (unsigned int)(v17 >> 31);
      goto LABEL_19;
    }
  }
  v14 = -105;
LABEL_15:
  v15 = v14;
  sk_skb_reason_drop(0, v9, 2);
  result = v15;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
