unsigned __int8 *__fastcall hdd_softap_update_pasn_vdev_params(
        __int64 *a1,
        unsigned __int8 a2,
        __int64 a3,
        char a4,
        char a5)
{
  int v7; // w8
  unsigned __int8 *v8; // x1
  int v9; // w2
  int v11; // w21
  unsigned __int8 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w5
  int v22; // w8
  unsigned int v23; // w21
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int8 *v33; // x22
  unsigned int v34; // w8
  const void *v35; // x1
  __int64 v36; // x22
  size_t v37; // x2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( (a4 & 1) != 0 )
    v7 = 2;
  else
    v7 = 0;
  v8 = *(unsigned __int8 **)(a3 + 8);
  v9 = *(_DWORD *)(a3 + 36);
  if ( (a5 & 1) != 0 )
    v11 = v7 | 4;
  else
    v11 = v7;
  result = wlan_get_ie_ptr_from_eid(0xF4u, v8, v9);
  if ( result )
  {
    if ( result[1] <= 1u )
      return (unsigned __int8 *)qdf_trace_msg(
                                  0x33u,
                                  8u,
                                  "%s: vdev:%d RSNXE len:%d less than expected",
                                  v13,
                                  v14,
                                  v15,
                                  v16,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  "hdd_softap_update_pasn_vdev_params",
                                  a2);
    v21 = result[3];
    if ( (v21 & 5) != 0 )
      v22 = v11 | 8;
    else
      v22 = v11;
    v23 = v22 | (v21 >> 7);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev_id:%d RSNXE Cap: 0x%x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "hdd_softap_update_pasn_vdev_params",
      a2);
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x7Fu, *(unsigned __int8 **)(a3 + 8), *(_DWORD *)(a3 + 36));
    if ( ie_ptr_from_eid )
    {
      v33 = ie_ptr_from_eid;
      result = (unsigned __int8 *)_qdf_mem_malloc(0xEu, "hdd_softap_update_pasn_vdev_params", 7168);
      if ( !result )
        return result;
      v34 = v33[1];
      v35 = v33 + 2;
      v36 = (__int64)result;
      if ( v34 >= 0xE )
        v37 = 14;
      else
        v37 = v34;
      qdf_mem_copy(result, v35, v37);
      v23 = v23 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)(v36 + 12) >> 1) & 1));
      _qdf_mem_free(v36);
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: pasn_vdev_param:0x%x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_softap_update_pasn_vdev_params",
      v23);
    return (unsigned __int8 *)wlan_crypto_vdev_set_param(*a1, v38, v39, v40, v41, v42, v43, v44, v45);
  }
  return result;
}
