__int64 __fastcall boot_option_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  unsigned int v6; // w4
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( (unsigned int)kstrtouint(a3, 0, &v8) )
  {
    a4 = -22;
  }
  else
  {
    v6 = v8;
    if ( v8 > 3 )
    {
      printk(&unk_2F7B3);
    }
    else
    {
      *(_DWORD *)(v5 + 1332) = v8;
      if ( v5 )
      {
        ipc_log_string(
          *(_QWORD *)(v5 + 1704),
          "DBG1:%s: PCIe: RC%d: boot_option is now 0x%x\n",
          "boot_option_store",
          *(_DWORD *)(v5 + 1348),
          v6);
        ipc_log_string(
          *(_QWORD *)(v5 + 1696),
          "%s: PCIe: RC%d: boot_option is now 0x%x\n",
          "boot_option_store",
          *(_DWORD *)(v5 + 1348),
          *(_DWORD *)(v5 + 1332));
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
