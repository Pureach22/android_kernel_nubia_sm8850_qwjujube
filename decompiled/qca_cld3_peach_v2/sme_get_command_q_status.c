unsigned int *__fastcall sme_get_command_q_status(
        unsigned int *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x19
  unsigned int pending_list_count; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  __int64 v45; // x4
  const char *v46; // x2

  if ( result )
  {
    v9 = result;
    pending_list_count = wlan_serialization_get_pending_list_count(
                           *((_QWORD *)result + 2703),
                           0,
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: smeCmdPendingList has %d commands",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "sme_get_command_q_status",
      pending_list_count);
    result = (unsigned int *)wlan_serialization_peek_head_active_cmd_using_psoc(
                               *((_QWORD *)v9 + 2703),
                               0,
                               v19,
                               v20,
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26);
    if ( result )
    {
      v35 = result;
      result = (unsigned int *)qdf_trace_msg(
                                 0x34u,
                                 8u,
                                 "%s: Active commaned is %d cmd id %d source %d",
                                 v27,
                                 v28,
                                 v29,
                                 v30,
                                 v31,
                                 v32,
                                 v33,
                                 v34,
                                 "sme_get_command_q_status",
                                 *result,
                                 result[1],
                                 result[4]);
      if ( !v35[4] )
      {
        v44 = *((_QWORD *)v35 + 5);
        if ( v44 )
        {
          v45 = *(unsigned int *)(v44 + 16);
          if ( (v45 & 0x10000) != 0 )
          {
            if ( (_DWORD)v45 == 65538 )
            {
              v45 = *(unsigned int *)(v44 + 32);
              v46 = "%s: WMStatusChange command type is %d";
            }
            else if ( (_DWORD)v45 == 65537 )
            {
              v45 = *(unsigned int *)(v44 + 32);
              v46 = "%s: roam command reason is %d";
            }
            else
            {
              v46 = "%s: default: Unhandled command %d";
            }
            return (unsigned int *)qdf_trace_msg(
                                     0x34u,
                                     8u,
                                     v46,
                                     v36,
                                     v37,
                                     v38,
                                     v39,
                                     v40,
                                     v41,
                                     v42,
                                     v43,
                                     "dump_csr_command_info",
                                     v45);
          }
        }
      }
    }
  }
  return result;
}
