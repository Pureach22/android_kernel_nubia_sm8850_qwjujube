__int64 __fastcall cvp_fastrpc_probe(__int64 a1)
{
  __int64 *fastrpc_node_with_handle; // x0
  __int64 *v3; // x20
  unsigned int v11; // w10

  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_849A6, "dsp", "cvp_fastrpc_probe", *(unsigned int *)(a1 + 928));
  fastrpc_node_with_handle = cvp_get_fastrpc_node_with_handle(*(_DWORD *)(a1 + 928));
  if ( fastrpc_node_with_handle )
  {
    v3 = fastrpc_node_with_handle;
    fastrpc_node_with_handle[32] = a1;
    complete(fastrpc_node_with_handle + 33);
    if ( *((int *)v3 + 7) >= 1 )
    {
      _X8 = (unsigned int *)v3 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 - 1, _X8) );
    }
  }
  return 0;
}
