__int64 __fastcall cnss_pci_time_sync_work_hdlr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 *v8; // x27
  __int64 v9; // x8
  unsigned int v10; // w20
  unsigned int *v11; // x19
  __int64 result; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  __int64 sync; // x0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x26
  __int64 v28; // x24
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  int *v36; // x23
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x3
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  __int64 v44; // x21
  unsigned int v45; // w8
  _DWORD *v46; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v48; // x0
  const char *v49; // x1
  unsigned __int64 v50; // x8
  __int16 v51; // w9
  const char *v52; // x8
  const char *v53; // x5
  __int16 v54; // w9
  const char *v55; // x8
  unsigned int v56; // w9
  __int64 v57; // x8
  __int64 v58; // x28
  unsigned int v59; // w9
  unsigned __int64 v60; // x21
  int v61; // w0
  __int64 v62; // x1
  __int64 v63; // x2
  __int64 v64; // x3
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  unsigned int v69; // w22
  __int64 v70; // x3
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  __int64 v75; // x0
  unsigned __int64 v76; // x22
  unsigned __int64 v77; // x8
  const char *v78; // x1
  __int16 v79; // w9
  const char *v80; // x8
  unsigned int v81; // w8
  __int64 v82; // x6
  __int64 v83; // x7
  unsigned __int64 v84; // x6
  unsigned __int64 v85; // x21
  unsigned __int64 v86; // x8
  const char *v87; // x1
  unsigned __int64 v88; // x28
  const char *v89; // x1
  __int16 v90; // w9
  const char *v91; // x8
  __int64 v92; // x3
  __int64 v93; // x4
  __int64 v94; // x5
  __int64 v95; // x6
  __int64 v96; // x7
  int v97; // w8
  unsigned int v98; // w22
  unsigned int v99; // w23
  unsigned int v100; // w8
  int v101; // w8
  __int64 v102; // x3
  __int64 v103; // x4
  __int64 v104; // x5
  __int64 v105; // x6
  __int64 v106; // x7
  __int64 v107; // x3
  __int64 v108; // x4
  __int64 v109; // x5
  __int64 v110; // x6
  __int64 v111; // x7
  __int64 v112; // x3
  __int64 v113; // x4
  __int64 v114; // x5
  __int64 v115; // x6
  __int64 v116; // x7
  const char *v117; // x1
  __int64 v118; // x8
  unsigned int v119; // w9
  __int64 v120; // x9
  __int64 v121; // x8
  unsigned __int64 v122; // x8
  const char *v123; // x1
  __int16 v124; // w9
  const char *v125; // x8
  __int64 v126; // x0
  __int64 v127; // x20
  __int64 v128; // x3
  __int64 v129; // x4
  __int64 v130; // x5
  __int64 v131; // x6
  __int64 v132; // x7
  char v133; // [xsp+0h] [xbp-40h]
  __int64 v134; // [xsp+18h] [xbp-28h]
  unsigned __int64 v135; // [xsp+20h] [xbp-20h]
  int v136; // [xsp+2Ch] [xbp-14h]
  _QWORD v137[2]; // [xsp+30h] [xbp-10h] BYREF

  v8 = (__int64 *)(a1 - 480);
  v137[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 - 480);
  v10 = *(_DWORD *)(v9 + 6704);
  if ( (*(_QWORD *)(v9 + 6680) & 0x1000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v48 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v49 = "irq";
    }
    else
    {
      v51 = *(_DWORD *)(StatusReg + 16);
      v52 = (const char *)(StatusReg + 2320);
      if ( (v51 & 0xFF00) != 0 )
        v49 = "soft_irq";
      else
        v49 = v52;
    }
    v53 = "Time sync is disabled\n";
    goto LABEL_22;
  }
  if ( !v10 )
  {
    v50 = _ReadStatusReg(SP_EL0);
    v48 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
    {
      v49 = "irq";
    }
    else
    {
      v54 = *(_DWORD *)(v50 + 16);
      v55 = (const char *)(v50 + 2320);
      if ( (v54 & 0xFF00) != 0 )
        v49 = "soft_irq";
      else
        v49 = v55;
    }
    v53 = "Skip time sync as time period is 0\n";
LABEL_22:
    result = cnss_debug_ipc_log_print(v48, v49, "cnss_pci_time_sync_work_hdlr", 7u, 7u, v53, a7, a8, v133);
    goto LABEL_23;
  }
  v11 = (unsigned int *)(a1 - 488);
  result = cnss_pcie_is_device_down(*(_QWORD *)(*(_QWORD *)(a1 - 488) + 352LL), a2, a3, a4, a5, a6, a7, a8);
  if ( (_DWORD)result )
    goto LABEL_23;
  sync = cnss_pci_pm_runtime_get_sync(v11, 0, v14, v15, v16, v17, v18, v19);
  if ( (sync & 0x80000000) == 0 )
  {
    mutex_lock(a1 + 112);
    v27 = *(_QWORD *)v11;
    v28 = *v8;
    if ( (unsigned int)_cnss_pci_prevent_l1(*(_QWORD *)v11 + 200LL) )
    {
LABEL_87:
      mutex_unlock(a1 + 112);
      v126 = _msecs_to_jiffies(v10);
      sync = queue_delayed_work_on(32, system_wq, a1, v126);
      goto LABEL_88;
    }
    if ( !(unsigned int)cnss_pci_force_wake_get((__int64 *)v11, v29, v30, v31, v32, v33, v34, v35) )
    {
      v36 = (int *)(a1 - 464);
      v44 = raw_spin_lock_irqsave(&time_sync_lock);
      v45 = *(_DWORD *)(a1 - 464) - 4359;
      if ( v45 < 0xC && ((0xC89u >> v45) & 1) != 0 )
      {
        v46 = (_DWORD *)((char *)&unk_5BB88 + 4 * v45);
      }
      else
      {
        cnss_pci_reg_write(v11, 33030432, 0, v39, v40, v41, v42, v43);
        v46 = (_DWORD *)(a1 - 464);
      }
      v56 = *v46 - 4359;
      if ( v56 > 0xB || (v57 = a1, ((1 << v56) & 0xC89) == 0) )
      {
        cnss_pci_reg_write(v11, 33030432, 0x80000000LL, v39, v40, v41, v42, v43);
        v57 = a1;
      }
      __isb(0xFu);
      v135 = _ReadStatusReg(CNTVCT_EL0);
      v58 = *v8;
      v136 = *(_DWORD *)(*v8 + 6484);
      if ( v136 )
      {
        v59 = *v36 - 4359;
        if ( v59 <= 0xB && ((1 << v59) & 0xC89) != 0 )
        {
          v134 = v44;
          v60 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v60 + 16) & 0xFFFF00) != 0
            || (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v61 = cnss_pci_check_link_status((__int64)v11, v37, v38, v39, v40, v41, v42, v43), v57 = a1, !v61) )
          {
            v69 = readl_relaxed((unsigned int *)(*(_QWORD *)(v57 - 168) + 2600LL));
          }
          else
          {
            v69 = 0;
          }
          if ( (*(_DWORD *)(v60 + 16) & 0xFFFF00) != 0
            || (_ReadStatusReg(DAIF) & 0x80) != 0
            || !(unsigned int)cnss_pci_check_link_status((__int64)v11, v62, v63, v64, v65, v66, v67, v68) )
          {
            v75 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 - 168) + 2604LL));
            v44 = v134;
          }
          else
          {
            v44 = v134;
            v75 = 0;
          }
        }
        else
        {
          v137[0] = 0;
          cnss_pci_reg_read(v11, 33030424, (_DWORD *)v137 + 1, v39, v40, v41, v42, v43);
          cnss_pci_reg_read(v11, 33030428, v137, v128, v129, v130, v131, v132);
          v75 = LODWORD(v137[0]);
          v69 = HIDWORD(v137[0]);
        }
        v76 = 10 * ((v69 | (unsigned __int64)(v75 << 32)) / (*(unsigned int *)(v58 + 6484) / 0x186A0uLL));
      }
      else
      {
        v77 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v77 + 16) & 0xF0000) != 0 )
        {
          v78 = "irq";
        }
        else
        {
          v79 = *(_DWORD *)(v77 + 16);
          v80 = (const char *)(v77 + 2320);
          if ( (v79 & 0xFF00) != 0 )
            v78 = "soft_irq";
          else
            v78 = v80;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v78,
          "cnss_pci_get_device_timestamp",
          3u,
          3u,
          "Device time clock frequency is not valid\n",
          v42,
          v43,
          v133);
        v76 = 0;
      }
      v81 = *v36 - 4359;
      if ( v81 > 0xB || ((1 << v81) & 0xC89) == 0 )
        cnss_pci_reg_write(v11, 33030432, 0, v70, v71, v72, v73, v74);
      raw_spin_unlock_irqrestore(&time_sync_lock, v44);
      if ( v136 )
      {
        v84 = 10 * (v135 / 0xC0);
        v85 = v84 - v76;
        if ( v84 >= v76 )
        {
          *(_QWORD *)(v28 + 7872) = v85;
          v88 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v88 + 16) & 0xF0000) != 0 )
          {
            v89 = "irq";
          }
          else if ( (*(_DWORD *)(v88 + 16) & 0xFF00) != 0 )
          {
            v89 = "soft_irq";
          }
          else
          {
            v89 = (const char *)(v88 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v89,
            "cnss_pci_update_timestamp",
            7u,
            7u,
            "Host time = %llu us, device time = %llu us, offset = %llu us\n",
            v84,
            v76,
            v84 - v76);
          v97 = *v36;
          v98 = 2440;
          v99 = 2436;
          v100 = v97 - 4359;
          v137[0] = __PAIR64__(v85, HIDWORD(v85));
          if ( v100 <= 0xB && ((1 << v100) & 0xC89) != 0 )
          {
            v101 = 4 * *(_DWORD *)(*v8 + 7764);
            v99 = v101 + 2300;
            v98 = v101 + 2304;
          }
          cnss_pci_reg_write(v11, v99, (unsigned int)v85, v92, v93, v94, v95, v96);
          cnss_pci_reg_write(v11, v98, HIDWORD(v85), v102, v103, v104, v105, v106);
          cnss_pci_reg_read(v11, v99, (_DWORD *)v137 + 1, v107, v108, v109, v110, v111);
          cnss_pci_reg_read(v11, v98, v137, v112, v113, v114, v115, v116);
          if ( (*(_DWORD *)(v88 + 16) & 0xF0000) != 0 )
          {
            v117 = "irq";
          }
          else if ( (*(_DWORD *)(v88 + 16) & 0xFF00) != 0 )
          {
            v117 = "soft_irq";
          }
          else
          {
            v117 = (const char *)(v88 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v117,
            "cnss_pci_time_sync_reg_update",
            7u,
            7u,
            "Updated time sync regs [0x%x] = 0x%x, [0x%x] = 0x%x\n",
            v99,
            HIDWORD(v137[0]),
            v98);
        }
        else
        {
          v86 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v86 + 16) & 0xF0000) != 0 )
          {
            v87 = "irq";
          }
          else
          {
            v90 = *(_DWORD *)(v86 + 16);
            v91 = (const char *)(v86 + 2320);
            if ( (v90 & 0xFF00) != 0 )
              v87 = "soft_irq";
            else
              v87 = v91;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v87,
            "cnss_pci_update_timestamp",
            3u,
            3u,
            "Host time (%llu us) is smaller than device time (%llu us), stop\n",
            v84,
            v76,
            v133);
        }
      }
      v118 = *(_QWORD *)(*(_QWORD *)v11 + 352LL);
      if ( !v118 )
      {
LABEL_80:
        v122 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v122 + 16) & 0xF0000) != 0 )
        {
          v123 = "irq";
        }
        else
        {
          v124 = *(_DWORD *)(v122 + 16);
          v125 = (const char *)(v122 + 2320);
          if ( (v124 & 0xFF00) != 0 )
            v123 = "soft_irq";
          else
            v123 = v125;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v123,
          "cnss_pci_force_wake_put",
          3u,
          3u,
          "Failed to release force wake\n",
          v82,
          v83,
          v133);
        goto LABEL_86;
      }
      v119 = *(_DWORD *)(v118 + 24) - 4353;
      if ( v119 <= 0x11 && ((1 << v119) & 0x32245) != 0 )
      {
        v120 = *(_QWORD *)(v118 + 344);
        if ( v120 )
        {
          v121 = *(_QWORD *)(v118 + 8);
          if ( v121 )
          {
            if ( (*(_QWORD *)(v121 + 552) & 0x800) == 0 )
              mhi_device_put(*(_QWORD *)(v120 + 16));
            goto LABEL_86;
          }
        }
        goto LABEL_80;
      }
    }
LABEL_86:
    _cnss_pci_allow_l1(v27 + 200);
    goto LABEL_87;
  }
LABEL_88:
  if ( v11 )
  {
    v127 = *(_QWORD *)v11;
    *(_QWORD *)(v127 + 720) = ktime_get_mono_fast_ns(sync);
  }
  result = cnss_pci_pm_runtime_put_autosuspend(v11, 0, v21, v22, v23, v24, v25, v26);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
