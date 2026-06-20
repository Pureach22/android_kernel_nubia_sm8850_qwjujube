_QWORD *__fastcall msm_m31_eusb2_repeater_reset_and_init(_QWORD *a1)
{
  __int64 v1; // x8
  _QWORD *result; // x0
  unsigned int (*v4)(void); // x8
  unsigned int (*v5)(void); // x8
  __int64 (*v6)(void); // x8
  __int64 v7; // x8
  unsigned int v8; // w19

  v1 = a1[70];
  if ( !v1 )
    return nullptr;
  *(_DWORD *)(v1 + 16) = *((_DWORD *)a1 + 4);
  result = (_QWORD *)a1[70];
  if ( result )
  {
    v4 = (unsigned int (*)(void))result[8];
    if ( !v4 )
      goto LABEL_7;
    if ( *((_DWORD *)v4 - 1) != -867545059 )
      __break(0x8228u);
    if ( v4() )
    {
      dev_err(*a1, "repeater powerup failed.\n");
      result = (_QWORD *)a1[70];
      if ( !result )
        return result;
    }
    else
    {
LABEL_7:
      result = (_QWORD *)a1[70];
      if ( !result )
        return result;
    }
    v5 = (unsigned int (*)(void))result[5];
    if ( !v5 )
      goto LABEL_12;
    if ( *((_DWORD *)v5 - 1) != -2106062652 )
      __break(0x8228u);
    if ( v5() )
    {
      dev_err(*a1, "repeater reset failed.\n");
      result = (_QWORD *)a1[70];
      if ( !result )
        return result;
    }
    else
    {
LABEL_12:
      result = (_QWORD *)a1[70];
      if ( !result )
        return result;
    }
    v6 = (__int64 (*)(void))result[6];
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != -867545059 )
        __break(0x8228u);
      result = (_QWORD *)v6();
      if ( (_DWORD)result )
      {
        v7 = *a1;
        v8 = (unsigned int)result;
        dev_err(v7, "repeater init failed.\n");
        return (_QWORD *)v8;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}
