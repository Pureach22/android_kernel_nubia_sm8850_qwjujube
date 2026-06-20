bool __fastcall csr_is_conn_state_disconnected(__int64 a1, unsigned __int8 a2)
{
  if ( (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a2) & 0xFFFFFFFD) != 0 )
    return *(_DWORD *)(*(_QWORD *)(a1 + 17296) + 96LL * a2 + 4) == 0;
  else
    return !cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), a2);
}
