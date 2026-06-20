__int64 __fastcall reg_process_self_managed_hint(__int64 a1)
{
  unsigned __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x0
  unsigned int v5; // w0
  char v6; // w8
  char v7; // w9
  _DWORD *v8; // x8
  _QWORD v9[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v10; // [xsp+18h] [xbp-38h]
  __int64 v11; // [xsp+20h] [xbp-30h]
  __int64 v12; // [xsp+28h] [xbp-28h]
  __int64 v13; // [xsp+30h] [xbp-20h]
  __int64 v14; // [xsp+38h] [xbp-18h]
  __int64 v15; // [xsp+40h] [xbp-10h]
  __int64 v16; // [xsp+48h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v14 = 0;
    v15 = 0;
    v12 = 0;
    v13 = 0;
    v10 = 0;
    v11 = 0;
    v9[0] = 0;
    v9[1] = 0;
    if ( !(unsigned int)rtnl_is_locked(a1) && (reg_process_self_managed_hint___already_done & 1) == 0 )
    {
      reg_process_self_managed_hint___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 3171);
      __break(0x800u);
    }
    raw_spin_lock(&reg_requests_lock);
    v2 = *(_QWORD *)(a1 - 904);
    *(_QWORD *)(a1 - 904) = 0;
    result = raw_spin_unlock(&reg_requests_lock);
    if ( v2 )
    {
      v4 = *(_QWORD *)(a1 + 384);
      atomic_store(v2, (unsigned __int64 *)(a1 + 384));
      if ( v4 )
        kvfree_call_rcu(v4, v4);
      handle_band_custom(a1, *(_QWORD *)(a1 + 328), v2);
      handle_band_custom(a1, *(_QWORD *)(a1 + 336), v2);
      handle_band_custom(a1, *(_QWORD *)(a1 + 344), v2);
      handle_band_custom(a1, *(_QWORD *)(a1 + 352), v2);
      handle_band_custom(a1, *(_QWORD *)(a1 + 360), v2);
      handle_band_custom(a1, *(_QWORD *)(a1 + 368), v2);
      ((void (__fastcall *)(__int64))reg_process_ht_flags)(a1);
      v5 = ((__int64 (__fastcall *)(__int64))get_wiphy_idx)(a1);
      v6 = *(_BYTE *)(v2 + 20);
      v10 = v5 | 0x200000000LL;
      v7 = *(_BYTE *)(a1 + 103);
      BYTE4(v11) = v6;
      BYTE5(v11) = *(_BYTE *)(v2 + 21);
      if ( (v7 & 1) != 0 )
      {
        v8 = *(_DWORD **)(a1 + 376);
        if ( v8 )
        {
          if ( *(v8 - 1) != -1916906463 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD *))v8)(a1, v9);
        }
      }
      result = nl80211_common_reg_change_event(0x71u, (__int64)v9);
    }
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    __break(0x800u);
    return wiphy_regulatory_register(0);
  }
  return result;
}
