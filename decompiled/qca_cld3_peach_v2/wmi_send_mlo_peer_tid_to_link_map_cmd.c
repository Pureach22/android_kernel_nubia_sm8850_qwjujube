__int64 __fastcall wmi_send_mlo_peer_tid_to_link_map_cmd(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 4856LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1983057364 )
    __break(0x8228u);
  return v1();
}
