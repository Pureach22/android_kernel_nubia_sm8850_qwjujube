__int64 __fastcall lim_delete_pre_auth_list(__int64 result)
{
  __int64 *v1; // x21
  __int64 i; // x19
  char v3; // w8
  int v4; // w9
  __int64 *v5; // x22
  __int64 v6; // x20

  v1 = *(__int64 **)(result + 11424);
  for ( i = result; v1; --*(_DWORD *)(i + 11404) )
  {
    v3 = *((_BYTE *)v1 + 278);
    v4 = *((_DWORD *)v1 + 4);
    v5 = v1;
    v1 = (__int64 *)*v1;
    *((_BYTE *)v5 + 278) = v3 | 4;
    if ( v4 == 3 && *((_BYTE *)v5 + 560) == 1 )
    {
      v6 = v5[71];
      lim_free_assoc_req_frm_buf(v6);
      _qdf_mem_free(v6);
      v5[71] = 0;
      *((_BYTE *)v5 + 560) = 0;
    }
    qdf_trace(53, 0xEu, 255, 7);
    result = tx_timer_deactivate(v5 + 35);
  }
  *(_QWORD *)(i + 11424) = 0;
  return result;
}
