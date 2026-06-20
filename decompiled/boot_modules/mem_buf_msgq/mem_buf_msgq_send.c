__int64 __fastcall mem_buf_msgq_send(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v4; // w19

  if ( *(_DWORD *)(a2 + 4) >= 4u )
  {
    printk(&unk_7201, "mem_buf_msgq_send", a3);
    return 4294967274LL;
  }
  else
  {
    result = gh_msgq_send(*(_QWORD *)(a1 + 88), a2, *(unsigned int *)(a2 + 8), 0);
    if ( (result & 0x80000000) != 0 )
    {
      v4 = result;
      printk(&unk_7284, "mem_buf_msgq_send", (unsigned int)result);
      return v4;
    }
  }
  return result;
}
