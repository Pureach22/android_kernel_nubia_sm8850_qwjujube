__int64 __fastcall print_smem_dsp(int a1, __int64 a2, unsigned int *a3, __int64 a4)
{
  int pkt_index_from_type; // w0
  __int64 v9; // x24
  size_t v10; // x0
  unsigned __int64 v11; // x2
  int v12; // w0
  _BOOL4 v14; // w8
  unsigned __int64 v15; // x8
  unsigned int v16; // w20
  unsigned int v17; // w21
  const char *v18; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v21; // x8
  unsigned int v22; // w20
  unsigned int v23; // w21
  const char *v24; // x0
  const char *debug_level_str; // x0
  const char *v26; // x0
  __int64 v27; // x0
  _QWORD v28[9]; // [xsp+38h] [xbp-48h] BYREF

  v28[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  strcpy((char *)v28, "Unknown");
  memset(&v28[1], 0, 56);
  if ( (msm_cvp_debug & a1) == 0 )
    goto LABEL_26;
  if ( !a3 || !a4 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_95145, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
    goto LABEL_27;
  }
  if ( !*(_QWORD *)(a4 + 48) )
  {
LABEL_26:
    result = 0;
LABEL_27:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  pkt_index_from_type = get_pkt_index_from_type(*(unsigned int *)(a4 + 92));
  if ( pkt_index_from_type < 1 )
  {
LABEL_12:
    v12 = a1;
    v14 = (msm_cvp_debug & a1) != 0 && msm_cvp_debug_out == 0;
    if ( *(_DWORD *)(a4 + 40) )
    {
      if ( v14 )
      {
        if ( (unsigned int)(a1 - 1) > 1 )
        {
          debug_level_str = get_debug_level_str(a1);
          printk(&unk_845B1, debug_level_str, a2, *a3);
        }
        else
        {
          v15 = _ReadStatusReg(SP_EL0);
          v16 = *(_DWORD *)(v15 + 1800);
          v17 = *(_DWORD *)(v15 + 1804);
          v18 = get_debug_level_str(v12);
          printk(&unk_8EBAF, v16, v17, v18);
        }
      }
    }
    else if ( v14 )
    {
      if ( (unsigned int)(a1 - 1) > 1 )
      {
        v26 = get_debug_level_str(a1);
        printk(&unk_89F57, v26, a2, *(_QWORD *)(a4 + 48));
      }
      else
      {
        v21 = _ReadStatusReg(SP_EL0);
        v22 = *(_DWORD *)(v21 + 1800);
        v23 = *(_DWORD *)(v21 + 1804);
        v24 = get_debug_level_str(v12);
        printk(&unk_916F0, v22, v23, v24);
      }
    }
    goto LABEL_26;
  }
  v9 = cvp_hfi_defs + 84LL * (unsigned int)pkt_index_from_type;
  v10 = strnlen((const char *)(v9 + 16), 0x40u);
  if ( v10 >= 0x41 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v10 == 64 )
      v11 = 64;
    else
      v11 = v10 + 1;
    if ( v11 < 0x41 )
    {
      sized_strscpy(v28, v9 + 16);
      goto LABEL_12;
    }
  }
  v27 = _fortify_panic(7);
  return print_cvp_buffer(v27);
}
