__int64 __fastcall icnss_smmu_fault_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x10
  void (__fastcall *v11)(__int64, __int64 *); // x8
  __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x10
  void (__fastcall *v15)(__int64, __int64 *); // x8
  __int64 result; // x0
  _BYTE v17[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  _BYTE *v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  printk("%sicnss2: fatal: SMMU fault happened with IOVA 0x%lx\n", byte_130B32, a3);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: fatal: SMMU fault happened with IOVA 0x%lx\n",
    (const char *)&unk_12DBF3,
    a3);
  if ( a5 )
  {
    v7 = a5[229];
    if ( (v7 & 4) != 0 )
    {
      v8 = a5[2];
      v17[0] = 1;
      if ( v8 )
      {
        if ( !*(_QWORD *)(v8 + 288) )
          goto LABEL_17;
        v18 = 3;
        ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v7, 3);
        v10 = a5[1];
        v9 = a5[2];
        v19 = v17;
        v11 = *(void (__fastcall **)(__int64, __int64 *))(v9 + 288);
        if ( *((_DWORD *)v11 - 1) != -712363570 )
          __break(0x8228u);
        v11(v10 + 16, &v18);
        v8 = a5[2];
        if ( v8 )
        {
LABEL_17:
          if ( *(_QWORD *)(v8 + 288) )
          {
            v12 = a5[229];
            v18 = 1;
            ipc_log_string(icnss_ipc_log_context, "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n", v12, 1);
            v14 = a5[1];
            v13 = a5[2];
            v19 = v17;
            v15 = *(void (__fastcall **)(__int64, __int64 *))(v13 + 288);
            if ( *((_DWORD *)v15 - 1) != -712363570 )
              __break(0x8228u);
            v15(v14 + 16, &v18);
          }
        }
      }
    }
    icnss_trigger_recovery(a5[1] + 16LL);
    result = 4294967258LL;
  }
  else
  {
    printk("%sicnss2: priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: priv is NULL\n", (const char *)&unk_12DBF3);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
