__int64 __fastcall fastrpc_mmap(__int64 a1, _QWORD *a2)
{
  return dma_mmap_attrs(
           *(_QWORD *)(*(_QWORD *)(a1 + 112) + 32LL),
           a2,
           *(_QWORD *)(*(_QWORD *)(a1 + 112) + 48LL),
           *(_QWORD *)(*(_QWORD *)(a1 + 112) + 64LL)
         & ~(-1LL << *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 112) + 40LL) + 140LL)),
           a2[1] - *a2,
           0);
}
