__int64 __fastcall dp_direct_link_handle_lpass_ssr_notif(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x8

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 1472) + 24LL);
  if ( !v1 )
    return 0;
  v2 = *(_DWORD **)(v1 + 208);
  if ( !v2 || *v2 )
    return 0;
  _qdf_trigger_self_recovery();
  return 0;
}
