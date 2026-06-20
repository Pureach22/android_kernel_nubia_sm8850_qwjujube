__int64 __fastcall sub_16C48(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  *(_DWORD *)(a8 + 11416) = a2;
  return ufs_qcom_hook_send_tm_command();
}
