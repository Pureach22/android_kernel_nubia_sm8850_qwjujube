__int64 __fastcall sme_is_any_session_in_middle_of_roaming(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  char v3; // w8
  unsigned int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x20
  char v7; // w8
  __int64 v8; // x8
  __int64 v9; // x19
  char v10; // w8
  __int64 v11; // x8
  __int64 v12; // x19
  char v13; // w8
  __int64 v14; // x8
  __int64 v15; // x19
  char v16; // w8
  __int64 v17; // x8

  if ( !a1 )
    return 0;
  v1 = *(_QWORD *)(a1 + 17296);
  if ( !v1 )
    return 0;
  if ( *(_BYTE *)(v1 + 1) == 1 )
  {
    v2 = a1;
    v3 = wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 0);
    a1 = v2;
    if ( (v3 & 1) != 0 )
      return 1;
  }
  v5 = *(_QWORD *)(a1 + 17296);
  if ( !v5 )
    return 0;
  if ( *(_BYTE *)(v5 + 97) != 1
    || (v6 = a1, v4 = 1, v7 = wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 1), a1 = v6, (v7 & 1) == 0) )
  {
    v8 = *(_QWORD *)(a1 + 17296);
    if ( v8 )
    {
      if ( *(_BYTE *)(v8 + 193) == 1 )
      {
        v9 = a1;
        v10 = wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 2);
        a1 = v9;
        if ( (v10 & 1) != 0 )
          return 1;
      }
      v11 = *(_QWORD *)(a1 + 17296);
      if ( v11 )
      {
        if ( *(_BYTE *)(v11 + 289) == 1 )
        {
          v12 = a1;
          v13 = wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 3);
          a1 = v12;
          if ( (v13 & 1) != 0 )
            return 1;
        }
        v14 = *(_QWORD *)(a1 + 17296);
        if ( v14 )
        {
          if ( *(_BYTE *)(v14 + 385) == 1 )
          {
            v15 = a1;
            v16 = wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 4);
            a1 = v15;
            if ( (v16 & 1) != 0 )
              return 1;
          }
          v17 = *(_QWORD *)(a1 + 17296);
          if ( v17 )
          {
            if ( *(_BYTE *)(v17 + 481) == 1 && (wlan_cm_host_roam_in_progress(*(_QWORD *)(a1 + 21624), 5) & 1) != 0 )
              return 1;
          }
        }
      }
    }
    return 0;
  }
  return v4;
}
