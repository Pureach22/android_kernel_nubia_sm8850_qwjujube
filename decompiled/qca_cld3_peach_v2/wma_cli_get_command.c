__int64 __fastcall wma_cli_get_command(
        int a1,
        int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int *v24; // x9
  __int64 result; // x0
  const char *v26; // x2
  unsigned int v27; // w1

  context = (unsigned int *)_cds_get_context(54, (__int64)"wma_cli_get_command", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4294967274LL;
  v23 = *((_QWORD *)context + 65);
  v24 = context;
  result = 0;
  if ( a3 <= 4 )
  {
    if ( a3 != 1 )
    {
      if ( a3 != 2 )
      {
        if ( a3 != 3 )
          return result;
        if ( a2 <= 6 )
        {
          switch ( a2 )
          {
            case 1:
              return *(unsigned int *)(v23 + 488LL * a1 + 48);
            case 2:
              return *(unsigned int *)(v23 + 488LL * a1 + 52);
            case 6:
              return *(unsigned int *)(v23 + 488LL * a1 + 268);
          }
        }
        else
        {
          if ( a2 <= 8 )
          {
            if ( a2 == 7 )
              return *(unsigned int *)(v23 + 488LL * a1 + 148);
            else
              return *(unsigned int *)(v23 + 488LL * a1 + 152);
          }
          if ( a2 == 9 )
            return *(unsigned int *)(v23 + 488LL * a1 + 156);
          if ( a2 == 10 )
            return *(unsigned int *)(v23 + 488LL * a1 + 160);
        }
        goto LABEL_74;
      }
      if ( a2 <= 36 )
      {
        if ( a2 <= 2 )
        {
          if ( a2 == 1 )
            return v24[139];
          if ( a2 == 2 )
            return v24[140];
        }
        else
        {
          switch ( a2 )
          {
            case 3:
              return v24[141];
            case 4:
              return v24[142];
            case 10:
              return v24[137];
          }
        }
      }
      else
      {
        if ( a2 <= 39 )
        {
          if ( a2 == 37 )
            return v24[132];
          if ( a2 == 38 )
            return v24[133];
          return v24[134];
        }
        switch ( a2 )
        {
          case '(':
            return v24[135];
          case ')':
            return v24[136];
          case '<':
            return v24[138];
        }
      }
      v26 = "%s: Invalid cli_get pdev command/Not yet implemented 0x%x";
LABEL_117:
      v27 = 2;
      goto LABEL_118;
    }
    if ( a2 > 30 )
    {
      if ( a2 > 105 )
      {
        if ( (unsigned int)(a2 - 106) < 2 )
          return wma_get_he_vdev_param(v23 + 488LL * a1, (unsigned int)a2);
      }
      else
      {
        switch ( a2 )
        {
          case 31:
            return *(unsigned int *)(v23 + 488LL * a1 + 28);
          case 34:
            return *(unsigned int *)(v23 + 488LL * a1 + 16);
          case 44:
            return *(unsigned int *)(v23 + 488LL * a1 + 36);
        }
      }
    }
    else
    {
      if ( a2 > 27 )
      {
        if ( a2 == 28 )
          return *(unsigned int *)(v23 + 488LL * a1 + 32);
        if ( a2 == 29 )
          return *(unsigned int *)(v23 + 488LL * a1 + 20);
        return *(unsigned int *)(v23 + 488LL * a1 + 24);
      }
      if ( a2 == 21 )
        return *(unsigned int *)(v23 + 488LL * a1 + 40);
      if ( a2 == 27 )
        return *(unsigned int *)(v23 + 488LL * a1 + 44);
    }
    v26 = "%s: Invalid cli_get vdev command/Not yet implemented 0x%x";
    goto LABEL_117;
  }
  if ( a3 == 5 )
  {
    if ( a2 <= 3 )
    {
      if ( a2 > 1 )
      {
        if ( a2 == 2 )
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 86);
        else
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 87);
      }
      if ( !a2 )
        return *(unsigned __int8 *)(v23 + 488LL * a1 + 84);
      if ( a2 == 1 )
        return *(unsigned __int8 *)(v23 + 488LL * a1 + 85);
    }
    else
    {
      if ( a2 <= 5 )
      {
        if ( a2 == 4 )
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 88);
        else
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 89);
      }
      switch ( a2 )
      {
        case 6:
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 90);
        case 7:
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 91);
        case 8:
          return *(unsigned __int8 *)(v23 + 488LL * a1 + 92);
      }
    }
    v26 = "%s: Invalid pps vdev command/Not yet implemented 0x%x";
    goto LABEL_117;
  }
  if ( a3 == 6 )
  {
    if ( a2 > 7 )
    {
      if ( a2 == 8 )
        return *(unsigned int *)(v23 + 488LL * a1 + 104);
      if ( a2 == 9 )
        return *(unsigned int *)(v23 + 488LL * a1 + 108);
    }
    else
    {
      if ( a2 == 5 )
        return *(unsigned int *)(v23 + 488LL * a1 + 96);
      if ( a2 == 7 )
        return *(unsigned int *)(v23 + 488LL * a1 + 100);
    }
LABEL_74:
    v26 = "%s: Invalid generic vdev command/Not yet implemented 0x%x";
    v27 = 3;
LABEL_118:
    qdf_trace_msg(0x36u, v27, v26, v15, v16, v17, v18, v19, v20, v21, v22, "wma_cli_get_command", (unsigned int)a2);
    return 4294967274LL;
  }
  if ( a3 != 7 )
    return result;
  if ( a2 > 3 )
  {
    if ( a2 > 5 )
    {
      if ( a2 == 6 )
        return *(unsigned int *)(v23 + 488LL * a1 + 136);
      if ( a2 == 7 )
        return *(unsigned int *)(v23 + 488LL * a1 + 140);
      goto LABEL_74;
    }
    if ( a2 == 4 )
      return *(unsigned int *)(v23 + 488LL * a1 + 128);
    else
      return *(unsigned int *)(v23 + 488LL * a1 + 132);
  }
  else
  {
    if ( a2 <= 1 )
    {
      if ( !a2 )
        return *(unsigned int *)(v23 + 488LL * a1 + 112);
      if ( a2 == 1 )
        return *(unsigned int *)(v23 + 488LL * a1 + 116);
      goto LABEL_74;
    }
    if ( a2 == 2 )
      return *(unsigned int *)(v23 + 488LL * a1 + 120);
    else
      return *(unsigned int *)(v23 + 488LL * a1 + 124);
  }
}
