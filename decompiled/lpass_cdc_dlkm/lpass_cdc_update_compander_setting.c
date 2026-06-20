__int64 __fastcall lpass_cdc_update_compander_setting(__int64 a1, unsigned __int16 a2, _DWORD *a3)
{
  int v3; // w23
  int v4; // w22
  unsigned int v5; // w20
  int v7; // w21
  unsigned int v8; // w8
  __int64 v9; // x2
  __int64 v10; // x2
  unsigned int v11; // w8
  __int64 v12; // x2
  unsigned int v13; // w8
  __int64 v14; // x2
  int v15; // w8

  v3 = a3[1];
  v4 = a2;
  v5 = a3[2];
  v7 = *a3 - v3;
  snd_soc_component_write(a1, (unsigned int)a2 + 8, 6);
  if ( v7 <= 17 )
    v8 = v7;
  else
    v8 = 12;
  if ( v7 <= 23 )
    v9 = v8;
  else
    v9 = 18;
  snd_soc_component_write(a1, (unsigned int)(v4 + 12), v9);
  if ( v7 <= 65 )
  {
    if ( v7 <= 29 )
      v11 = v7;
    else
      v11 = 24;
    if ( v7 <= 35 )
      v12 = v11;
    else
      v12 = 30;
    snd_soc_component_write(a1, (unsigned int)(v4 + 16), v12);
    if ( v7 <= 41 )
      v13 = v7;
    else
      v13 = 36;
    if ( v7 <= 47 )
      v10 = v13;
    else
      v10 = 42;
  }
  else
  {
    snd_soc_component_write(a1, (unsigned int)(v4 + 16), 33);
    v10 = 48;
  }
  snd_soc_component_write(a1, (unsigned int)(v4 + 20), v10);
  if ( v7 <= 68 )
    v14 = 60;
  else
    v14 = 63;
  if ( v7 <= 65 )
  {
    if ( v7 <= 59 )
    {
      if ( v7 <= 53 )
        v14 = (unsigned int)v7;
      else
        v14 = 48;
    }
    else
    {
      v14 = 54;
    }
  }
  snd_soc_component_write(a1, (unsigned int)(v4 + 24), v14);
  snd_soc_component_write(a1, (unsigned int)(v4 + 28), (unsigned int)v7);
  snd_soc_component_write(a1, (unsigned int)(v4 + 32), v3 + ((unsigned int)v3 >> 31 << 8));
  if ( v3 >= 0 )
    v15 = v3;
  else
    v15 = -v3;
  snd_soc_component_write(a1, (unsigned int)(v4 + 36), (unsigned int)(v7 - v15));
  snd_soc_component_write(a1, (unsigned int)(v4 + 40), v5);
  return 0;
}
