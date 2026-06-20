__int64 __fastcall lim_is_valid_fils_auth_frame(__int64 a1, __int64 a2, _BYTE *a3)
{
  _BYTE *v3; // x8

  v3 = *(_BYTE **)(a2 + 9976);
  if ( !v3 )
    return 1;
  if ( *v3 )
  {
    if ( (unsigned int)qdf_mem_cmp(a3 + 736, v3 + 70, 8u) )
      return 0;
    qdf_mem_copy((void *)(*(_QWORD *)(a2 + 9976) + 758LL), a3 + 1000, 0x10u);
    *(_BYTE *)(*(_QWORD *)(a2 + 9976) + 774LL) = a3[735];
  }
  return 1;
}
