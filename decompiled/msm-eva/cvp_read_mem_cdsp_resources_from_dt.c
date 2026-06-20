__int64 __fastcall cvp_read_mem_cdsp_resources_from_dt(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v5; // x0
  __int64 result; // x0
  unsigned __int64 v7; // x8
  unsigned int v8; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  void *v12; // x0
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  _QWORD v15[11]; // [xsp+8h] [xbp-58h] BYREF

  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_21;
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = *(unsigned int *)(StatusReg + 1800);
    v11 = *(unsigned int *)(StatusReg + 1804);
    v12 = &unk_8A398;
    goto LABEL_20;
  }
  v1 = *(_QWORD *)(a1 + 112);
  v2 = a1 + 16;
  if ( v1 )
  {
    v3 = *(_QWORD *)(v1 + 152);
    if ( v3 )
    {
      v5 = *(_QWORD *)(a1 + 760);
      memset(v15, 0, 80);
      if ( !(unsigned int)_of_parse_phandle_with_args(v5, "memory-region", 0, 0, 0, v15)
        && v15[0]
        && (result = of_reserved_mem_device_init_by_idx(v2, *(_QWORD *)(a1 + 760), 0), (_DWORD)result) )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v7 = _ReadStatusReg(SP_EL0);
          v8 = result;
          printk(&unk_84A68, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
          result = v8;
        }
      }
      else
      {
        result = 0;
        *(_QWORD *)(v3 + 1048) = v2;
      }
      goto LABEL_21;
    }
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_21;
    v14 = _ReadStatusReg(SP_EL0);
    v10 = *(unsigned int *)(v14 + 1800);
    v11 = *(unsigned int *)(v14 + 1804);
    v12 = &unk_8D745;
LABEL_20:
    printk(v12, v10, v11, &unk_8E7CE);
    result = 4294967274LL;
    goto LABEL_21;
  }
  result = 4294967277LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v13 = _ReadStatusReg(SP_EL0);
    printk(&unk_849F0, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
    result = 4294967277LL;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
