__int64 __fastcall synx_hwfence_signal(unsigned __int64 a1, int a2, int a3)
{
  __int64 v3; // x30
  unsigned __int64 v4; // x6
  int v5; // w9
  __int64 result; // x0
  int v7; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-28h] BYREF
  __int64 v9; // [xsp+20h] [xbp-20h]
  __int64 v10; // [xsp+28h] [xbp-18h]
  int *v11; // [xsp+30h] [xbp-10h]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = nullptr;
  v8 = 0;
  v9 = 0;
  v7 = 0;
  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL && (v4 = *(_QWORD *)(a1 + 8)) != 0 && v4 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(unsigned __int8 *)(v4 + 179);
    v11 = &v7;
    LODWORD(v8) = a2;
    HIDWORD(v8) = v5 ^ 1;
    LODWORD(v9) = a3;
    result = synx_hwfence_signal_n_indv((unsigned int *)a1, (unsigned __int16 *)&v8);
  }
  else
  {
    printk(&unk_27D41, "synx_hwfence_signal", 381, v3, a1);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
