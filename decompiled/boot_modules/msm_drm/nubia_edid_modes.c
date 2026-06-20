__int64 __fastcall nubia_edid_modes(__int64 a1)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v4; // x0
  void *v5; // x0
  _QWORD *v6; // x27
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  unsigned int v11; // w9
  unsigned int v12; // w20
  int v13; // w21
  unsigned int v14; // w9
  bool v15; // cf
  int v16; // w22
  char v17; // w23
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  void *v21; // x20
  __int64 v22; // x8
  unsigned int v23; // w21
  int v24; // w10
  __int64 v25; // x8
  __int64 v26; // x0
  size_t v27; // x0
  __int64 v28; // x0
  const char *v29; // x21
  __int64 v30; // x8
  const char *v31; // x22
  _QWORD *v32; // x23
  __int64 v33; // x0
  _QWORD *v34; // x19
  int v35; // w21
  _WORD *v36; // x8
  __int64 v37; // x0
  __int64 v38; // x8
  _WORD *v39; // x9
  __int64 v40; // x0
  int v41; // w19
  __int64 v42; // x0
  unsigned __int16 v43; // w0
  int v44; // w28
  int v45; // w24
  unsigned __int16 v46; // w21
  const char *v47; // x20
  __int64 v48; // x22
  unsigned __int64 v49; // x25
  char v50; // w26
  size_t v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  _QWORD *i; // x19
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x9
  __int64 v61; // x0
  __int64 v62; // x0
  char v63; // [xsp+14h] [xbp-CCh]
  unsigned __int64 v64; // [xsp+18h] [xbp-C8h]
  unsigned __int16 v65; // [xsp+20h] [xbp-C0h]
  int v66; // [xsp+2Ch] [xbp-B4h]
  char string[8]; // [xsp+38h] [xbp-A8h] BYREF
  __int64 v68; // [xsp+40h] [xbp-A0h]
  int v69; // [xsp+48h] [xbp-98h]
  char dest[128]; // [xsp+50h] [xbp-90h] BYREF
  __int64 v71; // [xsp+D0h] [xbp-10h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(ipc_log_context, "[d][%-4d]: +\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]: +\n", *(_DWORD *)(StatusReg + 1800));
  if ( !dp_debug_p )
  {
    v4 = get_ipc_log_context();
    ipc_log_string(v4, "[w][%-4d]: dp_debug_p = NULL\n", *(_DWORD *)(StatusReg + 1800));
    v5 = &unk_24BFA7;
    goto LABEL_11;
  }
  v6 = (_QWORD *)(a1 + 176);
  if ( *(_QWORD *)(a1 + 176) == a1 + 176 )
  {
    v7 = get_ipc_log_context();
    ipc_log_string(v7, "[i][%-4d]: connector modes is empty\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) == 0 )
    {
      v5 = &unk_2799CE;
      goto LABEL_11;
    }
    result = printk(&unk_23EBB8, *(unsigned int *)(StatusReg + 1800));
    goto LABEL_12;
  }
  if ( !edid_ctl || !*(_QWORD *)(edid_ctl + 48) )
  {
    v8 = get_ipc_log_context();
    ipc_log_string(v8, "[w][%-4d]: edid_ctl or edid_ctl->sel_mode = NULL\n", *(_DWORD *)(StatusReg + 1800));
    v5 = &unk_26BF8A;
    goto LABEL_11;
  }
  v10 = *(_QWORD *)(dp_debug_p + 120);
  v11 = *(unsigned __int8 *)(v10 + 962);
  v12 = v11 >> 4;
  v13 = v11 & 0xF;
  v14 = (v11 >> 4) - 1;
  v15 = v13 != 1 || v14 >= 2;
  v16 = !v15;
  v17 = drm_detect_hdmi_monitor(**(_QWORD **)(v10 + 96));
  v18 = get_ipc_log_context();
  ipc_log_string(
    v18,
    "[i][%-4d]: dp revision = 0x%x, hdmi cable = %d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(*(_QWORD *)(dp_debug_p + 360) + 392LL),
    v17 & 1);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_22A3CC, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_23B30F, "nubia_edid_modes");
  v19 = get_ipc_log_context();
  ipc_log_string(
    v19,
    "[i][%-4d]: sink dsc version: %d.%d, dsc_version_supported = %d\n",
    *(_DWORD *)(StatusReg + 1800),
    v13,
    v12,
    v16);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2459AA, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_223A50, "nubia_edid_modes");
  if ( !(unsigned __int16)strlen((const char *)(a1 + 2300)) )
  {
    v20 = get_ipc_log_context();
    ipc_log_string(v20, "[w][%-4d]: original monitor name length = %d\n", *(_DWORD *)(StatusReg + 1800), 0);
    printk(&unk_219100, "nubia_edid_modes");
    goto LABEL_46;
  }
  v21 = (void *)edid_ctl;
  v69 = 0;
  *(_QWORD *)string = 0;
  v68 = 0;
  strncpy(dest, (const char *)(a1 + 2300), 0x7Fu);
  v22 = 0;
  v23 = 0;
  dest[127] = 0;
  do
  {
    if ( v22 == 128 )
      goto LABEL_138;
    v24 = (unsigned __int8)dest[v22];
    if ( !dest[v22] )
    {
      v25 = v23;
      goto LABEL_41;
    }
    if ( (unsigned int)(v24 - 48) < 0xA
      || (unsigned int)(v24 - 97) < 0x1A
      || v24 == 32
      || (unsigned int)(v24 - 65) <= 0x19 )
    {
      string[v23++] = v24;
    }
    ++v22;
  }
  while ( v23 < 0x13 );
  v26 = get_ipc_log_context();
  ipc_log_string(v26, "[w][%-4d]: monitor_string full\n", *(_DWORD *)(StatusReg + 1800));
  printk(&unk_23EC11, "trim_monitor_string");
  if ( v23 != 19 )
  {
LABEL_138:
    __break(0x5512u);
    __break(1u);
  }
  v25 = 19;
LABEL_41:
  string[v25] = 0;
  v27 = strnlen(string, 0x14u);
  if ( v27 >= 0x15 )
  {
LABEL_134:
    v51 = _fortify_panic(2, 20, v27 + 1);
LABEL_135:
    _fortify_panic(2, 12, v51 + 1);
LABEL_136:
    _fortify_panic(4, 20, 21);
LABEL_137:
    _fortify_panic(4, 12, 13);
    goto LABEL_138;
  }
  if ( v27 == 20 )
  {
    v62 = _fortify_panic(4, 20, 21);
    return get_higher_refresh_resolution(v62);
  }
  memcpy(v21, string, v27 + 1);
  v28 = get_ipc_log_context();
  ipc_log_string(
    v28,
    "[i][%-4d][monitor_name]: original = %s, trimed = %s\n",
    *(_DWORD *)(StatusReg + 1800),
    (const char *)(a1 + 2300),
    (const char *)edid_ctl);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_22DAB8, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_226C18, "nubia_edid_modes");
LABEL_46:
  v29 = (const char *)edid_ctl;
  v30 = edid_ctl + 56;
  v31 = *(const char **)(edid_ctl + 56);
  while ( 1 )
  {
    if ( v31 == (const char *)v30 )
    {
      v63 = 0;
      goto LABEL_62;
    }
    if ( !strcmp(v31 - 40, v29) && !strcmp(v31 - 20, v29 + 20) )
    {
      v32 = (_QWORD *)*v6;
      if ( (_QWORD *)*v6 != v6 )
        break;
    }
LABEL_48:
    v31 = *(const char **)v31;
    v30 = (__int64)(v29 + 56);
  }
  while ( *((unsigned __int16 *)v32 - 30) != *((unsigned __int16 *)v31 - 4)
       || *((unsigned __int16 *)v32 - 25) != *((unsigned __int16 *)v31 - 3)
       || (unsigned int)drm_mode_vrefresh(v32 - 8) != *((unsigned __int16 *)v31 - 2)
       || *((_DWORD *)v32 + 13) != *((unsigned __int8 *)v31 - 2) )
  {
    v32 = (_QWORD *)*v32;
    if ( v32 == v6 )
    {
      v29 = (const char *)edid_ctl;
      goto LABEL_48;
    }
  }
  **(_WORD **)(edid_ctl + 48) = *((_WORD *)v31 - 4);
  *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 2LL) = *((_WORD *)v31 - 3);
  *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 4LL) = *((_WORD *)v31 - 2);
  *(_BYTE *)(*(_QWORD *)(edid_ctl + 48) + 6LL) = *(v31 - 2);
  v33 = get_ipc_log_context();
  ipc_log_string(
    v33,
    "[i][%-4d]: %s %s %dx%d %d %d matched\n",
    *(_DWORD *)(StatusReg + 1800),
    v31 - 40,
    v31 - 20,
    *((unsigned __int16 *)v31 - 4),
    *((unsigned __int16 *)v31 - 3),
    *((unsigned __int16 *)v31 - 2),
    *((unsigned __int8 *)v31 - 2));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2650DD, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_22A4EF, "match_user_edid_modes");
  v63 = 1;
LABEL_62:
  v34 = (_QWORD *)*v6;
  if ( (_QWORD *)*v6 == v6 )
  {
    LOBYTE(v35) = 0;
LABEL_64:
    v36 = *(_WORD **)(edid_ctl + 48);
    if ( !*v36 || !v36[1] )
    {
      v37 = get_ipc_log_context();
      ipc_log_string(v37, "[w][%-4d]: no 16:9 resolutions, use others\n", *(_DWORD *)(StatusReg + 1800));
      printk(&unk_256787, "nubia_edid_modes");
      if ( (v63 & 1) == 0 )
      {
        for ( i = (_QWORD *)*v6; i != v6; i = (_QWORD *)*i )
        {
          drm_mode_vrefresh(i - 8);
          get_higher_refresh_resolution(*((unsigned __int16 *)i - 30));
        }
      }
    }
    if ( (_BYTE)v35 )
    {
      v38 = edid_ctl;
      v39 = *(_WORD **)(edid_ctl + 48);
      if ( *v39 && v39[1] )
      {
        v60 = dp_debug_p;
        *(_BYTE *)(*(_QWORD *)(dp_debug_p + 120) + 981LL) = 1;
        *(_DWORD *)(*(_QWORD *)(v60 + 120) + 984LL) = **(unsigned __int16 **)(v38 + 48);
        *(_DWORD *)(*(_QWORD *)(v60 + 120) + 988LL) = *(unsigned __int16 *)(*(_QWORD *)(v38 + 48) + 2LL);
        *(_DWORD *)(*(_QWORD *)(v60 + 120) + 992LL) = *(unsigned __int16 *)(*(_QWORD *)(v38 + 48) + 4LL);
        *(_DWORD *)(*(_QWORD *)(v60 + 120) + 996LL) = *(unsigned __int8 *)(*(_QWORD *)(v38 + 48) + 6LL);
        v61 = get_ipc_log_context();
        ipc_log_string(
          v61,
          "[i][%-4d]: selected_edid_mode: %dx%d %d %d, mode_override = %d\n",
          *(_DWORD *)(StatusReg + 1800),
          **(unsigned __int16 **)(edid_ctl + 48),
          *(unsigned __int16 *)(*(_QWORD *)(edid_ctl + 48) + 2LL),
          *(unsigned __int16 *)(*(_QWORD *)(edid_ctl + 48) + 4LL),
          *(unsigned __int8 *)(*(_QWORD *)(edid_ctl + 48) + 6LL),
          *(unsigned __int8 *)(*(_QWORD *)(dp_debug_p + 120) + 981LL));
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_24BFD9, *(unsigned int *)(StatusReg + 1800));
        else
          printk(&unk_25DE23, "nubia_edid_modes");
      }
      else
      {
        v40 = get_ipc_log_context();
        ipc_log_string(v40, "[e][%-4d]: no best edid mode found\n", *(_DWORD *)(StatusReg + 1800));
        printk(&unk_26849C, "nubia_edid_modes");
      }
      v41 = (unsigned __int16)strlen(*(const char **)(edid_ctl + 32));
      if ( v41 )
        *(_BYTE *)(edid_ctl + 40) = 1;
      v42 = get_ipc_log_context();
      ipc_log_string(
        v42,
        "[i][%-4d]: edid_modes length = %d, cable_connected = %d\n",
        *(_DWORD *)(StatusReg + 1800),
        v41,
        *(unsigned __int8 *)(edid_ctl + 40));
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_21CD2B, *(unsigned int *)(StatusReg + 1800));
      else
        printk(&unk_215533, "nubia_edid_modes");
    }
    v58 = get_ipc_log_context();
    ipc_log_string(v58, "[i][%-4d]: edid_modes count = %d\n", *(_DWORD *)(StatusReg + 1800), (unsigned __int8)v35);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_226C61, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_22A4B9, "nubia_edid_modes");
    v59 = get_ipc_log_context();
    result = ipc_log_string(v59, "[d][%-4d]: -\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]: -\n", *(_DWORD *)(StatusReg + 1800));
    goto LABEL_12;
  }
  v35 = 0;
  v64 = StatusReg;
  v65 = 0;
  while ( 1 )
  {
    v66 = v35;
    v43 = drm_mode_vrefresh(v34 - 8);
    v44 = *((unsigned __int16 *)v34 - 30);
    v45 = *((unsigned __int16 *)v34 - 25);
    v46 = v43;
    v47 = (const char *)edid_ctl;
    v48 = 0;
    v49 = 0;
    v50 = 1;
    while ( 1 )
    {
      v27 = strnlen(&filtered_modes[v48], 0x14u);
      if ( v27 >= 0x15 )
        goto LABEL_134;
      if ( !v27 )
        goto LABEL_142;
      if ( v27 == 20 )
        goto LABEL_136;
      if ( !strcmp(v47, &filtered_modes[v48]) )
      {
LABEL_142:
        v51 = strnlen(&filtered_modes[v48 + 20], 0xCu);
        if ( v51 >= 0xD )
          goto LABEL_135;
        if ( !v51 )
          goto LABEL_94;
        if ( v51 == 12 )
          goto LABEL_137;
        if ( !strcmp(v47 + 20, &filtered_modes[v48 + 20]) )
        {
LABEL_94:
          if ( (!*(_WORD *)&filtered_modes[v48 + 32] || *(unsigned __int16 *)&filtered_modes[v48 + 32] == v44)
            && (!*(_WORD *)&filtered_modes[v48 + 34] || *(unsigned __int16 *)&filtered_modes[v48 + 34] == v45)
            && (!*(_WORD *)&filtered_modes[v48 + 36] || *(unsigned __int16 *)&filtered_modes[v48 + 36] == v46) )
          {
            break;
          }
        }
      }
      v15 = v49 >= 0xF;
      v48 += 40;
      ++v49;
      v50 = !v15;
      if ( v48 == 640 )
        goto LABEL_97;
    }
    v52 = get_ipc_log_context();
    ipc_log_string(
      v52,
      "[i][%-4d]: name = %s, vdo = %s, %dx%d %d %d\n",
      *(_DWORD *)(v64 + 1800),
      &filtered_modes[v48],
      &filtered_modes[v48 + 20],
      *(unsigned __int16 *)&filtered_modes[v48 + 32],
      *(unsigned __int16 *)&filtered_modes[v48 + 34],
      *(unsigned __int16 *)&filtered_modes[v48 + 36],
      (unsigned __int8)filtered_modes[v48 + 38]);
    if ( (_drm_debug & 4) != 0 )
      break;
    printk(&unk_25A28C, "filter_edid_modes");
    if ( (v50 & 1) == 0 )
      goto LABEL_97;
LABEL_118:
    StatusReg = v64;
    v35 = v66;
LABEL_115:
    v34 = (_QWORD *)*v34;
    if ( v34 == v6 )
      goto LABEL_64;
  }
  printk(&unk_25DE97, *(unsigned int *)(v64 + 1800));
  if ( (v50 & 1) != 0 )
    goto LABEL_118;
LABEL_97:
  if ( *((_WORD *)v34 - 30) && *((_WORD *)v34 - 25) )
  {
    StatusReg = v64;
    v65 += (unsigned __int8)snprintf(
                              (char *)(*(_QWORD *)(edid_ctl + 32) + v65),
                              0x20u,
                              "%dx%d %d %d\n",
                              *((unsigned __int16 *)v34 - 30),
                              *((unsigned __int16 *)v34 - 25),
                              v46,
                              *((_DWORD *)v34 + 13));
  }
  else
  {
    v53 = get_ipc_log_context();
    StatusReg = v64;
    ipc_log_string(v53, "[i][%-4d]: hdisplay or vdisplay = 0\n", *(_DWORD *)(v64 + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_273099, *(unsigned int *)(v64 + 1800));
    else
      printk(&unk_22A443, "nubia_edid_modes");
  }
  v54 = get_ipc_log_context();
  ipc_log_string(
    v54,
    "[i][%-4d]: %dx%d %d %d\n",
    *(_DWORD *)(StatusReg + 1800),
    *((unsigned __int16 *)v34 - 30),
    *((unsigned __int16 *)v34 - 25),
    v46,
    *((_DWORD *)v34 + 13));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_25A262, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_211ACE, "nubia_edid_modes");
  if ( v65 <= 0x1000u )
  {
    if ( (v63 & 1) == 0 )
    {
      if ( edid_ctl && !strncmp("GM002J", (const char *)edid_ctl, 6u) )
      {
        v55 = get_ipc_log_context();
        ipc_log_string(v55, "[d][%-4d]: it's 32:9 monitor, prefer to 32:9 rate\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]: it's 32:9 monitor, prefer to 32:9 rate\n",
            *(_DWORD *)(StatusReg + 1800));
        get_higher_refresh_resolution(*((unsigned __int16 *)v34 - 30));
      }
      get_higher_refresh_resolution(*((unsigned __int16 *)v34 - 30));
    }
    v35 = v66 + 1;
    goto LABEL_115;
  }
  v57 = get_ipc_log_context();
  ipc_log_string(v57, "[e][%-4d]: edid_ctl->edid_modes overflow\n", *(_DWORD *)(StatusReg + 1800));
  v5 = &unk_22A47C;
LABEL_11:
  result = printk(v5, "nubia_edid_modes");
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
