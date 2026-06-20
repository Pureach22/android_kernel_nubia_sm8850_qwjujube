__int64 __fastcall ipa3_switch_to_intr_rx_work_func(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 368) || *(_DWORD *)(*(_QWORD *)(a1 + 1608) + 4LL) == 105 )
    return ((__int64 (*)(void))ipa_assert)();
  else
    return ipa3_handle_rx(a1 - 16);
}
