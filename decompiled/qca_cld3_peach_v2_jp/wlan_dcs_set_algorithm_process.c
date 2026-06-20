__int64 __fastcall wlan_dcs_set_algorithm_process(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  const char *v14; // x2
  __int64 v15; // x19

  if ( !a1 )
  {
    v14 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x74u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_dcs_get_pdev_private_obj");
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dcs_set_algorithm_process");
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !result )
  {
    v14 = "%s: dcs psoc object is null";
    goto LABEL_7;
  }
  if ( a2 >= 3 )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: invalid pdev_id: %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_dcs_get_pdev_private_obj",
      a2);
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dcs_set_algorithm_process");
  }
  v15 = result + 384LL * a2;
  if ( !v15 )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: dcs pdev private object is null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dcs_set_algorithm_process");
  if ( *(_BYTE *)(v15 + 3) == 1 )
  {
    result = qdf_trace_msg(
               0x74u,
               8u,
               "%s: dcs algorithm is disabled forcely",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_dcs_set_algorithm_process");
    *(_BYTE *)(v15 + 2) = 0;
  }
  else
  {
    *(_BYTE *)(v15 + 2) = a3 & 1;
  }
  return result;
}
