__int64 __fastcall reg_fill_channel_list_for_pwrmode(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        char a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 result; // x0
  unsigned int v18; // w20
  char v19; // w21
  __int64 v20; // x22
  unsigned int v21; // w23
  int v22; // w24
  _BYTE v23[4]; // [xsp+0h] [xbp-10h] BYREF
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = a4;
  if ( a6 )
  {
    if ( a4 < 9 )
    {
      if ( a4 != 7 )
      {
LABEL_8:
        *(_DWORD *)(a6 + 4) = a4;
        *(_BYTE *)a6 = 1;
        *(_WORD *)(a6 + 22) = 0;
        result = reg_set_channel_params_for_pwrmode(a1, a2, a3, a6 + 4, (unsigned int)a7, a8 & 1);
        goto LABEL_9;
      }
    }
    else
    {
      v24 = 7;
    }
    v18 = a3;
    v19 = a8;
    v23[0] = 0;
    v20 = a1;
    v21 = a2;
    v22 = a7;
    result = reg_fill_channel_list_for_320_for_pwrmode(a1, a2, &v24, a5, a6, v23, a7, a8 & 1);
    if ( v23[0] == 1 )
    {
      a4 = v24;
      LODWORD(a7) = v22;
      a8 = v19;
      a3 = v18;
      a2 = v21;
      a1 = v20;
      goto LABEL_8;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x51u,
               2u,
               "%s: channel params is NULL",
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               "reg_fill_channel_list_for_pwrmode");
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
