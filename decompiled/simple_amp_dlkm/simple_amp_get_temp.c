__int64 __fastcall simple_amp_get_temp(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  _QWORD *v4; // x20
  __int64 v5; // x8
  int v6; // w0
  int v7; // w3
  __int64 v9; // x8
  int v10; // w0
  __int64 v12; // x8
  int v13; // w0
  __int64 v15; // x8
  int v16; // w0
  __int64 v18; // x8
  __int64 result; // x0
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 128);
  v4 = *(_QWORD **)(*(_QWORD *)(v3 + 24) + 152LL);
  if ( (*((_BYTE *)v4 + 173) & 1) != 0 )
  {
    v20 = 0;
    *((_BYTE *)v4 + 173) = 0;
    cancel_work_sync(v4 + 67);
    v5 = v4[6];
    *((_DWORD *)v4 + 142) = 0;
    if ( v5 )
    {
      v6 = regmap_read(
             *v4,
             (*(_DWORD *)(v5 + 288) << 15) & 0x200000 | ((*(_DWORD *)(v5 + 288) & 0x3F) << 7) | 0x40080000u,
             &v20);
      v7 = v20;
      if ( v6 || v20 == 0 )
        goto LABEL_28;
    }
    v9 = v4[7];
    if ( v9 )
    {
      v10 = regmap_read(
              *v4,
              (*(_DWORD *)(v9 + 288) << 15) & 0x200000 | ((*(_DWORD *)(v9 + 288) & 0x3F) << 7) | 0x40480000u,
              &v20);
      v7 = v20;
      if ( v10 || v20 == 0 )
        goto LABEL_28;
    }
    v12 = v4[8];
    if ( v12 )
    {
      v13 = regmap_read(
              *v4,
              (*(_DWORD *)(v12 + 288) << 15) & 0x200000 | ((*(_DWORD *)(v12 + 288) & 0x3F) << 7) | 0x40880000u,
              &v20);
      v7 = v20;
      if ( v13 || v20 == 0 )
        goto LABEL_28;
    }
    v15 = v4[9];
    if ( v15 )
    {
      v16 = regmap_read(
              *v4,
              (*(_DWORD *)(v15 + 288) << 15) & 0x200000 | ((*(_DWORD *)(v15 + 288) & 0x3F) << 7) | 0x40C80000u,
              &v20);
      v7 = v20;
      if ( v16 || v20 == 0 )
      {
LABEL_28:
        dev_err(v4[1], "%s: PDE is already on!! Invalid request ps: %d\n", "simple_amp_get_temp", v7);
        result = 4294967274LL;
        goto LABEL_27;
      }
    }
    queue_work_on(32, system_wq, v4 + 67);
    if ( !(unsigned int)wait_for_completion_timeout(v4 + 71, 125) )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: Timeout occurred before work function completed\n", "simple_amp_get_temp");
      goto LABEL_30;
    }
    v18 = *((unsigned int *)v4 + 150);
    if ( (unsigned int)(v18 - 45) <= 0xFFFFFFD8 )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: Temp range Invalid\n", "simple_amp_get_temp");
LABEL_30:
      result = 4294967274LL;
      goto LABEL_27;
    }
  }
  else
  {
    v18 = *((int *)v4 + 150);
  }
  result = 0;
  *(_QWORD *)(a2 + 72) = v18;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
