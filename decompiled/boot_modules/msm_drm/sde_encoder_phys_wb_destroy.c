_QWORD *__fastcall sde_encoder_phys_wb_destroy(_QWORD *result)
{
  _QWORD *v1; // x19
  int v2; // w4
  __int64 v3; // x8
  int v4; // w5
  int v11; // w8

  if ( !result )
    return result;
  v1 = result;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *result )
    {
      v2 = *(_DWORD *)(*result + 24LL);
      v3 = result[358];
      if ( v3 )
      {
LABEL_5:
        v4 = *(_DWORD *)(v3 + 12) - 1;
LABEL_8:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d]\n", v2, v4);
        goto LABEL_9;
      }
    }
    else
    {
      v2 = -1;
      v3 = result[358];
      if ( v3 )
        goto LABEL_5;
    }
    v4 = -1;
    goto LABEL_8;
  }
LABEL_9:
  if ( v1[363] )
  {
    drm_framebuffer_unregister_private();
    drm_framebuffer_remove(v1[363]);
    v1[363] = 0;
  }
  _X0 = (unsigned int *)v1[359];
  if ( _X0 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(_X0);
    while ( __stlxr(v11 - 1, _X0) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      drm_gem_object_free(_X0);
    }
    else if ( v11 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    v1[359] = 0;
  }
  return (_QWORD *)kfree(v1);
}
