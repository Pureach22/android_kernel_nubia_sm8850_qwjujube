__int64 __fastcall kgsl_ioctl_device_getproperty(__int64 *a1, __int64 a2, int *a3)
{
  int v3; // w9
  __int64 v4; // x8
  const char *v5; // x8
  __int64 (*v6)(void); // x8
  __int64 v8; // x10
  __int64 v9; // x9
  int (__fastcall *v10)(__int64, int *); // x9

  v3 = *a3;
  v4 = *a1;
  if ( *a3 <= 38 )
  {
    if ( v3 > 34 )
    {
      if ( v3 == 35 )
      {
        v5 = (const char *)&off_171420;
        goto LABEL_22;
      }
      if ( v3 == 36 )
      {
        v5 = (const char *)&off_171430;
        goto LABEL_22;
      }
    }
    else
    {
      if ( v3 == 8 )
      {
        v5 = "\b";
        goto LABEL_22;
      }
      if ( v3 == 9 )
      {
        v5 = (const char *)&unk_171410;
        goto LABEL_22;
      }
    }
  }
  else if ( v3 <= 43 )
  {
    if ( v3 == 39 )
    {
      v5 = (const char *)&off_171440;
      goto LABEL_22;
    }
    if ( v3 == 40 )
    {
      v5 = (const char *)&off_171450;
      goto LABEL_22;
    }
  }
  else
  {
    switch ( v3 )
    {
      case ',':
        v5 = (const char *)&off_171460;
        goto LABEL_22;
      case '1':
        v5 = (const char *)&off_171470;
        goto LABEL_22;
      case '2':
        v5 = (const char *)&off_171480;
LABEL_22:
        v6 = *((__int64 (**)(void))v5 + 1);
        if ( *((_DWORD *)v6 - 1) != -338900413 )
          __break(0x8228u);
        return v6();
    }
  }
  v8 = *(_QWORD *)_ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(v4 + 8752);
  if ( (v8 & 0x400000) != 0 )
    v10 = *(int (__fastcall **)(__int64, int *))(v9 + 48);
  else
    v10 = *(int (__fastcall **)(__int64, int *))(v9 + 40);
  if ( *((_DWORD *)v10 - 1) != -477936819 )
    __break(0x8229u);
  return v10(v4, a3);
}
