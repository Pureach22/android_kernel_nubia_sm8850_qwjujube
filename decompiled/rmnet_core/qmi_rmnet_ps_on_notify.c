__int64 __fastcall qmi_rmnet_ps_on_notify(__int64 a1)
{
  __int64 result; // x0
  _UNKNOWN **v3; // x21
  __int64 (__fastcall *v4)(_QWORD); // x8

  result = rmnet_mem_cb(0, 0);
  v3 = (_UNKNOWN **)ps_list;
  if ( ps_list != (_UNKNOWN *)&ps_list )
  {
    do
    {
      v4 = (__int64 (__fastcall *)(_QWORD))*(v3 - 2);
      if ( *((_DWORD *)v4 - 1) != 251140989 )
        __break(0x8228u);
      result = v4(a1);
      v3 = (_UNKNOWN **)*v3;
    }
    while ( v3 != &ps_list );
  }
  return result;
}
