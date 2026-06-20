__int64 __fastcall slim_device_remove(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(result + 136);
  if ( v1 )
  {
    v2 = *(__int64 (**)(void))(v1 - 24);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 1375322912 )
        __break(0x8228u);
      return v2();
    }
  }
  return result;
}
