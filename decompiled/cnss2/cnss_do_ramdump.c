__int64 __fastcall cnss_do_ramdump(_QWORD *a1)
{
  __int64 v2; // x6
  __int64 v3; // x7
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  _QWORD *v11; // [xsp+0h] [xbp-40h] BYREF
  _QWORD *v12; // [xsp+8h] [xbp-38h]
  _QWORD v13[6]; // [xsp+10h] [xbp-30h] BYREF

  v13[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (dump_enabled() & 1) != 0 )
  {
    v11 = &v11;
    v12 = &v11;
    v5 = a1[21];
    v4 = a1[22];
    v13[1] = &v11;
    v13[2] = 0;
    v13[3] = v4;
    v13[4] = v5;
    v12 = v13;
    v13[0] = &v11;
    v11 = v13;
    result = qcom_dump(&v11, a1[20]);
  }
  else
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
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_do_ramdump",
      6u,
      6u,
      "Dump collection is not enabled\n",
      v2,
      v3,
      (char)v11);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
