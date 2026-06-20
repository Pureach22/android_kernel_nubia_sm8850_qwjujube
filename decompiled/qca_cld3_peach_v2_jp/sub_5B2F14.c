double __fastcall sub_5B2F14(__int64 a1, __int64 a2)
{
  if ( (a1 & 0x1000000000000LL) != 0 )
    JUMPOUT(0x5B61E8);
  return cm_add_roam_req_to_list(a1, a2);
}
