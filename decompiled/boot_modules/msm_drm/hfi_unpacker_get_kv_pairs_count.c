__int64 __fastcall hfi_unpacker_get_kv_pairs_count(_QWORD *a1, __int64 a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x8

  if ( a1 && a2 && *a1 && a4 && (v4 = *(_QWORD *)(a2 + 24)) != 0 )
  {
    *a4 = *(_DWORD *)(v4 + a3);
    return 0;
  }
  else
  {
    printk(&unk_253204, "hfi_unpacker_get_kv_pairs_count");
    return 0xFFFFFFFFLL;
  }
}
