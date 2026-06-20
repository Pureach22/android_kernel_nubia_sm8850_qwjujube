__int64 __fastcall csr_get_vdev_type_nss(
        unsigned int a1,
        unsigned __int8 *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _BYTE *mac_context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  mac_context = sme_get_mac_context(a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !mac_context )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid MAC context",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "csr_get_vdev_type_nss");
  if ( (int)a1 <= 4 )
  {
    if ( (int)a1 > 1 )
    {
      if ( a1 == 2 )
      {
        *a2 = mac_context[21515];
        *a3 = mac_context[21525];
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: mode - %d: nss_2g - %d, 5g - %d",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "csr_get_vdev_type_nss",
                 a1,
                 *a2);
      }
      if ( a1 == 3 )
      {
        *a2 = mac_context[21514];
        *a3 = mac_context[21524];
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: mode - %d: nss_2g - %d, 5g - %d",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "csr_get_vdev_type_nss",
                 a1,
                 *a2);
      }
    }
    else
    {
      if ( !a1 )
      {
        *a2 = mac_context[21512];
        *a3 = mac_context[21522];
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: mode - %d: nss_2g - %d, 5g - %d",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "csr_get_vdev_type_nss",
                 a1,
                 *a2);
      }
      if ( a1 == 1 )
      {
        *a2 = mac_context[21513];
        *a3 = mac_context[21523];
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%s: mode - %d: nss_2g - %d, 5g - %d",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "csr_get_vdev_type_nss",
                 a1,
                 *a2);
      }
    }
LABEL_24:
    *a2 = 1;
    *a3 = 1;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Unknown device mode: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "csr_get_vdev_type_nss",
      a1);
    return qdf_trace_msg(
             0x34u,
             8u,
             "%s: mode - %d: nss_2g - %d, 5g - %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "csr_get_vdev_type_nss",
             a1,
             *a2);
  }
  if ( (int)a1 <= 7 )
  {
    if ( a1 == 5 )
    {
      *a2 = mac_context[21517];
      *a3 = mac_context[21527];
      return qdf_trace_msg(
               0x34u,
               8u,
               "%s: mode - %d: nss_2g - %d, 5g - %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "csr_get_vdev_type_nss",
               a1,
               *a2);
    }
    if ( a1 == 7 )
    {
      *a2 = mac_context[21516];
      *a3 = mac_context[21526];
      return qdf_trace_msg(
               0x34u,
               8u,
               "%s: mode - %d: nss_2g - %d, 5g - %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "csr_get_vdev_type_nss",
               a1,
               *a2);
    }
    goto LABEL_24;
  }
  if ( a1 == 8 )
  {
    *a2 = mac_context[21519];
    *a3 = mac_context[21529];
    return qdf_trace_msg(
             0x34u,
             8u,
             "%s: mode - %d: nss_2g - %d, 5g - %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "csr_get_vdev_type_nss",
             a1,
             *a2);
  }
  if ( a1 == 11 )
  {
    *a2 = mac_context[21521];
    *a3 = mac_context[21531];
    return qdf_trace_msg(
             0x34u,
             8u,
             "%s: mode - %d: nss_2g - %d, 5g - %d",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "csr_get_vdev_type_nss",
             a1,
             *a2);
  }
  if ( a1 != 16 )
    goto LABEL_24;
  *a2 = mac_context[21520];
  *a3 = mac_context[21530];
  return qdf_trace_msg(
           0x34u,
           8u,
           "%s: mode - %d: nss_2g - %d, 5g - %d",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           "csr_get_vdev_type_nss",
           a1,
           *a2);
}
