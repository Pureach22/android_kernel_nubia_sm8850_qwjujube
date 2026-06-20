__int64 __fastcall ieee80211_netdev_fill_forward_path(_BYTE *a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x19
  __int64 v6; // x22
  __int64 lock; // x0
  int v8; // w8
  unsigned int v9; // w20
  _BYTE *v10; // x1
  int v11; // w2
  __int64 v12; // x9
  __int64 v13; // x23
  const char *v14; // x1
  _DWORD *v15; // x8

  v2 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 4304LL);
  if ( *(_QWORD *)(*(_QWORD *)(v3 + 464) + 912LL) )
  {
    v6 = v2 + 2688;
    lock = _rcu_read_lock(a1, a2);
    v8 = *(_DWORD *)(v2 + 7408);
    switch ( v8 )
    {
      case 2:
        if ( (*(_BYTE *)(*(_QWORD *)(v2 + 2704) + 101LL) & 0x80) != 0 )
        {
          lock = sta_info_get(v2 + 2688, a1 + 8);
          if ( lock )
          {
            if ( (*(_QWORD *)(lock + 216) & 0x800) != 0 )
            {
              if ( (*(_QWORD *)(lock + 216) & 0x1000) != 0 )
                goto LABEL_18;
              goto LABEL_27;
            }
          }
        }
        v10 = (_BYTE *)(v2 + 6840);
        break;
      case 3:
        v10 = a1 + 8;
        if ( (a1[8] & 1) != 0 )
        {
LABEL_27:
          v9 = -2;
          goto LABEL_37;
        }
        break;
      case 4:
        lock = *(_QWORD *)(v2 + 4968);
        if ( !lock )
        {
          if ( (*(_BYTE *)(v2 + 2769) & 1) != 0 )
            goto LABEL_27;
          if ( (a1[8] & 1) != 0 )
            goto LABEL_27;
          lock = sta_info_get_bss(v2 + 2688, a1 + 8);
          if ( !lock )
            goto LABEL_27;
        }
LABEL_18:
        if ( v2 != -2688 && *(_DWORD *)(v2 + 7408) == 4 )
          v6 = *(_QWORD *)(v2 + 4720) - 2264LL;
        if ( (*(_BYTE *)(*(_QWORD *)(v6 + 1616) + 1471LL) & 1) != 0
          || (v11 = *(_DWORD *)(v6 + 1624), (v11 & 0x20) != 0)
          || (drv_net_fill_forward_path___already_done & 1) != 0 )
        {
          if ( (*(_BYTE *)(v6 + 1624) & 0x20) == 0 )
          {
LABEL_25:
            v9 = -5;
LABEL_37:
            _rcu_read_unlock(lock);
            return v9;
          }
        }
        else
        {
          v12 = *(_QWORD *)(v6 + 1608);
          drv_net_fill_forward_path___already_done = 1;
          v13 = lock;
          if ( v12 )
            v14 = (const char *)(v12 + 296);
          else
            v14 = (const char *)(v6 + 1640);
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v14, v11);
          lock = v13;
          __break(0x800u);
          if ( (*(_BYTE *)(v6 + 1624) & 0x20) == 0 )
            goto LABEL_25;
        }
        v15 = *(_DWORD **)(*(_QWORD *)(v3 + 464) + 912LL);
        if ( v15 )
        {
          if ( *(v15 - 1) != -2073107615 )
            __break(0x8228u);
          lock = ((__int64 (__fastcall *)(__int64, __int64, __int64, _BYTE *, __int64))v15)(
                   v3,
                   v6 + 4720,
                   lock + 2688,
                   a1,
                   a2);
          v9 = lock;
        }
        else
        {
          v9 = -95;
        }
        goto LABEL_37;
      default:
        goto LABEL_27;
    }
    lock = sta_info_get(v2 + 2688, v10);
    if ( lock )
      goto LABEL_18;
    goto LABEL_27;
  }
  return (unsigned int)-95;
}
