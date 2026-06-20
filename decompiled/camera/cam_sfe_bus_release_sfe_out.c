__int64 __fastcall cam_sfe_bus_release_sfe_out(_DWORD *a1, __int64 a2)
{
  int v4; // w6
  __int64 v5; // x23
  __int64 v6; // x24
  unsigned __int64 v7; // x25
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x21
  int v12; // w8
  __int64 v13; // x22
  int v14; // w8
  unsigned int v15; // w8
  __int64 v16; // x20
  int v17; // w7
  int v18; // w6

  if ( a1 && a2 )
  {
    v4 = *(_DWORD *)(a2 + 8);
    v5 = *(_QWORD *)(a2 + 24);
    if ( v4 != 2 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_release_sfe_out",
        1394,
        "Invalid resource state:%d SFE:%d out_type:0x%X",
        v4,
        **(_DWORD **)(v5 + 8),
        *(_DWORD *)(a2 + 4));
    if ( *(_DWORD *)(v5 + 24) )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        v8 = *(_QWORD *)(v5 + 32) + v6;
        v9 = *(_QWORD *)(v8 + 24);
        *(_BYTE *)(v9 + 122) = 0;
        *(_WORD *)(v9 + 120) = 0;
        *(_QWORD *)(v9 + 48) = 0;
        *(_QWORD *)(v9 + 56) = 0;
        *(_QWORD *)(v9 + 64) = 0;
        *(_QWORD *)(v9 + 76) = 0;
        *(_QWORD *)(v9 + 84) = 0;
        *(_QWORD *)(v9 + 92) = 0;
        *(_DWORD *)(v9 + 100) = 0;
        *(_QWORD *)(v8 + 56) = 0;
        *(_DWORD *)(v8 + 8) = 1;
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_bus_release_wm",
            848,
            "SFE:%d Release WM:%d",
            **(_DWORD **)(v9 + 8),
            *(_DWORD *)v9);
        ++v7;
        v6 += 152;
      }
      while ( v7 < *(unsigned int *)(v5 + 24) );
    }
    v11 = *(_QWORD *)(v5 + 40);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 8);
      if ( v12 == 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_release_comp_grp",
          1098,
          "Invalid State %d",
          4);
      }
      else if ( v12 == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_release_comp_grp",
          1092,
          "Already released comp_grp");
      }
      else
      {
        v13 = *(_QWORD *)(v11 + 24);
        if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000000,
            4,
            "cam_sfe_bus_release_comp_grp",
            1105,
            "Release SFE:%d comp_grp:%u",
            *a1,
            *(_DWORD *)v13);
        v14 = *(_DWORD *)(v13 + 40) - 1;
        *(_DWORD *)(v13 + 40) = v14;
        if ( !v14 )
        {
          *(_QWORD *)(v13 + 32) = 0;
          *(_DWORD *)(v13 + 24) = 2;
          *(_QWORD *)(v11 + 56) = 0;
          *(_DWORD *)(v11 + 8) = 1;
        }
      }
    }
    *(_QWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 56) = 0;
    v15 = *(_DWORD *)v5;
    *(_QWORD *)(v5 + 88) = 0;
    if ( v15 < 6 || v15 == 16 )
    {
      v16 = v5 + 8;
      mutex_lock(*(_QWORD *)(v5 + 8) + 27376LL);
      v17 = *(_DWORD *)(v5 + 96);
      v18 = *(_DWORD *)(*(_QWORD *)(v5 + 8) + 27424LL);
      if ( v17 == v18 )
      {
        --*(_DWORD *)(*(_QWORD *)v16 + 27428LL);
        *(_DWORD *)(v5 + 96) = 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_release_sfe_out",
          1425,
          "driver[%d],resource[%d] mismatch",
          v18,
          v17);
      }
      if ( !*(_DWORD *)(*(_QWORD *)v16 + 27428LL) )
        *(_DWORD *)(*(_QWORD *)v16 + 27424LL) = 0;
    }
    else
    {
      mutex_lock(*(_QWORD *)(v5 + 8) + 27376LL);
      v16 = v5 + 8;
    }
    mutex_unlock(*(_QWORD *)v16 + 27376LL);
    result = 0;
    if ( *(_DWORD *)(a2 + 8) == 2 )
      *(_DWORD *)(a2 + 8) = 1;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_release_sfe_out",
      1383,
      "Invalid input bus_priv %pK release_args %pK",
      a1,
      (const void *)a2);
    return 4294967274LL;
  }
  return result;
}
