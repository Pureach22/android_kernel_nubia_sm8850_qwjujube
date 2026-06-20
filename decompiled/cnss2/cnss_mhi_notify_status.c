_DWORD *__fastcall cnss_mhi_notify_status(
        _DWORD *result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 *v8; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v10; // x22
  const char *v11; // x8
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int64 v14; // x7
  __int64 v15; // x22
  __int64 v16; // x1
  void (__fastcall **v17)(__int64, __int64); // x22
  __int64 v18; // t1
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  __int64 v23; // x7
  const char *v24; // x1
  char v25; // w8
  const char *v26; // x1
  __int64 v27; // x22
  char v28; // w8
  const char *v29; // x1
  __int64 v30; // x7
  __int64 v31; // x22
  __int64 v32; // t1
  const char *v33; // x1
  __int64 v34; // x7
  __int64 v35; // x22
  const char *v36; // x1
  unsigned int v37; // w20
  void (__fastcall *v38)(__int64, __int64); // x8
  __int64 v39; // x0
  __int64 (__fastcall *v40)(__int64, __int64); // x8
  __int64 v41; // x0
  unsigned __int64 v48; // x9
  unsigned __int64 v51; // x9
  unsigned __int64 v54; // x9
  char v55; // [xsp+0h] [xbp-10h]
  char v56; // [xsp+0h] [xbp-10h]
  char v57; // [xsp+0h] [xbp-10h]
  char v58; // [xsp+0h] [xbp-10h]
  char v59; // [xsp+0h] [xbp-10h]

  v8 = *(__int64 **)(*((_QWORD *)result + 1) + 152LL);
  if ( v8 )
  {
    if ( !a2 )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = v8[1];
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
      if ( a2 <= 5 )
        goto LABEL_5;
    }
    else
    {
      v11 = "soft_irq";
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
        v11 = (const char *)(StatusReg + 2320);
      if ( a2 <= 5 )
      {
LABEL_5:
        if ( a2 != 4 )
        {
          if ( a2 == 5 )
            return (_DWORD *)cnss_debug_ipc_log_print(
                               cnss_ipc_log_context,
                               v11,
                               "cnss_mhi_notify_status",
                               7u,
                               7u,
                               "MHI status cb is called with reason %s(%d)\n",
                               (__int64)"MISSION_MODE",
                               5,
                               v55);
          goto LABEL_25;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v11,
          "cnss_mhi_notify_status",
          7u,
          7u,
          "MHI status cb is called with reason %s(%d)\n",
          (__int64)"RDDM",
          4,
          v55);
        cnss_ignore_qmi_failure(1);
        _X8 = (unsigned __int64 *)(v10 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 | 0x800, _X8) );
        timer_delete((timer_t)(v10 + 6272));
        v25 = timer_delete(v8 + 50);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v26 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v26 = "soft_irq";
        }
        else
        {
          v26 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v26,
          "__cnss_del_rddm_timer",
          7u,
          7u,
          "Delete RDDM timer @%s(%d), ret %d\n",
          (__int64)"cnss_mhi_notify_status",
          7880,
          v25);
        v31 = v8[5];
        v16 = 2;
        if ( (*(_QWORD *)(v8[1] + 552) & 0x20) == 0 )
        {
          if ( v31 )
          {
            v32 = *(_QWORD *)(v31 + 104);
            v17 = (void (__fastcall **)(__int64, __int64))(v31 + 104);
            if ( v32 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v33 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v33 = "soft_irq";
              }
              else
              {
                v33 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v33,
                "cnss_pci_update_status",
                7u,
                7u,
                "Update driver status: %d\n",
                4,
                v30,
                v58);
              v37 = 2;
LABEL_61:
              v38 = *v17;
              v39 = *v8;
              if ( *((_DWORD *)*v17 - 1) != -1174368176 )
                __break(0x8228u);
              v38(v39, 4);
              v16 = v37;
              return cnss_schedule_recovery(*v8 + 200, v16);
            }
          }
        }
        return cnss_schedule_recovery(*v8 + 200, v16);
      }
    }
    if ( a2 != 6 )
    {
      if ( a2 != 7 )
      {
LABEL_25:
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v11,
          "cnss_mhi_notify_status",
          7u,
          7u,
          "MHI status cb is called with reason %s(%d)\n",
          (__int64)"UNKNOWN",
          (unsigned int)a2,
          v55);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(StatusReg + 2320);
        }
        return (_DWORD *)cnss_debug_ipc_log_print(
                           cnss_ipc_log_context,
                           v24,
                           "cnss_mhi_notify_status",
                           3u,
                           3u,
                           "Unsupported MHI status cb reason: %d\n",
                           (unsigned int)a2,
                           v23,
                           v57);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v11,
        "cnss_mhi_notify_status",
        7u,
        7u,
        "MHI status cb is called with reason %s(%d)\n",
        (__int64)"FATAL_ERROR",
        7,
        v55);
      cnss_ignore_qmi_failure(1);
      _X8 = (unsigned __int64 *)(v10 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v48 = __ldxr(_X8);
      while ( __stxr(v48 | 0x800, _X8) );
      timer_delete((timer_t)(v10 + 6272));
      v15 = v8[5];
      v16 = 5;
      if ( (*(_QWORD *)(v8[1] + 552) & 0x20) == 0 )
      {
        if ( v15 )
        {
          v18 = *(_QWORD *)(v15 + 104);
          v17 = (void (__fastcall **)(__int64, __int64))(v15 + 104);
          if ( v18 )
          {
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v19 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v19 = "soft_irq";
            }
            else
            {
              v19 = (const char *)(StatusReg + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v19,
              "cnss_pci_update_status",
              7u,
              7u,
              "Update driver status: %d\n",
              4,
              v14,
              v56);
            v37 = 5;
            goto LABEL_61;
          }
        }
      }
      return cnss_schedule_recovery(*v8 + 200, v16);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_mhi_notify_status",
      7u,
      7u,
      "MHI status cb is called with reason %s(%d)\n",
      (__int64)"SYS_ERROR",
      6,
      v55);
    v27 = v8[1];
    cnss_ignore_qmi_failure(1);
    _X8 = (unsigned __int64 *)(v27 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v54 = __ldxr(_X8);
    while ( __stxr(v54 | 0x800, _X8) );
    timer_delete((timer_t)(v27 + 6272));
    *((_DWORD *)v8 + 92) = 0;
    v28 = mod_timer(v8 + 50, jiffies + 1250LL);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v29 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v29 = "soft_irq";
    }
    else
    {
      v29 = (const char *)(StatusReg + 2320);
    }
    result = (_DWORD *)cnss_debug_ipc_log_print(
                         cnss_ipc_log_context,
                         v29,
                         "__cnss_start_rddm_timer",
                         7u,
                         7u,
                         "Start RDDM timer @%s(%d), ret %d\n",
                         (__int64)"cnss_pci_handle_mhi_sys_err",
                         7828,
                         v28);
    v35 = v8[5];
    if ( (*(_QWORD *)(v8[1] + 552) & 0x20) == 0 && v35 && *(_QWORD *)(v35 + 104) )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v36 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v36 = "soft_irq";
      }
      else
      {
        v36 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v36,
        "cnss_pci_update_status",
        7u,
        7u,
        "Update driver status: %d\n",
        4,
        v34,
        v59);
      v40 = *(__int64 (__fastcall **)(__int64, __int64))(v35 + 104);
      v41 = *v8;
      if ( *((_DWORD *)v40 - 1) != -1174368176 )
        __break(0x8228u);
      return (_DWORD *)v40(v41, 4);
    }
  }
  else
  {
    v12 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(v12 + 16);
      v21 = (const char *)(v12 + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v21;
    }
    return (_DWORD *)cnss_debug_ipc_log_print(
                       cnss_ipc_log_context,
                       v13,
                       "cnss_mhi_notify_status",
                       3u,
                       3u,
                       "pci_priv is NULL",
                       a7,
                       a8,
                       v55);
  }
  return result;
}
