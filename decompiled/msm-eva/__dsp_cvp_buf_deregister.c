__int64 __fastcall _dsp_cvp_buf_deregister(__int64 a1)
{
  char v2; // w8
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v5; // x20
  __int64 v6; // x21
  int v7; // w8
  int v8; // w11
  int v9; // w10
  int v10; // w11
  __int64 v11; // x3
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v15; // x8
  unsigned int v18; // w10
  unsigned int v25; // w10
  unsigned int v28; // w10

  v2 = BYTE1(msm_cvp_debug);
  *(_DWORD *)(a1 + 4) = 0;
  if ( (v2 & 8) != 0 && !msm_cvp_debug_out )
    printk(&unk_90F1F, "dsp", "__dsp_cvp_buf_deregister", (unsigned int)dword_6C7D4);
  result = get_inst_from_dsp((unsigned int)dword_6C7DC, dword_6C7D8);
  if ( result )
  {
    v4 = result;
    result = (__int64)cvp_get_fastrpc_node_with_handle((unsigned int)off_6C7E0);
    if ( result )
    {
      v5 = result;
      result = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 2704);
      v6 = result;
      if ( result )
      {
        *(_DWORD *)result = 268439556;
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
        if ( (unsigned int)msm_cvp_unregister_buffer(v4, (_DWORD *)(result + 16)) )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_8FAFB, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          *(_DWORD *)(a1 + 4) = -1;
        }
        else
        {
          _X8 = (unsigned int *)(v5 + 6520);
          __asm { PRFM            #0x11, [X8] }
          do
            v25 = __ldxr(_X8);
          while ( __stxr(v25 - 1, _X8) );
          if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
            printk(&unk_92753, "dsp", "__dsp_cvp_buf_deregister", v11);
        }
        if ( *(int *)(v5 + 28) >= 1 )
        {
          _X8 = (unsigned int *)(v5 + 28);
          __asm { PRFM            #0x11, [X8] }
          do
            v18 = __ldxr(_X8);
          while ( __stxr(v18 - 1, _X8) );
        }
        return kfree(v6);
      }
      else
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v15 = _ReadStatusReg(SP_EL0);
          result = printk(&unk_8FACF, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
        }
        *(_DWORD *)(a1 + 4) = -1;
        if ( *(int *)(v5 + 28) >= 1 )
        {
          _X8 = (unsigned int *)(v5 + 28);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 - 1, _X8) );
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
      v13 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_92722, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
    }
    *(_DWORD *)(a1 + 4) = -1;
  }
  return result;
}
