__int64 __fastcall synx_client_cleanup(__int64 a1)
{
  __int64 v1; // x9
  __int64 *v2; // x8
  __int64 *v3; // x27
  __int64 *v4; // x20
  int i; // w21
  __int64 *v7; // x8
  __int64 v8; // x9
  int v14; // w8
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 *v18; // [xsp+18h] [xbp-8h]

  if ( (unsigned int)__ratelimit(&synx_ratelimit_state, "synx_client_cleanup") && (synx_debug & 4) != 0 )
    printk(&unk_283A4, "info", "synx_client_cleanup", 1633, *(_QWORD *)(a1 - 264824), a1 - 264888);
  v1 = 0;
  do
  {
    v17 = v1;
    v2 = *(__int64 **)(a1 - 2056 + 8 * v1);
    if ( v2 )
    {
      do
      {
        v3 = v2 - 9;
        if ( v2 == &_ksymtab_synx_deregister_ops )
          break;
        v4 = v2;
        v18 = (__int64 *)*v2;
        if ( (unsigned int)__ratelimit(&synx_ratelimit_state, "synx_client_cleanup") && (synx_debug & 2) != 0 )
          printk(&unk_28A78, "warn", "synx_client_cleanup", 1642, *(_QWORD *)(a1 - 264824), *((unsigned int *)v3 + 7));
        _X28 = (unsigned int *)(v3 + 3);
        for ( i = *((_DWORD *)v3 + 6); i; --i )
        {
          __asm { PRFM            #0x11, [X28] }
          do
            v14 = __ldxr(_X28);
          while ( __stlxr(v14 - 1, _X28) );
          if ( v14 == 1 )
          {
            __dmb(9u);
            v7 = (__int64 *)v3[10];
            if ( v7 )
            {
              v8 = *v4;
              *v7 = *v4;
              if ( v8 )
                *(_QWORD *)(v8 + 8) = v7;
              *v4 = 0;
              v3[10] = 0;
            }
            if ( (synx_debug & 0x80) != 0 )
              printk(
                &unk_2A487,
                &unk_25D36,
                "synx_util_destroy_handle",
                1257,
                *(_QWORD *)(*v3 + 104),
                *((unsigned int *)v3 + 7));
            v3[5] = 0xFFFFFFFE00000LL;
            v3[6] = (__int64)(v3 + 6);
            v3[7] = (__int64)(v3 + 6);
            v3[8] = (__int64)synx_util_destroy_handle_worker;
            queue_work_on(32, *(_QWORD *)(synx_dev + 168), v3 + 5);
          }
          else if ( v14 <= 0 )
          {
            refcount_warn_saturate(v3 + 3, 3);
          }
        }
        v2 = v18;
      }
      while ( v18 );
    }
    v1 = v17 + 1;
  }
  while ( v17 != 255 );
  if ( (synx_debug & 0x10) != 0 )
    printk(&unk_28D3C, "verb", "synx_client_cleanup", 1652, *(_QWORD *)(a1 - 264824), a1 - 264888);
  *(_QWORD *)(a1 - 264912) = 0;
  return vfree(a1 - 264928);
}
