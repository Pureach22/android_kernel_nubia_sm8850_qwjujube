__int64 __fastcall cnss_get_vreg_type(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x6
  const char *v10; // x1
  _QWORD *v12; // x21
  __int64 v13; // x26
  int string_helper; // w0
  unsigned __int64 v15; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  unsigned int v19; // w28
  unsigned __int64 v20; // x25
  __int64 v21; // x22
  __int64 v22; // x24
  unsigned __int64 v23; // x20
  _QWORD *v24; // x0
  _QWORD *v25; // x27
  unsigned int v26; // w0
  __int64 v27; // x6
  __int64 v28; // x7
  char *v29; // x10
  char *v30; // x8
  __int64 v31; // x23
  __int64 v32; // x8
  __int64 v33; // x1
  unsigned __int64 optional; // x0
  __int64 v35; // x7
  const char *v36; // x1
  const char *v37; // x3
  unsigned int *property; // x0
  const char *v39; // x1
  const char *v40; // x7
  const char *v41; // x1
  _QWORD *v42; // x1
  unsigned __int64 v43; // x8
  const char *v44; // x1
  __int16 v45; // w9
  const char *v46; // x8
  unsigned __int64 v48; // x8
  const char *v49; // x1
  unsigned __int64 v50; // x8
  const char *v51; // x1
  unsigned __int64 v52; // x8
  const char *v53; // x1
  __int16 v54; // w9
  const char *v55; // x8
  __int16 v56; // w9
  const char *v57; // x8
  __int16 v58; // w9
  const char *v59; // x8
  __int16 v60; // w9
  const char *v61; // x8
  char v62; // [xsp+0h] [xbp-60h]
  __int64 *v63; // [xsp+28h] [xbp-38h]
  int v64; // [xsp+34h] [xbp-2Ch] BYREF
  char s[8]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v66; // [xsp+40h] [xbp-20h]
  __int64 v67; // [xsp+48h] [xbp-18h]
  __int64 v68; // [xsp+50h] [xbp-10h]
  __int64 v69; // [xsp+58h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = a2;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "get_vreg_list",
      3u,
      3u,
      "Unsupported vreg type 0x%x\n",
      v9,
      a8,
      v62);
    v19 = -22;
    goto LABEL_69;
  }
  v12 = a1 + 3;
  v13 = *a1;
  if ( (__int64 *)a1[3] == a1 + 3 || *((_DWORD *)a1 + 1934) == 2 )
  {
    v63 = (__int64 *)a1[972];
    if ( !v63 )
      v63 = *(__int64 **)(v13 + 760);
    if ( *((_DWORD *)a1 + 1934) == 2 )
    {
      string_helper = of_property_read_string_helper(v63, "wlan_vregs", 0, 0, 0);
      if ( string_helper <= 0 )
      {
        if ( string_helper == -22 || string_helper == -61 )
        {
          v15 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v16 = "irq";
          }
          else
          {
            v56 = *(_DWORD *)(v15 + 16);
            v57 = (const char *)(v15 + 2320);
            if ( (v56 & 0xFF00) != 0 )
              v16 = "soft_irq";
            else
              v16 = v57;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v16,
            "cnss_get_vreg",
            7u,
            7u,
            "No additional vregs for: %s:%lx\n",
            *v63,
            a1[66],
            v62);
          v19 = 1;
        }
        else
        {
          v52 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v52 + 16) & 0xF0000) != 0 )
          {
            v53 = "irq";
          }
          else
          {
            v60 = *(_DWORD *)(v52 + 16);
            v61 = (const char *)(v52 + 2320);
            if ( (v60 & 0xFF00) != 0 )
              v53 = "soft_irq";
            else
              v53 = v61;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v53,
            "cnss_get_vreg",
            3u,
            3u,
            "property %s is invalid: %s:%lx\n",
            (__int64)"wlan_vregs",
            *v63,
            a1[66]);
          v19 = -22;
        }
        goto LABEL_69;
      }
    }
    else
    {
      string_helper = 21;
    }
    v20 = 0;
    v21 = 0;
    v22 = (unsigned int)string_helper;
    v23 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v24 = (_QWORD *)devm_kmalloc(v13 + 16, 64, 3520);
      if ( !v24 )
      {
        v19 = -12;
        goto LABEL_69;
      }
      v25 = v24;
      if ( *((_DWORD *)a1 + 1934) == 2 )
      {
        v26 = of_property_read_string_helper(v63, "wlan_vregs", v24 + 3, 1, (unsigned int)v21);
        if ( (v26 & 0x80000000) != 0 )
        {
          v19 = v26;
          v48 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v48 + 16) & 0xF0000) != 0 )
          {
            v49 = "irq";
          }
          else
          {
            v54 = *(_DWORD *)(v48 + 16);
            v55 = (const char *)(v48 + 2320);
            if ( (v54 & 0xFF00) != 0 )
              v49 = "soft_irq";
            else
              v49 = v55;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v49,
            "cnss_get_vreg",
            3u,
            3u,
            "Failed to read vreg ids\n",
            v27,
            v28,
            v62);
          goto LABEL_69;
        }
      }
      else
      {
        if ( v20 >= 84 )
          _fortify_panic(16, 40, 32);
        v29 = (&cnss_vreg_list)[v20 + 1];
        v24[3] = (&cnss_vreg_list)[v20];
        v24[4] = v29;
        v30 = (&cnss_vreg_list)[v20 + 3];
        v24[5] = (&cnss_vreg_list)[v20 + 2];
        v24[6] = v30;
      }
      v31 = a1[972];
      v32 = *a1;
      v67 = 0;
      v68 = 0;
      *(_QWORD *)s = 0;
      v66 = 0;
      if ( !v31 )
        v31 = *(_QWORD *)(v32 + 760);
      v33 = v25[3];
      v64 = 0;
      optional = devm_regulator_get_optional(v32 + 16, v33);
      v19 = optional;
      if ( optional < 0xFFFFFFFFFFFFF001LL )
        break;
      if ( (_DWORD)optional != -19 )
      {
        if ( (_DWORD)optional == -517 )
        {
          v50 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
          {
            v51 = "irq";
          }
          else
          {
            v58 = *(_DWORD *)(v50 + 16);
            v59 = (const char *)(v50 + 2320);
            if ( (v58 & 0xFF00) != 0 )
              v51 = "soft_irq";
            else
              v51 = v59;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v51,
            "cnss_get_vreg_single",
            6u,
            6u,
            "EPROBE_DEFER for regulator: %s\n",
            v25[3],
            v35,
            v62);
LABEL_88:
          devm_kfree(v13 + 16, v25);
          goto LABEL_69;
        }
        v36 = "irq";
        if ( (*(_DWORD *)(v23 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
            v36 = "soft_irq";
          else
            v36 = (const char *)(v23 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v36,
          "cnss_get_vreg_single",
          3u,
          3u,
          "Failed to get regulator %s, err = %d\n",
          v25[3],
          (unsigned int)optional,
          v62);
        if ( !v19 )
          goto LABEL_56;
        if ( v19 != -19 )
          goto LABEL_88;
      }
      devm_kfree(v13 + 16, v25);
LABEL_22:
      ++v21;
      v20 += 4LL;
      if ( v22 == v21 )
        goto LABEL_68;
    }
    v37 = (const char *)v25[3];
    v25[2] = optional;
    snprintf(s, 0x20u, "qcom,%s-config", v37);
    property = (unsigned int *)of_get_property(v31, s, &v64);
    if ( property && v64 == 20 )
    {
      *((_DWORD *)v25 + 8) = bswap32(*property);
      *((_DWORD *)v25 + 9) = bswap32(property[1]);
      *((_DWORD *)v25 + 10) = bswap32(property[2]);
      *((_DWORD *)v25 + 11) = bswap32(property[3]);
      *((_DWORD *)v25 + 12) = bswap32(property[4]);
    }
    else
    {
      v39 = "irq";
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
          v39 = "soft_irq";
        else
          v39 = (const char *)(v23 + 2320);
      }
      if ( property )
        v40 = "invalid format";
      else
        v40 = "doesn't exist";
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v39,
        "cnss_get_vreg_single",
        7u,
        7u,
        "Property %s %s, use default\n",
        (__int64)s,
        (__int64)v40,
        v62);
    }
    v41 = "irq";
    if ( (*(_DWORD *)(v23 + 16) & 0xF0000) == 0 )
    {
      if ( (*(_DWORD *)(v23 + 16) & 0xFF00) != 0 )
        v41 = "soft_irq";
      else
        v41 = (const char *)(v23 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v41,
      "cnss_get_vreg_single",
      7u,
      7u,
      "Got regulator: %s, min_uv: %u, max_uv: %u, load_ua: %u, delay_us: %u, need_unvote: %u\n",
      v25[3],
      *((unsigned int *)v25 + 8),
      *((_DWORD *)v25 + 9));
LABEL_56:
    v42 = (_QWORD *)a1[4];
    if ( v25 == v12 || v42 == v25 || (_QWORD *)*v42 != v12 )
    {
      _list_add_valid_or_report(v25, v42);
    }
    else
    {
      a1[4] = (__int64)v25;
      *v25 = v12;
      v25[1] = v42;
      *v42 = v25;
    }
    goto LABEL_22;
  }
  v43 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v43 + 16) & 0xF0000) != 0 )
  {
    v44 = "irq";
  }
  else
  {
    v45 = *(_DWORD *)(v43 + 16);
    v46 = (const char *)(v43 + 2320);
    if ( (v45 & 0xFF00) != 0 )
      v44 = "soft_irq";
    else
      v44 = v46;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v44,
    "cnss_get_vreg",
    7u,
    7u,
    "Vregs have already been updated\n",
    a7,
    a8,
    v62);
LABEL_68:
  v19 = 0;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v19;
}
