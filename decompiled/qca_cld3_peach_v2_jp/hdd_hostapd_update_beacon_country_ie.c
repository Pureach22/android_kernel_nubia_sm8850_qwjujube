__int64 __fastcall hdd_hostapd_update_beacon_country_ie(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x22
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  __int64 result; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // x26
  int v17; // w8
  __int64 v18; // x8
  const char *v19; // x2
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-38h] BYREF
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v33[2]; // [xsp+30h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = (_QWORD *)a1[3];
  v32 = 0;
  v33[0] = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  if ( !v9 )
  {
    v19 = "%s: HDD context is null";
    goto LABEL_38;
  }
  v11 = a1[6603];
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4859);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4859);
    a1[4860] |= 1uLL;
  }
  hdd_get_front_sta_info_no_lock(a1 + 4856, v33);
  if ( v33[0] )
    hdd_take_sta_info_ref(a1 + 4856, v33[0], 0, 17);
  hdd_get_next_sta_info_no_lock(a1 + 4856);
  if ( v32 )
    hdd_take_sta_info_ref(a1 + 4856, v32, 0, 17);
  v13 = a1[4860];
  if ( (v13 & 1) == 0 )
  {
    result = raw_spin_unlock(a1 + 4859);
    v15 = v33[0];
    if ( v33[0] )
      goto LABEL_12;
    goto LABEL_35;
  }
  a1[4860] = v13 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(a1 + 4859);
  v15 = v33[0];
  if ( !v33[0] )
  {
LABEL_35:
    if ( *(_BYTE *)(v11 + 2366) != 1 )
      goto LABEL_39;
    result = sme_update_beacon_country_ie(v9[2], *(unsigned __int8 *)(a1[6603] + 8LL), 0);
    if ( !(_DWORD)result )
    {
      *(_BYTE *)(v11 + 2366) = 0;
      goto LABEL_39;
    }
    v19 = "%s: fail to update country ie";
LABEL_38:
    result = qdf_trace_msg(0x33u, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_hostapd_update_beacon_country_ie");
    goto LABEL_39;
  }
LABEL_12:
  v16 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)(v15 + 264) )
    {
      qdf_mem_set(&v28, 0x20u, 0);
      v17 = *(_DWORD *)(v33[0] + 264LL);
      v28 = *(_QWORD *)(v33[0] + 272LL);
      LODWORD(v29) = v17;
      if ( (ucfg_action_oui_search(*v9, &v28, 20) & 1) != 0 )
        break;
    }
    hdd_put_sta_info_ref(a1 + 4856, v33, 1, 17);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v16 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4859);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4859);
      a1[4860] |= 1uLL;
    }
    v33[0] = v32;
    hdd_get_next_sta_info_no_lock(a1 + 4856);
    if ( v32 )
      hdd_take_sta_info_ref(a1 + 4856, v32, 0, 17);
    v18 = a1[4860];
    if ( (v18 & 1) != 0 )
    {
      a1[4860] = v18 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 4859);
      v15 = v33[0];
      if ( !v33[0] )
        goto LABEL_35;
    }
    else
    {
      result = raw_spin_unlock(a1 + 4859);
      v15 = v33[0];
      if ( !v33[0] )
        goto LABEL_35;
    }
  }
  if ( (*(_BYTE *)(v11 + 2366) & 1) == 0 )
  {
    if ( (unsigned int)sme_update_beacon_country_ie(v9[2], *(unsigned __int8 *)(a1[6603] + 8LL), 1) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to update country ie",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_hostapd_update_beacon_country_ie");
    else
      *(_BYTE *)(v11 + 2366) = 1;
  }
  result = hdd_put_sta_info_ref(a1 + 4856, v33, 1, 17);
  if ( v32 )
    result = hdd_put_sta_info_ref(a1 + 4856, &v32, 1, 17);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
