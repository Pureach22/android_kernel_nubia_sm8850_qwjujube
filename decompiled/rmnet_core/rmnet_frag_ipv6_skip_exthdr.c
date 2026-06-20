__int64 __fastcall rmnet_frag_ipv6_skip_exthdr(__int64 a1, unsigned int a2, _BYTE *a3, _WORD *a4, _BYTE *a5)
{
  unsigned int v10; // w24
  char v11; // w8
  int v12; // w8
  unsigned __int8 *v13; // x0
  unsigned __int8 *v14; // x26
  _WORD *v15; // x0
  _WORD v17[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (unsigned __int8)*a3;
  *a4 = 0;
  *a5 = 0;
  if ( (ipv6_ext_hdr(v10) & 1) != 0 )
  {
    while ( 1 )
    {
      v18 = 0;
      if ( (unsigned __int8)v10 == 59
        || (v13 = (unsigned __int8 *)rmnet_frag_header_ptr(a1, a2, 2u, (__int64)&v18)) == nullptr )
      {
LABEL_15:
        a2 = -22;
        goto LABEL_16;
      }
      if ( (unsigned __int8)v10 == 51 )
        break;
      if ( (unsigned __int8)v10 != 44 )
      {
        v11 = 3;
        goto LABEL_4;
      }
      v14 = v13;
      v17[0] = 0;
      v15 = (_WORD *)rmnet_frag_header_ptr(a1, a2 + 2, 2u, (__int64)v17);
      if ( !v15 )
        goto LABEL_15;
      *a4 = *v15;
      *a5 = 1;
      if ( bswap32((unsigned __int16)*a4) >> 16 >= 8 )
        goto LABEL_14;
      v13 = v14;
      v12 = 8;
LABEL_5:
      LOBYTE(v10) = *v13;
      a2 += v12;
      if ( (ipv6_ext_hdr(*v13) & 1) == 0 )
        goto LABEL_14;
    }
    v11 = 2;
LABEL_4:
    v12 = (v13[1] << v11) + 8;
    goto LABEL_5;
  }
LABEL_14:
  *a3 = v10;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return a2;
}
