__int64 __fastcall wlan_serialization_remove_cmd_from_queue(
        _QWORD *a1,
        unsigned int *a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        unsigned int a13)
{
  __int64 result; // x0
  _QWORD *cmd; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  _QWORD *v28; // x23
  _QWORD *v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x4
  unsigned int v47; // w19
  unsigned __int64 v54; // x9

  if ( !a2 )
    return 16;
  if ( !a1 || qdf_list_empty(a1) )
  {
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Empty queue",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_serialization_remove_cmd_from_queue");
    return 16;
  }
  cmd = wlan_serialization_find_cmd(
          (__int64)a1,
          3,
          a2,
          0,
          0,
          *((_QWORD *)a2 + 4),
          a13,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11);
  if ( !cmd )
  {
    qdf_trace_msg(
      0x4Cu,
      4u,
      "%s: fail to find node %d for removal",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_serialization_remove_cmd_from_queue",
      a13);
    return 16;
  }
  v27 = 0x1FFFFFFFFFFFFFFELL;
  if ( !a13 )
    v27 = 0;
  v28 = &cmd[v27];
  if ( (cmd[v27 + 10] & 2) == 0 )
  {
    v29 = cmd;
    if ( qdf_list_empty(a1) )
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: The list is empty",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_serialization_remove_node");
      LODWORD(result) = 13;
    }
    else
    {
      result = qdf_list_remove_node((__int64)a1, v29);
      if ( !(_DWORD)result )
      {
LABEL_17:
        *a3 = v28;
        return result;
      }
    }
    v46 = *a2;
    v47 = result;
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Fail to add to free pool type %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_serialization_remove_cmd_from_queue",
      v46);
    result = v47;
    goto LABEL_17;
  }
  _X8 = v28 + 10;
  __asm { PRFM            #0x11, [X8] }
  do
    v54 = __ldxr(_X8);
  while ( __stxr(v54 | 0x10, _X8) );
  return 24;
}
