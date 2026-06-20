__int64 __fastcall reg_freq_width_to_chan_op_class_auto(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        _BYTE *a6,
        __int64 a7)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // x0
  __int64 psoc_tx_ops; // x0
  _DWORD *v24; // x8
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)reg_freq_to_band(a2) != 2 && (reg_is_5dot9_ghz_freq(a1, a2) & 1) == 0 )
  {
    v22 = *(_QWORD *)(a1 + 80);
    v25[0] = 0;
    if ( v22 )
    {
      psoc_tx_ops = reg_get_psoc_tx_ops(v22);
      if ( psoc_tx_ops )
      {
        v24 = *(_DWORD **)(psoc_tx_ops + 160);
        if ( v24 )
        {
          if ( *(v24 - 1) != -1393108416 )
            __break(0x8228u);
          psoc_tx_ops = ((__int64 (__fastcall *)(__int64, _BYTE *))v24)(a1, v25);
          if ( v25[0] == 4 )
            goto LABEL_3;
        }
      }
    }
    else
    {
      psoc_tx_ops = qdf_trace_msg(
                      0x51u,
                      2u,
                      "%s: psoc is NULL",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      "reg_is_country_opclass_global");
    }
    *a6 = 0;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _BYTE *, __int64))reg_freq_width_to_chan_op_class)(
               psoc_tx_ops,
               a2,
               a3,
               0,
               a5,
               a6,
               a7);
    if ( *a6 )
      goto LABEL_5;
    goto LABEL_4;
  }
LABEL_3:
  *a6 = 0;
LABEL_4:
  result = ((__int64 (*)(void))reg_freq_width_to_chan_op_class)();
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
