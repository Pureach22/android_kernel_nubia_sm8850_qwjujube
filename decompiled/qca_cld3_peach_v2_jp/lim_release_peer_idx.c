void __fastcall lim_release_peer_idx(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 v3; // x9
  __int64 v4; // x9

  v3 = *(unsigned __int8 *)(a3 + 7249);
  --*(_WORD *)(a3 + 7250);
  if ( v3 )
    *(_BYTE *)(*(_QWORD *)(a3 + 7240) + v3) = a2;
  else
    *(_BYTE *)(a3 + 7248) = a2;
  v4 = *(_QWORD *)(a3 + 7240);
  *(_BYTE *)(a3 + 7249) = a2;
  *(_BYTE *)(v4 + a2) = 0;
}
