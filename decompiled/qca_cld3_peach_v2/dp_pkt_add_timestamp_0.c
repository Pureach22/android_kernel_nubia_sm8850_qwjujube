__int64 __fastcall dp_pkt_add_timestamp_0(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qdf_is_dp_pkt_timestamp_enabled();
  if ( (result & 1) != 0 )
  {
    v9 = *(_DWORD **)(a1 + 256);
    v11[0] = 0;
    if ( v9 )
    {
      v10 = *(_QWORD *)(a1 + 88);
      if ( *(v9 - 1) != 927319496 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD *))v9)(v10, a3, v11);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))qdf_add_dp_pkt_timestamp)(a4, a2, v11[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
