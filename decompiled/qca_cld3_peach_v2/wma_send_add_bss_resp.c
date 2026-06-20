__int64 __fastcall wma_send_add_bss_resp(__int64 a1, char a2, int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = _qdf_mem_malloc(0x10u, "wma_send_add_bss_resp", 4863);
  if ( result )
  {
    *(_BYTE *)result = a2;
    *(_DWORD *)(result + 4) = a3;
    return lim_handle_add_bss_rsp(*(_QWORD *)(a1 + 16), (unsigned __int8 *)result, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  return result;
}
