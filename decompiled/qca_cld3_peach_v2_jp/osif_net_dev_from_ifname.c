__int64 __fastcall osif_net_dev_from_ifname(__int64 a1, __int64 a2, _QWORD *a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x8
  __int64 v21; // x20
  __int64 result; // x0
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = a2;
  v24 = 0;
  wlan_objmgr_iterate_obj_list(a1, 2, os_if_get_ndi_vdev_by_ifname_cb, (__int64)&v23, 0, 0x14u);
  if ( !v24 || (unsigned int)wlan_objmgr_vdev_try_get_ref(v24, 0x14u, v4, v5, v6, v7, v8, v9, v10, v11) || !v24 )
    goto LABEL_9;
  v20 = *(unsigned int **)(v24 + 608);
  if ( !v20 || (v20 = *(unsigned int **)v20) == nullptr || (v21 = *((_QWORD *)v20 + 4)) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v24, 0x14u, v20, v12, v13, v14, v15, v16, v17, v18, v19);
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  wlan_objmgr_vdev_release_ref(v24, 0x14u, v20, v12, v13, v14, v15, v16, v17, v18, v19);
  result = 0;
  *a3 = v21;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
