__int64 __fastcall ieee80211_tx_status_ext(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24
  int *v5; // x25
  __int64 v7; // x22
  __int64 v8; // x20
  __int64 v9; // x23
  _QWORD *v10; // x10
  __int64 *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x8
  int v14; // w8
  char *v15; // x9
  unsigned int v16; // w27
  __int16 v17; // w8
  unsigned int v18; // w10
  int v19; // w8
  unsigned int v20; // w26
  unsigned int v21; // w21
  char v22; // w28
  __int64 v23; // x24
  int *v24; // x24
  __int64 v25; // x27
  unsigned __int16 *v26; // x8
  int v27; // w9
  __int16 v28; // w25
  int v30; // w28
  _QWORD *v31; // x12
  int v32; // w9
  __int64 v33; // x11
  char *v34; // x9
  char v35; // w10
  int v36; // w10
  __int64 v37; // x9
  unsigned __int64 v38; // x23
  __int64 v39; // x2
  __int64 *v40; // x1
  int v41; // w10
  char v42; // w8
  __int64 v43; // x9
  __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned int v46; // w2
  __int64 v47; // x8
  __int64 v48; // x9
  __int64 v49; // x0
  __int64 v50; // x1
  __int64 v51; // x8
  unsigned __int64 v52; // x9
  __int64 *v53; // x10
  __int16 v54; // w9
  __int64 v55; // x8
  __int64 v56; // x8
  unsigned __int16 *v57; // x8
  int v58; // w10
  __int64 v59; // x10
  __int64 v60; // x2
  __int64 v61; // x10
  __int64 v62; // x8
  __int64 v63; // x1
  __int64 v64; // x2
  __int64 v65; // x3
  __int64 (__fastcall *v66)(_QWORD); // x8
  _BOOL8 v67; // x3
  unsigned __int64 v73; // x11

  v4 = *(_QWORD *)a2;
  v5 = *(int **)(a2 + 8);
  v7 = *(_QWORD *)(a2 + 16);
  v8 = result;
  if ( !*(_QWORD *)a2 )
  {
    v9 = 0;
    if ( v7 )
      goto LABEL_5;
LABEL_10:
    if ( !*(_QWORD *)(a2 + 8) )
      return result;
    goto LABEL_11;
  }
  v9 = v4 - 2688;
  if ( *(_BYTE *)(a2 + 40) )
  {
    v10 = (_QWORD *)(v4 - 292);
    v11 = (__int64 *)(*(_QWORD *)(a2 + 24) + 16LL * ((unsigned int)*(unsigned __int8 *)(a2 + 40) - 1));
    v12 = *(__int64 *)((char *)v11 + 6);
    v13 = *v11;
    *(_QWORD *)((char *)v10 + 6) = v12;
    *v10 = v13;
  }
  if ( !v7 )
    goto LABEL_10;
LABEL_5:
  v14 = *(_DWORD *)(v7 + 44) >> 19;
  a4 = v14 & 0xFFC;
  if ( (v14 & 0xFFC) != 0 )
  {
    result = ieee80211_sta_update_pending_airtime(result, v9, *(_BYTE *)(v7 + 124), v14 & 0xFFC, 1);
    *(_DWORD *)(v7 + 44) &= 0x801FFFFF;
  }
  if ( !*(_QWORD *)(a2 + 8) )
  {
LABEL_50:
    result = ieee80211_report_used_skb(v8, v7, 0, *(_QWORD *)(a2 + 32));
    goto LABEL_51;
  }
LABEL_11:
  v15 = (char *)(v5 + 2);
  v16 = *v5;
  if ( (*v5 & 0x440) == 0x40 )
  {
    v17 = *(_WORD *)((char *)v5 + 9);
    *((_BYTE *)v5 + 8) = -1;
    *(_WORD *)((char *)v5 + 9) = v17 & 0xFFE0;
LABEL_18:
    v19 = -1;
    v20 = -1;
    goto LABEL_31;
  }
  if ( *v15 < 0 )
    goto LABEL_18;
  v18 = *(unsigned __int8 *)(v8 + 134);
  if ( !*(_BYTE *)(v8 + 134) )
  {
    v20 = -1;
    v19 = -1;
    goto LABEL_20;
  }
  v15 = (char *)v5 + 11;
  v19 = (*(_WORD *)((_BYTE *)v5 + 9) & 0x1F) - 1;
  if ( *((char *)v5 + 11) < 0 )
  {
    v20 = 0;
  }
  else
  {
    if ( v18 == 1 )
    {
      v20 = 0;
LABEL_20:
      *(_WORD *)(v15 + 1) &= 0xFFE0u;
      v16 = *v5;
      *v15 = -1;
      goto LABEL_31;
    }
    v15 = (char *)v5 + 14;
    v19 += v5[3] & 0x1F;
    if ( *((char *)v5 + 14) < 0 )
    {
      v20 = 1;
    }
    else
    {
      if ( v18 < 3 )
      {
        v20 = 1;
        goto LABEL_20;
      }
      v15 = (char *)v5 + 17;
      v19 += *(_WORD *)((_BYTE *)v5 + 15) & 0x1F;
      if ( *((char *)v5 + 17) < 0 )
      {
        v20 = 2;
      }
      else
      {
        if ( v18 == 3 )
        {
          v20 = 2;
          goto LABEL_20;
        }
        v20 = 3;
        v19 += *((_WORD *)v5 + 9) & 0x1F;
      }
    }
  }
LABEL_31:
  v21 = v19 & ~(v19 >> 31);
  if ( !v4 )
    goto LABEL_36;
  v22 = *((_BYTE *)v5 + 30);
  if ( (v16 & 0x80000200) == 0 )
    ++*(_QWORD *)(v9 + 2000);
  v23 = *(_QWORD *)(v9 + 80);
  *(_QWORD *)(v9 + 2008) += v21;
  if ( (*(_QWORD *)(v8 + 96) & 0x10000) != 0 )
  {
    if ( v7 && *(_DWORD *)(v23 + 4720) == 2 && (*((_BYTE *)v5 + 1) & 0x40) == 0 )
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ieee80211_sta_tx_notify)(
                 v23,
                 *(_QWORD *)(v7 + 224),
                 (v16 >> 9) & 1,
                 *((unsigned __int16 *)v5 + 14));
    if ( (v16 & 0x200) == 0 )
    {
      if ( (*(_QWORD *)(v9 + 216) & 4) != 0 )
      {
        if ( !v7 )
          return result;
        v49 = v8;
        v50 = v9;
        return ieee80211_handle_filtered_frame(v49, v50, v7, a4);
      }
      if ( (v16 & 0x80000000) == 0
        && (*(_QWORD *)(*(_QWORD *)(v9 + 72) + 96LL) & 0x2000000000LL) == 0
        && (*v5 & 0x440) != 0x40 )
      {
        v46 = *(_DWORD *)(v9 + 2016) + 1;
        *(_DWORD *)(v9 + 2016) = v46;
        if ( v46 >= 0x32 )
        {
          v47 = 2500;
          if ( !*(_BYTE *)(v9 + 2712) )
            v47 = 250;
          if ( v47 + *(_QWORD *)(v9 + 2024) - jiffies < 0 )
          {
            cfg80211_cqm_pktloss_notify(*(_QWORD *)(*(_QWORD *)(v9 + 80) + 1608LL), v9 + 2688);
            *(_DWORD *)(v9 + 2016) = 0;
          }
        }
      }
      goto LABEL_35;
    }
    v41 = *(_DWORD *)(v9 + 2016);
    *(_QWORD *)(v9 + 2304) = jiffies;
    if ( v41 )
      *(_DWORD *)(v9 + 2016) = 0;
    *(_QWORD *)(v9 + 2024) = jiffies;
    if ( *(_DWORD *)(v23 + 4720) == 2 && *(int *)(v23 + 2472) >= 1 )
    {
      *(_DWORD *)(v23 + 2472) = 0;
      if ( (v22 & 1) == 0 )
        goto LABEL_35;
    }
    else if ( (v22 & 1) == 0 )
    {
      goto LABEL_35;
    }
    v42 = v5[5];
    *(_BYTE *)(v9 + 2313) = 1;
    *(_BYTE *)(v9 + 2312) = v42;
    v43 = *(_QWORD *)(v9 + 2320);
    v44 = -v5[5];
    if ( v43 )
      v45 = (unsigned __int64)(7 * v43 + (v44 << 10)) >> 3;
    else
      v45 = v44 << 10;
    *(_QWORD *)(v9 + 2320) = v45;
  }
LABEL_35:
  result = ((__int64 (__fastcall *)(__int64, __int64))rate_control_tx_status)(v8, a2);
LABEL_36:
  if ( !v7 )
    return result;
  if ( (*((_BYTE *)v5 + 1) & 0x40) != 0 )
    goto LABEL_50;
  v24 = *(int **)(a2 + 8);
  v7 = *(_QWORD *)(a2 + 16);
  v25 = *(_QWORD *)a2;
  v26 = *(unsigned __int16 **)(v7 + 224);
  v27 = *v24;
  v28 = *v26;
  if ( *(_QWORD *)a2 )
  {
    if ( (v27 & 0x10000000) != 0 )
    {
      _X9 = (unsigned __int64 *)(v25 - 2472);
      __asm { PRFM            #0x11, [X9] }
      do
        v73 = __ldxr(_X9);
      while ( __stxr(v73 & 0xFFFFFFFFFFFBFFFFLL, _X9) );
    }
    v30 = *v24;
    v31 = (_QWORD *)(v25 - 2608);
    LOWORD(v32) = *v24;
    if ( (*(_QWORD *)(v8 + 96) & 1) != 0 )
    {
      LOWORD(v32) = *v24;
      if ( v20 != -1 )
      {
        LOWORD(v32) = *v24;
        if ( (*v26 & 0xC) == 8 )
        {
          v33 = v25 - 296;
          v34 = (char *)v24 + 3 * v20;
          v35 = v34[10];
          LOWORD(v34) = *((_WORD *)v34 + 4);
          *(_BYTE *)(v33 + 2) = v35;
          *(_WORD *)v33 = (_WORD)v34;
          v32 = *v24;
        }
      }
    }
    v36 = v28 & 0x8C;
    if ( (v32 & 0x800) != 0 && v36 == 136 )
    {
      v37 = 12;
      if ( (~*v26 & 0x300) == 0 )
        v37 = 15;
      LODWORD(v38) = v26[v37] & 0xF;
      ieee80211_send_bar(*v31 + 4720LL, (__int64)(v26 + 2), v26[v37] & 0xF, (v26[11] & 0xFFF0) + 16);
      v31 = (_QWORD *)(v25 - 2608);
    }
    else if ( v36 == 136 )
    {
      v48 = 12;
      if ( (~*v26 & 0x300) == 0 )
        v48 = 15;
      LODWORD(v38) = v26[v48] & 0xF;
    }
    else
    {
      LODWORD(v38) = 16;
    }
    if ( (v30 & 0x200) == 0 && (v28 & 0xFC) == 0x84 )
    {
      v51 = *(_QWORD *)(v7 + 224);
      v52 = *(unsigned __int16 *)(v51 + 16);
      if ( (v52 & 2) == 0 )
      {
        v38 = v52 >> 12;
        v53 = (__int64 *)(v25 + 8 * (v52 >> 12) - 1784);
        v54 = *(_WORD *)(v51 + 18);
        v55 = *v53;
        if ( *v53 )
        {
          *(_WORD *)(v55 + 154) = v54;
          *(_BYTE *)(v55 + 156) = 1;
        }
      }
    }
    v27 = *v24;
    if ( (*v24 & 0x100) == 0 )
    {
      if ( (v28 & 0x4C) == 8 )
      {
        v56 = v25 + 8LL * (unsigned int)v38;
        if ( (v30 & 0x80000200) == 0 )
          ++*(_QWORD *)(v56 - 520);
        *(_QWORD *)(v56 - 656) += v21;
        v27 = *v24;
      }
      if ( (v27 & 0x80) == 0 && (v30 & 0x200) != 0 )
      {
        v57 = *(unsigned __int16 **)(v7 + 224);
        v58 = *v57;
        if ( (v58 & 0x8C) == 0x88 )
        {
          _ZF = (~v58 & 0x300) == 0;
          v59 = 12;
          if ( _ZF )
            v59 = 15;
          v60 = v57[v59] & 0xF;
          v61 = *(_QWORD *)(v25 + 8 * v60 - 1784);
          if ( v61 && *(_BYTE *)(v61 + 156) == 1 )
          {
            *(_BYTE *)(v61 + 156) = 0;
            ieee80211_send_bar(*v31 + 4720LL, (__int64)(v57 + 2), v60, *(_WORD *)(v61 + 154));
            v27 = *v24;
          }
        }
      }
      goto LABEL_104;
    }
    v50 = v25 - 2688;
    v49 = v8;
    return ieee80211_handle_filtered_frame(v49, v50, v7, a4);
  }
LABEL_104:
  if ( (v28 & 0x107C) == 0x1048 && (v27 & 0x80) == 0 && (*(_QWORD *)(v8 + 96) & 0x10000) != 0 )
  {
    v62 = *(_QWORD *)(v8 + 5008);
    if ( v62 )
    {
      if ( !*(_QWORD *)(v8 + 4696) )
      {
        if ( (v27 & 0x200) != 0 )
          *(_DWORD *)(v62 + 2500) |= 0x100u;
        mod_timer(v8 + 5064, jiffies + 3LL);
      }
    }
  }
  result = ieee80211_report_used_skb(v8, v7, 0, *(_QWORD *)(a2 + 32));
  v66 = *(__int64 (__fastcall **)(_QWORD))(v7 + 96);
  if ( v66 )
  {
    if ( *((_DWORD *)v66 - 1) != 303786302 )
      __break(0x8228u);
    result = v66(v7);
    *(_QWORD *)(v7 + 96) = 0;
    *(_QWORD *)(v7 + 24) = 0;
  }
  else if ( *(_QWORD *)(v7 + 24) )
  {
    __break(0x800u);
    return ieee80211_handle_filtered_frame(result, v63, v64, v65);
  }
  if ( (*(_BYTE *)v24 & 0x80) != 0 )
  {
    if ( *(_DWORD *)(v8 + 1320) )
    {
LABEL_125:
      v67 = 1;
      return ieee80211_tx_monitor(v8, v7, v21, v67, a2);
    }
  }
  else
  {
    v67 = (v28 & 0xC) != 8;
    if ( *(_DWORD *)(v8 + 1320) )
      return ieee80211_tx_monitor(v8, v7, v21, v67, a2);
    if ( (v28 & 0xC) == 8 )
      goto LABEL_51;
  }
  if ( *(_DWORD *)(v8 + 1324) )
    goto LABEL_125;
LABEL_51:
  v39 = *(_QWORD *)(a2 + 48);
  if ( !v39 )
    return consume_skb(v7);
  v40 = *(__int64 **)(v39 + 8);
  if ( v7 == v39 || v40 == (__int64 *)v7 || *v40 != v39 )
    return _list_add_valid_or_report(v7, v40);
  *(_QWORD *)(v39 + 8) = v7;
  *(_QWORD *)v7 = v39;
  *(_QWORD *)(v7 + 8) = v40;
  *v40 = v7;
  return result;
}
