__int64 __fastcall sde_fence_release(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned __int64 v3; // x0
  __int64 v4; // x8
  int v11; // w9

  if ( result )
  {
    v1 = *(_QWORD *)(result + 120);
    v2 = result;
    if ( (*(_QWORD *)(result + 48) & 0x80000000) != 0 )
    {
      if ( v1 )
      {
        v3 = *(_QWORD *)(v1 + 168);
        if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(
              0,
              0,
              0,
              "destroy hw fence ctl_id:%d ctx:%llu seqno:%llu name:%s\n",
              *(_DWORD *)(v1 + 64) - 1,
              *(_QWORD *)(v2 + 32),
              *(_QWORD *)(v2 + 40),
              (const char *)(v2 + 72));
            v3 = *(_QWORD *)(v1 + 168);
          }
          if ( (unsigned int)synx_release(v3, *(unsigned int *)(v2 + 128)) )
            printk(&unk_24D874, "_sde_hw_fence_release");
        }
        else
        {
          printk(&unk_247027, "_sde_hw_fence_release");
        }
      }
      else
      {
        printk(&unk_23CE1A, "_sde_hw_fence_release");
      }
    }
    v4 = *(_QWORD *)(v2 + 64);
    _X0 = (unsigned int *)(v4 + 12);
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(_X0);
    while ( __stlxr(v11 - 1, _X0) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      if ( v4 == -12 )
        printk(&unk_228677, "sde_fence_destroy");
      else
        kfree(v4);
    }
    else if ( v11 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    return kfree(v2);
  }
  return result;
}
