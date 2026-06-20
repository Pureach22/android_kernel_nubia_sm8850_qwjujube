__int64 __fastcall qptm_for_each_node(_DWORD *a1, __int64 a2)
{
  _UNKNOWN **i; // x22
  unsigned int v5; // w0
  unsigned int v6; // w19

  mutex_lock(&qptm_list_lock);
  for ( i = (_UNKNOWN **)qptm_list; i != &qptm_list; i = (_UNKNOWN **)*i )
  {
    if ( *((_BYTE *)i - 20) == 1 )
    {
      if ( *(a1 - 1) != -2024705205 )
        __break(0x8234u);
      v5 = ((__int64 (__fastcall *)(_UNKNOWN **, __int64))a1)(i - 148, a2);
      if ( (v5 & 0x80000000) != 0 )
      {
        v6 = v5;
        goto LABEL_10;
      }
    }
  }
  v6 = 0;
LABEL_10:
  mutex_unlock(&qptm_list_lock);
  return v6;
}
