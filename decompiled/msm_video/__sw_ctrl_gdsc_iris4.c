__int64 __fastcall _sw_ctrl_gdsc_iris4(__int64 result)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 6552);
    if ( v1 && (v2 = *(__int64 (**)(void))(v1 + 80)) != nullptr )
    {
      if ( *((_DWORD *)v2 - 1) != -1850880742 )
        __break(0x8228u);
      return v2();
    }
    else
    {
      return 0;
    }
  }
  return result;
}
