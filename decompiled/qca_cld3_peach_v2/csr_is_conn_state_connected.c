bool __fastcall csr_is_conn_state_connected(__int64 a1, unsigned int a2)
{
  if ( cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), a2) )
    return 1;
  if ( a2 <= 5 )
    return *(_DWORD *)(*(_QWORD *)(a1 + 17296) + 96LL * a2 + 4) == 2;
  return 0;
}
