__int64 __fastcall hfi_process_sys_property_info(__int64 a1, _DWORD *a2, _DWORD *a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x1
  __int64 v8; // x2
  void *v9; // x0
  const char *v10; // x3
  int v11; // w9
  _DWORD *v12; // x1
  int v13; // t1
  __int64 v14; // x8
  __int64 v15; // x19
  int v16; // w10
  __int64 v17; // x11
  _DWORD *v18; // x21
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  _DWORD *v22; // x19

  if ( !a2 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = *(unsigned int *)(StatusReg + 1800);
    v8 = *(unsigned int *)(StatusReg + 1804);
    v9 = &unk_87782;
    v10 = (const char *)&unk_8E7CE;
LABEL_24:
    printk(v9, v7, v8, v10);
    return 4294967274LL;
  }
  if ( *a2 >= 0x20Du )
  {
    result = 4294967289LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = _ReadStatusReg(SP_EL0);
      printk(&unk_8DD5D, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
      return 4294967289LL;
    }
    return result;
  }
  v11 = a2[2];
  if ( !v11 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    v19 = _ReadStatusReg(SP_EL0);
    v7 = *(unsigned int *)(v19 + 1800);
    v8 = *(unsigned int *)(v19 + 1804);
    v9 = &unk_914DB;
    v10 = "warn";
    goto LABEL_24;
  }
  if ( a2[3] == 11 )
  {
    if ( v11 == 1 && (v13 = a2[4], v12 = a2 + 4, v13) )
    {
      v14 = 0;
      v15 = *(_QWORD *)(cvp_driver + 48);
      do
      {
        v16 = *((unsigned __int8 *)v12 + v14);
        v17 = cvp_driver + v14++;
        if ( !v16 )
          LOBYTE(v16) = 32;
        *(_BYTE *)(v17 + 136) = v16;
      }
      while ( v14 != 128 );
      v18 = a3;
      *(_BYTE *)(cvp_driver + 263) = 0;
      if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        printk(&unk_8589E, "hfi", cvp_driver + 136, a4);
      *(_DWORD *)(v15 + 1248) = msm_cvp_set_fw_version(cvp_driver + 136);
      a3 = v18;
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      v22 = a3;
      printk(&unk_8F4C2, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
      a3 = v22;
    }
    *a3 = 0x10000000;
    memset(a3 + 1, 0, 0x2FCu);
    return 0;
  }
  else
  {
    result = 4294966772LL;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_8BDE3, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), "warn");
      return 4294966772LL;
    }
  }
  return result;
}
