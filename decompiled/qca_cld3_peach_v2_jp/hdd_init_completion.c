__int64 __fastcall hdd_init_completion(_DWORD *a1)
{
  a1[436] = 0;
  _init_swait_queue_head(a1 + 438, "&x->wait", &init_completion___key_1);
  a1[444] = 0;
  _init_swait_queue_head(a1 + 446, "&x->wait", &init_completion___key_1);
  a1[13016] = 0;
  return _init_swait_queue_head(a1 + 13018, "&x->wait", &init_completion___key_1);
}
