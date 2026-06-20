__int64 __fastcall syna_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x19
  void (*v3)(void); // x8

  v2 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    if ( v2 != -1096 )
    {
      v3 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v3 - 1) != -442429149 )
          __break(0x8228u);
        v3();
        __dmb(0xBu);
      }
    }
  }
  if ( *(_DWORD *)(v2 + 1128) )
    return 65;
  else
    return 0;
}
