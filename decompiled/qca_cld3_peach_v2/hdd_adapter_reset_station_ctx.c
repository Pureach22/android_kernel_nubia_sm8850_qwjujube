__int64 __fastcall hdd_adapter_reset_station_ctx(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( result )
  {
    v1 = result + 52840;
    if ( result != -52840 )
    {
      v2 = 0;
      do
      {
        if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v2 >> 3)) > 2 )
          break;
        qdf_mem_set((void *)(v1 + 308), 6u, 0);
        result = hdd_cm_clear_ieee_link_id(v1, 0, v3, v4, v5, v6, v7, v8, v9, v10);
        *(_BYTE *)(v1 + 1697) = 8;
        v1 += 6088;
        v2 += 6088;
      }
      while ( v1 );
    }
  }
  return result;
}
