__int64 __fastcall ipa3_read_ep_reg(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  int v7; // w22
  int v8; // w28
  __int64 v9; // x25
  int v10; // w26
  _DWORD *v11; // x8
  __int64 v12; // x24
  int v13; // w0
  __int64 v14; // x20
  int v15; // w19

  _ReadStatusReg(SP_EL0);
  v7 = byte_1F9005;
  if ( byte_1F9005 < 0 )
  {
    v7 = 0;
    v8 = *(_DWORD *)(ipa3_ctx + 34308);
  }
  else
  {
    v8 = byte_1F9005 + 1;
  }
  v9 = *a4;
  ipa3_inc_client_enable_clks();
  if ( v7 >= v8 )
  {
    v14 = 0;
LABEL_12:
    ipa3_dec_client_disable_clks();
    *a4 = v9 + v14;
  }
  else
  {
    v10 = 0;
    while ( 1 )
    {
      v11 = *(_DWORD **)(*(_QWORD *)(ipa3_ctx + 34176) + 104LL);
      if ( *(v11 - 1) != 1503913740 )
        __break(0x8228u);
      v12 = ((int (__fastcall *)(void *, __int64, _QWORD))v11)(&dbg_buff, 4096, (unsigned int)v7);
      *a4 = v9;
      v13 = simple_read_from_buffer(a2, a3, a4, &dbg_buff, v12);
      if ( v13 < 0 )
        break;
      ++v7;
      v10 += v13;
      a2 += v12;
      a3 -= v12;
      if ( v8 == v7 )
      {
        v14 = v10;
        goto LABEL_12;
      }
    }
    v15 = v13;
    ipa3_dec_client_disable_clks();
    v14 = v15;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
