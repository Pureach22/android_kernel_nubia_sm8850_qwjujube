bool __fastcall wsa884x_validate_dt_configuration_params(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4)
{
  unsigned int v4; // w22
  unsigned int v7; // w21
  unsigned __int8 v8; // w0
  __int64 v9; // x8
  int v10; // w20
  unsigned int v11; // w8

  v4 = a2;
  v7 = a4;
  v8 = snd_soc_component_read(a1, 13569);
  v9 = *(_QWORD *)(a1 + 24);
  v10 = v8;
  dev_info(v9, "VPHX EN Status: %d", v8);
  v11 = a3;
  if ( (a3 & 0xFE) == 4 || a3 == 6 )
    v11 = 0;
  return v4 > 3 || v7 > 0x12 || v11 > 6 || v11 != v10;
}
