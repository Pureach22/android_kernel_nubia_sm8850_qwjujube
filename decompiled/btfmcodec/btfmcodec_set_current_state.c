__int64 __fastcall btfmcodec_set_current_state(__int64 a1, unsigned int a2)
{
  mutex_lock(a1);
  coverttostring(*(_DWORD *)(a1 + 52));
  coverttostring(a2);
  printk(&unk_DE1E, "btfmcodec_set_current_state");
  *(_DWORD *)(a1 + 48) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a1 + 52) = a2;
  return mutex_unlock(a1);
}
