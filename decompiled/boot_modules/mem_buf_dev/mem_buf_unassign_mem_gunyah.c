__int64 __fastcall mem_buf_unassign_mem_gunyah(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x2
  unsigned int v3; // w19

  result = ghd_rm_mem_reclaim(a1, 0);
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_1355B, "mem_buf_unassign_mem_gunyah", v2);
    return v3;
  }
  return result;
}
