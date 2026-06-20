__int64 __fastcall hdd_unregister_notifiers(_QWORD *a1)
{
  osif_dp_nud_unregister_netevent_notifier(*a1);
  unregister_inet6addr_notifier(a1 + 143);
  return unregister_inetaddr_notifier(a1 + 147);
}
