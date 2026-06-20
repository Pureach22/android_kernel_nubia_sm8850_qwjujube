__int64 __fastcall mhi_controller_set_privdata(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8

  if ( result )
  {
    v2 = *(_QWORD *)(result + 16);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 192);
      if ( v3 )
        *(_QWORD *)(v3 + 56) = a2;
    }
  }
  return result;
}
