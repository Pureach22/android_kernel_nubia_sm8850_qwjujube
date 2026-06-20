__int64 __fastcall debugfs_misr_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x19
  size_t v5; // x21
  char *v9; // x20
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x22
  int v13; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x9
  _QWORD *v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x10
  int v27; // w0
  __int64 v28; // x23
  int v29; // w0
  int v30; // w0

  v4 = *(_QWORD *)(a1 + 32);
  if ( a3 >= 0x100 )
    v5 = 256;
  else
    v5 = a3;
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = (char *)_kmalloc_noprof(v5, 3520);
  if ( (unsigned __int64)v9 < 0x11 )
    return -12;
  mutex_lock(v4 + 72);
  if ( (*(_BYTE *)(v4 + 1642) & 1) == 0 )
    goto LABEL_25;
  v10 = *(unsigned int *)(*(_QWORD *)(v4 + 168) + 1608LL);
  if ( (unsigned int)v10 < 3 )
  {
    v11 = *(void (__fastcall **)(_QWORD))(v4 + 8 * v10 + 1896);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 2041732229 )
        __break(0x8228u);
      v11(v4);
      if ( *(_DWORD *)(v4 + 1352) )
      {
        LODWORD(v12) = scnprintf(v9, v5, "DSI_%d MISR: 0x%x\n", 1, *(_DWORD *)(v4 + 1356));
        if ( (unsigned int)v12 < (unsigned int)v5 && *(_DWORD *)(v4 + 1352) >= 2u )
        {
          v12 = (unsigned int)scnprintf(
                                &v9[(unsigned int)v12],
                                v5 - (unsigned int)v12,
                                "DSI_%d MISR: 0x%x\n",
                                2,
                                *(_DWORD *)(v4 + 1360))
              + (unsigned int)v12;
          if ( (unsigned int)v12 < (unsigned int)v5 && *(_DWORD *)(v4 + 1352) >= 3u )
          {
            v12 = (unsigned int)scnprintf(&v9[v12], v5 - v12, "DSI_%d MISR: 0x%x\n", 3, *(_DWORD *)(v4 + 1364))
                + (unsigned int)v12;
            if ( (unsigned int)v12 < (unsigned int)v5 && *(_DWORD *)(v4 + 1352) >= 4u )
            {
              LODWORD(v12) = scnprintf(&v9[v12], v5 - v12, "DSI_%d MISR: 0x%x\n", 4, *(_DWORD *)(v4 + 1368)) + v12;
              if ( (unsigned int)v12 < (unsigned int)v5 && *(_DWORD *)(v4 + 1352) > 4u )
                goto LABEL_24;
            }
          }
        }
      }
      else
      {
        LODWORD(v12) = 0;
      }
    }
    else
    {
      v13 = dsi_display_clk_ctrl(*(_QWORD *)(v4 + 1320), 1, 1);
      if ( v13 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI core clocks, rc=%d\n",
          *(const char **)(v4 + 32),
          v13);
        LODWORD(v12) = 0;
        goto LABEL_44;
      }
      if ( *(_DWORD *)(v4 + 160) )
      {
        v12 = *(_QWORD *)(v4 + 168);
        v27 = dsi_ctrl_collect_misr(v12);
        LODWORD(v12) = snprintf(v9, v5, "DSI_%d MISR: 0x%x\n", *(_DWORD *)(v12 + 8), v27);
        if ( (unsigned int)v12 < (unsigned int)v5 && *(_DWORD *)(v4 + 160) > 1u )
        {
          v28 = *(_QWORD *)(v4 + 216);
          v29 = dsi_ctrl_collect_misr(v28);
          LODWORD(v12) = snprintf(
                           &v9[(unsigned int)v12],
                           v5 - (unsigned int)v12,
                           "DSI_%d MISR: 0x%x\n",
                           *(_DWORD *)(v28 + 8),
                           v29)
                       + v12;
        }
      }
      else
      {
        LODWORD(v12) = 0;
      }
      v30 = dsi_display_clk_ctrl(*(_QWORD *)(v4 + 1320), 1, 0);
      if ( v30 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI core clocks, rc=%d\n",
          *(const char **)(v4 + 32),
          v30);
        goto LABEL_44;
      }
    }
    _check_object_size(v9, v5, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v15 = a2 & ((__int64)(a2 << 8) >> 8);
    _CF = 0x8000000000LL - v5 >= v15;
    v17 = a4;
    if ( _CF )
    {
      v18 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v18);
      v5 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v17 = a4;
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v26 - 4096);
      _WriteStatusReg(TTBR1_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
    }
    if ( !v5 )
      *v17 += (unsigned int)v12;
    goto LABEL_44;
  }
LABEL_24:
  __break(0x5512u);
LABEL_25:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] op not supported due to HW unavailability\n", *(const char **)(v4 + 32));
  LODWORD(v12) = 0;
LABEL_44:
  mutex_unlock(v4 + 72);
  kfree(v9);
  return (unsigned int)v12;
}
