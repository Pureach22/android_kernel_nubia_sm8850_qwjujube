__int64 htc_log_link_user_votes()
{
  __int64 result; // x0

  if ( dword_716830 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_716830, 1);
  if ( dword_716834 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_716834, 2);
  if ( dword_716838 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_716838, 3);
  if ( dword_71683C )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_71683C, 4);
  if ( dword_716840 )
    result = qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_716840, 5);
  if ( dword_716844 )
    return qdf_trace_msg(62, 4, "Link vote %d user id: %d", dword_716844, 6);
  return result;
}
