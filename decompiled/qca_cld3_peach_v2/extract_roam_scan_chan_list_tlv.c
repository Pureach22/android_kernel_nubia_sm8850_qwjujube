__int64 __fastcall extract_roam_scan_chan_list_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11,
        __int64 *a12)
{
  __int64 v12; // x20
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x20
  unsigned int v16; // w22
  unsigned int v19; // w21
  __int64 v20; // x0
  __int64 v21; // x9

  if ( !a10 )
  {
    v14 = jiffies;
    if ( extract_roam_scan_chan_list_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: NULL event received from target",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_scan_chan_list_tlv");
      extract_roam_scan_chan_list_tlv___last_ticks = v14;
    }
    return 4294967274LL;
  }
  v12 = *a10;
  if ( !*a10 )
  {
    v15 = jiffies;
    if ( extract_roam_scan_chan_list_tlv___last_ticks_71 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s:  NULL fixed param",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_scan_chan_list_tlv");
      extract_roam_scan_chan_list_tlv___last_ticks_71 = v15;
    }
    return 4294967274LL;
  }
  if ( *(_DWORD *)(v12 + 4) >= 6u )
  {
    v13 = jiffies;
    if ( extract_roam_scan_chan_list_tlv___last_ticks_73 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid vdev_id %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_scan_chan_list_tlv");
      extract_roam_scan_chan_list_tlv___last_ticks_73 = v13;
    }
    return 4294967274LL;
  }
  v16 = *((_DWORD *)a10 + 6);
  if ( v16 >= 0x64 )
    v19 = 100;
  else
    v19 = *((_DWORD *)a10 + 6);
  v20 = _qdf_mem_malloc(4 * v19 + 16, "extract_roam_scan_chan_list_tlv", 3048);
  if ( !v20 )
    return 4294967274LL;
  *(_QWORD *)(v20 + 8) = v20 + 16;
  *(_WORD *)v20 = *(_DWORD *)(v12 + 4);
  *(_DWORD *)(v20 + 4) = *(_DWORD *)(v12 + 44);
  *(_WORD *)(v20 + 2) = *((_DWORD *)a10 + 6);
  if ( v16 )
  {
    v21 = 0;
    do
    {
      *(_DWORD *)(*(_QWORD *)(v20 + 8) + v21) = *(_DWORD *)(a10[2] + v21);
      v21 += 4;
    }
    while ( 4LL * v19 != v21 );
  }
  *a12 = v20;
  return 0;
}
