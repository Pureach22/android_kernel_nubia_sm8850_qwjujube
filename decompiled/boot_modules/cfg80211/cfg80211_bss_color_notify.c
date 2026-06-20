__int64 __fastcall cfg80211_bss_color_notify(__int64 a1, unsigned int a2, char a3, __int64 a4, char a5)
{
  unsigned int v5; // w20
  __int64 v6; // x21
  unsigned int v7; // w22
  char v8; // w23
  __int64 v9; // x25
  __int64 *v10; // x27
  __int64 v11; // x26
  __int64 v12; // x0
  _DWORD *v13; // x19
  __int64 v14; // x0
  __int64 v15; // x24
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x3
  int v19; // w0
  unsigned __int64 StatusReg; // x19
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x8
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 992);
  v11 = *v10;
  if ( *v10 )
  {
    v8 = a5;
    v6 = a4;
    LOBYTE(v5) = a3;
    v9 = a1;
    v7 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v21 = _traceiter_cfg80211_bss_color_notify(0, v9, v7, v5, v6);
      v24 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v24;
      if ( !v24 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v21, v22, v23);
    }
  }
  v12 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( !v12 )
  {
    result = 4294967284LL;
    goto LABEL_8;
  }
  v13 = (_DWORD *)v12;
  v14 = genlmsg_put(v12, 0, 0, &nl80211_fam, 0, v7);
  if ( !v14 )
    goto LABEL_6;
  v15 = v14;
  LODWORD(v25[0]) = *(_DWORD *)(v9 + 224);
  if ( (unsigned int)nla_put(v13, 3, 4, v25) )
    goto LABEL_6;
  if ( *((_WORD *)v10 + 736) )
  {
    LOBYTE(v25[0]) = v8;
    if ( (unsigned int)nla_put(v13, 313, 1, v25) )
      goto LABEL_6;
  }
  if ( v7 != 141 )
  {
    if ( v7 != 143 )
      goto LABEL_16;
    LODWORD(v25[0]) = (unsigned __int8)v5;
    if ( !(unsigned int)nla_put(v13, 303, 4, v25) )
      goto LABEL_16;
LABEL_6:
    sk_skb_reason_drop(0, v13, 2);
    result = 4294967274LL;
    goto LABEL_8;
  }
  v25[0] = v6;
  if ( (unsigned int)nla_put_64bit(v13, 302, 8, v25, 229) )
    goto LABEL_6;
LABEL_16:
  *(_DWORD *)(v15 - 20) = v13[54] + v13[52] - (v15 - 20);
  if ( (unsigned __int8)byte_BF570 <= 3u )
  {
    __break(0x800u);
    result = 4294967274LL;
  }
  else
  {
    v17 = *(_QWORD *)(*(_QWORD *)(v11 + 1352) + 288LL);
    v18 = (unsigned int)(dword_BF5E4 + 3);
    v13[14] = v18;
    v19 = netlink_broadcast_filtered(v17, v13, 0, v18, 3264, 0, 0);
    result = v19 & (unsigned int)(v19 >> 31);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
