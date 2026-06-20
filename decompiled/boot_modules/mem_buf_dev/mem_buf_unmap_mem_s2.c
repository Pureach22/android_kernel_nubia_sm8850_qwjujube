__int64 __fastcall mem_buf_unmap_mem_s2(__int64 a1)
{
  unsigned int v1; // w19
  __int64 result; // x0
  unsigned int v3; // w20

  v1 = a1;
  result = gh_rm_mem_release(a1, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v3 = result;
    printk(&unk_13658, "mem_buf_unmap_mem_s2", v1);
    return v3;
  }
  return result;
}
