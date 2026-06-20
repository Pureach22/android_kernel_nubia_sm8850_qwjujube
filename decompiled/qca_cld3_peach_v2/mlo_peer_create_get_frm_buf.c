__int64 __fastcall mlo_peer_create_get_frm_buf(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8

  if ( !a3 )
    return 16;
  v4 = _qdf_nbuf_clone(a3);
  *(_QWORD *)(a2 + 24) = v4;
  return 2 * (unsigned int)(v4 == 0);
}
