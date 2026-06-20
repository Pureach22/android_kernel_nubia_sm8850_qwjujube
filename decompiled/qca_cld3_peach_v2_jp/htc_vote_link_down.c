__int64 __fastcall htc_vote_link_down(__int64 *a1, int a2)
{
  __int64 result; // x0
  unsigned int v10; // w10

  result = *a1;
  if ( result )
  {
    if ( (unsigned int)(a2 - 7) > 0xFFFFFFF9 )
    {
      result = hif_vote_link_down(result);
      _X8 = (unsigned int *)&htc_link_vote_ids[a2];
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 - 1, _X8) );
    }
    else
    {
      return qdf_trace_msg(62, 2, "invalid id: %d", a2);
    }
  }
  return result;
}
