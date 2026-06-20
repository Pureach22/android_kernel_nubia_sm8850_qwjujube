__int64 __fastcall ipa3_uc_register_ready_cb(_DWORD **a1)
{
  unsigned int v2; // w20
  _DWORD *v3; // x8

  mutex_lock(&uc_loaded_nb_lock);
  v2 = blocking_notifier_chain_register(&uc_loaded_notifier, a1);
  if ( !v2 && *(_BYTE *)(ipa3_ctx + 34657) == 1 )
  {
    v3 = *a1;
    if ( *(*a1 - 1) != -720209349 )
      __break(0x8228u);
    ((void (__fastcall *)(_DWORD **, _QWORD))v3)(a1, 0);
  }
  mutex_unlock(&uc_loaded_nb_lock);
  return v2;
}
