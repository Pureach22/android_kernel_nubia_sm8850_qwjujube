__int64 __fastcall aw882xx_init(__int64 a1)
{
  int v2; // w3
  _UNKNOWN **v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 *v6; // x8
  __int64 v7; // x1

  aw_dev_init_cmm(a1);
  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 > 8469 )
  {
    if ( v2 > 9007 )
    {
      switch ( v2 )
      {
        case 9008:
          v3 = &off_29968;
          goto LABEL_28;
        case 9223:
          v3 = &off_29978;
          goto LABEL_28;
        case 9240:
          v3 = &off_29988;
          goto LABEL_28;
      }
    }
    else
    {
      switch ( v2 )
      {
        case 8470:
          v3 = &off_29938;
          goto LABEL_28;
        case 8968:
          v3 = &off_29948;
          goto LABEL_28;
        case 9001:
          v3 = &off_29958;
          goto LABEL_28;
      }
    }
  }
  else if ( v2 > 8276 )
  {
    switch ( v2 )
    {
      case 8277:
        v3 = &off_29908;
        goto LABEL_28;
      case 8305:
        v3 = &off_29918;
        goto LABEL_28;
      case 8467:
        v3 = &off_29928;
        goto LABEL_28;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 6226:
        v3 = &aw_dev_attr_array;
        goto LABEL_28;
      case 8211:
        v3 = &off_298E8;
        goto LABEL_28;
      case 8242:
        v3 = &off_298F8;
LABEL_28:
        v4 = (void (__fastcall *)(_QWORD))v3[1];
        if ( *((_DWORD *)v4 - 1) != -835398270 )
          __break(0x8228u);
        v4(a1);
        aw882xx_dev_check_ef_lock(a1);
        return aw882xx_dev_probe(a1);
    }
  }
  v6 = *(__int64 **)(a1 + 112);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  printk(&unk_24158, v7, "aw882xx_init");
  return 4294967274LL;
}
