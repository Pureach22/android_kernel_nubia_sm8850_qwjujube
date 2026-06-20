unsigned int *__fastcall sde_encoder_uidle_enable(
        unsigned int *result,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned int *v8; // x19
  __int64 v10; // x8
  unsigned int v11; // w21
  unsigned __int64 v12; // x8
  void *v13; // x0
  __int64 v14; // x23
  int v15; // w4
  __int64 (*v16)(void); // x9
  __int64 v17; // x27
  char v18; // [xsp+0h] [xbp+0h]

  v8 = result;
  if ( !result )
  {
LABEL_10:
    v11 = 0;
    v12 = v8[49];
    if ( !(_DWORD)v12 )
      return result;
    goto LABEL_11;
  }
  if ( !*(_QWORD *)result )
  {
    v13 = &unk_26FCAB;
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v10 || !*(_QWORD *)(v10 + 8) )
  {
    v13 = &unk_234896;
LABEL_9:
    result = (unsigned int *)printk(v13, "sde_encoder_get_kms");
    goto LABEL_10;
  }
  result = (unsigned int *)sde_kms_get_disp_op();
  v11 = (unsigned int)result;
  v12 = v8[49];
  if ( !(_DWORD)v12 )
    return result;
LABEL_11:
  v14 = 0;
  while ( v14 != 4 )
  {
    v17 = *(_QWORD *)&v8[2 * v14 + 50];
    if ( v17 )
    {
      result = *(unsigned int **)(v17 + 416);
      if ( result )
      {
        if ( v11 > 2 )
          break;
        v16 = *(__int64 (**)(void))&result[2 * v11 + 160];
        if ( v16 && *(_DWORD *)(v17 + 664) != 3 )
        {
          if ( (a2 & 1) != 0 )
          {
            if ( v8 )
              v15 = v8[6];
            else
              v15 = -1;
            sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_uidle_enable", 137, -1, v15, 1, -1059143953, a8, v18);
            v16 = *(__int64 (**)(void))(*(_QWORD *)(v17 + 416) + 8LL * v11 + 640);
          }
          if ( *((_DWORD *)v16 - 1) != -1792093723 )
            __break(0x8229u);
          result = (unsigned int *)v16();
          v12 = v8[49];
        }
      }
    }
    if ( ++v14 >= v12 )
      return result;
  }
  __break(0x5512u);
  return (unsigned int *)sde_encoder_get_programmed_fetch_time(result + 43, result[1]);
}
