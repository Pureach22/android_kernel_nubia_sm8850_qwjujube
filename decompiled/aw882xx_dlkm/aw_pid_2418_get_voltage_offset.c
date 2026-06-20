__int64 __fastcall aw_pid_2418_get_voltage_offset(_QWORD *a1, _DWORD *a2)
{
  __int64 (__fastcall *v4)(__int64, __int64, int *); // x8
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 *v8; // x8
  __int64 v9; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 (__fastcall *)(__int64, __int64, int *))a1[145];
  v5 = a1[15];
  v11 = 0;
  if ( *((_DWORD *)v4 - 1) != 1983062130 )
    __break(0x8228u);
  v6 = v4(v5, 117, &v11);
  *a2 = 2 * (char)v11;
  v7 = v6;
  v8 = (__int64 *)a1[14];
  v9 = v8[14];
  if ( !v9 )
    v9 = *v8;
  printk(&unk_248AF, v9, "aw_pid_2418_get_voltage_offset");
  _ReadStatusReg(SP_EL0);
  return v7;
}
