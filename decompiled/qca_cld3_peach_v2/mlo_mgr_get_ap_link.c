__int64 __fastcall mlo_mgr_get_ap_link(__int64 result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1360);
    if ( v1 )
      return *(_QWORD *)(v1 + 3880);
    else
      return 0;
  }
  return result;
}
