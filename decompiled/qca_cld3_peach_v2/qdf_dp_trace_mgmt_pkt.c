__int64 __fastcall qdf_dp_trace_mgmt_pkt(__int64 result, char a2, unsigned int a3, char a4, char a5)
{
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
      v5[1] = a4;
      v5[2] = a5;
      v5[0] = a2;
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _BYTE *, __int64, _QWORD, _QWORD, __int64))qdf_dp_add_record)(
                 result,
                 a3,
                 v5,
                 3,
                 0,
                 0,
                 1);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
