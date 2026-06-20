__int64 __fastcall hdd_sap_indicate_disconnect_for_sta(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x8
  unsigned __int8 *v21; // x8
  unsigned __int64 v22; // x28
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  const char *v33; // x2
  unsigned int v34; // w1
  __int64 result; // x0
  _QWORD v36[2]; // [xsp+8h] [xbp-238h] BYREF
  int s[134]; // [xsp+18h] [xbp-228h] BYREF
  __int64 v38; // [xsp+230h] [xbp-10h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v36[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_sap_indicate_disconnect_for_sta");
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 52832) + 272LL);
  if ( v18 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 38872);
    }
    else
    {
      raw_spin_lock_bh(a1 + 38872);
      *(_QWORD *)(a1 + 38880) |= 1uLL;
    }
    hdd_get_front_sta_info_no_lock(a1 + 38848, v36);
    if ( v36[0] )
      hdd_take_sta_info_ref(a1 + 38848, v36[0], 0, 18);
    hdd_get_next_sta_info_no_lock(a1 + 38848);
    v20 = *(_QWORD *)(a1 + 38880);
    if ( (v20 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 38880) = v20 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 38872);
      v21 = (unsigned __int8 *)v36[0];
      if ( v36[0] )
        goto LABEL_10;
    }
    else
    {
      raw_spin_unlock(a1 + 38872);
      v21 = (unsigned __int8 *)v36[0];
      if ( v36[0] )
      {
LABEL_10:
        v22 = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: sta_mac: %02x:%02x:%02x:**:**:%02x",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "hdd_sap_indicate_disconnect_for_sta",
            v21[32],
            v21[33],
            v21[34],
            v21[37]);
          if ( *(_DWORD *)(v36[0] + 32LL) == -1 && *(__int16 *)(v36[0] + 36LL) == -1 )
          {
            hdd_softap_deregister_sta(a1, v36);
            hdd_put_sta_info_ref(a1 + 38848, v36, 1, 18);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
              goto LABEL_20;
          }
          else
          {
            s[0] = 5;
            qdf_mem_copy(&s[2], (const void *)(v36[0] + 32LL), 6u);
            hdd_put_sta_info_ref(a1 + 38848, v36, 1, 18);
            s[6] = 0x10000;
            s[4] = 1;
            hdd_hostapd_sap_event_cb(v18, s, v24, v25, v26, v27, v28, v29, v30, v31);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
              goto LABEL_20;
          }
          if ( (*(_DWORD *)(v22 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v22 + 16) & 0xFF00) == 0 )
          {
            raw_spin_lock_bh(a1 + 38872);
            *(_QWORD *)(a1 + 38880) |= 1uLL;
            goto LABEL_21;
          }
LABEL_20:
          raw_spin_lock(a1 + 38872);
LABEL_21:
          v36[0] = 0;
          hdd_get_next_sta_info_no_lock(a1 + 38848);
          v32 = *(_QWORD *)(a1 + 38880);
          if ( (v32 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 38880) = v32 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 38872);
            v21 = (unsigned __int8 *)v36[0];
            if ( !v36[0] )
              break;
          }
          else
          {
            raw_spin_unlock(a1 + 38872);
            v21 = (unsigned __int8 *)v36[0];
            if ( !v36[0] )
              break;
          }
        }
      }
    }
    v33 = "%s: exit";
    v34 = 8;
  }
  else
  {
    v33 = "%s: invalid sap context";
    v34 = 2;
  }
  result = qdf_trace_msg(0x33u, v34, v33, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_sap_indicate_disconnect_for_sta");
  _ReadStatusReg(SP_EL0);
  return result;
}
