__int64 __fastcall wcd939x_swr_reset(__int64 a1)
{
  __int64 v1; // x8
  void (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 224);
    if ( v1 )
    {
      v2 = *(void (__fastcall **)(_QWORD))(v1 + 48);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v1 + 56);
        if ( *((_DWORD *)v2 - 1) != -1066802076 )
          __break(0x8229u);
        v2(v3);
      }
    }
  }
  return 0;
}
