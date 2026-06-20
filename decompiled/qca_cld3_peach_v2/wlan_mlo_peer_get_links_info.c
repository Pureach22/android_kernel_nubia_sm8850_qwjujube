__int64 __fastcall wlan_mlo_peer_get_links_info(__int64 result, _BYTE *a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v5; // x9
  _BYTE *v6; // x8
  __int64 v7; // x11
  unsigned int v8; // w10
  _BYTE *v9; // x12
  char v10; // w10
  int v11; // w13
  unsigned int v12; // w13
  int v13; // w14
  int v14; // w13
  unsigned int v15; // w13
  __int16 v16; // w14
  __int16 v17; // w9
  char v18; // w11
  __int64 v19; // x10
  __int64 v20; // x12
  unsigned int v21; // w11
  _BYTE *v22; // x8
  int v23; // w13
  unsigned int v24; // w13
  int v25; // w14
  int v26; // w13
  unsigned int v27; // w13
  __int16 v28; // w14
  __int16 v29; // w9
  __int16 v30; // w9

  v2 = *(_QWORD *)(result + 784);
  *a2 = 0;
  if ( v2 )
  {
    v3 = result;
    qdf_mutex_acquire(v2 + 120);
    if ( *(_DWORD *)(v2 + 200) <= 1u )
    {
      v5 = *(_QWORD *)(v2 + 16);
      v6 = a2 + 4;
      if ( !v5 )
      {
LABEL_13:
        v19 = *(_QWORD *)(v2 + 56);
        if ( v19 )
        {
          if ( v19 != v3 && (*(_BYTE *)(v19 + 64) & 0x40) == 0 )
          {
            v20 = *(_QWORD *)(v19 + 96);
            if ( v20 )
            {
              v21 = (unsigned __int8)*a2;
              if ( v21 <= 1 )
              {
                v22 = &v6[12 * (unsigned __int8)*a2];
                *v22 = *(_BYTE *)(v20 + 168);
                v23 = *((unsigned __int16 *)v22 + 1) | 1;
                v22[1] = *(_BYTE *)(v2 + 72);
                *((_WORD *)v22 + 1) = v23;
                v24 = v23 & 0xFFFFFFFD;
                if ( *(_BYTE *)(v19 + 88) )
                  v25 = 2;
                else
                  v25 = 0;
                v26 = v25 | v24;
                *((_WORD *)v22 + 1) = v26;
                v27 = v26 & 0xFFFFFFF3 | (4 * ((((4 * *(unsigned __int8 *)(v2 + 71)) | 8u) >> 2) & 3));
                *((_WORD *)v22 + 1) = v27;
                v28 = *(_WORD *)(v2 + 626);
                *((_DWORD *)v22 + 2) = v5;
                LOWORD(v27) = v27 & 0xFFBF | ((v28 & 1) << 6);
                *((_WORD *)v22 + 1) = v27;
                v29 = v27 & 0xFDFF | (*(unsigned __int8 *)(v19 + 804) << 9);
                *((_WORD *)v22 + 1) = v29;
                v30 = v29 & 0xC3FF | ((*(_BYTE *)(v20 + 93) & 0xF) << 10);
                *a2 = v21 + 1;
                *((_WORD *)v22 + 1) = v30;
              }
            }
          }
        }
        return qdf_mutex_release(v2 + 120);
      }
      if ( v5 == v3 || (*(_BYTE *)(v5 + 64) & 0x40) != 0 || (v7 = *(_QWORD *)(v5 + 96)) == 0 )
      {
LABEL_12:
        LODWORD(v5) = 1;
        goto LABEL_13;
      }
      v8 = (unsigned __int8)*a2;
      if ( v8 <= 1 )
      {
        v9 = &v6[12 * (unsigned __int8)*a2];
        v10 = v8 + 1;
        *v9 = *(_BYTE *)(v7 + 168);
        v11 = *((unsigned __int16 *)v9 + 1) | 1;
        v9[1] = *(_BYTE *)(v2 + 32);
        *((_WORD *)v9 + 1) = v11;
        v12 = v11 & 0xFFFFFFFD;
        if ( *(_BYTE *)(v5 + 88) )
          v13 = 2;
        else
          v13 = 0;
        v14 = v13 | v12;
        *((_WORD *)v9 + 1) = v14;
        v15 = v14 & 0xFFFFFFF3 | (4 * ((((4 * *(unsigned __int8 *)(v2 + 31)) | 8u) >> 2) & 3));
        *((_WORD *)v9 + 1) = v15;
        v16 = *(_WORD *)(v2 + 626);
        *((_DWORD *)v9 + 2) = 0;
        LOWORD(v15) = v15 & 0xFFBF | ((v16 & 1) << 6);
        *((_WORD *)v9 + 1) = v15;
        v17 = v15 & 0xFDFF | (*(unsigned __int8 *)(v5 + 804) << 9);
        *((_WORD *)v9 + 1) = v17;
        v18 = *(_BYTE *)(v7 + 93);
        *a2 = v10;
        *((_WORD *)v9 + 1) = v17 & 0xC3FF | ((v18 & 0xF) << 10);
        goto LABEL_12;
      }
    }
    return qdf_mutex_release(v2 + 120);
  }
  return result;
}
