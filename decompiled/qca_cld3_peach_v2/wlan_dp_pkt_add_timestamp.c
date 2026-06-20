__int64 __fastcall wlan_dp_pkt_add_timestamp(_QWORD *a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  void (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x2
  __int64 v10; // x3
  _QWORD v11[3]; // [xsp+8h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v11[1] = 0;
  result = qdf_is_dp_pkt_timestamp_enabled();
  if ( (result & 1) != 0 )
  {
    v7 = a1[7];
    v8 = *(void (__fastcall **)(_QWORD))(*a1 + 408LL);
    __isb(0xFu);
    _ReadStatusReg(CNTVCT_EL0);
    if ( *((_DWORD *)v8 - 1) != -239780719 )
      __break(0x8228u);
    v8(v7);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qdf_add_dp_pkt_timestamp)(a3, a2, 0);
    if ( a2 == 3 )
    {
      HIDWORD(v11[0]) = 32;
      result = _qdf_nbuf_set_rx_cksum(a3, v11, v9, v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
