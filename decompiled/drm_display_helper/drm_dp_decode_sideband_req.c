__int64 __fastcall drm_dp_decode_sideband_req(_BYTE *a1, __int64 a2)
{
  int v4; // w8
  int v5; // w8
  int v6; // w8
  __int64 v7; // x0
  int v8; // w8
  int v9; // w9
  __int16 v10; // w9
  __int64 v11; // x9
  __int64 v13; // x0
  bool v14; // zf
  unsigned __int64 v15; // x21
  __int64 v16; // x22
  int v17; // w8
  int v18; // w25
  __int64 v19; // x0
  int v20; // w8
  int v21; // w8
  int v22; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v24; // x22

  v4 = *a1 & 0x7F;
  *(_BYTE *)a2 = v4;
  if ( v4 > 33 )
  {
    if ( v4 <= 35 )
    {
      if ( v4 != 34 )
      {
        *(_BYTE *)(a2 + 8) = a1[1] >> 4;
        *(_BYTE *)(a2 + 9) = a1[2] & 0x7F;
        *(_BYTE *)(a2 + 10) = a1[3];
        v13 = kmemdup_noprof(a1 + 4, *(unsigned __int8 *)(a2 + 10), 3264);
        *(_QWORD *)(a2 + 16) = v13;
        if ( !v13 )
          return 4294967284LL;
        return 0;
      }
      v14 = (a1[1] & 3) == 0;
      *(_BYTE *)(a2 + 8) = a1[1] & 3;
      *(_BYTE *)(a2 + 9) = a1[1] >> 4;
      if ( v14 )
      {
        v17 = 1;
LABEL_44:
        *(_BYTE *)(a2 + 112) = a1[v17 + 1] & 0x7F;
        *(_BYTE *)(a2 + 113) = a1[v17 + 2];
        return 0;
      }
      v15 = 0;
      v16 = a2 + 16;
      v17 = 1;
      _ReadStatusReg(SP_EL0);
      while ( v15 != 5 )
      {
        *(_BYTE *)v16 = a1[v17 + 1] & 0x7F;
        *(_BYTE *)(v16 + 1) = a1[v17 + 2];
        v18 = v17 + 3;
        v19 = kmemdup_noprof(&a1[v17 + 3], *(unsigned __int8 *)(v16 + 1), 3264);
        *(_QWORD *)(v16 + 8) = v19;
        if ( !v19 )
        {
          if ( *(_BYTE *)(a2 + 8) )
          {
            kfree(*(_QWORD *)(a2 + 24));
            if ( *(unsigned __int8 *)(a2 + 8) > 1u )
            {
              kfree(*(_QWORD *)(a2 + 48));
              if ( *(unsigned __int8 *)(a2 + 8) >= 3u )
              {
                kfree(*(_QWORD *)(a2 + 72));
                if ( *(unsigned __int8 *)(a2 + 8) >= 4u )
                {
                  kfree(*(_QWORD *)(a2 + 96));
                  if ( *(unsigned __int8 *)(a2 + 8) >= 5u )
                  {
                    kfree(*(_QWORD *)(a2 + 120));
                    if ( *(unsigned __int8 *)(a2 + 8) > 5u )
                      break;
                  }
                }
              }
            }
          }
          return 4294967284LL;
        }
        ++v15;
        v17 = v18 + *(unsigned __int8 *)(v16 + 1);
        *(_BYTE *)(v16 + 16) = (a1[v17] & 0x20) != 0;
        *(_BYTE *)(v16 + 17) = a1[v17] & 0xF;
        v16 += 24;
        if ( v15 >= *(unsigned __int8 *)(a2 + 8) )
          goto LABEL_44;
      }
LABEL_45:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &drm_dp_decode_sideband_req__alloc_tag;
      v7 = kmemdup_noprof(a1 + 5, *(unsigned __int8 *)(a2 + 16), 3264);
      *(_QWORD *)(StatusReg + 80) = v24;
LABEL_7:
      *(_QWORD *)(a2 + 24) = v7;
      if ( !v7 )
        return 4294967284LL;
      return 0;
    }
    if ( (unsigned int)(v4 - 36) >= 2 )
    {
      if ( v4 == 56 )
      {
        *(_BYTE *)(a2 + 8) = a1[1];
        *(_BYTE *)(a2 + 9) = a1[2];
        *(_BYTE *)(a2 + 10) = a1[3];
        *(_BYTE *)(a2 + 11) = a1[4];
        *(_BYTE *)(a2 + 12) = a1[5];
        *(_BYTE *)(a2 + 13) = a1[6];
        *(_BYTE *)(a2 + 14) = a1[7];
        *(_BYTE *)(a2 + 15) = a1[8];
        *(_BYTE *)(a2 + 16) = a1[9] & 3;
        *(_BYTE *)(a2 + 17) = (a1[9] & 4) != 0;
        *(_BYTE *)(a2 + 18) = (a1[9] >> 3) & 3;
        *(_BYTE *)(a2 + 19) = (a1[9] & 0x20) != 0;
      }
      return 0;
    }
LABEL_22:
    *(_BYTE *)(a2 + 8) = a1[1] >> 4;
    return 0;
  }
  if ( v4 <= 17 )
  {
    if ( v4 != 16 )
    {
      if ( v4 != 17 )
        return 0;
      v8 = a1[1] & 0xF;
      *(_BYTE *)(a2 + 9) = v8;
      *(_BYTE *)(a2 + 8) = a1[1] >> 4;
      v9 = (char)a1[2];
      if ( v9 < 0 )
      {
        __break(0x800u);
        LOBYTE(v9) = a1[2];
        v8 = *(unsigned __int8 *)(a2 + 9);
      }
      *(_BYTE *)(a2 + 10) = v9 & 0x7F;
      v10 = (unsigned __int8)a1[3];
      *(_WORD *)(a2 + 12) = v10 << 8;
      *(_WORD *)(a2 + 12) = (unsigned __int8)a1[4] | (unsigned __int16)(v10 << 8);
      if ( !v8 )
        return 0;
      v11 = 0;
      while ( v11 != 16 )
      {
        *(_BYTE *)(a2 + 14 + v11) = ((unsigned __int8)a1[((unsigned int)v11 >> 1) + 5] >> (~(4 * v11) & 4)) & 0xF;
        if ( v8 == ++v11 )
          return 0;
      }
      goto LABEL_45;
    }
    goto LABEL_22;
  }
  switch ( v4 )
  {
    case 18:
      *(_BYTE *)(a2 + 8) = a1[1] >> 4;
      v20 = (char)a1[2];
      if ( v20 < 0 )
      {
        __break(0x800u);
        LOBYTE(v20) = a1[2];
      }
      *(_BYTE *)(a2 + 9) = v20 & 0x7F;
      return 0;
    case 32:
      *(_BYTE *)(a2 + 8) = a1[1] >> 4;
      v21 = (a1[1] & 0xF) << 16;
      *(_DWORD *)(a2 + 12) = v21;
      v22 = v21 | ((unsigned __int8)a1[2] << 8);
      *(_DWORD *)(a2 + 12) = v22;
      *(_DWORD *)(a2 + 12) = v22 | (unsigned __int8)a1[3];
      *(_BYTE *)(a2 + 16) = a1[4];
      return 0;
    case 33:
      *(_BYTE *)(a2 + 8) = a1[1] >> 4;
      v5 = (a1[1] & 0xF) << 16;
      *(_DWORD *)(a2 + 12) = v5;
      v6 = v5 | ((unsigned __int8)a1[2] << 8);
      *(_DWORD *)(a2 + 12) = v6;
      *(_DWORD *)(a2 + 12) = v6 | (unsigned __int8)a1[3];
      *(_BYTE *)(a2 + 16) = a1[4];
      v7 = kmemdup_noprof(a1 + 5, *(unsigned __int8 *)(a2 + 16), 3264);
      goto LABEL_7;
    default:
      return 0;
  }
}
