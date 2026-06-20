unsigned __int64 __fastcall msm_vidc_debugfs_update(
        unsigned __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  unsigned __int64 v5; // x19
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x20
  unsigned __int64 v9; // x8
  __int64 v10; // x10
  unsigned __int64 v11; // x9
  __int64 v12; // x6
  unsigned __int64 v13; // x3
  __int64 v14; // x4
  void *v15; // x0
  __int64 v16; // x8
  unsigned __int64 v17; // x10
  int v18; // w9
  unsigned __int64 v19; // x20
  unsigned __int64 v20; // x8
  __int64 v21; // x10
  unsigned __int64 v22; // x9
  __int64 v23; // x9
  unsigned __int64 v24; // x8
  int v25; // w11
  unsigned __int64 v26; // x19
  unsigned __int64 v27; // x20
  unsigned __int64 v28; // x20

  v5 = result + 340;
  if ( a2 > 1 )
  {
    if ( a2 != 2 )
    {
      if ( a2 == 3 )
      {
        v16 = *(_QWORD *)(result + 4248);
        v17 = *(_QWORD *)(result + 4240);
        v18 = *(_DWORD *)(result + 4228) + 1;
        *(_QWORD *)(result + 4248) = v16 + 1;
        *(_DWORD *)(result + 4228) = v18;
        if ( v17 >= v16 + 3 )
          goto LABEL_21;
        if ( !*(_DWORD *)(result + 4208) )
        {
          v19 = result;
          v20 = ktime_get(result);
          v21 = *(_QWORD *)(v19 + 4136);
          result = v19;
          v22 = v20 / 0xF4240 - *(_QWORD *)(v19 + 4120);
          *(_QWORD *)(v19 + 4128) = v20 / 0xF4240;
          *(_QWORD *)(v19 + 4136) = v22 + v21;
          *(_DWORD *)(v19 + 4208) = 1;
        }
        if ( result && (msm_vidc_debug & 8) != 0 )
        {
          v28 = result;
          printk(&unk_946FC, "perf", v5, *(_QWORD *)(result + 4232), *(_QWORD *)(result + 4256));
          result = v28;
          v14 = *(_QWORD *)(v28 + 4256);
          if ( !v14 )
            return result;
        }
        else
        {
LABEL_21:
          v14 = *(_QWORD *)(result + 4256);
          if ( !v14 )
            return result;
        }
        if ( result )
        {
          v13 = *(_QWORD *)(result + 4232);
          if ( v13 < v14 + 2 && (msm_vidc_debug & 8) != 0 )
          {
            v15 = &unk_85813;
            return printk(v15, "perf", v5, v13, v14);
          }
        }
        return result;
      }
LABEL_27:
      if ( result && (msm_vidc_debug & 1) != 0 )
        return printk(&unk_8BF42, "err ", v5, (unsigned int)a2, a5);
      return result;
    }
    v24 = *(_QWORD *)(result + 4256);
    ++*(_QWORD *)(result + 4240);
    if ( !v24 || *(_QWORD *)(result + 4232) <= v24 )
      return result;
LABEL_35:
    v25 = *(_DWORD *)(result + 4208);
    *(_BYTE *)(result + 4161) = 0;
    *(_WORD *)(result + 4162) = 0;
    *(_DWORD *)(result + 4164) = 0;
    *(_QWORD *)(result + 4168) = 0;
    *(_QWORD *)(result + 4176) = 0;
    *(_QWORD *)(result + 4184) = 0;
    *(_QWORD *)(result + 4192) = 0;
    *(_QWORD *)(result + 4200) = 0;
    strcpy((char *)(result + 4144), "Frame processing");
    if ( v25 )
    {
      v26 = result;
      result = ktime_get(result);
      *(_DWORD *)(v26 + 4208) = 0;
      *(_QWORD *)(v26 + 4120) = result / 0xF4240;
    }
    return result;
  }
  if ( !a2 )
  {
    v23 = *(_QWORD *)(result + 4256);
    ++*(_QWORD *)(result + 4232);
    if ( !v23 || *(_QWORD *)(result + 4240) <= *(_QWORD *)(result + 4248) )
      return result;
    goto LABEL_35;
  }
  if ( a2 != 1 )
    goto LABEL_27;
  v6 = *(_QWORD *)(result + 4256);
  v7 = *(_QWORD *)(result + 4232);
  *(_QWORD *)(result + 4256) = v6 + 1;
  if ( v7 >= v6 + 3 )
    goto LABEL_9;
  if ( !*(_DWORD *)(result + 4208) )
  {
    v8 = result;
    v9 = ktime_get(result);
    v10 = *(_QWORD *)(v8 + 4136);
    result = v8;
    v11 = v9 / 0xF4240 - *(_QWORD *)(v8 + 4120);
    *(_QWORD *)(v8 + 4128) = v9 / 0xF4240;
    *(_QWORD *)(v8 + 4136) = v11 + v10;
    *(_DWORD *)(v8 + 4208) = 1;
  }
  if ( result && (msm_vidc_debug & 8) != 0 )
  {
    v27 = result;
    printk(&unk_87431, "perf", v5, *(_QWORD *)(result + 4232), *(_QWORD *)(result + 4256));
    result = v27;
    v12 = *(_QWORD *)(v27 + 4248);
    if ( !v12 )
      return result;
  }
  else
  {
LABEL_9:
    v12 = *(_QWORD *)(result + 4248);
    if ( !v12 )
      return result;
  }
  if ( result && *(_QWORD *)(result + 4240) < (unsigned __int64)(v12 + 2) && (msm_vidc_debug & 8) != 0 )
  {
    v13 = *(_QWORD *)(result + 4232);
    v14 = *(_QWORD *)(result + 4256);
    v15 = &unk_8E2C0;
    return printk(v15, "perf", v5, v13, v14);
  }
  return result;
}
