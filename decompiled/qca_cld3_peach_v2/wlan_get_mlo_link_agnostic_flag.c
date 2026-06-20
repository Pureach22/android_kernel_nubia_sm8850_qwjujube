__int64 __fastcall wlan_get_mlo_link_agnostic_flag(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  int v13; // w8
  __int64 result; // x0
  unsigned __int8 *v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _BOOL4 v24; // w19
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7

  _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(a1 + 216);
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    goto LABEL_10;
  v13 = *(_DWORD *)(a1 + 16);
  if ( v13 != 1 )
  {
    if ( !v13 && ((mlo_mgr_is_link_switch_in_progress(a1) & 1) != 0 || (mlo_is_mld_vdevs_active(a1) & 1) != 0) )
    {
      result = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x43u);
      if ( result )
      {
        v15 = (unsigned __int8 *)result;
        if ( (unsigned int)qdf_mem_cmp((const void *)(result + 48), a2, 6u)
          && (unsigned int)qdf_mem_cmp(v15 + 792, a2, 6u) )
        {
          v24 = 0;
          result = (__int64)v15;
        }
        else
        {
          if ( a2 )
          {
            v25 = *a2;
            v26 = a2[1];
            v27 = a2[2];
            v28 = a2[5];
          }
          else
          {
            v27 = 0;
            v25 = 0;
            v26 = 0;
            v28 = 0;
          }
          qdf_trace_msg(
            0x1Fu,
            8u,
            "%s: dest address%02x:%02x:%02x:**:**:%02xbss peer address%02x:%02x:%02x:**:**:%02xmld addr%02x:%02x:%02x:**:**:%02x",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "wlan_get_mlo_link_agnostic_flag",
            v25,
            v26,
            v27,
            v28,
            v15[48],
            v15[49],
            v15[50],
            v15[53],
            v15[792],
            v15[793],
            v15[794],
            v15[797]);
          result = (__int64)v15;
          v24 = 1;
        }
        goto LABEL_17;
      }
      goto LABEL_18;
    }
LABEL_10:
    result = 0;
    goto LABEL_18;
  }
  result = (__int64)wlan_objmgr_get_peer_by_mac(*(_QWORD *)(v12 + 80), a2, 0x43u);
  if ( result )
  {
    v24 = (*(_DWORD *)(result + 792) | *(unsigned __int16 *)(result + 796)) != 0;
LABEL_17:
    wlan_objmgr_peer_release_ref(result, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23);
    result = v24;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
