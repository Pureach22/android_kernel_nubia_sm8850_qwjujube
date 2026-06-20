__int64 __fastcall msm_cvp_mmrm_register(__int64 a1)
{
  __int64 v1; // x9
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  unsigned __int64 v6; // x8
  char v7; // w0
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x3
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 2208);
    *(_QWORD *)(a1 + 2400) = 0;
    *(_DWORD *)(a1 + 2216) = 0;
    *(_DWORD *)(a1 + 2376) = 2;
    *(_QWORD *)(a1 + 2384) = a1;
    *(_QWORD *)(a1 + 2392) = msm_cvp_mmrm_notifier_cb;
    *(_DWORD *)(a1 + 2224) = 2;
    v3 = *(_QWORD *)(v1 + 280);
    if ( v3 < v3 + 32LL * *(unsigned int *)(v1 + 288) )
    {
      do
      {
        if ( *(_BYTE *)(v3 + 28) == 1 )
        {
          *(_QWORD *)(a1 + 2360) = *(_QWORD *)(v3 + 16);
          *(_DWORD *)(a1 + 2228) = *(_DWORD *)(v3 + 8);
          sized_strscpy(a1 + 2232, *(_QWORD *)v3);
        }
        v3 += 32LL;
      }
      while ( v3 < *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 280LL)
                 + 32 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 288LL) );
      v4 = *(unsigned int *)(a1 + 2216);
    }
    else
    {
      v4 = 0;
    }
    v7 = mmrm_client_check_scaling_supported(v4);
    v8 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 2);
    if ( (v7 & 1) == 0 )
    {
      if ( v8 )
        printk(&unk_94677, &unk_8DA84, "msm_cvp_mmrm_register", 0);
      return 0;
    }
    if ( v8 )
      printk(&unk_8A181, &unk_8DA84, "msm_cvp_mmrm_register", a1 + 2232);
    v9 = mmrm_client_register(a1 + 2216);
    *(_QWORD *)(a1 + 2400) = v9;
    if ( v9 )
    {
      v10 = v9;
      result = 0;
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_863E0, &unk_8DA84, "msm_cvp_mmrm_register", v10);
        return 0;
      }
    }
    else
    {
      result = 4294967294LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_84691, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967294LL;
      }
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_861CC, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
