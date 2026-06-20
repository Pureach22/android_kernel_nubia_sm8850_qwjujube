__int64 __fastcall nl80211_dump_survey(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x22
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 v8; // x1
  __int64 v9; // x28
  __int64 v10; // x25
  _DWORD *v11; // x8
  unsigned int v12; // w0
  __int64 v13; // x28
  __int64 v14; // x0
  __int64 v15; // x24
  __int64 v16; // x28
  __int64 v17; // x26
  _WORD *v18; // x28
  __int16 v19; // w8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x9
  __int64 result; // x0
  __int64 v23; // [xsp+8h] [xbp-68h] BYREF
  __int64 v24; // [xsp+10h] [xbp-60h] BYREF
  __int64 v25; // [xsp+18h] [xbp-58h] BYREF
  __int64 v26; // [xsp+20h] [xbp-50h]
  __int64 v27; // [xsp+28h] [xbp-48h]
  __int64 v28; // [xsp+30h] [xbp-40h]
  __int64 v29; // [xsp+38h] [xbp-38h]
  __int64 v30; // [xsp+40h] [xbp-30h]
  __int64 v31; // [xsp+48h] [xbp-28h]
  __int64 v32; // [xsp+50h] [xbp-20h]
  __int64 v33; // [xsp+58h] [xbp-18h]
  _QWORD v34[2]; // [xsp+60h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 96);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v5 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
  if ( !v5 )
  {
    result = 4294967284LL;
    goto LABEL_64;
  }
  v23 = 0;
  v24 = 0;
  v6 = nl80211_prepare_wdev_dump(a2, &v24, &v23, v5);
  if ( v6 )
  {
    v7 = v6;
    kfree(v5);
    goto LABEL_61;
  }
  v8 = *(_QWORD *)(v23 + 32);
  if ( !v8 )
  {
    v7 = -22;
    goto LABEL_60;
  }
  v9 = v24;
  if ( !*(_QWORD *)(*(_QWORD *)v24 + 472LL) )
  {
    v7 = -95;
    goto LABEL_60;
  }
  v10 = *(_QWORD *)(v5 + 1744);
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v11 = *(_DWORD **)(*(_QWORD *)v9 + 472LL);
    if ( *(v11 - 1) != 1827032819 )
      __break(0x8228u);
    v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64 *))v11)(v9 + 992, v8, v4, &v25);
    if ( v12 )
      break;
    if ( v25 )
    {
      if ( (*(_BYTE *)(v25 + 12) & 1) != 0 )
        goto LABEL_8;
    }
    else if ( !v10 )
    {
      goto LABEL_8;
    }
    v13 = *(_QWORD *)(v23 + 32);
    v14 = genlmsg_put(
            a1,
            *(unsigned int *)(*(_QWORD *)a2 + 52LL),
            *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
            &nl80211_fam,
            2,
            51);
    if ( !v14 )
      goto LABEL_59;
    v15 = v14;
    LODWORD(v34[0]) = *(_DWORD *)(v13 + 224);
    if ( (unsigned int)nla_put(a1, 3, 4, v34) )
      goto LABEL_54;
    v16 = *(_QWORD *)(a1 + 216);
    v17 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 84, 0, 0) & 0x80000000) != 0 )
      goto LABEL_54;
    v18 = (_WORD *)(v16 + v17);
    if ( !v18 )
      goto LABEL_54;
    if ( v25 )
    {
      LODWORD(v34[0]) = *(_DWORD *)(v25 + 4);
      if ( (unsigned int)nla_put(a1, 1, 4, v34) )
        goto LABEL_54;
      if ( v25 )
      {
        if ( *(_WORD *)(v25 + 8) )
        {
          LODWORD(v34[0]) = *(unsigned __int16 *)(v25 + 8);
          if ( (unsigned int)nla_put(a1, 12, 4, v34) )
            goto LABEL_54;
        }
      }
    }
    v19 = v33;
    if ( (v33 & 1) != 0 )
    {
      LOBYTE(v34[0]) = BYTE4(v33);
      if ( (unsigned int)nla_put(a1, 2, 1, v34) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 2) != 0 )
    {
      if ( (unsigned int)nla_put(a1, 3, 0, 0) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 4) != 0 )
    {
      v34[0] = v26;
      if ( (unsigned int)nla_put_64bit(a1, 4, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 8) != 0 )
    {
      v34[0] = v27;
      if ( (unsigned int)nla_put_64bit(a1, 5, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 0x10) != 0 )
    {
      v34[0] = v28;
      if ( (unsigned int)nla_put_64bit(a1, 6, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 0x20) != 0 )
    {
      v34[0] = v29;
      if ( (unsigned int)nla_put_64bit(a1, 7, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 0x40) != 0 )
    {
      v34[0] = v30;
      if ( (unsigned int)nla_put_64bit(a1, 8, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 0x80) != 0 )
    {
      v34[0] = v31;
      if ( (unsigned int)nla_put_64bit(a1, 9, 8, v34, 10) )
        goto LABEL_54;
      v19 = v33;
    }
    if ( (v19 & 0x100) != 0 )
    {
      v34[0] = v32;
      if ( (unsigned int)nla_put_64bit(a1, 11, 8, v34, 10) )
      {
LABEL_54:
        v20 = v15 - 20;
        if ( v15 != 20 )
        {
          v21 = *(_QWORD *)(a1 + 224);
          if ( v21 > v20 )
          {
            __break(0x800u);
            v21 = *(_QWORD *)(a1 + 224);
          }
          skb_trim(a1, (unsigned int)(v20 - v21));
        }
        goto LABEL_59;
      }
    }
    *v18 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v18;
    *(_DWORD *)(v15 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v15 - 20);
LABEL_8:
    v9 = v24;
    ++v4;
    v8 = *(_QWORD *)(v23 + 32);
  }
  if ( v12 == -2 )
  {
LABEL_59:
    *(_QWORD *)(a2 + 96) = (int)v4;
    v7 = *(_DWORD *)(a1 + 112);
    goto LABEL_60;
  }
  v7 = v12;
LABEL_60:
  kfree(v5);
  mutex_unlock(v24 + 992);
LABEL_61:
  result = v7;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
