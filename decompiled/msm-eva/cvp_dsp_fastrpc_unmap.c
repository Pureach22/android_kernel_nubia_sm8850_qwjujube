__int64 __fastcall cvp_dsp_fastrpc_unmap(__int64 a1, __int64 a2)
{
  __int64 fastrpc_node_with_handle; // x0
  __int64 v4; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w20
  unsigned __int64 v8; // x8
  unsigned int v15; // w10

  fastrpc_node_with_handle = cvp_get_fastrpc_node_with_handle();
  if ( fastrpc_node_with_handle )
  {
    v4 = fastrpc_node_with_handle;
    result = eva_fastrpc_dev_unmap_dma(*(_QWORD *)(fastrpc_node_with_handle + 256), a2);
    if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v7 = result;
      printk(&unk_85256, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v7;
    }
    if ( *(int *)(v4 + 28) >= 1 )
    {
      _X8 = (unsigned int *)(v4 + 28);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 - 1, _X8) );
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_8900F, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
