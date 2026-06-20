__int64 __fastcall sink_name_store(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // x19
  __int64 v6; // x0
  __int64 v7; // x20
  int v8; // w0
  __int64 sink_by_id; // x22
  __int64 enabled_sink_from_bus; // x0

  if ( a4 > 0x18 )
    return -22;
  v4 = a4;
  if ( a4 )
  {
    v6 = kstrdup(a3, 3264);
    if ( v6 )
    {
      v7 = v6;
      *(_BYTE *)(v6 + v4 - 1) = 0;
      v8 = hashlen_string(0, v6);
      sink_by_id = coresight_get_sink_by_id(v8);
      enabled_sink_from_bus = coresight_get_enabled_sink_from_bus(0);
      if ( sink_by_id
        && (!enabled_sink_from_bus || *(_DWORD *)(enabled_sink_from_bus + 8) == *(_DWORD *)(sink_by_id + 8)) )
      {
        *(_QWORD *)(a1 + 936) = sink_by_id;
        kfree(v7);
      }
      else
      {
        dev_err(a1, "Sink name is invalid or another type sink is enabled.\n");
        kfree(v7);
        return -22;
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    *(_QWORD *)(a1 + 936) = 0;
  }
  return v4;
}
