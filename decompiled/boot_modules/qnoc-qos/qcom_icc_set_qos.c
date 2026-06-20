__int64 __fastcall qcom_icc_set_qos(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned int v3; // w21
  __int64 v4; // x22

  if ( *(_QWORD *)(result + 400) )
  {
    v1 = *(_QWORD *)(result + 408);
    v2 = result;
    if ( v1 )
    {
      if ( *(_DWORD *)v1 )
      {
        v3 = 0;
        v4 = v1 + 24;
        do
        {
          regmap_update_bits_base(
            *(_QWORD *)(v2 + 400),
            *(_DWORD *)(v4 + 4LL * (int)v3) + (unsigned int)**(unsigned __int8 **)(v1 + 8),
            0x1000000,
            *(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 8LL) << 24,
            0,
            0,
            0);
          regmap_update_bits_base(
            *(_QWORD *)(v2 + 400),
            *(_DWORD *)(v4 + 4LL * (int)v3) + (unsigned int)**(unsigned __int8 **)(v1 + 8),
            112,
            (unsigned int)(16 * **(_DWORD **)(v1 + 16)),
            0,
            0,
            0);
          result = regmap_update_bits_base(
                     *(_QWORD *)(v2 + 400),
                     *(_DWORD *)(v4 + 4LL * (int)v3++) + (unsigned int)**(unsigned __int8 **)(v1 + 8),
                     8,
                     (unsigned int)(8 * *(_DWORD *)(*(_QWORD *)(v1 + 16) + 4LL)),
                     0,
                     0,
                     0);
        }
        while ( v3 < *(_DWORD *)v1 );
      }
    }
  }
  return result;
}
