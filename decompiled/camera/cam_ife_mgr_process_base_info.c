__int64 __fastcall cam_ife_mgr_process_base_info(__int64 a1)
{
  __int64 *v2; // x24
  __int64 *v3; // x25
  __int64 v4; // x26
  __int64 v5; // x26
  __int64 *i; // x25
  __int64 v7; // x28
  __int64 v8; // x2
  __int64 v9; // x6
  char v10; // w8
  __int64 v11; // x28
  __int64 v12; // x2
  __int64 v13; // x6
  char v14; // w8
  __int64 *j; // x25
  __int64 v16; // x26
  __int64 v17; // x26
  __int64 result; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-10h]

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v2 = (__int64 *)(a1 + 224);
  v3 = *(__int64 **)(a1 + 224);
  if ( v3 != (__int64 *)(a1 + 224) )
  {
    while ( 1 )
    {
      if ( *((_DWORD *)v3 + 4) )
      {
        v4 = v3[4];
        if ( v4
          && (cam_ife_mgr_add_base_info(a1, 0, *(unsigned int *)(*(_QWORD *)(v4 + 16) + 4LL), 2), (debug_mdl & 8) != 0)
          && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_process_base_info",
            2694,
            "add IFE base info for hw %d ctx_idx: %u",
            *(_DWORD *)(*(_QWORD *)(v4 + 16) + 4LL),
            *(_DWORD *)(a1 + 56));
          v5 = v3[5];
          if ( v5 )
          {
LABEL_9:
            cam_ife_mgr_add_base_info(a1, 1, *(unsigned int *)(*(_QWORD *)(v5 + 16) + 4LL), 2);
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_process_base_info",
                2694,
                "add IFE base info for hw %d ctx_idx: %u",
                *(_DWORD *)(*(_QWORD *)(v5 + 16) + 4LL),
                *(_DWORD *)(a1 + 56));
          }
        }
        else
        {
          v5 = v3[5];
          if ( v5 )
            goto LABEL_9;
        }
      }
      v3 = (__int64 *)*v3;
      if ( v3 == v2 )
        goto LABEL_15;
    }
  }
  if ( *(_QWORD *)(a1 + 240) == a1 + 240 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_process_base_info",
      2676,
      "Mux List empty");
    result = 4294967277LL;
  }
  else
  {
LABEL_15:
    for ( i = *(__int64 **)(a1 + 208); i != (__int64 *)(a1 + 208); i = (__int64 *)*i )
    {
      if ( *((_DWORD *)i + 4) )
      {
        v7 = i[4];
        if ( !v7 )
          goto LABEL_25;
        v8 = *(unsigned int *)(*(_QWORD *)(v7 + 16) + 4LL);
        if ( (unsigned int)v8 > 7 )
          goto LABEL_52;
        if ( (*((_BYTE *)v19 + v8) & 1) != 0 )
          goto LABEL_25;
        cam_ife_mgr_add_base_info(a1, 0, v8, 0);
        v9 = *(unsigned int *)(*(_QWORD *)(v7 + 16) + 4LL);
        if ( (unsigned int)v9 > 7 )
          goto LABEL_52;
        v10 = debug_mdl;
        *((_BYTE *)v19 + v9) = 1;
        if ( (v10 & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v10 & 8,
            4,
            "cam_ife_mgr_process_base_info",
            2718,
            "add CSID base info for hw %d, ctx_idx: %u",
            v9,
            *(_DWORD *)(a1 + 56));
          v11 = i[5];
          if ( !v11 )
            continue;
        }
        else
        {
LABEL_25:
          v11 = i[5];
          if ( !v11 )
            continue;
        }
        v12 = *(unsigned int *)(*(_QWORD *)(v11 + 16) + 4LL);
        if ( (unsigned int)v12 > 7 )
          goto LABEL_52;
        if ( (*((_BYTE *)v19 + v12) & 1) == 0 )
        {
          cam_ife_mgr_add_base_info(a1, 1, v12, 0);
          v13 = *(unsigned int *)(*(_QWORD *)(v11 + 16) + 4LL);
          if ( (unsigned int)v13 > 7 )
LABEL_52:
            __break(0x5512u);
          v14 = debug_mdl;
          *((_BYTE *)v19 + v13) = 1;
          if ( (v14 & 8) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v14 & 8,
              4,
              "cam_ife_mgr_process_base_info",
              2718,
              "add CSID base info for hw %d, ctx_idx: %u",
              v13,
              *(_DWORD *)(a1 + 56));
        }
      }
    }
    for ( j = *(__int64 **)(a1 + 240); j != (__int64 *)(a1 + 240); j = (__int64 *)*j )
    {
      if ( *((_DWORD *)j + 4) )
      {
        v16 = j[4];
        if ( v16
          && (cam_ife_mgr_add_base_info(a1, 0, *(unsigned int *)(*(_QWORD *)(v16 + 16) + 4LL), 7), (debug_mdl & 8) != 0)
          && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_process_base_info",
            2736,
            "add SFE base info for hw %d, ctx_idx: %u",
            *(_DWORD *)(*(_QWORD *)(v16 + 16) + 4LL),
            *(_DWORD *)(a1 + 56));
          v17 = j[5];
          if ( v17 )
          {
LABEL_42:
            cam_ife_mgr_add_base_info(a1, 1, *(unsigned int *)(*(_QWORD *)(v17 + 16) + 4LL), 7);
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_process_base_info",
                2736,
                "add SFE base info for hw %d, ctx_idx: %u",
                *(_DWORD *)(*(_QWORD *)(v17 + 16) + 4LL),
                *(_DWORD *)(a1 + 56));
          }
        }
        else
        {
          v17 = j[5];
          if ( v17 )
            goto LABEL_42;
        }
      }
    }
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_process_base_info",
        2740,
        "ctx base num = %d, ctx_idx: %u",
        *(_DWORD *)(a1 + 8716),
        *(_DWORD *)(a1 + 56));
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
