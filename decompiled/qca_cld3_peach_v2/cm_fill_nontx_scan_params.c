__int64 __fastcall cm_fill_nontx_scan_params(__int64 a1, int *a2, int a3, unsigned int a4)
{
  int v8; // w10
  __int64 v9; // x8
  __int64 v10; // x9
  unsigned int v11; // w11
  __int64 v12; // x15
  int v13; // w16
  int v14; // w15
  __int16 v16; // w12
  __int64 v17; // x9
  __int64 v18; // x11
  int v19; // w8
  unsigned int v20; // w10
  unsigned int *v21; // x8
  __int64 result; // x0
  __int64 v23; // x9
  unsigned __int8 v24; // w13
  int *v25; // x10
  int v26; // w14
  int v27; // w10
  int v29; // w12
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x8

  if ( (wlan_reg_is_6ghz_chan_freq(a4) & 1) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 1240);
    v9 = (unsigned __int8)v8;
    if ( (unsigned __int8)v8 <= 9u )
    {
      v10 = a1 + 1348;
      if ( (_BYTE)v8 )
      {
        v11 = 0;
        while ( 1 )
        {
          v12 = v10 + 12LL * v11;
          v13 = *(_DWORD *)(v12 + 4);
          v14 = *(unsigned __int16 *)(v12 + 8);
          if ( *a2 == v13 && *((unsigned __int16 *)a2 + 2) == v14 )
            return 6;
          if ( ++v11 >= (unsigned __int8)v8 )
          {
            v8 = *(_DWORD *)(a1 + 1240);
            break;
          }
        }
      }
      v16 = *((_WORD *)a2 + 2);
      v17 = v10 + 12LL * (unsigned __int8)*(_DWORD *)(a1 + 1240);
      v18 = a1 + 8 * v9;
      v19 = *a2;
      *(_DWORD *)(a1 + 1240) = v8 + 1;
      v20 = *(_DWORD *)(a1 + 1236);
      *(_DWORD *)(v18 + 1272) = a3;
      *(_WORD *)(v17 + 8) = v16;
      *(_DWORD *)v17 = a4 << 16;
      *(_DWORD *)(v17 + 4) = v19;
      v21 = (unsigned int *)(a1 + 1236);
      *(_DWORD *)(v18 + 1268) = a4 << 16;
LABEL_22:
      v31 = *(unsigned __int8 *)(a1 + 4);
      *v21 = v20 + 1;
      if ( (_DWORD)v31 )
      {
        v32 = 0;
        while ( 1 )
        {
          if ( v32 == 1224 )
            goto LABEL_28;
          if ( *(_DWORD *)(a1 + 8 + v32) == a4 )
            return 0;
          v32 += 12;
          if ( 12 * v31 == v32 )
          {
            *(_BYTE *)(a1 + 4) = v31 + 1;
            if ( (unsigned int)v31 <= 0x65 )
              goto LABEL_30;
LABEL_28:
            __break(0x5512u);
            goto LABEL_29;
          }
        }
      }
      else
      {
LABEL_29:
        *(_BYTE *)(a1 + 4) = 1;
LABEL_30:
        *(_DWORD *)(a1 + 12LL * (unsigned int)v31 + 8) = a4;
        return 0;
      }
    }
    return 1;
  }
  v20 = *(_DWORD *)(a1 + 1232);
  if ( v20 > 3 )
    return 1;
  v23 = a1 + 1244;
  v21 = (unsigned int *)(a1 + 1232);
  if ( !v20 )
  {
LABEL_21:
    v29 = *a2;
    v30 = v23 + 6LL * v20;
    *(_WORD *)(v30 + 4) = *((_WORD *)a2 + 2);
    *(_DWORD *)v30 = v29;
    goto LABEL_22;
  }
  v24 = 0;
  while ( 1 )
  {
    result = 6;
    v25 = (int *)(v23 + 6LL * v24);
    v26 = *v25;
    v27 = *((unsigned __int16 *)v25 + 2);
    if ( *a2 == v26 && *((unsigned __int16 *)a2 + 2) == v27 )
      return result;
    v20 = *v21;
    if ( *v21 <= ++v24 )
      goto LABEL_21;
  }
}
