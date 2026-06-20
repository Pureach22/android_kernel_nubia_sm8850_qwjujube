__int64 __fastcall cnss_power_off_device(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x24
  unsigned __int64 v10; // x26
  const char *v11; // x1
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned __int64 v16; // x8
  __int64 v17; // x20
  const char *v18; // x1
  int string_helper; // w0
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 v22; // x8
  __int64 v23; // x2
  int v24; // w0
  int v25; // w9
  const char *v26; // x1
  __int64 v27; // x0
  const char *v28; // x1
  __int16 v29; // w9
  const char *v30; // x8
  __int64 result; // x0
  const char *v32; // x5
  unsigned __int64 i; // x20
  __int64 v34; // x8
  const char *v35; // x23
  __int64 v36; // x7
  const char *v37; // x1
  const char *v38; // x1
  unsigned int v39; // w3
  unsigned int v40; // w4
  __int64 v41; // x0
  __int64 v42; // x2
  __int64 v43; // x3
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  __int64 v48; // x2
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  const char *v54; // x1
  __int64 v55; // x6
  __int64 v56; // x7
  const char *v57; // x1
  __int64 v58; // x1
  __int64 v59; // x2
  __int64 v60; // x3
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  __int64 *v65; // x20
  unsigned __int64 v66; // x8
  __int64 v67; // x7
  const char *v68; // x1
  __int64 v69; // x7
  const char *v70; // x1
  __int64 v71; // x2
  __int64 v72; // x3
  __int64 v73; // x4
  __int64 v74; // x5
  __int64 v75; // x6
  __int64 v76; // x7
  _QWORD *j; // x20
  unsigned __int64 v78; // x8
  unsigned __int64 v85; // x9
  char v86; // [xsp+0h] [xbp-50h]
  const char *v87; // [xsp+0h] [xbp-50h]
  char v88; // [xsp+0h] [xbp-50h]
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v90; // [xsp+10h] [xbp-40h]
  __int64 v91; // [xsp+18h] [xbp-38h]
  __int64 v92; // [xsp+20h] [xbp-30h]
  __int64 v93; // [xsp+28h] [xbp-28h]
  __int64 v94; // [xsp+30h] [xbp-20h]
  __int64 v95; // [xsp+38h] [xbp-18h]
  __int64 v96; // [xsp+40h] [xbp-10h]
  __int64 v97; // [xsp+48h] [xbp-8h]

  v8 = a1 + 512;
  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*((_BYTE *)a1 + 6513) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v29 = *(_DWORD *)(StatusReg + 16);
      v30 = (const char *)(StatusReg + 2320);
      if ( (v29 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v30;
    }
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v13,
               "cnss_power_off_device",
               7u,
               7u,
               "Already powered down",
               a7,
               a8,
               v86);
    goto LABEL_120;
  }
  _X8 = a1 + 69;
  __asm { PRFM            #0x11, [X8] }
  do
    v85 = __ldxr(_X8);
  while ( __stxr(v85 | 0x10000000, _X8) );
  v10 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(v10 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_power_off_device",
    7u,
    7u,
    "Device_id: 0x%lx\n",
    a1[66],
    a8,
    v86);
  v16 = a1[66] - 4359LL;
  if ( v16 <= 0xA && ((1LL << v16) & 0x481) != 0 )
  {
    v17 = *a1;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v18 = "soft_irq";
    }
    else
    {
      v18 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_aop_update_mode",
      7u,
      7u,
      "Reading PDC Mode Vote table\n",
      v14,
      v15,
      (char)v87);
    string_helper = of_property_read_string_helper(*(_QWORD *)(v17 + 760), "qcom,pdc_mode_vote_table", 0, 0, 0);
    *((_DWORD *)a1 + 1930) = string_helper;
    if ( string_helper < 1 )
    {
      v27 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
      {
        v28 = "irq";
      }
      else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
      {
        v28 = "soft_irq";
      }
      else
      {
        v28 = (const char *)(v10 + 2320);
      }
      v32 = "PDC Mode Vote Table not configured\n";
LABEL_64:
      v39 = 7;
      v40 = 7;
      goto LABEL_73;
    }
    v22 = *((unsigned int *)a1 + 1930);
    if ( (v22 & 0x80000000) != 0 )
    {
      a1[964] = 0;
    }
    else
    {
      v23 = _kmalloc_noprof(8 * v22, 3520);
      a1[964] = v23;
      if ( v23 )
      {
        v24 = of_property_read_string_helper(
                *(_QWORD *)(v17 + 760),
                "qcom,pdc_mode_vote_table",
                v23,
                *((int *)a1 + 1930),
                0);
        v25 = *(_DWORD *)(v10 + 16) & 0xF0000;
        if ( (v24 & 0x80000000) == 0 )
        {
          if ( v25 )
          {
            v26 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v26 = "soft_irq";
          }
          else
          {
            v26 = (const char *)(v10 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v26,
            "cnss_aop_update_mode",
            7u,
            7u,
            "Updating PDC mode votes \n",
            v20,
            v21,
            v88);
          if ( *((_DWORD *)a1 + 1930) )
          {
            for ( i = 0; i < *((unsigned int *)a1 + 1930); ++i )
            {
              v34 = a1[964];
              v95 = 0;
              v96 = 0;
              v93 = 0;
              v94 = 0;
              v91 = 0;
              v92 = 0;
              *(_QWORD *)s = 0;
              v90 = 0;
              v35 = *(const char **)(v34 + 8 * i);
              if ( strlen(v35) < 0x41 )
              {
                snprintf(s, 0x40u, v35);
                if ( (cnss_aop_send_msg((int)a1, s) & 0x80000000) != 0 )
                {
                  if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
                  {
                    v38 = "irq";
                  }
                  else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
                  {
                    v38 = "soft_irq";
                  }
                  else
                  {
                    v38 = (const char *)(v10 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v38,
                    "cnss_aop_update_mode",
                    3u,
                    3u,
                    "Failed to send QMP message for line %d\n",
                    (unsigned int)i,
                    v21,
                    v88);
                  break;
                }
              }
              else
              {
                v37 = "irq";
                if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
                {
                  if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
                    v37 = "soft_irq";
                  else
                    v37 = (const char *)(v10 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v37,
                  "cnss_aop_update_mode",
                  3u,
                  3u,
                  "msg too long: %s\n",
                  (__int64)v35,
                  v36,
                  v88);
              }
            }
          }
          v27 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
          {
            v28 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v28 = "soft_irq";
          }
          else
          {
            v28 = (const char *)(v10 + 2320);
          }
          v32 = "Successfully updated regulator modes\n";
          goto LABEL_64;
        }
        if ( v25 )
        {
          v28 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v28 = "soft_irq";
        }
        else
        {
          v28 = (const char *)(v10 + 2320);
        }
        v32 = "Failed to get PDC Mode Vote Table\n";
        v27 = cnss_ipc_log_context;
LABEL_72:
        v39 = 3;
        v40 = 3;
LABEL_73:
        cnss_debug_ipc_log_print(v27, v28, "cnss_aop_update_mode", v39, v40, v32, v20, v21, v88);
        v41 = a1[964];
        if ( v41 )
        {
          kfree(v41);
          a1[964] = 0;
        }
        goto LABEL_75;
      }
    }
    v27 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v28 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v28 = "soft_irq";
    }
    else
    {
      v28 = (const char *)(v10 + 2320);
    }
    v32 = "Failed to alloc PDC Mode Vote Table mem\n";
    goto LABEL_72;
  }
LABEL_75:
  cnss_bus_shutdown_cleanup((__int64)a1);
  result = cnss_disable_dev_sol_irq((__int64)a1);
  if ( (v8[473] & 1) == 0 )
  {
    if ( a1[66] == 4369 || of_find_property(*(_QWORD *)(*a1 + 760LL), "fig-direct-cx", 0) )
    {
      if ( (cnss_set_cxpc_power_off((__int64)a1, 1, v42, v43, v44, v45, v46, v47) & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v54 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v54 = "soft_irq";
        }
        else
        {
          v54 = (const char *)(v10 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v54,
          "cnss_power_off_device",
          3u,
          3u,
          "failed to set cx to CX_RET\n",
          v52,
          v53,
          (char)v87);
      }
      if ( (cnss_set_direct_cx_host_sol_value((__int64)a1, 0, v48, v49, v50, v51, v52, v53) & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v57 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v57 = "soft_irq";
        }
        else
        {
          v57 = (const char *)(v10 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v57,
          "cnss_power_off_device",
          3u,
          3u,
          "Failed to de-assert Host SOL\n",
          v55,
          v56,
          (char)v87);
      }
      usleep_range_state(1000, 2000, 2);
      if ( !(unsigned int)cnss_get_cxpc((__int64)a1, v58, v59, v60, v61, v62, v63, v64) && (a1[69] & 0x200) != 0 )
      {
        v65 = (__int64 *)a1[3];
        if ( v65 != a1 + 3 )
        {
          v87 = (const char *)(v10 + 2320);
          do
          {
            v66 = v65[2];
            if ( v66 && v66 <= 0xFFFFFFFFFFFFF000LL && !strcmp((const char *)v65[3], "vdd-wlan-cx") )
            {
              v68 = "irq";
              if ( (*(_DWORD *)(v10 + 16) & 0xF0000) == 0 )
              {
                if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
                  v68 = "soft_irq";
                else
                  v68 = v87;
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v68,
                "cnss_select_vreg_off_single",
                6u,
                6u,
                "found %s rail\n",
                (__int64)"vdd-wlan-cx",
                v67,
                (char)v87);
              cnss_vreg_off_single(v65);
            }
            v65 = (__int64 *)*v65;
          }
          while ( v65 != a1 + 3 );
        }
      }
    }
    cnss_select_pinctrl_state(a1, 0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v70 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v70 = "soft_irq";
    }
    else
    {
      v70 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v70,
      "cnss_power_off_device",
      6u,
      6u,
      "Device id: 0x%lx\n",
      a1[66],
      v69,
      (char)v87);
    if ( a1[66] == 4369 )
      usleep_range_state(1000, 2000, 2);
    for ( j = (_QWORD *)a1[6]; j != a1 + 5; j = (_QWORD *)j[1] )
    {
      v78 = j[2];
      if ( v78 )
      {
        if ( v78 <= 0xFFFFFFFFFFFFF000LL )
          cnss_clk_off_single(j);
      }
    }
    result = cnss_vreg_off_type(a1, 0, v71, v72, v73, v74, v75, v76);
  }
  *((_BYTE *)v8 + 2417) = 0;
LABEL_120:
  _ReadStatusReg(SP_EL0);
  return result;
}
