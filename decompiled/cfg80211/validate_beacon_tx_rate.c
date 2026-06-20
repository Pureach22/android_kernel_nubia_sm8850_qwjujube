__int64 __fastcall validate_beacon_tx_rate(_BYTE *a1, __int64 a2, __int64 a3)
{
  unsigned int *v4; // x21
  int v5; // w20
  int v6; // w23
  _BOOL4 v7; // w22
  __int64 result; // x0
  bool v9; // w8
  bool v10; // zf
  int v11; // w24
  _BOOL4 v12; // w23
  bool v13; // w8
  bool v14; // zf
  int v15; // w25
  _BOOL4 v16; // w24
  bool v17; // w8
  bool v18; // zf
  bool v19; // w8

  if ( (unsigned int)a2 >= 6 )
  {
    __break(0x5512u);
    return parse_acl_data(a1, a2);
  }
  v4 = (unsigned int *)(a3 + 60LL * (unsigned int)a2);
  v5 = *v4;
  if ( (unsigned int)_sw_hweight32(*v4) > 1 )
    return 4294967274LL;
  if ( (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 4)) > 1 )
    return 4294967274LL;
  v6 = *((unsigned __int8 *)v4 + 4);
  v7 = *((_BYTE *)v4 + 4) != 0;
  if ( *((_BYTE *)v4 + 4) )
  {
    if ( v5 )
      return 4294967274LL;
  }
  if ( (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 5)) > 1 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( *((_BYTE *)v4 + 5) )
    v7 = 1;
  if ( v5 )
    v9 = v7;
  else
    v9 = 0;
  if ( v6 )
    v10 = *((_BYTE *)v4 + 5) == 0;
  else
    v10 = 1;
  if ( v10 && !v9 )
  {
    if ( (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 6)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 6) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 7)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 7) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 8)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 8) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 9)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 9) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 10)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 10) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 11)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 11) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 12)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 12) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 || (unsigned int)_sw_hweight8(*((unsigned __int8 *)v4 + 13)) > 1 )
      return 4294967274LL;
    if ( *((_BYTE *)v4 + 13) )
    {
      if ( v7 )
        return 4294967274LL;
      v7 = 1;
    }
    if ( v7 && v5 )
      return 4294967274LL;
    if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 7)) > 1 )
      return 4294967274LL;
    v11 = *((unsigned __int16 *)v4 + 7);
    v12 = *((_WORD *)v4 + 7) != 0;
    if ( *((_WORD *)v4 + 7) )
    {
      if ( v5 )
        return 4294967274LL;
    }
    if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 8)) > 1 )
      return 4294967274LL;
    result = 4294967274LL;
    if ( *((_WORD *)v4 + 8) )
      v12 = 1;
    if ( v5 )
      v13 = v12;
    else
      v13 = 0;
    if ( v11 )
      v14 = *((unsigned __int16 *)v4 + 8) == 0;
    else
      v14 = 1;
    if ( v14 && !v13 )
    {
      if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 9)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 9) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 10)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 10) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 11)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 11) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 12)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 12) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 13)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 13) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 14)) > 1 )
        return 4294967274LL;
      if ( *((_WORD *)v4 + 14) )
      {
        if ( v12 )
          return 4294967274LL;
        v12 = 1;
      }
      if ( v12 && v5 )
        return 4294967274LL;
      if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 15)) > 1 )
        return 4294967274LL;
      v15 = *((unsigned __int16 *)v4 + 15);
      v16 = *((_WORD *)v4 + 15) != 0;
      if ( *((_WORD *)v4 + 15) )
      {
        if ( v5 )
          return 4294967274LL;
      }
      if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 16)) > 1 )
        return 4294967274LL;
      result = 4294967274LL;
      if ( *((_WORD *)v4 + 16) )
        v16 = 1;
      v17 = v5 && v16;
      v18 = !v15 || *((_WORD *)v4 + 16) == 0;
      if ( v18 && !v17 )
      {
        if ( (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 17)) <= 1 )
        {
          if ( *((_WORD *)v4 + 17) )
          {
            if ( v16 )
              return 4294967274LL;
            v16 = 1;
          }
          if ( v16 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 18)) > 1 )
            return 4294967274LL;
          if ( *((_WORD *)v4 + 18) )
          {
            if ( v16 )
              return 4294967274LL;
            v16 = 1;
          }
          if ( v16 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 19)) > 1 )
            return 4294967274LL;
          if ( *((_WORD *)v4 + 19) )
          {
            if ( v16 )
              return 4294967274LL;
            v16 = 1;
          }
          if ( v16 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 20)) > 1 )
            return 4294967274LL;
          if ( *((_WORD *)v4 + 20) )
          {
            if ( v16 )
              return 4294967274LL;
            v16 = 1;
          }
          if ( v16 && v5 || (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 21)) > 1 )
            return 4294967274LL;
          if ( *((_WORD *)v4 + 21) )
          {
            if ( v16 )
              return 4294967274LL;
            v16 = 1;
          }
          if ( (!v16 || !v5) && (unsigned int)_sw_hweight16(*((unsigned __int16 *)v4 + 22)) <= 1 )
          {
            if ( !*((_WORD *)v4 + 22) )
              goto LABEL_168;
            if ( !v16 )
            {
              v16 = 1;
LABEL_168:
              result = 4294967274LL;
              if ( v5 )
                v19 = v16;
              else
                v19 = 0;
              if ( !v19
                && (!v7 || !v12 || !v16)
                && v7 | v5 | (v12 || v16)
                && (!v5 || (a1[1104] & 0x40) != 0)
                && (!v7 || (char)a1[1104] < 0)
                && (!v12 || (a1[1105] & 1) != 0)
                && (!v16 || (a1[1110] & 0x40) != 0) )
              {
                return 0;
              }
              return result;
            }
          }
        }
        return 4294967274LL;
      }
    }
  }
  return result;
}
