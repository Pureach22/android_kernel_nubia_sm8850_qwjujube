__int64 __fastcall msm_cvp_unmap_ipcc_regs(unsigned int a1)
{
  __int64 v1; // x8
  __int64 *v2; // x8
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 *v8; // x22
  __int64 *v9; // x23
  int v10; // w8
  unsigned __int64 v11; // x8
  unsigned __int64 StatusReg; // x8

  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(__int64 **)(v1 + 256);
  if ( !v2 )
    return 4294967274LL;
  v3 = *v2;
  if ( !v3 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a1 )
  {
    v6 = *(_QWORD *)(v3 + 2208);
    v7 = *(unsigned int *)(v6 + 36);
    if ( (_DWORD)v7 )
    {
      v8 = *(__int64 **)(v6 + 336);
      v9 = (__int64 *)(v6 + 336);
      if ( v8 != (__int64 *)(v6 + 336) )
      {
        while ( (*((_BYTE *)v8 + 28) & 1) != 0 || strcmp("cvp_hlos", (const char *)v8[2]) )
        {
          v8 = (__int64 *)*v8;
          if ( v8 == v9 )
            goto LABEL_15;
        }
        if ( v8 )
        {
          dma_unmap_resource(v8[5], a1, v7, 0, 0);
          return 0;
        }
      }
LABEL_15:
      v10 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_94F70, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        v10 = msm_cvp_debug_out;
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) == 0 )
          return result;
      }
      else
      {
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) == 0 )
          return result;
      }
      if ( !v10 )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_8B2C0, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
    }
  }
  return result;
}
