__int64 __fastcall policy_mgr_is_mlo_in_mode_dbs(__int64 a1, unsigned int a2, __int64 a3, unsigned __int8 *a4)
{
  unsigned int mode_specific_conn_info; // w0
  char v8; // w8
  __int64 v9; // x26
  char v10; // w24
  char v11; // w25
  unsigned __int8 v12; // w27
  __int64 v13; // x28
  unsigned int operation_chan_freq; // w0
  _BOOL4 is_24ghz_ch_freq; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  int v36; // [xsp+0h] [xbp-10h] BYREF
  char v37; // [xsp+4h] [xbp-Ch]
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v36 = 0;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v36, a2);
  v8 = 0;
  if ( mode_specific_conn_info >= 2 )
  {
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = mode_specific_conn_info;
    do
    {
      if ( v9 == 5 )
        __break(0x5512u);
      v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *((unsigned __int8 *)&v36 + v9),
              24);
      if ( !v25 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: invalid vdev for id %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "policy_mgr_is_mlo_in_mode_dbs",
          *((unsigned __int8 *)&v36 + v9));
        v8 = 0;
        goto LABEL_14;
      }
      v34 = v25;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v25, v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
      {
        if ( a3 )
          *(_BYTE *)(a3 + v12) = *((_BYTE *)&v36 + v9);
        operation_chan_freq = wlan_get_operation_chan_freq(v34);
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(operation_chan_freq);
        v24 = (unsigned int *)!is_24ghz_ch_freq;
        ++v12;
        v11 |= is_24ghz_ch_freq;
        v10 |= !is_24ghz_ch_freq;
      }
      wlan_objmgr_vdev_release_ref(v34, 0x18u, v24, v16, v17, v18, v19, v20, v21, v22, v23);
      ++v9;
    }
    while ( v13 != v9 );
    if ( a4 )
      *a4 = v12;
    v8 = v11 & v10;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v8 & 1;
}
