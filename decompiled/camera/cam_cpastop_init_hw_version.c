__int64 __fastcall cam_cpastop_init_hw_version(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x21
  int v3; // w8
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  int v8; // w7
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x12
  __int64 v12; // x12
  __int64 v13; // x12
  __int64 v14; // x12
  __int64 v15; // x9
  int v16; // w6
  __int64 v17; // x8
  __int64 v18; // x12
  __int64 v19; // x10
  __int64 v20; // x11
  _BYTE *v21; // x12
  __int64 v22; // x12
  __int64 v23; // x10
  __int64 v24; // x11
  _BYTE *v25; // x12
  __int64 v26; // x12
  __int64 v27; // x10
  __int64 v28; // x11
  _BYTE *v29; // x12
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x10
  _BYTE *v33; // x11
  _DWORD *v34; // x22
  _DWORD *v35; // x21
  int v36; // w6
  const char *v37; // x5
  __int64 v38; // x4
  unsigned int v39; // w19
  unsigned int v41; // w8
  __int64 v42; // x23
  int v43; // w0
  char v44; // w8
  int v45; // w0
  _DWORD *v46; // x22
  __int64 v47; // x23

  v2 = *(_QWORD *)(a1 + 3680);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v46 = a2;
    v47 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpastop_init_hw_version",
      1696,
      "hw_version=0x%x Camera Version %d.%d.%d, cpas version %d.%d.%d",
      *(_DWORD *)(a1 + 112),
      a2[1],
      a2[2],
      a2[3],
      a2[5],
      a2[6],
      a2[7]);
    a2 = v46;
    a1 = v47;
  }
  v3 = *(_DWORD *)(a1 + 112);
  if ( v3 > 5701887 )
  {
    if ( v3 <= 7864575 )
    {
      if ( v3 > 6554111 )
      {
        switch ( v3 )
        {
          case 6554112:
            v4 = &cam640_cpas200_hw_info;
            break;
          case 6816000:
            v4 = &cam680_cpas100_hw_info;
            break;
          case 6816016:
            v4 = &cam680_cpas110_hw_info;
            break;
          default:
            goto LABEL_126;
        }
      }
      else
      {
        switch ( v3 )
        {
          case 5701888:
            v4 = &cam570_cpas100_hw_info;
            break;
          case 5702144:
            v4 = &cam570_cpas200_hw_info;
            break;
          case 5767424:
            v4 = &cam580_cpas100_hw_info;
            break;
          default:
            goto LABEL_126;
        }
      }
    }
    else if ( v3 <= 9916671 )
    {
      switch ( v3 )
      {
        case 7864576:
          v4 = &cam780_cpas100_hw_info;
          break;
        case 8913152:
          v4 = &cam880_cpas100_hw_info;
          break;
        case 9896208:
          v4 = &cam970_cpas110_hw_info;
          break;
        default:
          goto LABEL_126;
      }
    }
    else if ( v3 > 17264895 )
    {
      if ( v3 == 17264896 )
      {
        v4 = &cam1077_cpas100_hw_info;
      }
      else
      {
        if ( v3 != 17301760 )
          goto LABEL_126;
        v4 = &cam1080_cpas100_hw_info;
      }
    }
    else if ( v3 == 9916672 )
    {
      v4 = &cam975_cpas100_hw_info;
    }
    else
    {
      if ( v3 != 9961728 )
        goto LABEL_126;
      v4 = &cam980_cpas100_hw_info;
    }
  }
  else if ( v3 <= 1528064 )
  {
    if ( v3 > 1507599 )
    {
      switch ( v3 )
      {
        case 1507600:
          v4 = &cam170_cpas110_hw_info;
          break;
        case 1507840:
          v4 = &cam170_cpas200_hw_info;
          break;
        case 1528064:
          v4 = &cam175_cpas100_hw_info;
          break;
        default:
          goto LABEL_126;
      }
    }
    else
    {
      switch ( v3 )
      {
        case 1376512:
          v4 = &cam150_cpas100_hw_info;
          break;
        case 1462528:
          v4 = &cam165_cpas100_hw_info;
          break;
        case 1507584:
          v4 = &cam170_cpas100_hw_info;
          break;
        default:
          goto LABEL_126;
      }
    }
  }
  else if ( v3 <= 4718847 )
  {
    switch ( v3 )
    {
      case 1528065:
        v4 = &cam175_cpas101_hw_info;
        break;
      case 1528096:
        v4 = &cam175_cpas120_hw_info;
        break;
      case 1528112:
        v4 = &cam175_cpas130_hw_info;
        break;
      default:
        goto LABEL_126;
    }
  }
  else if ( v3 > 5505279 )
  {
    if ( v3 == 5505280 )
    {
      v4 = &cam540_cpas100_hw_info;
    }
    else
    {
      if ( v3 != 5525760 )
        goto LABEL_126;
      v4 = &cam545_cpas100_hw_info;
    }
  }
  else
  {
    if ( v3 != 4718848 )
    {
      if ( v3 == 5374208 )
      {
        v4 = &cam520_cpas100_hw_info;
        goto LABEL_65;
      }
LABEL_126:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpastop_init_hw_version",
        1781,
        "Camera Version not supported %d.%d.%d",
        a2[1],
        a2[2],
        a2[3]);
      return (unsigned int)-22;
    }
    v4 = &cam480_cpas100_hw_info;
  }
LABEL_65:
  *(_QWORD *)v2 = v4;
  v5 = v2 + 2812;
  v6 = v4[1];
  if ( v6 )
  {
    v7 = *(unsigned int *)(v6 + 4);
    if ( (unsigned int)v7 > 9 )
      goto LABEL_138;
    if ( *(_DWORD *)(v5 + 4 * v7) == -1 )
    {
      v17 = 0;
      goto LABEL_120;
    }
    v8 = 1;
    v9 = v4[2];
    if ( v9 )
    {
LABEL_69:
      v10 = *(unsigned int *)(v9 + 4);
      if ( (unsigned int)v10 > 9 )
        goto LABEL_138;
      if ( *(_DWORD *)(v5 + 4 * v10) != -1 )
      {
        ++v8;
        v11 = v4[3];
        if ( !v11 )
          goto LABEL_72;
        goto LABEL_78;
      }
      v17 = 1;
LABEL_120:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpastop_setup_camnoc_info",
        1548,
        "Regbase not set up for %s",
        g_camnoc_names[v17]);
      goto LABEL_121;
    }
  }
  else
  {
    v8 = 0;
    v9 = v4[2];
    if ( v9 )
      goto LABEL_69;
  }
  v11 = v4[3];
  if ( !v11 )
  {
LABEL_72:
    v12 = v4[4];
    if ( v12 )
      goto LABEL_73;
LABEL_81:
    if ( !v8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpastop_setup_camnoc_info",
        1556,
        "No available camnoc header for binding");
      goto LABEL_121;
    }
    goto LABEL_82;
  }
LABEL_78:
  v14 = *(unsigned int *)(v11 + 4);
  if ( (unsigned int)v14 > 9 )
    goto LABEL_138;
  if ( *(_DWORD *)(v5 + 4 * v14) == -1 )
  {
    v17 = 2;
    goto LABEL_120;
  }
  ++v8;
  v12 = v4[4];
  if ( !v12 )
    goto LABEL_81;
LABEL_73:
  v13 = *(unsigned int *)(v12 + 4);
  if ( (unsigned int)v13 > 9 )
    goto LABEL_138;
  if ( *(_DWORD *)(v5 + 4 * v13) == -1 )
  {
    v17 = 3;
    goto LABEL_120;
  }
  ++v8;
LABEL_82:
  v15 = v4[5];
  v16 = *(unsigned __int8 *)(v15 + 36);
  if ( *(_BYTE *)(v15 + 36) && v8 != v16 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_setup_camnoc_info",
      1563,
      "Invalid number of qchannel: %u number of camnoc: %u",
      v16,
      v8);
LABEL_121:
    v37 = "Failed to set up camnoc info rc=%d";
    v38 = 1787;
    goto LABEL_122;
  }
  if ( !(v6 | v9) )
  {
    *(_BYTE *)(v2 + 159424) = -1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_setup_camnoc_info",
      1573,
      "No CAMNOC RT idx found");
    goto LABEL_121;
  }
  *(_BYTE *)(v2 + 159424) = v6 == 0;
  v18 = v4[1];
  if ( v18 )
  {
    v19 = *(unsigned int *)(v18 + 40);
    if ( (int)v19 >= 1 )
    {
      v20 = 0;
      v21 = (_BYTE *)(*(_QWORD *)(v18 + 32) + 4LL);
      while ( *((_DWORD *)v21 - 1) || *v21 != 1 )
      {
        ++v20;
        v21 += 96;
        if ( v19 == v20 )
          goto LABEL_95;
      }
      *(_DWORD *)(v2 + 2796) = v20;
      *(_BYTE *)(v2 + 159427) = 1;
    }
  }
LABEL_95:
  v22 = v4[2];
  if ( v22 )
  {
    v23 = *(unsigned int *)(v22 + 40);
    if ( (int)v23 >= 1 )
    {
      v24 = 0;
      v25 = (_BYTE *)(*(_QWORD *)(v22 + 32) + 4LL);
      while ( *((_DWORD *)v25 - 1) || (*v25 & 1) == 0 )
      {
        ++v24;
        v25 += 96;
        if ( v23 == v24 )
          goto LABEL_102;
      }
      *(_DWORD *)(v2 + 2800) = v24;
      *(_BYTE *)(v2 + 159428) = 1;
    }
  }
LABEL_102:
  v26 = v4[3];
  if ( v26 )
  {
    v27 = *(unsigned int *)(v26 + 40);
    if ( (int)v27 >= 1 )
    {
      v28 = 0;
      v29 = (_BYTE *)(*(_QWORD *)(v26 + 32) + 4LL);
      while ( *((_DWORD *)v29 - 1) || (*v29 & 1) == 0 )
      {
        ++v28;
        v29 += 96;
        if ( v27 == v28 )
          goto LABEL_109;
      }
      *(_DWORD *)(v2 + 2804) = v28;
      *(_BYTE *)(v2 + 159429) = 1;
    }
  }
LABEL_109:
  v30 = v4[4];
  if ( v30 )
  {
    v31 = *(unsigned int *)(v30 + 40);
    if ( (int)v31 >= 1 )
    {
      v32 = 0;
      v33 = (_BYTE *)(*(_QWORD *)(v30 + 32) + 4LL);
      while ( *((_DWORD *)v33 - 1) || (*v33 & 1) == 0 )
      {
        ++v32;
        v33 += 96;
        if ( v31 == v32 )
          goto LABEL_116;
      }
      *(_DWORD *)(v2 + 2808) = v32;
      *(_BYTE *)(v2 + 159430) = 1;
    }
  }
LABEL_116:
  v34 = *(_DWORD **)(a1 + 3680);
  v35 = *(_DWORD **)(*(_QWORD *)v34 + 40LL);
  v36 = v35[6];
  if ( (unsigned int)(v36 - 3) < 0xFFFFFFFE )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_get_hw_capability",
      1614,
      "Invalid number of populated caps registers: %u",
      v36);
    v37 = "Failed to get titan hw capability rc=%d";
    v38 = 1793;
LABEL_122:
    v39 = -22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpastop_init_hw_version",
      v38,
      v37,
      4294967274LL);
    return v39;
  }
  v34[13] = v36;
  v41 = v34[703];
  if ( !v35[6] )
    return 0;
  if ( v41 <= 7 )
  {
    v42 = a1 + 24LL * v41;
    v43 = cam_io_r_mb(*(_QWORD *)(v42 + 384) + (unsigned int)v35[7]);
    v44 = debug_mdl;
    v34[11] = v43;
    if ( (v44 & 4) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v44 & 4,
        4,
        "cam_cpastop_get_hw_capability",
        1626,
        "camera_caps_%d = 0x%x",
        0,
        v43);
    if ( v35[6] < 2u )
      return 0;
    v45 = cam_io_r_mb(*(_QWORD *)(v42 + 384) + (unsigned int)v35[8]);
    v34[12] = v45;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_get_hw_capability",
        1626,
        "camera_caps_%d = 0x%x",
        1,
        v45);
    if ( v35[6] <= 2u )
      return 0;
  }
LABEL_138:
  __break(0x5512u);
  return cam_cpastop_handle_irq();
}
