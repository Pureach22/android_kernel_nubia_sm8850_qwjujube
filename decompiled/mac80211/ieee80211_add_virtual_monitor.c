__int64 __fastcall ieee80211_add_virtual_monitor(__int64 a1)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x19
  __int64 v5; // x8
  const char *v6; // x3
  __int64 v7; // x8
  char v8; // w9
  unsigned __int64 v9; // x9
  char v10; // w9
  unsigned __int64 v11; // x23
  char v12; // w8
  unsigned int v13; // w0
  unsigned int v14; // w9
  unsigned int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // w0
  unsigned int v20; // w20
  __int64 v21; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v23; // x23
  unsigned __int64 v30; // x9

  if ( (unsigned int)rtnl_is_locked() || (ieee80211_add_virtual_monitor___already_done & 1) != 0 )
  {
    if ( *(_QWORD *)(a1 + 5384) )
      return 0;
  }
  else
  {
    ieee80211_add_virtual_monitor___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 1131);
    __break(0x800u);
    if ( *(_QWORD *)(a1 + 5384) )
      return 0;
  }
  v3 = *(int *)(a1 + 112) + 5904LL;
  v4 = _kmalloc_noprof(v3, 3520);
  if ( v4 )
  {
    while ( 1 )
    {
      if ( v3 >> 4 < 0x127 || (v3 & 0xFFFFFFFFFFFFFFFCLL) == 0x1270 )
        goto LABEL_71;
      v5 = *(_QWORD *)(a1 + 72);
      *(_DWORD *)(v4 + 4720) = 6;
      v6 = *(const char **)(v5 + 504);
      if ( !v6 )
        v6 = *(const char **)(v5 + 392);
      snprintf((char *)(v4 + 1640), 0x10u, "%s-monitor", v6);
      if ( v3 < 0x18 )
        goto LABEL_71;
      if ( (v3 & 0xFFFFFFFFFFFFFFFCLL) == 0x18 )
        goto LABEL_71;
      *(_DWORD *)(v4 + 24) = 6;
      if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
        goto LABEL_71;
      *(_QWORD *)(v4 + 16) = *(_QWORD *)(a1 + 72);
      if ( v3 < 0x650 )
        goto LABEL_71;
      if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) == 0x650 )
        goto LABEL_71;
      *(_QWORD *)(v4 + 1616) = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))ieee80211_link_init)(
        v4,
        0xFFFFFFFFLL,
        v4 + 3616,
        v4 + 4808);
      v7 = *(_QWORD *)(v4 + 1616);
      if ( v3 < 0x16DB )
        goto LABEL_71;
      *(_BYTE *)(v4 + 5850) = (__int64)(*(_QWORD *)(v7 + 96) << 45) >> 63;
      if ( (*(_QWORD *)(v7 + 96) & 0x40000) != 0 )
        break;
      if ( *(unsigned __int16 *)(v7 + 128) > 3u )
      {
        if ( v3 == 5851 )
          goto LABEL_71;
        v8 = 1;
LABEL_23:
        *(_BYTE *)(v4 + 5851) = v8;
        if ( (*(_QWORD *)(v7 + 96) & 0x40000) != 0 )
          goto LABEL_29;
        goto LABEL_24;
      }
      if ( v3 == 5851 )
        goto LABEL_71;
      *(_BYTE *)(v4 + 5851) = 0;
      if ( (*(_QWORD *)(v7 + 96) & 0x40000) != 0 )
      {
LABEL_29:
        if ( v3 - 5851 < 2 )
          goto LABEL_71;
        v10 = -1;
LABEL_31:
        *(_BYTE *)(v4 + 5852) = v10;
        goto LABEL_34;
      }
LABEL_24:
      v9 = v3 - 5851;
      if ( *(unsigned __int16 *)(v7 + 128) > 3u )
      {
        if ( v9 < 2 )
          goto LABEL_71;
        v10 = 2;
        goto LABEL_31;
      }
      if ( v9 < 2 )
        goto LABEL_71;
      *(_BYTE *)(v4 + 5852) = 0;
LABEL_34:
      v11 = v3 >> 1;
      if ( (*(_QWORD *)(v7 + 96) & 0x40000) != 0 )
      {
        if ( v11 < 0xB6F )
          goto LABEL_71;
        v12 = -1;
      }
      else
      {
        if ( *(unsigned __int16 *)(v7 + 128) <= 3u )
        {
          if ( v11 < 0xB6F )
            goto LABEL_71;
          *(_BYTE *)(v4 + 5853) = 0;
          goto LABEL_43;
        }
        if ( v11 < 0xB6F )
          goto LABEL_71;
        v12 = 3;
      }
      *(_BYTE *)(v4 + 5853) = v12;
LABEL_43:
      *(_BYTE *)(v4 + 5849) = -1;
      if ( (*(_QWORD *)(a1 + 96) & 0x1000) != 0 )
      {
        v13 = drv_add_interface(a1, v4);
        if ( v13 )
        {
          v20 = v13;
          __break(0x800u);
          goto LABEL_58;
        }
      }
      _X8 = (unsigned __int64 *)(v4 + 1632);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 | 1, _X8) );
      if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x650 )
      {
        v14 = *(unsigned __int8 *)(v4 + 5850);
        if ( v14 == 255
          || (v15 = *(unsigned __int16 *)(*(_QWORD *)(v4 + 1616) + 128LL), v15 <= v14)
          || (v16 = *(unsigned __int8 *)(v4 + 5851), v16 == 255)
          || v15 <= v16 )
        {
LABEL_69:
          __break(0x800u);
          kfree(v4);
          return 4294967274LL;
        }
        if ( v3 != 5852 )
        {
          v17 = *(unsigned __int8 *)(v4 + 5852);
          if ( v17 == 255 )
            goto LABEL_69;
          if ( v15 <= v17 )
            goto LABEL_69;
          v18 = *(unsigned __int8 *)(v4 + 5853);
          if ( v18 == 255 || v15 <= v18 )
            goto LABEL_69;
          *(_BYTE *)(v4 + 5849) = -1;
          mutex_lock(a1 + 4648);
          atomic_store(v4, (unsigned __int64 *)(a1 + 5384));
          mutex_unlock(a1 + 4648);
          v19 = ieee80211_link_use_channel(v4 + 3616, (__int64 *)(a1 + 5392), 1u, 0);
          if ( v19 )
          {
            v20 = v19;
            mutex_lock(a1 + 4648);
            *(_QWORD *)(a1 + 5384) = 0;
            v21 = mutex_unlock(a1 + 4648);
            synchronize_net(v21);
            drv_remove_interface(a1, v4);
LABEL_58:
            kfree(v4);
            return v20;
          }
          if ( (v3 & 0xFFFFFFFFFFFFFFFCLL) != 0x7D4 )
          {
            *(_DWORD *)(v4 + 2004) = 0;
            if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x7C0 )
            {
              *(_QWORD *)(v4 + 1984) = v4 + 1984;
              if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x7C8 )
              {
                *(_QWORD *)(v4 + 1992) = v4 + 1984;
                if ( (v3 & 0xFFFFFFFFFFFFFFFCLL) != 0x7D0 )
                {
                  *(_DWORD *)(v4 + 2000) = 0;
                  if ( (v3 & 0xFFFFFFFFFFFFFFFCLL) != 0x7EC )
                  {
                    *(_DWORD *)(v4 + 2028) = 0;
                    if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x7D8 )
                    {
                      *(_QWORD *)(v4 + 2008) = v4 + 2008;
                      if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x7E0 )
                      {
                        *(_QWORD *)(v4 + 2016) = v4 + 2008;
                        if ( (v3 & 0xFFFFFFFFFFFFFFFCLL) != 0x7E8 )
                        {
                          *(_DWORD *)(v4 + 2024) = 0;
                          *(_QWORD *)(v4 + 1960) = v4 + 1960;
                          *(_QWORD *)(v4 + 1968) = v4 + 1960;
                          if ( (v3 & 0xFFFFFFFFFFFFFFF8LL) != 0x7B8 )
                          {
                            *(_QWORD *)(v4 + 1976) = ieee80211_iface_work;
                            return 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_71:
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v23 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ieee80211_add_virtual_monitor__alloc_tag;
      v3 = *(int *)(a1 + 112) + 5904LL;
      v4 = _kmalloc_noprof(v3, 3520);
      *(_QWORD *)(StatusReg + 80) = v23;
      if ( !v4 )
        return 4294967284LL;
    }
    if ( v3 == 5851 )
      goto LABEL_71;
    v8 = -1;
    goto LABEL_23;
  }
  return 4294967284LL;
}
