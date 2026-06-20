__int64 __fastcall cam_vfe_bus_ver3_deinit(__int64 **a1)
{
  __int64 *v1; // x20
  __int64 v3; // x28
  __int64 v4; // x1
  __int64 v5; // x8
  __int64 v6; // x9
  unsigned int v7; // w21
  __int64 v8; // x8
  _QWORD *v9; // x0
  unsigned int v10; // w21
  unsigned int v11; // w21
  int v12; // w0
  _QWORD *v13; // x0
  _QWORD *v14; // x0
  _QWORD *v15; // x0
  __int64 *v17; // [xsp+8h] [xbp-8h]

  if ( a1 && (v1 = *a1) != nullptr )
  {
    v3 = *v1;
    if ( *v1 )
    {
      v17 = *a1;
      v4 = raw_spin_lock_irqsave(v3 + 34560);
      v5 = 0;
      *(_QWORD *)(v3 + 34544) = v3 + 34544;
      *(_QWORD *)(v3 + 34552) = v3 + 34544;
      do
      {
        v6 = v3 + v5;
        v5 += 128;
        *(_QWORD *)(v6 + 1776) = v6 + 1776;
        *(_QWORD *)(v6 + 1784) = v6 + 1776;
      }
      while ( v5 != 0x8000 );
      *(_BYTE *)(v3 + 34666) = 0;
      *(_BYTE *)(v3 + 34670) = 0;
      raw_spin_unlock_irqrestore(v3 + 34560, v4);
      if ( *(_DWORD *)(v3 + 34736) )
      {
        v7 = 0;
        do
        {
          v8 = *(_QWORD *)(v3 + 34752) + 152LL * (int)v7;
          v9 = *(_QWORD **)(v8 + 24);
          *(_DWORD *)(v8 + 8) = 0;
          *(_QWORD *)(v8 + 16) = 0;
          *(_QWORD *)(v8 + 24) = 0;
          *(_QWORD *)(v8 + 88) = 0;
          *(_QWORD *)(v8 + 96) = 0;
          *(_QWORD *)(v8 + 112) = 0;
          *(_QWORD *)(v8 + 120) = 0;
          if ( v9 )
          {
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v9, 0);
            else
              kvfree(v9);
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_deinit_comp_grp",
              1996,
              "comp_grp_priv is NULL");
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_deinit",
              5932,
              "VFE:%u deinit comp_grp:%d failed rc:%d",
              *(_DWORD *)(v3 + 8),
              v7,
              -19);
          }
          ++v7;
        }
        while ( v7 < *(_DWORD *)(v3 + 34736) );
      }
      if ( *(_DWORD *)(v3 + 34732) )
      {
        v11 = 0;
        do
        {
          v12 = ((__int64 (__fastcall *)(__int64))cam_vfe_bus_ver3_deinit_vfe_out_resource)(*(_QWORD *)(v3 + 34760) + 152LL * (int)v11);
          if ( v12 < 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_deinit",
              5941,
              "VFE:%u deinit out_type:0x%X failed rc:%d",
              *(_DWORD *)(v3 + 8),
              v11,
              v12);
          ++v11;
        }
        while ( v11 < *(_DWORD *)(v3 + 34732) );
      }
      v10 = cam_irq_controller_deinit((__int64 *)(v3 + 32));
      if ( v10 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_deinit",
          5950,
          "VFE:%u Deinit BUS IRQ Controller failed rc=%d",
          *(_DWORD *)(v3 + 8),
          v10);
      v13 = *(_QWORD **)(v3 + 34752);
      v1 = v17;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      v14 = *(_QWORD **)(v3 + 34760);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v14, 0);
      else
        kvfree(v14);
      v15 = (_QWORD *)*v17;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v15, 0);
      else
        kvfree(v15);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_deinit",
        5914,
        "bus_priv is NULL");
      v10 = -19;
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v1, 0);
    else
      kvfree(v1);
    *a1 = nullptr;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_deinit",
      5907,
      "Invalid input");
    return (unsigned int)-22;
  }
  return v10;
}
