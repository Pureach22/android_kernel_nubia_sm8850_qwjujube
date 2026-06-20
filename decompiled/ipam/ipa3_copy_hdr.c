__int64 __fastcall ipa3_copy_hdr(__int64 a1)
{
  __int64 hdr; // x0
  size_t v3; // x2
  __int64 v4; // x20
  unsigned int v5; // w21
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  size_t v10; // x21

  if ( a1 )
  {
    mutex_lock(ipa3_ctx + 29472);
    *(_BYTE *)(a1 + 31) = 0;
    hdr = _ipa_find_hdr((const char *)a1);
    if ( hdr )
    {
      v3 = *(unsigned int *)(hdr + 276);
      v4 = hdr;
      if ( (unsigned int)v3 >= 0x100 && (ipa3_copy_hdr___already_done & 1) == 0 )
      {
        ipa3_copy_hdr___already_done = 1;
        v10 = v3;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v3,
          "field \"copy->hdr\" at ../vendor/qcom/opensource/dataipa/drivers/platform/msm/ipa/ipa_v3/ipa_hdr.c:1735",
          0xFFu);
        v3 = v10;
        __break(0x800u);
      }
      memcpy((void *)(a1 + 32), (const void *)(v4 + 20), v3);
      v5 = 0;
      *(_BYTE *)(a1 + 287) = *(_DWORD *)(v4 + 276);
      *(_DWORD *)(a1 + 288) = *(_DWORD *)(v4 + 312);
      *(_BYTE *)(a1 + 292) = *(_BYTE *)(v4 + 316);
      *(_BYTE *)(a1 + 293) = *(_BYTE *)(v4 + 344);
      *(_WORD *)(a1 + 294) = *(_WORD *)(v4 + 346);
    }
    else
    {
      v5 = -14;
    }
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_copy_hdr__rs, "ipa3_copy_hdr") )
      printk(&unk_3FB3F2, "ipa3_copy_hdr");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-22;
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d bad parm\n", "ipa3_copy_hdr", 1728);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d bad parm\n", "ipa3_copy_hdr", 1728);
      return (unsigned int)-22;
    }
    else
    {
      return (unsigned int)-22;
    }
  }
  return v5;
}
