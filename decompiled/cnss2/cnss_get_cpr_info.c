__int64 __fastcall cnss_get_cpr_info(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int string; // w0
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned __int64 StatusReg; // x9
  unsigned int v15; // w19
  const char *v16; // x1
  unsigned __int64 v17; // x8
  const char *v18; // x1
  unsigned int v19; // w0
  __int64 v20; // x7
  unsigned __int64 v21; // x9
  unsigned int v22; // w19
  const char *v23; // x1
  __int16 v24; // w8
  const char *v25; // x9
  __int64 result; // x0
  __int16 v27; // w9
  const char *v28; // x8
  unsigned int addr; // w0
  __int64 v30; // x7
  unsigned __int64 v31; // x8
  const char *v32; // x1
  __int16 v33; // w8
  const char *v34; // x9
  unsigned __int64 v35; // x8
  const char *v36; // x1
  __int16 v37; // w9
  const char *v38; // x8
  __int16 v39; // w9
  const char *v40; // x8
  __int64 v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1[937];
  v9 = *a1;
  v41[0] = 0;
  if ( v8 )
  {
    string = of_property_read_string(*(_QWORD *)(v9 + 760), "qcom,cmd_db_name", v41);
    if ( string )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v15 = string;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v16 = "irq";
      }
      else
      {
        v24 = *(_DWORD *)(StatusReg + 16);
        v25 = (const char *)(StatusReg + 2320);
        if ( (v24 & 0xFF00) != 0 )
          v16 = "soft_irq";
        else
          v16 = v25;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v16,
        "cnss_get_cpr_info",
        7u,
        7u,
        "CommandDB name is not present for CPR\n",
        v12,
        v13,
        v41[0]);
      result = v15;
    }
    else
    {
      v19 = cmd_db_ready();
      if ( v19 )
      {
        v21 = _ReadStatusReg(SP_EL0);
        v22 = v19;
        if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
        {
          v23 = "irq";
        }
        else
        {
          v33 = *(_DWORD *)(v21 + 16);
          v34 = (const char *)(v21 + 2320);
          if ( (v33 & 0xFF00) != 0 )
            v23 = "soft_irq";
          else
            v23 = v34;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v23,
          "cnss_get_cpr_info",
          3u,
          3u,
          "CommandDB is not ready, err = %d\n",
          v19,
          v20,
          v41[0]);
        result = v22;
      }
      else
      {
        addr = cmd_db_read_addr(v41[0]);
        if ( addr )
        {
          *((_DWORD *)a1 + 1684) = addr;
          v31 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v31 + 16) & 0xF0000) != 0 )
          {
            v32 = "irq";
          }
          else
          {
            v37 = *(_DWORD *)(v31 + 16);
            v38 = (const char *)(v31 + 2320);
            if ( (v37 & 0xFF00) != 0 )
              v32 = "soft_irq";
            else
              v32 = v38;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v32,
            "cnss_get_cpr_info",
            7u,
            7u,
            "Get CPR PMIC address 0x%x from %s\n",
            addr,
            v41[0],
            v41[0]);
          result = 0;
        }
        else
        {
          v35 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
          {
            v36 = "irq";
          }
          else
          {
            v39 = *(_DWORD *)(v35 + 16);
            v40 = (const char *)(v35 + 2320);
            if ( (v39 & 0xFF00) != 0 )
              v36 = "soft_irq";
            else
              v36 = v40;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v36,
            "cnss_get_cpr_info",
            3u,
            3u,
            "CPR PMIC address is not available for %s\n",
            v41[0],
            v30,
            v41[0]);
          result = 4294967274LL;
        }
      }
    }
  }
  else
  {
    v17 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v17 + 16);
      v28 = (const char *)(v17 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_get_cpr_info",
      7u,
      7u,
      "TCS CMD not configured\n",
      a7,
      a8,
      v41[0]);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
