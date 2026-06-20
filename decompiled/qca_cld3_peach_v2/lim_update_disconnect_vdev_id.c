__int64 __fastcall lim_update_disconnect_vdev_id(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8

  result = pe_find_session_by_vdev_id(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Session is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_update_disconnect_vdev_id");
  if ( *(_QWORD *)(result + 16) )
  {
    v21 = *(_DWORD **)(a1 + 14704);
    if ( v21 )
    {
      if ( *(v21 - 1) != 2130452855 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, __int64))v21)(a2, 1);
    }
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: disconnect received on vdev id %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_update_disconnect_vdev_id",
             (unsigned __int8)a2);
  }
  return result;
}
