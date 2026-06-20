__int64 __fastcall qdf_dp_trace(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        int a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x29
  __int64 v9; // x30
  __int64 v10; // x8
  _BOOL8 v11; // x6

  if ( byte_73EC28 == 1 )
  {
    if ( (unsigned __int8)byte_73EC26 > 1u )
    {
      if ( byte_73EC26 == 2 )
      {
        if ( a2 >= 0x17 )
          return result;
      }
      else if ( byte_73EC26 != 4 && (byte_73EC26 != 3 || a2 >= 0x23) )
      {
        return result;
      }
LABEL_15:
      if ( !result || a6 )
      {
        if ( result && a6 == 1 )
        {
          if ( (*(_BYTE *)(result + 85) & 1) == 0 )
            return result;
        }
        else if ( !result )
        {
          v10 = 0;
          v11 = 0;
          return ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _BOOL8, __int64, __int64, __int64))qdf_dp_add_record)(
                   a2,
                   a3,
                   v10,
                   a5,
                   0,
                   0,
                   v11,
                   a8,
                   v8,
                   v9);
        }
      }
      else if ( (*(_BYTE *)(result + 71) & 1) == 0 || (*(_WORD *)(result + 69) & 0x700) != 0x100 )
      {
        return result;
      }
      v10 = *(_QWORD *)(result + 224);
      v11 = *(char *)(result + 71) < 0;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _BOOL8, __int64, __int64, __int64))qdf_dp_add_record)(
               a2,
               a3,
               v10,
               a5,
               0,
               0,
               v11,
               a8,
               v8,
               v9);
    }
    if ( !byte_73EC26 )
    {
      if ( a2 > 7 )
        return result;
      goto LABEL_15;
    }
    if ( byte_73EC26 == 1 && a2 < 0xE )
      goto LABEL_15;
  }
  return result;
}
