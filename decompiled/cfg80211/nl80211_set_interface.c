__int64 __fastcall nl80211_set_interface(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  _QWORD *v5; // x8
  __int64 v6; // x19
  __int64 v7; // x10
  int v8; // w9
  unsigned int v9; // w22
  _BOOL4 v10; // w24
  _WORD *v11; // x10
  __int64 result; // x0
  size_t v13; // x2
  __int64 v14; // x8
  int v15; // w8
  __int64 v16; // x8
  int v17; // w8
  __int64 v18; // x9
  int v19; // w23
  char v20; // w8
  size_t v21; // [xsp+0h] [xbp-30h]
  _QWORD v22[5]; // [xsp+8h] [xbp-28h] BYREF

  v22[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[6];
  v4 = a2[7];
  v5 = (_QWORD *)a2[4];
  memset(v22, 0, 32);
  v6 = *(_QWORD *)(v4 + 992);
  v7 = v5[5];
  v8 = *(_DWORD *)(v6 + 8);
  if ( v7 )
  {
    v9 = *(_DWORD *)(v7 + 4);
    v10 = v8 != v9;
    v11 = (_WORD *)v5[24];
    if ( v11 )
    {
LABEL_3:
      result = 4294967274LL;
      if ( v9 != 7 || v8 != 7 )
        goto LABEL_38;
      if ( (*(_QWORD *)(v4 + 168) & 1) != 0 )
        goto LABEL_37;
      v13 = (unsigned __int8)(*v11 - 4);
      *(_BYTE *)(v6 + 385) = *v11 - 4;
      if ( (unsigned int)v13 >= 0x21 && (nl80211_set_interface___already_done & 1) == 0 )
      {
        nl80211_set_interface___already_done = 1;
        v21 = v13;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v13,
          "field \"wdev->u.mesh.id\" at ../soc-repo/net/wireless/nl80211.c:4397",
          0x20u);
        v13 = v21;
        __break(0x800u);
      }
      memcpy((void *)(v6 + 352), (const void *)(*(_QWORD *)(a2[4] + 192LL) + 4LL), v13);
      v14 = *(_QWORD *)(a2[4] + 664LL);
      if ( !v14 )
        goto LABEL_10;
      goto LABEL_13;
    }
  }
  else
  {
    v10 = 0;
    v9 = *(_DWORD *)(v6 + 8);
    v11 = (_WORD *)v5[24];
    if ( v11 )
      goto LABEL_3;
  }
  v14 = v5[83];
  if ( !v14 )
  {
LABEL_10:
    HIDWORD(v22[0]) = -1;
    goto LABEL_24;
  }
LABEL_13:
  v15 = *(unsigned __int8 *)(v14 + 4);
  HIDWORD(v22[0]) = v15 != 0;
  if ( v15 )
  {
    if ( v9 == 2 )
    {
      if ( (*(_BYTE *)(v3 + 1092) & 0x40) == 0 )
      {
LABEL_22:
        result = 4294967201LL;
        goto LABEL_38;
      }
    }
    else if ( v9 != 4 || (*(_BYTE *)(v3 + 1092) & 0x20) == 0 )
    {
      goto LABEL_22;
    }
  }
  else if ( v4 && (*(_BYTE *)(v4 + 1) & 2) != 0 )
  {
    goto LABEL_37;
  }
  v10 = 1;
LABEL_24:
  result = nl80211_parse_mon_options(v3, v9, a2, v22);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_38;
  if ( (_DWORD)result )
    v10 = 1;
  v16 = *(_QWORD *)(a2[4] + 2664LL);
  if ( v16 )
  {
    v17 = *(_DWORD *)(v16 + 4);
    v18 = -1LL << *(_DWORD *)(a2[6] + 2488LL);
    if ( (v17 & (unsigned int)v18) != 0 )
    {
      result = 4294967274LL;
      goto LABEL_38;
    }
    if ( v17 )
      v19 = v17;
    else
      v19 = ~(_DWORD)v18;
    if ( (*(_QWORD *)(v4 + 168) & 1) == 0 )
      goto LABEL_35;
LABEL_37:
    result = 4294967280LL;
    goto LABEL_38;
  }
  v19 = 0;
LABEL_35:
  if ( v10 )
    result = cfg80211_change_iface(v3, v4, v9, v22);
  else
    result = 0;
  if ( !(_DWORD)result && HIDWORD(v22[0]) != -1 )
    *(_BYTE *)(*(_QWORD *)(v4 + 992) + 65LL) = HIDWORD(v22[0]) != 0;
  if ( v19 )
    *(_DWORD *)(v6 + 1476) = v19;
  v20 = !v10;
  if ( (_DWORD)result )
    v20 = 1;
  if ( (v20 & 1) == 0 )
  {
    nl80211_notify_iface(v3, v6, 6u);
    result = 0;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
