__int64 __fastcall wiphy_register(__int64 a1)
{
  __int64 v1; // x9
  int v2; // w8
  __int64 v4; // x20
  __int64 v5; // x10
  char v6; // w9
  unsigned int v7; // w11
  unsigned int v8; // w10
  int v9; // w9
  _DWORD *v10; // x9
  int v11; // w10
  int *v12; // x9
  int v13; // w11
  int v14; // w9
  _QWORD *v16; // x9
  int *v17; // x9
  __int16 v18; // w10
  int v19; // w9
  int v20; // w8
  int v21; // w21
  __int64 v22; // x22
  __int64 v23; // x23
  __int64 result; // x0
  __int64 v25; // x8
  char v26; // w17
  char v27; // w10
  __int64 *v28; // x15
  int v29; // w16
  __int64 v30; // x0
  __int64 v31; // x16
  __int64 v32; // x17
  __int64 v33; // x16
  unsigned __int16 *v34; // x17
  int v35; // w15
  unsigned __int16 *v36; // x17
  __int64 v37; // x0
  int v38; // w1
  __int64 v39; // x8
  _QWORD *v40; // x9
  _DWORD *v41; // x8
  int v42; // w9
  unsigned int v43; // w8
  __int64 v44; // x0
  unsigned int v45; // w0
  unsigned int v46; // w20
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  unsigned int v50; // w8
  int v51; // w9
  __int64 v52; // x10
  unsigned __int64 v53; // x13
  int v54; // w14
  int v55; // w15
  __int64 v56; // x16
  _QWORD v57[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v58; // [xsp+18h] [xbp-38h]
  __int64 v59; // [xsp+20h] [xbp-30h]
  __int64 v60; // [xsp+28h] [xbp-28h]
  __int64 v61; // [xsp+30h] [xbp-20h]
  __int64 v62; // [xsp+38h] [xbp-18h]
  __int64 v63; // [xsp+40h] [xbp-10h]
  __int64 v64; // [xsp+48h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 248);
    v2 = *(unsigned __int16 *)(a1 + 96);
    if ( v1 && ((*(_DWORD *)v1 & 0x18) == 0x10 || !*(_DWORD *)v1 && !*(_DWORD *)(v1 + 4) && !*(_QWORD *)(v1 + 24)) )
      goto LABEL_155;
    v4 = a1 - 992;
    if ( (*(_BYTE *)(a1 + 111) & 0x10) != 0
      && (!*(_QWORD *)(*(_QWORD *)v4 + 768LL) || !*(_QWORD *)(*(_QWORD *)v4 + 776LL)) )
    {
      goto LABEL_155;
    }
    if ( (v2 & 0x1000) != 0 )
    {
      v16 = *(_QWORD **)v4;
      if ( !*(_QWORD *)(*(_QWORD *)v4 + 784LL) || !v16[99] || !v16[100] || !v16[101] || (*(_BYTE *)(a1 + 1400) & 1) == 0 )
        goto LABEL_155;
    }
    if ( (v2 & 0x20) != 0 )
      goto LABEL_155;
    v5 = *(_QWORD *)(a1 + 1432);
    if ( v5 )
    {
      v6 = *(_BYTE *)(v5 + 18);
      if ( (v6 & 1) == 0 )
        goto LABEL_155;
      if ( (*(_BYTE *)(v5 + 18) & 6) == 0 )
        goto LABEL_155;
      v7 = *(_DWORD *)(v5 + 8);
      if ( !v7 )
        goto LABEL_155;
      v8 = *(_DWORD *)(v5 + 12);
      if ( !v8 || v7 >= 0x20 || (v6 & 0x60) != 0 && v7 <= 0xF )
        goto LABEL_155;
      if ( v8 >= 0x100 )
        goto LABEL_155;
    }
    v9 = *(_DWORD *)(a1 + 104);
    if ( (v9 & 0x80) != 0 && (v9 & 0x1B) != 0 )
      goto LABEL_155;
    v10 = *(_DWORD **)(a1 + 1360);
    if ( v10 && (!*v10 || !v10[2]) )
    {
      v11 = v10[4];
      if ( !v11 || v11 > v10[3] )
        goto LABEL_155;
    }
    if ( *(_DWORD *)(a1 + 124) && (*(_BYTE *)(a1 + 102) & 2) == 0 )
      goto LABEL_155;
    v12 = *(int **)(a1 + 64);
    if ( v12 )
    {
      if ( !*(_WORD *)(a1 + 94) )
        goto LABEL_155;
      if ( *(_DWORD *)(a1 + 48) | *(unsigned __int16 *)(a1 + 52) )
      {
        v13 = *v12;
        v14 = *((unsigned __int16 *)v12 + 2);
        if ( *(_DWORD *)(a1 + 48) != v13 || *(unsigned __int16 *)(a1 + 52) != v14 )
          goto LABEL_155;
      }
    }
    if ( *(_WORD *)(a1 + 98) && ((*(_BYTE *)(a1 + 102) & 2) == 0 || !*(_QWORD *)(*(_QWORD *)v4 + 672LL))
      || (*(_DWORD *)(a1 + 1396) & 0xFFFFFFF1) != 0
      || (*(_BYTE *)(a1 + 114) & 1) != 0 && (!*(_QWORD *)(*(_QWORD *)v4 + 840LL) || !*(_QWORD *)(*(_QWORD *)v4 + 848LL))
      || (*(_BYTE *)(a1 + 101) & 0x20) == 0 && *(_QWORD *)(*(_QWORD *)v4 + 376LL) )
    {
      goto LABEL_155;
    }
    v17 = *(int **)(a1 + 64);
    if ( v17 )
    {
      v18 = *((_WORD *)v17 + 2);
      v19 = *v17;
      *(_WORD *)(a1 + 52) = v18;
      *(_DWORD *)(a1 + 48) = v19;
    }
    if ( !v2 )
      __break(0x800u);
    v20 = v2 & 0x1FDE;
    if ( v20 != *(unsigned __int16 *)(a1 + 96) )
    {
      __break(0x800u);
      *(_WORD *)(a1 + 96) = v20;
    }
    v21 = *(_DWORD *)(a1 + 1496);
    if ( v21 >= 1 )
    {
      v22 = 0;
      v23 = 0;
      do
      {
        result = wiphy_verify_iface_combinations(
                   a1,
                   *(_QWORD *)(*(_QWORD *)(a1 + 1504) + v22 + 16),
                   *(unsigned int *)(*(_QWORD *)(a1 + 1504) + v22 + 24),
                   0);
        if ( (_DWORD)result )
          goto LABEL_157;
        ++v23;
        v22 += 32;
      }
      while ( v23 < *(int *)(a1 + 1496) );
    }
    result = wiphy_verify_iface_combinations(a1, *(_QWORD *)(a1 + 80), *(unsigned int *)(a1 + 88), v21 != 0);
    if ( !(_DWORD)result )
    {
      v25 = 0;
      v26 = 0;
      v27 = cfg80211_disable_40mhz_24ghz;
      do
      {
        v28 = *(__int64 **)(a1 + 328 + 8 * v25);
        if ( v28 )
        {
          v29 = *((_DWORD *)v28 + 5);
          *((_DWORD *)v28 + 4) = v25;
          if ( !v29 || (_DWORD)v25 != 2 && (_DWORD)v25 != 4 && !*((_DWORD *)v28 + 6) )
            goto LABEL_155;
          if ( v25 == 3 )
          {
            if ( (*((_BYTE *)v28 + 30) & 1) != 0 || *((_BYTE *)v28 + 52) == 1 )
              goto LABEL_155;
          }
          else if ( !v25 && (v27 & 1) != 0 && *((_BYTE *)v28 + 30) == 1 )
          {
            *((_WORD *)v28 + 14) &= 0xFFBDu;
          }
          if ( *((int *)v28 + 6) > 32 )
            goto LABEL_155;
          if ( v29 >= 1 )
          {
            v30 = *v28;
            v31 = 0;
            v32 = 0;
            do
            {
              *(_DWORD *)(v30 + v31 + 32) = *(_DWORD *)(v30 + v31 + 12);
              *(_DWORD *)(*v28 + v31 + 36) = 0x7FFFFFFF;
              *(_DWORD *)(*v28 + v31 + 40) = *(_DWORD *)(*v28 + v31 + 20);
              *(_DWORD *)(*v28 + v31) = v25;
              v30 = *v28;
              if ( *(unsigned __int16 *)(*v28 + v31 + 8) >= 0x3E8u )
                goto LABEL_155;
              ++v32;
              v31 += 64;
            }
            while ( v32 < *((int *)v28 + 5) );
          }
          v33 = *((unsigned __int16 *)v28 + 46);
          if ( *((_WORD *)v28 + 46) )
          {
            v34 = (unsigned __int16 *)v28[12];
            v35 = *v34;
            if ( !*v34
              || *((_BYTE *)v34 + 2) != 1
              || (v35 & 0xFDF7) != 0 && (v35 & 0x208) != 0 && (*((_BYTE *)v34 + 59) & 1) != 0 )
            {
              goto LABEL_155;
            }
            if ( (_DWORD)v33 != 1 )
            {
              v36 = v34 + 64;
              v37 = v33 - 1;
              while ( 1 )
              {
                v38 = *v36;
                if ( !*v36
                  || (v38 & v35) != 0
                  || (v36[1] & 1) == 0
                  || (v38 & 0xFDF7) != 0 && (v38 & 0x208) != 0 && (*((_BYTE *)v36 + 59) & 1) != 0 )
                {
                  goto LABEL_155;
                }
                --v37;
                v35 |= v38;
                v36 += 64;
                if ( !v37 )
                  goto LABEL_103;
              }
            }
            v26 = 1;
          }
          else
          {
LABEL_103:
            v26 = 1;
            if ( v25 == 3 && !(_DWORD)v33 )
              goto LABEL_155;
          }
        }
        ++v25;
      }
      while ( v25 != 6 );
      if ( (v26 & 1) == 0 )
        goto LABEL_155;
      v39 = *(unsigned int *)(a1 + 1384);
      if ( (int)v39 >= 1 )
      {
        v40 = (_QWORD *)(*(_QWORD *)(a1 + 1368) + 32LL);
        while ( *v40 && (*(v40 - 2) || *(v40 - 1)) )
        {
          --v39;
          v40 += 7;
          if ( !v39 )
            goto LABEL_117;
        }
LABEL_155:
        __break(0x800u);
LABEL_156:
        result = 4294967274LL;
        goto LABEL_157;
      }
LABEL_117:
      v41 = *(_DWORD **)(a1 + 248);
      if ( v41 )
      {
        if ( v41[1] )
        {
          v42 = v41[3];
          if ( !v42 || v42 > v41[2] )
            goto LABEL_155;
        }
      }
      v43 = *(unsigned __int16 *)(a1 + 1490);
      if ( v43 == 1 )
        goto LABEL_156;
      if ( *(_WORD *)(a1 + 1490) )
      {
        if ( v43 > 0xA )
          goto LABEL_156;
      }
      else
      {
        *(_WORD *)(a1 + 1490) = 2;
      }
      v44 = ieee80211_set_bitrate_flags(a1);
      *(_DWORD *)(a1 + 108) |= 0x80u;
      rtnl_lock(v44);
      mutex_lock(a1);
      v45 = device_add(a1 + 392);
      if ( v45 )
      {
        v46 = v45;
        v47 = mutex_unlock(a1);
        rtnl_unlock(v47);
LABEL_154:
        result = v46;
        goto LABEL_157;
      }
      list_add_rcu(a1 - 984, &cfg80211_rdev_list);
      v48 = *(_QWORD *)(a1 + 504);
      ++cfg80211_rdev_list_generation;
      if ( !v48 )
        v48 = *(_QWORD *)(a1 + 392);
      *(_QWORD *)(a1 + 1312) = debugfs_create_dir(v48, ieee80211_debugfs_dir);
      nl80211_notify_wiphy(a1 - 992, 3);
      mutex_unlock(a1);
      v49 = wiphy_regulatory_register(a1);
      if ( (*(_BYTE *)(a1 + 104) & 1) != 0 )
      {
        v58 = 0;
        v59 = 0;
        v50 = *(_DWORD *)(a1 - 892);
        v62 = 0;
        v63 = 0;
        v58 = v50 | 0x200000000LL;
        v60 = 0;
        v61 = 0;
        v57[0] = 0;
        v57[1] = 0;
        WORD2(v59) = 14649;
        v49 = nl80211_common_reg_change_event(36, v57);
      }
      if ( *(_BYTE *)(a1 + 296) )
      {
        v51 = *(_DWORD *)(a1 + 312);
        if ( v51 )
        {
          v52 = *(_QWORD *)(a1 + 304);
          if ( v52 )
          {
            v53 = 0;
            while ( 1 )
            {
              if ( v53 >= *(unsigned __int8 *)(v52 + 24) )
                v54 = 0;
              else
                v54 = *(unsigned __int8 *)(*(_QWORD *)(v52 + 8) + v53);
              if ( v51 != 1 )
              {
                v55 = 1;
                while ( 1 )
                {
                  v56 = v52 + 32LL * v55;
                  if ( v53 >= *(unsigned __int8 *)(v56 + 24) )
                    break;
                  ++v55;
                  v54 = (unsigned __int8)(*(_BYTE *)(*(_QWORD *)(v56 + 8) + v53) & v54);
                  if ( v51 == v55 )
                    goto LABEL_150;
                }
                v54 = 0;
              }
LABEL_150:
              if ( (*(unsigned __int8 *)(*(_QWORD *)(a1 + 280) + v53) & ~v54) != 0 )
                break;
              if ( ++v53 == *(unsigned __int8 *)(a1 + 296) )
                goto LABEL_152;
            }
            __break(0x800u);
          }
        }
      }
LABEL_152:
      *(_BYTE *)(a1 + 1304) = 1;
      rtnl_unlock(v49);
      result = rfkill_register(*(_QWORD *)(a1 + 1480));
      if ( (_DWORD)result )
      {
        v46 = result;
        rfkill_destroy(*(_QWORD *)(a1 + 1480));
        *(_QWORD *)(a1 + 1480) = 0;
        wiphy_unregister(a1);
        goto LABEL_154;
      }
    }
LABEL_157:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return ((__int64 (*)(void))list_add_rcu)();
}
