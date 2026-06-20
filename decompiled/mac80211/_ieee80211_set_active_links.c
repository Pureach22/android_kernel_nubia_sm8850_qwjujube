__int64 __fastcall ieee80211_set_active_links(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  int v3; // w22
  __int64 result; // x0
  int v6; // w23
  char v8; // w8
  __int64 v9; // x26
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x24
  __int64 *v12; // x25
  _QWORD *v13; // x25
  _QWORD *i; // x27
  _QWORD *j; // x25
  char v16; // w8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x23
  __int64 v19; // x22
  unsigned __int16 v20; // w2
  unsigned __int64 v21; // [xsp+0h] [xbp-90h]
  unsigned __int64 v22; // [xsp+8h] [xbp-88h]

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 1616);
  v3 = *(unsigned __int16 *)(a1 + 5802);
  if ( (*(_QWORD *)(a1 + 1632) & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 4720) == 2
      && (v6 = (unsigned __int16)a2,
          ((unsigned __int16)a2 & ~(*(unsigned __int16 *)(a1 + 5800) & ~*(unsigned __int16 *)(a1 + 5804))) == 0) )
    {
      if ( v3 == (unsigned __int16)a2 )
        goto LABEL_8;
      if ( ((unsigned __int16)a2 & ~v3) != 0 )
      {
        *(_WORD *)(a1 + 5802) = v3 | a2;
        result = drv_change_vif_links(v2, a1, v3, (unsigned __int16)v3 | (unsigned __int16)a2);
        if ( (_DWORD)result )
        {
          *(_WORD *)(a1 + 5802) = v3;
          goto LABEL_6;
        }
      }
      v8 = 0;
      v9 = a1 + 4568;
      v21 = v6 & (unsigned int)~v3;
      v22 = v3 & (unsigned int)~v6;
      do
      {
        v10 = v3 & (unsigned int)~v6 & 0x7FFFLL & (-1LL << v8);
        if ( !v10 )
          break;
        v11 = __clz(__rbit64(v10));
        v12 = *(__int64 **)(v9 + 8 * v11);
        ieee80211_teardown_tdls_peers(v12);
        _ieee80211_link_release_channel(v12, 1);
        if ( *(_BYTE *)(v12[118] + 830) == 1 )
          wiphy_delayed_work_queue(*(_QWORD *)(v2 + 72), v12 + 71, v12[97] - jiffies);
        v8 = v11 + 1;
      }
      while ( v11 < 0xE );
      v13 = *(_QWORD **)(v2 + 1616);
      for ( i = (_QWORD *)(v2 + 1616); v13 != i; v13 = (_QWORD *)*v13 )
      {
        if ( v13[10] == a1 )
        {
          _ieee80211_sta_recalc_aggregates(v13, v3 | a2);
          if ( (unsigned int)drv_change_sta_links(
                               v2,
                               a1,
                               (__int64)(v13 + 336),
                               v3,
                               (unsigned __int16)v3 | (unsigned __int16)a2) )
            __break(0x800u);
        }
      }
      if ( (unsigned int)ieee80211_key_switch_links(a1, v22, v21) )
        __break(0x800u);
      for ( j = (_QWORD *)*i; j != i; j = (_QWORD *)*j )
      {
        if ( j[10] == a1 )
        {
          _ieee80211_sta_recalc_aggregates(j, a2);
          if ( (unsigned int)drv_change_sta_links(
                               v2,
                               a1,
                               (__int64)(j + 336),
                               (unsigned __int16)v3 | (unsigned __int16)a2,
                               a2) )
            __break(0x800u);
          _ieee80211_sta_recalc_aggregates(j, a2);
        }
      }
      v16 = 0;
      do
      {
        v17 = v21 & 0x7FFF & (-1LL << v16);
        if ( !v17 )
          break;
        v18 = __clz(__rbit64(v17));
        v19 = *(_QWORD *)(v9 + 8 * v18);
        if ( (unsigned int)ieee80211_link_use_channel(v19, (__int64 *)(*(_QWORD *)(v19 + 944) + 136LL), 0, 1) )
          __break(0x800u);
        ieee80211_mgd_set_link_qos_params(v19);
        ieee80211_link_info_change_notify(a1, v19, 941892798);
        v16 = v18 + 1;
      }
      while ( v18 < 0xE );
      v20 = *(_WORD *)(a1 + 5802);
      *(_WORD *)(a1 + 5802) = a2;
      if ( !(_DWORD)v22 )
      {
LABEL_8:
        result = 0;
      }
      else
      {
        result = drv_change_vif_links(v2, a1, v20, a2);
        if ( (_DWORD)result )
        {
          result = 0;
          __break(0x800u);
        }
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967196LL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
