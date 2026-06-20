__int64 __fastcall wlan_serialization_get_list_from_pdev_queue(__int64 a1, int a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8

  v3 = 104;
  v4 = 24;
  if ( !a2 )
    v3 = 0;
  v5 = a1 + v3;
  if ( a3 )
    v4 = 0;
  return v5 + v4;
}
