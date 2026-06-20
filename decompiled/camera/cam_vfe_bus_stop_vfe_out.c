__int64 __fastcall cam_vfe_bus_stop_vfe_out(__int64 a1)
{
  int v1; // w6
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 v9; // x23
  __int64 v10; // x24

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (unsigned int)(v1 - 1) > 1 )
    {
      v4 = *(_QWORD *)(a1 + 24);
      v5 = *(_QWORD *)(v4 + 40);
      v6 = *(_QWORD *)(v4 + 8);
      if ( v5 )
        *(_DWORD *)(v5 + 8) = 2;
      if ( *(_DWORD *)(v4 + 16) )
      {
        v7 = *(_QWORD *)(v4 + 24);
        v8 = *(_QWORD *)(v7 + 24);
        cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)(v8 + 8) + 8LL) + *(unsigned int *)(*(_QWORD *)(v8 + 16) + 8LL));
        *(_DWORD *)(v7 + 8) = 2;
        *(_WORD *)(v8 + 24) = 0;
        if ( *(_DWORD *)(v4 + 16) > 1u )
        {
          v9 = *(_QWORD *)(v4 + 32);
          v10 = *(_QWORD *)(v9 + 24);
          cam_io_w_mb(0, *(_QWORD *)(*(_QWORD *)(v10 + 8) + 8LL) + *(unsigned int *)(*(_QWORD *)(v10 + 16) + 8LL));
          *(_DWORD *)(v9 + 8) = 2;
          *(_WORD *)(v10 + 24) = 0;
          if ( *(_DWORD *)(v4 + 16) > 2u )
          {
            __break(0x5512u);
            JUMPOUT(0x1B45F0);
          }
        }
      }
      if ( *(_DWORD *)(a1 + 64) )
      {
        result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v6 + 24));
        *(_DWORD *)(a1 + 64) = 0;
      }
      else
      {
        result = 0;
      }
      *(_DWORD *)(a1 + 8) = 2;
    }
    else
    {
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_stop_vfe_out",
          2343,
          "vfe_out res_state is %d",
          v1);
        return 0;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_stop_vfe_out",
      2334,
      "Invalid input");
    return 4294967274LL;
  }
  return result;
}
