__int64 __fastcall ieee80211_queue_skb(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  int v4; // w8
  int v6; // w8
  __int16 v7; // w8
  __int64 **v8; // x8
  __int64 *v9; // x20
  __int64 result; // x0
  __int64 *v11; // x24
  __int64 *v12; // x21
  unsigned int v13; // w21
  unsigned int v14; // w23
  __int64 *v15; // x22
  unsigned __int64 v16; // x0
  __int64 *v17; // x9
  __int64 *v18; // x10
  unsigned __int64 v19; // x11
  __int64 v20; // x9
  __int64 *v21; // x12
  __int64 *v22; // x8
  __int64 *v23; // x11
  int v24; // w13
  int v25; // w13
  _QWORD *v26; // x12
  __int64 *v27; // x0
  __int64 **v28; // x1
  unsigned int v29; // w8
  unsigned int v30; // w9
  bool v31; // w24
  __int64 v32; // x21
  void (__fastcall *v33)(__int64, __int64 *); // x8
  __int64 **v34; // x22
  unsigned __int64 v35; // x1
  unsigned int v36; // w8
  unsigned int v37; // w21
  __int64 *v38; // x28
  unsigned int next_bit; // w0
  __int64 *v40; // x8
  unsigned int v41; // w9
  __int64 *v42; // x10
  int v43; // w27
  int v44; // w21
  int v45; // w26
  unsigned int v46; // w8
  __int64 *v47; // x25
  int v48; // w24
  __int64 v49; // x1
  __int64 v50; // x8
  _QWORD *v51; // x9
  __int64 v52; // x10
  bool v53; // w13
  int v54; // w9
  int v55; // w9
  int v56; // w8
  _QWORD *v57; // x8
  __int64 *v58; // x9
  __int64 v59; // x11
  __int64 *v60; // x0
  __int64 *v61; // x1
  __int64 *v62; // x2
  __int64 *v64; // x20
  __int64 v65; // x22
  _QWORD *v66; // x9
  __int64 v67; // x9
  __int64 v68; // x1
  unsigned __int64 v75; // x9
  bool v76; // [xsp+Ch] [xbp-4h]

  v4 = *(_DWORD *)(a2 + 4720);
  if ( v4 == 6 )
    return 0;
  if ( v4 == 4 )
    a2 = *(_QWORD *)(a2 + 2032) - 2264LL;
  v6 = *((_DWORD *)a4 + 10);
  if ( (v6 & 0x20) != 0 || (a4[10] & 2) != 0 )
    return 0;
  if ( (v6 & 0x4000) == 0 )
  {
    v7 = *(_WORD *)a4[28];
    if ( (v7 & 0x4C) != 8 )
    {
      v64 = a4;
      if ( (v7 & 0xC) != 0 || (v65 = a2, (ieee80211_is_bufferable_mmpdu(a4) & 1) != 0) )
      {
        if ( !a3 )
          return 0;
      }
      else
      {
        result = 0;
        if ( !a3 || *(_DWORD *)(v65 + 4720) != 2 )
          return result;
      }
      if ( *(_BYTE *)(a3 + 204) == 1 )
      {
        v8 = (__int64 **)(a3 + 2864);
        a4 = v64;
        goto LABEL_12;
      }
      return 0;
    }
  }
  if ( !a3 )
  {
    v8 = (__int64 **)(a2 + 5856);
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a3 + 204) != 1 )
    return 0;
  v8 = (__int64 **)(a3 + 8 * (a4[18] & 0xF) + 2736);
LABEL_12:
  v9 = *v8;
  result = 0;
  if ( !*v8 )
    return result;
  v11 = v9 - 29;
  if ( v9 == &qword_E8 )
    return result;
  if ( (*((_BYTE *)a4 + 130) & 6) == 0 )
  {
    v12 = a4;
    result = _skb_get_hash_net(0, a4);
    a4 = v12;
  }
  v13 = *((_DWORD *)a4 + 38);
  v14 = *(_DWORD *)(a1 + 244);
  v15 = a4;
  v16 = ktime_get(result);
  if ( v15 )
  {
    v17 = v15;
    do
    {
      v18 = (__int64 *)*v17;
      *((_DWORD *)v17 + 21) = v16 >> 10;
      v17 = v18;
    }
    while ( v18 );
  }
  raw_spin_lock_bh(a1 + 240);
  if ( *((_BYTE *)v9 + 16) != 16 )
  {
    v19 = v14 * (unsigned __int64)v13;
    v20 = *(_QWORD *)(a1 + 208) + 56LL * HIDWORD(v19);
    v21 = *(__int64 **)v20;
    if ( *(_QWORD *)v20 )
    {
      v22 = v15;
      if ( v21 != v11 )
      {
        ++*((_DWORD *)v9 - 29);
        ++*(_DWORD *)(a1 + 276);
        v20 = (__int64)(v9 - 23);
        v21 = (__int64 *)*(v9 - 23);
      }
      if ( v21 )
      {
LABEL_25:
        if ( *(_DWORD *)(v20 + 48) )
          goto LABEL_26;
        if ( (__int64 *)v20 != v9 - 23 )
        {
          *(_QWORD *)(*(_QWORD *)(a1 + 216) + ((v19 >> 35) & 0x1FFFFFF8)) |= 1LL << SBYTE4(v19);
          *(_QWORD *)v20 = v11;
          if ( !v22 )
            goto LABEL_28;
          do
          {
LABEL_27:
            v23 = (__int64 *)*v22;
            *v22 = 0;
            *(_DWORD *)(v20 + 48) += *((_DWORD *)v22 + 28);
            v24 = *((_DWORD *)v9 - 31) + 1;
            *((_DWORD *)v9 - 32) += *((_DWORD *)v22 + 28);
            *((_DWORD *)v9 - 31) = v24;
            v25 = *(_DWORD *)(a1 + 264) + 1;
            *(_DWORD *)(a1 + 256) += *((_DWORD *)v22 + 58);
            *(_DWORD *)(a1 + 264) = v25;
            v26 = *(_QWORD **)(v20 + 32);
            *v22 = v20 + 24;
            v22[1] = (__int64)v26;
            *(_QWORD *)(v20 + 32) = v22;
            *v26 = v22;
            ++*(_DWORD *)(v20 + 40);
            v22 = v23;
          }
          while ( v23 );
          goto LABEL_28;
        }
        v60 = v9 - 25;
        if ( (__int64 *)*(v9 - 25) == v9 - 25 )
        {
          v61 = (__int64 *)(a1 + 224);
          v62 = *(__int64 **)(a1 + 224);
          if ( v62[1] != a1 + 224 || v60 == v61 || v62 == v60 )
          {
            _list_add_valid_or_report(v60, v61);
            v22 = v15;
            *(_QWORD *)v20 = v11;
            if ( !v15 )
              goto LABEL_28;
            goto LABEL_27;
          }
          v62[1] = (__int64)v60;
          *(v9 - 25) = (__int64)v62;
          *(v9 - 24) = (__int64)v61;
          *v61 = (__int64)v60;
        }
LABEL_26:
        *(_QWORD *)v20 = v11;
        if ( v22 )
          goto LABEL_27;
LABEL_28:
        v27 = (__int64 *)(v20 + 8);
        if ( *(_QWORD *)(v20 + 8) == v20 + 8 )
        {
          *(_DWORD *)(v20 + 52) = *(_DWORD *)(a1 + 260);
          v28 = (__int64 **)*(v9 - 28);
          if ( v27 == v11 || v28 == (__int64 **)v27 || *v28 != v11 )
          {
            _list_add_valid_or_report(v27, v28);
          }
          else
          {
            *(v9 - 28) = (__int64)v27;
            *(_QWORD *)(v20 + 8) = v11;
            *(_QWORD *)(v20 + 16) = v28;
            *v28 = v27;
          }
        }
        v30 = *(_DWORD *)(a1 + 252);
        v29 = *(_DWORD *)(a1 + 256);
        v31 = v29 > v30;
        if ( *(_DWORD *)(a1 + 264) <= *(_DWORD *)(a1 + 248) && v29 <= v30 )
          goto LABEL_35;
        v34 = (__int64 **)(a1 + 224);
        while ( 1 )
        {
          v35 = *(unsigned int *)(a1 + 244);
          v36 = 0;
          v37 = 0;
          v38 = nullptr;
          while ( 1 )
          {
            next_bit = find_next_bit(*(_QWORD *)(a1 + 216), v35, (int)v36);
            v35 = *(unsigned int *)(a1 + 244);
            if ( v35 <= next_bit )
              break;
            if ( *(_DWORD *)(*(_QWORD *)(a1 + 208) + 56LL * (int)next_bit + 48) > v37 )
            {
              v37 = *(_DWORD *)(*(_QWORD *)(a1 + 208) + 56LL * (int)next_bit + 48);
              v38 = (__int64 *)(*(_QWORD *)(a1 + 208) + 56LL * (int)next_bit);
            }
            v36 = next_bit + 1;
          }
          v40 = *v34;
          while ( v40 != (__int64 *)v34 )
          {
            v41 = *((_DWORD *)v40 + 16);
            v42 = v40 + 2;
            v40 = (__int64 *)*v40;
            if ( v41 > v37 )
            {
              v37 = v41;
              v38 = v42;
            }
          }
          if ( !v38 )
            goto LABEL_35;
          v76 = v31;
          v43 = 0;
          v44 = 0;
          v45 = 0;
          v46 = *((_DWORD *)v38 + 10) >> 1;
          v47 = v38 + 3;
          if ( v46 >= 0x20 )
            v46 = 32;
          if ( v46 <= 1 )
            v48 = 1;
          else
            v48 = v46;
          while ( 1 )
          {
            v49 = *v47;
            if ( (__int64 *)*v47 == v47 || !v49 )
              break;
            ++v45;
            --*((_DWORD *)v38 + 10);
            v50 = *(_QWORD *)v49;
            v51 = *(_QWORD **)(v49 + 8);
            *(_QWORD *)v49 = 0;
            *(_QWORD *)(v49 + 8) = 0;
            *(_QWORD *)(v50 + 8) = v51;
            *v51 = v50;
            v44 += *(_DWORD *)(v49 + 112);
            v43 += *(_DWORD *)(v49 + 232);
            ieee80211_free_txskb(a1, v49);
            if ( v48 == v45 )
            {
              v45 = v48;
              break;
            }
          }
          v52 = *v38;
          v53 = v76;
          v54 = *(_DWORD *)(*v38 + 108) - v45;
          *(_DWORD *)(v52 + 104) = *(_DWORD *)(*v38 + 104) - v44;
          *(_DWORD *)(v52 + 108) = v54;
          *((_DWORD *)v38 + 12) -= v44;
          v55 = *(_DWORD *)(a1 + 256) - v43;
          *(_DWORD *)(a1 + 264) -= v45;
          *(_DWORD *)(a1 + 256) = v55;
          if ( *((_DWORD *)v38 + 12) )
            goto LABEL_68;
          if ( (__int64 *)(v52 + 48) != v38 )
            break;
          v57 = *(_QWORD **)(v52 + 40);
          v58 = (__int64 *)(v52 + 32);
          if ( *v57 == v52 + 32 && (v59 = *v58, *(__int64 **)(*v58 + 8) == v58) )
          {
            *(_QWORD *)(v59 + 8) = v57;
            *v57 = v59;
          }
          else
          {
            _list_del_entry_valid_or_report(v52 + 32);
          }
          *(_QWORD *)(v52 + 32) = v52 + 32;
          *(_QWORD *)(v52 + 40) = v58;
          if ( !v45 )
            goto LABEL_35;
LABEL_69:
          ++*(_DWORD *)(*v38 + 112);
          ++*(_DWORD *)(a1 + 268);
          if ( v53 )
          {
            v31 = *(_DWORD *)(a1 + 256) > *(_DWORD *)(a1 + 252);
            ++*(_DWORD *)(a1 + 272);
          }
          else
          {
            v31 = 0;
          }
          if ( *(_DWORD *)(a1 + 264) <= *(_DWORD *)(a1 + 248) && !v31 )
            goto LABEL_35;
        }
        v56 = -1227133513 * (((__int64)v38 - *(_QWORD *)(a1 + 208)) >> 3);
        *(_QWORD *)(*(_QWORD *)(a1 + 216) + (((unsigned __int64)v56 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) &= ~(1LL << v56);
LABEL_68:
        if ( !v45 )
          goto LABEL_35;
        goto LABEL_69;
      }
    }
    else
    {
      v22 = v15;
    }
    ++*((_DWORD *)v9 - 28);
    goto LABEL_25;
  }
  *((_DWORD *)v15 + 20) |= 0x40u;
  v66 = (_QWORD *)*(v9 - 3);
  *v15 = (__int64)(v9 - 4);
  v15[1] = (__int64)v66;
  *(v9 - 3) = (__int64)v15;
  *v66 = v15;
  ++*((_DWORD *)v9 - 4);
LABEL_35:
  raw_spin_unlock_bh(a1 + 240);
  _ieee80211_schedule_txq(a1, v9, 1);
  if ( *(_BYTE *)(a1 + 1470) == 1 )
  {
    _X8 = (unsigned __int64 *)(v9 - 1);
    __asm { PRFM            #0x11, [X8] }
    do
      v75 = __ldxr(_X8);
    while ( __stxr(v75 | 8, _X8) );
  }
  else
  {
    v32 = *v9;
    if ( (*(_BYTE *)(*(_QWORD *)(*v9 - 3104) + 1471LL) & 1) == 0
      && (*(_DWORD *)(v32 - 3096) & 0x20) == 0
      && (drv_wake_tx_queue___already_done_1 & 1) == 0 )
    {
      v67 = *(_QWORD *)(v32 - 3112);
      drv_wake_tx_queue___already_done_1 = 1;
      if ( v67 )
        v68 = v67 + 296;
      else
        v68 = v32 - 3080;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v68);
      __break(0x800u);
    }
    if ( (*(_BYTE *)(v32 - 3096) & 0x20) != 0 )
    {
      v33 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(a1 + 464) + 752LL);
      if ( *((_DWORD *)v33 - 1) != -1212882962 )
        __break(0x8228u);
      v33(a1, v9);
    }
  }
  return 1;
}
