__int64 __fastcall cnss_pci_start_mhi(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  int v10; // w9
  __int64 result; // x0
  __int64 v12; // x8
  int v13; // w21
  unsigned int v14; // w20
  __int64 v15; // x6
  __int64 v16; // x7
  unsigned __int64 StatusReg; // x21
  __int64 v18; // x20
  const char *v19; // x1
  unsigned __int64 v20; // x8
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  __int64 v24; // x6
  __int64 v25; // x7
  const char *v26; // x1
  char v27; // w8
  const char *v28; // x1
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x20
  const char *v37; // x1
  size_t v38; // x2
  __int64 v39; // x1
  __int64 v40; // x2
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // x0
  __int64 v47; // x7
  char *v48; // x1
  const char *v49; // x1
  __int64 v50; // x3
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x6
  __int64 v54; // x7
  unsigned int v55; // w23
  int v56; // w24
  unsigned int v57; // w0
  const char *v58; // x1
  unsigned __int64 v65; // x9
  char v66; // [xsp+0h] [xbp-10h]
  char v67; // [xsp+0h] [xbp-10h]
  char v68; // [xsp+0h] [xbp-10h]
  char v69; // [xsp+0h] [xbp-10h]
  char v70; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    v8 = *(_QWORD *)(a1 + 8);
    if ( (*(_QWORD *)(v8 + 6680) & 0x80) != 0 )
      return 0;
    v10 = *(_DWORD *)(v8 + 6688);
    if ( v10 )
      *(_DWORD *)(*(_QWORD *)(a1 + 344) + 328LL) = v10;
    mhi_set_m2_timeout_ms(*(_QWORD *)(a1 + 344), *(unsigned int *)(v8 + 6692));
    result = cnss_pci_set_mhi_state(a1, 0);
    if ( !(_DWORD)result )
    {
      v12 = *(_QWORD *)(a1 + 344);
      v13 = *(_DWORD *)(v12 + 328);
      *(_DWORD *)(v12 + 328) = 6 * v13;
      mod_timer(a1 + 448, jiffies + 1750LL);
      v14 = cnss_pci_set_mhi_state(a1, 2);
      timer_delete_sync(a1 + 448);
      if ( !v14 )
      {
        cnss_wlan_adsp_pc_enable(a1, 0);
        *(_DWORD *)(*(_QWORD *)(a1 + 344) + 328LL) = v13;
        return 0;
      }
      result = v14;
      *(_DWORD *)(*(_QWORD *)(a1 + 344) + 328LL) = v13;
      if ( v14 == -110 )
      {
        _X8 = (unsigned __int64 *)(a1 + 352);
        __asm { PRFM            #0x11, [X8] }
        do
          v65 = __ldxr(_X8);
        while ( __stxr(v65 | 4, _X8) );
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(a1 + 8);
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
          "cnss_pci_handle_mhi_poweron_timeout",
          3u,
          3u,
          "fatal: MHI power up returns timeout\n",
          v15,
          v16,
          v66);
        if ( (mhi_scan_rddm_cookie(*(_QWORD *)(a1 + 344), 3405695694LL) & 1) != 0
          || (int)cnss_get_dev_sol_value(v18) >= 1 )
        {
          if ( (*(_QWORD *)(v18 + 552) & 0x800) != 0 || *(_BYTE *)(a1 + 49) )
            return 0;
          v27 = mod_timer(a1 + 400, jiffies + 1250LL);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v28 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v28 = "soft_irq";
          }
          else
          {
            v28 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v28,
            "__cnss_start_rddm_timer",
            7u,
            7u,
            "Start RDDM timer @%s(%d), ret %d\n",
            (__int64)"cnss_pci_handle_mhi_poweron_timeout",
            2381,
            v27);
          return 0;
        }
        else
        {
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
            "cnss_pci_handle_mhi_poweron_timeout",
            7u,
            7u,
            "RDDM cookie is not set and device SOL is low\n",
            v24,
            v25,
            v67);
          if ( !(unsigned int)cnss_pci_check_link_status(a1, v29, v30, v31, v32, v33, v34, v35) )
            mhi_debug_reg_dump(*(_QWORD *)(a1 + 344));
          cnss_pci_bhi_debug_reg_dump(a1);
          cnss_pci_soc_scratch_reg_dump(a1);
          cnss_pci_dump_bl_sram_mem(a1);
          v36 = *(_QWORD *)(a1 + 8);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v37 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v37 = "soft_irq";
          }
          else
          {
            v37 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v37,
            "cnss_pci_dump_sram",
            7u,
            7u,
            "SRAM dump: start addr 0x%x, size 0x%x\n",
            *(unsigned int *)(v36 + 6596),
            *(unsigned int *)(v36 + 6600),
            v68);
          v38 = *(unsigned int *)(v36 + 6600);
          if ( (_DWORD)v38 )
          {
            if ( *(_QWORD *)(v36 + 6608) )
            {
              memset(*(void **)(v36 + 6608), 0, v38);
              v46 = *(_QWORD *)(v36 + 6608);
            }
            else
            {
              v46 = vzalloc_noprof(*(unsigned int *)(v36 + 6600));
              *(_QWORD *)(v36 + 6608) = v46;
            }
            if ( v46 )
            {
              if ( !(unsigned int)cnss_pci_check_link_status(a1, v39, v40, v41, v42, v43, v44, v45) )
              {
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                  v48 = "irq";
                else
                  v48 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v48,
                  "cnss_pci_dump_sram",
                  7u,
                  7u,
                  "Dumping SRAM at 0x%lx\n",
                  *(_QWORD *)(v36 + 6608),
                  v47,
                  v69);
                if ( *(_DWORD *)(v36 + 6600) )
                {
                  v55 = 0;
                  while ( 1 )
                  {
                    v56 = *(_DWORD *)(v36 + 6596);
                    v57 = cnss_pci_reg_read(
                            (_QWORD *)a1,
                            v55 + v56,
                            (_DWORD *)(*(_QWORD *)(v36 + 6608) + v55),
                            v50,
                            v51,
                            v52,
                            v53,
                            v54);
                    if ( v57 )
                      break;
                    v55 += 4;
                    result = 4294967186LL;
                    if ( v55 >= *(_DWORD *)(v36 + 6600) )
                      return result;
                  }
                  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                  {
                    v58 = "irq";
                  }
                  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                  {
                    v58 = "soft_irq";
                  }
                  else
                  {
                    v58 = (const char *)(StatusReg + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v58,
                    "cnss_pci_dump_sram",
                    3u,
                    3u,
                    "SRAM Dump failed at 0x%x, %d\n",
                    v55 + v56,
                    v57,
                    v70);
                }
              }
            }
            else
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v49 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v49 = "soft_irq";
              }
              else
              {
                v49 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v49,
                "cnss_pci_dump_sram",
                3u,
                3u,
                "SRAM dump memory is not allocated\n",
                v44,
                v45,
                v69);
            }
          }
          return 4294967186LL;
        }
      }
    }
  }
  else
  {
    v20 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(v20 + 16);
      v23 = (const char *)(v20 + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v21 = "soft_irq";
      else
        v21 = v23;
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v21, "cnss_pci_start_mhi", 3u, 3u, "pci_priv is NULL\n", a7, a8, v66);
    return 4294967277LL;
  }
  return result;
}
