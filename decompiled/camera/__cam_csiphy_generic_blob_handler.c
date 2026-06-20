__int64 __fastcall _cam_csiphy_generic_blob_handler(
        __int64 a1,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  int v7; // w6
  unsigned int v8; // w8
  __int16 v9; // w10
  int v10; // w9
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned int v15; // w8
  unsigned int v16; // w6

  if ( !a3 || !a4 )
  {
    v11 = "Invalid blob info %pK %u";
    v12 = 1334;
    v13 = (__int64)a4;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      0x8000,
      1,
      "__cam_csiphy_generic_blob_handler",
      v12,
      v11,
      v13,
      a3);
    return (unsigned int)-22;
  }
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      0x8000,
      1,
      "__cam_csiphy_generic_blob_handler",
      1339,
      "Invalid user data",
      a7,
      a3);
    return (unsigned int)-22;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      if ( a3 >= 0x20 )
      {
        v7 = a4[1];
        if ( (unsigned int)(v7 - 1) >= 2 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000,
            1,
            "__cam_csiphy_handle_cdr_sweep_info",
            1195,
            "Invalid tolerance op type: %u",
            v7);
          return (unsigned int)-22;
        }
        v8 = 0;
        v9 = debug_mdl;
        *(_DWORD *)(a1 + 4592) = *a4;
        v10 = a4[1];
        *(_BYTE *)(a1 + 4600) = 1;
        *(_DWORD *)(a1 + 4596) = v10;
        if ( (v9 & 0x8000) == 0 || debug_priority )
          return v8;
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v9 & 0x8000,
          4,
          "__cam_csiphy_handle_cdr_sweep_info",
          1206,
          "CSIPHY:%u cdr sweep with tolerance: %u op_type: %u",
          *(unsigned int *)(a1 + 932));
        return 0;
      }
      v11 = "Invalid blob size expected: 0x%x actual: 0x%x";
      v12 = 1350;
      v13 = 32;
      goto LABEL_12;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      2,
      "__cam_csiphy_generic_blob_handler",
      1371,
      "Invalid blob type %d",
      a2);
    return 0;
  }
  if ( a3 < 0x18 )
  {
    v11 = "Invalid blob size expected: 0x%x actual: 0x%x";
    v12 = 1363;
    v13 = 24;
    goto LABEL_12;
  }
  v14 = *(_QWORD *)a4;
  if ( *(_QWORD *)a4 )
  {
    v15 = *(_DWORD *)(a1 + 932);
    if ( v15 >= 8 )
      goto LABEL_28;
    *((_QWORD *)&g_phy_data + 7 * v15 + 3) |= v14;
  }
  v8 = 0;
  if ( (debug_mdl & 0x8000) == 0 || debug_priority )
    return v8;
  v16 = *(_DWORD *)(a1 + 932);
  if ( v16 <= 7 )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "__cam_csiphy_handle_aux_mem_buffer",
      1223,
      "CSIPHY:%u provided_mask: 0x%llx current_mask :0x%llx",
      v16,
      v14,
      *((_QWORD *)&g_phy_data + 7 * v16 + 3));
    return 0;
  }
LABEL_28:
  __break(0x5512u);
  return cam_csiphy_cphy_irq_config();
}
