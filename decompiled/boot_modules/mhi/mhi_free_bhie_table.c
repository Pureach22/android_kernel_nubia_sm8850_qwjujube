__int64 __fastcall mhi_free_bhie_table(__int64 result, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v4; // x20
  unsigned int v5; // w21
  _QWORD *v6; // x22

  if ( (*(_BYTE *)(result + 612) & 1) == 0 )
  {
    v2 = (_QWORD *)*a2;
    if ( *(_DWORD *)(*a2 + 16LL) )
    {
      v4 = result;
      v5 = 0;
      v6 = (_QWORD *)(*v2 + 24LL);
      do
      {
        dma_free_attrs(*(_QWORD *)(v4 + 8), *v6, *(v6 - 3), *(v6 - 1), 64);
        v2 = (_QWORD *)*a2;
        ++v5;
        v6 += 4;
      }
      while ( v5 < *(_DWORD *)(*a2 + 16LL) );
    }
    kfree(*v2);
    result = kfree(*a2);
    *a2 = 0;
  }
  return result;
}
