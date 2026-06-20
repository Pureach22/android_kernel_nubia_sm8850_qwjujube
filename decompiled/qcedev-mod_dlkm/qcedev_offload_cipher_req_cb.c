_QWORD *__fastcall qcedev_offload_cipher_req_cb(_QWORD *result, int a2, void *src)
{
  __int64 *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x9
  size_t v6; // x8
  unsigned __int64 v13; // x8
  size_t v14; // [xsp+0h] [xbp-10h]
  void *v15; // [xsp+8h] [xbp-8h]
  __int64 v16; // [xsp+28h] [xbp+18h]

  if ( result )
  {
    v3 = (__int64 *)result[10];
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        if ( src )
        {
          v5 = *(_QWORD *)(v4 + 264);
          if ( v5 )
          {
            v6 = *(unsigned int *)(v5 + 592);
            if ( (unsigned int)v6 >= 0x21 && (qcedev_offload_cipher_req_cb___already_done & 1) == 0 )
            {
              v16 = *(_QWORD *)(v4 + 264);
              v14 = *(unsigned int *)(v5 + 592);
              v15 = src;
              qcedev_offload_cipher_req_cb___already_done = 1;
              _warn_printk(
                "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                v6,
                "field \"&qcedev_areq->offload_cipher_op_req.iv[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto"
                "-qti/qcedev.c:593",
                0x20u);
              v6 = v14;
              src = v15;
              v5 = v16;
              __break(0x800u);
            }
            result = memcpy((void *)(v5 + 600), src, v6);
          }
        }
        _X9 = (unsigned __int64 *)(v4 + 288);
        __asm { PRFM            #0x11, [X9] }
        do
          v13 = __ldxr(_X9);
        while ( __stlxr(v13 | 1, _X9) );
        __dmb(0xBu);
        if ( (v13 & 1) == 0 )
          return (_QWORD *)_tasklet_schedule(v4 + 280);
      }
    }
  }
  return result;
}
