__int64 __fastcall nl80211_get_reg_do(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x21
  int v10; // w23
  __int64 wiphy_regdom; // x0
  __int64 v12; // x23
  int v13; // w8
  __int64 lock; // x0
  __int64 unlock; // x0
  int v17; // w0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( v3 )
  {
    v4 = v3;
    v5 = genlmsg_put(v3, a2[1], *a2, &nl80211_fam, 0, 31);
    if ( !v5 )
    {
      LODWORD(v9) = -90;
LABEL_19:
      sk_skb_reason_drop(0, v4, 2);
      goto LABEL_20;
    }
    v6 = v5;
    v7 = rtnl_lock(v5);
    if ( *(_QWORD *)(*((_QWORD *)a2 + 4) + 8LL) )
    {
      v8 = ((__int64 (__fastcall *)(_QWORD))_cfg80211_rdev_from_attrs)(*((_QWORD *)a2 + 5));
      v9 = v8;
      if ( v8 > 0xFFFFFFFFFFFFF000LL )
      {
LABEL_18:
        rtnl_unlock(v8);
        goto LABEL_19;
      }
      v10 = *(_DWORD *)(v8 + 1096);
      _rcu_read_lock(v8);
      wiphy_regdom = get_wiphy_regdom(v9 + 992);
      if ( !wiphy_regdom && (v10 & 0x80) != 0 )
      {
        __break(0x800u);
        LODWORD(v9) = -22;
        goto LABEL_17;
      }
      if ( wiphy_regdom )
      {
        v12 = wiphy_regdom;
        v18 = ((__int64 (__fastcall *)(unsigned __int64))get_wiphy_idx)(v9 + 992);
        v13 = nla_put(v4, 1, 4, &v18);
        wiphy_regdom = v12;
        if ( !v13 )
        {
LABEL_15:
          wiphy_regdom = nl80211_put_regdom(wiphy_regdom, v4);
          if ( !(_DWORD)wiphy_regdom )
          {
            unlock = _rcu_read_unlock(wiphy_regdom);
            *(_DWORD *)(v6 - 20) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - (v6 - 20);
            rtnl_unlock(unlock);
            v17 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v4, a2[1], 64);
            LODWORD(v9) = v17 & (v17 >> 31);
            goto LABEL_20;
          }
        }
LABEL_16:
        LODWORD(v9) = -90;
LABEL_17:
        v8 = _rcu_read_unlock(wiphy_regdom);
        goto LABEL_18;
      }
    }
    else
    {
      lock = _rcu_read_lock(v7);
      if ( (reg_last_request_cell_base(lock) & 1) != 0 )
      {
        v18 = 1;
        wiphy_regdom = nla_put(v4, 154, 4, &v18);
        if ( (_DWORD)wiphy_regdom )
          goto LABEL_16;
      }
    }
    wiphy_regdom = cfg80211_regdomain;
    goto LABEL_15;
  }
  LODWORD(v9) = -105;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
