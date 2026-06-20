__int64 __fastcall hdd_softap_deauth_all_sta(
        _QWORD *a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x8
  _QWORD *v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x23
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 *v34; // x8
  unsigned __int64 v35; // x27
  unsigned int v36; // w0
  __int64 v37; // x8
  unsigned int v38; // w20
  __int64 v39; // [xsp+0h] [xbp-230h]
  __int64 v40; // [xsp+10h] [xbp-220h] BYREF
  __int64 v41; // [xsp+18h] [xbp-218h] BYREF
  _BYTE v42[4]; // [xsp+24h] [xbp-20Ch] BYREF
  _DWORD s[128]; // [xsp+28h] [xbp-208h] BYREF
  __int64 v44; // [xsp+228h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (__int64 *)a1[3];
  v42[0] = 0;
  v40 = 0;
  v41 = 0;
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_deauth_all_sta");
    result = 4;
    goto LABEL_46;
  }
  v13 = a1 + 6603;
  wlan_mlme_get_sap_bcast_deauth_enabled(*v10, v42);
  if ( v42[0] == 1 )
  {
    memset(s, 0, sizeof(s));
    s[8] = -1;
    LOWORD(s[9]) = -1;
    if ( a1 )
    {
      if ( (a1[205] & 1) != 0 )
      {
        v22 = a1 + 6604;
        if ( a1 != (_QWORD *)-52832LL )
        {
          do
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d send broadcast deauth",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "hdd_softap_deauth_all_sta",
              *((unsigned __int8 *)v22 + 8));
            hdd_softap_deauth_current_sta(v22, s, a2);
            if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v22 - *(_DWORD *)v22 - 52832) >> 4)) )
              break;
            v22 = a1 + 6604;
          }
          while ( (a1[205] & 1) != 0 );
        }
      }
    }
    goto LABEL_45;
  }
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
  hdd_get_front_sta_info_no_lock(a1 + 4856, &v41);
  if ( v41 )
    hdd_take_sta_info_ref(a1 + 4856, v41, 0, 13);
  hdd_get_next_sta_info_no_lock(a1 + 4856);
  if ( v40 )
    hdd_take_sta_info_ref(a1 + 4856, v40, 0, 13);
  v25 = a1[4860];
  if ( (v25 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 4859);
    v34 = (unsigned __int8 *)v41;
    if ( v41 )
      goto LABEL_20;
LABEL_45:
    result = 0;
    goto LABEL_46;
  }
  a1[4860] = v25 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 4859);
  v34 = (unsigned __int8 *)v41;
  if ( !v41 )
    goto LABEL_45;
LABEL_20:
  v35 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (v34[49] & 1) == 0 )
    {
      LODWORD(v39) = v34[37];
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Vdev %d Delete STA with %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_softap_deauth_all_sta",
        *(unsigned __int8 *)(*v13 + 8LL),
        v34[32],
        v34[33],
        v34[34],
        v39);
      if ( *(unsigned __int8 *)(v41 + 32) != 255
        || *(unsigned __int8 *)(v41 + 33) != 255
        || *(unsigned __int8 *)(v41 + 34) != 255
        || *(unsigned __int8 *)(v41 + 35) != 255
        || *(unsigned __int8 *)(v41 + 36) != 255
        || *(unsigned __int8 *)(v41 + 37) != 255 )
      {
        qdf_mem_copy(a2, (const void *)(v41 + 32), 6u);
        v36 = hdd_softap_deauth_current_sta(*(_QWORD *)(v41 + 16), v41, a2);
        if ( v36 )
          break;
      }
    }
    hdd_put_sta_info_ref(a1 + 4856, &v41, 1, 13);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v35 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4859);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4859);
      a1[4860] |= 1uLL;
    }
    v41 = v40;
    hdd_get_next_sta_info_no_lock(a1 + 4856);
    if ( v40 )
      hdd_take_sta_info_ref(a1 + 4856, v40, 0, 13);
    v37 = a1[4860];
    if ( (v37 & 1) != 0 )
    {
      a1[4860] = v37 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4859);
      v34 = (unsigned __int8 *)v41;
      if ( !v41 )
        goto LABEL_45;
    }
    else
    {
      raw_spin_unlock(a1 + 4859);
      v34 = (unsigned __int8 *)v41;
      if ( !v41 )
        goto LABEL_45;
    }
  }
  v38 = v36;
  hdd_put_sta_info_ref(a1 + 4856, &v41, 1, 13);
  if ( v40 )
    hdd_put_sta_info_ref(a1 + 4856, &v40, 1, 13);
  result = v38;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
