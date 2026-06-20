__int64 __fastcall sme_get_sap_vdev_type_nss(__int64 result, _BYTE *a2, int a3)
{
  __int64 v3; // x8

  v3 = 21513;
  if ( a3 == 2 )
    v3 = 21523;
  *a2 = *(_BYTE *)(result + v3);
  return result;
}
