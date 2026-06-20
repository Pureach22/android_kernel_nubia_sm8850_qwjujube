__int64 __fastcall pattern_trig_timer_common_function(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  _DWORD *v4; // x21
  char v5; // w8
  unsigned int *v6; // x13
  _DWORD *v7; // x9
  __int64 v8; // x1
  int v9; // w10
  unsigned int v10; // w12
  unsigned int v11; // w13
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 (*v16)(void); // x8
  __int64 v17; // x0
  __int64 v18; // x0
  int v19; // w8
  unsigned int v20; // w8
  __int64 v21; // x20
  __int64 v22; // x0
  _DWORD *v23; // x8
  char v24; // w9
  __int64 v25; // x10
  __int64 v26; // x10
  int v27; // w9
  _DWORD *v28; // x8
  __int64 v29; // x0
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0

  v3 = result;
  v4 = (_DWORD *)(result + 8);
  v5 = *(_BYTE *)(result + 8280);
  if ( (v5 & 1) != 0 )
  {
LABEL_3:
    while ( 1 )
    {
      v6 = *(unsigned int **)(result + 8200);
      v7 = *(_DWORD **)(result + 8208);
      v8 = v6[1];
      v9 = v7[1];
      if ( v9 == (_DWORD)v8 )
        break;
      v10 = *(_DWORD *)(result + 8276);
      v11 = *v6;
      if ( v10 <= v11 )
      {
        v18 = *(_QWORD *)result;
        if ( v10 && v11 >= 0x32 )
        {
          if ( v9 - (int)v8 >= 0 )
            v19 = v9 - v8;
          else
            v19 = v8 - v9;
          v20 = v10 * v19 / v11;
          if ( v9 <= (int)v8 )
            v8 = (unsigned int)v8 - v20;
          else
            v8 = v20 + (unsigned int)v8;
        }
        v29 = led_set_brightness(v18, v8);
        if ( *(_DWORD *)(v3 + 8284) == 1 )
        {
          v30 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 8376) + 48LL);
          if ( *((_DWORD *)v30 - 1) != -432005955 )
            __break(0x8228u);
          v31 = v30(v29);
          result = hrtimer_forward(v3 + 8328, v31, 50000000);
        }
        else
        {
          result = mod_timer(v3 + 8288, jiffies + 13LL);
        }
        v27 = *(_DWORD *)(v3 + 8276) + 50;
        goto LABEL_50;
      }
      *(_QWORD *)(result + 8200) = v7;
      if ( (v5 & 1) == 0 && v7 == v4 )
        --*(_DWORD *)(result + 8268);
      v12 = *(unsigned int *)(result + 8264);
      if ( (unsigned int)v12 >= 0x401 )
        goto LABEL_52;
      *(_DWORD *)(result + 8276) = 0;
      if ( v7 == (_DWORD *)(result + 8 * v12) )
        v13 = result + 8;
      else
        v13 = (__int64)(v7 + 2);
      *(_QWORD *)(result + 8208) = v13;
      if ( (v5 & 1) == 0 )
        goto LABEL_2;
    }
    led_set_brightness(*(_QWORD *)result, v8);
    v14 = **(unsigned int **)(v3 + 8200);
    if ( *(_DWORD *)(v3 + 8284) == 1 )
    {
      v15 = 1000000LL * (unsigned int)v14;
      v16 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 8376) + 48LL);
      if ( *((_DWORD *)v16 - 1) != -432005955 )
        __break(0x8228u);
      v17 = v16();
      result = hrtimer_forward(v3 + 8328, v17, v15);
    }
    else
    {
      v21 = jiffies;
      v22 = _msecs_to_jiffies(v14);
      result = mod_timer(v3 + 8288, v22 + v21);
    }
    v23 = *(_DWORD **)(v3 + 8208);
    v24 = *(_BYTE *)(v3 + 8280);
    if ( !*v23 )
    {
      *(_QWORD *)(v3 + 8200) = v23;
      if ( (v24 & 1) == 0 && v23 == v4 )
        --*(_DWORD *)(v3 + 8268);
      v25 = *(unsigned int *)(v3 + 8264);
      if ( (unsigned int)v25 >= 0x401 )
      {
LABEL_52:
        __break(0x5512u);
        return pattern_trig_store_patterns(result, v8, a3);
      }
      *(_DWORD *)(v3 + 8276) = 0;
      if ( v23 == &v4[2 * v25 - 2] )
        v23 = v4;
      else
        v23 += 2;
      *(_QWORD *)(v3 + 8208) = v23;
    }
    *(_QWORD *)(v3 + 8200) = v23;
    if ( (v24 & 1) == 0 && v23 == v4 )
      --*(_DWORD *)(v3 + 8268);
    v26 = *(unsigned int *)(v3 + 8264);
    if ( (unsigned int)v26 < 0x401 )
    {
      v27 = 0;
      if ( v23 == &v4[2 * v26 - 2] )
        v28 = v4;
      else
        v28 = v23 + 2;
      *(_QWORD *)(v3 + 8208) = v28;
LABEL_50:
      *(_DWORD *)(v3 + 8276) = v27;
      return result;
    }
    goto LABEL_52;
  }
LABEL_2:
  if ( *(_DWORD *)(result + 8268) )
    goto LABEL_3;
  return result;
}
