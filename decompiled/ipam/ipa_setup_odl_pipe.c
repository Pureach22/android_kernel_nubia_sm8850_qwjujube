__int64 ipa_setup_odl_pipe()
{
  __int64 v0; // x8
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8

  v0 = ipa3_ctx;
  v1 = ipa3_odl_ctx;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d Setting up the odl endpoint\n", "ipa_setup_odl_pipe", 287);
      v0 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v0 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d Setting up the odl endpoint\n", "ipa_setup_odl_pipe", 287);
  }
  *(_DWORD *)(v1 + 528) = 1;
  *(_DWORD *)(v1 + 452) = 1;
  *(_WORD *)(v1 + 496) = 1;
  *(_BYTE *)(v1 + 488) = 1;
  *(_DWORD *)(v1 + 592) = -16777216;
  *(_QWORD *)(v1 + 532) = 0xF00000004LL;
  *(_QWORD *)(v1 + 544) = 0x100000000LL;
  *(_QWORD *)(v1 + 624) = 0x60000000053LL;
  *(_QWORD *)(v1 + 444) = 0x100000004LL;
  *(_QWORD *)(v1 + 640) = odl_ipa_packet_receive_notify;
  v4 = ipa3_odl_ctx;
  *(_DWORD *)(v1 + 584) = 0;
  *(_QWORD *)(v1 + 460) = 0x200000001LL;
  *(_DWORD *)(v1 + 492) = 0;
  *(_DWORD *)(v1 + 484) = 0;
  *(_QWORD *)(v1 + 656) = 0;
  *(_DWORD *)(v4 + 688) = -1;
  return ipa_setup_sys_pipe(v1 + 432, (unsigned int *)(v4 + 688));
}
