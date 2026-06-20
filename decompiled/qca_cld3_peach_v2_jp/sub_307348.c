__int64 __fastcall sub_307348(__int64 a1)
{
  if ( (a1 & 0x20000000000000LL) == 0 )
    JUMPOUT(0x30225C);
  return hdd_cm_disconnect_complete();
}
