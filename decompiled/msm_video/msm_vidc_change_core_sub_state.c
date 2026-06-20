__int64 __fastcall msm_vidc_change_core_sub_state(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v9; // w20
  __int64 (__fastcall *v10)(__int64, __int64, __int64 *); // x8
  int v11; // w23
  unsigned int v12; // w0
  unsigned int v13; // w21
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v17[17]; // [xsp+8h] [xbp-88h] BYREF

  v17[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _strict_check(a1, a4);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v9 = result;
      printk(&unk_955EF, "err ", 0xFFFFFFFFLL, "codec", a4);
      result = v9;
    }
    goto LABEL_22;
  }
  v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(a1 + 3712);
  if ( !v10 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_86C3F, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_change_core_sub_state");
    goto LABEL_21;
  }
  if ( a2 == a3 )
  {
LABEL_6:
    result = 0;
    goto LABEL_22;
  }
  if ( a2 > 0x100 || a3 >= 0x101 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_85DAA, "err ", 0xFFFFFFFFLL, "codec", a4);
LABEL_21:
    result = 4294967274LL;
    goto LABEL_22;
  }
  v11 = *(_DWORD *)(a1 + 3720);
  if ( !a3 )
  {
    v14 = *(_DWORD *)(a1 + 3720);
    goto LABEL_25;
  }
  memset(v17, 0, 128);
  v16 = a3;
  if ( *((_DWORD *)v10 - 1) != 1956467913 )
    __break(0x8228u);
  v12 = v10(a1, 2, &v16);
  if ( !v12 )
  {
    v14 = *(_DWORD *)(a1 + 3720);
LABEL_25:
    if ( (v14 & a3) != a3 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_90D0A, "err ", 0xFFFFFFFFLL, "codec", a4);
      v14 = *(_DWORD *)(a1 + 3720);
    }
    v15 = v14 & ~a2;
    *(_DWORD *)(a1 + 3720) = v15;
    if ( (_DWORD)v15 != v11 && !(unsigned int)prepare_core_sub_state_name(v15, a1 + 3724) && (msm_vidc_debug & 2) != 0 )
      printk(&unk_878A6, "high", 0xFFFFFFFFLL, "codec", a4);
    goto LABEL_6;
  }
  v13 = v12;
  if ( !(unsigned int)prepare_core_sub_state_name(a3, v17) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_96FE1, "err ", 0xFFFFFFFFLL, "codec", a4);
  result = v13;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
