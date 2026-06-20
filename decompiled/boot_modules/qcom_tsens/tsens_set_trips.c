__int64 __fastcall tsens_set_trips(__int64 a1, int a2, int a3)
{
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned int *v8; // x20
  unsigned int v9; // w10
  __int64 v10; // x8
  int v11; // w9
  int v12; // w11
  unsigned int v13; // w22
  char v14; // w8
  int v15; // w10
  int v16; // w26
  int v17; // w10
  int v18; // w27
  unsigned int v19; // w24
  unsigned int v20; // w25
  int v21; // w11
  __int64 v22; // x10
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // kr00_8
  __int64 v25; // x23
  __int64 v26; // x28
  unsigned int v27; // w8
  int v28; // w8
  __int64 v29; // x0
  const char *v30; // x11
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  bool v35; // zf
  unsigned __int64 StatusReg; // x8
  const char *v37; // x3
  _QWORD v39[2]; // [xsp+28h] [xbp-38h] BYREF
  __int64 v40; // [xsp+38h] [xbp-28h]
  __int64 v41; // [xsp+40h] [xbp-20h]
  __int64 v42; // [xsp+48h] [xbp-18h]
  __int64 v43; // [xsp+50h] [xbp-10h]
  __int64 v44; // [xsp+58h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = thermal_zone_device_priv();
  v7 = *(_QWORD *)v6;
  v42 = 0;
  v43 = 0;
  v8 = (unsigned int *)v6;
  v40 = 0;
  v41 = 0;
  v9 = *(_DWORD *)(v6 + 68);
  v10 = *(_QWORD *)(v7 + 2544);
  v39[0] = 0;
  v39[1] = 0;
  v12 = *(_DWORD *)(v10 + 16);
  v11 = *(_DWORD *)(v10 + 20);
  if ( *(_DWORD *)v10 )
    v13 = v9;
  else
    v13 = 0;
  v14 = *(_BYTE *)(v10 + 4);
  if ( v12 <= a3 )
    v15 = a3;
  else
    v15 = v12;
  if ( v11 <= a3 )
    v16 = v11;
  else
    v16 = v15;
  if ( v12 <= a2 )
    v17 = a2;
  else
    v17 = v12;
  if ( v11 <= a2 )
    v18 = v11;
  else
    v18 = v17;
  if ( (v14 & 4) != 0 )
  {
    v21 = *(_DWORD *)(v6 + 72);
    v22 = *(int *)(v6 + 64);
    v23 = v22 + v21 * (__int64)(v18 / 1000);
    v24 = v22 + v21 * (__int64)(v16 / 1000);
    if ( v24 <= 0xF9C17 )
      v19 = v24 / 0x3E8;
    else
      v19 = 1023;
    if ( v23 <= 0xF9C17 )
      v20 = v23 / 0x3E8;
    else
      v20 = 1023;
  }
  else
  {
    v19 = v16 / 100;
    v20 = v18 / 100;
  }
  v25 = raw_spin_lock_irqsave(v7 + 40);
  ((void (__fastcall *)(__int64, _QWORD, unsigned int *, _QWORD *))tsens_read_irq_state)(v7, v13, v8, v39);
  if ( v13 + 89 >= 0x137
    || (v26 = v7 + 48,
        regmap_field_update_bits_base(*(_QWORD *)(v7 + 48 + 8LL * (v13 + 89)), 0xFFFFFFFFLL, v20, 0, 0, 0),
        v13 + 169 > 0x136)
    || ((regmap_field_update_bits_base(*(_QWORD *)(v26 + 8LL * (v13 + 169)), 0xFFFFFFFFLL, v19, 0, 0, 0),
         **(_DWORD **)(v7 + 2544) < 3u)
      ? (v27 = v13 + 57)
      : (v27 = v13 + 73),
        v27 >= 0x137) )
  {
    __break(0x5512u);
  }
  regmap_field_update_bits_base(*(_QWORD *)(v26 + 8LL * v27), 0xFFFFFFFFLL, 0, 0, 0, 0);
  if ( **(_DWORD **)(v7 + 2544) <= 2u )
    v28 = 137;
  else
    v28 = 153;
  regmap_field_update_bits_base(*(_QWORD *)(v26 + 8LL * (v13 + v28)), 0xFFFFFFFFLL, 0, 0, 0, 0);
  raw_spin_unlock_irqrestore(v7 + 40, v25);
  ((void (__fastcall *)(__int64, _QWORD, unsigned int *, unsigned int *))tsens_read_irq_state)(v7, v13, v8, v8 + 4);
  if ( v7 )
  {
    v29 = *(_QWORD *)(v7 + 2592);
    if ( v29 )
    {
      v30 = (const char *)&unk_10983;
      if ( (_DWORD)v42 )
        v30 = "(V)";
      v31 = *(unsigned int *)(a1 + 1088);
      v32 = v8[10];
      v33 = v8[6];
      v34 = v8[14];
      v35 = (LODWORD(v39[0]) | (unsigned int)v40) == 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( v35 )
        v37 = v30;
      else
        v37 = "(V)";
      ipc_log_string(
        v29,
        "%s %s temp:%d mask(%u|%u|%u) | (%d:%d)->(%d:%d)\n [%s]\n",
        a1 + 4,
        v37,
        v31,
        v32,
        v33,
        v34,
        HIDWORD(v40),
        HIDWORD(v39[0]),
        v18,
        v16,
        StatusReg + 2320);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
