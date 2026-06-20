_QWORD *__fastcall cm_override_partner_link_akm(_QWORD *result, __int64 a2)
{
  __int64 assoc_link_vdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19

  if ( *(_QWORD *)(a2 + 1040) )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*result);
    if ( assoc_link_vdev )
    {
      v12 = *(_QWORD *)(*(_QWORD *)(a2 + 1040) + 24LL);
      result = (_QWORD *)wlan_crypto_get_param(assoc_link_vdev, 7u);
      *(_DWORD *)(v12 + 1268) = (_DWORD)result;
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x68u,
                         2u,
                         "%s: Assoc vdev not found",
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         "cm_override_partner_link_akm");
    }
  }
  return result;
}
