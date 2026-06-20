__int64 __fastcall drm_dp_read_clock_recovery_delay(__int64 a1, unsigned __int8 *a2, int a3, char a4)
{
  unsigned int v4; // w8
  __int64 (__fastcall *v5)(); // x9
  __int64 result; // x0
  __int64 v7; // x19
  unsigned __int8 v8; // w8
  __int64 v9; // x8
  __int64 v10; // x1
  unsigned __int8 v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  if ( !a3 )
  {
    if ( (a4 & 1) == 0 && *a2 <= 0x13u )
    {
      v5 = (__int64 (__fastcall *)())_8b10b_clock_recovery_delay_us;
      v4 = 14;
      goto LABEL_11;
    }
LABEL_7:
    result = 100;
    goto LABEL_15;
  }
  if ( (a4 & 1) == 0 )
    goto LABEL_7;
  v4 = 80 * a3 + 982994;
  if ( v4 <= 0xE )
  {
    v5 = _128b132b_channel_eq_delay_us;
LABEL_11:
    v8 = a2[v4];
    v11[0] = v8;
    goto LABEL_12;
  }
  v7 = a1;
  if ( drm_dp_dpcd_read(a1, v4, v11, 1) != 1 )
  {
    v9 = *(_QWORD *)(v7 + 1256);
    if ( v9 )
      v10 = *(_QWORD *)(v9 + 8);
    else
      v10 = 0;
    _drm_dev_dbg(0, v10, 2, "%s: failed rd interval read\n", *(const char **)v7);
    result = 400;
    goto LABEL_15;
  }
  v8 = v11[0];
  v5 = _128b132b_channel_eq_delay_us;
  a1 = v7;
LABEL_12:
  if ( *((_DWORD *)v5 - 1) != 297030811 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a1, v8 & 0x7F);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
