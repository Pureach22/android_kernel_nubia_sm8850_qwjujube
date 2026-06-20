__int64 __fastcall cnss_enable_int_pow_amp_vreg(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  const char *v11; // x1
  __int64 result; // x0
  unsigned __int64 v13; // x22
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int *v20; // x20
  unsigned int v21; // w19
  __int64 v22; // x7
  const char *v23; // x1
  __int64 v24; // x0
  const char *v25; // x1
  const char *v26; // x5
  unsigned int v27; // w3
  unsigned int v28; // w4
  char v29; // [xsp+0h] [xbp-10h]
  char v30; // [xsp+0h] [xbp-10h]
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1[66] != 4355 )
    goto LABEL_40;
  v8 = *a1;
  v31 = 0;
  if ( cnss_enable_int_pow_amp_vreg_config_done == 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_enable_int_pow_amp_vreg",
      7u,
      7u,
      "IPA Vreg already configured\n",
      a7,
      a8,
      v29);
    result = 0;
    goto LABEL_41;
  }
  v11 = (const char *)a1[958];
  if ( !v11 || !a1[955] && !a1[956] )
  {
    v13 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v13 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_enable_int_pow_amp_vreg",
      7u,
      7u,
      "AOP interface / IPA Vreg not configured\n",
      a7,
      a8,
      v29);
    if ( a1[938] )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(v8 + 760), "qcom,tcs_offset_int_pow_amp_vreg", &v31, 1, 0)
          & 0x80000000) == 0 )
      {
        v20 = (unsigned int *)(a1[938] + v31);
        v21 = readl_relaxed_0(v20);
        writel_relaxed_0(1u, v20 + 1);
        v22 = (unsigned int)readl_relaxed_0(v20 + 1);
        if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
        {
          v23 = "irq";
        }
        else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
        {
          v23 = "soft_irq";
        }
        else
        {
          v23 = (const char *)(v13 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v23,
          "cnss_enable_int_pow_amp_vreg",
          7u,
          7u,
          "Setup S3E TCS Addr: %x Data: %d\n",
          v21,
          v22,
          v30);
        result = 0;
        cnss_enable_int_pow_amp_vreg_config_done = 1;
        goto LABEL_41;
      }
      v24 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
      {
        v25 = "soft_irq";
      }
      else
      {
        v25 = (const char *)(v13 + 2320);
      }
      v26 = "Internal Power Amp Vreg not configured\n";
      v27 = 7;
      v28 = 7;
    }
    else
    {
      v24 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else if ( (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
      {
        v25 = "soft_irq";
      }
      else
      {
        v25 = (const char *)(v13 + 2320);
      }
      v26 = "TCS CMD not configured for IPA Vreg enable\n";
      v27 = 3;
      v28 = 3;
    }
    cnss_debug_ipc_log_print(v24, v25, "cnss_enable_int_pow_amp_vreg", v27, v28, v26, v18, v19, v30);
LABEL_40:
    result = 4294967274LL;
    goto LABEL_41;
  }
  result = cnss_aop_set_vreg_param((__int64)a1, v11, 2u, 0, 1);
  if ( !(_DWORD)result )
    cnss_enable_int_pow_amp_vreg_config_done = 1;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
