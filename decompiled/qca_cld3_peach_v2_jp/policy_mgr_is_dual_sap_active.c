__int64 __fastcall policy_mgr_is_dual_sap_active(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  __int64 v4; // x0
  unsigned int *v5; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  unsigned int *v15; // x8
  __int64 v16; // x0
  unsigned int *v17; // x8
  __int64 v18; // x0
  unsigned int *v19; // x8
  __int64 v20; // x0
  unsigned int *v21; // x8
  unsigned __int8 *v22; // x8
  int v23; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v24; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-20h] BYREF
  int v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v25[0] = 0;
  v25[1] = 0;
  v24 = 0;
  v23 = 0;
  result = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v25, (unsigned __int64)&v23, 1u);
  if ( (_DWORD)result )
  {
    v3 = result;
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned __int8)v23,
           24);
    if ( !v4 )
    {
LABEL_13:
      v22 = (unsigned __int8 *)&v23;
LABEL_19:
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid vdev for id %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "policy_mgr_get_ml_and_non_ml_mode_count",
        *v22);
      goto LABEL_20;
    }
    wlan_objmgr_vdev_release_ref(v4, 0x18u, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( v3 == 1 )
    {
LABEL_20:
      result = 0;
      goto LABEL_21;
    }
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, BYTE1(v23), 24);
    if ( !v14 )
    {
      v22 = (unsigned __int8 *)&v23 + 1;
      goto LABEL_19;
    }
    wlan_objmgr_vdev_release_ref(v14, 0x18u, v15, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( v3 >= 3 )
    {
      v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, BYTE2(v23), 24);
      if ( !v16 )
      {
        v22 = (unsigned __int8 *)&v23 + 2;
        goto LABEL_19;
      }
      wlan_objmgr_vdev_release_ref(v16, 0x18u, v17, v6, v7, v8, v9, v10, v11, v12, v13);
      if ( v3 != 3 )
      {
        v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                HIBYTE(v23),
                24);
        if ( !v18 )
        {
          v22 = (unsigned __int8 *)&v23 + 3;
          goto LABEL_19;
        }
        wlan_objmgr_vdev_release_ref(v18, 0x18u, v19, v6, v7, v8, v9, v10, v11, v12, v13);
        if ( v3 >= 5 )
        {
          v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v24, 24);
          if ( !v20 )
          {
            v22 = &v24;
            goto LABEL_19;
          }
          wlan_objmgr_vdev_release_ref(v20, 0x18u, v21, v6, v7, v8, v9, v10, v11, v12, v13);
          if ( v3 != 5 )
          {
            __break(1u);
            goto LABEL_13;
          }
        }
      }
      goto LABEL_20;
    }
    result = 1;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
