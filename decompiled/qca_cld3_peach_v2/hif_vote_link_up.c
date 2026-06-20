__int64 __fastcall hif_vote_link_up(__int64 a1)
{
  int v2; // w4
  __int64 result; // x0

  v2 = *(_DWORD *)(a1 + 712) + 1;
  *(_DWORD *)(a1 + 712) = v2;
  result = qdf_trace_msg(61, 5, "%s: Up_linkstate_vote %d", "hif_vote_link_up", v2);
  if ( *(_DWORD *)(a1 + 712) == 1 )
    return hif_bus_prevent_linkdown(a1);
  return result;
}
