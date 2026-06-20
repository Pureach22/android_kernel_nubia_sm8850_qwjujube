__int64 htc_log_link_user_votes()
{
  __int64 result; // x0

  if ( dword_7CF260 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF260, 1);
  if ( dword_7CF264 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF264, 2);
  if ( dword_7CF268 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF268, 3);
  if ( dword_7CF26C )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF26C, 4);
  if ( dword_7CF270 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF270, 5);
  if ( dword_7CF274 )
    return qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_7CF274, 6);
  return result;
}
