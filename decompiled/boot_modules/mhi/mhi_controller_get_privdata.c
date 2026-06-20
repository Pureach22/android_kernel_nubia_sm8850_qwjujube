__int64 __fastcall mhi_controller_get_privdata(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 16);
    if ( v1 && (v2 = *(_QWORD *)(v1 + 192)) != 0 )
      return *(_QWORD *)(v2 + 56);
    else
      return 0;
  }
  return result;
}
