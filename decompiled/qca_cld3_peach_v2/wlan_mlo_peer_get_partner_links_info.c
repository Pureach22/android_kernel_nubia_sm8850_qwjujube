__int64 __fastcall wlan_mlo_peer_get_partner_links_info(__int64 result, _BYTE *a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v5; // x9
  _BYTE *v6; // x8
  unsigned int v7; // w10
  _BYTE *v8; // x11
  int v9; // w12
  __int64 v10; // x9
  unsigned int v11; // w10
  _BYTE *v12; // x8
  int v13; // w11

  v2 = *(_QWORD *)(result + 784);
  *a2 = 0;
  if ( v2 )
  {
    v3 = result;
    qdf_mutex_acquire(v2 + 120);
    if ( *(_DWORD *)(v2 + 200) <= 1u )
    {
      v5 = *(_QWORD *)(v2 + 16);
      v6 = a2 + 8;
      if ( !v5 || v5 == v3 || !*(_QWORD *)(v5 + 96) )
      {
LABEL_8:
        v10 = *(_QWORD *)(v2 + 56);
        if ( v10 && v10 != v3 && *(_QWORD *)(v10 + 96) )
        {
          v11 = (unsigned __int8)*a2;
          if ( v11 <= 1 )
          {
            v12 = &v6[48 * (unsigned __int8)*a2];
            v12[6] = *(_BYTE *)(v2 + 70);
            v12[8] = *(_DWORD *)(v10 + 68) == 13;
            v13 = *(_DWORD *)(v2 + 64);
            *((_WORD *)v12 + 2) = *(_WORD *)(v2 + 68);
            *(_DWORD *)v12 = v13;
            *a2 = v11 + 1;
          }
        }
        return qdf_mutex_release(v2 + 120);
      }
      v7 = (unsigned __int8)*a2;
      if ( v7 <= 1 )
      {
        v8 = &v6[48 * (unsigned __int8)*a2];
        v8[6] = *(_BYTE *)(v2 + 30);
        v8[8] = *(_DWORD *)(v5 + 68) == 13;
        v9 = *(_DWORD *)(v2 + 24);
        *((_WORD *)v8 + 2) = *(_WORD *)(v2 + 28);
        *(_DWORD *)v8 = v9;
        *a2 = v7 + 1;
        goto LABEL_8;
      }
    }
    return qdf_mutex_release(v2 + 120);
  }
  return result;
}
