__int64 __fastcall ufs_qcom_shared_ice_init(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x0
  int v5; // w8
  __int64 next_available_child; // x0
  char *v7; // x19
  unsigned int v8; // w21
  int v9; // w8
  char *s1; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v11[11]; // [xsp+8h] [xbp-58h] BYREF

  v11[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 184);
    if ( (*(_BYTE *)v1 & 0x10) == 0 )
    {
      result = 0;
LABEL_17:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 64) + 744LL);
    s1 = nullptr;
    memset(v11, 0, 80);
    v5 = _of_parse_phandle_with_args(v4, "shared-ice-cfg", 0, 0, 0, v11);
    result = 4294967294LL;
    if ( v5 || !v11[0] )
      goto LABEL_17;
    next_available_child = of_get_next_available_child(v11[0], 0);
    *(_QWORD *)(v1 + 672) = next_available_child;
    if ( next_available_child )
    {
      result = of_property_read_string(next_available_child, "alg-name", &s1);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_17;
      v7 = s1;
      v8 = result;
      if ( !strcmp(s1, "alg1") )
      {
        v9 = 0;
      }
      else if ( !strcmp(v7, "alg2") )
      {
        v9 = 1;
      }
      else
      {
        if ( strcmp(v7, "alg3") )
        {
          result = 4294967235LL;
          goto LABEL_17;
        }
        v9 = 2;
      }
      result = v8;
    }
    else
    {
      dev_err(*(_QWORD *)(a1 + 64), "Resort to default alg2\n");
      result = 0;
      v9 = 1;
    }
    *(_DWORD *)(v1 + 680) = v9;
    goto LABEL_17;
  }
  __break(0x800u);
  return ufs_qcom_ice_init(0);
}
