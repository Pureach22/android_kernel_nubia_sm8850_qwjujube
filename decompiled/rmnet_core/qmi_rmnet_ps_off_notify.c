__int64 __fastcall qmi_rmnet_ps_off_notify(__int64 result)
{
  _UNKNOWN **v1; // x21
  __int64 v2; // x19
  __int64 (__fastcall *v3)(_QWORD); // x8

  v1 = (_UNKNOWN **)ps_list;
  if ( ps_list != (_UNKNOWN *)&ps_list )
  {
    v2 = result;
    do
    {
      v3 = (__int64 (__fastcall *)(_QWORD))*(v1 - 1);
      if ( *((_DWORD *)v3 - 1) != 251140989 )
        __break(0x8228u);
      result = v3(v2);
      v1 = (_UNKNOWN **)*v1;
    }
    while ( v1 != &ps_list );
  }
  return result;
}
