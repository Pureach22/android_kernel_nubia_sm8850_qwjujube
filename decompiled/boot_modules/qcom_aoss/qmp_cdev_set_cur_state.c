__int64 __fastcall qmp_cdev_set_cur_state(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  bool v9; // w20
  __int64 result; // x0
  const char *v11; // x3
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 944);
  v9 = a2 != 0;
  if ( *(unsigned __int8 *)(v8 + 24) == a2 )
    return 0;
  if ( a2 )
    v11 = "on";
  else
    v11 = "off";
  result = qmp_send(
             *(_QWORD *)(v8 + 8),
             "{class: volt_flr, event:zero_temp, res:%s, value:%s}",
             *(_QWORD *)(v8 + 16),
             (int)v11,
             a5,
             a6,
             a7,
             a8,
             vars0);
  if ( !(_DWORD)result )
    *(_BYTE *)(v8 + 24) = v9;
  return result;
}
