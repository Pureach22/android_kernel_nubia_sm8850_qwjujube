__int64 __fastcall mem_buf_alloc_resp_hdlr(__int64 a1, unsigned int *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v5; // w19

  if ( (mem_buf_capability & 2) == 0 )
    return 0xFFFFFFFFLL;
  result = a2[3];
  if ( (result & 0x80000000) != 0 )
  {
    v5 = a2[3];
    printk(&unk_98E8, "mem_buf_alloc_resp_hdlr");
    return v5;
  }
  else
  {
    *(_DWORD *)(a4 + 24) = a2[4];
    *(_DWORD *)(a4 + 88) = a2[5];
  }
  return result;
}
