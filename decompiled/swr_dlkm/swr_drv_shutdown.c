__int64 __fastcall swr_drv_shutdown(__int64 result)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  v1 = *(_QWORD *)(result + 136);
  if ( v1 )
  {
    if ( v1 != 72 )
    {
      v2 = *(__int64 (__fastcall **)(_QWORD))(v1 - 56);
      if ( v2 )
      {
        if ( result )
          v3 = result - 72;
        else
          v3 = 0;
        if ( *((_DWORD *)v2 - 1) != -104212543 )
          __break(0x8228u);
        return v2(v3);
      }
    }
  }
  return result;
}
