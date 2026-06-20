__int64 __fastcall sde_kms_info_reset(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 0x4000) = 0;
  return result;
}
