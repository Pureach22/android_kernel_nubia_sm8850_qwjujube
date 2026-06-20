__int64 __fastcall icnss_exit_power_save(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  ipc_log_string(icnss_ipc_log_long_context, "icnss2: Calling Exit Power Save\n");
  if ( (*(_QWORD *)(v1 + 1832) & 0x200) == 0 && (*(_QWORD *)(v1 + 1832) & 0x10000) != 0 )
    return icnss_send_smp2p(v1, 2, 0);
  else
    return 0;
}
