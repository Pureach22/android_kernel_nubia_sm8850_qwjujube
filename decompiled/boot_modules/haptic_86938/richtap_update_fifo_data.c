__int64 __fastcall richtap_update_fifo_data(__int16 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w21
  __int16 *v7; // x20
  unsigned int v8; // w19
  int v9; // w23
  unsigned __int8 *v10; // x8
  int v11; // w9
  size_t v12; // x22
  unsigned int v13; // w9
  int v14; // w25
  unsigned __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x1
  _DWORD *v19; // x8

  v6 = a2;
  v7 = a1;
  v8 = 0;
  v9 = 3;
  while ( 1 )
  {
    v10 = *((unsigned __int8 **)v7 + 196);
    v11 = *v10;
    if ( v11 == 85 )
      break;
    if ( v11 == 170 )
      goto LABEL_16;
    if ( v9 <= 0 )
    {
      printk(&unk_16842, a2, a3, a4);
      goto LABEL_16;
    }
    --v9;
    a1 = (__int16 *)usleep_range_state(1000, 1000, 2);
    if ( !v6 )
      goto LABEL_16;
LABEL_11:
    if ( !*((_DWORD *)v7 + 431) )
      goto LABEL_16;
  }
  v12 = *((__int16 *)v10 + 1) - (__int64)v7[860];
  v13 = (unsigned __int16)v7[860];
  v14 = v6 - v12;
  if ( v6 > (unsigned int)v12 )
  {
    if ( v13 >= 0x3E9 )
      goto LABEL_20;
    v15 = (unsigned __int16)v7[860];
    if ( v15 > 0x3E8 )
      goto LABEL_20;
    a1 = (__int16 *)memcpy(
                      (void *)(*((_QWORD *)v7 + 193) + (int)v8),
                      (const void *)(*((_QWORD *)v7 + 196) + v15 + 24),
                      v12);
    v8 += v12;
    v6 -= v12;
    **((_BYTE **)v7 + 196) = -1;
    *(_WORD *)(*((_QWORD *)v7 + 196) + 2LL) = 0;
    v16 = *(_QWORD *)(*((_QWORD *)v7 + 196) + 8LL);
    v7[860] = 0;
    *((_QWORD *)v7 + 196) = v16;
    if ( !v14 )
      goto LABEL_16;
    goto LABEL_11;
  }
  if ( v13 > 0x3E8 || (v17 = (unsigned __int16)v7[860], v17 > 0x3E8) )
  {
LABEL_20:
    __break(0x5512u);
    return brightness_get(a1, a2, a3, a4, a5, a6, (unsigned int)SLOBYTE(STACK[0x920]));
  }
  memcpy((void *)(*((_QWORD *)v7 + 193) + (int)v8), (const void *)(*((_QWORD *)v7 + 196) + v17 + 24), v6);
  v8 += v6;
  v7[860] += v6;
LABEL_16:
  v18 = *((_QWORD *)v7 + 193);
  v19 = *(_DWORD **)(*((_QWORD *)v7 + 185) + 208LL);
  if ( *(v19 - 1) != -962088293 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int16 *, __int64, _QWORD))v19)(v7, v18, v8);
}
