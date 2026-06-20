__int64 __fastcall backlight_disable(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8

  if ( result )
  {
    v1 = *(_DWORD *)(result + 16);
    v2 = result;
    *(_DWORD *)(result + 8) = 4;
    *(_DWORD *)(result + 16) = v1 | 2;
    mutex_lock(result + 24);
    v3 = *(_QWORD *)(v2 + 120);
    if ( v3 )
    {
      v4 = *(void (__fastcall **)(_QWORD))(v3 + 8);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1345616862 )
          __break(0x8228u);
        v4(v2);
      }
    }
    return mutex_unlock(v2 + 24);
  }
  return result;
}
