__int64 __fastcall cm_update_scan_db_on_roam_success(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  __int64 v17; // x23
  __int64 src_addr_from_frame; // x0
  int v19; // w0
  __int64 v20; // x0
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x9
  char v31; // w10
  __int64 v32; // x8
  __int64 v33; // x9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD v42[4]; // [xsp+0h] [xbp-30h] BYREF
  char v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = cm_get_cm_ctx_fl(a1, (__int64)"cm_update_scan_db_on_roam_success", 0x48Fu, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v17 = result;
    if ( *(_DWORD *)(a2 + 88) )
    {
      src_addr_from_frame = wlan_mlme_get_src_addr_from_frame(a2 + 88);
      v19 = ((__int64 (__fastcall *)(__int64, __int64))mlo_roam_get_link_freq_from_mac_addr)(a3, src_addr_from_frame);
      cm_inform_bcn_probe(v17, *(_BYTE **)(a2 + 96), *(_DWORD *)(a2 + 88), v19, *(char *)(a3 + 60), a4);
    }
    v20 = wlan_mlme_get_src_addr_from_frame(a2 + 72);
    v21 = ((__int64 (__fastcall *)(__int64, __int64))mlo_roam_get_link_freq_from_mac_addr)(a3, v20);
    if ( v21 )
      cm_inform_bcn_probe(v17, *(_BYTE **)(a2 + 80), *(_DWORD *)(a2 + 72), v21, *(char *)(a3 + 60), a4);
    cm_update_scan_mlme_on_roam(a1, (int *)(a2 + 8), 2, v22, v23, v24, v25, v26, v27, v28, v29);
    v30 = *(_QWORD *)(a2 + 38);
    v31 = *(_BYTE *)(a2 + 46);
    v42[2] = *(_QWORD *)(a2 + 30);
    v42[3] = v30;
    v32 = *(_QWORD *)(a2 + 22);
    v33 = *(_QWORD *)(a2 + 14);
    v43 = v31;
    v42[0] = v33;
    v42[1] = v32;
    result = cm_standby_link_update_mlme_by_bssid(a1, 2, (unsigned __int8 *)v42, v34, v35, v36, v37, v38, v39, v40, v41);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
