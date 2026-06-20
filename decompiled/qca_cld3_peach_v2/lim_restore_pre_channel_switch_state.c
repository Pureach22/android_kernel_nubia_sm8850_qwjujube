__int64 __fastcall lim_restore_pre_channel_switch_state(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 88) == 2 )
    *(_DWORD *)(a2 + 7196) = 0;
  return 0;
}
