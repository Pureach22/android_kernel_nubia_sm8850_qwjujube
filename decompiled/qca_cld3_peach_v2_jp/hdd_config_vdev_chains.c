__int64 __fastcall hdd_config_vdev_chains(
        __int64 *a1,
        __int64 a2,
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
  __int64 v11; // x9
  unsigned __int8 v12; // w20
  unsigned __int8 v14; // w21
  __int64 v15; // x22
  const char *v17; // x4

  v10 = *(_QWORD *)(a2 + 584);
  v11 = *(_QWORD *)(a2 + 592);
  if ( *(_OWORD *)(a2 + 584) == 0 )
    return 0;
  if ( v10 && v11 )
  {
    v12 = *(_BYTE *)(v10 + 4);
    v14 = *(_BYTE *)(v11 + 4);
    v15 = *(_QWORD *)(*a1 + 24);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: tx_chains %d rx_chains %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_vdev_chains",
      v12,
      v14);
    if ( *(_BYTE *)(v15 + 3744) == 1 )
      return hdd_set_dynamic_antenna_mode(a1, v14, v12);
    else
      return 0;
  }
  else
  {
    if ( v10 )
      v17 = (const char *)&unk_956283;
    else
      v17 = "TX";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_vdev_chains",
      v17);
    return 4294967274LL;
  }
}
