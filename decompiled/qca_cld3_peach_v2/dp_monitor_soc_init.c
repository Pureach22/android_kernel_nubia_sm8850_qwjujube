__int64 __fastcall dp_monitor_soc_init(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x20
  void (*v3)(void); // x8
  __int64 v4; // x19
  __int64 (__fastcall *v5)(_QWORD); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 20112);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 416);
      if ( v2 )
      {
        v3 = *(void (**)(void))(v2 + 40);
        if ( v3 )
        {
          v4 = result;
          if ( *((_DWORD *)v3 - 1) != -1941278151 )
            __break(0x8228u);
          v3();
          result = v4;
        }
        v5 = *(__int64 (__fastcall **)(_QWORD))(v2 + 48);
        if ( v5 )
        {
          if ( *((_DWORD *)v5 - 1) != -1941278151 )
            __break(0x8228u);
          return v5(result);
        }
      }
    }
  }
  return result;
}
