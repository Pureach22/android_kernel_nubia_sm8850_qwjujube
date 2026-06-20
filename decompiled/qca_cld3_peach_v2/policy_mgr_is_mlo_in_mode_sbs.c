__int64 __fastcall policy_mgr_is_mlo_in_mode_sbs(__int64 a1, unsigned int a2, __int64 a3, _BYTE *a4)
{
  unsigned int mode_specific_conn_info; // w8
  __int64 result; // x0
  __int64 v9; // x26
  unsigned __int64 v10; // x24
  __int64 v11; // x27
  char v12; // w25
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  _BOOL8 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int operation_chan_freq; // w0
  unsigned int v33; // w20
  unsigned int v34; // w21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // [xsp+8h] [xbp-28h] BYREF
  char v44; // [xsp+Ch] [xbp-24h]
  _QWORD v45[2]; // [xsp+10h] [xbp-20h]
  int v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v45[0] = 0;
  v45[1] = 0;
  v44 = 0;
  v43 = 0;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v43, a2);
  result = 0;
  if ( mode_specific_conn_info >= 2 )
  {
    v9 = 0;
    v10 = 0;
    v11 = mode_specific_conn_info;
    v12 = 1;
    do
    {
      if ( v9 == 5 )
LABEL_23:
        __break(0x5512u);
      v13 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *((unsigned __int8 *)&v43 + v9),
              24);
      if ( !v13 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: invalid vdev for id %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "policy_mgr_is_mlo_in_mode_sbs",
          *((unsigned __int8 *)&v43 + v9));
LABEL_20:
        result = 0;
        goto LABEL_21;
      }
      v22 = v13;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v13, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      {
        if ( a3 )
          *(_BYTE *)(a3 + v10) = *((_BYTE *)&v43 + v9);
        operation_chan_freq = wlan_get_operation_chan_freq(v22);
        if ( v10 > 4 )
          goto LABEL_23;
        *((_DWORD *)v45 + v10) = operation_chan_freq;
        v23 = !wlan_reg_is_24ghz_ch_freq(operation_chan_freq);
        ++v10;
        v12 &= v23;
      }
      wlan_objmgr_vdev_release_ref(v22, 0x18u, (unsigned int *)v23, v24, v25, v26, v27, v28, v29, v30, v31);
      ++v9;
    }
    while ( v11 != v9 );
    if ( a4 )
      *a4 = v10;
    if ( ((v10 > 1) & (unsigned __int8)v12) != 1 )
      goto LABEL_20;
    v33 = v45[0];
    v34 = HIDWORD(v45[0]);
    if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0
      || wlan_reg_is_24ghz_ch_freq(v33)
      || wlan_reg_is_24ghz_ch_freq(v34)
      || (policy_mgr_2_freq_same_mac_in_sbs(a1, v33, v34) & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Freq %d and %d are not SBS, set SBS false",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "policy_mgr_is_mlo_in_mode_sbs",
        v33,
        v34);
      goto LABEL_20;
    }
    result = 1;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
