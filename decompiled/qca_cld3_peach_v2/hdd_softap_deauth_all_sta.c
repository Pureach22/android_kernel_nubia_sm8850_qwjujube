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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x8
  unsigned __int64 v37; // x27
  unsigned int v38; // w0
  __int64 v39; // x8
  unsigned int v40; // w20
  __int64 v41; // [xsp+0h] [xbp-230h]
  __int64 v42; // [xsp+8h] [xbp-228h] BYREF
  __int64 v43; // [xsp+10h] [xbp-220h] BYREF
  _BYTE v44[4]; // [xsp+1Ch] [xbp-214h] BYREF
  _DWORD s[128]; // [xsp+20h] [xbp-210h] BYREF
  __int64 v46; // [xsp+220h] [xbp-10h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (__int64 *)a1[3];
  v44[0] = 0;
  v42 = 0;
  v43 = 0;
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_deauth_all_sta");
    result = 4;
    goto LABEL_54;
  }
  wlan_mlme_get_sap_bcast_deauth_enabled(*v10, v44);
  if ( v44[0] == 1 )
  {
    memset(s, 0, sizeof(s));
    s[8] = -1;
    LOWORD(s[9]) = -1;
    if ( a1 )
    {
      if ( (a1[205] & 1) != 0 && (v21 = (__int64)(a1 + 6605), a1 != (_QWORD *)-52840LL)
        || (a1[205] & 2) != 0 && (v21 = (__int64)(a1 + 7366), a1 != (_QWORD *)-58928LL)
        || (a1[205] & 4) != 0 && (v21 = (__int64)(a1 + 8127), a1 != (_QWORD *)-65016LL) )
      {
        do
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Vdev %d send broadcast deauth",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "hdd_softap_deauth_all_sta",
            *(unsigned __int8 *)(v21 + 8));
          hdd_softap_deauth_current_sta(v21, s, a2);
          if ( (unsigned __int8)(73 * ((unsigned int)(v21 - *(_DWORD *)v21 - 52840) >> 3) + 1) > 2u )
            break;
          v22 = (unsigned __int8)(73 * ((unsigned int)(v21 - *(_DWORD *)v21 - 52840) >> 3) + 1);
          v21 = 0;
          v23 = (__int64)&a1[761 * (unsigned int)v22 + 6605];
          do
          {
            if ( v21 )
              break;
            v24 = a1[205] >> v22++;
            v21 = (v24 << 63 >> 63) & v23;
            v23 += 6088;
          }
          while ( v22 != 3 );
        }
        while ( v21 );
      }
    }
    goto LABEL_53;
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
  hdd_get_front_sta_info_no_lock(a1 + 4856, &v43);
  if ( v43 )
    hdd_take_sta_info_ref(a1 + 4856, v43, 0, 13);
  hdd_get_next_sta_info_no_lock(a1 + 4856);
  if ( v42 )
    hdd_take_sta_info_ref(a1 + 4856, v42, 0, 13);
  v27 = a1[4860];
  if ( (v27 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 4859);
    v36 = (unsigned __int8 *)v43;
    if ( v43 )
      goto LABEL_28;
LABEL_53:
    result = 0;
    goto LABEL_54;
  }
  a1[4860] = v27 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 4859);
  v36 = (unsigned __int8 *)v43;
  if ( !v43 )
    goto LABEL_53;
LABEL_28:
  v37 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (v36[49] & 1) == 0 )
    {
      LODWORD(v41) = v36[37];
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Vdev %d Delete STA with %02x:%02x:%02x:**:**:%02x",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_softap_deauth_all_sta",
        *(unsigned __int8 *)(a1[6604] + 8LL),
        v36[32],
        v36[33],
        v36[34],
        v41);
      if ( *(unsigned __int8 *)(v43 + 32) != 255
        || *(unsigned __int8 *)(v43 + 33) != 255
        || *(unsigned __int8 *)(v43 + 34) != 255
        || *(unsigned __int8 *)(v43 + 35) != 255
        || *(unsigned __int8 *)(v43 + 36) != 255
        || *(unsigned __int8 *)(v43 + 37) != 255 )
      {
        qdf_mem_copy(a2, (const void *)(v43 + 32), 6u);
        v38 = hdd_softap_deauth_current_sta(*(_QWORD *)(v43 + 16), v43, a2);
        if ( v38 )
          break;
      }
    }
    hdd_put_sta_info_ref(a1 + 4856, &v43, 1, 13);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v37 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4859);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4859);
      a1[4860] |= 1uLL;
    }
    v43 = v42;
    hdd_get_next_sta_info_no_lock(a1 + 4856);
    if ( v42 )
      hdd_take_sta_info_ref(a1 + 4856, v42, 0, 13);
    v39 = a1[4860];
    if ( (v39 & 1) != 0 )
    {
      a1[4860] = v39 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4859);
      v36 = (unsigned __int8 *)v43;
      if ( !v43 )
        goto LABEL_53;
    }
    else
    {
      raw_spin_unlock(a1 + 4859);
      v36 = (unsigned __int8 *)v43;
      if ( !v43 )
        goto LABEL_53;
    }
  }
  v40 = v38;
  hdd_put_sta_info_ref(a1 + 4856, &v43, 1, 13);
  if ( v42 )
    hdd_put_sta_info_ref(a1 + 4856, &v42, 1, 13);
  result = v40;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
