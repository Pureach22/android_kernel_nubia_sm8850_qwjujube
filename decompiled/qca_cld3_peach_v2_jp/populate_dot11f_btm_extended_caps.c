__int64 __fastcall populate_dot11f_btm_extended_caps(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // [xsp+8h] [xbp-28h] BYREF
  __int64 v43; // [xsp+10h] [xbp-20h]
  __int64 v44; // [xsp+18h] [xbp-18h]
  __int64 v45; // [xsp+20h] [xbp-10h]
  __int64 v46; // [xsp+28h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)a3 = 3841;
  v6 = *(_QWORD *)(a1 + 21552);
  v7 = *(_QWORD *)(a2 + 16);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  if ( (unsigned int)cm_akm_roam_allowed(v6, v7) )
  {
    *(_QWORD *)(a3 + 2) &= ~0x80000uLL;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev:%d, Disable btm for roaming not suppprted",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "populate_dot11f_btm_extended_caps",
      *(unsigned __int8 *)(a2 + 10));
  }
  wlan_cm_roam_cfg_get_value(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10), 0x1Fu, &v42);
  if ( (unsigned __int8)v43 == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev:%d, Disable BTM as BTM roam disabled by user",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "populate_dot11f_btm_extended_caps",
      *(unsigned __int8 *)(a2 + 10));
    *(_QWORD *)(a3 + 2) &= ~0x80000uLL;
  }
  if ( *(_QWORD *)(a2 + 112)
    && (*(_BYTE *)(a3 + 4) & 8) != 0
    && !wlan_vdev_is_open_mode(*(_QWORD *)(a2 + 16))
    && *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4456LL)
    && (*(_BYTE *)(a2 + 7024) & 0x10) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev:%d, Disable BTM as MBO AP doesn't support PMF",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "populate_dot11f_btm_extended_caps",
      *(unsigned __int8 *)(a2 + 10));
    *(_QWORD *)(a3 + 2) &= ~0x80000uLL;
  }
  v32 = lim_compute_ext_cap_ie_length((_BYTE *)a3);
  *(_BYTE *)(a3 + 1) = v32;
  if ( !v32 )
  {
    *(_BYTE *)a3 = 0;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ext ie length become 0, disable the ext caps",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "populate_dot11f_btm_extended_caps");
  }
  wlan_cm_set_assoc_btm_cap(
    *(_QWORD *)(a2 + 16),
    (*(_QWORD *)(a3 + 2) & 0x80000LL) != 0,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40);
  _ReadStatusReg(SP_EL0);
  return 0;
}
