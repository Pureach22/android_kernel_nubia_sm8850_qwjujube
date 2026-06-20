__int64 __fastcall adreno_create_hw_fence(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(result + 20896);
  if ( v1 )
  {
    v2 = *(__int64 (**)(void))(v1 + 32);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -353547434 )
        __break(0x8228u);
      return v2();
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
