__int64 __fastcall aw882xx_dsp_parse_topo_id_dt(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x1
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1

  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL),
          "aw-tx-topo-id",
          &g_tx_topo_id,
          1,
          0)
      & 0x80000000) != 0 )
  {
    v2 = *(__int64 **)(a1 + 112);
    g_tx_topo_id = 268500736;
    v3 = v2[14];
    if ( !v3 )
      v3 = *v2;
    printk(&unk_23819, v3, "aw882xx_dsp_parse_topo_id_dt");
  }
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL),
          "aw-rx-topo-id",
          &g_rx_topo_id,
          1,
          0)
      & 0x80000000) != 0 )
  {
    v4 = *(__int64 **)(a1 + 112);
    g_rx_topo_id = 268500737;
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_28E23, v5, "aw882xx_dsp_parse_topo_id_dt");
  }
  v6 = *(__int64 **)(a1 + 112);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  return printk(&unk_22780, v7, "aw882xx_dsp_parse_topo_id_dt");
}
