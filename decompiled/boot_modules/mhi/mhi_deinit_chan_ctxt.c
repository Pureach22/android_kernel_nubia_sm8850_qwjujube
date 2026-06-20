__int64 __fastcall mhi_deinit_chan_ctxt(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v4; // w8

  v2 = *(_QWORD *)(*(_QWORD *)(result + 264) + 8LL) + 44LL * *(unsigned int *)(a2 + 200);
  if ( *(_QWORD *)(v2 + 12) )
  {
    dma_free_attrs(*(_QWORD *)(result + 8), *(_QWORD *)(a2 + 184), *(_QWORD *)(a2 + 128), *(_QWORD *)(a2 + 104), 0);
    result = vfree(*(_QWORD *)(a2 + 40));
    *(_QWORD *)(a2 + 136) = 0;
    *(_QWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 120) = 0;
    v4 = *(_DWORD *)v2;
    *(_QWORD *)(v2 + 28) = 0;
    *(_QWORD *)(v2 + 36) = 0;
    *(_QWORD *)(v2 + 12) = 0;
    *(_QWORD *)(v2 + 20) = 0;
    *(_DWORD *)v2 = v4 & 0xFFFFFF00;
    __dmb(0xAu);
  }
  return result;
}
