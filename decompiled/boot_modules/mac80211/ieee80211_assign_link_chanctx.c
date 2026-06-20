__int64 __fastcall ieee80211_assign_link_chanctx(_QWORD *a1, __int64 a2, char a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  __int64 v8; // x8
  _BYTE *v9; // x23
  _QWORD *v10; // x8
  _QWORD *v11; // x0
  __int64 v12; // x9
  unsigned int v13; // w20
  unsigned __int64 v14; // x25
  _QWORD *v15; // x0
  _QWORD *v16; // x1
  _QWORD *v17; // x2
  int v18; // w8
  _QWORD *v19; // x10
  int v20; // w8
  _QWORD *v21; // x10
  char v22; // w10
  char v23; // w9
  int v24; // w10
  _QWORD *v26; // x8
  __int64 v27; // x11
  __int64 v28; // x11
  __int64 v29; // x11
  __int64 v30; // x11
  __int64 v31; // x11
  __int64 v32; // x11
  __int64 v33; // x11
  __int64 v34; // x11
  __int64 v35; // x11
  __int64 v36; // x11
  __int64 v37; // x11
  __int64 v38; // x11
  __int64 v39; // x11
  __int64 v40; // x11
  __int64 v41; // x11

  v3 = *a1;
  if ( *(_DWORD *)(*a1 + 4720LL) == 12 )
  {
    __break(0x800u);
    return (unsigned int)-95;
  }
  v5 = *(_QWORD *)(v3 + 1616);
  v8 = *(_QWORD *)(a1[118] + 832LL);
  if ( v8 )
  {
    v9 = (_BYTE *)(v8 - 152);
    drv_unassign_vif_chanctx(*(_QWORD *)(v3 + 1616), v3);
    v10 = (_QWORD *)a1[3];
    v11 = a1 + 2;
    if ( (_QWORD *)*v10 == a1 + 2 && (v12 = *v11, *(_QWORD **)(*v11 + 8LL) == v11) )
    {
      *(_QWORD *)(v12 + 8) = v10;
      *v10 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    a1[2] = 0xDEAD000000000100LL;
    a1[3] = 0xDEAD000000000122LL;
    if ( a2 )
    {
LABEL_7:
      ieee80211_recalc_chanctx_min_def(v5, a2);
      v13 = drv_assign_vif_chanctx(v5, v3, a1[118], a2);
      if ( (a3 & 1) != 0 || !v13 )
      {
        if ( v13 && (*(_BYTE *)(v5 + 1470) & 1) == 0 )
          __break(0x800u);
        v15 = a1 + 2;
        v16 = (_QWORD *)(a2 + 32);
        v17 = *(_QWORD **)(a2 + 32);
        v14 = a2 + 152;
        if ( v17[1] != a2 + 32 || v15 == v16 || v17 == v15 )
        {
          _list_add_valid_or_report(v15, v16);
          v13 = 0;
        }
        else
        {
          v13 = 0;
          v17[1] = v15;
          a1[2] = v17;
          a1[3] = v16;
          *v16 = v15;
        }
      }
      else
      {
        v14 = 0;
      }
      goto LABEL_19;
    }
  }
  else
  {
    v9 = nullptr;
    if ( a2 )
      goto LABEL_7;
  }
  v13 = 0;
  v14 = 0;
LABEL_19:
  atomic_store(v14, (unsigned __int64 *)(a1[118] + 832LL));
  if ( v9 )
  {
    v18 = -1;
    v19 = v9 + 32;
    do
    {
      v19 = (_QWORD *)*v19;
      ++v18;
    }
    while ( v19 != (_QWORD *)(v9 + 32) );
    if ( v18 >= 1 )
    {
      ((void (__fastcall *)(__int64, _BYTE *))ieee80211_recalc_chanctx_chantype)(v5, v9);
      ieee80211_recalc_smps_chanctx(v5, v9);
      ieee80211_recalc_radar_chanctx(v5, v9);
      ieee80211_recalc_chanctx_min_def(v5, (__int64)v9);
    }
  }
  if ( a2 )
  {
    v20 = -1;
    v21 = (_QWORD *)(a2 + 32);
    do
    {
      v21 = (_QWORD *)*v21;
      ++v20;
    }
    while ( v21 != (_QWORD *)(a2 + 32) );
    if ( v20 >= 1 )
    {
      ieee80211_recalc_txpower(v3, 0);
      ieee80211_recalc_chanctx_min_def(v5, a2);
    }
  }
  if ( v14 )
  {
    v22 = 0;
  }
  else
  {
    v26 = *(_QWORD **)(v5 + 4616);
    v22 = 1;
    while ( v26 != (_QWORD *)(v5 + 4616) )
    {
      if ( (v26[204] & 1) != 0 )
      {
        v27 = v26[571];
        if ( v27 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v27 + 944) + 832LL) )
            goto LABEL_38;
        }
        v28 = v26[572];
        if ( v28 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v28 + 944) + 832LL) )
            goto LABEL_38;
        }
        v29 = v26[573];
        if ( v29 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v29 + 944) + 832LL) )
            goto LABEL_38;
        }
        v30 = v26[574];
        if ( v30 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v30 + 944) + 832LL) )
            goto LABEL_38;
        }
        v31 = v26[575];
        if ( v31 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v31 + 944) + 832LL) )
            goto LABEL_38;
        }
        v32 = v26[576];
        if ( v32 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v32 + 944) + 832LL) )
            goto LABEL_38;
        }
        v33 = v26[577];
        if ( v33 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v33 + 944) + 832LL) )
            goto LABEL_38;
        }
        v34 = v26[578];
        if ( v34 )
        {
          if ( *(_QWORD *)(*(_QWORD *)(v34 + 944) + 832LL) )
            goto LABEL_38;
        }
        if ( (v35 = v26[579]) != 0 && *(_QWORD *)(*(_QWORD *)(v35 + 944) + 832LL)
          || (v36 = v26[580]) != 0 && *(_QWORD *)(*(_QWORD *)(v36 + 944) + 832LL)
          || (v37 = v26[581]) != 0 && *(_QWORD *)(*(_QWORD *)(v37 + 944) + 832LL)
          || (v38 = v26[582]) != 0 && *(_QWORD *)(*(_QWORD *)(v38 + 944) + 832LL)
          || (v39 = v26[583]) != 0 && *(_QWORD *)(*(_QWORD *)(v39 + 944) + 832LL)
          || (v40 = v26[584]) != 0 && *(_QWORD *)(*(_QWORD *)(v40 + 944) + 832LL)
          || (v41 = v26[585]) != 0 && *(_QWORD *)(*(_QWORD *)(v41 + 944) + 832LL) )
        {
LABEL_38:
          v22 = 0;
        }
      }
      v26 = (_QWORD *)*v26;
    }
  }
  v23 = v22;
  if ( *(_BYTE *)(v3 + 4801) != (v22 & 1) )
  {
    v24 = *(_DWORD *)(v3 + 4720);
    *(_BYTE *)(v3 + 4801) = v23;
    if ( v24 != 6 && v24 != 10 )
      ieee80211_vif_cfg_change_notify(v3, 0x4000);
  }
  ieee80211_check_fast_xmit_iface(v3);
  return v13;
}
