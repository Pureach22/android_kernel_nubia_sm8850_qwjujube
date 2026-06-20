__int64 __fastcall thermal_qmi_del_server(__int64 result)
{
  _QWORD *i; // x8

  for ( i = *(_QWORD **)(result + 360); i != (_QWORD *)(result + 360); i = (_QWORD *)*i )
    *((_BYTE *)i - 8) = 0;
  return result;
}
