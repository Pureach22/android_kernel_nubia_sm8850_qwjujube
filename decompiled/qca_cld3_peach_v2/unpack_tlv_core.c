__int64 __fastcall unpack_tlv_core(unsigned __int8 *a1, unsigned int a2, unsigned int *a3, __int64 a4)
{
  unsigned int v6; // w19
  __int64 v7; // x8
  int v8; // w9
  int v9; // w10
  unsigned int v10; // w11
  unsigned int v11; // w26
  unsigned __int8 *v12; // x22
  unsigned int *v13; // x23
  unsigned int v14; // w11
  unsigned __int8 *v15; // x22
  unsigned int v16; // w26
  char v17; // w8
  unsigned __int16 v18; // w27
  int v19; // w8
  size_t v20; // x2
  int v21; // w9
  unsigned int v22; // w10
  _BYTE *v23; // x8
  int v24; // w8
  __int64 v25; // x9
  unsigned __int8 *v26; // x22
  unsigned int v27; // w26
  unsigned __int8 *v28; // x22
  unsigned int v29; // w26
  __int64 v30; // x9
  int v31; // w8
  __int64 v32; // x8
  __int64 v33; // x8
  bool v34; // cf
  _BYTE *v35; // x8
  _BYTE *v36; // x8
  void *v37; // x0
  unsigned __int8 *v38; // x1
  __int64 v39; // x23
  unsigned __int8 v40; // w9
  unsigned __int8 v41; // w9
  _BYTE *v42; // x23
  unsigned __int16 v43; // w8
  void *v44; // x2
  _BYTE *v45; // x0
  unsigned __int8 v46; // w9
  _BYTE *v47; // x8
  unsigned int v48; // w9
  _WORD n[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 n_4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v6 = 0;
  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  n_4 = 0;
  if ( a2 )
  {
    n[0] = 0;
    do
    {
      if ( a2 <= 2 )
      {
LABEL_107:
        v6 |= 0x80u;
        break;
      }
      v7 = *((unsigned __int8 *)a3 + 37);
      v8 = *a1;
      v9 = v8;
      if ( (_DWORD)v7 == 2 )
        v9 = a1[1] | (v8 << 8);
      v10 = a3[5];
      if ( v10 == 0xFFFF )
        goto LABEL_7;
      v13 = a3;
      while ( 1 )
      {
        if ( v10 == v9 )
        {
          v14 = v13[6];
          if ( !v14 || a2 >= 6 && ((a1[4] << 16) | (a1[5] << 8) | a1[6]) == v14 )
            break;
        }
        v10 = v13[15];
        v13 += 10;
        if ( v10 == 0xFFFF )
          goto LABEL_7;
      }
      if ( !v13 )
      {
LABEL_7:
        v11 = a2 - v7;
        if ( a2 < (unsigned int)v7 || v11 <= 1 )
          goto LABEL_107;
        v12 = &a1[v7];
        if ( (_DWORD)v7 == 2 )
          n[0] = bswap32(*(unsigned __int16 *)v12) >> 16;
        else
          qdf_mem_copy(n, v12, 2u);
        v13 = nullptr;
        v15 = v12 + 2;
        v16 = v11 - 2;
        v17 = 1;
      }
      else
      {
        if ( *((_BYTE *)v13 + 37) == 2 )
        {
          if ( *((_BYTE *)v13 + 39) )
          {
            n_4 = a1[1] | (unsigned __int16)((_WORD)v8 << 8);
          }
          else
          {
            v26 = a1;
            v27 = a2;
            qdf_mem_copy(&n_4, a1, 2u);
            a2 = v27;
            a1 = v26;
          }
          v24 = -2;
          v25 = 2;
        }
        else
        {
          n_4 = v8;
          v24 = -1;
          v25 = 1;
        }
        v28 = &a1[v25];
        v29 = a2 + v24;
        if ( *((_BYTE *)v13 + 38) == 2 )
        {
          if ( v29 <= 1 )
            goto LABEL_107;
          if ( *((_BYTE *)v13 + 39) )
            n[0] = bswap32(*(unsigned __int16 *)v28) >> 16;
          else
            qdf_mem_copy(n, v28, 2u);
          v31 = -2;
          v30 = 2;
        }
        else
        {
          v30 = 1;
          n[0] = *v28;
          v31 = -1;
        }
        v15 = &v28[v30];
        v16 = v29 + v31;
        if ( v13[6] )
        {
          if ( v16 <= 2 )
            goto LABEL_107;
          v16 -= 3;
          v18 = n[0] - 3;
          n[0] -= 3;
          v20 = n[0];
          if ( v16 < n[0] )
            goto LABEL_107;
          v15 += 3;
          v19 = 3;
          goto LABEL_27;
        }
        v17 = 0;
      }
      v18 = n[0];
      if ( v16 < n[0] )
        goto LABEL_107;
      if ( (v17 & 1) != 0 )
      {
        v6 |= 0x400u;
        goto LABEL_95;
      }
      v19 = 0;
      v20 = n[0];
LABEL_27:
      v21 = *((unsigned __int8 *)v13 + 38) + *((unsigned __int8 *)v13 + 37);
      v22 = v13[7] - v19;
      if ( v21 + (int)v20 < v22 || v16 < v22 - v21 )
        goto LABEL_107;
      if ( v13[8] - v19 - v21 >= (unsigned int)v20 )
      {
        switch ( *((_WORD *)v13 + 8) )
        {
          case 1:
          case 0x13:
          case 0x3A:
            v35 = (_BYTE *)(a4 + *v13);
            *v35 = 1;
            if ( v18 <= 5u )
              goto LABEL_105;
            v37 = v35 + 1;
            v38 = v15;
            v20 = 6;
            goto LABEL_94;
          case 2:
          case 4:
          case 0xD:
          case 0x16:
          case 0x18:
          case 0x1A:
          case 0x1B:
          case 0x1C:
          case 0x23:
          case 0x24:
          case 0x26:
          case 0x27:
          case 0x2A:
          case 0x2C:
          case 0x2D:
          case 0x2F:
          case 0x35:
          case 0x36:
          case 0x37:
          case 0x38:
          case 0x39:
          case 0x3B:
            v23 = (_BYTE *)(a4 + *v13);
            *v23 = 1;
            v23[1] = *v15;
            break;
          case 3:
          case 0x22:
          case 0x31:
          case 0x33:
            v36 = (_BYTE *)(a4 + *v13);
            *v36 = 1;
            if ( !v18 )
              goto LABEL_104;
            v36[1] = *v15;
            break;
          case 5:
          case 6:
          case 7:
          case 9:
          case 0x1D:
          case 0x25:
            v32 = a4 + *v13;
            *(_BYTE *)v32 = 1;
            *(_WORD *)(v32 + 2) = bswap32(*(unsigned __int16 *)v15) >> 16;
            break;
          case 8:
          case 0xE:
          case 0xF:
          case 0x1E:
            v33 = *v13;
            v34 = v18 >= 0x21u;
            goto LABEL_50;
          case 0xA:
            v39 = a4 + *v13;
            *(_BYTE *)v39 = 1;
            if ( v18 <= 1u )
              goto LABEL_103;
            qdf_mem_copy((void *)(v39 + 2), v15, 2u);
            if ( (v18 & 0xFFFE) == 2 )
              goto LABEL_103;
            v37 = (void *)(v39 + 4);
            v38 = v15 + 2;
            v20 = 2;
            goto LABEL_94;
          case 0xB:
          case 0x11:
            v39 = a4 + *v13;
            *(_BYTE *)v39 = 1;
            if ( v18 <= 2u )
              goto LABEL_103;
            qdf_mem_copy((void *)(v39 + 1), v15, 3u);
            if ( v18 == 3 )
              goto LABEL_103;
            *(_BYTE *)(v39 + 4) = v15[3];
            if ( v18 == 4 )
              goto LABEL_103;
            *(_BYTE *)(v39 + 5) = v15[4];
            break;
          case 0xC:
            v33 = *v13;
            v34 = v18 >= 0x41u;
LABEL_50:
            v35 = (_BYTE *)(a4 + v33);
            *v35 = 1;
            v35[1] = v18;
            if ( v34 )
              goto LABEL_52;
            v37 = v35 + 2;
            v38 = v15;
            goto LABEL_94;
          case 0x10:
            v35 = (_BYTE *)(a4 + *v13);
            *v35 = 1;
            if ( !v18 )
              goto LABEL_105;
            v35[1] = *v15;
            if ( v18 == 1 )
              goto LABEL_105;
            v46 = v15[1];
            v20 = (unsigned __int16)(v18 - 2);
            v35[3] = v18 - 2;
            v35[2] = v46;
            if ( (unsigned int)v20 >= 0x25 )
              goto LABEL_52;
            v37 = v35 + 4;
            v38 = v15 + 2;
            goto LABEL_94;
          case 0x12:
          case 0x2E:
          case 0x32:
          case 0x34:
            v36 = (_BYTE *)(a4 + *v13);
            *v36 = 1;
            if ( !v18 )
              goto LABEL_104;
            v36[1] = *v15;
            if ( v18 == 1 )
              goto LABEL_104;
            v36[2] = v15[1];
            break;
          case 0x14:
            v42 = (_BYTE *)(a4 + *v13);
            *v42 = 1;
            if ( v18 <= 5u )
              goto LABEL_106;
            qdf_mem_copy(v42 + 1, v15, 6u);
            if ( (v18 & 0xFFFE) == 6 )
              goto LABEL_106;
            qdf_mem_copy(v42 + 8, v15 + 6, 2u);
            if ( (v18 & 0xFFF8) == 8 )
              goto LABEL_106;
            qdf_mem_copy(v42 + 10, v15 + 8, 8u);
            v43 = v18 - 16;
            v44 = &TLVS_P2PDeviceInfo;
            v45 = v15 + 16;
            goto LABEL_90;
          case 0x15:
            v47 = (_BYTE *)(a4 + *v13);
            *v47 = 1;
            v47[1] = v18;
            qdf_mem_copy(v47 + 2, v15, v20);
            break;
          case 0x17:
          case 0x19:
            v39 = a4 + *v13;
            *(_BYTE *)v39 = 1;
            if ( v18 <= 1u )
              goto LABEL_103;
            *(_WORD *)(v39 + 2) = bswap32(*(unsigned __int16 *)v15) >> 16;
            if ( (unsigned __int16)(v18 - 2) <= 3u )
              goto LABEL_103;
            qdf_mem_copy((void *)(v39 + 4), v15 + 2, 4u);
            if ( (v18 & 0xFFFE) == 6 )
              goto LABEL_103;
            *(_WORD *)(v39 + 8) = bswap32(*((unsigned __int16 *)v15 + 3)) >> 16;
            break;
          case 0x1F:
          case 0x20:
            v35 = (_BYTE *)(a4 + *v13);
            *v35 = 1;
            if ( v18 <= 0xFu )
              goto LABEL_105;
            v37 = v35 + 1;
            v38 = v15;
            v20 = 16;
            goto LABEL_94;
          case 0x21:
            v42 = (_BYTE *)(a4 + *v13);
            *v42 = 1;
            if ( v18 <= 2u )
            {
LABEL_106:
              *v42 = 0;
              v6 |= 4u;
            }
            else
            {
              qdf_mem_copy(v42 + 1, v15, 3u);
              v43 = v18 - 3;
              v44 = &TLVS_VendorExtension;
              v45 = v15 + 3;
LABEL_90:
              v6 |= unpack_tlv_core(v45, v43, v44, v42);
            }
            break;
          case 0x28:
            v39 = a4 + *v13;
            *(_BYTE *)v39 = 1;
            if ( v18 )
            {
              *(_BYTE *)(v39 + 1) = *v15;
              if ( v18 > 8u )
              {
                qdf_mem_copy((void *)(v39 + 4), v15 + 1, 4u);
                v37 = (void *)(v39 + 8);
                v38 = v15 + 5;
                v20 = 4;
                goto LABEL_94;
              }
            }
LABEL_103:
            *(_BYTE *)v39 = 0;
            v6 |= 4u;
            break;
          case 0x29:
            v35 = (_BYTE *)(a4 + *v13);
            *v35 = 1;
            if ( !v18 )
              goto LABEL_105;
            v40 = *v15;
            v20 = (unsigned __int16)(v18 - 1);
            v35[2] = v18 - 1;
            v35[1] = v40;
            if ( (unsigned int)v20 >= 5 )
              goto LABEL_52;
            goto LABEL_75;
          case 0x2B:
            v36 = (_BYTE *)(a4 + *v13);
            *v36 = 1;
            if ( !v18 || (v36[1] = *v15, v18 == 1) || (v36[2] = v15[1], v18 == 2) )
            {
LABEL_104:
              *v36 = 0;
              v6 |= 4u;
            }
            else
            {
              v36[3] = v15[2];
            }
            break;
          case 0x30:
            v35 = (_BYTE *)(a4 + *v13);
            *v35 = 1;
            if ( v18 )
            {
              v41 = *v15;
              v20 = (unsigned __int16)(v18 - 1);
              v35[2] = v18 - 1;
              v35[1] = v41;
              if ( (unsigned int)v20 >= 0xFF )
              {
LABEL_52:
                *v35 = 0;
                v6 |= 8u;
              }
              else
              {
LABEL_75:
                v37 = v35 + 3;
                v38 = v15 + 1;
LABEL_94:
                qdf_mem_copy(v37, v38, v20);
              }
            }
            else
            {
LABEL_105:
              *v35 = 0;
              v6 |= 4u;
            }
            break;
          default:
            v6 = 268435457;
            goto LABEL_117;
        }
      }
      else
      {
        v6 |= 0x200u;
      }
LABEL_95:
      a2 = v16 - n[0];
      if ( v16 < n[0] )
      {
        v6 |= 0x800u;
        break;
      }
      a1 = &v15[n[0]];
    }
    while ( v16 != n[0] );
  }
  v48 = a3[5];
  while ( v48 != 0xFFFF )
  {
    if ( *((_BYTE *)a3 + 36) )
    {
      if ( !*(_BYTE *)(a4 + *a3 + a3[1]) )
        v6 |= 0x1000u;
    }
    v48 = a3[15];
    a3 += 10;
  }
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return v6;
}
