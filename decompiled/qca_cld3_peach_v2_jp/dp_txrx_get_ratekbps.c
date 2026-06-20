__int64 __fastcall dp_txrx_get_ratekbps(unsigned __int8 a1, unsigned __int16 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  _WORD v5[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5[0] = 0;
  result = dp_getrateindex(a4, a2, 1u, a1, 1u, 0, &v6, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
