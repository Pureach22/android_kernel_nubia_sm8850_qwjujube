__int64 __fastcall _dsp_cvp_buf_register(_DWORD *a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v5; // x20
  _DWORD *v6; // x21
  int v7; // w8
  int v8; // w11
  int v9; // w10
  int v10; // w11
  __int64 v11; // x3
  unsigned __int64 v12; // x8
  __int64 v13; // x3
  int v14; // w4
  int v15; // w9
  char v16; // w10
  int v17; // w8
  unsigned __int64 v18; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x8
  unsigned int v27; // w10
  unsigned int v30; // w9
  unsigned int v33; // w10

  v2 = BYTE1(msm_cvp_debug);
  a1[1] = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_90EDF, "dsp", "__dsp_cvp_buf_register", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  if ( result )
  {
    v4 = result;
    result = (__int64)cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
    if ( result )
    {
      v5 = result;
      result = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 2704);
      v6 = (_DWORD *)result;
      if ( result )
      {
        *(_DWORD *)result = 268439555;
        v7 = dword_6C8A0;
        v8 = dword_6C8A4;
        *(_QWORD *)(result + 36) = 0;
        *(_DWORD *)(result + 16) = v8;
        v9 = dword_6C898;
        v10 = dword_6C89C;
        *(_DWORD *)(result + 20) = 1;
        *(_DWORD *)(result + 24) = v10;
        *(_DWORD *)(result + 28) = v9;
        *(_DWORD *)(result + 32) = v7;
        if ( (unsigned int)msm_cvp_register_buffer(v4, (_DWORD *)(result + 16)) )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8D504, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          a1[1] = -1;
        }
        else
        {
          if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            printk(&unk_84915, "dsp", "__dsp_cvp_buf_register", v11);
          _X8 = (unsigned int *)(v5 + 6520);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 + 1, _X8) );
          v13 = (unsigned int)v6[6];
          v14 = v6[11];
          v15 = v6[4];
          v16 = BYTE1(msm_cvp_debug);
          a1[17] = v6[7];
          a1[18] = v13;
          v17 = v6[8];
          a1[20] = v15;
          a1[21] = v14;
          a1[19] = v17;
          if ( (v16 & 8) != 0 && !msm_cvp_debug_out )
            printk(&unk_9713E, "dsp", "__dsp_cvp_buf_register", v13);
        }
        if ( *(int *)(v5 + 28) >= 1 )
        {
          _X8 = (unsigned int *)(v5 + 28);
          __asm { PRFM            #0x11, [X8] }
          do
            v27 = __ldxr(_X8);
          while ( __stxr(v27 - 1, _X8) );
        }
        return kfree(v6);
      }
      else
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v20 = _ReadStatusReg(SP_EL0);
          result = printk(&unk_8FACF, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
        }
        a1[1] = -1;
        if ( *(int *)(v5 + 28) >= 1 )
        {
          _X8 = (unsigned int *)(v5 + 28);
          __asm { PRFM            #0x11, [X8] }
          do
            v33 = __ldxr(_X8);
          while ( __stxr(v33 - 1, _X8) );
        }
      }
    }
    else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      return printk(&unk_84897, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), "warn");
    }
  }
  else
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v18 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_92722, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
    }
    a1[1] = -1;
  }
  return result;
}
