__int64 __fastcall mpam_msc_slc_get_params(__int64 a1, _QWORD *a2, void *a3, unsigned int a4, unsigned int a5)
{
  __int64 v5; // x8
  size_t v7; // x21
  __int64 v8; // x0
  __int64 v9; // x9
  _DWORD *v11; // x8
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  _QWORD src[9]; // [xsp+8h] [xbp-48h] BYREF

  src[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  if ( !v5 )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_8;
  }
  v7 = a4;
  v9 = *(_QWORD *)(v5 + 40);
  v8 = *(_QWORD *)(v5 + 48);
  src[0] = *a2;
  memset(&src[1], 0, 56);
  v11 = *(_DWORD **)(v9 + 8);
  if ( *(v11 - 1) != 1134762728 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, _QWORD, __int64, _QWORD))v11)(
             v8,
             src,
             0x534C434D50414DLL,
             a5,
             8,
             a4);
  if ( (_DWORD)result )
    goto LABEL_8;
  if ( a4 < 0x41 )
  {
    memcpy(a3, src, v7);
    result = 0;
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = _fortify_panic(16, -1, v7);
  return llcc_perf_clk_enable(v13, v14);
}
