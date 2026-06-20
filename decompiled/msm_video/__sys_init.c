__int64 __fastcall _sys_init(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4

  result = hfi_packet_sys_init(a1, *(_QWORD *)(a1 + 6464), *(_DWORD *)(a1 + 6472));
  if ( !(_DWORD)result )
  {
    v3 = *(_QWORD *)(a1 + 6464);
    result = _resume(a1);
    if ( !(_DWORD)result )
    {
      result = venus_hfi_queue_cmd_write(a1, v3);
      if ( !(_DWORD)result )
      {
        _schedule_power_collapse_work(a1, v4, v5, v6, v7);
        return 0;
      }
    }
  }
  return result;
}
