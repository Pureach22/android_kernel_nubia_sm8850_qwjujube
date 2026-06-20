__int64 __fastcall bam_dma_xlate(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v4; // w8

  v2 = *(_QWORD *)(a2 + 48);
  if ( *(_QWORD *)(v2 + 520) )
    ipc_log_string(*(_QWORD *)(v2 + 520), "%s No of channels:%d\n", "bam_dma_xlate", *(_DWORD *)(v2 + 400));
  _ftrace_dbg(*(_QWORD *)(v2 - 8), "%s No of channels:%d\n");
  if ( *(_DWORD *)(a1 + 8) == 1 && (v4 = *(_DWORD *)(a1 + 12), v4 < *(_DWORD *)(v2 + 400)) )
    return dma_get_slave_channel(*(_QWORD *)(v2 + 392) + 408LL * v4);
  else
    return 0;
}
