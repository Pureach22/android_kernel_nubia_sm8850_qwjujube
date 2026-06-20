__int64 __fastcall is_service_enabled_tlv(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w10
  char v14; // w8
  const char *v15; // x2
  __int64 v16; // x20
  unsigned int v18; // w8
  unsigned int v19; // w10
  char v20; // w9
  unsigned int v21; // w8
  char v22; // w9

  v10 = *(_QWORD *)(a1 + 760);
  v11 = *(_QWORD *)(v10 + 6336);
  if ( !v11 )
  {
    v15 = "%s: WMI service bit map is not saved yet";
LABEL_13:
    qdf_trace_msg(0x31u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "is_service_enabled_tlv");
    return 0;
  }
  v12 = *(_QWORD *)(v10 + 6360);
  if ( !v12 )
  {
    if ( a2 >= 0x100 )
    {
      v16 = jiffies;
      if ( is_service_enabled_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Service id %d but WMI ext2 service bitmap is NULL",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "is_service_enabled_tlv");
        is_service_enabled_tlv___last_ticks = v16;
        return 0;
      }
      return 0;
    }
    if ( *(_QWORD *)(v10 + 6344) )
    {
      v19 = (a2 - 128) >> 5;
      if ( a2 < 0x80 )
        v19 = a2 >> 2;
      else
        v11 = *(_QWORD *)(v10 + 6344);
      if ( a2 >= 0x80 )
        v20 = 31;
      else
        v20 = 3;
      v21 = *(_DWORD *)(v11 + 4LL * v19);
      v22 = v20 & a2;
    }
    else
    {
      if ( a2 >= 0x80 )
      {
        v15 = "%s: Service id %d but WMI ext service bitmap is NULL";
        goto LABEL_13;
      }
      v21 = *(_DWORD *)(v11 + (a2 & 0xFFFFFFFC));
      v22 = a2 & 3;
    }
    v18 = v21 >> v22;
    return v18 & 1;
  }
  if ( !*(_QWORD *)(v10 + 6344) )
  {
    v15 = "%s: WMI service ext bit map is not saved yet";
    goto LABEL_13;
  }
  if ( a2 < 0x101 )
  {
    if ( a2 == 256 )
    {
      v13 = 0;
    }
    else
    {
      v12 = *(_QWORD *)(v10 + 6344);
      v13 = (a2 - 128) >> 5;
    }
    if ( a2 > 0x7F )
    {
      v14 = 31;
    }
    else
    {
      v13 = a2 >> 2;
      v12 = *(_QWORD *)(v10 + 6336);
      v14 = 3;
    }
    goto LABEL_20;
  }
  v13 = (a2 - 256) >> 5;
  if ( v13 >= *(_DWORD *)(v10 + 6352) )
  {
    v15 = "%s: WMI service ext2 bit = %d is not advertised by fw";
    goto LABEL_13;
  }
  if ( a2 > 0x1CB )
    return 0;
  v14 = 31;
LABEL_20:
  v18 = *(_DWORD *)(v12 + 4LL * v13) >> (v14 & a2);
  return v18 & 1;
}
