__int64 __fastcall syna_tcm_buf_lock(__int64 a1)
{
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 64) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 64));
  result = mutex_lock(a1 + 16);
  ++*(_BYTE *)(a1 + 64);
  return result;
}
