bool __fastcall wma_is_vdev_in_ap_mode(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  int v13; // w8

  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev_id %hu",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_is_vdev_in_ap_mode",
      v10,
      v11);
    return 0;
  }
  else
  {
    v12 = *(_QWORD *)(a1 + 520) + 488LL * a2;
    if ( *(_DWORD *)(v12 + 164) == 1 )
    {
      v13 = *(_DWORD *)(v12 + 168);
      return v13 == 3 || v13 == 0;
    }
    else
    {
      return 0;
    }
  }
}
