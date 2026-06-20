__int64 __fastcall sde_encoder_begin_commit(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x1

  v1 = *(_QWORD **)(a1 + 328);
  if ( v1 )
  {
    if ( (*(_BYTE *)(a1 + 644) & 2) != 0 )
    {
      v1 = (_QWORD *)v1[1];
      if ( v1 )
      {
        v1 = (_QWORD *)v1[314];
        if ( v1 )
          LOBYTE(v1) = v1[180] != 0;
      }
    }
    else
    {
      LOBYTE(v1) = 0;
    }
  }
  if ( ((*(_BYTE *)(a1 + 4968) | (unsigned __int8)v1) & 1) != 0 )
    v2 = 3;
  else
    v2 = 1;
  return sde_encoder_cesta_update(a1, v2);
}
