__int64 __fastcall lim_free_assoc_req_frm_buf(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 3272);
    if ( result )
    {
      result = _qdf_nbuf_free(result);
      *(_QWORD *)(v1 + 3272) = 0;
      *(_QWORD *)(v1 + 3288) = 0;
      *(_DWORD *)(v1 + 3280) = 0;
    }
  }
  return result;
}
