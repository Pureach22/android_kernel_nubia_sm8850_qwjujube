__int64 __fastcall print_smem(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  int pkt_index_from_type; // w0
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x0
  _BOOL4 v15; // w8
  unsigned __int64 v16; // x8
  unsigned int v17; // w19
  unsigned int v18; // w20
  __int64 v19; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v21; // x8
  unsigned int v22; // w19
  unsigned int v23; // w20
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  unsigned int v26; // w21
  unsigned int v27; // w22
  __int64 v28; // x0
  unsigned __int64 v29; // x8
  unsigned int v30; // w21
  unsigned int v31; // w22
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 debug_level_str; // x0
  __int64 v35; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  _QWORD v39[9]; // [xsp+18h] [xbp-48h] BYREF

  v39[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  strcpy((char *)v39, "Unknown");
  memset(&v39[1], 0, 56);
  if ( (msm_cvp_debug & a1) == 0 )
  {
LABEL_40:
    LODWORD(v4) = 0;
    goto LABEL_41;
  }
  if ( !a3 || !a4 )
  {
    LODWORD(v4) = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_90B4D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      LODWORD(v4) = -22;
    }
    goto LABEL_41;
  }
  v4 = *(_QWORD *)(a4 + 48);
  if ( !v4 )
  {
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return (unsigned int)v4;
  }
  pkt_index_from_type = get_pkt_index_from_type(*(unsigned int *)(a4 + 92));
  if ( pkt_index_from_type < 1 )
  {
LABEL_12:
    v13 = a1;
    v15 = (msm_cvp_debug & a1) != 0 && msm_cvp_debug_out == 0;
    if ( *(_DWORD *)(a4 + 40) )
    {
      if ( v15 )
      {
        if ( a1 - 1 > 1 )
        {
          debug_level_str = get_debug_level_str(a1);
          printk(&unk_944EA, debug_level_str, a2, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
        else
        {
          v25 = _ReadStatusReg(SP_EL0);
          v26 = *(_DWORD *)(v25 + 1800);
          v27 = *(_DWORD *)(v25 + 1804);
          v28 = get_debug_level_str(a1);
          printk(&unk_916AC, v26, v27, v28);
        }
        v13 = a1;
      }
      LODWORD(v4) = 0;
      if ( (msm_cvp_debug & (unsigned int)v13) == 0 || msm_cvp_debug_out )
        goto LABEL_41;
      if ( (unsigned int)(v13 - 1) > 1 )
      {
        v33 = get_debug_level_str(v13);
        printk(&unk_82703, v33, *(unsigned int *)(a4 + 40), v39);
      }
      else
      {
        v16 = _ReadStatusReg(SP_EL0);
        v17 = *(_DWORD *)(v16 + 1800);
        v18 = *(_DWORD *)(v16 + 1804);
        v19 = get_debug_level_str(v13);
        printk(&unk_89534, v17, v18, v19);
      }
    }
    else
    {
      if ( v15 )
      {
        if ( a1 - 1 > 1 )
        {
          v37 = get_debug_level_str(a1);
          printk(&unk_89F1B, v37, a2, *(_QWORD *)(a4 + 48));
        }
        else
        {
          v29 = _ReadStatusReg(SP_EL0);
          v30 = *(_DWORD *)(v29 + 1800);
          v31 = *(_DWORD *)(v29 + 1804);
          v32 = get_debug_level_str(a1);
          printk(&unk_92414, v30, v31, v32);
        }
        v13 = a1;
      }
      LODWORD(v4) = 0;
      if ( (msm_cvp_debug & (unsigned int)v13) == 0 || msm_cvp_debug_out )
        goto LABEL_41;
      if ( (unsigned int)(v13 - 1) > 1 )
      {
        v35 = get_debug_level_str(v13);
        printk(&unk_90344, v35, v39, *(unsigned int *)(a4 + 96));
      }
      else
      {
        v21 = _ReadStatusReg(SP_EL0);
        v22 = *(_DWORD *)(v21 + 1800);
        v23 = *(_DWORD *)(v21 + 1804);
        v24 = get_debug_level_str(v13);
        printk(&unk_8BF0A, v22, v23, v24);
      }
    }
    goto LABEL_40;
  }
  v10 = cvp_hfi_defs + 84LL * (unsigned int)pkt_index_from_type;
  v11 = strnlen((const char *)(v10 + 16), 0x40u);
  if ( v11 >= 0x41 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v11 == 64 )
      v12 = 64;
    else
      v12 = v11 + 1;
    if ( v12 < 0x41 )
    {
      sized_strscpy(v39, v10 + 16);
      goto LABEL_12;
    }
  }
  v38 = _fortify_panic(7);
  return get_debug_level_str(v38);
}
