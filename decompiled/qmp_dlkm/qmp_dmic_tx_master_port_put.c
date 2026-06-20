__int64 __fastcall qmp_dmic_tx_master_port_put(__int64 a1, __int64 a2)
{
  __int64 v6; // x21
  size_t v7; // x0
  size_t v8; // x2
  __int64 v9; // x8
  size_t v10; // x0
  size_t v11; // x0
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x0

  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  v7 = strnlen((const char *)(a1 + 32), 0x2Cu);
  v8 = v7;
  if ( v7 >= 0x2D )
    goto LABEL_16;
  if ( v7 == 44 )
  {
LABEL_17:
    v14 = _fortify_panic(4, 44, 45);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return qmp_fu1_usage_modes_get(v14);
  }
  if ( strnstr(a1 + 32, "VA", v7) )
  {
    v9 = 2;
    goto LABEL_12;
  }
  v10 = strnlen((const char *)(a1 + 32), 0x2Cu);
  v8 = v10;
  if ( v10 >= 0x2D )
  {
LABEL_16:
    _fortify_panic(2, 44, v8 + 1);
    goto LABEL_17;
  }
  if ( v10 == 44 )
    goto LABEL_17;
  if ( strnstr(a1 + 32, "Normal", v10) )
  {
    v9 = 0;
    goto LABEL_12;
  }
  v11 = strnlen((const char *)(a1 + 32), 0x2Cu);
  v8 = v11;
  if ( v11 >= 0x2D )
    goto LABEL_16;
  if ( v11 == 44 )
    goto LABEL_17;
  v9 = strnstr(a1 + 32, "LP", v11) != 0;
LABEL_12:
  v12 = *(unsigned int *)(a2 + 72);
  if ( (unsigned int)v12 > 0xE )
    return 4294967274LL;
  result = 0;
  *(_BYTE *)(v6 + v9 + 56) = qmp_master_channel_map[v12];
  return result;
}
