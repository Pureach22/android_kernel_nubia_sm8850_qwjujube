__int64 __fastcall cnss_pci_misc_reg_dump(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x24
  __int64 v9; // x21
  __int64 *v10; // x19
  unsigned int v13; // w23
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x7
  const char *v22; // x1
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  unsigned __int64 v30; // x27
  unsigned __int64 v31; // x28
  __int64 v32; // x1
  __int64 v33; // x2
  bool v34; // cf
  const char *v35; // x1
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+0h] [xbp-10h]
  int v38; // [xsp+4h] [xbp-Ch]

  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = *(_QWORD *)(result + 8);
    v10 = (__int64 *)result;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) == 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      v13 = a3;
      result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
      if ( !(_DWORD)result )
      {
        result = cnss_pci_force_wake_get(v10, v14, v15, v16, v17, v18, v19, v20);
        if ( !(_DWORD)result || (*(_QWORD *)(v9 + 552) & 0x800) != 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v22 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v22 = "soft_irq";
          }
          else
          {
            v22 = (const char *)(StatusReg + 2320);
          }
          result = cnss_debug_ipc_log_print(
                     cnss_ipc_log_context,
                     v22,
                     "cnss_pci_misc_reg_dump",
                     7u,
                     7u,
                     "Start to dump %s registers\n",
                     a4,
                     v21,
                     v36);
          if ( v13 )
          {
            v30 = 0;
            while ( 1 )
            {
              if ( ((*(_QWORD *)(a2 + 24 * v30 + (((unsigned __int64)v10[86] >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v10[86])
                  & 1) == 0 )
                goto LABEL_15;
              v31 = a2 + 24 * v30;
              v32 = *(unsigned int *)(v31 + 12);
              if ( *(_BYTE *)(v31 + 8) )
              {
                if ( v30 && (_DWORD)v32 == 14352392 )
                {
                  v33 = *(_DWORD *)(v31 - 8) | 0x20u;
                  *(_DWORD *)(v31 + 16) = v33;
                }
                else
                {
                  v33 = *(unsigned int *)(v31 + 16);
                }
                result = cnss_pci_reg_write(v10, v32, v33, v25, v26, v27, v28, v29);
                if ( (_DWORD)result )
                  break;
                v35 = "irq";
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
                {
                  if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                    v35 = "soft_irq";
                  else
                    v35 = (const char *)(StatusReg + 2320);
                }
                result = cnss_debug_ipc_log_print(
                           cnss_ipc_log_long_context,
                           v35,
                           "cnss_pci_misc_reg_dump",
                           7u,
                           7u,
                           "Write 0x%X to 0x%X\n",
                           *(unsigned int *)(v31 + 16),
                           *(unsigned int *)(v31 + 12),
                           v37);
LABEL_15:
                if ( ++v30 >= v13 )
                  break;
              }
              else
              {
                result = cnss_pci_reg_read(v10, v32, (_DWORD *)(v31 + 16), v25, v26, v27, v28, v29);
                ++v30;
                if ( (_DWORD)result )
                  v34 = 1;
                else
                  v34 = v30 >= v13;
                if ( v34 )
                  break;
              }
            }
          }
          if ( !v38 )
            return cnss_pci_force_wake_put((__int64)v10, v23, v24, v25, v26, v27, v28, v29);
        }
      }
    }
  }
  return result;
}
