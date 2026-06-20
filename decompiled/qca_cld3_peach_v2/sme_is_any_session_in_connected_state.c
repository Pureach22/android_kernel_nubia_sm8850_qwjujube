__int64 __fastcall sme_is_any_session_in_connected_state(__int64 a1)
{
  char is_any_session_in_connect_state; // w20

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    is_any_session_in_connect_state = 0;
  }
  else
  {
    is_any_session_in_connect_state = csr_is_any_session_in_connect_state(a1);
    qdf_mutex_release(a1 + 12848);
  }
  return is_any_session_in_connect_state & 1;
}
