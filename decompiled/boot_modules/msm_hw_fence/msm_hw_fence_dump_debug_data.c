__int64 __fastcall msm_hw_fence_dump_debug_data(unsigned __int64 a1, char a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v7; // w19
  __int64 result; // x0
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 i; // x20

  v7 = a3;
  result = hw_fence_check_valid_client(hw_fence_drv_data, a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( (a2 & 1) != 0 )
    {
      hw_fence_debug_dump_queues(hw_fence_drv_data, 0x10000, a1, v10, v11, v12);
      if ( v7 )
      {
        for ( i = 0; i != 1665; ++i )
        {
          if ( ((v7 >> i) & 1) != 0 )
          {
            v9 = *(_QWORD *)(*(_QWORD *)(hw_fence_drv_data + 728) + 8 * i);
            if ( v9 )
              hw_fence_debug_dump_queues(hw_fence_drv_data, 0x10000, v9, v10, v11, v12);
          }
        }
      }
    }
    if ( (a2 & 2) != 0 )
      hw_fence_debug_dump_table(0x10000, hw_fence_drv_data);
    if ( (a2 & 4) != 0 )
      hw_fence_debug_dump_events(0x10000, hw_fence_drv_data, v9, v10, v11, v12);
    return 0;
  }
  return result;
}
