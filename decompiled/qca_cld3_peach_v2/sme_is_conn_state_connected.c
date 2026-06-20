__int64 __fastcall sme_is_conn_state_connected(__int64 a1, unsigned __int8 a2)
{
  return csr_is_conn_state_connected(a1, a2) & 1;
}
