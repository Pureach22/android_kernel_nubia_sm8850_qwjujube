__int64 __fastcall lim_populate_mcs_set_vht_per_vdev(__int64 a1, _WORD *a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 ini_vdev_config; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x9
  unsigned int v26; // w10
  __int64 v27; // x11
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned int *v30; // x8

  v6 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21624),
         a3,
         1);
  if ( !v6 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Got NULL vdev obj, returning",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "lim_populate_mcs_set_vht_per_vdev");
  v15 = v6;
  ini_vdev_config = mlme_get_ini_vdev_config(v6, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( ini_vdev_config )
  {
    v25 = ini_vdev_config + 4LL * a4;
    a2[5] |= -1LL << (2 * *(_BYTE *)(v25 + 16));
    LODWORD(v25) = *(_DWORD *)(v25 + 16);
    v26 = v25 - 1;
    if ( (unsigned int)v25 > 2 )
      v26 = 1;
    if ( v26 >= 4
      || ((v27 = ini_vdev_config + 4LL * a4,
           a2[6] = vht_supported_datarate_bw80_gi400ns[v26],
           a2[3] |= -1LL << (2 * *(_BYTE *)(v27 + 24)),
           v28 = *(_DWORD *)(v27 + 24),
           v28 > 2)
        ? (v29 = 1)
        : (v29 = v28 - 1),
          v29 > 3) )
    {
      __break(0x5512u);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      _ReadStatusReg(CNTVCTSS_EL0);
      JUMPOUT(0x16D5E20);
    }
    v30 = (unsigned int *)(unsigned int)vht_supported_datarate_bw80_gi400ns[v29];
    a2[4] = (_WORD)v30;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: nss chain dynamic config NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_populate_mcs_set_vht_per_vdev");
  }
  return wlan_objmgr_vdev_release_ref(v15, 1u, v30, v17, v18, v19, v20, v21, v22, v23, v24);
}
