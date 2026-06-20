__int64 __fastcall mhi_in_rddm(__int64 a1)
{
  __int64 v1; // x20
  __int64 v4; // x9
  __int64 v5; // x21
  void (__fastcall *v6)(__int64, __int64); // x8

  if ( !*(_QWORD *)(a1 + 160) )
    return 0;
  v1 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)mhi_get_exec_env(a1) != 3 || (unsigned int)(*(_DWORD *)(a1 + 348) - 2) > 4 )
    return 0;
  v4 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 344) = 3;
  v5 = *(_QWORD *)(v4 + 192);
  dev_err(v1 + 40, "[E][%s] RDDM event occurred!\n", "mhi_in_rddm");
  if ( v5 && *(_DWORD *)(v5 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v5 + 32), "[E][%s] RDDM event occurred!\n", "mhi_in_rddm");
  mhi_report_error(a1);
  v6 = *(void (__fastcall **)(__int64, __int64))(a1 + 480);
  if ( *((_DWORD *)v6 - 1) != 1183736653 )
    __break(0x8228u);
  v6(a1, 4);
  _wake_up(a1 + 456, 3, 0, 0);
  return 1;
}
