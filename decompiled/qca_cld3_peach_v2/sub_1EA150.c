__int64 __fastcall sub_1EA150(__int64 a1)
{
  __int64 v1; // x24

  if ( (v1 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1EECE0);
  return mlme_cm_disconnect_complete_ind(a1);
}
