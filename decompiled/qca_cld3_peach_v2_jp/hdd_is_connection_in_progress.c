__int64 __fastcall hdd_is_connection_in_progress(
        _BYTE *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  int v13; // w9
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  hdd_adapter_iterate(
    (__int64 (__fastcall *)(__int64, __int64))hdd_is_connection_in_progress_iterator,
    (__int64)&v14,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10);
  result = (unsigned __int8)v15;
  if ( a1 && a2 && (_BYTE)v15 )
  {
    v13 = HIDWORD(v14);
    *a1 = v14;
    *a2 = v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
