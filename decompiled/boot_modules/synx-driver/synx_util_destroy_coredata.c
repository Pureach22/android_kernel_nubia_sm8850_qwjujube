__int64 __fastcall synx_util_destroy_coredata(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5

  v7 = a1 - 120;
  if ( v7 && (*(_BYTE *)(a1 + 4) & 2) != 0 )
  {
    v8 = v7;
    v9 = a1;
    if ( (unsigned int)synx_global_clear_subscribed_core(*(_DWORD *)(a1 + 224), 0, a3, a4, a5, a6)
      && (synx_debug & 1) != 0 )
    {
      printk(&unk_2867D, &unk_29207, "synx_util_destroy_coredata", 330, v13, v14);
    }
    synx_global_put_ref(*(unsigned int *)(v9 + 224), v10, v11, v12, v13, v14);
    v7 = v8;
  }
  return synx_util_object_destroy(v7);
}
