__int64 __fastcall wlan_sap_check_n_update_ccfs2_for_320(__int64 a1, unsigned __int8 a2, int a3, _DWORD *a4)
{
  unsigned int scc_vdev_id; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  _QWORD v16[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v16[0] = 0;
  v16[1] = 0;
  scc_vdev_id = policy_mgr_fetch_scc_vdev_id(a1, a2, a3);
  result = wlan_get_chan_by_vdev_id(a1, scc_vdev_id, v16, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( !(_DWORD)result && (_DWORD)v18 == 7 && *a4 != HIDWORD(v17) )
    *a4 = HIDWORD(v17);
  _ReadStatusReg(SP_EL0);
  return result;
}
