__int64 __fastcall p2p_go_start_bearer_switch_requester_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return qdf_event_set(a6 + 792, a2);
}
