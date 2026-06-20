__int64 __fastcall csr_is_all_session_disconnected(__int64 a1)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  char v4; // w22
  bool v5; // cc
  __int64 v6; // x8

  v2 = 0;
  v3 = 0;
  v4 = 0;
  do
  {
    if ( a1 )
    {
      v6 = *(_QWORD *)(a1 + 17296);
      if ( v6 )
      {
        if ( *(_BYTE *)(v6 + v2 + 1) == 1 )
        {
          if ( (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), v3) & 0xFFFFFFFD) != 0 )
          {
            if ( *(_DWORD *)(*(_QWORD *)(a1 + 17296) + v2 + 4) )
              return v4 & 1;
          }
          else if ( cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), v3) )
          {
            return v4 & 1;
          }
        }
      }
    }
    v5 = v3++ > 4;
    v2 += 96;
    v4 = v5;
  }
  while ( v3 != 6 );
  return v4 & 1;
}
