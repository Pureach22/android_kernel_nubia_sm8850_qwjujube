__int64 __fastcall cam_cdm_stream_stop(__int64 a1, _DWORD *a2)
{
  if ( a1 )
    return cam_cdm_stream_ops_internal(a1, a2, 0);
  else
    return 4294967274LL;
}
