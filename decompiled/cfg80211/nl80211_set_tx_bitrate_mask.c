__int64 __fastcall nl80211_set_tx_bitrate_mask(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x1
  __int64 v4; // x8
  unsigned int v5; // w19
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 result; // x0
  _DWORD *v9; // x8
  _BYTE v10[360]; // [xsp+0h] [xbp-170h] BYREF
  __int64 v11; // [xsp+168h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v10, 0, sizeof(v10));
  v3 = a2[4];
  v4 = *(_QWORD *)(v3 + 2504);
  if ( v4 )
    v5 = *(unsigned __int8 *)(v4 + 4);
  else
    v5 = 0;
  v6 = a2[6];
  if ( *(_QWORD *)(*(_QWORD *)v6 + 464LL) )
  {
    v7 = a2[7];
    result = nl80211_parse_tx_bitrate_mask((int)a2, v3, 90, v10);
    if ( !(_DWORD)result )
    {
      v9 = *(_DWORD **)(*(_QWORD *)v6 + 464LL);
      if ( *(v9 - 1) != 1007451213 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _BYTE *))v9)(v6 + 992, v7, v5, 0, v10);
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
