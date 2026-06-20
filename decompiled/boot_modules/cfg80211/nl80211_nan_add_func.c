__int64 __fastcall nl80211_nan_add_func(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w8
  __int64 v5; // x8
  __int64 result; // x0
  _WORD *v7; // x2
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int *v11; // x9
  bool v12; // cf
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x8
  __int16 v16; // w10
  __int64 v17; // x21
  int v18; // w12
  _BYTE *v19; // x8
  bool v20; // zf
  char v21; // w10
  __int64 v22; // x8
  int v23; // w8
  __int64 v24; // x8
  char v25; // w10
  char v26; // w11
  __int64 v27; // x22
  unsigned int v28; // w23
  __int64 v29; // x6
  unsigned int v30; // w8
  __int64 v31; // x0
  __int64 v32; // x24
  __int64 v33; // x11
  __int64 v34; // x10
  char v35; // w8
  int v36; // w11
  __int16 v37; // w8
  int v38; // w10
  _BYTE *v39; // x8
  _WORD *v40; // x22
  __int64 v41; // x8
  unsigned int v42; // w0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x19
  __int64 v46; // x20
  _WORD *v47; // x19
  int v48; // w0
  int v49; // w0
  __int64 v50; // x8
  int v51; // w8
  int v52; // w11
  unsigned __int16 *v53; // x9
  unsigned int v54; // w12
  int v55; // w14
  __int64 v56; // x12
  __int64 v57; // x12
  __int64 v58; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v59; // [xsp+10h] [xbp-B0h]
  _BYTE *v60; // [xsp+18h] [xbp-A8h]
  __int64 v61; // [xsp+20h] [xbp-A0h]
  _WORD *v62; // [xsp+28h] [xbp-98h]
  __int64 v63; // [xsp+30h] [xbp-90h] BYREF
  __int64 v64; // [xsp+38h] [xbp-88h]
  __int64 v65; // [xsp+40h] [xbp-80h]
  __int64 v66; // [xsp+48h] [xbp-78h]
  __int64 v67; // [xsp+50h] [xbp-70h]
  __int64 v68; // [xsp+58h] [xbp-68h]
  __int64 v69; // [xsp+60h] [xbp-60h]
  __int64 v70; // [xsp+68h] [xbp-58h]
  __int64 v71; // [xsp+70h] [xbp-50h]
  __int64 v72; // [xsp+78h] [xbp-48h]
  __int64 v73; // [xsp+80h] [xbp-40h]
  _BYTE *v74; // [xsp+88h] [xbp-38h]
  _WORD *v75; // [xsp+90h] [xbp-30h]
  __int64 v76; // [xsp+98h] [xbp-28h]
  __int64 v77; // [xsp+A0h] [xbp-20h]
  __int64 v78; // [xsp+A8h] [xbp-18h]
  __int64 v79; // [xsp+B0h] [xbp-10h]
  __int64 v80; // [xsp+B8h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_QWORD *)a2 + 6);
  v2 = *((_QWORD *)a2 + 7);
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = nullptr;
  v75 = nullptr;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v4 = *(_DWORD *)(v2 + 8);
  v63 = 0;
  if ( v4 != 12 )
  {
    result = 4294967201LL;
    goto LABEL_6;
  }
  v5 = *(_QWORD *)(v2 + 32);
  if ( v5 )
  {
    if ( (*(_QWORD *)(v5 + 168) & 1) == 0 )
    {
LABEL_4:
      result = 4294967189LL;
      goto LABEL_6;
    }
  }
  else if ( *(_BYTE *)(v2 + 66) != 1 )
  {
    goto LABEL_4;
  }
  v7 = *(_WORD **)(*((_QWORD *)a2 + 4) + 1920LL);
  if ( !v7 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  result = _nla_parse(&v63, 16, v7 + 2, (unsigned __int16)(*v7 - 4), &nl80211_nan_func_policy, 0, *((_QWORD *)a2 + 8));
  if ( !(_DWORD)result )
  {
    v9 = _kmalloc_cache_noprof(timer_delete_sync, 3520, 120);
    if ( !v9 )
    {
      result = 4294967284LL;
      goto LABEL_6;
    }
    v10 = *(_QWORD *)(v3 + 176);
    v11 = a2;
    v12 = __CFADD__(v10, 1);
    v13 = v10 + 1;
    *(_QWORD *)(v3 + 176) = v13;
    if ( v12 )
    {
      __break(0x800u);
      v13 = *(_QWORD *)(v3 + 176) + 1LL;
      *(_QWORD *)(v3 + 176) = v13;
    }
    v14 = v64;
    *(_QWORD *)(v9 + 104) = v13;
    if ( !v14 )
      goto LABEL_31;
    v15 = v65;
    *(_DWORD *)v9 = *(unsigned __int8 *)(v14 + 4);
    if ( !v15 )
      goto LABEL_31;
    v16 = *(_WORD *)(v15 + 8);
    v17 = v9;
    v18 = *(_DWORD *)(v15 + 4);
    v19 = v74;
    v20 = v72 == 0;
    *(_WORD *)(v9 + 8) = v16;
    v21 = !v20;
    *(_DWORD *)(v9 + 4) = v18;
    *(_BYTE *)(v9 + 11) = v21;
    if ( v19 )
    {
      *(_BYTE *)(v9 + 40) = *v19 - 4;
      v22 = kmemdup_noprof(v74 + 4, *(unsigned __int8 *)(v9 + 40), 3264);
      v9 = v17;
      v11 = a2;
      *(_QWORD *)(v17 + 32) = v22;
      if ( !v22 )
      {
        v27 = 0;
        v28 = -12;
        goto LABEL_32;
      }
    }
    if ( v73 )
      *(_DWORD *)(v9 + 24) = *(_DWORD *)(v73 + 4);
    v23 = *(_DWORD *)v9;
    if ( *(_DWORD *)v9 == 2 )
    {
      v27 = 0;
      v28 = -22;
      if ( !v69 )
        goto LABEL_32;
      v33 = v70;
      if ( !v70 )
        goto LABEL_32;
      v34 = v71;
      if ( !v71 )
        goto LABEL_32;
      *(_BYTE *)(v9 + 14) = *(_BYTE *)(v69 + 4);
      v35 = *(_BYTE *)(v33 + 4);
      v36 = *(_DWORD *)(v9 + 24);
      *(_BYTE *)(v9 + 15) = v35;
      v37 = *(_WORD *)(v34 + 8);
      v38 = *(_DWORD *)(v34 + 4);
      *(_WORD *)(v9 + 20) = v37;
      *(_DWORD *)(v9 + 16) = v38;
      if ( v36 )
      {
        v27 = 0;
        goto LABEL_32;
      }
    }
    else if ( v23 == 1 )
    {
      *(_BYTE *)(v9 + 13) = v68 != 0;
    }
    else if ( v23
           || !v66
           || ((v24 = v67, v25 = *(_BYTE *)(v66 + 4), v20 = v67 == 0, *(_BYTE *)(v9 + 10) = v25, v20)
             ? (v26 = 0)
             : (v26 = 1),
               (*(_BYTE *)(v9 + 12) = v26, (v25 & 1) == 0) && v24) )
    {
LABEL_31:
      v27 = 0;
      v28 = -22;
LABEL_32:
      cfg80211_free_nan_func();
      sk_skb_reason_drop(0, v27, 2);
      result = v28;
      goto LABEL_6;
    }
    if ( v75 )
    {
      v61 = 0;
      v62 = nullptr;
      v29 = *((_QWORD *)v11 + 8);
      v59 = 0;
      v60 = nullptr;
      v58 = 0;
      v30 = _nla_parse(&v58, 4, v75 + 2, (unsigned __int16)(*v75 - 4), &nl80211_nan_srf_policy, 0, v29);
      v31 = v17;
      v28 = v30;
      if ( v30 )
        goto LABEL_38;
      v39 = v60;
      v40 = v62;
      *(_BYTE *)(v17 + 41) = v59 != 0;
      if ( v39 )
      {
        v28 = -22;
        if ( !v40 && v61 )
        {
          *(_BYTE *)(v17 + 56) = *v39 - 4;
          v41 = kmemdup_noprof(v60 + 4, *(unsigned __int8 *)(v17 + 56), 3264);
          v31 = v17;
          *(_QWORD *)(v17 + 48) = v41;
          if ( v41 )
          {
            *(_BYTE *)(v17 + 57) = *(_BYTE *)(v61 + 4);
            goto LABEL_51;
          }
          goto LABEL_73;
        }
LABEL_38:
        v32 = 0;
        v27 = 0;
        if ( (v28 & 0x80000000) != 0 )
          goto LABEL_32;
        goto LABEL_39;
      }
      if ( !v40 )
      {
        v28 = -22;
        goto LABEL_38;
      }
      v49 = validate_acl_mac_addrs(v40);
      if ( v49 < 1 )
      {
        v28 = -22;
        v31 = v17;
        goto LABEL_38;
      }
      *(_DWORD *)(v17 + 72) = v49;
      v50 = _kmalloc_noprof(6LL * (unsigned int)v49, 3520);
      v31 = v17;
      *(_QWORD *)(v17 + 64) = v50;
      if ( !v50 )
      {
LABEL_73:
        v28 = -12;
        goto LABEL_38;
      }
      v51 = (unsigned __int16)(*v40 - 4);
      if ( (unsigned int)v51 >= 4 )
      {
        v52 = 0;
        v53 = v40 + 2;
        do
        {
          v54 = *v53;
          if ( v54 < 4 )
            break;
          if ( v51 < v54 )
            break;
          v55 = *((_DWORD *)v53 + 1);
          v56 = *(_QWORD *)(v17 + 64) + 6LL * v52++;
          *(_WORD *)(v56 + 4) = v53[4];
          *(_DWORD *)v56 = v55;
          v57 = (*v53 + 3) & 0x1FFFC;
          v51 -= v57;
          v53 = (unsigned __int16 *)((char *)v53 + v57);
        }
        while ( v51 > 3 );
      }
    }
LABEL_51:
    if ( v77 && (v42 = handle_nan_filter(v77, v17, 1)) != 0 || v76 && (v42 = handle_nan_filter(v76, v17, 0)) != 0 )
    {
      v28 = v42;
      v27 = 0;
      goto LABEL_32;
    }
    v43 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    v27 = v43;
    if ( v43 )
    {
      v44 = genlmsg_put(v43, a2[1], *a2, &nl80211_fam, 0, 117);
      if ( v44 )
      {
        v32 = v44;
        v28 = rdev_add_nan_func(v3, v2, v17);
        v31 = v17;
        if ( (v28 & 0x80000000) != 0 )
          goto LABEL_32;
LABEL_39:
        v58 = *(_QWORD *)(v31 + 104);
        if ( (unsigned int)nla_put_64bit(v27, 88, 8, &v58, 229)
          || (v45 = *(_QWORD *)(v27 + 216),
              v46 = *(unsigned int *)(v27 + 208),
              (nla_put(v27, 240, 0, 0) & 0x80000000) != 0)
          || (v47 = (_WORD *)(v45 + v46)) == nullptr
          || (LOBYTE(v58) = *(_BYTE *)(v17 + 98), (unsigned int)nla_put(v27, 15, 1, &v58)) )
        {
          sk_skb_reason_drop(0, v27, 2);
          result = 4294967191LL;
        }
        else
        {
          *v47 = *(_DWORD *)(v27 + 216) + *(_DWORD *)(v27 + 208) - (_WORD)v47;
          *(_DWORD *)(v32 - 20) = *(_DWORD *)(v27 + 216) + *(_DWORD *)(v27 + 208) - (v32 - 20);
          v48 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v27, a2[1], 64);
          result = v48 & (unsigned int)(v48 >> 31);
        }
        goto LABEL_6;
      }
      __break(0x800u);
    }
    v28 = -12;
    goto LABEL_32;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
