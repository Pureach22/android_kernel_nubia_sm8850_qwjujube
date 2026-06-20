__int64 __fastcall osif_twt_teardown_in_ps_disable(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v3; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w9
  __int64 v16; // x19
  __int16 v17; // w8
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _DWORD v28[2]; // [xsp+8h] [xbp-18h] BYREF
  int v29; // [xsp+10h] [xbp-10h]
  int v30; // [xsp+14h] [xbp-Ch]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v3 = a3;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 94);
  if ( v6 )
  {
    v15 = *(_DWORD *)a2;
    v16 = v6;
    v30 = 255;
    v17 = *(_WORD *)(a2 + 4);
    v28[0] = v3;
    v28[1] = v15;
    LOWORD(v29) = v17;
    if ( (ucfg_twt_is_setup_done() & 1) != 0 )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev%d: Terminate existing TWT session %d due to ps disable",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "osif_twt_teardown_in_ps_disable",
        v3,
        255);
      if ( (unsigned int)osif_send_sta_twt_teardown_req(a1, v28) )
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: TWT teardown is failed on vdev: %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "osif_twt_teardown_in_ps_disable",
          v3);
        ucfg_twt_set_work_params(v16, (int *)a2, v30, 1, 1);
        queue_work_on(32, system_wq, v16 + 1368);
      }
    }
    result = wlan_objmgr_vdev_release_ref(v16, 0x5Eu, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is NULL",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "osif_twt_teardown_in_ps_disable");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
