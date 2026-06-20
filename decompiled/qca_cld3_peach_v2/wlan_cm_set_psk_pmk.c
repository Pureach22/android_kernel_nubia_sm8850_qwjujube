_QWORD *__fastcall wlan_cm_set_psk_pmk(__int64 a1, char a2, const void *a3, unsigned __int8 a4)
{
  _QWORD *result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *ext_hdl_fl; // x8
  _QWORD *v16; // x21
  __int64 v17; // x2

  result = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( result )
  {
    if ( (result[2] & 0xFFFFFFFD) != 0 )
    {
      ext_hdl_fl = (unsigned int *)&policy_mgr_2_freq_always_on_same_mac___last_ticks;
      wlan_cm_set_psk_pmk_rso_cfg = 0;
    }
    else
    {
      v16 = result;
      ext_hdl_fl = (unsigned int *)cm_get_ext_hdl_fl(
                                     (__int64)result,
                                     (__int64)"wlan_cm_set_psk_pmk",
                                     0x31Cu,
                                     v7,
                                     v8,
                                     v9,
                                     v10,
                                     v11,
                                     v12,
                                     v13,
                                     v14);
      result = v16;
      wlan_cm_set_psk_pmk_rso_cfg = (__int64)ext_hdl_fl;
      if ( ext_hdl_fl )
      {
        qdf_mem_set((char *)ext_hdl_fl + 727, 0x40u, 0);
        if ( a3 )
          qdf_mem_copy((void *)(wlan_cm_set_psk_pmk_rso_cfg + 727), a3, a4);
        v17 = wlan_cm_set_psk_pmk_rso_cfg + 727;
        *(_BYTE *)(wlan_cm_set_psk_pmk_rso_cfg + 791) = a4;
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(31, 8, v17, 2);
        result = v16;
      }
    }
    return (_QWORD *)wlan_objmgr_vdev_release_ref(
                       (__int64)result,
                       0x4Du,
                       ext_hdl_fl,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14);
  }
  return result;
}
