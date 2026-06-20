__int64 __fastcall msm_config_group_get(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v9; // x21
  unsigned int v10; // w8
  unsigned int v11; // w24
  __int64 v12; // x23
  unsigned __int64 v13; // x9
  unsigned int v14; // w9
  int v15; // w8
  unsigned int v16; // w0
  unsigned int v17; // w9
  __int16 v18; // w8

  drvdata = pinctrl_dev_get_drvdata();
  v6 = *a3;
  v7 = drvdata;
  if ( (gpiochip_line_is_valid(drvdata + 16, a2) & 1) == 0 )
    return 4294967274LL;
  result = 4294966772LL;
  v9 = *(_QWORD *)(*(_QWORD *)(v7 + 968) + 32LL) + 112LL * a2;
  v10 = (unsigned __int8)v6;
  if ( (unsigned __int8)v6 <= 0xBu )
  {
    if ( (unsigned __int8)v6 > 4u )
    {
      if ( (unsigned __int8)v6 != 5 )
      {
        if ( (unsigned __int8)v6 != 6 )
        {
          if ( (unsigned __int8)v6 != 9 )
            return result;
          LODWORD(v13) = 2
                       * (((unsigned int)readl((unsigned int *)(*(_QWORD *)(v7
                                                                          + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL)
                                                                          + 976)
                                                              + *(unsigned int *)(v9 + 60))) >> (v10 >> 17))
                        & 7)
                       + 2;
          goto LABEL_55;
        }
        if ( (((unsigned int)readl((unsigned int *)(*(_QWORD *)(v7 + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL) + 976)
                                                  + *(unsigned int *)(v9 + 60))) >> (v10 >> 27))
            & 1) != 0 )
          goto LABEL_54;
        return 4294967274LL;
      }
    }
    else if ( (unsigned __int8)v6 >= 2u && (unsigned __int8)v6 != 3 )
    {
      return result;
    }
    v14 = *(_DWORD *)(v9 + 84);
    v15 = (v14 >> 22) & 0x1F;
    LODWORD(v12) = (v14 >> 12) & 0x1F;
    if ( v15 )
      v11 = ((unsigned int)(1 << v15) >> v12) | 3;
    else
      v11 = 3;
LABEL_20:
    v16 = readl((unsigned int *)(*(_QWORD *)(v7 + 976 + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL))
                               + *(unsigned int *)(v9 + 60)));
    v17 = v16 >> v12;
    v18 = v16;
    result = 4294966772LL;
    v13 = v17 & v11;
    if ( (unsigned __int8)v6 > 0x11u )
    {
      if ( (unsigned __int8)v6 > 0x7Fu )
      {
        if ( (unsigned __int8)v6 == 128 )
        {
          result = 4294967274LL;
          if ( (v18 & 0x800) == 0 || !(_DWORD)v13 )
            return result;
        }
        else
        {
          if ( (unsigned __int8)v6 != 129 )
            return result;
          result = 4294967274LL;
          if ( (v18 & 0x800) == 0 || (_DWORD)v13 )
            return result;
        }
        goto LABEL_54;
      }
      if ( (unsigned __int8)v6 != 18 )
      {
        if ( (unsigned __int8)v6 != 19 )
          return result;
        if ( (_DWORD)v13 )
          goto LABEL_55;
        return 4294967274LL;
      }
      if ( !(_DWORD)v13 )
        return 4294967274LL;
      v13 = ((unsigned __int64)(unsigned int)readl((unsigned int *)(*(_QWORD *)(v7
                                                                              + 976
                                                                              + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL))
                                                                  + *(unsigned int *)(v9 + 64))) >> ((*(_QWORD *)(v9 + 84) >> 47) & 0x1F))
          & 1;
    }
    else
    {
      if ( (unsigned __int8)v6 <= 2u )
      {
        if ( (_BYTE)v6 )
        {
          if ( (unsigned __int8)v6 != 1 )
            return result;
          if ( !(_DWORD)v13 )
            goto LABEL_54;
          return 4294967274LL;
        }
        if ( (*(_BYTE *)(*(_QWORD *)(v7 + 968) + 48LL) & 1) != 0 )
          return result;
LABEL_44:
        if ( (_DWORD)v13 != 2 )
          return 4294967274LL;
        goto LABEL_54;
      }
      if ( (unsigned __int8)v6 == 3 )
      {
        if ( (_DWORD)v13 != 1 )
          return 4294967274LL;
        goto LABEL_54;
      }
      if ( (unsigned __int8)v6 != 5 )
        return result;
      if ( *(_BYTE *)(*(_QWORD *)(v7 + 968) + 48LL) == 1 )
        goto LABEL_44;
      if ( ((v13 >> ((*(_QWORD *)(v9 + 84) >> 22) & 0x1F)) & 1) == 0 )
      {
        if ( (_DWORD)v13 != 3 )
          return 4294967274LL;
LABEL_54:
        LODWORD(v13) = 1;
        goto LABEL_55;
      }
      LODWORD(v13) = 2200;
    }
LABEL_55:
    *a3 = (unsigned int)(unsigned __int8)v6 | ((_DWORD)v13 << 8);
    return 0;
  }
  if ( (unsigned __int8)v6 > 0x7Fu )
  {
    if ( (unsigned int)(unsigned __int8)v6 - 128 >= 2 )
    {
      if ( (unsigned __int8)v6 != 130 )
        return result;
      readl((unsigned int *)(*(_QWORD *)(v7 + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v9 + 60)));
      goto LABEL_54;
    }
    LOBYTE(v12) = 12;
    v11 = 1;
    goto LABEL_20;
  }
  if ( (unsigned int)(unsigned __int8)v6 - 18 < 2 || (unsigned __int8)v6 == 12 )
  {
    v11 = 1;
    v12 = (*(_QWORD *)(v9 + 84) >> 42) & 0x1FLL;
    goto LABEL_20;
  }
  return result;
}
