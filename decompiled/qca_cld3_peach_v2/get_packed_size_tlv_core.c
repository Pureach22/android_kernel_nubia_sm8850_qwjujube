__int64 __fastcall get_packed_size_tlv_core(__int64 a1, int *a2, unsigned int *a3)
{
  unsigned int v3; // w8
  _BYTE *v5; // x9
  int v6; // w10
  unsigned int v7; // w9
  int v8; // w9
  __int64 v9; // x9
  _BYTE *v10; // x9
  _BYTE *v11; // x9
  __int64 v12; // x22
  unsigned int *v13; // x23
  int *v14; // x19
  unsigned int packed_size_tlv_core; // w0
  __int64 v16; // x9
  unsigned int *v17; // x23
  int *v18; // x19
  unsigned int v19; // w0

  if ( a3[5] == 0xFFFF )
  {
    return 0;
  }
  else
  {
    v3 = 0;
    do
    {
      if ( *(_BYTE *)(a1 + *a3 + a3[1]) )
      {
        v8 = *((unsigned __int8 *)a3 + 38) + *((unsigned __int8 *)a3 + 37) + *a2;
        *a2 = v8;
        if ( a3[6] )
          *a2 = v8 + 3;
        switch ( *((_WORD *)a3 + 8) )
        {
          case 1:
          case 0x13:
          case 0x3A:
            v9 = *a3;
            v6 = 6;
            goto LABEL_29;
          case 2:
          case 3:
          case 4:
          case 0xD:
          case 0x16:
          case 0x18:
          case 0x1A:
          case 0x1B:
          case 0x1C:
          case 0x22:
          case 0x23:
          case 0x24:
          case 0x26:
          case 0x27:
          case 0x2A:
          case 0x2C:
          case 0x2D:
          case 0x2F:
          case 0x31:
          case 0x33:
          case 0x35:
          case 0x36:
          case 0x37:
          case 0x38:
          case 0x39:
          case 0x3B:
            v9 = *a3;
            v6 = 1;
            goto LABEL_29;
          case 5:
          case 6:
          case 7:
          case 9:
          case 0x12:
          case 0x1D:
          case 0x25:
          case 0x2E:
          case 0x32:
          case 0x34:
            v9 = *a3;
            v6 = 2;
            goto LABEL_29;
          case 8:
          case 0xC:
          case 0xE:
          case 0xF:
          case 0x15:
          case 0x1E:
            v5 = (_BYTE *)(a1 + *a3);
            v6 = (unsigned __int8)v5[1];
            if ( !*v5 )
              break;
            goto LABEL_6;
          case 0xA:
            v9 = *a3;
            v6 = 4;
            goto LABEL_29;
          case 0xB:
          case 0x11:
            v9 = *a3;
            v6 = 5;
            goto LABEL_29;
          case 0x10:
            v11 = (_BYTE *)(a1 + *a3);
            v6 = (unsigned __int8)v11[3] + 2;
            if ( !*v11 )
              break;
            goto LABEL_6;
          case 0x14:
            v12 = a1;
            v13 = a3;
            v14 = a2;
            packed_size_tlv_core = get_packed_size_tlv_core(a1 + *a3, a2, &TLVS_P2PDeviceInfo);
            v16 = *v13;
            a3 = v13;
            a2 = v14;
            v3 = packed_size_tlv_core;
            a1 = v12;
            v6 = 16;
            goto LABEL_26;
          case 0x17:
          case 0x19:
            v9 = *a3;
            v6 = 8;
            goto LABEL_29;
          case 0x1F:
          case 0x20:
            v9 = *a3;
            v6 = 16;
            goto LABEL_29;
          case 0x21:
            v12 = a1;
            v17 = a3;
            v18 = a2;
            v19 = get_packed_size_tlv_core(a1 + *a3, a2, &TLVS_VendorExtension);
            v16 = *v17;
            a3 = v17;
            a2 = v18;
            v3 = v19;
            a1 = v12;
            v6 = 3;
LABEL_26:
            if ( !*(_BYTE *)(v12 + v16) )
              break;
            goto LABEL_6;
          case 0x28:
            v9 = *a3;
            v6 = 9;
            goto LABEL_29;
          case 0x29:
          case 0x30:
            v10 = (_BYTE *)(a1 + *a3);
            v6 = (unsigned __int8)v10[2] + 1;
            if ( !*v10 )
              break;
            goto LABEL_6;
          case 0x2B:
            v9 = *a3;
            v6 = 3;
LABEL_29:
            if ( *(_BYTE *)(a1 + v9) )
LABEL_6:
              *a2 += v6;
            break;
          default:
            return 268435457;
        }
      }
      v7 = a3[15];
      a3 += 10;
    }
    while ( v7 != 0xFFFF );
  }
  return v3;
}
