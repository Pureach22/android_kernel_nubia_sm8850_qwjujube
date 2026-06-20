__int64 __fastcall uaudio_event_ring_cleanup_free(__int64 result)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x10
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x19
  unsigned __int64 v13; // x11

  v1 = (unsigned __int64)"does not exist\n";
  v2 = *(unsigned int *)(result + 16);
  v3 = v2 >> 6;
  v4 = 1LL << v2;
  v5 = uaudio_qdev + 96;
  while ( 1 )
  {
    _X10 = (unsigned __int64 *)(v5 + 8 * v3);
    __asm { PRFM            #0x11, [X10] }
    do
      v13 = __ldxr(_X10);
    while ( __stxr(v13 & ~v4, _X10) );
    if ( *(_QWORD *)(*(_QWORD *)(v1 + 2760) + 96LL) )
      break;
    v6 = result;
    result = uaudio_iommu_unmap(0, 4096, 4096, 4096);
    v1 = **(unsigned int **)(*(_QWORD *)(v6 + 80) + 16LL);
    if ( (unsigned int)v1 < 0x20 )
    {
      xhci_sideband_remove_interrupter(uadev[11 * (unsigned int)v1 + 7]);
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: all audio devices disconnected\n",
        (const char *)&unk_B13E,
        "uaudio_event_ring_cleanup_free");
      return printk("%s%s: all audio devices disconnected\n", &unk_B8A7);
    }
    __break(0x5512u);
  }
  return result;
}
