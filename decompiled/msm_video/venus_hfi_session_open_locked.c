__int64 __fastcall venus_hfi_session_open_locked(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 320);
  if ( (*(_BYTE *)(v1 + 4768) & 1) != 0 )
    return 4294967274LL;
  _sys_set_debug(v1, msm_fw_debug & 0xFFFFFFF);
  return venus_hfi_session_command_locked(
           a1,
           0x1000003u,
           3,
           0,
           0,
           1,
           (const void *)(a1 + 332),
           4u,
           (__int64)"venus_hfi_session_open_locked");
}
