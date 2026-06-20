__int64 __fastcall cnss_get_msi_address(__int64 result, _DWORD *a2, unsigned int *a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  char v5; // w9
  __int64 v8; // x23
  unsigned int *v9; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x0
  const char *v13; // x1
  __int64 v14; // x0
  unsigned __int64 v16; // x8
  __int16 v17; // w9
  const char *v18; // x8
  __int64 v19; // x6
  __int64 v20; // x7
  __int16 v21; // w9
  const char *v22; // x8
  char v23; // [xsp+0h] [xbp-10h]
  __int16 v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v3 = result - 200;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result != 200 )
  {
    v4 = *(_QWORD *)(result + 152);
    if ( v4 )
    {
      v5 = *(_BYTE *)(result + 2650);
      v24 = 0;
      if ( (v5 & 0x20) != 0 )
      {
        *a2 = *(_DWORD *)(v4 + 340);
        *a3 = 0;
        if ( !dword_5BF90++ )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v12 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v13 = "irq";
          }
          else
          {
            v17 = *(_DWORD *)(StatusReg + 16);
            v18 = (const char *)(StatusReg + 2320);
            if ( (v17 & 0xFF00) != 0 )
              v13 = "soft_irq";
            else
              v13 = v18;
          }
          v19 = (unsigned int)*a2;
          v20 = 0;
          goto LABEL_21;
        }
      }
      else
      {
        v8 = result;
        pci_read_config_word(result - 200, (unsigned int)*(unsigned __int8 *)(result - 91) + 2, &v24);
        result = pci_read_config_dword(v3, (unsigned int)*(unsigned __int8 *)(v8 - 91) + 4, a2);
        if ( (v24 & 0x80) != 0 )
        {
          v14 = v3;
          v9 = a3;
          result = pci_read_config_dword(v14, (unsigned int)*(unsigned __int8 *)(v8 - 91) + 8, a3);
        }
        else
        {
          v9 = a3;
          *a3 = 0;
        }
        if ( !dword_5BF90++ )
        {
          v16 = _ReadStatusReg(SP_EL0);
          v12 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
          {
            v13 = "irq";
          }
          else
          {
            v21 = *(_DWORD *)(v16 + 16);
            v22 = (const char *)(v16 + 2320);
            if ( (v21 & 0xFF00) != 0 )
              v13 = "soft_irq";
            else
              v13 = v22;
          }
          v19 = (unsigned int)*a2;
          v20 = *v9;
LABEL_21:
          result = cnss_debug_ipc_log_print(
                     v12,
                     v13,
                     "cnss_get_msi_address",
                     7u,
                     7u,
                     "Get MSI low addr = 0x%x, high addr = 0x%x\n",
                     v19,
                     v20,
                     v23);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
