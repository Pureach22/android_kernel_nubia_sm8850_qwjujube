void __fastcall qcom_check_ssr_status(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 968)
    && *(_DWORD *)(a2 + 972) != 2
    && (qcom_device_shutdown_in_progress & 1) == 0
    && (unsigned int)(system_state - 4) > 2 )
  {
    panic("Panicking, remoteproc %s failed to recover!\n", *(const char **)(a2 + 24));
  }
}
