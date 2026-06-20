__int64 __fastcall ml_nlink_nan_post_disable_handler(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  unsigned int *v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _BYTE v23[4]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v24[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v25; // [xsp+8h] [xbp-28h] BYREF
  char v26; // [xsp+Ch] [xbp-24h]
  _QWORD v27[2]; // [xsp+10h] [xbp-20h] BYREF
  int v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
  if ( (result & 1) != 0 )
  {
    result = wlan_mlme_is_aux_emlsr_support(a1);
    if ( (result & 1) != 0 )
    {
      v24[0] = 0;
      v23[0] = 0;
      v26 = 0;
      v25 = 0;
      v28 = 0;
      v27[0] = 0;
      v27[1] = 0;
      result = policy_mgr_get_ml_sta_info_psoc(a1, v24, v23, (__int64)&v25, (__int64)v27, nullptr, 0, 0);
      if ( (unsigned int)v24[0] - 6 >= 0xFFFFFFFB )
      {
        v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               (unsigned __int8)v25,
               90);
        if ( v3 )
        {
          v13 = *(_QWORD *)(v3 + 1360);
          if ( v13 )
          {
            v4 = *(unsigned int **)(v13 + 2224);
            if ( v4 )
            {
              v14 = v3;
              qdf_mutex_acquire(v13 + 1656);
              *(_DWORD *)(*(_QWORD *)(v13 + 2224) + 1448LL) &= ~0x80u;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: clr disable_req to 0x%x from 0x%x by req 0x%x",
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                "ml_nlink_clr_emlsr_mode_disable_req");
              qdf_mutex_release(v13 + 1656);
              v3 = v14;
            }
          }
          result = wlan_objmgr_vdev_release_ref(v3, 0x5Au, v4, v5, v6, v7, v8, v9, v10, v11, v12);
        }
        else
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     2u,
                     "%s: invalid vdev for id %d",
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     "ml_nlink_get_affect_ml_sta",
                     (unsigned __int8)v25);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
