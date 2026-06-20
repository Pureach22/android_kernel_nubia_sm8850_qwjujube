__int64 __fastcall mem_object_to_dma_buf(unsigned __int64 a1)
{
  if ( a1 >= 2 && *(_DWORD *)(a1 + 12) == 2 && *(__int64 **)(a1 + 24) == &mem_ops )
    return *(_QWORD *)(a1 + 88);
  else
    return -22;
}
