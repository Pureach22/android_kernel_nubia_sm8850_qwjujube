__int64 __fastcall dp_peer_update_inactive_time(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v13; // x1
  __int64 v14; // x8
  __int64 v15; // x19

  if ( a2 == 60 )
  {
    v11 = result;
    result = dp_peer_get_ref_by_id_0(*(_QWORD *)(result + 8), *(unsigned __int16 *)(result + 95240));
    if ( result )
    {
      if ( (*(_BYTE *)(result + 120) & 1) == 0 )
      {
        *(_DWORD *)(result + 188) = *(_DWORD *)(a3 + 76);
        v14 = v11 + 94208;
        v15 = result;
        qdf_event_set(v14 + 1040, v13);
        result = v15;
      }
      return dp_peer_unref_delete(result, 13);
    }
  }
  else if ( a2 == 61 )
  {
    *(_WORD *)(result + 95240) = *(_DWORD *)(a3 + 8);
  }
  else
  {
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Invalid tag_type: %u",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_peer_update_inactive_time",
             a2);
  }
  return result;
}
