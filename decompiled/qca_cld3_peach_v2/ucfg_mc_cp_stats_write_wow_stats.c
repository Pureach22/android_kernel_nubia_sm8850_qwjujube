__int64 __fastcall ucfg_mc_cp_stats_write_wow_stats(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  __int64 v17; // x23
  unsigned int psoc_wake_lock_stats; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v30; // x8
  int v31; // w22
  int v32; // w0
  int v33; // w8
  __int64 v34; // [xsp+88h] [xbp-78h] BYREF
  __int64 v35; // [xsp+90h] [xbp-70h]
  __int64 v36; // [xsp+98h] [xbp-68h]
  __int64 v37; // [xsp+A0h] [xbp-60h]
  __int64 v38; // [xsp+A8h] [xbp-58h]
  __int64 v39; // [xsp+B0h] [xbp-50h]
  __int64 v40; // [xsp+B8h] [xbp-48h]
  __int64 v41; // [xsp+C0h] [xbp-40h]
  __int64 v42; // [xsp+C8h] [xbp-38h]
  __int64 v43; // [xsp+D0h] [xbp-30h]
  __int64 v44; // [xsp+D8h] [xbp-28h]
  __int64 v45; // [xsp+E0h] [xbp-20h]
  __int64 v46; // [xsp+E8h] [xbp-18h]
  __int64 v47; // [xsp+F0h] [xbp-10h]
  __int64 v48; // [xsp+F8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v17 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    psoc_wake_lock_stats = ucfg_mc_cp_stats_get_psoc_wake_lock_stats(
                             a1,
                             (__int64)&v34,
                             a5,
                             a6,
                             a7,
                             a8,
                             a9,
                             a10,
                             a11,
                             a12);
    if ( psoc_wake_lock_stats )
    {
      v27 = psoc_wake_lock_stats;
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Failed to get WoW stats",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "ucfg_mc_cp_stats_write_wow_stats");
      result = v27;
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v17 + 16);
        v30 = *(_QWORD *)(v17 + 24);
      }
      else
      {
        raw_spin_lock_bh(v17 + 16);
        v30 = *(_QWORD *)(v17 + 24) | 1LL;
        *(_QWORD *)(v17 + 24) = v30;
      }
      v31 = *(_DWORD *)(*(_QWORD *)(v17 + 40) + 352LL);
      if ( (v30 & 1) != 0 )
      {
        *(_QWORD *)(v17 + 24) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v17 + 16);
      }
      else
      {
        raw_spin_unlock(v17 + 16);
      }
      scnprintf(
        a2,
        a3,
        "WoW Wake Reasons\n"
        "\tunspecified wake count: %u\n"
        "\tunicast: %u\n"
        "\tbroadcast: %u\n"
        "\tIPv4 multicast: %u\n"
        "\tIPv6 multicast: %u\n"
        "\tIPv6 multicast RA: %u\n"
        "\tIPv6 multicast NS: %u\n"
        "\tIPv6 multicast NA: %u\n"
        "\tIPv6 multicast MLQ: %u\n"
        "\tICMPv4: %u\n"
        "\tICMPv6: %u\n"
        "\tRSSI Breach: %u\n"
        "\tLow RSSI: %u\n"
        "\tG-Scan: %u\n"
        "\tPNO Complete: %u\n"
        "\tPNO Match: %u\n"
        "\tUC Drop wake_count: %u\n"
        "\twake count due to fatal event: %u\n"
        "\tOEM rsp wake_count: %u\n"
        "\twake count due to pwr_save_fail_detected: %u\n"
        "\twake count due to 11d scan: %u\n",
        v31,
        v34,
        HIDWORD(v34),
        v35,
        HIDWORD(v35),
        v36,
        HIDWORD(v36),
        v37,
        HIDWORD(v37),
        v38,
        HIDWORD(v38),
        v39,
        HIDWORD(v39),
        v40,
        HIDWORD(v40),
        v41,
        v42,
        HIDWORD(v42),
        HIDWORD(v41),
        v43,
        HIDWORD(v43));
      v33 = v32;
      result = 0;
      *a4 = v33;
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "ucfg_mc_cp_stats_write_wow_stats");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
