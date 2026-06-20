__int64 __fastcall dp_connector_post_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 (__fastcall *v6)(_QWORD); // x8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(a2 + 16) = a1;
    *(_QWORD *)(v5 + 304) = a1;
    v6 = *(__int64 (__fastcall **)(_QWORD))(a2 + 192);
    if ( !v6 )
      goto LABEL_7;
    if ( *((_DWORD *)v6 - 1) != 1970643636 )
      __break(0x8228u);
    result = v6(a2);
    if ( !(_DWORD)result )
    {
LABEL_7:
      *(_QWORD *)(*(_QWORD *)(a2 + 8) + 1120LL) = *(_QWORD *)(a1 + 2768);
      result = dp_mst_init(a2);
      if ( *(_BYTE *)(a2 + 35) == 1 )
        *(_QWORD *)(a1 + 2912) = 0;
    }
  }
  return result;
}
