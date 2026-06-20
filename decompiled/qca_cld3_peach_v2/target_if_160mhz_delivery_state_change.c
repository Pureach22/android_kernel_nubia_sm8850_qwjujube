__int64 __fastcall target_if_160mhz_delivery_state_change(
        _QWORD *a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 result; // x0
  _QWORD *v13; // x21
  _QWORD *v14; // x20
  int v16; // w9
  int v17; // w8
  __int64 v18; // x20
  void (__fastcall *v19)(_QWORD); // x9
  __int64 v20; // x0
  __int64 v22; // x9

  if ( a2 >= 2 )
  {
    v11 = jiffies;
    if ( target_if_160mhz_delivery_state_change___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid Spectral mode %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "target_if_160mhz_delivery_state_change",
        a2);
      target_if_160mhz_delivery_state_change___last_ticks = v11;
    }
    return 4;
  }
  v13 = a1 + 148;
  if ( (unsigned int)(*((_DWORD *)a1 + a2 + 296) - 3) >= 2 )
  {
    v18 = jiffies;
    if ( target_if_160mhz_delivery_state_change___last_ticks_58 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Scan BW %d is not 160/80p80 for mode %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "target_if_160mhz_delivery_state_change");
      target_if_160mhz_delivery_state_change___last_ticks_58 = v18;
    }
    return 16;
  }
  else
  {
    v14 = a1 + 172;
    result = 0;
    v16 = *((_DWORD *)v14 + a2);
    if ( v16 <= 1 )
    {
      if ( v16 )
      {
        if ( v16 != 1 )
          return result;
        result = 0;
        v17 = 2;
      }
      else
      {
        if ( a3 )
        {
          ++a1[153];
          return 16;
        }
        result = 0;
        v17 = 1;
      }
LABEL_26:
      *((_DWORD *)v14 + a2) = v17;
      return result;
    }
    if ( v16 == 2 )
    {
      if ( a3 != 1 )
      {
        v22 = a1[154];
        *((_DWORD *)v14 + a2) = 0;
        a1[154] = v22 + 1;
        return 16;
      }
      result = 0;
      v17 = 3;
      goto LABEL_26;
    }
    if ( v16 == 3 )
    {
      v19 = (void (__fastcall *)(_QWORD))a1[161];
      v20 = *a1;
      if ( *((_DWORD *)v19 - 1) != 1779743641 )
        __break(0x8229u);
      v19(v20);
      result = 0;
      if ( (unsigned int)(*((_DWORD *)v13 + a2) - 3) <= 1 )
        *((_DWORD *)v14 + a2) = 0;
    }
  }
  return result;
}
