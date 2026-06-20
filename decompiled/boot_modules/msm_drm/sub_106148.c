__int64 __fastcall sub_106148(__int64 a1, __int64 a2)
{
  char v2; // w26

  if ( (v2 & 4) == 0 )
    JUMPOUT(0x10AE8C);
  return sde_rm_request_hw_blk(a1, a2);
}
