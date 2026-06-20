__int64 __fastcall nl80211_process_links(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6)
{
  _QWORD *v12; // x19
  _WORD *v13; // x8
  int v14; // w25
  const char *v15; // x28
  unsigned int v16; // w8
  __int64 v17; // x27
  __int64 v18; // x8
  __int64 v19; // x27
  __int64 v20; // x26
  __int64 v21; // x20
  __int64 v22; // x8
  __int64 v23; // x1
  __int64 v24; // x8
  __int64 channel_khz; // x0
  int v26; // w8
  unsigned __int64 bss; // x0
  _WORD *v28; // x8
  int v29; // w1
  unsigned __int16 v30; // w8
  __int64 v31; // x1
  int v32; // w2
  __int64 v33; // x8
  const char **v34; // x21
  __int64 v35; // x8
  __int64 v36; // x8
  const char *v37; // x20
  __int64 v39; // [xsp+0h] [xbp-20h]
  __int64 v40; // [xsp+8h] [xbp-18h]
  char s2[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = (_QWORD *)_kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
  if ( !v12 )
  {
    LODWORD(v17) = -12;
    goto LABEL_45;
  }
  v13 = *(_WORD **)(*(_QWORD *)(a6 + 32) + 2496LL);
  v14 = (unsigned __int16)(*v13 - 4);
  if ( (unsigned int)v14 >= 4 )
  {
    v15 = (const char *)(v13 + 2);
    v39 = a6;
    v40 = a5;
    while ( 1 )
    {
      v16 = *(unsigned __int16 *)v15;
      LODWORD(v17) = 0;
      if ( v16 < 4 || v14 < v16 )
        goto LABEL_40;
      memset(v12, 0, 0xA80u);
      if ( *((__int16 *)v15 + 1) < 0 )
      {
        _nla_parse(v12, 335, v15 + 4, (unsigned __int16)(*(_WORD *)v15 - 4), 0, 31, 0);
        v18 = v12[313];
        if ( !v18 )
          break;
      }
      else
      {
        do_trace_netlink_extack("NLA_F_NESTED is missing");
        v18 = v12[313];
        if ( !v18 )
          break;
      }
      v19 = *(unsigned __int8 *)(v18 + 4);
      v20 = a2 + 32 * v19;
      if ( *(_QWORD *)v20 )
        break;
      v21 = v12[6];
      if ( !v21 )
        goto LABEL_27;
      v22 = v12[38];
      if ( !v22 )
        goto LABEL_27;
      v23 = (unsigned int)(1000 * *(_DWORD *)(v22 + 4));
      v24 = v12[290];
      if ( v24 )
        v23 = (unsigned int)(*(_DWORD *)(v24 + 4) + v23);
      channel_khz = ieee80211_get_channel_khz(a1 + 992, v23);
      if ( !channel_khz || (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
      {
LABEL_27:
        v17 = -22;
LABEL_28:
        *(_QWORD *)v20 = v17;
LABEL_29:
        *(_QWORD *)v20 = 0;
        v34 = *(const char ***)(v39 + 64);
        do_trace_netlink_extack("Error fetching BSS for link");
        if ( v34 )
        {
          *v34 = "Error fetching BSS for link";
          v34[1] = v15;
          goto LABEL_39;
        }
LABEL_40:
        if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_45;
        goto LABEL_41;
      }
      v26 = (a3 >> 30) & 2;
      if ( (_DWORD)v19 == a3 )
        v26 = ((a3 >> 30) & 2) + 1;
      bss = _cfg80211_get_bss(a1 + 992, channel_khz, v21 + 4, a4, v40, 0, 2, v26 ^ 2u);
      if ( !bss )
      {
        v17 = -2;
        goto LABEL_28;
      }
      LODWORD(v17) = bss;
      *(_QWORD *)v20 = bss;
      if ( bss >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_29;
      v28 = (_WORD *)v12[42];
      if ( v28 )
      {
        v29 = (_DWORD)v28 + 4;
        *(_QWORD *)(v20 + 8) = v28 + 2;
        v30 = *v28 - 4;
        *(_QWORD *)(v20 + 16) = v30;
        if ( cfg80211_find_elem_match(242, v29, v30, nullptr, 0) )
        {
          v36 = v39;
          v37 = "cannot deal with fragmentation";
          goto LABEL_36;
        }
        v31 = *(_QWORD *)(v20 + 8);
        v32 = *(_DWORD *)(v20 + 16);
        s2[0] = 56;
        if ( cfg80211_find_elem_match(255, v31, v32, s2, 1u) )
        {
          v36 = v39;
          v37 = "cannot deal with non-inheritance";
LABEL_36:
          v34 = *(const char ***)(v36 + 64);
          do_trace_netlink_extack(v37);
          if ( v34 )
          {
            *v34 = v37;
            v34[1] = (const char *)v12[42];
LABEL_38:
            LODWORD(v17) = -22;
LABEL_39:
            v34[2] = nullptr;
            goto LABEL_40;
          }
          goto LABEL_42;
        }
      }
      *(_BYTE *)(v20 + 24) = v12[326] != 0;
      v33 = (*(unsigned __int16 *)v15 + 3) & 0x1FFFC;
      v14 -= v33;
      v15 += v33;
      if ( v14 <= 3 )
        goto LABEL_25;
    }
    v35 = *(_QWORD *)(v39 + 64);
    if ( v35 )
    {
      *(_QWORD *)(v35 + 8) = v15;
      v34 = *(const char ***)(v39 + 64);
      goto LABEL_38;
    }
LABEL_42:
    LODWORD(v17) = -22;
    if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_45;
    goto LABEL_41;
  }
LABEL_25:
  LODWORD(v17) = 0;
  if ( (unsigned __int64)v12 <= 0xFFFFFFFFFFFFF000LL )
LABEL_41:
    kfree(v12);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
