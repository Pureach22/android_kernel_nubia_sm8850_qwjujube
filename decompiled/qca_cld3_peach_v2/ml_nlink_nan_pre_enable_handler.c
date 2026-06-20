__int64 __fastcall ml_nlink_nan_pre_enable_handler(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _BYTE v39[4]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v40[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v41; // [xsp+8h] [xbp-28h] BYREF
  char v42; // [xsp+Ch] [xbp-24h]
  _QWORD v43[2]; // [xsp+10h] [xbp-20h] BYREF
  int v44; // [xsp+20h] [xbp-10h]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
  if ( (result & 1) != 0 )
  {
    result = wlan_mlme_is_aux_emlsr_support(a1);
    if ( (result & 1) != 0 )
    {
      v40[0] = 0;
      v39[0] = 0;
      v42 = 0;
      v41 = 0;
      v44 = 0;
      v43[0] = 0;
      v43[1] = 0;
      result = policy_mgr_get_ml_sta_info_psoc(a1, v40, v39, (__int64)&v41, (__int64)v43, nullptr, 0, 0);
      if ( (unsigned int)v40[0] - 6 >= 0xFFFFFFFB )
      {
        v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               (unsigned __int8)v41,
               90);
        if ( v3 )
        {
          v12 = v3;
          policy_mgr_wait_for_set_link_update(a1);
          v21 = *(_QWORD *)(v12 + 1360);
          if ( v21 && *(_QWORD *)(v21 + 2224) )
          {
            qdf_mutex_acquire(v21 + 1656);
            *(_DWORD *)(*(_QWORD *)(v21 + 2224) + 1448LL) |= 0x80u;
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: set disable_req to 0x%x from 0x%x by req 0x%x",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              "ml_nlink_set_emlsr_mode_disable_req");
            qdf_mutex_release(v21 + 1656);
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: mlo_ctx or sta_ctx null",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "ml_nlink_set_emlsr_mode_disable_req");
          }
          result = wlan_objmgr_vdev_release_ref(v12, 0x5Au, v30, v31, v32, v33, v34, v35, v36, v37, v38);
        }
        else
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     2u,
                     "%s: invalid vdev for id %d",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "ml_nlink_get_affect_ml_sta",
                     (unsigned __int8)v41);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
