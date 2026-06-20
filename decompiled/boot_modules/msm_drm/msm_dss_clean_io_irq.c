_QWORD **__fastcall msm_dss_clean_io_irq(_QWORD **result)
{
  _QWORD *v1; // x9
  _QWORD **v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x21

  v1 = *result;
  if ( *result != result )
  {
    v2 = result;
    do
    {
      v4 = (_QWORD *)*v1;
      v3 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v3 == v1 && (_QWORD *)v4[1] == v1 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      result = (_QWORD **)kfree(v1 - 1);
      v1 = v4;
    }
    while ( v4 != v2 );
  }
  return result;
}
