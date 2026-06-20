__int64 __fastcall cm_remove_cmd(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x4
  const char *v12; // x2
  unsigned int v13; // w1
  __int64 result; // x0
  __int64 v15; // x9
  unsigned int v17; // w20

  if ( !a2 )
    return qdf_trace_msg(0x68u, 2u, "%s: cm_id_to_remove is null", a3, a4, a5, a6, a7, a8, a9, a10, "cm_remove_cmd");
  v10 = *a1;
  if ( *a2 + 1 > 1 )
  {
    v15 = *(_QWORD *)(v10 + 152);
    if ( !v15 || !*(_QWORD *)(v15 + 80) )
    {
      v11 = *(unsigned __int8 *)(v10 + 104);
      v12 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
      v13 = 2;
      return qdf_trace_msg(0x68u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "cm_remove_cmd", v11);
    }
    v17 = *a2;
    result = cm_delete_req_from_list((__int64)a1, *a2);
    if ( (_DWORD)result )
      return result;
    if ( (v17 & 0x10000000) != 0 )
    {
      v12 = "%s: vdev %d cm_id 0x%x: Skip cmd remove for link switch connect/disconnect";
      v11 = *(unsigned __int8 *)(*a1 + 104);
    }
    else
    {
      if ( (v17 & 0x20000000) == 0 )
        return cm_remove_cmd_from_serialization(a1, v17);
      v12 = "%s: vdev %d cm_id 0x%x: Skip cmd for link add connect";
      v11 = *(unsigned __int8 *)(*a1 + 104);
    }
  }
  else
  {
    v11 = *(unsigned __int8 *)(v10 + 104);
    v12 = "%s: vdev %d cm_id 0x%x:  Invalid cm_id";
  }
  v13 = 8;
  return qdf_trace_msg(0x68u, v13, v12, a3, a4, a5, a6, a7, a8, a9, a10, "cm_remove_cmd", v11);
}
