__int64 __fastcall msm_cvp_map_ipcc_regs(_DWORD *a1)
{
  __int64 v1; // x8
  __int64 *v2; // x8
  __int64 v3; // x23
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 result; // x0
  __int64 *v9; // x24
  __int64 *v10; // x25
  int v12; // w8
  int v13; // w8
  unsigned __int64 v14; // x8
  unsigned __int64 StatusReg; // x8

  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(__int64 **)(v1 + 256);
  if ( !v2 )
    return 4294967274LL;
  v3 = *v2;
  if ( !*v2 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v3 + 2208);
  v5 = *(_QWORD *)(v4 + 16);
  v6 = *(unsigned int *)(v4 + 36);
  if ( !v5 || (_DWORD)v6 == 0 )
    return 4294967274LL;
  v9 = *(__int64 **)(v4 + 336);
  v10 = (__int64 *)(v4 + 336);
  if ( v9 != (__int64 *)(v4 + 336) )
  {
    while ( (*((_BYTE *)v9 + 28) & 1) != 0 || strcmp("cvp_hlos", (const char *)v9[2]) )
    {
      v9 = (__int64 *)*v9;
      if ( v9 == v10 )
        goto LABEL_18;
    }
    if ( v9 )
    {
      v12 = dma_map_resource(v9[5], v5, v6, 0, 0);
      *a1 = v12;
      *(_DWORD *)(*(_QWORD *)(v3 + 2208) + 44LL) = v12;
      return 0;
    }
  }
LABEL_18:
  v13 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_94F70, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    v13 = msm_cvp_debug_out;
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
  if ( !v13 )
  {
    v14 = _ReadStatusReg(SP_EL0);
    printk(&unk_8B2C0, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
