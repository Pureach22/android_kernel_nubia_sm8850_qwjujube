__int64 *__fastcall get_client_node(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x23
  __int64 *i; // x20
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v12; // x20
  __int64 v13; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_15:
      printk(&unk_1905C, "_get_client_node", 361, v5, a5);
      return nullptr;
    }
  }
  else
  {
    v12 = a1;
    v13 = v5;
    printk(&unk_1E83A, "_get_client_node", 358, a4, a5);
    a1 = v12;
    v5 = v13;
    if ( !v12 )
      goto LABEL_15;
  }
  v7 = *(_QWORD *)(a1 + 792);
  if ( !v7 )
    goto LABEL_15;
  mutex_lock(v7 + 32);
  for ( i = *(__int64 **)(v7 + 16); i != (__int64 *)(v7 + 16); i = (__int64 *)*i )
  {
    if ( i && *((_DWORD *)i + 6) == a2 )
      goto LABEL_11;
  }
  i = nullptr;
LABEL_11:
  mutex_unlock(v7 + 32);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "_get_client_node", 375, v9, v10);
  return i;
}
