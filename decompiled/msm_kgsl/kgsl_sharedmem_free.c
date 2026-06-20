__int64 __fastcall kgsl_sharedmem_free(__int64 result)
{
  __int64 v1; // x8
  void (*v2)(void); // x9
  __int64 v3; // x19
  __int64 (__fastcall *v4)(_QWORD); // x8

  if ( result )
  {
    if ( *(_QWORD *)(result + 40) )
    {
      v1 = *(_QWORD *)(result + 64);
      if ( v1 )
      {
        v2 = *(void (**)(void))(v1 + 40);
        if ( v2 )
        {
          v3 = result;
          if ( *((_DWORD *)v2 - 1) != 1555154090 )
            __break(0x8229u);
          v2();
          v1 = *(_QWORD *)(v3 + 64);
          result = v3;
        }
        v4 = *(__int64 (__fastcall **)(_QWORD))(v1 + 16);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != 1555154090 )
            __break(0x8228u);
          return v4(result);
        }
      }
    }
  }
  return result;
}
