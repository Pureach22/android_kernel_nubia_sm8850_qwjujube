__int64 __fastcall cvp_dsp_del_sess(unsigned int a1, __int64 *a2)
{
  __int64 *fastrpc_node_with_handle; // x0
  __int64 *v4; // x19
  __int64 *v5; // x21
  __int64 *v6; // x8
  __int64 **v7; // x8
  __int64 **v8; // x0
  __int64 *v9; // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v18; // w10

  fastrpc_node_with_handle = cvp_get_fastrpc_node_with_handle(a1);
  if ( fastrpc_node_with_handle )
  {
    v4 = fastrpc_node_with_handle;
    v5 = fastrpc_node_with_handle + 37;
    mutex_lock(fastrpc_node_with_handle + 39);
    v6 = v5;
    while ( 1 )
    {
      v6 = (__int64 *)*v6;
      if ( v6 == v5 || !v6 )
        break;
      if ( v6 - 2 == a2 )
      {
        if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
          printk(&unk_8904A, "dsp", "cvp_dsp_del_sess", a2);
        v7 = (__int64 **)a2[3];
        v8 = (__int64 **)(a2 + 2);
        if ( *v7 == a2 + 2 && (v9 = *v8, (__int64 **)(*v8)[1] == v8) )
        {
          v9[1] = (__int64)v7;
          *v7 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        a2[2] = 0xDEAD000000000100LL;
        a2[3] = 0xDEAD000000000122LL;
        --*((_DWORD *)v4 + 5);
        break;
      }
    }
    mutex_unlock(v4 + 39);
    if ( *((int *)v4 + 7) >= 1 )
    {
      _X8 = (unsigned int *)v4 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 - 1, _X8) );
    }
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8900F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
