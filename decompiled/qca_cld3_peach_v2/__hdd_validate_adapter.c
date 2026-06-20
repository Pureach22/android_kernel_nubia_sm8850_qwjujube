__int64 __fastcall _hdd_validate_adapter(
        __int64 a1,
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
  __int64 v11; // x20
  const char *v13; // x2
  unsigned int v14; // w4
  __int64 v15; // x20

  if ( !a1 )
  {
    v13 = "%s: adapter is null (via %s)";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "__hdd_validate_adapter", a2);
    return 4294967274LL;
  }
  if ( *(_DWORD *)a1 != 1885692259 )
  {
    v13 = "%s: bad adapter magic (via %s)";
    goto LABEL_11;
  }
  v10 = *(_QWORD *)(a1 + 32);
  if ( !v10 )
  {
    v13 = "%s: adapter net_device is null (via %s)";
    goto LABEL_11;
  }
  if ( (*(_BYTE *)(v10 + 176) & 1) != 0 )
  {
    v14 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL);
    if ( v14 == 255 )
    {
      v15 = jiffies;
      if ( _wlan_hdd_validate_vdev_id___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: adapter is not up (via %s)",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "__wlan_hdd_validate_vdev_id",
          a2);
        _wlan_hdd_validate_vdev_id___last_ticks = v15;
      }
    }
    else
    {
      if ( v14 < 6 )
        return 0;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: bad vdev Id:%u (via %s)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "__wlan_hdd_validate_vdev_id");
    }
    return 4294967274LL;
  }
  v11 = jiffies;
  if ( _hdd_validate_adapter___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: adapter '%s' is not up (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__hdd_validate_adapter",
      v10 + 296,
      a2);
    _hdd_validate_adapter___last_ticks = v11;
  }
  return 4294967285LL;
}
