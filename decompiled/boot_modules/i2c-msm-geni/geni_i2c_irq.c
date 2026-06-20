__int64 __fastcall geni_i2c_irq(__int64 a1, __int64 a2)
{
  unsigned int v3; // w23
  unsigned int v4; // w21
  unsigned int v5; // w22
  int v6; // w0
  __int64 v7; // x25
  __int64 v8; // x26
  int v9; // w24
  unsigned __int64 v10; // x20
  __int64 v11; // x26
  int v12; // w0
  int v13; // w4
  int v14; // w8
  int v15; // w25
  int v16; // w0
  int v17; // w9
  __int64 v18; // x8
  unsigned __int64 v19; // x26
  __int16 v20; // w26
  __int64 v21; // x27
  unsigned int v22; // w9
  int v23; // w25
  __int64 v24; // x8
  __int64 v25; // x10
  unsigned int v26; // w0
  int v27; // w11
  int v28; // w11
  int v29; // w9
  __int64 v30; // x0
  bool v31; // w24
  __int64 v32; // x21
  __int64 v33; // x0

  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 1552LL));
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 3136LL));
  v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 3392LL));
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 600LL));
  v7 = *(_QWORD *)(a2 + 5104);
  v8 = *(_QWORD *)(a2 + 1336);
  v9 = v6;
  if ( v7 )
  {
    if ( *(_DWORD *)(a2 + 5112) )
    {
      v10 = sched_clock();
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_irq", v10, v10 / 0x3E8);
    }
    else
    {
      v10 = 0;
    }
  }
  else
  {
    v10 = -22;
  }
  ipc_log_string(*(_QWORD *)(a2 + 5096), "%s: m_irq_status:0x%x\n", "geni_i2c_irq", v3);
  if ( *(_QWORD *)a2 )
    i2c_trace_log();
  if ( !v8 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 5096), "Spurious irq\n");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Received unexpected interrupt");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
    LODWORD(v19) = 0;
    goto LABEL_29;
  }
  if ( (v3 & 0x3438) != 0 || (v5 & 0x340) != 0 )
  {
    if ( (v3 & 0x400) == 0 )
      goto LABEL_56;
    v20 = *(_WORD *)(*(_QWORD *)(a2 + 1336) + 2LL);
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 2320LL)) )
    {
      if ( (v20 & 1) != 0 )
        goto LABEL_56;
      ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Data NACK: Device NACK before end of TX transfer");
      if ( *(_QWORD *)a2 )
        goto LABEL_54;
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Address NACK: slv unresponsive, check its power/reset-ln");
      if ( *(_QWORD *)a2 )
LABEL_54:
        i2c_trace_log();
    }
    *(_DWORD *)(a2 + 24) = -107;
LABEL_56:
    if ( (v3 & 0x1000) != 0 )
    {
      ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Bus proto err, noisy/unepxected start/stop");
      if ( *(_QWORD *)a2 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
      *(_DWORD *)(a2 + 24) = -71;
      if ( (v3 & 0x2000) == 0 )
      {
LABEL_58:
        if ( (v3 & 2) == 0 )
          goto LABEL_59;
        goto LABEL_69;
      }
    }
    else if ( (v3 & 0x2000) == 0 )
    {
      goto LABEL_58;
    }
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Bus arbitration lost, clock line undriveable");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
    *(_DWORD *)(a2 + 24) = -16;
    if ( (v3 & 2) == 0 )
    {
LABEL_59:
      if ( (v3 & 4) == 0 )
        goto LABEL_60;
      goto LABEL_72;
    }
LABEL_69:
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Cmd overrun, check GENI cmd-state machine");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
    *(_DWORD *)(a2 + 24) = -5;
    if ( (v3 & 4) == 0 )
    {
LABEL_60:
      v19 = ((unsigned __int64)v3 >> 4) & 1;
      if ( (v3 & 0x20) == 0 )
        goto LABEL_61;
      goto LABEL_75;
    }
LABEL_72:
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Illegal cmd, check GENI cmd-state machine");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
    *(_DWORD *)(a2 + 24) = -84;
    v19 = ((unsigned __int64)v3 >> 4) & 1;
    if ( (v3 & 0x20) == 0 )
    {
LABEL_61:
      if ( (v3 & 8) == 0 )
        goto LABEL_81;
LABEL_78:
      v30 = *(_QWORD *)(a2 + 5096);
      if ( *(_DWORD *)(a2 + 24) )
      {
        ipc_log_string(v30, "%s:GENI_M_CMD_FAILURE\n", "geni_i2c_irq");
        if ( *(_QWORD *)a2 )
          i2c_trace_log();
        goto LABEL_81;
      }
      ipc_log_string(v30, "%s\n", "Master command failure");
      if ( *(_QWORD *)a2 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
LABEL_29:
      *(_DWORD *)(a2 + 24) = -22;
      goto LABEL_81;
    }
LABEL_75:
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Abort after timeout successful");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    *(_DWORD *)(a2 + 24) = -110;
    if ( (v3 & 8) == 0 )
    {
LABEL_81:
      *(_BYTE *)(a2 + 9084) = 1;
      if ( v9 )
      {
        v31 = 0;
        if ( !v3 )
          goto LABEL_94;
      }
      else
      {
        writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 8) + 2060LL));
        v31 = 1;
        if ( !v3 )
          goto LABEL_94;
      }
LABEL_93:
      writel_relaxed(v3, (unsigned int *)(*(_QWORD *)(a2 + 8) + 1560LL));
      goto LABEL_94;
    }
    goto LABEL_78;
  }
  v11 = *(_QWORD *)(a2 + 1336);
  v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 2052LL));
  if ( v11 )
  {
    v13 = *(unsigned __int16 *)(v11 + 2);
    if ( (v3 & 0xC000000) != 0 && (v13 & 1) != 0 )
    {
      if ( (v12 & 0x1FFFFFF) != 0 )
      {
        v14 = (v12 & 0x1FFFFFF) - 1;
        do
        {
          v15 = v14;
          v16 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 8) + 1920LL));
          v17 = *(_DWORD *)(a2 + 5084);
          LODWORD(v18) = v17;
          if ( v17 < *(unsigned __int16 *)(v11 + 4) )
          {
            *(_BYTE *)(*(_QWORD *)(v11 + 8) + v17) = v16;
            v18 = v17 + 1LL;
            if ( v18 < *(unsigned __int16 *)(v11 + 4) )
            {
              *(_BYTE *)(*(_QWORD *)(v11 + 8) + v18) = BYTE1(v16);
              v18 = v17 + 2LL;
              if ( v18 < *(unsigned __int16 *)(v11 + 4) )
              {
                *(_BYTE *)(*(_QWORD *)(v11 + 8) + v18) = BYTE2(v16);
                v18 = v17 + 3LL;
                if ( v18 < *(unsigned __int16 *)(v11 + 4) )
                {
                  *(_BYTE *)(*(_QWORD *)(v11 + 8) + v18) = HIBYTE(v16);
                  LODWORD(v18) = v17 + 4;
                }
              }
            }
          }
          *(_DWORD *)(a2 + 5084) = v18;
          if ( (_DWORD)v18 == *(unsigned __int16 *)(v11 + 4) )
            break;
          v14 = v15 - 1;
        }
        while ( v15 );
      }
    }
    else if ( (v3 & 0x40000000) == 0 || (v13 & 1) != 0 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 5096),
        "%s: m_irq_status:0x%x cur->flags:%d\n",
        "geni_i2c_irq_handle_watermark",
        v3,
        v13);
      if ( *(_QWORD *)a2 )
        i2c_trace_log();
    }
    else if ( *(_DWORD *)(a2 + 16) )
    {
      LODWORD(v21) = *(_DWORD *)(a2 + 5080);
      v22 = *(unsigned __int16 *)(v11 + 4);
      v23 = 0;
      while ( 1 )
      {
        if ( (int)v21 >= (int)v22 )
        {
          v26 = 0;
        }
        else
        {
          v24 = (int)v21;
          v25 = *(_QWORD *)(v11 + 8);
          v21 = (int)v21 + 1LL;
          v26 = *(unsigned __int8 *)(v25 + v24);
          if ( v21 < v22 )
          {
            v27 = *(unsigned __int8 *)(v25 + v21);
            v21 = v24 + 2;
            v26 |= v27 << 8;
            if ( v24 + 2 < v22 )
            {
              v28 = *(unsigned __int8 *)(v25 + v21);
              v21 = v24 + 3;
              v26 |= v28 << 16;
              if ( v24 + 3 < v22 )
              {
                v29 = *(unsigned __int8 *)(v25 + v21);
                LODWORD(v21) = v24 + 4;
                v26 |= v29 << 24;
              }
            }
          }
        }
        writel_relaxed(v26, (unsigned int *)(*(_QWORD *)(a2 + 8) + 1792LL));
        *(_DWORD *)(a2 + 5080) = v21;
        v22 = *(unsigned __int16 *)(v11 + 4);
        if ( (_DWORD)v21 == v22 )
          break;
        if ( (unsigned int)++v23 >= *(_DWORD *)(a2 + 16) )
          goto LABEL_92;
      }
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 8) + 2060LL));
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s: Spurious irq\n", "geni_i2c_irq_handle_watermark");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    ipc_log_string(*(_QWORD *)(a2 + 5096), "%s\n", "Received unexpected interrupt");
    if ( *(_QWORD *)a2 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a2 + 4960, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 5096));
    *(_DWORD *)(a2 + 24) = -22;
  }
LABEL_92:
  LODWORD(v19) = 0;
  v31 = v9 == 0;
  if ( v3 )
    goto LABEL_93;
LABEL_94:
  if ( v31 )
  {
    if ( (v3 & 1) == 0 )
      goto LABEL_103;
LABEL_102:
    *(_BYTE *)(a2 + 9084) = 1;
    goto LABEL_103;
  }
  if ( v4 )
    writel_relaxed(v4, (unsigned int *)(*(_QWORD *)(a2 + 8) + 3140LL));
  if ( v5 )
    writel_relaxed(v5, (unsigned int *)(*(_QWORD *)(a2 + 8) + 3396LL));
  __dsb(0xEu);
  if ( ((v4 | v5) & 1) != 0 )
    goto LABEL_102;
LABEL_103:
  if ( *(_BYTE *)(a2 + 9084) != 1 )
  {
    if ( !(_DWORD)v19 )
      goto LABEL_105;
LABEL_108:
    complete(a2 + 1304);
    v32 = *(_QWORD *)(a2 + 5104);
    if ( !v32 )
      return 1;
    goto LABEL_109;
  }
  *(_BYTE *)(a2 + 9084) = 0;
  complete(a2 + 1272);
  if ( (_DWORD)v19 )
    goto LABEL_108;
LABEL_105:
  v32 = *(_QWORD *)(a2 + 5104);
  if ( !v32 )
    return 1;
LABEL_109:
  if ( v10 && *(_DWORD *)(a2 + 5112) )
  {
    v33 = sched_clock();
    ipc_log_string(v32, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_irq", v33 - v10, (v33 - v10) / 0x3E8);
  }
  return 1;
}
