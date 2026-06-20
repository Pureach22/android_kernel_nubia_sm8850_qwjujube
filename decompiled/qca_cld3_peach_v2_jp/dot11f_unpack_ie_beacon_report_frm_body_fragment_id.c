__int64 __fastcall dot11f_unpack_ie_beacon_report_frm_body_fragment_id(
        __int64 a1,
        const void *a2,
        unsigned __int8 a3,
        __int64 a4)
{
  __int64 result; // x0
  __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a4 )
  {
    result = 32;
  }
  else
  {
    *(_BYTE *)a4 = 1;
    if ( a3 <= 1u )
    {
      *(_BYTE *)a4 = 0;
      result = 4;
    }
    else
    {
      v6 = 0;
      qdf_mem_copy(&v6, a2, 2u);
      result = 0;
      *(_WORD *)(a4 + 1) = v6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
