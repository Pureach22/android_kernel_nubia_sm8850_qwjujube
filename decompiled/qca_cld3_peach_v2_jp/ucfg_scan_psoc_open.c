__int64 __fastcall ucfg_scan_psoc_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _BYTE *v27; // x22
  __int64 v28; // x21
  __int64 v29; // x20
  unsigned __int8 v30; // w8
  int v31; // w10
  int v32; // w9
  int v33; // w8
  __int64 values; // x0
  int v35; // w8
  __int64 v36; // x0
  __int16 v37; // w10
  int v38; // w8
  int v39; // w9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v49; // x2

  qdf_trace_msg(0x15u, 8u, "%s: psoc open: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_scan_psoc_open", a1);
  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      *(_DWORD *)comp_private_obj = 0;
      v27 = (_BYTE *)(comp_private_obj + 23986);
      v28 = comp_private_obj + 18345;
      v29 = comp_private_obj;
      *(_BYTE *)(comp_private_obj + 18739) = *(_BYTE *)(cfg_psoc_get_values(a1) + 24);
      v30 = *(_BYTE *)(cfg_psoc_get_values(a1) + 25);
      *(_BYTE *)(v28 + 393) = 0;
      *(_WORD *)(v28 + 395) = v30;
      *(_DWORD *)(v29 + 1600) = *(_DWORD *)(cfg_psoc_get_values(a1) + 28);
      *(_BYTE *)(v29 + 1604) = *(_BYTE *)(cfg_psoc_get_values(a1) + 34) ^ 1;
      *(_BYTE *)(v29 + 1605) = *(_BYTE *)(cfg_psoc_get_values(a1) + 32);
      *(_BYTE *)(v29 + 1606) = *(_BYTE *)(cfg_psoc_get_values(a1) + 136);
      *(_BYTE *)(v29 + 1607) = *(_BYTE *)(cfg_psoc_get_values(a1) + 26);
      *(_DWORD *)(v29 + 1608) = *(_DWORD *)(cfg_psoc_get_values(a1) + 36);
      *(_DWORD *)(v29 + 1612) = *(_DWORD *)(cfg_psoc_get_values(a1) + 44);
      *(_DWORD *)(v29 + 1616) = *(_DWORD *)(cfg_psoc_get_values(a1) + 48);
      *(_DWORD *)(v29 + 1620) = *(_DWORD *)(cfg_psoc_get_values(a1) + 52);
      *(_DWORD *)(v29 + 1624) = *(_DWORD *)(cfg_psoc_get_values(a1) + 56);
      *(_DWORD *)(v29 + 1628) = *(_DWORD *)(cfg_psoc_get_values(a1) + 60);
      v31 = *(_DWORD *)(cfg_psoc_get_values(a1) + 40);
      *(_QWORD *)(v29 + 1636) = 0x19000000000LL;
      *(_DWORD *)(v29 + 1632) = v31;
      *(_DWORD *)(v29 + 1644) = 0;
      *(_DWORD *)(v29 + 1652) = *(_DWORD *)(cfg_psoc_get_values(a1) + 88);
      *(_DWORD *)(v29 + 1656) = *(_DWORD *)(cfg_psoc_get_values(a1) + 84);
      *(_DWORD *)(v29 + 1660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 92);
      *(_DWORD *)(v29 + 1664) = *(_DWORD *)(cfg_psoc_get_values(a1) + 96);
      *(_DWORD *)(v29 + 1668) = *(_DWORD *)(cfg_psoc_get_values(a1) + 100);
      *(_BYTE *)(v29 + 1672) = *(_BYTE *)(cfg_psoc_get_values(a1) + 104);
      v32 = *(_DWORD *)(cfg_psoc_get_values(a1) + 68);
      *(_QWORD *)(v29 + 1680) = 0;
      *(_DWORD *)(v29 + 1676) = v32;
      *(_QWORD *)(v29 + 1688) = 0x753000000000LL;
      *(_DWORD *)(v29 + 1696) = *(_DWORD *)(cfg_psoc_get_values(a1) + 64);
      v33 = *(_DWORD *)(cfg_psoc_get_values(a1) + 108);
      *(_WORD *)(v29 + 1728) = 100;
      *(_DWORD *)(v29 + 1648) = 0;
      *(_DWORD *)(v29 + 1748) = 1;
      *(_QWORD *)(v29 + 1704) = (unsigned int)(1000 * v33);
      *(_DWORD *)(v29 + 1752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 72);
      *(_DWORD *)(v29 + 1756) = *(_DWORD *)(cfg_psoc_get_values(a1) + 76);
      *(_BYTE *)(v29 + 1760) = *(_BYTE *)(cfg_psoc_get_values(a1) + 80);
      *(_BYTE *)(v29 + 1716) = *(_BYTE *)(cfg_psoc_get_values(a1) + 105);
      *(_DWORD *)(v29 + 1764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 112);
      *(_BYTE *)(v29 + 1736) = *(_DWORD *)(cfg_psoc_get_values(a1) + 116);
      *(_BYTE *)(v29 + 1737) = *(_DWORD *)(cfg_psoc_get_values(a1) + 120);
      *(_BYTE *)(v29 + 1738) = *(_DWORD *)(cfg_psoc_get_values(a1) + 124);
      values = cfg_psoc_get_values(a1);
      v35 = *(_DWORD *)(v29 + 1776) | 0xC00009;
      *(_BYTE *)(v29 + 1739) = *(_DWORD *)(values + 132);
      *(_DWORD *)(v29 + 1776) = v35;
      v36 = cfg_psoc_get_values(a1);
      v37 = *(_WORD *)(v29 + 1780);
      *(_DWORD *)(v29 + 1776) = *(_DWORD *)(v29 + 1776) & 0xFFFFFFEF | (16 * (*(_BYTE *)(v36 + 128) & 1));
      *(_WORD *)(v29 + 1780) = v37 | 0x1FF;
      *(_BYTE *)(v29 + 1745) = *(_BYTE *)(cfg_psoc_get_values(a1) + 33);
      *(_DWORD *)(v29 + 1740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 140);
      *(_BYTE *)(v29 + 1744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 144);
      *v27 = *(_BYTE *)(cfg_psoc_get_values(a1) + 148);
      *(_BYTE *)(v29 + 1768) = *(_BYTE *)(cfg_psoc_get_values(a1) + 149);
      v38 = *(_DWORD *)(cfg_psoc_get_values(a1) + 216);
      v27[1] = 0;
      *(_DWORD *)(v29 + 1772) = v38;
      *(_QWORD *)(v29 + 1784) = *(unsigned int *)(cfg_psoc_get_values(a1) + 220);
      *(_DWORD *)(v29 + 24) = 0;
      _qdf_wake_lock_create((_QWORD *)(v29 + 18384), (__int64)"wlan_pno_wl");
      _qdf_runtime_lock_init((__int64 *)(v29 + 18584), "&pno_def->pno_runtime_pm_lock");
      *(_BYTE *)v28 = *(_BYTE *)(cfg_psoc_get_values(a1) + 172);
      *(_BYTE *)(v28 + 1) = *(_DWORD *)(cfg_psoc_get_values(a1) + 176);
      *(_BYTE *)(v28 + 2) = *(_DWORD *)(cfg_psoc_get_values(a1) + 180);
      *(_DWORD *)(v28 + 7) = *(_DWORD *)(cfg_psoc_get_values(a1) + 184);
      *(_DWORD *)(v28 + 3) = *(_DWORD *)(cfg_psoc_get_values(a1) + 188);
      *(_BYTE *)(v28 + 11) = *(_BYTE *)(cfg_psoc_get_values(a1) + 161);
      *(_BYTE *)(v28 + 12) = *(_BYTE *)(cfg_psoc_get_values(a1) + 160);
      *(_DWORD *)(v28 + 15) = *(_DWORD *)(cfg_psoc_get_values(a1) + 164);
      *(_DWORD *)(v28 + 19) = *(_DWORD *)(cfg_psoc_get_values(a1) + 168);
      *(_BYTE *)(v28 + 31) = *(_DWORD *)(cfg_psoc_get_values(a1) + 192);
      *(_DWORD *)(v28 + 23) = *(_DWORD *)(cfg_psoc_get_values(a1) + 156);
      *(_DWORD *)(v28 + 27) = *(_DWORD *)(cfg_psoc_get_values(a1) + 152);
      *(_BYTE *)(v28 + 279) = *(_BYTE *)(cfg_psoc_get_values(a1) + 212);
      *(_BYTE *)(v28 + 264) = *(_BYTE *)(cfg_psoc_get_values(a1) + 196);
      *(_DWORD *)(v28 + 267) = *(_DWORD *)(cfg_psoc_get_values(a1) + 200);
      *(_DWORD *)(v28 + 271) = *(_DWORD *)(cfg_psoc_get_values(a1) + 204);
      v39 = *(_DWORD *)(cfg_psoc_get_values(a1) + 208);
      *(_DWORD *)(v29 + 8) = 0;
      *(_DWORD *)(v28 + 275) = v39;
      *(_QWORD *)(v29 + 16) = 0;
      pmo_register_suspend_handler(3, ucfg_scan_suspend_handler, 0);
      v40 = pmo_register_resume_handler(3, ucfg_scan_resume_handler, 0);
      scm_db_init(a1, v40, v41, v42, v43, v44, v45, v46, v47);
      scm_channel_list_db_init(a1);
      return 0;
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_psoc_get_scan_obj_fl",
      "ucfg_scan_psoc_open",
      1339);
    v49 = "%s: Failed to get scan object";
  }
  else
  {
    v49 = "%s: null psoc";
  }
  qdf_trace_msg(0x15u, 2u, v49, v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_scan_psoc_open");
  return 16;
}
