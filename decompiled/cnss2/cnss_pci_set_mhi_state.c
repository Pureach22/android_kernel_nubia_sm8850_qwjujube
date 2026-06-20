__int64 __fastcall cnss_pci_set_mhi_state(__int64 a1, int a2)
{
  unsigned int v2; // w21
  unsigned __int64 v5; // x25
  const char *v6; // x1
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  unsigned int i; // w23
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x7
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  const char *v16; // x6
  const char *v17; // x1
  const char *v18; // x6
  __int64 v19; // x7
  const char *v20; // x1
  const char *v21; // x1
  const char *v22; // x6
  unsigned int v24; // w0
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x0
  unsigned int v28; // w0
  __int64 v29; // x7
  const char *v30; // x1
  const char *v31; // x1
  __int64 v32; // x0
  unsigned int v33; // w0
  char v34; // [xsp+0h] [xbp-10h]
  char v35; // [xsp+0h] [xbp-10h]
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+0h] [xbp-10h]
  char v38; // [xsp+0h] [xbp-10h]

  if ( *(_DWORD *)(a1 + 24) != 62 )
  {
    if ( a2 > 5 )
    {
      if ( a2 > 7 )
      {
        if ( a2 != 8 )
        {
          if ( a2 == 10 )
            goto LABEL_27;
LABEL_40:
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v8 = "irq";
          }
          else
          {
            v14 = *(_DWORD *)(StatusReg + 16);
            v15 = (const char *)(StatusReg + 2320);
            if ( (v14 & 0xFF00) != 0 )
              v8 = "soft_irq";
            else
              v8 = v15;
          }
          if ( (unsigned int)(a2 - 3) > 7 )
            v16 = "UNKNOWN";
          else
            v16 = off_5BA38[a2 - 3];
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v8,
            "cnss_pci_check_mhi_state_bit",
            3u,
            3u,
            "Unhandled MHI state: %s(%d)\n",
            (__int64)v16,
            (unsigned int)a2,
            v34);
          goto LABEL_63;
        }
        if ( (*(_QWORD *)(a1 + 352) & 4) != 0 && (*(_QWORD *)(a1 + 352) & 0x100) == 0 )
          goto LABEL_27;
LABEL_63:
        v5 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
          if ( a2 <= 4 )
          {
LABEL_65:
            if ( a2 > 1 )
            {
              if ( a2 == 2 )
              {
                v18 = "POWER_ON";
              }
              else if ( a2 == 3 )
              {
                v18 = "POWERING_OFF";
              }
              else
              {
                v18 = "POWER_OFF";
              }
              goto LABEL_90;
            }
            if ( !a2 )
            {
              v18 = "INIT";
              goto LABEL_90;
            }
            if ( a2 == 1 )
            {
              v18 = "DEINIT";
              goto LABEL_90;
            }
            goto LABEL_89;
          }
        }
        else
        {
          if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
            v17 = "soft_irq";
          else
            v17 = (const char *)(v5 + 2320);
          if ( a2 <= 4 )
            goto LABEL_65;
        }
        if ( a2 <= 6 )
        {
          if ( a2 == 5 )
            v18 = "FORCE_POWER_OFF";
          else
            v18 = "SUSPEND";
LABEL_90:
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v17,
            "cnss_pci_check_mhi_state_bit",
            3u,
            3u,
            "Cannot set MHI state %s(%d) in current MHI state (0x%lx)\n",
            (__int64)v18,
            (unsigned int)a2,
            *(_QWORD *)(a1 + 352));
          if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
          {
            v20 = "irq";
          }
          else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
          {
            v20 = "soft_irq";
          }
          else
          {
            v20 = (const char *)(v5 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v20,
            "cnss_pci_check_mhi_state_bit",
            3u,
            3u,
            "ASSERT at line %d\n",
            2468,
            v19,
            v36);
          __break(0x800u);
          goto LABEL_96;
        }
        switch ( a2 )
        {
          case 7:
            v18 = "RESUME";
            goto LABEL_90;
          case 8:
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v17,
              "cnss_pci_check_mhi_state_bit",
              3u,
              3u,
              "Cannot set MHI state %s(%d) in current MHI state (0x%lx)\n",
              (__int64)"TRIGGER_RDDM",
              8,
              *(_QWORD *)(a1 + 352));
LABEL_96:
            v2 = -22;
            goto LABEL_97;
          case 10:
            v18 = "RDDM_DONE";
            goto LABEL_90;
        }
LABEL_89:
        v18 = "UNKNOWN";
        goto LABEL_90;
      }
      if ( a2 != 6 )
      {
        if ( (*(_QWORD *)(a1 + 352) & 0x40) == 0 )
          goto LABEL_63;
        goto LABEL_27;
      }
    }
    else
    {
      if ( a2 <= 3 )
      {
        if ( (unsigned int)(a2 - 1) < 2 )
        {
          if ( (*(_QWORD *)(a1 + 352) & 1) == 0 || (*(_QWORD *)(a1 + 352) & 4) != 0 )
            goto LABEL_63;
LABEL_27:
          v5 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
          {
            v6 = "irq";
            if ( a2 <= 4 )
            {
LABEL_29:
              if ( a2 > 1 )
              {
                if ( a2 != 2 )
                {
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_long_context,
                    v6,
                    "cnss_pci_set_mhi_state",
                    7u,
                    7u,
                    "Setting MHI state: %s(%d)\n",
                    (__int64)"POWER_OFF",
                    4,
                    v34);
                  mhi_power_down(*(_QWORD *)(a1 + 344), 1);
LABEL_132:
                  cnss_pci_set_mhi_state_bit(a1, (unsigned int)a2);
                  return 0;
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_long_context,
                  v6,
                  "cnss_pci_set_mhi_state",
                  7u,
                  7u,
                  "Setting MHI state: %s(%d)\n",
                  (__int64)"POWER_ON",
                  2,
                  v34);
                v24 = mhi_sync_power_up(*(_QWORD *)(a1 + 344));
                if ( !v24 )
                {
                  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 344) + 612LL) & 1) == 0 )
                  {
                    if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
                    {
                      v31 = "irq";
                    }
                    else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
                    {
                      v31 = "soft_irq";
                    }
                    else
                    {
                      v31 = (const char *)(v5 + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v31,
                      "cnss_pci_set_mhi_state",
                      7u,
                      7u,
                      "Notify MHI to use already allocated images\n",
                      v25,
                      v26,
                      v37);
                    *(_BYTE *)(*(_QWORD *)(a1 + 344) + 612LL) = 1;
                  }
                  goto LABEL_132;
                }
                v2 = v24;
                goto LABEL_97;
              }
              if ( a2 )
              {
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_long_context,
                  v6,
                  "cnss_pci_set_mhi_state",
                  7u,
                  7u,
                  "Setting MHI state: %s(%d)\n",
                  (__int64)"DEINIT",
                  1,
                  v34);
                mhi_unprepare_after_power_down(*(_QWORD *)(a1 + 344));
                goto LABEL_132;
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_long_context,
                v6,
                "cnss_pci_set_mhi_state",
                7u,
                7u,
                "Setting MHI state: %s(%d)\n",
                (__int64)"INIT",
                0,
                v34);
              v2 = mhi_prepare_for_power_up(*(_QWORD *)(a1 + 344));
              goto LABEL_131;
            }
          }
          else
          {
            if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
              v6 = "soft_irq";
            else
              v6 = (const char *)(v5 + 2320);
            if ( a2 <= 4 )
              goto LABEL_29;
          }
          if ( a2 <= 6 )
          {
            if ( a2 == 5 )
            {
              cnss_debug_ipc_log_print(
                cnss_ipc_log_long_context,
                v6,
                "cnss_pci_set_mhi_state",
                7u,
                7u,
                "Setting MHI state: %s(%d)\n",
                (__int64)"FORCE_POWER_OFF",
                5,
                v34);
              mhi_power_down(*(_QWORD *)(a1 + 344), 0);
              goto LABEL_132;
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_long_context,
              v6,
              "cnss_pci_set_mhi_state",
              7u,
              7u,
              "Setting MHI state: %s(%d)\n",
              (__int64)"SUSPEND",
              6,
              v34);
            for ( i = 1; ; ++i )
            {
              mutex_lock(*(_QWORD *)(a1 + 344) + 272LL);
              v10 = *(_QWORD *)(a1 + 344);
              v11 = *(_BYTE *)(a1 + 232) ? mhi_pm_fast_suspend(v10, 1) : mhi_pm_suspend(v10);
              v2 = v11;
              mutex_unlock(*(_QWORD *)(a1 + 344) + 272LL);
              if ( v2 != -16 )
                break;
              if ( i == 4 )
              {
                v2 = -16;
                goto LABEL_97;
              }
              v13 = "irq";
              if ( (*(_DWORD *)(v5 + 16) & 0xF0000) == 0 )
              {
                if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
                  v13 = "soft_irq";
                else
                  v13 = (const char *)(v5 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_long_context,
                v13,
                "cnss_pci_set_mhi_state",
                7u,
                7u,
                "Retry MHI suspend #%d\n",
                i,
                v12,
                v35);
              usleep_range_state(5000, 6000, 2);
            }
          }
          else
          {
            if ( a2 != 7 )
            {
              if ( a2 != 8 )
              {
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_long_context,
                  v6,
                  "cnss_pci_set_mhi_state",
                  7u,
                  7u,
                  "Setting MHI state: %s(%d)\n",
                  (__int64)"RDDM_DONE",
                  10,
                  v34);
                goto LABEL_132;
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_long_context,
                v6,
                "cnss_pci_set_mhi_state",
                7u,
                7u,
                "Setting MHI state: %s(%d)\n",
                (__int64)"TRIGGER_RDDM",
                8,
                v34);
              cnss_rddm_trigger_debug(a1);
              v28 = mhi_force_rddm_mode(*(_QWORD *)(a1 + 344));
              if ( !v28 )
                goto LABEL_132;
              v2 = v28;
              if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
              {
                v30 = "irq";
              }
              else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
              {
                v30 = "soft_irq";
              }
              else
              {
                v30 = (const char *)(v5 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v30,
                "cnss_pci_set_mhi_state",
                3u,
                3u,
                "Failed to trigger RDDM, err = %d\n",
                v28,
                v29,
                v38);
              cnss_rddm_trigger_check(a1);
LABEL_97:
              if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
              {
                v21 = "irq";
                if ( (unsigned int)a2 <= 0xA )
                {
LABEL_99:
                  v22 = off_5BA78[a2];
LABEL_105:
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v21,
                    "cnss_pci_set_mhi_state",
                    3u,
                    3u,
                    "Failed to set MHI state: %s(%d), err = %d\n",
                    (__int64)v22,
                    (unsigned int)a2,
                    v2);
                  return v2;
                }
              }
              else
              {
                if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
                  v21 = "soft_irq";
                else
                  v21 = (const char *)(v5 + 2320);
                if ( (unsigned int)a2 <= 0xA )
                  goto LABEL_99;
              }
              v22 = "UNKNOWN";
              goto LABEL_105;
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_long_context,
              v6,
              "cnss_pci_set_mhi_state",
              7u,
              7u,
              "Setting MHI state: %s(%d)\n",
              (__int64)"RESUME",
              7,
              v34);
            mutex_lock(*(_QWORD *)(a1 + 344) + 272LL);
            if ( *(_BYTE *)(a1 + 232) )
            {
              v2 = _cnss_pci_prevent_l1(*(_QWORD *)a1 + 200LL);
              v27 = *(_QWORD *)(a1 + 344);
              if ( v2 )
              {
                mutex_unlock(v27 + 272);
                goto LABEL_97;
              }
              v2 = mhi_pm_fast_resume(v27, 1);
              _cnss_pci_allow_l1(*(_QWORD *)a1 + 200LL);
            }
            else
            {
              v32 = *(_QWORD *)(a1 + 344);
              if ( *(_DWORD *)(a1 + 24) == 4353 )
                v33 = mhi_pm_resume_force(v32);
              else
                v33 = mhi_pm_resume(v32);
              v2 = v33;
            }
            mutex_unlock(*(_QWORD *)(a1 + 344) + 272LL);
          }
LABEL_131:
          if ( !v2 )
            goto LABEL_132;
          goto LABEL_97;
        }
        if ( !a2 )
        {
          if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
            goto LABEL_63;
          goto LABEL_27;
        }
        goto LABEL_40;
      }
      if ( a2 != 4 )
      {
        if ( (*(_QWORD *)(a1 + 352) & 4) == 0 )
          goto LABEL_63;
        goto LABEL_27;
      }
    }
    if ( (*(_QWORD *)(a1 + 352) & 4) != 0 && (*(_QWORD *)(a1 + 352) & 0x40) == 0 )
      goto LABEL_27;
    goto LABEL_63;
  }
  return 0;
}
