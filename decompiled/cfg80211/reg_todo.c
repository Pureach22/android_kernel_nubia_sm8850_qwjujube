__int64 __fastcall reg_todo(__int64 a1)
{
  unsigned __int64 v1; // x20
  _QWORD *v2; // x21
  const char *v3; // x22
  _QWORD *v4; // x19
  void **v5; // x8
  void *v6; // x9
  __int64 v7; // x0
  _UNKNOWN **i; // x23
  _DWORD *v9; // x8
  __int64 v10; // x19
  __int64 is_locked; // x0
  void **v12; // x8
  _QWORD *v13; // x28
  _UNKNOWN **j; // x27
  __int64 v15; // x8
  unsigned int v16; // w23
  _QWORD *v17; // x1
  __int64 v18; // x0
  __int64 v19; // x0

  rtnl_lock(a1);
  v2 = &unk_4000;
  if ( !last_request || *((_BYTE *)last_request + 37) == 1 )
  {
    raw_spin_lock(&reg_requests_lock);
    v3 = (const char *)&reg_requests_list;
    v4 = reg_requests_list;
    if ( reg_requests_list != (_UNKNOWN *)&reg_requests_list )
    {
      v5 = *(void ***)((char *)&unk_8 + (_QWORD)reg_requests_list);
      if ( *v5 == reg_requests_list
        && (v6 = *(void **)reg_requests_list,
            *(_UNKNOWN **)((char *)&unk_8 + *(_QWORD *)reg_requests_list) == reg_requests_list) )
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)v6) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(reg_requests_list);
      }
      *v4 = v4;
      v1 = (unsigned __int64)(v4 - 6);
      *(_QWORD *)((char *)&unk_8 + (_QWORD)v4) = v4;
      v7 = raw_spin_unlock(&reg_requests_lock);
      if ( !(unsigned int)rtnl_is_locked(v7) && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
      {
LABEL_51:
        for_each_rdev_check_rtnl___already_done_2 = 1;
        _warn_printk(
          "RTNL: assertion failed at %s (%d)\n",
          "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
          166);
        __break(0x800u);
      }
      for ( i = (_UNKNOWN **)cfg80211_rdev_list; i != &cfg80211_rdev_list; i = (_UNKNOWN **)*i )
      {
        if ( ((_BYTE)i[136] & 0x80) != 0 && *((_DWORD *)v4 - 7) == 1 )
        {
          v9 = i[170];
          if ( v9 )
          {
            if ( *(v9 - 1) != -1916906463 )
              __break(0x8228u);
            ((void (__fastcall *)(_UNKNOWN **, unsigned __int64))v9)(i + 123, v1);
          }
        }
      }
      reg_process_hint(v1);
      v10 = v2[457];
      raw_spin_lock(&reg_requests_lock);
      if ( *(const char **)v3 != v3 && v10 && *(_BYTE *)(v10 + 37) == 1 )
        queue_work_on(32, system_wq, &reg_work);
    }
    raw_spin_unlock(&reg_requests_lock);
  }
  is_locked = raw_spin_lock_bh(&reg_pending_beacons_lock);
  v2 = reg_pending_beacons;
  if ( reg_pending_beacons != (_UNKNOWN *)&reg_pending_beacons )
  {
    v4 = &reg_beacon_list;
    v3 = "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h";
    do
    {
      v13 = (_QWORD *)*v2;
      v12 = (void **)v2[1];
      if ( *v12 == v2 && (_QWORD *)v13[1] == v2 )
      {
        v13[1] = v12;
        *v12 = v13;
      }
      else
      {
        is_locked = _list_del_entry_valid_or_report(v2);
      }
      *v2 = v2;
      v2[1] = v2;
      is_locked = rtnl_is_locked(is_locked);
      if ( !(_DWORD)is_locked && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
      {
        for_each_rdev_check_rtnl___already_done_2 = 1;
        is_locked = _warn_printk(
                      "RTNL: assertion failed at %s (%d)\n",
                      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                      166);
        __break(0x800u);
      }
      for ( j = (_UNKNOWN **)cfg80211_rdev_list; j != &cfg80211_rdev_list; j = (_UNKNOWN **)*j )
      {
        v15 = *((unsigned int *)v2 + 4);
        if ( (unsigned int)v15 >= 6 )
        {
          __break(0x5512u);
          goto LABEL_51;
        }
        v1 = (unsigned __int64)j[v15 + 164];
        if ( v1 && *(_DWORD *)(v1 + 20) )
        {
          v16 = 0;
          do
            is_locked = handle_reg_beacon(j + 123, v16++, v2);
          while ( v16 < *(_DWORD *)(v1 + 20) );
        }
      }
      v17 = off_4E08;
      if ( v2 == &reg_beacon_list || off_4E08 == v2 || *off_4E08 != (_UNKNOWN *)&reg_beacon_list )
      {
        is_locked = _list_add_valid_or_report(v2, off_4E08);
      }
      else
      {
        off_4E08 = (_UNKNOWN **)v2;
        *v2 = &reg_beacon_list;
        v2[1] = v17;
        *v17 = v2;
      }
      v2 = v13;
    }
    while ( v13 != &reg_pending_beacons );
  }
  v18 = raw_spin_unlock_bh(&reg_pending_beacons_lock);
  v19 = reg_process_self_managed_hints(v18);
  return rtnl_unlock(v19);
}
