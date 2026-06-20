__int64 __fastcall cnss_update_supported_link_info(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int64 v16; // x8
  __int64 v17; // x7
  unsigned __int64 StatusReg; // x8
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8

  if ( *(_DWORD *)(result + 24) == 4359 )
  {
    v9 = *(_QWORD *)result;
    if ( *(_QWORD *)result )
    {
      v10 = *(_QWORD *)(result + 8);
      while ( !*(_BYTE *)(v9 + 108) || (*(_WORD *)(v9 + 114) & 0xF0) != 0x40 )
      {
        if ( (*(_BYTE *)(v9 + 2851) & 0x80) != 0 )
          v9 = *(_QWORD *)(v9 + 3288);
        v11 = *(_QWORD *)(v9 + 16);
        if ( *(_QWORD *)(v11 + 16) )
        {
          v9 = *(_QWORD *)(v11 + 56);
          if ( v9 )
            continue;
        }
        goto LABEL_10;
      }
      v16 = *(_QWORD *)(v9 + 944);
      if ( v16 )
      {
        result = *(_QWORD *)(v16 + 112);
        if ( result )
        {
          result = of_property_read_variable_u32_array(result, "qcom,target-link-speed", v10 + 6480, 1, 0);
          if ( (result & 0x80000000) != 0 )
          {
            *(_DWORD *)(v10 + 6480) = 0;
          }
          else
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v19 = "irq";
            }
            else
            {
              v20 = *(_DWORD *)(StatusReg + 16);
              v21 = (const char *)(StatusReg + 2320);
              if ( (v20 & 0xFF00) != 0 )
                v19 = "soft_irq";
              else
                v19 = v21;
            }
            return cnss_debug_ipc_log_print(
                     cnss_ipc_log_context,
                     v19,
                     "cnss_update_supported_link_info",
                     7u,
                     7u,
                     "Supported PCIe Link Speed: %d\n",
                     *(unsigned int *)(v10 + 6480),
                     v17,
                     v8);
          }
        }
      }
    }
    else
    {
LABEL_10:
      v12 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v14 = *(_DWORD *)(v12 + 16);
        v15 = (const char *)(v12 + 2320);
        if ( (v14 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v15;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v13,
               "cnss_update_supported_link_info",
               3u,
               3u,
               "PCIe root port is null\n",
               a7,
               a8,
               v8);
    }
  }
  return result;
}
