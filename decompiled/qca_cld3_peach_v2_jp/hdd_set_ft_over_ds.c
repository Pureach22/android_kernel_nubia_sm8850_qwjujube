__int64 __fastcall hdd_set_ft_over_ds(
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
  __int64 *v10; // x20
  unsigned int v11; // w19
  __int64 v12; // x21
  const char *v13; // x2
  __int64 result; // x0

  v10 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  if ( v10 )
  {
    v11 = *(unsigned __int8 *)(a2 + 4);
    if ( v11 >= 2 )
    {
      v12 = jiffies;
      if ( hdd_set_ft_over_ds___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid ft_over_ds_enable: %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_set_ft_over_ds",
          *(unsigned __int8 *)(a2 + 4));
        hdd_set_ft_over_ds___last_ticks = v12;
      }
      return 4294967274LL;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Enable FT over DS: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_set_ft_over_ds",
      *(unsigned __int8 *)(a2 + 4));
    result = wlan_mlme_set_ft_over_ds(*v10, v11);
    if ( !(_DWORD)result )
      return result;
    v13 = "%s: set ft_over_ds failed";
  }
  else
  {
    v13 = "%s: hdd_ctx failure";
  }
  qdf_trace_msg(0x33u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_ft_over_ds");
  return 4294967274LL;
}
