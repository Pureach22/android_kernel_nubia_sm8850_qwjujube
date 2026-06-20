__int64 __fastcall cam_vfe_handle_sof(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x20
  __int64 v7; // x19
  int v8; // w8
  __int64 v9; // x7
  unsigned int v10; // w8
  __int64 v11; // x10
  __int64 v12; // x9
  int v13; // w8
  int v14; // w10
  int v15; // w9
  _DWORD *v17; // x8
  int v18; // w9
  unsigned int v19; // w9
  const char *v20; // x7
  __int64 v21; // x19
  __int64 v22; // x20
  int v23; // [xsp+0h] [xbp-20h]
  _DWORD *v24; // [xsp+8h] [xbp-18h] BYREF
  __int64 v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v5 = a1 + 20480;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 22813) == 1 && *(_DWORD *)(a1 + 22704) <= 2u )
  {
    v7 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_handle_sof",
      2279,
      "VFE:%u Received SOF at [%lld: %09lld]",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      *(_QWORD *)(a2 + 40),
      *(_QWORD *)(a2 + 48));
    a1 = v7;
    v8 = *(_DWORD *)(v5 + 2224) + 1;
    *(_DWORD *)(v5 + 2224) = v8;
    if ( v8 != 2 )
    {
LABEL_15:
      v10 = 0;
      ++*(_DWORD *)(*(_QWORD *)(a1 + 72) + 10772LL);
      goto LABEL_16;
    }
    *(_DWORD *)(v5 + 2224) = 0;
    v9 = *(unsigned int *)(a3 + 8);
    v25 = 0;
    if ( (unsigned int)v9 >= 7 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, _DWORD *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_handle_sof",
        2290,
        "VFE:%u inval res_id for mux_rsrc:%d",
        *(unsigned int *)(*(_QWORD *)(v7 + 16) + 4LL),
        v9,
        v23,
        v24,
        v25,
        v26);
LABEL_6:
      v10 = -22;
LABEL_16:
      _ReadStatusReg(SP_EL0);
      return v10;
    }
    v17 = *(_DWORD **)(v7 + 72);
    v18 = v17[272];
    if ( !v18 || v17[7] == (_DWORD)v9 )
    {
      v19 = 0;
LABEL_28:
      v24 = &v17[38 * v19 + 6];
      cam_vfe_top_ver4_update_sof_debug((__int64 *)&v24, 0x10u);
      a1 = v7;
      goto LABEL_15;
    }
    if ( v18 == 1 || v17[45] == (_DWORD)v9 )
    {
      v19 = 1;
      goto LABEL_28;
    }
    if ( v18 == 2 || v17[83] == (_DWORD)v9 )
    {
      v19 = 2;
      goto LABEL_28;
    }
    if ( v18 == 3 || v17[121] == (_DWORD)v9 )
    {
      v19 = 3;
      goto LABEL_28;
    }
    if ( v18 == 4 || v17[159] == (_DWORD)v9 )
    {
      v19 = 4;
      goto LABEL_28;
    }
    if ( v18 == 5 || v17[197] == (_DWORD)v9 )
    {
      v19 = 5;
      goto LABEL_28;
    }
    if ( v18 == 6 || v17[235] == (_DWORD)v9 )
    {
      v19 = 6;
      goto LABEL_28;
    }
    if ( v18 == 7 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, _DWORD *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_handle_sof",
        2299,
        "VFE:%u inval res_id :%d res_idx = %d",
        *(unsigned int *)(*(_QWORD *)(v7 + 16) + 4LL),
        v9,
        7,
        v24,
        v25,
        v26);
      goto LABEL_6;
    }
  }
  else
  {
    v11 = *(unsigned int *)(*(_QWORD *)(a1 + 24) + 776LL);
    if ( (unsigned int)v11 <= 4 )
    {
      v12 = *(_QWORD *)(a1 + 64);
      v13 = *(unsigned __int8 *)(v12 + 64);
      if ( v13 == 1 )
      {
        v14 = *(_DWORD *)(a2 + 4 * v11 + 16);
        if ( (*(_DWORD *)(v12 + 68) & v14) != 0 )
        {
          v15 = 0;
        }
        else if ( (*(_DWORD *)(v12 + 72) & v14) != 0 )
        {
          v15 = 1;
        }
        else if ( (*(_DWORD *)(v12 + 76) & v14) != 0 )
        {
          v15 = 2;
        }
        else
        {
          v15 = -1;
        }
      }
      else
      {
        v15 = -1;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        if ( v13 )
          v20 = "Y";
        else
          v20 = "N";
        v21 = a2;
        v22 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_handle_sof",
          2321,
          "VFE:%u is_mc:%s hw_ctxt:%d Received SOF",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
          v20,
          v15);
        a2 = v21;
        a1 = v22;
      }
      *(_QWORD *)(a1 + 22736) = *(_QWORD *)(a2 + 40);
      *(_QWORD *)(a1 + 22744) = *(_QWORD *)(a2 + 48);
      goto LABEL_15;
    }
  }
  __break(0x5512u);
  return cam_vfe_top_ver4_print_diag_sensor_frame_count_info(a1, a2, a3, a4, a5);
}
