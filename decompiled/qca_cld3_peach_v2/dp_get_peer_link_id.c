__int64 __fastcall dp_get_peer_link_id(__int64 a1)
{
  __int64 v1; // x8

  if ( *(_DWORD *)(a1 + 408) == 1 )
  {
    v1 = *(_QWORD *)(a1 + 416);
    if ( v1 )
      LODWORD(v1) = *(unsigned __int8 *)(a1 + 424) + 1;
  }
  else
  {
    LODWORD(v1) = 0;
  }
  if ( (unsigned __int8)(v1 - 5) >= 0xFCu )
    return (unsigned int)v1;
  else
    return 0;
}
