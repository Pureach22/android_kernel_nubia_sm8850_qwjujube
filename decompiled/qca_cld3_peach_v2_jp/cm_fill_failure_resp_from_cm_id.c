__int64 __fastcall cm_fill_failure_resp_from_cm_id(__int64 a1, __int64 a2, int a3, int a4)
{
  char v4; // w9

  *(_DWORD *)(a2 + 4) = a3;
  *(_DWORD *)(a2 + 52) = 16;
  v4 = *(_BYTE *)(*(_QWORD *)a1 + 104LL);
  *(_DWORD *)(a2 + 56) = a4;
  *(_BYTE *)a2 = v4;
  return cm_fill_bss_info_in_connect_rsp_by_cm_id();
}
