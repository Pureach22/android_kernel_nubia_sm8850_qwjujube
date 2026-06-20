__int64 __fastcall hw_fence_get_txq_skip_wr_idx(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  char v3; // w8

  if ( a1 && a2 && *(_DWORD *)(a2 + 136) )
  {
    v3 = *(_BYTE *)(a2 + 80);
  }
  else
  {
    printk(&unk_26248, "hw_fence_get_txq_skip_wr_idx", 2891, v2, a1);
    v3 = 0;
  }
  return v3 & 1;
}
