__int64 __fastcall cam_isp_irq_injection_write(__int64 a1, unsigned __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v5; // x0
  _QWORD *v6; // x20
  __int64 *v7; // x21
  int v8; // w0
  int v9; // w22
  __int64 v10; // x0
  _QWORD *v11; // x23
  char *v12; // x0
  int v13; // w24
  __int64 v14; // x0
  char v15; // w8
  int v16; // w8
  const char *v17; // x4
  char *v18; // x0
  char *v19; // x0
  char *v20; // x0
  char *v21; // x0
  char v22; // w8
  char *stringp; // [xsp+10h] [xbp-5F0h] BYREF
  _BYTE v25[4]; // [xsp+18h] [xbp-5E8h] BYREF
  _BYTE s[1500]; // [xsp+1Ch] [xbp-5E4h] BYREF
  __int64 v27; // [xsp+5F8h] [xbp-8h]

  LODWORD(v3) = a3;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  stringp = nullptr;
  memset(s, 0, sizeof(s));
  if ( mem_trace_en == 1 )
    v5 = cam_mem_trace_alloc(1500, 0xCC0u, 0, "cam_isp_irq_injection_write", 0x4CA8u);
  else
    v5 = _kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
  v6 = (_QWORD *)v5;
  if ( !v5 )
  {
    v3 = -12;
    goto LABEL_84;
  }
  if ( irq_inject_display_buf )
    memset((void *)irq_inject_display_buf, 0, 0x1000u);
  if ( !inline_copy_from_user_4((__int64)s, a2, 0x5DCu) )
  {
    v7 = &qword_3A8698;
    stringp = s;
    if ( (byte_3A86B0 & 1) != 0 )
    {
      v7 = &qword_3A86C0;
      if ( byte_3A86D8 == 1 )
      {
        v7 = &qword_3A86E8;
        if ( byte_3A8700 == 1 )
        {
          v7 = &qword_3A8710;
          if ( byte_3A8728 == 1 )
          {
            v7 = &qword_3A8738;
            if ( byte_3A8750 == 1 )
            {
              v7 = &qword_3A8760;
              if ( byte_3A8778 == 1 )
              {
                v7 = &qword_3A8788;
                if ( byte_3A87A0 == 1 )
                {
                  v7 = &qword_3A87B0;
                  if ( byte_3A87C8 == 1 )
                  {
                    v7 = &qword_3A87D8;
                    if ( byte_3A87F0 == 1 )
                    {
                      v7 = &qword_3A8800;
                      if ( byte_3A8818 == 1 )
                      {
                        v8 = 0;
                        goto LABEL_77;
                      }
                      v9 = 9;
                    }
                    else
                    {
                      v9 = 8;
                    }
                  }
                  else
                  {
                    v9 = 7;
                  }
                }
                else
                {
                  v9 = 6;
                }
              }
              else
              {
                v9 = 5;
              }
            }
            else
            {
              v9 = 4;
            }
          }
          else
          {
            v9 = 3;
          }
        }
        else
        {
          v9 = 2;
        }
      }
      else
      {
        v9 = 1;
      }
    }
    else
    {
      v9 = 0;
    }
    if ( mem_trace_en == 1 )
      v10 = cam_mem_trace_alloc(1500, 0xCC0u, 0, "cam_isp_irq_inject_command_parser", 0x4C41u);
    else
      v10 = _kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
    v11 = (_QWORD *)v10;
    if ( !v10 )
    {
      v8 = 0;
      v7[2] = 0;
      *v7 = -1;
      v7[1] = -1;
      v22 = v25[0];
      *((_BYTE *)v7 + 24) = 0;
      v7[4] = 0;
      if ( (v22 & 1) != 0 )
        goto LABEL_77;
      v13 = -12;
      goto LABEL_76;
    }
    v12 = strsep(&stringp, ":");
    if ( v12 )
    {
      v13 = cam_isp_irq_inject_parse_common_params(v7, 0, v12, v25);
      if ( v13 )
      {
LABEL_36:
        scnprintf(v11, 1500, "Parsed Command failed rc: %d\n", v13);
        goto LABEL_42;
      }
      v18 = strsep(&stringp, ":");
      if ( v18 )
      {
        v13 = cam_isp_irq_inject_parse_common_params(v7, 1, v18, v25);
        if ( v13 )
          goto LABEL_36;
        v19 = strsep(&stringp, ":");
        if ( v19 )
        {
          v13 = cam_isp_irq_inject_parse_common_params(v7, 2, v19, v25);
          if ( v13 )
            goto LABEL_36;
          v20 = strsep(&stringp, ":");
          if ( v20 )
          {
            v13 = cam_isp_irq_inject_parse_common_params(v7, 3, v20, v25);
            if ( v13 )
              goto LABEL_36;
            v21 = strsep(&stringp, ":");
            if ( v21 )
            {
              v13 = cam_isp_irq_inject_parse_common_params(v7, 4, v21, v25);
              if ( v13 )
                goto LABEL_36;
              v13 = 5;
              v14 = irq_inject_display_buf;
              if ( !irq_inject_display_buf )
                goto LABEL_42;
LABEL_40:
              strlcat(v14, v11, 4096);
              goto LABEL_42;
            }
            v13 = 4;
          }
          else
          {
            v13 = 3;
          }
        }
        else
        {
          v13 = 2;
        }
      }
      else
      {
        v13 = 1;
      }
    }
    else
    {
      v13 = 0;
    }
    if ( (v25[0] & 1) == 0 )
    {
      scnprintf(v11, 1500, "Insufficient parameters passed for total parameters: %u\n", v13);
      v13 = -22;
      goto LABEL_42;
    }
    v14 = irq_inject_display_buf;
    if ( !irq_inject_display_buf )
    {
LABEL_42:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v11, 0);
      else
        kvfree(v11);
      v15 = v25[0];
      if ( v13 == 5 && (v25[0] & 1) == 0 )
      {
        v16 = *(_DWORD *)v7;
        *((_BYTE *)v7 + 24) = 1;
        if ( v16 )
        {
          if ( v16 == 7 )
          {
            v17 = "SFE";
          }
          else if ( v16 == 2 )
          {
            if ( dword_3A8694 == 65555 )
              v17 = "MC_TFE";
            else
              v17 = "VFE";
          }
          else
          {
            v17 = "Invalid hw_type";
          }
        }
        else
        {
          v17 = "CSID";
        }
        v8 = scnprintf(
               v6,
               1500,
               "Setting param[%d] : hw_type:%s hw_idx:%d reg_unit:%d irq_mask:%#x req_id:%lld\n",
               v9,
               v17,
               *((_DWORD *)v7 + 1),
               *((_DWORD *)v7 + 2),
               *((_DWORD *)v7 + 3),
               v7[2]);
LABEL_77:
        if ( v8 <= 1500 && irq_inject_display_buf )
          strlcat(irq_inject_display_buf, v6, 4096);
        v3 = (int)v3;
        goto LABEL_81;
      }
      v8 = 0;
      v7[2] = 0;
      *v7 = -1;
      v7[1] = -1;
      *((_BYTE *)v7 + 24) = 0;
      v7[4] = 0;
      if ( (v15 & 1) != 0 )
        goto LABEL_77;
LABEL_76:
      v8 = scnprintf(v6, 1500, "Parsed Command failed, param_index = %d\n", v13);
      goto LABEL_77;
    }
    goto LABEL_40;
  }
  v3 = -14;
LABEL_81:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return v3;
}
