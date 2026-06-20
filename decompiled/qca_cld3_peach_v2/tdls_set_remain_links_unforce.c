__int64 __fastcall tdls_set_remain_links_unforce(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v10; // x19
  __int64 v11; // x20
  bool v12; // zf
  __int64 v13; // x20

  v9 = *(_QWORD *)(result + 1360);
  v10 = result;
  v11 = *(_QWORD *)(v9 + 24);
  if ( v11 )
    v12 = v11 == result;
  else
    v12 = 1;
  if ( !v12 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: try to set vdev %d to unforce",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tdls_set_remain_links_unforce",
      *(unsigned __int8 *)(v11 + 168));
    result = tdls_set_link_unforce(v11);
  }
  v13 = *(_QWORD *)(v9 + 32);
  if ( v13 )
  {
    if ( v13 != v10 )
    {
      qdf_trace_msg(
        0,
        8u,
        "%s: try to set vdev %d to unforce",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "tdls_set_remain_links_unforce",
        *(unsigned __int8 *)(v13 + 168));
      return tdls_set_link_unforce(v13);
    }
  }
  return result;
}
