__int64 __fastcall btfmcodec_revert_current_state(__int64 a1)
{
  int v2; // w8

  mutex_lock(a1);
  coverttostring(*(_DWORD *)(a1 + 52));
  coverttostring(*(_DWORD *)(a1 + 48));
  printk(&unk_D2A6, "btfmcodec_revert_current_state");
  v2 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 52) = v2;
  return mutex_unlock(a1);
}
