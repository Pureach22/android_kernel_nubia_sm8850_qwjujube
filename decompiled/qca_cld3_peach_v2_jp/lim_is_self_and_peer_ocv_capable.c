bool __fastcall lim_is_self_and_peer_ocv_capable(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v6; // x0
  __int16 param; // w8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _BOOL8 result; // x0
  _WORD *v17; // x0
  __int16 v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 16);
  v18 = 0;
  param = wlan_crypto_get_param(v6, 5u);
  result = 0;
  if ( (param & 0x4000) != 0 )
  {
    v17 = (_WORD *)dph_lookup_hash_entry(v8, v9, v10, v11, v12, v13, v14, v15, a1, a2, &v18, a3 + 360);
    result = v17 && (*v17 & 0x800) != 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
