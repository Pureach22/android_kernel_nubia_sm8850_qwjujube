__int64 __fastcall policy_mgr_update_emlsr_inactive_request(__int64 a1, unsigned int a2, unsigned __int8 *a3, char a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  double updated; // d0
  unsigned int *v19; // x8
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _QWORD v28[2]; // [xsp+0h] [xbp-20h] BYREF
  int v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v28[0] = 0;
  v28[1] = 0;
  qdf_mem_set(v28, 0x14u, 0);
  if ( (a4 & 1) == 0 )
  {
    v28[0] = 0x100000004LL;
    LOBYTE(v29) = a2 - 1;
    HIWORD(v29) = ml_nlink_convert_vdev_ids_to_link_bitmap(a1, a3, a2);
  }
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a3, 24);
  if ( v8 )
  {
    v17 = v8;
    updated = ml_nlink_update_force_link_request(a1, v8, v28, 0);
    result = wlan_objmgr_vdev_release_ref(v17, 0x18u, v19, updated, v20, v21, v22, v23, v24, v25, v26);
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: vdev not found for vdev_id %d ",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "policy_mgr_update_emlsr_inactive_request",
               *a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
