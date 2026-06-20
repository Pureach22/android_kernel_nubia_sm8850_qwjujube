__int64 __fastcall nl80211_dump_interface(__int64 a1, __int64 a2)
{
  int v4; // w22
  int v5; // w23
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w21
  __int64 is_locked; // x0
  unsigned int v10; // w21
  __int64 v11; // x8
  _QWORD *v12; // x26
  int v13; // w25
  int v14; // w28
  _QWORD *v15; // x22
  int v17; // [xsp+8h] [xbp-48h]
  int v18; // [xsp+Ch] [xbp-44h]
  _QWORD v19[8]; // [xsp+10h] [xbp-40h] BYREF

  v19[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 80);
  v5 = *(_DWORD *)(a2 + 88);
  v6 = rtnl_lock(a1);
  v7 = *(_QWORD *)(a2 + 96);
  if ( !v7 )
  {
    memset(&v19[1], 0, 48);
    v19[0] = -1;
    is_locked = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))nl80211_dump_wiphy_parse)(a1, a2, v19);
    if ( (_DWORD)is_locked )
    {
      v10 = is_locked;
      goto LABEL_32;
    }
    v8 = v19[0];
    v11 = LODWORD(v19[0]) + 1;
    if ( SLODWORD(v19[0]) < 0 )
      v11 = -1;
    *(_QWORD *)(a2 + 96) = v11;
    is_locked = rtnl_is_locked(is_locked);
    if ( (_DWORD)is_locked )
      goto LABEL_14;
    goto LABEL_12;
  }
  if ( v7 < 1 )
  {
    v8 = -1;
    is_locked = rtnl_is_locked(v6);
    if ( (_DWORD)is_locked )
      goto LABEL_14;
LABEL_12:
    if ( (for_each_rdev_check_rtnl___already_done_1 & 1) == 0 )
    {
      for_each_rdev_check_rtnl___already_done_1 = 1;
      is_locked = _warn_printk(
                    "RTNL: assertion failed at %s (%d)\n",
                    "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                    166);
      __break(0x800u);
    }
    goto LABEL_14;
  }
  v8 = v7 - 1;
  is_locked = rtnl_is_locked(v6);
  if ( !(_DWORD)is_locked )
    goto LABEL_12;
LABEL_14:
  v12 = cfg80211_rdev_list;
  if ( cfg80211_rdev_list == (_UNKNOWN *)&cfg80211_rdev_list )
  {
    v13 = 0;
    v14 = 0;
    goto LABEL_31;
  }
  v13 = 0;
  v14 = 0;
  v17 = v8;
  v18 = v4;
  while ( 1 )
  {
    if ( v12[292] != *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL) )
      goto LABEL_19;
    if ( v13 >= v4 )
      break;
LABEL_18:
    ++v13;
LABEL_19:
    v12 = (_QWORD *)*v12;
    if ( v12 == &cfg80211_rdev_list )
      goto LABEL_31;
  }
  if ( (v8 & 0x80000000) == 0 && v8 != *((_DWORD *)v12 + 23) )
    goto LABEL_19;
  mutex_lock(v12 + 123);
  v15 = (_QWORD *)v12[290];
  if ( v15 == v12 + 290 )
  {
    v14 = 0;
LABEL_17:
    is_locked = mutex_unlock(v12 + 123);
    v8 = v17;
    v4 = v18;
    v5 = 0;
    goto LABEL_18;
  }
  v14 = 0;
  while ( v14 < v5
       || (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD *, _QWORD *, __int64))nl80211_send_iface)(
             a1,
             *(unsigned int *)(*(_QWORD *)a2 + 52LL),
             *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
             2,
             v12 - 1,
             v15 - 2,
             7)
         & 0x80000000) == 0 )
  {
    v15 = (_QWORD *)*v15;
    ++v14;
    if ( v15 == v12 + 290 )
      goto LABEL_17;
  }
  is_locked = mutex_unlock(v12 + 123);
LABEL_31:
  *(_QWORD *)(a2 + 80) = v13;
  *(_QWORD *)(a2 + 88) = v14;
  v10 = *(_DWORD *)(a1 + 112);
LABEL_32:
  rtnl_unlock(is_locked);
  _ReadStatusReg(SP_EL0);
  return v10;
}
