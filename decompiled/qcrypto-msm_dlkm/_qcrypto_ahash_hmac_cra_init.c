__int64 __fastcall qcrypto_ahash_hmac_cra_init(__int64 a1)
{
  __int64 v1; // x9
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 - 8) = 472;
  v3 = a1 + 32;
  v4 = *(_QWORD *)(v1 + 840);
  *(_DWORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = v4;
  *(_QWORD *)(a1 + 32) = a1 + 32;
  *(_QWORD *)(a1 + 40) = a1 + 32;
  v5 = _kmalloc_noprof(*(unsigned int *)(a1 - 8) + 80LL, 3264);
  if ( v5 )
  {
    *(_QWORD *)(v5 + 32) = a1;
    *(_DWORD *)(a1 + 152) = 0;
    v6 = a1 + 152;
    *(_QWORD *)(v6 - 8) = v5;
    _init_swait_queue_head(v6 + 8, "&x->wait", &init_completion___key);
    v7 = *(_QWORD *)(v6 - 8);
    result = 0;
    *(_QWORD *)(v7 + 16) = crypto_sha_hmac_ahash_req_complete;
    *(_QWORD *)(v7 + 24) = v6;
    *(_DWORD *)(v7 + 40) = 1024;
    *(_DWORD *)(v6 - 148) = 0;
  }
  else
  {
    *(_QWORD *)(a1 + 144) = 0;
    if ( *(_QWORD *)(a1 + 32) != v3 )
    {
      printk(&unk_11EF2, "_qcrypto_ahash_cra_exit");
      v9 = *(_QWORD *)(a1 + 144);
      if ( v9 )
      {
        kfree_sensitive(v9);
        *(_QWORD *)(a1 + 144) = 0;
      }
    }
    return 4294967284LL;
  }
  return result;
}
