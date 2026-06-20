bool __fastcall lim_create_peer_idxpool(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // x0

  *(_WORD *)(a1 + 7250) = 0;
  v3 = _qdf_mem_malloc(a2, "lim_create_peer_idxpool_legacy", 101);
  *(_QWORD *)(a1 + 7240) = v3;
  if ( v3 )
    *(_WORD *)(a1 + 7248) = 0;
  return v3 != 0;
}
