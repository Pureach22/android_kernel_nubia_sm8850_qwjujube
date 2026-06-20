_QWORD *__fastcall spectral_get_vdev(__int64 a1, unsigned __int8 a2)
{
  _QWORD *result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x19

  if ( a2 != 0xFF )
  {
    result = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x1Bu);
    if ( result )
      return result;
    goto LABEL_3;
  }
  result = wlan_objmgr_pdev_get_first_vdev(a1, 0x1Bu);
  if ( !result )
  {
LABEL_3:
    v11 = result;
    qdf_trace_msg(
      0x56u,
      3u,
      "%s: Unable to get first vdev of pdev",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "spectral_get_vdev");
    return v11;
  }
  return result;
}
