__int64 __fastcall cam_vfe_bus_ver3_handle_mc_comp_done_top_half(unsigned int a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w25
  unsigned int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a2 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_mc_comp_done_top_half",
        2712,
        "VFE:%u MC comp done res: %s",
        *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL),
        (const char *)(*(_QWORD *)(v2 + 40) + 128LL));
    v5 = *(_QWORD *)(v2 + 16);
    v12[0] = 0;
    result = cam_vfe_bus_ver3_get_evt_payload(v5, v12);
    if ( (_DWORD)result )
    {
      if ( *(_DWORD *)(a2 + 8) )
      {
        v7 = result;
        v8 = 0;
        do
        {
          if ( (unsigned int)__ratelimit(
                               &cam_vfe_bus_ver3_handle_mc_comp_done_top_half__rs_105,
                               "cam_vfe_bus_ver3_handle_mc_comp_done_top_half") )
            v9 = 3;
          else
            v9 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v9,
            8,
            3,
            "cam_vfe_bus_ver3_handle_mc_comp_done_top_half",
            2718,
            "VFE:%u Bus IRQ status_%d: 0x%X",
            *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL),
            v8,
            *(_DWORD *)(*(_QWORD *)(a2 + 16) + 4LL * (int)v8));
          ++v8;
        }
        while ( v8 < *(_DWORD *)(a2 + 8) );
        result = v7;
      }
    }
    else
    {
      byte_7C[v12[0]] = 1;
      result = cam_vfe_bus_ver3_out_done_top_half_util(a1, a2);
      if ( (_DWORD)result )
      {
        v11 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_handle_mc_comp_done_top_half",
          2726,
          "Failed to process out done top half rc:%d",
          result);
        result = v11;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(
                         &cam_vfe_bus_ver3_handle_mc_comp_done_top_half__rs,
                         "cam_vfe_bus_ver3_handle_mc_comp_done_top_half") )
      v10 = 3;
    else
      v10 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v10,
      8,
      1,
      "cam_vfe_bus_ver3_handle_mc_comp_done_top_half",
      2705,
      "No resource");
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
