__int64 __fastcall cam_sfe_bus_wr_deinit(_QWORD *a1)
{
  _QWORD *v1; // x20
  _DWORD *v3; // x28
  __int64 v4; // x1
  __int64 v5; // x9
  _QWORD *v6; // x8
  unsigned int v7; // w22
  unsigned int v8; // w21
  __int64 v9; // x8
  _QWORD *v10; // x0
  unsigned int v11; // w22
  _QWORD *v12; // x0
  _QWORD *v13; // x0
  _QWORD *v14; // x0

  if ( a1 && (v1 = (_QWORD *)*a1) != nullptr )
  {
    v3 = (_DWORD *)*v1;
    if ( *v1 )
    {
      v4 = raw_spin_lock_irqsave(v3 + 186);
      v5 = 256;
      *((_QWORD *)v3 + 91) = v3 + 182;
      *((_QWORD *)v3 + 92) = v3 + 182;
      v6 = v3 + 188;
      do
      {
        *v6 = v6;
        --v5;
        v6[1] = v6;
        v6 += 13;
      }
      while ( v5 );
      *((_BYTE *)v3 + 27448) = 0;
      raw_spin_unlock_irqrestore(v3 + 186, v4);
      if ( v3[6889] )
      {
        v7 = 0;
        do
        {
          v9 = *((_QWORD *)v3 + 3446) + 152LL * (int)v7;
          v10 = *(_QWORD **)(v9 + 24);
          *(_DWORD *)(v9 + 8) = 0;
          *(_QWORD *)(v9 + 16) = 0;
          *(_QWORD *)(v9 + 24) = 0;
          *(_QWORD *)(v9 + 88) = 0;
          *(_QWORD *)(v9 + 96) = 0;
          *(_QWORD *)(v9 + 112) = 0;
          *(_QWORD *)(v9 + 120) = 0;
          if ( v10 )
          {
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v10, 0);
            else
              kvfree(v10);
            v8 = 0;
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_deinit_comp_grp",
              1205,
              "comp_grp_priv is NULL");
            v8 = -19;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_wr_deinit",
              3790,
              "SFE:%d deinit comp_grp:%d failed rc:%d",
              *v3,
              v7,
              -19);
          }
          ++v7;
        }
        while ( v7 < v3[6889] );
      }
      else
      {
        v8 = 0;
      }
      if ( v3[6887] )
      {
        v11 = 0;
        do
        {
          v8 = cam_sfe_bus_deinit_sfe_out_resource(*((_QWORD *)v3 + 3447) + 152LL * (int)v11);
          if ( (v8 & 0x80000000) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_wr_deinit",
              3799,
              "SFE:%d deinit out_type:0x%X failed rc:%d",
              *v3,
              v11,
              v8);
          ++v11;
        }
        while ( v11 < v3[6887] );
      }
      v12 = *((_QWORD **)v3 + 3446);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v12, 0);
      else
        kvfree(v12);
      v13 = *((_QWORD **)v3 + 3447);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      v14 = (_QWORD *)*v1;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v14, 0);
      else
        kvfree(v14);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_wr_deinit",
        3773,
        "bus_priv is NULL");
      v8 = -19;
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    *a1 = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_wr_deinit",
      3766,
      "Invalid input");
    return (unsigned int)-22;
  }
  return v8;
}
