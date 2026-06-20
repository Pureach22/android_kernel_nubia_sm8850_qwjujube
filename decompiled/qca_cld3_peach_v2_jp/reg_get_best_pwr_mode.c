__int64 __fastcall reg_get_best_pwr_mode(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v5; // w20
  int v7; // w24
  int v8; // w22
  __int16 v9; // w0
  _BOOL4 v10; // w10
  _BOOL4 v11; // w8
  bool v12; // zf
  char v13; // w8
  unsigned int v14; // w10

  v5 = a2;
  v7 = (__int16)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))reg_get_eirp_from_mas_chan_list)(
                  a1,
                  a2,
                  a4,
                  0,
                  0,
                  2,
                  0);
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, _QWORD))reg_get_eirp_from_mas_chan_list)(
         a1,
         v5,
         a4,
         1,
         0,
         2,
         0);
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, __int64, _QWORD))reg_get_eirp_from_mas_chan_list)(
         a1,
         v5,
         a4,
         2,
         0,
         2,
         0);
  v10 = ((v8 << 8) & 0xFF00) != 0;
  v11 = (char)v8 > (char)(v7 & ~(v7 >> 31));
  v12 = !v10 || !v11;
  if ( v10 && v11 )
    v13 = v8;
  else
    v13 = v7 & ~(v7 >> 31);
  if ( v12 )
    v14 = 4 * (v7 < 1);
  else
    v14 = 1;
  if ( v9 <= v13 || v9 == 0 )
    return v14;
  else
    return 2;
}
