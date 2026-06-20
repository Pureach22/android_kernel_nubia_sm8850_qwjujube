__int64 __fastcall is_cvp_inst_valid(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *i; // x8
  unsigned int v4; // w20

  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( v1 )
  {
    mutex_lock(*(_QWORD *)(cvp_driver + 48));
    for ( i = *(_QWORD **)(v1 + 280); i != (_QWORD *)(v1 + 280); i = (_QWORD *)*i )
    {
      if ( i == (_QWORD *)a1 && *(_DWORD *)(a1 + 14824) )
      {
        v4 = 1;
        goto LABEL_9;
      }
    }
    v4 = 0;
LABEL_9:
    mutex_unlock(v1);
  }
  else
  {
    return 0;
  }
  return v4;
}
