__int64 __fastcall lim_process_assoc_cleanup(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x19
  __int64 result; // x0

  if ( (a4 & 1) != 0 && a3 && (v4 = *(_QWORD *)(a2 + 384)) != 0 )
  {
    *(_QWORD *)(v4 + 8LL * *(unsigned __int16 *)(a3 + 348)) = 0;
  }
  else if ( !a3 )
  {
    return result;
  }
  if ( *(_DWORD *)(a3 + 8) != 21 )
  {
    v5 = *(_QWORD *)(a2 + 384);
    if ( v5 )
    {
      v6 = *(unsigned __int16 *)(a3 + 348);
      v7 = *(_QWORD *)(v5 + 8 * v6);
      if ( v7 )
      {
        lim_free_assoc_req_frm_buf(*(_QWORD *)(v5 + 8 * v6));
        result = _qdf_mem_free(v7);
        *(_QWORD *)(*(_QWORD *)(a2 + 384) + 8LL * *(unsigned __int16 *)(a3 + 348)) = 0;
      }
    }
  }
  return result;
}
