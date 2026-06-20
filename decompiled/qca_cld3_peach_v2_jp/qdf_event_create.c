__int64 __fastcall qdf_event_create(_DWORD *a1)
{
  if ( !a1 )
    return 5;
  if ( a1[8] == 305402420 )
    return 8;
  *a1 = 0;
  _init_swait_queue_head(a1 + 2, "&x->wait", &init_completion___key);
  a1[8] = 305402420;
  return 0;
}
