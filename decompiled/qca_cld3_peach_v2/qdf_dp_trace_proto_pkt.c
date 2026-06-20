__int64 __fastcall qdf_dp_trace_proto_pkt(
        __int64 result,
        int *a2,
        int *a3,
        char a4,
        unsigned int a5,
        char a6,
        __int64 *a7)
{
  int v7; // w8
  __int16 v8; // w9
  int v9; // w10
  __int64 v10; // x9
  int v11; // w8
  int v12; // [xsp+Ch] [xbp-24h] BYREF
  __int16 v13; // [xsp+10h] [xbp-20h]
  int v14; // [xsp+12h] [xbp-1Eh]
  __int16 v15; // [xsp+16h] [xbp-1Ah]
  int v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+1Ch] [xbp-14h]
  int v18; // [xsp+24h] [xbp-Ch]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_7F7658 == 1 )
  {
    if ( (unsigned __int8)byte_7F7656 > 1u )
    {
      if ( byte_7F7656 == 2 )
      {
        if ( (unsigned int)result >= 0x17 )
          goto LABEL_14;
      }
      else if ( byte_7F7656 != 4 && (byte_7F7656 != 3 || (unsigned int)result >= 0x23) )
      {
        goto LABEL_14;
      }
      goto LABEL_13;
    }
    if ( !byte_7F7656 )
    {
      if ( (unsigned int)result > 7 )
        goto LABEL_14;
      goto LABEL_13;
    }
    if ( byte_7F7656 == 1 && (unsigned int)result < 0xE )
    {
LABEL_13:
      v7 = *a2;
      v8 = *((_WORD *)a2 + 2);
      v9 = *a3;
      v16 = 0;
      v12 = v7;
      LOWORD(v7) = *((_WORD *)a3 + 2);
      v13 = v8;
      v10 = *a7;
      v15 = v7;
      v11 = *((_DWORD *)a7 + 2);
      LOBYTE(v16) = a4;
      v14 = v9;
      v17 = v10;
      v18 = v11;
      result = ((__int64 (__fastcall *)(__int64, _QWORD, int *, __int64, _QWORD, _QWORD, _QWORD))qdf_dp_add_record)(
                 result,
                 a5,
                 &v12,
                 28,
                 0,
                 0,
                 a6 & 1);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
