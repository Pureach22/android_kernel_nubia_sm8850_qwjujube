__int64 __fastcall rmnet_shs_genl_mem_sync(__int64 a1, __int64 a2)
{
  if ( !rmnet_shs_userspace_connected )
    rmnet_shs_userspace_connected = 1;
  if ( !a2 )
    return 0xFFFFFFFFLL;
  last_net = *(_QWORD *)(a2 + 40);
  last_snd_portid = *(_DWORD *)(a2 + 4);
  return 0;
}
