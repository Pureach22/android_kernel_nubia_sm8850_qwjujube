__int64 __fastcall hfi_process_event_notify(int a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  int v9; // w8
  int v10; // w0
  unsigned __int64 v11; // x8
  __int64 v12; // x23
  int v13; // w0
  int v14; // w8
  __int64 v15; // x2
  __int64 v16; // x3
  int v17; // w8
  char v18; // w9
  int v19; // w10
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8

  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
    printk(&unk_92295, "hfi", a3, a4);
  if ( *a2 <= 0x17u )
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_920BB, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
    return result;
  }
  v9 = a2[3];
  if ( v9 == 2 )
  {
    v12 = (unsigned int)a2[2];
    v13 = hfi_map_err_status((unsigned int)a2[4]);
    v14 = a2[5];
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)(a3 + 12) = 0;
    *(_DWORD *)(a3 + 24) = v13;
    *(_DWORD *)(a3 + 28) = v14;
    *(_QWORD *)(a3 + 16) = v12;
    memset((void *)(a3 + 32), 0, 0x2E0u);
    v17 = msm_cvp_debug_out;
    v18 = msm_cvp_debug;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_9505F, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), "warn");
      v18 = msm_cvp_debug;
      v17 = msm_cvp_debug_out;
    }
    if ( a2[4] >> 1 == 2057 )
    {
      v19 = 0x10000000;
      if ( (v18 & 4) != 0 && !v17 )
      {
        printk(&unk_8DD29, "info", v15, v16);
        v19 = 0x10000000;
      }
    }
    else
    {
      v19 = 29;
      if ( (v18 & 1) != 0 && !v17 )
      {
        v22 = _ReadStatusReg(SP_EL0);
        printk(&unk_82666, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
        v19 = 29;
      }
    }
    *(_DWORD *)a3 = v19;
    return 0;
  }
  else
  {
    if ( v9 != 1 )
    {
      *(_DWORD *)a3 = 0x10000000;
      memset((void *)(a3 + 4), 0, 0x2FCu);
      return 0;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_96F99, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
    }
    v10 = hfi_map_err_status((unsigned int)a2[4]);
    *(_DWORD *)(a3 + 20) = 0;
    *(_DWORD *)(a3 + 24) = v10;
    *(_DWORD *)(a3 + 8) = a1;
    *(_DWORD *)a3 = 9;
    *(_QWORD *)(a3 + 12) = 0;
    memset((void *)(a3 + 28), 0, 0x2E4u);
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_82633, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      return 0;
    }
  }
  return result;
}
