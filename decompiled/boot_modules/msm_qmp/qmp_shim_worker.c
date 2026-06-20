__int64 __fastcall qmp_shim_worker(__int64 a1)
{
  unsigned int v2; // w0

  v2 = qmp_send(*(_QWORD *)(*(_QWORD *)(a1 + 272) + 136LL), *(_QWORD *)(a1 - 8), *(unsigned int *)(a1 - 16));
  return mbox_chan_txdone(*(_QWORD *)(a1 - 192) + 248LL * *(unsigned int *)(a1 - 44), v2);
}
