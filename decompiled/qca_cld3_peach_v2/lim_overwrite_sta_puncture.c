__int64 __fastcall lim_overwrite_sta_puncture(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w0
  unsigned int v13; // w2
  int v14; // w3
  unsigned int v15; // w4
  unsigned __int16 v16; // w1
  __int64 result; // x0
  unsigned __int16 v18; // w8
  unsigned __int16 v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a1 + 7176);
  v13 = *(_DWORD *)(a1 + 284);
  v14 = *(_DWORD *)(a2 + 12);
  v15 = *(_DWORD *)a2;
  v16 = *(_WORD *)(a1 + 7184);
  v19 = 0;
  result = wlan_reg_extract_puncture_by_bw(v12, v16, v13, v14, v15, &v19, a3, a4, a5, a6, a7, a8, a9, a10);
  v18 = v19;
  *(_WORD *)(a2 + 18) = v19;
  *(_WORD *)(a1 + 7184) = v18;
  _ReadStatusReg(SP_EL0);
  return result;
}
