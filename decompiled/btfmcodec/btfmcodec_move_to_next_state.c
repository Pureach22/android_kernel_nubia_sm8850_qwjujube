__int64 __fastcall btfmcodec_move_to_next_state(__int64 a1)
{
  unsigned int v2; // w0

  mutex_lock(a1);
  v2 = *(_DWORD *)(a1 + 52);
  if ( (v2 | 2) == 3 )
  {
    *(_DWORD *)(a1 + 52) = v2 + 1;
    coverttostring(v2);
    coverttostring(*(_DWORD *)(a1 + 52));
    printk(&unk_DE1E, "btfmcodec_move_to_next_state");
  }
  else
  {
    printk(&unk_DA22, "btfmcodec_move_to_next_state");
    *(_DWORD *)(a1 + 52) = 0;
  }
  *(_DWORD *)(a1 + 48) = 0;
  return mutex_unlock(a1);
}
