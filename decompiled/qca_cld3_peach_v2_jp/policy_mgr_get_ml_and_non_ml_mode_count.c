__int64 __fastcall policy_mgr_get_ml_and_non_ml_mode_count(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        _BYTE *a4,
        __int64 a5,
        unsigned __int64 a6,
        unsigned __int64 a7,
        unsigned int a8)
{
  __int64 result; // x0
  unsigned int v14; // w24
  unsigned __int8 v15; // w25
  unsigned int *v16; // x8
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  *a2 = 0;
  *a4 = 0;
  result = policy_mgr_get_mode_specific_conn_info(a1, a6, a7, a8);
  if ( (_DWORD)result )
  {
    v14 = result;
    v15 = 0;
    while ( 1 )
    {
      v17 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *(unsigned __int8 *)(a7 + v15),
              24);
      if ( !v17 )
        break;
      if ( a5 )
        *(_BYTE *)(a5 + (unsigned __int8)*a4) = v15;
      v16 = (unsigned int *)((unsigned int)(unsigned __int8)(*a4)++ + 1);
      result = wlan_objmgr_vdev_release_ref(v17, 0x18u, v16, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( v14 <= ++v15 )
        return result;
    }
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: invalid vdev for id %d",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "policy_mgr_get_ml_and_non_ml_mode_count",
               *(unsigned __int8 *)(a7 + v15));
    *a2 = 0;
    *a4 = 0;
  }
  return result;
}
