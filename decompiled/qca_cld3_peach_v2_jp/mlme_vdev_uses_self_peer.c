bool __fastcall mlme_vdev_uses_self_peer(int a1, int a2)
{
  bool v3; // zf
  _BOOL8 result; // x0

  v3 = a1 == 6;
  result = 1;
  if ( !v3 && a1 != 4 )
    return a1 == 1 && a2 == 1;
  return result;
}
