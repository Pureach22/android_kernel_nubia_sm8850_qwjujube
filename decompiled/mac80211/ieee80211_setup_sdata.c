__int64 __fastcall ieee80211_setup_sdata(__int64 a1, int a2)
{
  __int64 v2; // x20
  __int64 v5; // x23
  __int64 v6; // x9

  v2 = a1 + 2264;
  v5 = a1 + 4096;
  memset((void *)(a1 + 2264), 0, 0x548u);
  memset((void *)(a1 + 4152), 0, 0x160u);
  v6 = *(_QWORD *)(a1 + 1608);
  *(_DWORD *)(a1 + 1940) = 36488;
  *(_DWORD *)(a1 + 4720) = a2;
  *(_BYTE *)(v5 + 1752) = 0;
  *(_DWORD *)(a1 + 24) = a2;
  *(_BYTE *)(a1 + 1944) = 0;
  *(_BYTE *)(v5 + 705) = 1;
  *(_DWORD *)(a1 + 5036) = 0x80000000;
  *(_WORD *)(a1 + 1888) = 0;
  if ( v6 )
  {
    *(_QWORD *)(v6 + 8) = &ieee80211_dataif_ops;
    *(_WORD *)(*(_QWORD *)(a1 + 1608) + 544LL) = 1;
  }
  *(_QWORD *)(a1 + 2000) = 0;
  *(_QWORD *)(a1 + 1984) = a1 + 1984;
  *(_QWORD *)(a1 + 1992) = a1 + 1984;
  *(_QWORD *)(a1 + 2008) = a1 + 2008;
  *(_QWORD *)(a1 + 2016) = a1 + 2008;
  *(_QWORD *)(a1 + 2024) = 0;
  *(_QWORD *)(a1 + 1960) = a1 + 1960;
  *(_QWORD *)(a1 + 1968) = a1 + 1960;
  *(_QWORD *)(a1 + 1976) = ieee80211_iface_work;
  *(_QWORD *)(a1 + 4688) = a1 + 4688;
  *(_QWORD *)(a1 + 4696) = a1 + 4688;
  *(_QWORD *)(a1 + 4704) = &ieee80211_activate_links_work;
  switch ( a2 )
  {
    case 0:
    case 5:
    case 13:
      __break(0x800u);
      return ieee80211_link_setup(a1 + 3616);
    case 1:
      *(_QWORD *)(a1 + 4824) = a1 + 2346;
      ieee80211_ibss_setup_sdata(a1);
      return ieee80211_link_setup(a1 + 3616);
    case 2:
      goto LABEL_12;
    case 3:
      goto LABEL_6;
    case 4:
    case 10:
      goto LABEL_7;
    case 6:
      *(_WORD *)(*(_QWORD *)(a1 + 1608) + 544LL) = 803;
      *(_QWORD *)(*(_QWORD *)(a1 + 1608) + 8LL) = &ieee80211_monitorif_ops;
      *(_DWORD *)(a1 + 2264) = 24;
      return ieee80211_link_setup(a1 + 3616);
    case 8:
      *(_DWORD *)(a1 + 4720) = 2;
      *(_BYTE *)(v5 + 1752) = 1;
LABEL_12:
      *(_QWORD *)(a1 + 4824) = a1 + 4152;
      ieee80211_sta_setup_sdata(a1);
      return ieee80211_link_setup(a1 + 3616);
    case 9:
      *(_DWORD *)(a1 + 4720) = 3;
      *(_BYTE *)(v5 + 1752) = 1;
LABEL_6:
      *(_QWORD *)(a1 + 2552) = 0;
      *(_QWORD *)(a1 + 2536) = a1 + 2536;
      *(_QWORD *)(a1 + 2544) = a1 + 2536;
      *(_QWORD *)(a1 + 2264) = a1 + 2264;
      *(_QWORD *)(a1 + 2272) = v2;
LABEL_7:
      *(_QWORD *)(a1 + 4824) = a1 + 5842;
      break;
    case 11:
      *(_QWORD *)(a1 + 4824) = &ieee80211_setup_sdata_bssid_wildcard;
      ieee80211_ocb_setup_sdata(a1);
      break;
    case 12:
      *(_QWORD *)(a1 + 2280) = 0;
      *(_QWORD *)(a1 + 2288) = 0;
      *(_DWORD *)(a1 + 2276) = 268435460;
      *(_QWORD *)(a1 + 2268) = 0;
      *(_QWORD *)(a1 + 4824) = a1 + 5842;
      break;
    default:
      return ieee80211_link_setup(a1 + 3616);
  }
  return ieee80211_link_setup(a1 + 3616);
}
