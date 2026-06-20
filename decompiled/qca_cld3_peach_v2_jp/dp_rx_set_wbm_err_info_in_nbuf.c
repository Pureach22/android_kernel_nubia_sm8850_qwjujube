__int64 __fastcall dp_rx_set_wbm_err_info_in_nbuf(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(__int64, int *, __int64); // x8
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 1128);
  v4 = *(_QWORD *)(a2 + 224);
  v7 = a3;
  v5 = *(__int64 (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)(v3 + 74392) + 1576LL);
  if ( *((_DWORD *)v5 - 1) != -128330861 )
    __break(0x8228u);
  result = v5(v4, &v7, 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
