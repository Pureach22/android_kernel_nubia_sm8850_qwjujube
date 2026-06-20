__int64 __fastcall _smem_alloc(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  unsigned int v6; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8
  int v10; // w8
  __int64 v11; // x9
  int v12; // w10
  __int64 v13; // x24

  if ( a2 )
  {
    v6 = a3;
    if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
    {
      v13 = a1;
      printk(&unk_86C2D, "info", a3, 1);
      a1 = v13;
      a3 = v6;
    }
    *(_DWORD *)(a2 + 112) = 1;
    if ( (unsigned int)msm_cvp_smem_alloc(a3, 1, 1, *(_QWORD *)(a1 + 2208), a2 + 24, a4) )
    {
      result = 4294967284LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_82E3F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967284LL;
      }
    }
    else
    {
      if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
        printk(&unk_92F92, &unk_84256, "__smem_alloc", *(_QWORD *)(a2 + 80));
      v10 = *(_DWORD *)(a2 + 104);
      v11 = *(_QWORD *)(a2 + 80);
      v12 = *(_DWORD *)(a2 + 88);
      *(_QWORD *)(a2 + 116) = 0;
      *(_DWORD *)(a2 + 16) = v10;
      *(_QWORD *)(a2 + 8) = v11;
      *(_DWORD *)a2 = v12;
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_920BB, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
