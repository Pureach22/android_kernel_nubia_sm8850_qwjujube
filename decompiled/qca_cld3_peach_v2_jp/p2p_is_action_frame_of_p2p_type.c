bool __fastcall p2p_is_action_frame_of_p2p_type(
        unsigned __int8 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BOOL8 result; // x0
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  if ( (unsigned int)p2p_get_frame_info(a1, a2, (__int64)&v12, a3, a4, a5, a6, a7, a8, a9, a10) )
    result = 0;
  else
    result = (_DWORD)v13 != 17 || HIDWORD(v13) != 3;
  _ReadStatusReg(SP_EL0);
  return result;
}
