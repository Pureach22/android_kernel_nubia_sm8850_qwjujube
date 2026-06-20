__int64 __fastcall reg_add_indoor_concurrency(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 bonded_chan_entry; // x0
  __int64 v27; // x7
  __int64 v28; // x8

  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "reg_add_indoor_concurrency");
    return 16;
  }
  v24 = pdev_obj + 57344;
  if ( a4 )
  {
    bonded_chan_entry = wlan_reg_get_bonded_chan_entry(a3, a4, 0);
    if ( *(_DWORD *)(v24 + 1620) )
      goto LABEL_8;
  }
  else
  {
    bonded_chan_entry = 0;
    if ( *(_DWORD *)(v24 + 1620) )
      goto LABEL_8;
  }
  if ( *(unsigned __int8 *)(v24 + 1616) == 255 )
  {
    v27 = 0;
    v28 = v24 + 1616;
    goto LABEL_17;
  }
LABEL_8:
  if ( !*(_DWORD *)(v24 + 1636) && *(unsigned __int8 *)(v24 + 1632) == 255 )
  {
    v28 = v24 + 1632;
    v27 = 1;
  }
  else
  {
    if ( *(_DWORD *)(v24 + 1652) || *(unsigned __int8 *)(v24 + 1648) != 255 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Unable to add indoor concurrency for vdev %d freq %d width %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "reg_add_indoor_concurrency",
        a2,
        a3,
        a4);
      return 16;
    }
    v28 = v24 + 1648;
    v27 = 2;
  }
LABEL_17:
  *(_QWORD *)(v28 + 8) = bonded_chan_entry;
  *(_DWORD *)(v28 + 4) = a3;
  *(_BYTE *)v28 = a2;
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: Added freq %d vdev %d width %d at idx %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "reg_add_indoor_concurrency",
    a3,
    a2,
    a4,
    v27);
  return 0;
}
