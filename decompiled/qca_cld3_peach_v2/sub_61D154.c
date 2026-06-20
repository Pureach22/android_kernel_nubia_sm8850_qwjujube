__int64 __fastcall sub_61D154(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20

  if ( (v3 & 0x80000000000LL) != 0 )
    JUMPOUT(0x617590);
  return cm_check_and_prepare_roam_req(a1, a2, a3);
}
