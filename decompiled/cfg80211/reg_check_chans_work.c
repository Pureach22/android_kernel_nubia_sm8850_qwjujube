__int64 __fastcall reg_check_chans_work(__int64 a1)
{
  __int64 v1; // x0
  __int64 is_locked; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  _UNKNOWN **v5; // x20
  __int64 v6; // x19
  _UNKNOWN **v7; // x24
  _UNKNOWN **v8; // x28
  _QWORD *v9; // x8
  int v10; // w20
  __int64 v11; // x22
  _DWORD *v12; // x25
  _QWORD *v13; // x21
  __int64 *v14; // x8
  void *v15; // x9
  void *v16; // x10
  void *v17; // x8
  __int64 v18; // x11
  __int64 v19; // x23
  _DWORD *v20; // x8
  void *v21; // x8
  __int64 v22; // x10
  void *v23; // x11
  void *v24; // x8
  __int64 v25; // x10
  void *v26; // x11
  __int64 result; // x0
  _QWORD *v28; // [xsp+10h] [xbp-60h]
  __int64 v29; // [xsp+18h] [xbp-58h]
  __int64 v30; // [xsp+20h] [xbp-50h]
  __int64 v31; // [xsp+38h] [xbp-38h] BYREF
  void *v32; // [xsp+40h] [xbp-30h]
  void *v33; // [xsp+48h] [xbp-28h]
  void *v34; // [xsp+50h] [xbp-20h]
  unsigned int v35[2]; // [xsp+5Ch] [xbp-14h] BYREF
  char v36; // [xsp+64h] [xbp-Ch]
  __int16 v37; // [xsp+65h] [xbp-Bh]
  char v38; // [xsp+67h] [xbp-9h]
  __int64 v39; // [xsp+68h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = rtnl_lock(a1);
  is_locked = rtnl_is_locked(v1);
  if ( !(_DWORD)is_locked && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_2 = 1;
    is_locked = _warn_printk(
                  "RTNL: assertion failed at %s (%d)\n",
                  "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                  166);
    __break(0x800u);
  }
  v5 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list == (_UNKNOWN *)&cfg80211_rdev_list )
  {
LABEL_58:
    result = rtnl_unlock(is_locked);
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v6 = (__int64)(v5 + 123);
      if ( v5 == (_UNKNOWN **)-984LL )
        break;
      mutex_lock(v5 + 123);
      v7 = (_UNKNOWN **)v5[290];
      v8 = v5 + 290;
      v28 = v5;
      if ( v7 != v5 + 290 )
      {
        v29 = (__int64)(v5 - 1);
        while ( 1 )
        {
          v33 = nullptr;
          v34 = nullptr;
          v31 = 0;
          v32 = nullptr;
          v9 = v7[2];
          if ( v9 )
          {
            v10 = *((_DWORD *)v7 - 2);
            if ( (v9[21] & 1) != 0 )
              break;
          }
LABEL_11:
          v7 = (_UNKNOWN **)*v7;
          if ( v7 == v8 )
            goto LABEL_6;
        }
        v11 = 0;
        v12 = v7 + 33;
        v13 = v7 + 48;
        v30 = (__int64)(v7 - 2);
        while ( 2 )
        {
          if ( v11 && !*((_WORD *)v7 + 728) )
            goto LABEL_11;
          if ( *((_WORD *)v7 + 728) && (((unsigned __int64)*((unsigned __int16 *)v7 + 728) >> v11) & 1) == 0 )
            goto LABEL_18;
          if ( v10 <= 6 )
          {
            if ( v10 <= 2 )
            {
              if ( v10 == 1 )
              {
                v14 = (__int64 *)(v7 + 34);
                if ( !*((_BYTE *)v7 + 340) )
                  goto LABEL_18;
                goto LABEL_16;
              }
              if ( v10 == 2 )
                goto LABEL_39;
            }
            else
            {
              if ( v10 == 3 )
                goto LABEL_46;
              if ( v10 == 4 || v10 == 6 )
                goto LABEL_18;
            }
          }
          else
          {
            if ( v10 <= 9 )
            {
              if ( v10 != 7 )
              {
                if ( v10 != 8 )
                {
LABEL_46:
                  if ( *(_DWORD *)v13 )
                  {
                    v21 = (void *)v13[4];
                    v22 = v13[1];
                    v23 = (void *)v13[2];
                    v33 = (void *)v13[3];
                    v34 = v21;
                    v31 = v22;
                    v32 = v23;
                    goto LABEL_54;
                  }
LABEL_18:
                  ++v11;
                  v13 += 9;
                  if ( v11 == 15 )
                    goto LABEL_11;
                  continue;
                }
LABEL_39:
                if ( !*v13 )
                  goto LABEL_18;
                v19 = *(_QWORD *)(*v13 + 112LL);
                if ( !v19 )
                  goto LABEL_18;
                if ( !*(_QWORD *)(*(_QWORD *)v29 + 648LL) )
                  goto LABEL_45;
                v20 = *(_DWORD **)(*(_QWORD *)v29 + 648LL);
                if ( *(v20 - 1) != 1219933324 )
                  __break(0x8228u);
                if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD, __int64 *))v20)(
                       v6,
                       v30,
                       (unsigned int)v11,
                       &v31) )
                {
LABEL_45:
                  cfg80211_chandef_create((__int64)&v31, v19, 0);
                }
LABEL_54:
                if ( ((1 << v10) & 0x288) == 0 )
                {
                  if ( ((1 << v10) & 0x104) != 0 && (cfg80211_chandef_usable(v6, (__int64)&v31, 1) & 1) == 0 )
                  {
LABEL_10:
                    cfg80211_leave(v29, v30);
                    goto LABEL_11;
                  }
                  goto LABEL_18;
                }
LABEL_17:
                v35[0] = v10;
                v35[1] = 0;
                v36 = 1;
                v37 = 0;
                v38 = 0;
                if ( (cfg80211_reg_check_beaconing(v6, (__int64)&v31, v35) & 1) == 0 )
                  goto LABEL_10;
                goto LABEL_18;
              }
              v14 = (__int64 *)(v7 + 38);
              if ( !*v12 )
                goto LABEL_18;
LABEL_16:
              v16 = (void *)v14[2];
              v15 = (void *)v14[3];
              v18 = *v14;
              v17 = (void *)v14[1];
              v33 = v16;
              v34 = v15;
              v31 = v18;
              v32 = v17;
              goto LABEL_17;
            }
            switch ( v10 )
            {
              case 10:
                goto LABEL_18;
              case 11:
                if ( *(_QWORD *)v12 )
                {
                  v24 = v7[36];
                  v25 = *(_QWORD *)v12;
                  v26 = v7[34];
                  v33 = v7[35];
                  v34 = v24;
                  v31 = v25;
                  v32 = v26;
                }
                goto LABEL_18;
              case 12:
                goto LABEL_18;
            }
          }
          break;
        }
        __break(0x800u);
        if ( (unsigned int)v10 <= 9 )
          goto LABEL_54;
        goto LABEL_18;
      }
LABEL_6:
      is_locked = mutex_unlock(v6);
      v5 = (_UNKNOWN **)*v28;
      if ( (_UNKNOWN **)*v28 == &cfg80211_rdev_list )
        goto LABEL_58;
    }
    __break(0x800u);
    return reg_rule_to_chan_bw_flags(is_locked, v3, v4);
  }
  return result;
}
