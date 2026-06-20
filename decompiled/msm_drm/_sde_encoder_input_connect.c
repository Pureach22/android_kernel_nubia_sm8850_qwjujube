__int64 __fastcall sde_encoder_input_connect(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x8
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w20

  v4 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  v5 = v4;
  if ( !v4 )
    return 4294967284LL;
  v6 = *(_QWORD *)(a1 + 72);
  v4[3] = a2;
  v4[4] = a1;
  v4[2] = v6;
  v7 = input_register_handle(v4);
  if ( v7 )
  {
    v9 = v7;
    printk(&unk_257025, "_sde_encoder_input_connect");
  }
  else
  {
    result = input_open_device(v5);
    if ( !(_DWORD)result )
      return result;
    v9 = result;
    printk(&unk_268F70, "_sde_encoder_input_connect");
    input_unregister_handle(v5);
  }
  kfree(v5);
  return v9;
}
