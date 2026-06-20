__int64 __fastcall sub_1EA348(__int64 a1, __int64 a2)
{
  __int64 v2; // x24

  if ( (v2 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1EEED8);
  return mlme_cm_osif_disconnect_complete(a1, a2);
}
