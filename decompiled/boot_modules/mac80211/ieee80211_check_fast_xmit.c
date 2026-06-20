__int64 __fastcall ieee80211_check_fast_xmit(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x1
  unsigned __int64 v6; // x0
  __int64 v7; // x1
  __int64 lock; // x0
  _DWORD **v9; // x8
  int v10; // w8
  __int16 v11; // w10
  __int16 v12; // w11
  int v13; // w9
  __int16 v14; // w9
  __int16 v15; // w10
  int v16; // w8
  __int16 v17; // w8
  unsigned int v18; // w9
  char v19; // w8
  unsigned __int64 v20; // x21
  __int64 v21; // x8
  __int64 v22; // x8
  __int16 v23; // w9
  int v24; // w9
  __int16 v25; // w10
  int v26; // w8
  unsigned __int64 v27; // x8
  unsigned int v28; // w9
  unsigned int v29; // w21
  __int64 v30; // x0
  __int64 v31; // x8
  int v32; // w9
  __int16 v33; // w8
  int v34; // w10
  int v35; // w10
  unsigned __int64 v36; // x10
  __int64 v37; // x10
  int v38; // w1
  __int16 v39; // w10
  char v40; // w11
  unsigned int v41; // w11
  char *v42; // x10
  __int16 v43; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v45; // x21
  __int64 v46; // [xsp+0h] [xbp-60h] BYREF
  __int64 v47; // [xsp+8h] [xbp-58h] BYREF
  __int64 v48; // [xsp+10h] [xbp-50h]
  __int128 v49; // [xsp+18h] [xbp-48h]
  __int64 v50; // [xsp+28h] [xbp-38h]
  __int64 v51; // [xsp+30h] [xbp-30h]
  __int64 v52; // [xsp+38h] [xbp-28h]
  __int64 v53; // [xsp+40h] [xbp-20h]
  __int64 v54; // [xsp+48h] [xbp-18h]
  __int64 v55; // [xsp+50h] [xbp-10h]
  __int64 v56; // [xsp+58h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 72);
  v1 = *(_QWORD *)(result + 80);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v49 = 0u;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  if ( (*(_QWORD *)(v2 + 96) & 0x8000) == 0 )
    goto LABEL_16;
  v3 = result;
  v4 = raw_spin_lock_bh(result + 148);
  if ( (*(_QWORD *)(v2 + 96) & 0x100) != 0 && (*(_QWORD *)(v2 + 96) & 0x400) == 0 && *(_DWORD *)(v1 + 4720) == 2
    || (*(_QWORD *)(v3 + 216) & 8) == 0
    || *(_BYTE *)(v3 + 204) != 1
    || (*(_QWORD *)(v3 + 216) & 4) != 0
    || (*(_QWORD *)(v3 + 216) & 0x200) != 0
    || (*(_QWORD *)(v3 + 216) & 0x2000000) != 0
    || (*(_QWORD *)(v3 + 216) & 0x40) != 0
    || *(_WORD *)(v1 + 1888)
    || *(_DWORD *)(*(_QWORD *)(v2 + 72) + 200LL) != -1 && (*(_QWORD *)(v2 + 96) & 0x4000000000LL) == 0 )
  {
    goto LABEL_12;
  }
  if ( *(_WORD *)(v1 + 5800) )
  {
    BYTE4(v47) = 0;
  }
  else
  {
    lock = _rcu_read_lock(v4, v5);
    v9 = *(_DWORD ***)(v1 + 5640);
    if ( !v9 )
      goto LABEL_84;
    BYTE4(v47) = **v9;
    _rcu_read_unlock(lock);
  }
  v10 = *(_DWORD *)(v1 + 4720);
  v6 = 0;
  if ( v10 > 2 )
  {
    if ( v10 != 3 )
    {
      if ( v10 != 4 )
        goto LABEL_13;
      if ( *(_BYTE *)(v1 + 81) == 1 )
      {
        v14 = *(_WORD *)(v3 + 2692);
        v15 = *(_WORD *)(v1 + 5846);
        *(_DWORD *)((char *)&v48 + 2) = *(_DWORD *)(v3 + 2688);
        v16 = *(_DWORD *)(v1 + 5842);
        HIWORD(v48) = v14;
        WORD2(v49) = v15;
        LODWORD(v49) = v16;
        goto LABEL_33;
      }
    }
    v19 = *(_BYTE *)(v3 + 2715);
    BYTE2(v47) = 4;
    if ( (v19 & 1) != 0 || !*(_WORD *)(v1 + 5800) )
    {
      v24 = *(_DWORD *)(v1 + 5842);
      WORD2(v49) = *(_WORD *)(v1 + 5846);
      LODWORD(v49) = v24;
      goto LABEL_40;
    }
    v20 = *(unsigned __int8 *)(v3 + 1646);
    lock = _rcu_read_lock(0, v5);
    if ( v20 > 0xF )
      goto LABEL_86;
    v21 = *(_QWORD *)(v1 + 8 * v20 + 4568);
    if ( v21 )
    {
      v22 = *(_QWORD *)(v21 + 944);
      v23 = *(_WORD *)(v22 + 32);
      LODWORD(v22) = *(_DWORD *)(v22 + 28);
      WORD2(v49) = v23;
      LODWORD(v49) = v22;
      _rcu_read_unlock(lock);
LABEL_40:
      BYTE1(v47) = 16;
      v17 = 520;
      goto LABEL_50;
    }
    __break(0x800u);
LABEL_84:
    _rcu_read_unlock(lock);
    goto LABEL_12;
  }
  if ( v10 == 1 )
  {
    v25 = *(_WORD *)(v1 + 2350);
    *(_WORD *)((char *)&v47 + 1) = 1034;
    v26 = *(_DWORD *)(v1 + 2346);
    WORD5(v49) = v25;
    *(_DWORD *)((char *)&v49 + 6) = v26;
    v17 = 8;
    goto LABEL_50;
  }
  if ( v10 != 2 )
    goto LABEL_13;
  if ( (*(_QWORD *)(v3 + 216) & 0x800) != 0 )
  {
    v27 = *(unsigned __int16 *)(v3 + 2872);
    *(_WORD *)((char *)&v47 + 1) = 1034;
    v28 = __clz(__rbit64(v27));
    if ( (_DWORD)v27 )
      v29 = v28;
    else
      v29 = 0;
    v30 = _rcu_read_lock(0, v5);
    if ( v29 < 0x10 )
    {
      v31 = *(_QWORD *)(v1 + 8LL * v29 + 4568);
      if ( v31 )
      {
        v32 = *(_DWORD *)(v31 + 536);
        v33 = *(_WORD *)(v31 + 540);
        *(_DWORD *)((char *)&v49 + 6) = v32;
        WORD5(v49) = v33;
      }
      else
      {
        __break(0x800u);
      }
      _rcu_read_unlock(v30);
      v17 = 8;
      goto LABEL_50;
    }
LABEL_86:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v45 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_check_fast_xmit__alloc_tag;
    v6 = kmemdup_noprof(&v46, 88);
    *(_QWORD *)(StatusReg + 80) = v45;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(v1 + 2524) )
  {
    v11 = *(_WORD *)(v1 + 4156);
    v12 = *(_WORD *)(v1 + 5846);
    *(_DWORD *)((char *)&v48 + 2) = *(_DWORD *)(v1 + 4152);
    v13 = *(_DWORD *)(v1 + 5842);
    HIWORD(v48) = v11;
    WORD2(v49) = v12;
    LODWORD(v49) = v13;
LABEL_33:
    v17 = 776;
    v18 = 30;
    *(_WORD *)((char *)&v47 + 1) = 4120;
    goto LABEL_51;
  }
  v34 = *(_DWORD *)(v1 + 4802);
  HIWORD(v48) = *(_WORD *)(v1 + 4806);
  *(_DWORD *)((char *)&v48 + 2) = v34;
  v17 = 264;
  *(_WORD *)((char *)&v47 + 1) = 4106;
LABEL_50:
  v18 = 24;
LABEL_51:
  v35 = *(unsigned __int8 *)(v3 + 2698);
  LOBYTE(v47) = v18;
  if ( v35 == 1 )
  {
    v18 += 2;
    v17 |= 0x80u;
    LOBYTE(v47) = v18;
  }
  v36 = *(unsigned __int8 *)(v3 + 120);
  if ( v36 > 4 )
    goto LABEL_86;
  v37 = *(_QWORD *)(v3 + 8 * v36 + 88);
  v46 = v37;
  if ( !v37 )
  {
    v37 = *(_QWORD *)(v1 + 1928);
    v46 = v37;
    if ( !v37 )
      goto LABEL_81;
  }
  if ( (*(_DWORD *)(v37 + 40) & 3) == 1 )
  {
    v38 = *(_DWORD *)(v37 + 544);
    v39 = *(_WORD *)(v37 + 552);
    if ( v38 <= 1027076 )
    {
      switch ( v38 )
      {
        case 1027073:
          goto LABEL_75;
        case 1027074:
          if ( (v39 & 0x106) == 0 )
          {
            v41 = v18 + 8;
            goto LABEL_77;
          }
          goto LABEL_12;
        case 1027076:
          goto LABEL_71;
      }
    }
    else
    {
      v40 = v38 - 6;
      if ( (unsigned int)(v38 - 1027078) <= 7 )
      {
        if ( ((1 << v40) & 0xE1) != 0 )
        {
          _warn_printk("management cipher suite 0x%x enabled for data\n", v38);
          v6 = 0;
          __break(0x800u);
          goto LABEL_13;
        }
        if ( ((1 << v40) & 0xC) != 0 )
        {
          if ( (v39 & 2) != 0 )
          {
LABEL_67:
            BYTE3(v47) = v18;
            goto LABEL_73;
          }
LABEL_72:
          if ( (v39 & 0x20) == 0 )
          {
LABEL_80:
            v17 |= 0x4000u;
LABEL_81:
            HIWORD(v47) = v17;
            v42 = (char *)&v47 + v18 + 6;
            v43 = *((_WORD *)&rfc1042_header + 2);
            LOBYTE(v47) = v18 + 6;
            *(_DWORD *)v42 = rfc1042_header;
            *((_WORD *)v42 + 2) = v43;
            v6 = kmemdup_noprof(&v46, 88);
            goto LABEL_13;
          }
LABEL_73:
          v18 += 8;
          goto LABEL_80;
        }
        if ( v38 == 1027082 )
        {
LABEL_71:
          if ( (v39 & 2) != 0 )
            goto LABEL_67;
          goto LABEL_72;
        }
      }
      if ( v38 == 1027077 )
      {
LABEL_75:
        if ( (v39 & 2) == 0 )
        {
          v41 = v18 + 4;
LABEL_77:
          if ( (v39 & 0x20) != 0 )
            v18 = v41;
          goto LABEL_80;
        }
        goto LABEL_12;
      }
    }
    if ( (v39 & 2) != 0 )
    {
      v6 = 0;
      __break(0x800u);
      goto LABEL_13;
    }
    goto LABEL_80;
  }
LABEL_12:
  v6 = 0;
LABEL_13:
  v7 = *(_QWORD *)(v3 + 152);
  atomic_store(v6, (unsigned __int64 *)(v3 + 152));
  if ( v7 )
    kvfree_call_rcu(v7 + 72, v7);
  result = raw_spin_unlock_bh(v3 + 148);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
