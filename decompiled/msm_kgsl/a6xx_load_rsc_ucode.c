__int64 __fastcall a6xx_load_rsc_ucode(__int64 result)
{
  int *v1; // x8
  int v2; // w19
  bool v3; // zf
  _DWORD *v4; // x19
  unsigned int v5; // w9
  __int64 v6; // x8
  int v7; // w21
  const char *v8; // x8
  __int64 v9; // x20
  int v10; // w8
  __int64 v11; // x20

  v1 = *(int **)(result + 14264);
  v2 = *v1;
  v3 = (unsigned int)(*v1 - 620) > 0x28 || ((1LL << ((unsigned __int8)*v1 - 108)) & 0x10040000001LL) == 0;
  if ( !v3
    || (v8 = *((const char **)v1 + 3)) != nullptr
    && (v9 = result, v10 = strcmp(v8, "qcom,adreno-gpu-a642l"), result = v9, !v10)
    || (unsigned int)(v2 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v2 - 109)) & 0x60000400003LL) != 0 )
  {
    v4 = *(_DWORD **)(result - 344);
  }
  else
  {
    v11 = result;
    v4 = (_DWORD *)kgsl_regmap_virt(result + 13200, 144384);
    result = v11;
  }
  v4[4] = 0x1000000;
  v4[11] = 1;
  v4[14] = 0;
  v4[13] = 0;
  v4[16] = 0;
  v4[15] = 0;
  if ( **(_DWORD **)(result + 14264) == 622 )
    v5 = -2147483608;
  else
    v5 = 0x80000000;
  v4[18] = v5;
  v4[17] = 0;
  v4[256] = 0;
  v4[8] = 17696;
  v4[9] = 17680;
  v4[10] = 17684;
  v6 = *(_QWORD *)(result + 14264);
  v7 = *(_DWORD *)v6;
  if ( *(int *)v6 > 649 )
  {
    if ( v7 == 650 || v7 == 660 )
      goto LABEL_19;
  }
  else
  {
    if ( v7 == 620 )
      goto LABEL_19;
    if ( v7 == 622 )
    {
      v4[340] = -357898848;
      v4[341] = -509482069;
      v4[342] = -1562335871;
      v4[343] = -324238622;
      v4[344] = 2157997;
      return result;
    }
  }
  result = *(_QWORD *)(v6 + 24);
  if ( !result || (result = strcmp((const char *)result, "qcom,adreno-gpu-a642l"), (_DWORD)result) )
  {
    if ( (unsigned int)(v7 - 621) > 0x2A || ((1LL << ((unsigned __int8)v7 - 109)) & 0x60000400003LL) == 0 )
    {
      v4[384] = -1482357088;
      v4[385] = -1578719513;
      v4[386] = -1562344991;
      v4[387] = -374766878;
      v4[388] = 2156712;
      return result;
    }
  }
LABEL_19:
  v4[384] = -357898848;
  v4[385] = -509482069;
  v4[386] = -1562335871;
  v4[387] = -324238622;
  v4[388] = 2157997;
  return result;
}
