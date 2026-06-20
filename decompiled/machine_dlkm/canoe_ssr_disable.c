__int64 __fastcall canoe_ssr_disable(__int64 a1)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 152) )
    return snd_card_notify_user(0);
  result = __ratelimit(&canoe_ssr_disable__rs, "canoe_ssr_disable");
  if ( (_DWORD)result )
    return dev_err(a1, "%s: card is NULL\n", "canoe_ssr_disable");
  return result;
}
