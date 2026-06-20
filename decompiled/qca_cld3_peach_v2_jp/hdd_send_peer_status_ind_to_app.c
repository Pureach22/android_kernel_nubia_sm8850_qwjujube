__int64 __fastcall hdd_send_peer_status_ind_to_app(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int128 *a5)
{
  int v5; // w9
  __int64 v6; // x8
  int v7; // w9
  int v8; // w9
  int v9; // w9
  __int64 result; // x0
  __int128 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  int v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  v11 = 0u;
  if ( a5 )
  {
    v5 = *((_DWORD *)a5 + 2);
    *(_QWORD *)((char *)&v11 + 4) = *(_QWORD *)a5;
    v6 = *(_QWORD *)((char *)a5 + 12);
    HIDWORD(v11) = v5;
    v7 = *((_DWORD *)a5 + 5);
    v12 = v6;
    LOBYTE(v6) = *((_BYTE *)a5 + 24);
    LODWORD(v13) = v7;
    v8 = *((_DWORD *)a5 + 7);
    BYTE4(v13) = v6;
    LOBYTE(v6) = *((_BYTE *)a5 + 32);
    LODWORD(v14) = v8;
    v9 = *((_DWORD *)a5 + 9);
    a5 = &v11;
    BYTE4(v14) = v6;
    v15 = v9;
  }
  result = os_if_wifi_pos_send_peer_status(a1, a2, a3, a4, a5, 3);
  _ReadStatusReg(SP_EL0);
  return result;
}
