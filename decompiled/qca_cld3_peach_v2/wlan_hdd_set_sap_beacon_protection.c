void *__fastcall wlan_hdd_set_sap_beacon_protection(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *ie_ptr_from_eid; // x0
  void *result; // x0
  const char *v15; // x2
  unsigned __int8 *v16; // x22
  __int64 v17; // x19
  size_t v18; // x2
  __int64 vdev_by_user; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _BYTE v37[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  if ( !a3 )
  {
    v15 = "%s: beacon is null";
LABEL_7:
    result = (void *)qdf_trace_msg(
                       0x33u,
                       2u,
                       v15,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       "wlan_hdd_set_sap_beacon_protection");
    goto LABEL_8;
  }
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x7Fu, *(unsigned __int8 **)(a3 + 8), *(_DWORD *)(a3 + 36));
  if ( !ie_ptr_from_eid )
  {
    v15 = "%s: IE is null";
    goto LABEL_7;
  }
  if ( (unsigned int)ie_ptr_from_eid[1] - 16 > 0xFFFFFFF0 )
  {
    v16 = ie_ptr_from_eid;
    result = (void *)_qdf_mem_malloc(0xEu, "wlan_hdd_set_sap_beacon_protection", 20096);
    if ( result )
    {
      v17 = (__int64)result;
      if ( v16[1] >= 0xEu )
        v18 = 14;
      else
        v18 = v16[1];
      qdf_mem_copy(result, v16 + 2, v18);
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a2, 5, "wlan_hdd_set_sap_beacon_protection");
      if ( vdev_by_user )
      {
        v28 = vdev_by_user;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d beacon protection %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_hdd_set_sap_beacon_protection",
          *(unsigned __int8 *)(vdev_by_user + 168),
          (*(unsigned __int8 *)(v17 + 10) >> 4) & 1);
        wlan_mlme_get_bigtk_support(*a1, v37);
        if ( v37[0] == 1 && (*(_BYTE *)(v17 + 10) & 0x10) != 0 )
          mlme_set_bigtk_support(v28, 1, v29, v30, v31, v32, v33, v34, v35, v36);
        _hdd_objmgr_put_vdev_by_user(v28, 5, "wlan_hdd_set_sap_beacon_protection");
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: vdev is null",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_hdd_set_sap_beacon_protection");
      }
      result = (void *)_qdf_mem_free(v17);
    }
  }
  else
  {
    result = (void *)qdf_trace_msg(
                       0x33u,
                       2u,
                       "%s: Invalid IEs eid: %d elem_len: %d",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       "wlan_hdd_set_sap_beacon_protection",
                       *ie_ptr_from_eid);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
