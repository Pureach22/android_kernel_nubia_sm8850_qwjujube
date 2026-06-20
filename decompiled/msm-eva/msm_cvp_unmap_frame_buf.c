__int64 __fastcall msm_cvp_unmap_frame_buf(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x26
  __int64 *v5; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v7; // x27
  __int64 v8; // x9
  unsigned int v15; // w8
  unsigned int v16; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8

  if ( *(_DWORD *)(a2 + 2576) )
  {
    v4 = 0;
    v5 = (__int64 *)(a2 + 72);
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      if ( v4 == 41 )
      {
        __break(0x5512u);
        JUMPOUT(0x43B10);
      }
      v7 = *v5;
      msm_cvp_cache_operations(*v5, 2, *((_DWORD *)v5 - 8), *((_DWORD *)v5 - 9));
      if ( v7 )
      {
        if ( *(_BYTE *)(v7 + 84) == 1 )
        {
          mutex_lock(a1 + 536);
          _X9 = (unsigned int *)(v7 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v15 = __ldxr(_X9);
            v16 = v15 - 1;
          }
          while ( __stlxr(v16, _X9) );
          __dmb(0xBu);
          if ( !v16 )
          {
            print_smem(0x40u, (__int64)"Map dereference", a1, v7);
            *(_DWORD *)(v7 + 96) |= 0x10000000u;
          }
          mutex_unlock(a1 + 536);
        }
        else
        {
          _X9 = (unsigned int *)(v7 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v19 = __ldxr(_X9);
            v20 = v19 - 1;
          }
          while ( __stlxr(v20, _X9) );
          __dmb(0xBu);
          if ( !v20 )
          {
            if ( (unsigned int)msm_cvp_unmap_smem(a1, v7, (__int64)"unmap cpu") )
            {
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_9188E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            }
            else
            {
              msm_cvp_smem_put_dma_buf(*(_QWORD *)(v7 + 48));
            }
            v8 = cvp_driver;
            *(_DWORD *)(v7 + 96) |= 0xDEAD0000;
            cvp_kmem_cache_free(v8 + 120, v7);
            *v5 = 0;
          }
        }
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_9185A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      ++v4;
      v5 += 8;
    }
    while ( v4 < *(unsigned int *)(a2 + 2576) );
  }
  return cvp_kmem_cache_free(cvp_driver + 88, a2);
}
