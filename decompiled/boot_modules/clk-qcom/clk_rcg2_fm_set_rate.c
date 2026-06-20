unsigned __int64 __fastcall clk_rcg2_fm_set_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 freq_multi; // x0
  __int64 *v6; // x21
  unsigned __int64 result; // x0
  __int16 v8; // w9
  int v9; // w10
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h]
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v11 = 0;
  v12 = 0;
  freq_multi = qcom_find_freq_multi(v4, a2);
  if ( freq_multi && (v6 = (__int64 *)freq_multi, *(_QWORD *)(freq_multi + 16)) )
  {
    result = _clk_rcg2_select_conf(a1, freq_multi, a2);
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = *(_WORD *)result;
      v9 = *(_DWORD *)(result + 2);
      v10 = *v6;
      LOWORD(v11) = v8;
      *(_DWORD *)((char *)&v11 + 2) = v9;
      result = clk_rcg2_configure(a1 - 48, &v10);
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
