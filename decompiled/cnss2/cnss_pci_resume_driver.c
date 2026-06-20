__int64 __fastcall cnss_pci_resume_driver(__int64 *a1)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  result = *a1;
  v4 = a1[5];
  if ( (*(_QWORD *)(a1[1] + 552) & 0x4000000) != 0 )
  {
    if ( v4 )
    {
      v5 = *(__int64 (__fastcall **)(_QWORD))(v4 + 72);
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != -55329153 )
          __break(0x8228u);
        result = v5(result);
        if ( (_DWORD)result )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v8 = "irq";
          }
          else
          {
            v9 = *(_DWORD *)(StatusReg + 16);
            v10 = (const char *)(StatusReg + 2320);
            if ( (v9 & 0xFF00) != 0 )
              v8 = "soft_irq";
            else
              v8 = v10;
          }
          return cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v8,
                   "cnss_pci_resume_driver",
                   3u,
                   3u,
                   "Failed to resume host driver, err = %d\n",
                   (unsigned int)result,
                   v6,
                   vars0);
        }
      }
    }
  }
  return result;
}
