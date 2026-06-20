_QWORD *__fastcall lim_process_ap_assist_dfs_group_p2p_fw_monitor_update(
        unsigned int a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char v21; // w10

  result = _cds_get_context(
             53,
             (__int64)"lim_process_ap_assist_dfs_group_p2p_fw_monitor_update",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( result )
  {
    result = (_QWORD *)pe_find_session_by_vdev_id(result, a1);
    if ( result )
    {
      if ( *((_DWORD *)result + 1759) == 2 )
      {
        if ( (a2 & 1) != 0 )
          v21 = 4;
        else
          v21 = 0;
        *((_BYTE *)result + 10080) = result[1260] & 0xFB | v21;
      }
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x35u,
                         2u,
                         "%s: Session not found for vdev_id: %d",
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         "lim_process_ap_assist_dfs_group_p2p_fw_monitor_update",
                         (unsigned __int8)a1);
    }
  }
  return result;
}
