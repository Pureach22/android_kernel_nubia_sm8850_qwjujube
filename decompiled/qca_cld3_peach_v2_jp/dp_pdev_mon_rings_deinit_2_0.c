__int64 __fastcall dp_pdev_mon_rings_deinit_2_0(unsigned __int8 *a1)
{
  __int64 v1; // x21
  unsigned int v3; // w20
  int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x1

  v1 = *((_QWORD *)a1 + 1);
  v3 = *a1;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v1 + 40)) )
  {
    if ( v3 )
      goto LABEL_11;
    v3 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
  }
  ((void (__fastcall *)(unsigned __int8 *, _QWORD))dp_tx_mon_pdev_rings_deinit_2_0)(a1, v3);
  v4 = *a1;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v1 + 40)) )
  {
    if ( !v4 )
    {
      v13 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 72) + 1LL);
      return ((__int64 (__fastcall *)(unsigned __int8 *, __int64))dp_tx_mon_pdev_rings_deinit_2_0)(a1, v13);
    }
LABEL_11:
    __break(0x5512u);
    JUMPOUT(0x5EA884);
  }
  if ( v4 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Both mac_id and pdev_id cannot be non zero",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dp_get_lmac_id_for_pdev_id");
    v13 = 0;
  }
  else
  {
    v13 = 1;
  }
  return ((__int64 (__fastcall *)(unsigned __int8 *, __int64))dp_tx_mon_pdev_rings_deinit_2_0)(a1, v13);
}
