__int64 __fastcall cam_csiphy_subdev_handle_message(__int64 result, int a2, unsigned int *a3)
{
  __int64 v3; // x19
  unsigned int v4; // w7
  unsigned int v5; // w8
  const char *v6; // x5
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x4
  __int64 v10; // x20
  __int64 v11; // x22
  __int64 v12; // x8
  unsigned int v13; // w7
  unsigned int v14; // w8
  unsigned int v15; // w7
  unsigned int v16; // w8
  __int64 v17; // x23
  __int64 v18; // x8
  int v19; // w11
  unsigned int v20; // w8
  __int64 v21; // x10
  unsigned int v22; // w8
  unsigned int v23; // w6
  __int16 v24; // w10
  __int64 v25; // x7
  int v26; // w8
  __int64 v27; // x1
  unsigned int v28; // w7
  __int64 v29; // x20
  unsigned int *v30; // x21
  __int64 v31; // x0
  unsigned int *v32; // x21
  __int64 v33; // x12

  if ( !a3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x8000,
             1,
             "cam_csiphy_subdev_handle_message",
             202,
             "Empty Payload");
  v3 = *(_QWORD *)(result + 240);
  if ( !v3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x8000,
             1,
             "cam_csiphy_subdev_handle_message",
             207,
             "csiphy_dev ptr is NULL");
  if ( *a3 != *(_DWORD *)(v3 + 932) )
  {
    if ( (debug_mdl & 0x8000) == 0 || debug_priority )
      return result;
    v6 = "Current HW IDX: %u, Expected IDX: %u";
    v7 = (unsigned __int16)debug_mdl & 0x8000;
    v8 = 4;
    v9 = 214;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v7,
             v8,
             "cam_csiphy_subdev_handle_message",
             v9,
             v6);
  }
  if ( a2 > 3 )
  {
    if ( a2 > 5 )
    {
      if ( a2 != 6 )
      {
        if ( a2 == 8 )
          return cam_csiphy_update_qmargin_csid_vals(a3, *a3);
        return result;
      }
      v15 = a3[1];
      if ( v15 == *(unsigned __int16 *)(v3 + 600) )
      {
        v16 = 0;
      }
      else if ( v15 == *(unsigned __int16 *)(v3 + 704) )
      {
        v16 = 1;
      }
      else
      {
        if ( v15 != *(unsigned __int16 *)(v3 + 808) )
        {
          v6 = "Phy session not found %d %d";
          v7 = 0x8000;
          v8 = 1;
          v9 = 297;
          return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                   3,
                   v7,
                   v8,
                   "cam_csiphy_subdev_handle_message",
                   v9,
                   v6);
        }
        v16 = 2;
      }
      v28 = a3[2];
      v29 = v3 + 600 + 104LL * v16;
      if ( v28 == 2 )
      {
        if ( *((_BYTE *)a3 + 13) == 1 )
        {
          v32 = a3;
          result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))cam_csiphy_release_from_reset_state)(
                     *(_QWORD *)(result + 240),
                     *(_QWORD *)(v3 + 1200),
                     v16);
          a3 = v32;
        }
        if ( *((_BYTE *)a3 + 12) != 1 )
          return result;
        v31 = 0;
      }
      else
      {
        if ( v28 != 1 )
        {
          v6 = "CSIPHY:%d Failed to handle CSID halt resume csid_state: %d";
          v7 = 0x8000;
          v8 = 1;
          v9 = 320;
          return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                   3,
                   v7,
                   v8,
                   "cam_csiphy_subdev_handle_message",
                   v9,
                   v6);
        }
        if ( *((_BYTE *)a3 + 13) == 1 )
        {
          v30 = a3;
          result = cam_csiphy_reset(*(_QWORD *)(result + 240));
          a3 = v30;
        }
        if ( *((_BYTE *)a3 + 12) != 1 )
          return result;
        v31 = 1;
      }
      return cam_csiphy_drv_ops_util(v31, v3, v29, a3);
    }
    if ( a2 != 4 )
    {
      v4 = a3[1];
      if ( v4 == *(unsigned __int16 *)(v3 + 600) )
      {
        v5 = 0;
      }
      else if ( v4 == *(unsigned __int16 *)(v3 + 704) )
      {
        v5 = 1;
      }
      else
      {
        if ( v4 != *(unsigned __int16 *)(v3 + 808) )
        {
          v6 = "Phy session not found %d %d";
          v7 = 0x8000;
          v8 = 1;
          v9 = 272;
          return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                   3,
                   v7,
                   v8,
                   "cam_csiphy_subdev_handle_message",
                   v9,
                   v6);
        }
        v5 = 2;
      }
      v33 = v3 + 600 + 104LL * v5;
      *(_BYTE *)(v33 + 89) = *((_BYTE *)a3 + 9);
      *(_BYTE *)(v33 + 88) = *((_BYTE *)a3 + 8);
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        v6 = "PHY: %d, CSID: %d DRV info : use hw client %d, enable drv config %d";
        v7 = (unsigned __int16)debug_mdl & 0x8000;
        v8 = 4;
        v9 = 283;
        return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                 3,
                 v7,
                 v8,
                 "cam_csiphy_subdev_handle_message",
                 v9,
                 v6);
      }
      return result;
    }
    v13 = a3[1];
    if ( v13 == *(unsigned __int16 *)(v3 + 600) )
    {
      v14 = 0;
    }
    else if ( v13 == *(unsigned __int16 *)(v3 + 704) )
    {
      v14 = 1;
    }
    else
    {
      if ( v13 != *(unsigned __int16 *)(v3 + 808) )
      {
        v6 = "Phy session not found %d %d";
        v7 = 0x8000;
        v8 = 1;
        v9 = 252;
        return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                 3,
                 v7,
                 v8,
                 "cam_csiphy_subdev_handle_message",
                 v9,
                 v6);
      }
      v14 = 2;
    }
    *(_DWORD *)(v3 + 600 + 104LL * v14 + 84) = a3[2];
    if ( (debug_mdl & 0x8000) == 0 || debug_priority )
      return result;
    v6 = "PHY: %d, CSID: %d connected";
    v7 = (unsigned __int16)debug_mdl & 0x8000;
    v8 = 4;
    v9 = 260;
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             v7,
             v8,
             "cam_csiphy_subdev_handle_message",
             v9,
             v6);
  }
  if ( a2 == 1 )
  {
    result = cam_csiphy_common_status_reg_dump(*(_QWORD *)(result + 240), 1);
    if ( *(_BYTE *)(v3 + 4731) == 1 )
      result = cam_csiphy_reg_dump(v3 + 912);
    if ( *(_BYTE *)(v3 + 4730) == 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        3,
        "cam_csiphy_trigger_reg_dump",
        26,
        "Status Reg Dump on failure");
      result = cam_csiphy_dump_status_reg(v3);
    }
    if ( *(_DWORD *)(v3 + 4496) > 9u || !*(_DWORD *)(v3 + 1780) )
      return result;
    v11 = 0;
    while ( v11 != 32 )
    {
      v12 = *(unsigned int *)(v3 + 4496);
      if ( (unsigned int)v12 > 9 )
        break;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x8000,
                 3,
                 "cam_csiphy_clk_dump",
                 45,
                 "PHY[%d] Clock Name=%s Clock Rate=%d",
                 *(_DWORD *)(v3 + 932),
                 *(const char **)(v3 + 2296 + 8 * v11 - 512),
                 *(_DWORD *)(v3 + 2296 + (v12 << 7) + 4 * v11));
      if ( ++v11 >= (unsigned __int64)*(unsigned int *)(v3 + 1780) )
        return result;
    }
LABEL_104:
    __break(0x5512u);
    return cam_csiphy_subdev_close(result);
  }
  if ( a2 == 2 )
  {
    result = cam_csiphy_common_status_reg_dump(*(_QWORD *)(result + 240), 1);
    if ( *(_BYTE *)(v3 + 4731) == 1 )
      result = cam_csiphy_reg_dump(v3 + 912);
    if ( *(_BYTE *)(v3 + 4730) == 1 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        3,
        "cam_csiphy_trigger_reg_dump",
        26,
        "Status Reg Dump on failure");
      result = cam_csiphy_dump_status_reg(v3);
    }
    if ( *(_DWORD *)(v3 + 4496) > 9u || !*(_DWORD *)(v3 + 1780) )
    {
LABEL_48:
      if ( (*(_BYTE *)(v3 + 4732) & 1) != 0 )
        return result;
      ((void (__fastcall *)(__int64))cam_csiphy_update_auxiliary_mask)(v3);
      v6 = "CSIPHY[%u] updating aux settings for data rate idx: %u";
      v7 = 0x8000;
      v8 = 3;
      v9 = 234;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
               3,
               v7,
               v8,
               "cam_csiphy_subdev_handle_message",
               v9,
               v6);
    }
    v17 = 0;
    while ( v17 != 32 )
    {
      v18 = *(unsigned int *)(v3 + 4496);
      if ( (unsigned int)v18 > 9 )
        break;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x8000,
                 3,
                 "cam_csiphy_clk_dump",
                 45,
                 "PHY[%d] Clock Name=%s Clock Rate=%d",
                 *(_DWORD *)(v3 + 932),
                 *(const char **)(v3 + 2296 + 8 * v17 - 512),
                 *(_DWORD *)(v3 + 2296 + (v18 << 7) + 4 * v17));
      if ( ++v17 >= (unsigned __int64)*(unsigned int *)(v3 + 1780) )
        goto LABEL_48;
    }
    goto LABEL_104;
  }
  if ( a2 != 3 )
    return result;
  if ( *(_BYTE *)(v3 + 603) && a3[1] == *(unsigned __int16 *)(v3 + 600) )
  {
    v10 = v3 + 600;
  }
  else if ( *(_BYTE *)(v3 + 707) && a3[1] == *(unsigned __int16 *)(v3 + 704) )
  {
    v10 = v3 + 704;
  }
  else
  {
    if ( !*(_BYTE *)(v3 + 811) || a3[1] != *(unsigned __int16 *)(v3 + 808) )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x8000,
               1,
               "cam_csiphy_populate_secure_info",
               149,
               "No matching secure PHY for a session");
    v10 = v3 + 808;
  }
  v19 = *(_DWORD *)(v10 + 24);
  *(_DWORD *)(v10 + 76) = a3[5];
  *(_DWORD *)(v10 + 72) = a3[4];
  v20 = *(_DWORD *)(v10 + 4);
  v21 = *((_QWORD *)a3 + 1);
  *(_DWORD *)(v10 + 56) = 0;
  *(_QWORD *)(v10 + 64) = v21;
  if ( v19 )
    v22 = ((v20 >> 2) & 2 | (v20 >> 1) & 1 | (v20 >> 3) & 4) << 16;
  else
    v22 = (v20 & 1 | (2 * ((v20 >> 2) & 1)) | (v20 >> 2) & 4 | (v20 >> 3) & 8) << 24;
  v23 = *(_DWORD *)(v3 + 932);
  if ( v23 > 7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_format_secure_phy_lane_info",
      78,
      "Invalid PHY index: %u",
      v23);
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x8000,
             1,
             "cam_csiphy_populate_secure_info",
             142,
             "Error in formatting PHY[%u] phy_lane_sel_mask: 0x%llx",
             *(_DWORD *)(v3 + 932),
             *(_QWORD *)(v10 + 40));
  }
  v24 = debug_mdl;
  v25 = (1LL << v23) | v22;
  v26 = debug_priority;
  v27 = (unsigned __int16)debug_mdl & 0x8000;
  *(_QWORD *)(v10 + 40) = v25;
  if ( v24 < 0 && !v26 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
               3,
               v27,
               4,
               "cam_csiphy_format_secure_phy_lane_info",
               86,
               "Formatted PHY[%u] phy_lane_sel_mask: 0x%llx",
               *(unsigned int *)(v3 + 932));
    v26 = debug_priority;
    v27 = (unsigned __int16)debug_mdl & 0x8000;
    *(_BYTE *)(v10 + 80) = 1;
    if ( !v27 )
      return result;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 1;
    if ( !v27 )
      return result;
  }
  if ( !v26 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v27,
             4,
             "cam_csiphy_populate_secure_info",
             137,
             "PHY[%d] secure info, phy_lane_mask: 0x%llx, ife: 0x%x, cdm: 0x%x, vc_mask: 0x%llx",
             *(_DWORD *)(v3 + 932),
             *(_QWORD *)(v10 + 40),
             *(_DWORD *)(v10 + 72),
             *(_DWORD *)(v10 + 76),
             *(_QWORD *)(v10 + 64));
  return result;
}
