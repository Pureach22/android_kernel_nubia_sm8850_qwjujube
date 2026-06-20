__int64 __fastcall lim_alloc_assoc_req_frm_buf(__int64 result, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x21
  __int64 v7; // x8

  if ( result )
  {
    v4 = result;
    result = _qdf_nbuf_clone(a2);
    *(_QWORD *)(v4 + 3272) = result;
    if ( result )
    {
      v7 = *(_QWORD *)(result + 224);
      *(_DWORD *)(v4 + 3280) = a4;
      *(_QWORD *)(v4 + 3288) = v7 + a3;
      return 1;
    }
  }
  return result;
}
