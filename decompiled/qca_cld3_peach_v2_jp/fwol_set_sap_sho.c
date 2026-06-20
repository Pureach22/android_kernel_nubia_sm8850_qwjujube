__int64 __fastcall fwol_set_sap_sho(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v3 = tgt_fwol_vdev_param_send(a1, a2 | 0xA400000000LL, a3);
  if ( v3 )
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: wmi_vdev_param_sho_config failed %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "fwol_set_sap_sho",
      v3);
  return v3;
}
