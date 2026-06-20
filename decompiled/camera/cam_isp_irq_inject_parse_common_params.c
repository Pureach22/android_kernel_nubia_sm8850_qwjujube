__int64 __fastcall cam_isp_irq_inject_parse_common_params(int *a1, int a2, const char *a3, _BYTE *a4)
{
  _QWORD *v8; // x19
  int v9; // w21
  unsigned int v10; // w22
  int v11; // w8
  __int64 v12; // x3
  int v13; // w8
  const char *v14; // x3
  int v15; // w0
  int v16; // w0
  const char *v17; // x2
  int v18; // w8
  int v19; // w0
  unsigned int v20; // w23
  const char *v21; // x0
  int v22; // w0
  const char *v23; // x0
  int v24; // w23
  __int64 v25; // x4
  int v26; // w0
  const char *v27; // x22
  __int64 v29; // x4
  __int64 v30; // x3
  const char *v31; // x3

  if ( mem_trace_en == 1 )
  {
    v8 = (_QWORD *)cam_mem_trace_alloc(1500, 0xCC0u, 0, "cam_isp_irq_inject_parse_common_params", 0x4B8Bu);
    if ( v8 )
      goto LABEL_3;
    return (unsigned int)-12;
  }
  v8 = (_QWORD *)_kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
  if ( !v8 )
    return (unsigned int)-12;
LABEL_3:
  if ( a2 > 1 )
  {
    if ( a2 != 2 )
    {
      if ( a2 != 3 )
      {
        if ( a2 == 4 )
        {
          if ( strnstr(a3, "now", 3) )
          {
            v9 = scnprintf(v8, 1500, "Trigger IRQ now\n");
            v10 = 0;
            *((_QWORD *)a1 + 2) = 0xFFFFFFFFLL;
            goto LABEL_87;
          }
          if ( (unsigned int)kstrtoull(a3, 0, a1 + 4) )
          {
            v15 = scnprintf(v8, 1500, "Invalid request id %s\n", a3);
            goto LABEL_40;
          }
          goto LABEL_59;
        }
        goto LABEL_39;
      }
      if ( !strnstr(a3, "?", 1) )
      {
        if ( (unsigned int)kstrtouint(a3, 0, a1 + 3) )
        {
          v15 = scnprintf(v8, 1500, "Invalid irq mask %s\n", a3);
          goto LABEL_40;
        }
        goto LABEL_59;
      }
      *a4 = 1;
      if ( *a1 != -1 && a1[2] != -1 )
      {
        if ( (unsigned int)cam_ife_hw_mgr_irq_inject_or_dump_desc(g_ife_hw_mgr, a1, 1) )
        {
          v15 = scnprintf(v8, 1500, "Dump irq description failed\n");
LABEL_40:
          v9 = v15;
          v10 = -22;
          goto LABEL_87;
        }
LABEL_59:
        v9 = 0;
LABEL_86:
        v10 = 0;
        goto LABEL_87;
      }
      v16 = scnprintf(v8, 1500, "IRQ_MASK : Enter hw_type and reg_unit first\n");
LABEL_85:
      v9 = v16;
      goto LABEL_86;
    }
    if ( !strnstr(a3, "?", 1) )
    {
      if ( (unsigned int)kstrtouint(a3, 0, a1 + 2) )
      {
        v15 = scnprintf(v8, 1500, "Invalid register %s\n", a3);
        goto LABEL_40;
      }
      goto LABEL_59;
    }
    *a4 = 1;
    v13 = *a1;
    if ( *a1 > 1 )
    {
      if ( v13 == 2 )
      {
        if ( dword_3A8694 == 65555 )
          v14 = "MC_TFE";
        else
          v14 = "VFE";
        goto LABEL_76;
      }
      if ( v13 == 7 )
      {
        v14 = "SFE";
        goto LABEL_76;
      }
    }
    else
    {
      if ( v13 == -1 )
      {
        v16 = scnprintf(v8, 1500, "REG_UNIT : Enter hw_type first\n");
        goto LABEL_85;
      }
      if ( !v13 )
      {
        v14 = "CSID";
LABEL_76:
        v19 = scnprintf(v8, 1500, "Printing available res for hw_type: %s\n", v14);
        v20 = *a1;
        v9 = v19;
        if ( *a1 == 7 )
        {
          scnprintf(reg_str, 64, "CAM_SFE_IRQ_BUS_WR_REG_STATUS%u", 0);
          v24 = scnprintf((char *)v8 + v9, 1500 - v9, "%d : %s\n", 400, reg_str) + v9;
          if ( *a1 == 7 )
          {
            v27 = reg_str;
            scnprintf(reg_str, 64, "CAM_SFE_IRQ_BUS_RD_REG_STATUS%u", 0);
          }
          else
          {
            v27 = "Invalid reg_unit";
          }
          v26 = scnprintf((char *)v8 + v24, 1500 - v24, "%d : %s\n", 500, v27);
        }
        else
        {
          if ( v20 != 2 )
          {
            if ( !v20 )
            {
              do
              {
                v21 = (const char *)_cam_isp_irq_inject_reg_unit_to_name((unsigned int)*a1, v20);
                v22 = scnprintf((char *)v8 + v9, 1500 - v9, "%d : %s\n", v20++, v21);
                v10 = 0;
                v9 += v22;
              }
              while ( v20 != 16 );
              goto LABEL_87;
            }
            goto LABEL_86;
          }
          v23 = (const char *)_cam_isp_irq_inject_reg_unit_to_name(2, 200);
          v24 = scnprintf((char *)v8 + v9, 1500 - v9, "%d : %s\n", 200, v23) + v9;
          v25 = _cam_isp_irq_inject_reg_unit_to_name((unsigned int)*a1, 201);
          v26 = scnprintf((char *)v8 + v24, 1500 - v24, "%d : %s\n", 201, v25);
        }
        v10 = 0;
        v9 = v26 + v24;
        goto LABEL_87;
      }
    }
    v14 = "Invalid hw_type";
    goto LABEL_76;
  }
  if ( a2 )
  {
    if ( a2 != 1 )
    {
LABEL_39:
      v15 = scnprintf(v8, 1500, "Invalid extra parameter: %s\n", a3);
      goto LABEL_40;
    }
    if ( !strnstr(a3, "?", 1) )
    {
      if ( (unsigned int)kstrtouint(a3, 0, a1 + 1) )
      {
        v15 = scnprintf(v8, 1500, "Invalid hw index %s\n", a3);
        goto LABEL_40;
      }
      goto LABEL_59;
    }
    *a4 = 1;
    v9 = 0;
    v11 = *a1;
    if ( *a1 <= 1 )
    {
      if ( v11 == -1 )
      {
        v16 = scnprintf(v8, 1500, "HW_IDX : Enter hw_type first\n");
        goto LABEL_85;
      }
      v10 = 0;
      if ( v11 )
        goto LABEL_87;
      if ( qword_394958 )
      {
        if ( qword_394960 )
        {
          if ( qword_394968 )
          {
            if ( qword_394970 )
            {
              if ( qword_394978 )
              {
                if ( qword_394980 )
                {
                  if ( qword_394988 )
                  {
                    if ( qword_394990 )
                      v12 = 7;
                    else
                      v12 = 6;
                  }
                  else
                  {
                    v12 = 5;
                  }
                }
                else
                {
                  v12 = 4;
                }
              }
              else
              {
                v12 = 3;
              }
            }
            else
            {
              v12 = 2;
            }
          }
          else
          {
            v12 = 1;
          }
        }
        else
        {
          v12 = 0;
        }
      }
      else
      {
        v12 = 0xFFFFFFFFLL;
      }
      v17 = "Max index of CSID : %d\n";
LABEL_127:
      v16 = scnprintf(v8, 1500, v17, v12);
      goto LABEL_85;
    }
    if ( v11 == 2 )
    {
      if ( qword_394998 )
      {
        if ( qword_3949A0 )
        {
          if ( qword_3949A8 )
          {
            if ( qword_3949B0 )
            {
              if ( qword_3949B8 )
              {
                if ( qword_3949C0 )
                {
                  if ( qword_3949C8 )
                  {
                    if ( qword_3949D0 )
                      v29 = 7;
                    else
                      v29 = 6;
                  }
                  else
                  {
                    v29 = 5;
                  }
                }
                else
                {
                  v29 = 4;
                }
              }
              else
              {
                v29 = 3;
              }
            }
            else
            {
              v29 = 2;
            }
          }
          else
          {
            v29 = 1;
          }
        }
        else
        {
          v29 = 0;
        }
      }
      else
      {
        v29 = 0xFFFFFFFFLL;
      }
      if ( dword_3A8694 == 65555 )
        v31 = "MC_TFE";
      else
        v31 = "VFE";
      v16 = scnprintf(v8, 1500, "Max index of %s : %d\n", v31, v29);
      goto LABEL_85;
    }
    v10 = 0;
    if ( v11 != 7 )
      goto LABEL_87;
    if ( qword_3949D8 )
    {
      if ( qword_3949E0 )
      {
        v17 = "Max index of SFE : %d\n";
        if ( qword_3949E8 )
          v12 = 2;
        else
          v12 = 1;
        goto LABEL_127;
      }
      v30 = 0;
    }
    else
    {
      v30 = 0xFFFFFFFFLL;
    }
    v16 = scnprintf(v8, 1500, "Max index of SFE : %d\n", v30);
    goto LABEL_85;
  }
  if ( strnstr(a3, "?", 1) )
  {
    *a4 = 1;
    v16 = scnprintf(v8, 1500, "Interruptable HW : CSID | VFE | MC_TFE | SFE\n");
    goto LABEL_85;
  }
  if ( !strcmp(a3, "CSID") || !strcmp(a3, "csid") )
  {
    v18 = 0;
  }
  else if ( !strcmp(a3, "VFE") || !strcmp(a3, "vfe") || !strcmp(a3, "MC_TFE") || !strcmp(a3, "mc_tfe") )
  {
    v18 = 2;
  }
  else
  {
    if ( strcmp(a3, "SFE") && strcmp(a3, "sfe") )
    {
      *a1 = -1;
      v15 = scnprintf(v8, 1500, "Invalid camera hardware [ %s ]\n", a3);
      goto LABEL_40;
    }
    v18 = 7;
  }
  v9 = 0;
  v10 = 0;
  *a1 = v18;
LABEL_87:
  if ( v9 <= 1500 && irq_inject_display_buf )
    strlcat(irq_inject_display_buf, v8, 4096);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  return v10;
}
