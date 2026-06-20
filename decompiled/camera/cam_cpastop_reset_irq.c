__int64 __fastcall cam_cpastop_reset_irq(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _BYTE *v6; // x8
  int v7; // w20
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v11; // x21
  int v12; // w9
  unsigned int v13; // w23
  __int64 v14; // x8
  __int64 v15; // x24
  __int64 v16; // x25
  int v17; // w26
  int v18; // w8
  int v19; // w8
  __int64 v20; // x20
  __int64 i; // x21
  __int64 v22; // x9

  if ( (unsigned int)a3 >= 4 )
  {
LABEL_21:
    __break(0x5512u);
    return cam_cpastop_handle_errlogger(result, a2, a3, a4);
  }
  v5 = *(_QWORD *)(**(_QWORD **)(a2 + 3680) + 8LL * (unsigned int)a3 + 8);
  v6 = *(_BYTE **)(v5 + 24);
  if ( *v6 == 1 )
  {
    v7 = result;
    v8 = (unsigned int)a3;
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _BYTE *))cam_cpas_util_reg_update)(
               a2,
               *(unsigned int *)(v5 + 4),
               v6 + 56);
    v9 = *(_QWORD *)(a2 + 3680);
    v10 = *(_QWORD *)(*(_QWORD *)v9 + 8 * v8 + 8);
    if ( v7 )
    {
      v11 = *(unsigned int *)(v10 + 4);
      if ( (unsigned int)v11 <= 9 )
      {
        v12 = *(_DWORD *)(v10 + 40);
        v13 = *(_DWORD *)(v9 + 4 * v11 + 2812);
        if ( v12 < 1 )
        {
          v18 = -1;
          if ( v13 <= 7 )
            return cam_io_w(
                     *(_DWORD *)(*(_QWORD *)(v10 + 24) + 24LL) & (unsigned int)v18,
                     *(_QWORD *)(a2 + 24LL * v13 + 384) + *(unsigned int *)(*(_QWORD *)(v10 + 24) + 12LL));
        }
        else
        {
          v14 = *(_QWORD *)(v10 + 32);
          v15 = 0;
          v16 = 0;
          v17 = 0;
          do
          {
            if ( *(_BYTE *)(v14 + v15 + 4) == 1 && (*(_DWORD *)(v14 + v15 + 8) & v7) != 0 )
            {
              result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
                         a2,
                         (unsigned int)v11,
                         v14 + v15 + 68);
              v14 = *(_QWORD *)(v10 + 32);
              v12 = *(_DWORD *)(v10 + 40);
              v17 |= *(_DWORD *)(v14 + v15 + 8);
            }
            ++v16;
            v15 += 96;
          }
          while ( v16 < v12 );
          v18 = ~v17;
          if ( v13 <= 7 )
            return cam_io_w(
                     *(_DWORD *)(*(_QWORD *)(v10 + 24) + 24LL) & (unsigned int)v18,
                     *(_QWORD *)(a2 + 24LL * v13 + 384) + *(unsigned int *)(*(_QWORD *)(v10 + 24) + 12LL));
        }
      }
      goto LABEL_21;
    }
    *(_BYTE *)(v9 + 159431) = 0;
    v19 = *(_DWORD *)(v10 + 40);
    if ( v19 >= 1 )
    {
      v20 = 0;
      for ( i = 0; i < v19; ++i )
      {
        v22 = *(_QWORD *)(v10 + 32) + v20;
        if ( *(_BYTE *)(v22 + 4) == 1 )
        {
          ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
            a2,
            *(unsigned int *)(v10 + 4),
            v22 + 68);
          ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_update)(
            a2,
            *(unsigned int *)(v10 + 4),
            *(_QWORD *)(v10 + 32) + v20 + 12);
          v19 = *(_DWORD *)(v10 + 40);
        }
        v20 += 96;
      }
    }
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cam_cpas_util_reg_update)(
             a2,
             *(unsigned int *)(v10 + 4),
             *(_QWORD *)(v10 + 24));
  }
  return result;
}
