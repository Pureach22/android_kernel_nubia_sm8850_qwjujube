__int64 __fastcall nl80211_get_coalesce(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x25
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x27
  __int64 v15; // x27
  int v16; // t1
  __int64 v17; // x22
  __int64 v18; // x23
  _WORD *v19; // x26
  __int64 v20; // x22
  __int64 v21; // x23
  __int64 v22; // x24
  __int64 v23; // x28
  _WORD *v24; // x28
  __int64 v25; // x8
  unsigned int v26; // w24
  int v27; // w9
  int v28; // w0
  __int64 result; // x0
  _WORD *v30; // [xsp+8h] [xbp-28h]
  __int64 v31; // [xsp+10h] [xbp-20h]
  _WORD *v32; // [xsp+18h] [xbp-18h]
  int v33; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD *)a2 + 6);
  if ( !*(_QWORD *)(v2 + 2352) )
  {
    result = 4294967201LL;
    goto LABEL_32;
  }
  v4 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_32;
  }
  v5 = v4;
  v6 = genlmsg_put(v4, a2[1], *a2, &nl80211_fam, 0, 100);
  if ( !v6 )
    goto LABEL_31;
  v7 = *(_DWORD **)(v2 + 656);
  v8 = v6;
  if ( v7 && *v7 )
  {
    v9 = *(_QWORD *)(v5 + 216);
    v10 = *(unsigned int *)(v5 + 208);
    if ( (nla_put(v5, 182, 0, 0) & 0x80000000) == 0 )
    {
      v32 = (_WORD *)(v9 + v10);
      if ( v9 + v10 )
      {
        if ( **(int **)(v2 + 656) >= 1 )
        {
          v11 = 0;
          do
          {
            v12 = *(_QWORD *)(v5 + 216);
            v13 = *(unsigned int *)(v5 + 208);
            v31 = v11 + 1;
            if ( (nla_put(v5, v11 + 1, 0, 0) & 0x80000000) != 0 )
              goto LABEL_31;
            v30 = (_WORD *)(v12 + v13);
            if ( !(v12 + v13) )
              goto LABEL_31;
            v14 = *(_QWORD *)(v2 + 656) + 24 * v11;
            v16 = *(_DWORD *)(v14 + 8);
            v15 = v14 + 8;
            v33 = v16;
            if ( (unsigned int)nla_put(v5, 1, 4, &v33) )
              goto LABEL_31;
            v33 = *(_DWORD *)(v15 + 4);
            if ( (unsigned int)nla_put(v5, 2, 4, &v33) )
              goto LABEL_31;
            v17 = *(_QWORD *)(v5 + 216);
            v18 = *(unsigned int *)(v5 + 208);
            if ( (nla_put(v5, 3, 0, 0) & 0x80000000) != 0 )
              goto LABEL_31;
            v19 = (_WORD *)(v17 + v18);
            if ( !(v17 + v18) )
              goto LABEL_31;
            if ( *(int *)(v15 + 16) >= 1 )
            {
              v20 = 0;
              v21 = 0;
              do
              {
                ++v21;
                v22 = *(_QWORD *)(v5 + 216);
                v23 = *(unsigned int *)(v5 + 208);
                if ( (nla_put(v5, (unsigned int)v21, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_31;
                v24 = (_WORD *)(v22 + v23);
                if ( !v24 )
                  goto LABEL_31;
                v25 = *(_QWORD *)(v15 + 8) + v20;
                v26 = *(_DWORD *)(v25 + 16);
                v27 = v26 + 7;
                if ( (int)(v26 + 7) < 0 )
                  v27 = v26 + 14;
                if ( (unsigned int)nla_put(v5, 1, (unsigned int)(v27 >> 3), *(_QWORD *)v25) )
                  goto LABEL_31;
                if ( (unsigned int)nla_put(v5, 2, v26, *(_QWORD *)(*(_QWORD *)(v15 + 8) + v20 + 8)) )
                  goto LABEL_31;
                v33 = *(_DWORD *)(*(_QWORD *)(v15 + 8) + v20 + 20);
                if ( (unsigned int)nla_put(v5, 3, 4, &v33) )
                  goto LABEL_31;
                v20 += 24;
                *v24 = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (_WORD)v24;
              }
              while ( v21 < *(int *)(v15 + 16) );
            }
            *v19 = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (_WORD)v19;
            v11 = v31;
            *v30 = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (_WORD)v30;
          }
          while ( v31 < **(int **)(v2 + 656) );
        }
        *v32 = *(_WORD *)(v5 + 216) + *(_WORD *)(v5 + 208) - (_WORD)v32;
        goto LABEL_28;
      }
    }
LABEL_31:
    sk_skb_reason_drop(0, v5, 2);
    result = 4294967191LL;
    goto LABEL_32;
  }
LABEL_28:
  *(_DWORD *)(v8 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v8 - 20);
  v28 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v5, a2[1], 64);
  result = v28 & (unsigned int)(v28 >> 31);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
