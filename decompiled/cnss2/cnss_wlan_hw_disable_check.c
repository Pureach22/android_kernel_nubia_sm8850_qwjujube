__int64 __fastcall cnss_wlan_hw_disable_check(__int64 a1)
{
  char v1; // w8
  unsigned int *v3; // x0
  __int64 v4; // x7
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  __int16 v12; // w9
  const char *v13; // x8
  unsigned __int64 v14; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v28; // x9
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE *)(a1 + 7768);
  v29[0] = 0;
  if ( (v1 & 1) == 0 )
  {
    v3 = (unsigned int *)qcom_smem_get(0xFFFFFFFFLL, 651, v29);
    v5 = (__int64)v3;
    if ( v3 && (unsigned __int64)v3 < 0xFFFFFFFFFFFFF001LL )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v7 = "irq";
      }
      else
      {
        v10 = *(_DWORD *)(StatusReg + 16);
        v11 = (const char *)(StatusReg + 2320);
        if ( (v10 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v11;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v7,
        "cnss_wlan_hw_disable_check",
        7u,
        7u,
        "Secure HW state: %d\n",
        *v3,
        v4,
        v29[0]);
      if ( (*(_BYTE *)(v5 + 1) & 1) != 0 )
      {
        _X8 = (unsigned __int64 *)(a1 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 | 0x1000000, _X8) );
      }
      else
      {
        _X8 = (unsigned __int64 *)(a1 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 & 0xFFFFFFFFFEFFFFFFLL, _X8) );
      }
    }
    else
    {
      if ( v3 != (unsigned int *)-19LL && v3 != (unsigned int *)-2LL )
      {
        v8 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
        {
          v9 = "irq";
        }
        else
        {
          v12 = *(_DWORD *)(v8 + 16);
          v13 = (const char *)(v8 + 2320);
          if ( (v12 & 0xFF00) != 0 )
            v9 = "soft_irq";
          else
            v9 = v13;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v9,
          "cnss_wlan_hw_disable_check",
          3u,
          3u,
          "ASSERT at line %d\n",
          6240,
          v4,
          v29[0]);
        __break(0x800u);
      }
      v14 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
      {
        v15 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(v14 + 16);
        v17 = (const char *)(v14 + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v15 = "soft_irq";
        else
          v15 = v17;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_wlan_hw_disable_check",
        7u,
        7u,
        "Secure HW feature not enabled. ret = %d\n",
        v5,
        v4,
        v29[0]);
      *(_BYTE *)(a1 + 7768) = 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
