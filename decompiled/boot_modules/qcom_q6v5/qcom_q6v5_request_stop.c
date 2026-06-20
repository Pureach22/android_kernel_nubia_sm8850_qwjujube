__int64 __fastcall qcom_q6v5_request_stop(__int64 a1, __int64 a2)
{
  char v3; // w8
  __int64 result; // x0
  int v5; // w0
  int v6; // w9
  __int64 v7; // x8
  int v8; // w19

  *(_BYTE *)(a1 + 284) = 0;
  v3 = qcom_sysmon_shutdown_acked(a2);
  result = 0;
  if ( (v3 & 1) == 0 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 972LL) == 2 )
    {
      qcom_smem_state_update_bits(
        *(_QWORD *)(a1 + 16),
        1LL << *(_DWORD *)(a1 + 56),
        (unsigned int)(1LL << *(_DWORD *)(a1 + 56)));
      v5 = wait_for_completion_timeout(a1 + 176, 1250);
      v6 = *(_DWORD *)(a1 + 56);
      v7 = *(_QWORD *)(a1 + 16);
      v8 = v5;
      qcom_smem_state_update_bits(v7, 1LL << v6, 0);
      if ( v8 )
        return 0;
      else
        return 4294967186LL;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
