__int64 __fastcall hdd_stop_sap_set_tx_power(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 psoc_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x25
  unsigned int v26; // w22
  __int64 v27; // x26
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  __int64 v38; // x25
  __int64 v39; // x27
  __int64 channel_reg_power_for_freq; // x4
  __int64 v41; // x8
  const char *v42; // x2
  unsigned int v43; // w0
  int v44; // w9
  int v45; // w8

  result = _hdd_objmgr_get_vdev_by_user(a2, 6, "hdd_stop_sap_set_tx_power");
  if ( result )
  {
    v5 = *a2;
    v6 = *(_QWORD *)(result + 216);
    v7 = *(_QWORD *)(*a2 + 24);
    _hdd_objmgr_put_vdev_by_user(result, 6, "hdd_stop_sap_set_tx_power");
    psoc_obj = reg_get_psoc_obj(a1, v8, v9, v10, v11, v12, v13, v14, v15);
    if ( !psoc_obj )
    {
      v42 = "%s: reg psoc private obj is NULL";
      v43 = 81;
      return qdf_trace_msg(v43, 2u, v42, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_stop_sap_set_tx_power");
    }
    v25 = (unsigned int *)a2[34];
    if ( !v25 )
    {
      v42 = "%s: Invalid sap_ctx";
LABEL_22:
      v43 = 51;
      return qdf_trace_msg(v43, 2u, v42, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_stop_sap_set_tx_power");
    }
    v26 = *(_DWORD *)(v7 + 2496);
    v27 = psoc_obj;
    v28 = *v25;
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: vdev id %d Restriction_mask %d CSA reason %d ",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "hdd_stop_sap_set_tx_power",
               *((unsigned __int8 *)a2 + 8),
               v26,
               v25[183]);
    if ( v25[183] == 6 )
    {
      if ( (v26 & 2) != 0 )
        return queue_work_on(32, system_wq, a2 + 757);
      v37 = *((unsigned __int16 *)a2 + 358);
      v38 = *((unsigned int *)a2 + 178);
      v39 = *(unsigned __int16 *)(v27 + 91684);
      channel_reg_power_for_freq = (unsigned __int8)wlan_reg_get_channel_reg_power_for_freq(
                                                      v6,
                                                      v28,
                                                      v29,
                                                      v30,
                                                      v31,
                                                      v32,
                                                      v33,
                                                      v34,
                                                      v35,
                                                      v36);
      if ( v39 )
      {
        v41 = 0;
        while ( 1 )
        {
          if ( v41 == 102 )
          {
            __break(0x5512u);
            return hdd_sap_restart_with_channel_switch();
          }
          if ( v28 == *(unsigned __int16 *)(v27 + 91686 + 2 * v41) )
            break;
          if ( v39 == ++v41 )
            goto LABEL_20;
        }
        v44 = *(_DWORD *)(v27 + 4 * v41 + 91892);
        v45 = *(unsigned __int8 *)(v27 + v41 + 92300);
        if ( v44 >= (int)channel_reg_power_for_freq )
          v44 = channel_reg_power_for_freq;
        if ( v45 )
          channel_reg_power_for_freq = (unsigned int)v44;
        else
          channel_reg_power_for_freq = (unsigned int)channel_reg_power_for_freq;
      }
LABEL_20:
      result = sme_set_tx_power(
                 *(_QWORD *)(v7 + 16),
                 *((unsigned __int8 *)a2 + 8),
                 (v38 | (v37 << 32)) & 0xFFFFFFFFFFFFLL,
                 *(unsigned int *)(v5 + 40),
                 channel_reg_power_for_freq);
      if ( (_DWORD)result )
      {
        v42 = "%s: Setting tx power failed";
        goto LABEL_22;
      }
    }
  }
  return result;
}
