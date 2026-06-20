__int64 __fastcall rmnet_shs_open_global(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20
  __int64 v6; // x20
  __int64 free_pages_noprof; // x0
  unsigned int v13; // w8

  rmnet_shs_ep_lock_bh();
  if ( global_shared )
  {
    _X0 = (unsigned int *)(global_shared + 8);
    __asm { PRFM            #0x11, [X0] }
    do
      v13 = __ldxr(_X0);
    while ( __stxr(v13 + 1, _X0) );
    if ( !v13 || (((v13 + 1) | v13) & 0x80000000) != 0 )
      refcount_warn_saturate();
  }
  else
  {
    v6 = _kmalloc_cache_noprof(param_ops_uint, 2336, 16);
    if ( !v6 )
    {
      v4 = -12;
      goto LABEL_5;
    }
    free_pages_noprof = get_free_pages_noprof(264224, 4);
    *(_QWORD *)v6 = free_pages_noprof;
    if ( !free_pages_noprof )
    {
      kfree(v6);
      v4 = -12;
      goto LABEL_5;
    }
    global_shared = v6;
    *(_DWORD *)(v6 + 8) = 1;
  }
  v4 = 0;
  *(_QWORD *)(a2 + 32) = global_shared;
LABEL_5:
  rmnet_shs_ep_unlock_bh();
  return v4;
}
