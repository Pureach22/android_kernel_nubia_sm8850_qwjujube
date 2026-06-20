__int64 *__fastcall cqhci_post_req(__int64 *result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x3

  v2 = *(_QWORD *)(a2 + 16);
  if ( v2 )
  {
    v3 = *result;
    if ( (*(_DWORD *)(v2 + 24) & 0x200) != 0 )
      v4 = 2;
    else
      v4 = 1;
    return (__int64 *)dma_unmap_sg_attrs(v3, *(_QWORD *)(v2 + 56), *(unsigned int *)(v2 + 48), v4, 0);
  }
  return result;
}
