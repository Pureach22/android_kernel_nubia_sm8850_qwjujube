__int64 __fastcall rmnet_shs_release_global(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v11; // w8

  rmnet_shs_ep_lock_bh();
  if ( global_shared )
  {
    v3 = *(_QWORD *)(a2 + 32);
    _X0 = (unsigned int *)(v3 + 8);
    if ( *(_DWORD *)(v3 + 8) > 1u )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v11 = __ldxr(_X0);
      while ( __stlxr(v11 - 1, _X0) );
      if ( v11 <= 1 )
        refcount_warn_saturate();
    }
    else
    {
      free_pages(*(_QWORD *)v3, 0);
      kfree(v3);
      global_shared = 0;
      *(_QWORD *)(a2 + 32) = 0;
    }
  }
  rmnet_shs_ep_unlock_bh();
  return 0;
}
