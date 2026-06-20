__int64 __fastcall cam_vfe_bus_ver3_handle_vfe_out_done_top_half(unsigned int a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned int v6; // w25
  unsigned int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w19
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a2 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
    v11[0] = 0;
    result = cam_vfe_bus_ver3_get_evt_payload(*(_QWORD *)(v2 + 16), v11);
    if ( (_DWORD)result )
    {
      if ( *(_DWORD *)(a2 + 8) )
      {
        v6 = result;
        v7 = 0;
        do
        {
          if ( (unsigned int)__ratelimit(
                               &cam_vfe_bus_ver3_handle_vfe_out_done_top_half__rs_135,
                               "cam_vfe_bus_ver3_handle_vfe_out_done_top_half") )
            v8 = 3;
          else
            v8 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v8,
            8,
            3,
            "cam_vfe_bus_ver3_handle_vfe_out_done_top_half",
            2677,
            "VFE:%u Bus IRQ status_%d: 0x%X",
            *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL),
            v7,
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL * (int)v7));
          ++v7;
        }
        while ( v7 < *(_DWORD *)(a2 + 8) );
        result = v6;
      }
    }
    else
    {
      byte_7C[v11[0]] = 0;
      result = cam_vfe_bus_ver3_out_done_top_half_util(a1, a2);
      if ( (_DWORD)result )
      {
        v10 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_handle_vfe_out_done_top_half",
          2685,
          "Failed to process out done top half rc:%d",
          result);
        result = v10;
      }
      else if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_handle_vfe_out_done_top_half",
          2690,
          "VFE:%u Exit",
          *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL));
        result = 0;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(
                         &cam_vfe_bus_ver3_handle_vfe_out_done_top_half__rs,
                         "cam_vfe_bus_ver3_handle_vfe_out_done_top_half") )
      v9 = 3;
    else
      v9 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v9,
      8,
      1,
      "cam_vfe_bus_ver3_handle_vfe_out_done_top_half",
      2666,
      "No resource");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
