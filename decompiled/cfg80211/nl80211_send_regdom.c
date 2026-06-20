__int64 __fastcall nl80211_send_regdom(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x20
  __int64 v12; // x0
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  int *v19; // x3
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = genlmsg_put(a1, *(unsigned int *)(*(_QWORD *)a2 + 52LL), a3, &nl80211_fam, 2, 31);
  if ( !v9 )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_20;
  }
  v10 = a2[16];
  v11 = v9;
  if ( v10 && a2[17] != v10 )
    *(_WORD *)(v9 - 14) |= 0x10u;
  a2[16] = a2[17];
  v12 = nl80211_put_regdom(a5, a1);
  if ( !(_DWORD)v12 )
  {
    if ( a4 )
    {
      v20 = ((__int64 (__fastcall *)(__int64))get_wiphy_idx)(a4);
      if ( (unsigned int)nla_put(a1, 1, 4, &v20) )
        goto LABEL_6;
      if ( (*(_BYTE *)(a4 + 104) & 0x80) == 0 )
      {
LABEL_19:
        result = 0;
        *(_DWORD *)(v11 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v11 - 20);
        goto LABEL_20;
      }
      v16 = a1;
      v17 = 216;
      v18 = 0;
      v19 = nullptr;
    }
    else
    {
      if ( (reg_last_request_cell_base(v12) & 1) == 0 )
        goto LABEL_19;
      v19 = &v20;
      v16 = a1;
      v20 = 1;
      v17 = 154;
      v18 = 4;
    }
    if ( (unsigned int)nla_put(v16, v17, v18, v19) )
      goto LABEL_6;
    goto LABEL_19;
  }
LABEL_6:
  v13 = v11 - 20;
  if ( v11 != 20 )
  {
    v14 = *(_QWORD *)(a1 + 224);
    if ( v14 > v13 )
    {
      __break(0x800u);
      v14 = *(_QWORD *)(a1 + 224);
    }
    skb_trim(a1, (unsigned int)(v13 - v14));
  }
  result = 4294967206LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
