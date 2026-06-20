__int64 __fastcall drm_dp_read_channel_eq_delay(__int64 a1, __int64 a2, int a3, char a4)
{
  int v4; // w8
  unsigned int v5; // w8
  __int64 (__fastcall *v6)(); // x19
  __int64 v7; // x20
  char v8; // w8
  __int64 v9; // x8
  __int64 v10; // x1
  __int64 result; // x0
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  if ( a3 )
  {
    if ( (a4 & 1) != 0 )
      v4 = 982994;
    else
      v4 = 982992;
    v5 = v4 + 80 * a3;
    if ( (a4 & 1) != 0 )
      v6 = _128b132b_channel_eq_delay_us;
    else
      v6 = _8b10b_channel_eq_delay_us;
    if ( v5 <= 0xE )
      goto LABEL_17;
  }
  else
  {
    if ( (a4 & 1) == 0 )
    {
      v6 = _8b10b_channel_eq_delay_us;
      v5 = 14;
LABEL_17:
      v8 = *(_BYTE *)(a2 + v5);
      v12[0] = v8;
      goto LABEL_18;
    }
    v6 = _128b132b_channel_eq_delay_us;
    v5 = 8726;
  }
  v7 = a1;
  if ( drm_dp_dpcd_read(a1, v5, v12, 1) != 1 )
  {
    v9 = *(_QWORD *)(v7 + 1256);
    if ( v9 )
      v10 = *(_QWORD *)(v9 + 8);
    else
      v10 = 0;
    _drm_dev_dbg(0, v10, 2, "%s: failed rd interval read\n", *(const char **)v7);
    result = 400;
    goto LABEL_23;
  }
  v8 = v12[0];
  a1 = v7;
LABEL_18:
  if ( *((_DWORD *)v6 - 1) != 297030811 )
    __break(0x8233u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a1, v8 & 0x7F);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
