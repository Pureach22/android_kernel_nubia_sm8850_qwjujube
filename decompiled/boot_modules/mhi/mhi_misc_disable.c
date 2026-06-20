__int64 __fastcall mhi_misc_disable(__int64 result)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 96LL);
  if ( v1 )
  {
    if ( *v1 )
    {
      result = dma_free_attrs(*(_QWORD *)(result + 8), v1[2], *v1, v1[1], 0);
      *v1 = 0;
    }
  }
  return result;
}
